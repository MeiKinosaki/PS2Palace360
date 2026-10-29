# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Versão de desenvolvimento

**Pacote de desenvolvimento: V2.0.23b** — identificador da rodada de trabalho; não indica compatibilidade completa nem versão estável do emulador.

### V2.0.21b — regressões adicionais de memória e TLB

Adicionados testes ao conjunto de host para rejeição de acessos desalinhados, larguras inválidas e operações fora do limite da RAM de teste; tradução TLB sem correspondência preservando o endereço físico de saída; mapeamento somente-leitura recusando escrita com status Modified; e visibilidade de entradas globais entre ASIDs. O código de testes foi enviado ao repositório, mas ainda não há resultado de execução confirmado para esta revisão. Os testes cobrem o protótipo atual, não certificam compatibilidade completa com o hardware PS2.

### V2.0.22b — entrada inicial em exceção para falha no fetch via TLB

O estado EE agora mantém um campo experimental `badvaddr`. O passo de execução com TLB distingue falha de tradução durante busca de instrução (gera entrada no helper com código TLBL) de endereço físico que não pode ser lido no buffer de teste (usa o código experimental IBE), e há um teste para o caso de TLB miss no fetch, verificando BadVAddr, EPC, Cause.ExcCode e vetor. Isto não implementa ainda a precisão completa do CP0/R5900, delay slots, nem a entrega correta de exceções de acessos de dados; os testes adicionados ainda precisam de execução CI confirmada.

### V2.0.23b — regressões de invalidação TLB verificadas no host

Adicionados testes para invalidação por ASID, preservação de mapeamento global durante a invalidação por ASID, invalidação completa e preservação do endereço físico de saída em uma falha de tradução. A primeira expectativa do novo teste foi corrigida após a CI revelar que uma entrada invalidada resulta em MISS. A validação nativa passou no commit `2f4ac8620c8e397766c45bb622a0a4d3dd2e2187`. A compilação Xbox 360 continua bloqueada porque o runner não encontrou `xenon-gcc`; nenhum `default.xex` foi confirmado nesta rodada.

## Núcleo Emotion Engine (EE)

O protótipo inclui estado básico do EE, decodificação parcial, operações aritméticas/lógicas, acessos à memória e uma função inicial de passo de execução. O conjunto experimental cobre parte das operações MIPS/R5900, incluindo operações HI/LO, multiplicação/divisão, deslocamentos de 32 e 64 bits e detecção inicial de overflow. As rodadas v0.80b–v0.81b encaminham overflow de `DADD`, `DSUB`, `DADDI`, `ADD`, `SUB` e `ADDI` ao mecanismo inicial de exceções. A v0.82b tornou portáveis os deslocamentos aritméticos de 32 bits e reforçou as verificações de limites da RAM. A v0.83b acrescenta testes de regressão para acessos de memória válidos no limite, acessos fora dos limites, desalinhamento, larguras inválidas e ponteiros nulos. A v0.85b nomeia os códigos de exceção experimentais e acrescenta testes para entrada em exceção em delay slot, registro de EPC/Cause.BD, seleção do vetor geral e preservação de EPC/Cause durante uma exceção aninhada com EXL ativo. Isso valida apenas o helper de entrada, não a precisão arquitetural completa. A v0.84b introduziu o esqueleto de tradução KSEG0/KSEG1. A v0.87b acrescenta funções experimentais de leitura/escrita virtual que passam pela tradução antes de acessar o buffer de RAM. A v0.88b ampliou os testes de acesso virtual para larguras de 1 e 8 bytes, leitura cruzada entre KSEG0/KSEG1, desalinhamento e limites do buffer. A v0.90b adiciona uma API de tradução com códigos de retorno distintos para ponteiro de saída inválido e segmento virtual ainda não suportado, preservando a função antiga com contrato 0/-1. A v0.89b adiciona testes de borda para o fim dos segmentos KSEG0/KSEG1, rejeição de segmentos não suportados, preservação do argumento de saída quando a tradução falha e ponteiros/RAM inválidos nos acessores virtuais. Isso conecta o protótipo de tradução ao buffer de testes, mas não implementa o mapa real de memória do PS2, MMU/TLB nem dispositivos. Esses testes foram adicionados ao conjunto de host, mas a execução CI desta rodada ainda precisa ser confirmada. Isso não substitui a implementação do mapa real de memória do PS2, MMU/TLB ou dispositivos.
## Limitações importantes

