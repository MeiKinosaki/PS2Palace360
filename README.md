# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

O protótipo contém estado básico do Emotion Engine (EE), decodificador parcial, operações aritméticas/lógicas, cargas/gravações e uma função inicial de passo de execução.

A última expansão acrescenta operações HI/LO (`MFHI`, `MTHI`, `MFLO`, `MTLO`), multiplicação/divisão de 32 bits (`MULT`, `MULTU`, `DIV`, `DIVU`) e deslocamentos de 64 bits (`DSLL`, `DSRL`, `DSRA`). Também existem instruções básicas de salto/desvio e um buffer de RAM de teste.

## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; há instruções de 64 bits ausentes, estados de exceção incompletos, nenhum MMU/TLB e tratamento parcial de delay slots. A função de passo ainda precisa de mais testes de borda e integração arquitetural. O buffer de RAM não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos ainda não estão integrados.

## Validação na nuvem

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. Os testes de host usam `make validate` e `make test-host`. A compilação Xbox 360 requer runner configurado com libXenon; o runner GitHub padrão não fornece automaticamente `xenon-gcc`.

O `default.xex` ainda não foi confirmado. É necessário configurar a toolchain real, o entrypoint do Xbox 360 e a conversão ELF-to-XEX.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
