CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic -O2
BUILD_DIR := build
XENON_CC ?= xenon-gcc
ELF2XEX ?= elf2xex
XENON_CFLAGS ?= -O2 -Wall -Wextra
EE_SOURCES := src/ps2/ee_state.c src/ps2/ee_ops.c src/ps2/ee_immediate.c src/ps2/ee_compare.c src/ps2/ee_decode.c src/ps2/ee_memory.c
HOST_TEST := $(BUILD_DIR)/test_ee_state

.PHONY: all validate test-host check toolchain-check xex clean

all: check

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(HOST_TEST): $(EE_SOURCES) tests/test_ee_state.c src/ps2/ee_state.h src/ps2/ee_ops.h src/ps2/ee_immediate.h src/ps2/ee_compare.h src/ps2/ee_decode.h src/ps2/ee_memory.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc/ps2 $(EE_SOURCES) tests/test_ee_state.c -o $@

validate:
	@test -f src/ps2/ee_state.h
	@test -f src/ps2/ee_state.c
	@test -f src/ps2/ee_ops.h
	@test -f src/ps2/ee_ops.c
	@test -f src/ps2/ee_immediate.h
	@test -f src/ps2/ee_immediate.c
	@test -f src/ps2/ee_compare.h
	@test -f src/ps2/ee_compare.c
	@test -f src/ps2/ee_decode.h
	@test -f src/ps2/ee_decode.c
	@test -f src/ps2/ee_memory.h
	@test -f src/ps2/ee_memory.c
	@test -f tests/test_ee_state.c
	@test -s tests/test_ee_state.c || { echo "ERRO: arquivo de testes ausente ou vazio."; exit 2; }
	@for f in $(EE_SOURCES); do test -s "$f" || { echo "ERRO: módulo EE ausente ou vazio: $f"; exit 2; }; done
	@test -s src/main.c || { echo "ERRO: src/main.c ausente ou vazio."; exit 2; }
	@grep -Eq 'int[[:space:]]+main[[:space:]]*\(' src/main.c || { echo "ERRO: src/main.c não declara main()."; exit 2; }
	@echo "OK: arquivos mínimos e entrypoint main() presentes (sem validar runtime Xbox)."

test-host: $(HOST_TEST)
	./$(HOST_TEST)

check: validate test-host

$(BUILD_DIR)/ps2palace360.elf: src/main.c $(EE_SOURCES) | $(BUILD_DIR) toolchain-check validate
	$(XENON_CC) $(XENON_CFLAGS) -Isrc/ps2 src/main.c $(EE_SOURCES) -o $@
	@test -s $@ || { echo "ERRO: o compilador não produziu um ELF intermediário válido."; rm -f $@; exit 2; }

toolchain-check:
	@command -v $(XENON_CC) >/dev/null 2>&1 || { echo "ERRO: $(XENON_CC) não encontrado; configure libXenon no runner."; exit 2; }
	@command -v $(ELF2XEX) >/dev/null 2>&1 || { echo "ERRO: $(ELF2XEX) não encontrado; configure a ferramenta de conversão XEX."; exit 2; }
	@echo "OK: ferramentas da toolchain Xenon encontradas."

$(BUILD_DIR)/default.xex: $(BUILD_DIR)/ps2palace360.elf
	@test -s $< || { echo "ERRO: ELF intermediário ausente ou vazio."; exit 2; }
	$(ELF2XEX) $< $@
	@test -s $@ || { echo "ERRO: default.xex não foi gerado."; exit 2; }

xex: $(BUILD_DIR)/default.xex
	@echo "OK: artefato principal gerado em $(BUILD_DIR)/default.xex"

clean:
	rm -rf $(BUILD_DIR)
