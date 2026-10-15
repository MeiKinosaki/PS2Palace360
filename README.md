# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Versão de desenvolvimento

**Pacote de desenvolvimento: v0.82b** — identificador da rodada de trabalho; não indica compatibilidade completa nem versão estável do emulador.

## Núcleo Emotion Engine (EE)

O protótipo inclui estado básico do EE, decodificação parcial, operações aritméticas/lógicas, acessos à memória e uma função inicial de passo de execução. O conjunto experimental cobre parte das operações MIPS/R5900, incluindo operações HI/LO, multiplicação/divisão, deslocamentos de 32 e 64 bits e detecção inicial de overflow. As rodadas v0.80b–v0.81b encaminham overflow de `DADD`, `DSUB`, `DADDI`, `ADD`, `SUB` e `ADDI` ao mecanismo inicial de exceções, que atualiza EPC, Cause.ExcCode e Status.EXL e seleciona um vetor inicial. A v0.82b torna portáveis os deslocamentos aritméticos de 32 bits, acrescenta testes para valores com bit de sinal definido e endurece a validação dos limites de acesso à RAM contra overflow aritmético no cálculo dos endereços. A execução de `make validate`/`make test-host` ainda deve ser confirmada por CI para esta rodada; os testes adicionados não equivalem a validação completa do R5900.
## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; faltam instruções e extensões específicas, exceções arquiteturais completas, MMU/TLB e tratamento preciso de delay slots. O buffer de RAM é apenas para testes e não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos não estão integrados.

## Toolchain na nuvem

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. A validação de host usa `make validate` e `make test-host`. A compilação para Xbox 360 exige runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente. `default.xex` não foi confirmado como gerado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