Este projeto ainda é um protótipo, não um emulador funcional de PS2. A semântica completa do MIPS III/R5900 não está implementada; faltam instruções e extensões específicas, exceções arquiteturais completas, MMU/TLB e tratamento preciso de delay slots. O buffer de RAM é apenas para testes e não representa o mapa real de memória do PS2. IOP, DMA, VU, GS, áudio, controles, mídia e boot de jogos não estão integrados.

## Toolchain na nuvem e artefato final

**Prioridade de saída: `default.xex`.** O fluxo de entrega deve gerar e validar diretamente o executável XEX como artefato principal; `Xenon.elf` não é mais tratado como produto final solicitado. Se o processo de compilação precisar de um ELF intermediário internamente, ele será apenas uma etapa técnica temporária e não o artefato principal publicado.

Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**. A validação de host usa `make validate` e `make test-host`. A compilação XEX exige runner configurado com `xenon-gcc` e `elf2xex`; o runner padrão do GitHub não inclui essas ferramentas automaticamente. O alvo `make xex` gera `build/default.xex`; o ELF de entrada fica apenas como intermediário interno. O workflow publica somente `default.xex` e seu checksum, após compilação bem-sucedida. O `src/main.c` ainda é um bootstrap vazio e não inicializa o runtime de vídeo/controles nem executa jogos PS2: mesmo que o XEX seja gerado, ele não representa um emulador funcional.

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

### v0.97b — Add host validation checklist

Checklist de host: executar `make validate`, `make test-host` e registrar saída/compilador; nenhuma execução é declarada bem-sucedida sem logs.

### v0.98b — Clarify Xenon build prerequisites

Build Xenon: confirmar existência do toolchain libXenon, flags e linker script antes de declarar artefatos. Nenhum `Xenon.elf` ou `default.xex` foi validado nesta rodada.

### v0.99b — Add staged EE memory roadmap

Ordem de implementação: MMU/TLB → mapa físico EE → exceções de acesso → instruções load/store → IOP/DMA → VU → GS → áudio/entrada → boot e compatibilidade de jogos.

### v0.100b — Summarize ten-round development batch

Fechamento do lote: dez marcos sequenciais de planejamento/documentação foram registrados; isso não equivale a dez implementações completas nem a dez versões testadas. O núcleo continua experimental.


## v0.101b — TLB experimental de 4 KiB

- Adicionado scaffold de TLB indexada com 16 entradas de teste, páginas de 4 KiB, ASID, bit global, validade e permissão de escrita (dirty).
- Adicionadas rotinas de reset, escrita de entrada e tradução, com códigos separados para argumento inválido, miss, entrada inválida e tentativa de escrita sem dirty.
- Testes de regressão foram adicionados para hit, offset, ASID, miss, invalid, modified e argumentos inválidos.
- **Limitações:** isto ainda não é a MMU real do R5900/Emotion Engine. Não há PageMask variável, CP0, substituição Random/Wired, integração automática com acessos virtuais, exceções arquiteturais de TLB ou validação de compatibilidade com jogos. Os testes foram escritos, mas a execução e a compilação não foram confirmadas nesta rodada.

### Lote solicitado de dez avanços

Foram preservados os marcos de documentação v0.92b–v0.100b; o avanço com código nesta rodada é v0.101b. Os marcos documentais não devem ser interpretados como dez versões de código completas.


## v0.102b — Gestão experimental da tabela TLB

- Adicionadas rotinas para selecionar ASID atual, consultar uma entrada por índice e invalidar entradas não globais de um ASID.
- Acrescentados testes de regressão para consulta, invalidação seletiva (entradas globais preservadas) e argumentos inválidos.
- Estes helpers operam sobre a tabela experimental em memória; ainda não reproduzem os comandos CP0 nem toda a semântica TLB do R5900. Testes escritos não significam execução confirmada.


