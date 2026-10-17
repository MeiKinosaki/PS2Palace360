# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Versão de desenvolvimento

**Pacote de desenvolvimento: v0.96b** — identificador da rodada de trabalho; não indica compatibilidade completa nem versão estável do emulador.

## Núcleo Emotion Engine (EE)

O protótipo inclui estado básico do EE, decodificação parcial, operações aritméticas/lógicas, acessos à memória e uma função inicial de passo de execução. O conjunto experimental cobre parte das operações MIPS/R5900, incluindo operações HI/LO, multiplicação/divisão, deslocamentos de 32 e 64 bits e detecção inicial de overflow. As rodadas v0.80b–v0.81b encaminham overflow de `DADD`, `DSUB`, `DADDI`, `ADD`, `SUB` e `ADDI` ao mecanismo inicial de exceções. A v0.82b tornou portáveis os deslocamentos aritméticos de 32 bits e reforçou as verificações de limites da RAM. A v0.83b acrescenta testes de regressão para acessos de memória válidos no limite, acessos fora dos limites, desalinhamento, larguras inválidas e ponteiros nulos. A v0.85b nomeia os códigos de exceção experimentais e acrescenta testes para entrada em exceção em delay slot, registro de EPC/Cause.BD, seleção do vetor geral e preservação de EPC/Cause durante uma exceção aninhada com EXL ativo. Isso valida apenas o helper de entrada, não a precisão arquitetural completa. A v0.84b introduziu o esqueleto de tradução KSEG0/KSEG1. A v0.87b acrescenta funções experimentais de leitura/escrita virtual que passam pela tradução antes de acessar o buffer de RAM. A v0.88b ampliou os testes de acesso virtual para larguras de 1 e 8 bytes, leitura cruzada entre KSEG0/KSEG1, desalinhamento e limites do buffer. A v0.90b adiciona uma API de tradução com códigos de retorno distintos para ponteiro de saída inválido e segmento virtual ainda não suportado, preservando a função antiga com contrato 0/-1. A v0.89b adiciona testes de borda para o fim dos segmentos KSEG0/KSEG1, rejeição de segmentos não suportados, preservação do argumento de saída quando a tradução falha e ponteiros/RAM inválidos nos acessores virtuais. Isso conecta o protótipo de tradução ao buffer de testes, mas não implementa o mapa real de memória do PS2, MMU/TLB nem dispositivos. Esses testes foram adicionados ao conjunto de host, mas a execução CI desta rodada ainda precisa ser confirmada. Isso não substitui a implementação do mapa real de memória do PS2, MMU/TLB ou dispositivos.
## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; faltam instruções e extensões específicas, exceções arquiteturais completas, MMU/TLB e tratamento preciso de delay slots. O buffer de RAM é apenas para testes e não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos não estão integrados.

## Toolchain na nuvem

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. A validação de host usa `make validate` e `make test-host`. A compilação para Xbox 360 exige runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente. `default.xex` não foi confirmado como gerado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).

### v0.92b — Add address-range helper for direct-mapped segments

Escopo: definir com precisão os intervalos aceitos pela tradução direta experimental, sem tratar o buffer de teste como RAM física real.

### v0.93b — Add tests for direct-mapped range helper

Escopo: ampliar regressões para limites de segmentos e assegurar que falhas não alterem saídas. A execução permanece pendente até haver resultado de teste verificável.

### v0.94b — Document virtual access status contracts

Contrato: funções `*_virtual_ex` retornam códigos diferenciados; os wrappers antigos mantêm o contrato 0/-1. Erros de tradução ainda não são exceções arquiteturais automaticamente.

### v0.95b — Add memory API limitations and invariants

Invariantes documentadas: larguras permitidas 1/2/4/8 bytes, alinhamento natural e validação de limites antes de ler/escrever; endereços KUSEG/KSEG2 continuam indisponíveis sem TLB.

### v0.96b — Add TLB implementation checklist

Checklist MMU/TLB: formato de entradas, ASID/global, permissões, exceções TLB refill/invalid/modified, tradução de páginas e testes de conflito ainda não implementados.
