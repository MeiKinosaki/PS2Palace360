# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

Este repositório contém uma base inicial de estado do Emotion Engine (EE), operações aritméticas MIPS de 32 bits com detecção de overflow, testes nativos e um workflow GitHub Actions para validação na nuvem.

**Ainda não é um emulador funcional de PS2.** O núcleo R5900 está incompleto e os subsistemas IOP, DMA, VU, GS, BIOS boot, áudio, vídeo e entrada ainda precisam ser implementados e integrados. Não há um `default.xex` confirmado.

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