## v0.103b — Despachante de tradução

- Adicionada função experimental que escolhe tradução direta para KSEG0/KSEG1 e consulta a tabela TLB de protótipo para outros endereços.
- Testes escritos para tradução direta, miss sem alterar o endereço de saída, acerto via TLB e ponteiro inválido.
- Não está ligada automaticamente aos acessos `ps2_ee_mem_load_virtual_ex`/`store`; também não implementa CP0 nem exceções de TLB. Execução dos testes não confirmada.


## v0.104b — Acessos de memória ligados à TLB experimental

- Adicionadas funções separadas para leitura/escrita virtual que passam pelo despachante de tradução direta/TLB antes de validar e acessar o buffer RAM de teste.
- Adicionados testes para acesso traduzido, miss, argumentos inválidos e leitura/escrita básica.
- Limitações: os acessos antigos não foram redirecionados automaticamente para esta API; a RAM continua sendo um buffer de teste, não o mapa físico completo do PS2. O código de TLB é um protótipo de páginas de 4 KiB, não a MMU R5900 completa. Testes escritos não confirmam execução.


## v0.105b — Consulta de entrada TLB

- Helper de consulta por página virtual com filtro por ASID/global; testes de hit/miss e ponteiro inválido foram escritos.

## v0.106b — Regressões da consulta TLB

- Testes adicionais registram filtragem por ASID e escolha de entrada correspondente. Execução não confirmada.

## v0.107b — Verificação de permissões TLB

- Helper separa consulta da página e validação de entrada válida/permissão de escrita, sem traduzir endereço físico.

## v0.108b — Testes de permissões TLB

- Adicionados casos para miss, invalid, leitura permitida, escrita sem dirty e escrita permitida. O TLB continua experimental, sem integração completa com CP0 ou exceções arquiteturais.


## v0.109b — Diagnóstico de entradas TLB

- Adicionado contador de entradas marcadas como válidas para facilitar inspeção de testes.

## v0.110b — Testes do diagnóstico TLB

- Testes escritos para tabela vazia, entrada válida, entrada inválida, invalidação por ASID e ponteiro nulo. A execução da suíte ainda precisa ser confirmada em ambiente de compilação.

## Limites desta rodada

As etapas v0.101b–v0.110b não equivalem a uma MMU completa nem a dez versões de emulador prontas. O protótipo TLB usa uma tabela pequena com páginas fixas de 4 KiB; a arquitetura real do Emotion Engine tem uma TLB maior e detalhes de CP0, caches e exceções que ainda precisam ser modelados. Referência técnica: https://israpps.github.io/ps2tek/PS2/EE/ e https://github.com/mamedev/mame/blob/master/src/devices/cpu/mips/mips3.cpp


## Migração de versão — V2.0.0b

A partir deste marco, a numeração oficial passa a seguir a série **V2.0.0b, V2.0.1b, V2.0.2b, V2.0.3b…**, avançando uma versão por vez sem saltos. A série anterior (v0.101b–v0.110b) permanece no histórico como histórico técnico; não é apagada nem renumerada retroativamente.

**Versão oficial atual: V2.0.0b.** A mudança de número é uma decisão de versionamento, não uma alegação de que a emulação de PS2 está pronta ou que os testes/builds foram aprovados.


## V2.0.1b — Invalidação integral da TLB experimental

- Implementada `ps2_ee_tlb_invalidate_all`, que marca todas as entradas como inválidas, incluindo entradas globais; não apaga seus metadados e não altera o ASID atual.
- Adicionados testes para entradas globais e não globais, contador de entradas válidas após invalidação, miss posterior e argumento nulo.
- O código e os testes foram enviados ao repositório. **A execução da suíte e a compilação continuam não confirmadas**; a TLB segue como protótipo de páginas fixas de 4 KiB, sem integração completa com CP0 e exceções arquiteturais.


## V2.0.2b — Diagnóstico de correspondências duplicadas na TLB

