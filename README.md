# PS2Palace360

Emulador experimental de PlayStation 2 para Xbox 360.

## Estado atual

A base inclui estado do Emotion Engine (EE), operações aritméticas/lógicas parciais, comparações, movimentos condicionais, decodificação de um subconjunto MIPS e buffer de RAM de teste.

`ps2_ee_execute_word()` inclui instruções R-type e imediatas, deslocamentos, operações lógicas imediatas, saltos e desvios básicos (`J`, `JAL`, `JR`, `JALR`, `BEQ`, `BNE`, `BLEZ`, `BGTZ`). `ps2_ee_execute_memory_word()` inclui `LB`, `LBU`, `LH`, `LHU`, `LW`, `LWU`, `LD`, `SB`, `SH`, `SW` e `SD`. `ps2_ee_step()` busca uma instrução no buffer, avança o estado PC/next-PC e despacha a instrução; os desvios básicos agendam o destino para depois da instrução de delay slot.

## Limitações importantes

Este é um protótipo de execução, não um emulador funcional. O buffer de RAM é genérico e não representa o mapa real de memória do PS2. O ciclo de execução ainda não modela corretamente todas as regras MIPS/R5900; exceções, overflow arquitetural, branch-likely, estados de delay-slot para exceções, MMU/TLB e instruções de 64 bits específicas ainda estão incompletos. IOP, DMA, VU, GS, áudio, controles e mídia não estão integrados. Não há inicialização de jogos comprovada.

## Validação na nuvem

1. Abra **Actions** e execute **PS2Palace360 - Cloud Toolchain**.
2. A workflow de host deve executar `make validate` e `make test-host`.
3. A compilação Xbox 360 exige um runner configurado com libXenon; o runner padrão do GitHub não inclui `xenon-gcc` automaticamente.

## Testes de host

    make validate
    make test-host

O alvo `xex` ainda não produz um executável. Ele requer toolchain libXenon validada, entrypoint Xbox 360 e comando `elf2xex` verificado.

## BIOS

Nenhuma BIOS é distribuída. Quando houver loader, use apenas uma imagem extraída legalmente do seu próprio console.

## Licença

Consulte [LICENSE](LICENSE).
