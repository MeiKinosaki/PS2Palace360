# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

A base inclui estado do Emotion Engine (EE), helpers aritméticos e lógicos, comparações, movimentos condicionais, um decodificador inicial e um buffer de RAM de teste.

`ps2_ee_execute_word()` trata um subconjunto de operações R-type (incluindo deslocamentos fixos/variáveis), operações imediatas aritméticas/lógicas (`ADDI`, `ADDIU`, `SLTI`, `SLTIU`, `ANDI`, `ORI`, `XORI`, `LUI`) e comparações/movimentos condicionais. `ps2_ee_execute_memory_word()` trata `LB`, `LBU`, `LH`, `LHU`, `LW`, `LWU`, `LD`, `SB`, `SH`, `SW` e `SD`; outras instruções encaminham para o decodificador aritmético.

A memória é apenas um buffer genérico little-endian para testes, não o mapa real do PS2. O executor ainda não é um ciclo completo de busca/execução: não atualiza PC, não trata branches/delay slots ou exceções completas e não inclui MMU/TLB. O suporte MIPS III/R5900 e extensões específicas do Emotion Engine é incompleto. Portanto, o projeto ainda não executa jogos de PS2.

## Validação na nuvem

1. Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**.
2. A workflow de host deve executar `make validate` e `make test-host`.
3. A compilação Xbox 360 exige um runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente.

## Testes de host

    make validate
    make test-host

O alvo `xex` ainda não produz um executável; requer toolchain libXenon validada, entrypoint de Xbox 360 e comando `elf2xex` verificado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