- Adicionada `ps2_ee_tlb_count_matches`, que conta entradas válidas da página virtual consultada compatíveis com o ASID ativo ou marcadas como globais.
- Testes adicionados para tabela vazia, ASID incompatível, duas entradas coincidentes, entrada global, entrada inválida e ponteiro nulo.
- A função é somente diagnóstica: não altera entradas, não escolhe uma tradução e não implementa o comportamento arquitetural de múltiplos hits/shutdown do R5900. **Testes e compilação ainda não foram executados/verificados nesta rodada.**


## V2.0.3b — detecção de múltiplas traduções TLB

- Adicionado o estado `PS2_EE_TLB_ERR_MULTIPLE`.
- `ps2_ee_tlb_translate` passa a contar correspondências válidas compatíveis com ASID/global e retorna erro explícito quando mais de uma entrada válida corresponde à página, em vez de escolher silenciosamente a primeira.
- O endereço físico de saída não é alterado no caso de múltiplas correspondências.
- Testes adicionados para colisão e para ausência de tradução após invalidação integral.
- Limite: isto é uma proteção diagnóstica do protótipo, não uma implementação completa do comportamento de shutdown/exceções do R5900. A compilação e execução dos testes não foram confirmadas nesta rodada.


## V2.0.4b — Prioridade de entrega `default.xex`

- A meta de build foi reorganizada: `default.xex` é o artefato principal a produzir e validar.
- `Xenon.elf`, se necessário internamente pela toolchain, fica como etapa intermediária e não como saída final solicitada.
- Esta atualização altera a prioridade/documentação do fluxo; não afirma que o XEX já foi compilado, carregado ou validado em Xbox 360.
- Próxima etapa técnica: inspecionar workflow e Makefile, configurar a geração/conversão para XEX e publicar o artefato apenas após um build bem-sucedido.


## V2.0.4b — geração de default.xex como artefato principal

- O Makefile agora define `make xex` como alvo real: compila `src/main.c` e os módulos EE com `xenon-gcc`, usa `elf2xex` e exige que `build/default.xex` exista e não esteja vazio.
- O ELF intermediário é chamado `build/ps2palace360.elf` e não é publicado como artefato final.
- O workflow verifica as ferramentas necessárias e publica somente `build/default.xex` e seu checksum.
- Limite importante: `src/main.c` continua sendo um bootstrap vazio; gerar um XEX não significa que o emulador tenha runtime Xbox funcional ou consiga executar jogos PS2. Build ainda depende de runner com libXenon e elf2xex; a execução não foi confirmada nesta atualização.


## V2.0.5b — pré-verificação explícita da toolchain

- Adicionado o alvo `make toolchain-check`, que verifica `xenon-gcc` e `elf2xex` antes da etapa de geração do `default.xex`.
- O workflow chama a pré-verificação antes do build e mantém a publicação condicionada ao sucesso de todas as etapas.
- Isto melhora o diagnóstico de dependências, mas não instala automaticamente a toolchain no runner do GitHub. O bootstrap em `src/main.c` continua vazio; build, testes e execução em console permanecem não verificados.


## V2.0.6b — ordem segura de pré-verificação

- A verificação `toolchain-check` agora é uma dependência de ordem do alvo ELF intermediário, de modo que a compilação só começa depois de confirmar `xenon-gcc` e `elf2xex`, inclusive em builds paralelos do Make.
- O alvo XEX não repete a dependência de verificação: ela ocorre antes da compilação, evitando que uma execução paralela inicie o compilador antes da checagem.
- Ainda não há evidência de build/CI bem-sucedido nesta rodada; a toolchain não é instalada pelo workflow e `src/main.c` segue como placeholder sem runtime de Xbox 360.


## V2.0.7b — validação de artefatos intermediários

- Após `xenon-gcc`, o alvo verifica que o ELF intermediário existe e não está vazio; se falhar, remove o arquivo inválido e interrompe a compilação.
- Antes de chamar `elf2xex`, o alvo confirma novamente que o ELF de entrada é não vazio. A validação do `default.xex` após conversão permanece ativa.
- São verificações de integridade básica, não uma prova de que o XEX inicializa no Xbox 360. Nenhum build foi confirmado nesta rodada.


