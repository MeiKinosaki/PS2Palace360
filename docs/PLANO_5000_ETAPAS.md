# PS2Palace360 — plano de 5.000 etapas

Este plano de 5.000 etapas é um recorte operacional de curto prazo dentro do plano maior de 10.000.000. As etapas aqui listadas são tarefas, não implementações concluídas. Para manter o repositório revisável, o gerador paginado é reutilizado e cada etapa é numerada no CSV de saída.

## Gerar as 5.000 etapas

```sh
python3 tools/generate_10000000_step_backlog.py --start 1 --count 5000 > backlog-00000001-00005000.csv
```

## Sequência de execução

1. Confirmar sintaxe e build host com `make check`.
2. Corrigir falhas de compilação e testes antes de adicionar funcionalidades.
3. Expandir testes de TLB: miss, entrada inválida, escrita em página não dirty, ASID/global e múltiplas correspondências.
4. Ligar erros de tradução a um mecanismo de exceções que preserve PC, EPC, Cause e endereço da falha; acrescentar BadVAddr ao estado quando apropriado.
5. Implementar delay slots e fluxo de branches com testes de regressão.
6. Expandir cobertura R5900 com instruções individualmente testadas.
7. Integrar IOP/DMA e definir contratos entre subsistemas antes de implementar dispositivos.
8. Adicionar testes de regressão para VU0/VU1, GIF/GS, SPU2, CD/DVD e entrada.
9. Preparar runtime libXenon e testar separadamente compilação ELF e conversão XEX.
10. Validar o `default.xex` no console; registrar logs e compatibilidade por jogo.

## Critérios de aceite

- Nenhuma etapa marcada como concluída sem commit e evidência específica.
- `make check` deve terminar com código zero para declarar os testes host aprovados.
- A toolchain Xenon deve estar instalada no ambiente de build para produzir o ELF.
- Só declarar `default.xex` gerado após confirmar que o artefato existe e não está vazio; só declarar funcional após teste real no Xbox 360.

## Estado verificado nesta rodada

O cabeçalho `src/ps2/ee_decode.h` foi corrigido e o literal `\\n` em `tests/test_ee_state.c` foi removido em commits anteriores. A execução aprovada do workflow, os testes host e o runtime Xbox ainda não foram confirmados. O arquivo `src/main.c` segue como bootstrap placeholder.
