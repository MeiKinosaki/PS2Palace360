# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Versão de desenvolvimento

**Pacote de desenvolvimento: v21** — identificador da rodada de trabalho; não indica compatibilidade completa nem versão estável do emulador.

## Núcleo Emotion Engine (EE)

O protótipo inclui estado básico do EE, decodificação parcial, operações aritméticas/lógicas, acessos à memória e uma função inicial de passo de execução. A expansão atual adiciona `DADDU`, `DSUBU`, `DADDIU`, `DSLL32`, `DSRL32`, `DSRA32` e amplia o tratamento de operações HI/LO com `MFHI`, `MTHI`, `MFLO`, `MTLO`, `MULT`, `MULTU`, `DIV` e `DIVU`. A rodada v19 acrescentou um primeiro suporte a `DMULT`, `DMULTU`, `DDIV` e `DDIVU`, com produto de 128 bits calculado por partes de 32 bits para evitar depender de tipos inteiros de 128 bits do compilador. A v20 adicionou `DADD` e `DSUB` com detecção inicial de overflow assinado. A v21 acrescenta `DADDI`, também com detecção inicial de overflow, e testes para soma imediata normal e overflow. Atualmente esses casos de overflow retornam `PS2_EE_STEP_UNSUPPORTED`; a entrega de exceções arquiteturais ainda está pendente. Por enquanto, overflow é reportado como instrução não suportada; a entrega de uma exceção arquitetural precisa aguardar o subsistema de exceções.

Os testes de host foram ampliados para cobrir operações de 64 bits, deslocamentos de 32+ bits, resultados HI/LO e multiplicação/divisão de 64 bits com operandos de teste. A semântica completa do R5900 e todos os casos extremos ainda precisam de validação adicional. Execute `make validate` e `make test-host` para validar no ambiente de desenvolvimento.

## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; faltam instruções e extensões específicas, exceções arquiteturais completas, MMU/TLB e tratamento preciso de delay slots. O buffer de RAM é apenas para testes e não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos não estão integrados.

## Toolchain na nuvem

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. A validação de host usa `make validate` e `make test-host`. A compilação para Xbox 360 exige runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente. `default.xex` não foi confirmado como gerado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