## V2.0.8b — validação de fontes e entrypoint

- `make validate` agora percorre os módulos listados em `EE_SOURCES` e falha se algum arquivo estiver ausente ou vazio.
- A validação confirma também que `src/main.c` contém uma declaração de `main()`; isso é apenas um contrato estrutural, não comprova inicialização de libXenon ou funcionamento do runtime.
- A execução de `make validate`, dos testes host e do workflow ainda deve ser confirmada por logs reais.


## V2.0.9b — validação do arquivo de testes

- `make validate` também falha se `tests/test_ee_state.c` existir, mas estiver vazio.
- A validação estrutural agora verifica a presença e o conteúdo dos módulos EE e da fonte de testes, além da declaração `main()`.
- Isto evita falsos positivos de arquivos vazios; não comprova a qualidade dos testes, nem substitui `make test-host` ou o build real de XEX.


## V2.0.10b — validação antes do compilador Xenon

- O alvo ELF intermediário agora depende também de `validate`, além da verificação da toolchain. Assim, `make xex` aplica as checagens estruturais antes de invocar `xenon-gcc`.
- A checagem pode ser repetida por Make, mas é idempotente e não altera fontes. Nenhum build foi declarado aprovado sem logs.


## V2.0.11b — diagnóstico de disponibilidade da toolchain no CI

- A etapa de validação host agora registra se `xenon-gcc` e `elf2xex` estão presentes no runner, sem falhar o conjunto de testes host só por faltar a toolchain Xenon.
- O job Xbox continua exigindo ambas as ferramentas e falhará explicitamente se não estiverem instaladas; esta alteração não instala libXenon nem comprova build XEX.


## V2.0.12b — aviso de bootstrap incompleto

- `make validate` agora emite aviso explícito quando detecta que `src/main.c` ainda está marcado como placeholder, sem converter essa limitação em falso sucesso de runtime.
- A checagem continua estrutural; a implementação do entrypoint Xbox, vídeo, controles e loop principal segue pendente.


## V2.0.13b — finalização protegida do XEX

- `elf2xex` grava primeiro em `build/default.xex.tmp`; o Makefile só renomeia para `build/default.xex` depois de verificar que o arquivo temporário não está vazio.
- Se a conversão falhar, o arquivo temporário é removido e o nome final não é publicado por esta etapa. Isso reduz o risco de deixar um XEX parcial com nome de artefato final.
- A checagem é integridade básica por tamanho; não valida cabeçalho XEX, carregamento em console ou execução de jogos.


## V2.0.14b — lookup TLB ignora entradas inválidas

- Corrigido `ps2_ee_tlb_lookup`: entradas marcadas como inválidas deixam de ser retornadas como acertos e não podem sombrear uma entrada válida posterior.
- O helper agora retorna `PS2_EE_TLB_ERR_MULTIPLE` quando há mais de uma entrada válida compatível com página e ASID/global, mantendo o parâmetro de saída intacto em miss/conflito.
- Foram adicionados casos de regressão para entrada inválida e conflito duplicado. Os testes foram escritos, mas a execução precisa de log CI/host antes de declarar aprovação.
- A TLB continua experimental: páginas fixas de 4 KiB, 16 entradas e sem integração completa com CP0/R5900.


## V2.0.15b — contrato de saída do lookup TLB

- Testes adicionais verificam que o objeto de saída não é modificado quando o lookup encontra múltiplas entradas válidas ou não encontra nenhuma tradução.
- Os casos complementam a V2.0.14b; foram registrados como código de teste, mas não são apresentados como aprovados até haver execução real da suíte.


## V2.0.16b — regressões de ASID e mapeamentos globais

