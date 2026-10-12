# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

A base inclui estado do Emotion Engine (EE), helpers aritméticos e lógicos, operações imediatas, comparações, movimentos condicionais e um primeiro despachante de instruções de 32 bits.

O módulo `src/ps2/ee_decode.c` decodifica um subconjunto de instruções R-type (`ADD`, `ADDU`, `SUB`, `SUBU`, `AND`, `OR`, `XOR`, `NOR`, `SLT`, `SLTU`, `MOVZ`, `MOVN`) e imediatas (`ADDI`, `ADDIU`, `SLTI`, `SLTIU`, `LUI`). Os testes incluem palavras de instrução codificadas e verificam o resultado do despachante.

**Limitações importantes:** ainda não existe loop de busca/execução, avanço arquitetural do PC, tratamento correto de exceções de overflow, branches/delay slots completos, MMU/TLB, nem suporte completo às instruções MIPS III/R5900 e extensões do Emotion Engine. Portanto, ainda não executa programas PS2 nem constitui um emulador funcional.

## Validação na nuvem

1. Abra a aba **Actions**.
2. Execute **PS2Palace360 - Cloud Toolchain** manualmente ou envie uma alteração para `main`.
3. O trabalho de validação executa `make validate` e `make test-host`.
4. A etapa Xbox 360 exige um ambiente libXenon provisionado. O runner padrão do GitHub não inclui `xenon-gcc` automaticamente; essa etapa falhará de forma explícita até a toolchain ser configurada.

## Testes em Linux

    make validate
    make test-host

Para compilar um XEX real, ainda é necessário configurar e validar o SDK libXenon, o entrypoint específico do Xbox 360 e a invocação compatível do `elf2xex`.

## BIOS

Nenhuma BIOS de console é distribuída neste repositório. Use somente uma imagem extraída legalmente do seu próprio console, quando o loader de BIOS estiver implementado.

## Licença

Consulte [LICENSE](LICENSE).
