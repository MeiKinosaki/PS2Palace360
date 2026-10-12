CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -pedantic -O2
BUILD_DIR := build
EE_SOURCES := src/ps2/ee_state.c
HOST_TEST := $(BUILD_DIR)/test_ee_state

.PHONY: all validate test-host check xex clean

all: validate test-host

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(HOST_TEST): $(EE_SOURCES) tests/test_ee_state.c src/ps2/ee_state.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc/ps2 $(EE_SOURCES) tests/test_ee_state.c -o $@

validate:
	@test -f src/ps2/ee_state.h
	@test -f src/ps2/ee_state.c
	@test -f tests/test_ee_state.c
	@echo "OK: estrutura minima do PS2Palace360 presente."

test-host: $(HOST_TEST)
	./$(HOST_TEST)

check: validate test-host

xex:
	@echo "ERRO: alvo Xbox ainda nao implementado. Requer toolchain libXenon verificada, entrypoint Xbox e comando elf2xex validado."
	@exit 2

clean:
	rm -rf $(BUILD_DIR)