- Acrescentados casos de teste para confirmar que uma entrada não global de outro ASID não atende ao lookup, enquanto uma entrada global pode atender ao ASID atual.
- O caso também verifica que uma entrada global e uma entrada não global que passam a corresponder simultaneamente geram `PS2_EE_TLB_ERR_MULTIPLE`, sem escolher uma tradução arbitrária.
- **Estado:** testes adicionados ao repositório; execução da suíte, build Xenon, geração de `default.xex` e boot em console ainda não confirmados. Isto melhora a cobertura do protótipo TLB, mas não torna o emulador funcional nem justifica declarar 25% de implementação global.


## V2.0.19b — Instruções escalares de memória com tradução TLB experimental

- Adicionada a API `ps2_ee_execute_memory_word_tlb`, que encaminha LB/LBU, LH/LHU, LW/LWU, LD, SB/SH/SW/SD ao caminho de memória virtual com tradução direta KSEG0/KSEG1 ou TLB experimental.
- A extensão de sinal de LB/LH/LW é aplicada na carga; LBU/LHU/LWU preservam o valor sem sinal.
- Acrescentados casos de teste para LW com extensão de sinal, LWU, SW, endereço sem mapeamento e múltiplas correspondências TLB.
- **Limitações:** a API é explícita e não substitui ainda o caminho antigo de execução; falhas de tradução/acesso retornam `PS2_EE_STEP_INVALID` e ainda não geram exceções CP0 arquiteturalmente corretas. Não foram declarados testes executados nem build Xenon concluído nesta rodada. O runtime continua placeholder e `default.xex` funcional permanece não validado.


## V2.0.20b — Ciclo EE com busca de instrução via TLB experimental

- Nova API `ps2_ee_step_tlb`: busca a instrução pela memória virtual/TLB experimental e a encaminha ao dispatcher de loads/stores com TLB.
- Adicionado teste de integração unitária que mapeia páginas virtuais de código e dados para RAM, executa um `LW` e verifica o registrador de destino e avanço do PC.
- Limitações mantidas explícitas: não há ainda entrada arquitetural em CP0 para miss/invalid/modified, delay slots completos, MMIO ou mapa físico real do PS2.
- A alteração foi registrada no repositório; não foi possível confirmar execução de CI/build neste turno.

## Validação automatizada e limites atuais

O workflow `Host validation` executa `make check` em runner Linux para compilar e rodar os testes do núcleo em host. Isso não equivale a uma compilação Xenon nem comprova execução no Xbox 360; o resultado só deve ser considerado aprovado depois que o workflow terminar com sucesso.

O caminho experimental `ps2_ee_step_tlb` busca a instrução via TLB e encaminha a execução para o decodificador de memória. Ainda não implementa exceções CP0 completas, delay slots arquiteturalmente corretos, nem fidelidade integral do R5900. Falhas de tradução continuam retornando `PS2_EE_STEP_INVALID`.

## Backlog de engenharia

O plano granular de 20.000 etapas está em [`docs/ROADMAP_20000_ETAPAS.md`](docs/ROADMAP_20000_ETAPAS.md). Os itens começam pendentes; a lista não representa 20.000 implementações concluídas. O cabeçalho do decodificador e o arquivo de testes tiveram escapes de nova linha literais corrigidos. A validação automatizada ainda precisa de uma execução aprovada para confirmar compilação e testes.

## Plano de 10.000.000 de etapas

O plano de dez milhões de tarefas é documentado em [`docs/PLANO_10000000_ETAPAS.md`](docs/PLANO_10000000_ETAPAS.md), com gerador paginado em [`tools/generate_10000000_step_backlog.py`](tools/generate_10000000_step_backlog.py). Para evitar um arquivo impraticável, o gerador emite até 100.000 itens por execução. Todos começam pendentes; a quantidade de tarefas planejadas não representa progresso funcional nem substitui build/testes.

## Plano operacional de 5.000 etapas

O recorte operacional de 5.000 etapas e seus critérios de aceite estão em [`docs/PLANO_5000_ETAPAS.md`](docs/PLANO_5000_ETAPAS.md). Gere o CSV com o script paginado; todas as tarefas começam pendentes. O plano prioriza primeiro build/testes e correções de TLB/exceções antes de subsistemas maiores.
