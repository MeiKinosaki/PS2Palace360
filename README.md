# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

A base inclui estado do Emotion Engine (EE), helpers aritméticos e lógicos, operações imediatas, comparações, movimentos condicionais, um despachante inicial de instruções e um módulo de acesso a memória RAM de teste.

O módulo `src/ps2/ee_decode.c` decodifica um subconjunto de instruções R-type e imediatas. `src/ps2/ee_memory.c` fornece leituras e gravações little-endian de 8, 16, 32 e 64 bits sobre um buffer de RAM fornecido pelo chamador, verificando alinhamento e limites.

**Limitações importantes:** o módulo de memória é apenas um buffer genérico de testes, não o mapa de memória real do PS2. Ainda não existe loop completo de busca/execução, avanço arquitetural do PC, tratamento completo de exceções/overflow, branches e delay slots completos, MMU/TLB, nem suporte integral às instruções MIPS III/R5900 e extensões do Emotion Engine. O projeto ainda não executa jogos de PS2 e não é um emulador funcional.

## Validação na nuvem

1. Abra a aba **Actions**.
2. Execute **PS2Palace360 - Cloud Toolchain** manualmente ou envie uma alteração para `main`.
3. O trabalho de validação executa `make validate` e `make test-host`.
4. A etapa Xbox 360 exige um ambiente libXenon provisionado. O runner padrão do GitHub não inclui `xenon-gcc` automaticamente; essa etapa precisa de configuração explícita.

## Testes em Linux

    make validate
    make test-host

Para compilar um XEX real, ainda é necessário configurar e validar o SDK libXenon, o entrypoint específico do Xbox 360 e a invocação compatível do `elf2xex`.

## BIOS

Nenhuma BIOS de console é distribuída neste repositório. Use somente uma imagem extraída legalmente do seu próprio console, quando o loader de BIOS estiver implementado.

## Licença

Consulte [LICENSE](LICENSE).
