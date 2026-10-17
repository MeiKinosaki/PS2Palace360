# Plano PS2Palace360 — 10.000.000 de etapas

Este plano define um universo de 10.000.000 IDs de tarefas. **São tarefas planejadas, não dez milhões de implementações concluídas.** Para não criar um arquivo gigante impossível de revisar, as etapas são geradas em páginas CSV sob demanda.

## Gerador

Arquivo: `tools/generate_10000000_step_backlog.py`

Exemplos de uso local:

```sh
# Gerar as primeiras 1.000 tarefas
python3 tools/generate_10000000_step_backlog.py > backlog-00000001-00001000.csv

# Gerar 1.000 tarefas começando no ID 50.001
python3 tools/generate_10000000_step_backlog.py --start 50001 --count 1000 > backlog-00050001-00051000.csv

# Gerar uma página de até 100.000 itens
python3 tools/generate_10000000_step_backlog.py --start 100001 --count 100000 > backlog-page.csv
```

O gerador limita cada execução a 100.000 linhas para manter as saídas gerenciáveis. Ele não altera automaticamente o status de nenhuma tarefa. Os campos de status possíveis para o acompanhamento humano são: pendente, implementado sem verificação, compilado sem verificação, testes aprovados e verificado no hardware. A saída inicial marca tudo como `pending`.

## Áreas cobertas

1. EE/R5900 e decodificador
2. Registradores, HI/LO e aritmética
3. Exceções CP0 e interrupções
4. TLB e memória virtual
5. Memória física e MMIO
6. IOP
7. DMA
8. VU0
9. VU1
10. GIF
11. GS
12. Texturas e framebuffer
13. Áudio SPU2
14. CD/DVD e sistema de arquivos
15. Controladores e multitap
16. BIOS e boot
17. Scheduler e temporização
18. JIT/dynarec para Xenon
19. Apresentação de vídeo/Xenos
20. Runtime libXenon e entrada
21. Toolchain PowerPC/Xenon
22. ELF/XEX
23. Testes unitários e regressão
24. Compatibilidade por jogo
25. Save states e cartões de memória
26. Lista de jogos, capas e interface
27. Configuração por jogo
28. Logs e recuperação de falhas
29. Licenças e documentação
30. CI e validação em hardware

## Critérios obrigatórios

- Uma tarefa só passa a concluída com alteração rastreável e evidência correspondente.
- Código escrito não é prova de compilação; compilação não é prova de teste; teste host não é prova de funcionamento no Xbox 360.
- A integração de hardware e a criação de `default.xex` continuam dependentes de runtime e toolchain Xenon reais.
- O estado atual não deve ser inflado por criar IDs ou gerar mais linhas de planejamento.
