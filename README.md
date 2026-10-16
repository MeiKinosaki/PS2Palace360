# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Versão de desenvolvimento

**Pacote de desenvolvimento: v0.85b** — identificador da rodada de trabalho; não indica compatibilidade completa nem versão estável do emulador.

## Núcleo Emotion Engine (EE)

O protótipo inclui estado básico do EE, decodificação parcial, operações aritméticas/lógicas, acessos à memória e uma função inicial de passo de execução. O conjunto experimental cobre parte das operações MIPS/R5900, incluindo operações HI/LO, multiplicação/divisão, deslocamentos de 32 e 64 bits e detecção inicial de overflow. As rodadas v0.80b–v0.81b encaminham overflow de `DADD`, `DSUB`, `DADDI`, `ADD`, `SUB` e `ADDI` ao mecanismo inicial de exceções. A v0.82b tornou portáveis os deslocamentos aritméticos de 32 bits e reforçou as verificações de limites da RAM. A v0.83b acrescenta testes de regressão para acessos de memória válidos no limite, acessos fora dos limites, desalinhamento, larguras inválidas e ponteiros nulos. A v0.85b nomeia os códigos de exceção experimentais e acrescenta testes para entrada em exceção em delay slot, registro de EPC/Cause.BD, seleção do vetor geral e preservação de EPC/Cause durante uma exceção aninhada com EXL ativo. Isso valida apenas o helper de entrada, não a precisão arquitetural completa. A v0.84b introduz um esqueleto explícito de tradução de endereços para os segmentos diretos KSEG0/KSEG1, com remoção dos bits de segmento, além de testes para ambos os segmentos, endereços sem suporte e ponteiro de saída nulo. A tradução ainda não usa TLB e não foi conectada aos acessos de memória. Esses testes foram adicionados ao conjunto de host, mas a execução CI desta rodada ainda precisa ser confirmada. Isso não substitui a implementação do mapa real de memória do PS2, MMU/TLB ou dispositivos.
## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; faltam instruções e extensões específicas, exceções arquiteturais completas, MMU/TLB e tratamento preciso de delay slots. O buffer de RAM é apenas para testes e não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos não estão integrados.

## Toolchain na nuvem

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. A validação de host usa `make validate` e `make test-host`. A compilação para Xbox 360 exige runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente. `default.xex` não foi confirmado como gerado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
