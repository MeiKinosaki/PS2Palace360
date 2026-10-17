# PS2Palace360 — plano sequencial de 500 etapas

**Status:** plano de execução; nenhuma caixa abaixo significa concluída. A contagem organiza o trabalho, não mede implementação já existente. Cada etapa só deve ser marcada como concluída depois de código integrado, teste executado e evidência registrada quando aplicável.

**Regra de progresso:** documentação, checklist ou código enviado sem build/teste não aumenta automaticamente a porcentagem de implementação funcional. O artefato final solicitado continua sendo `build/default.xex`; `ELF` é apenas intermediário. Não declarar boot de jogos ou compatibilidade sem teste real.

**Licença PCSX2:** o projeto upstream usa GPL-3.0-or-later. Antes de importar código, registrar a revisão, manter avisos de copyright/licença, preservar a licença aplicável e preparar a distribuição do código-fonte correspondente. Referência: https://github.com/PCSX2/pcsx2

## Etapas (500 no total)

001. [ ] **Base e build:** Registrar versão, commit e estado inicial do build
002. [ ] **Base e build:** Validar headers públicos e dependências
003. [ ] **Base e build:** Validar compilação estrita C11 no host
004. [ ] **Base e build:** Corrigir warnings tratados como erro
005. [ ] **Base e build:** Executar suíte de testes do host
006. [ ] **Base e build:** Adicionar teste de inicialização do estado EE
007. [ ] **Base e build:** Verificar invariantes de GPR zero
008. [ ] **Base e build:** Verificar reset de HI/LO e registradores de controle
009. [ ] **Base e build:** Separar testes unitários por módulo
010. [ ] **Base e build:** Adicionar resumo reproduzível de comandos de build
011. [ ] **Base e build:** Registrar versão, commit e estado inicial do build — rodada 2: especificar, implementar e testar
012. [ ] **Base e build:** Validar headers públicos e dependências — rodada 2: especificar, implementar e testar
013. [ ] **Base e build:** Validar compilação estrita C11 no host — rodada 2: especificar, implementar e testar
014. [ ] **Base e build:** Corrigir warnings tratados como erro — rodada 2: especificar, implementar e testar
015. [ ] **Base e build:** Executar suíte de testes do host — rodada 2: especificar, implementar e testar
016. [ ] **Base e build:** Adicionar teste de inicialização do estado EE — rodada 2: especificar, implementar e testar
017. [ ] **Base e build:** Verificar invariantes de GPR zero — rodada 2: especificar, implementar e testar
018. [ ] **Base e build:** Verificar reset de HI/LO e registradores de controle — rodada 2: especificar, implementar e testar
019. [ ] **Base e build:** Separar testes unitários por módulo — rodada 2: especificar, implementar e testar
020. [ ] **Base e build:** Adicionar resumo reproduzível de comandos de build — rodada 2: especificar, implementar e testar
021. [ ] **Base e build:** Registrar versão, commit e estado inicial do build — rodada 3: especificar, implementar e testar
022. [ ] **Base e build:** Validar headers públicos e dependências — rodada 3: especificar, implementar e testar
023. [ ] **Base e build:** Validar compilação estrita C11 no host — rodada 3: especificar, implementar e testar
024. [ ] **Base e build:** Corrigir warnings tratados como erro — rodada 3: especificar, implementar e testar
025. [ ] **Base e build:** Executar suíte de testes do host — rodada 3: especificar, implementar e testar
026. [ ] **Base e build:** Adicionar teste de inicialização do estado EE — rodada 3: especificar, implementar e testar
027. [ ] **Base e build:** Verificar invariantes de GPR zero — rodada 3: especificar, implementar e testar
028. [ ] **Base e build:** Verificar reset de HI/LO e registradores de controle — rodada 3: especificar, implementar e testar
029. [ ] **Base e build:** Separar testes unitários por módulo — rodada 3: especificar, implementar e testar
030. [ ] **Base e build:** Adicionar resumo reproduzível de comandos de build — rodada 3: especificar, implementar e testar
031. [ ] **Base e build:** Registrar versão, commit e estado inicial do build — rodada 4: especificar, implementar e testar
032. [ ] **Base e build:** Validar headers públicos e dependências — rodada 4: especificar, implementar e testar
033. [ ] **Base e build:** Validar compilação estrita C11 no host — rodada 4: especificar, implementar e testar
034. [ ] **Base e build:** Corrigir warnings tratados como erro — rodada 4: especificar, implementar e testar
035. [ ] **Base e build:** Executar suíte de testes do host — rodada 4: especificar, implementar e testar
036. [ ] **Base e build:** Adicionar teste de inicialização do estado EE — rodada 4: especificar, implementar e testar
037. [ ] **Base e build:** Verificar invariantes de GPR zero — rodada 4: especificar, implementar e testar
038. [ ] **Base e build:** Verificar reset de HI/LO e registradores de controle — rodada 4: especificar, implementar e testar
039. [ ] **Base e build:** Separar testes unitários por módulo — rodada 4: especificar, implementar e testar
040. [ ] **Base e build:** Adicionar resumo reproduzível de comandos de build — rodada 4: especificar, implementar e testar
041. [ ] **Base e build:** Registrar versão, commit e estado inicial do build — rodada 5: especificar, implementar e testar
042. [ ] **Base e build:** Validar headers públicos e dependências — rodada 5: especificar, implementar e testar
043. [ ] **Base e build:** Validar compilação estrita C11 no host — rodada 5: especificar, implementar e testar
044. [ ] **Base e build:** Corrigir warnings tratados como erro — rodada 5: especificar, implementar e testar
045. [ ] **Base e build:** Executar suíte de testes do host — rodada 5: especificar, implementar e testar
046. [ ] **Base e build:** Adicionar teste de inicialização do estado EE — rodada 5: especificar, implementar e testar
047. [ ] **Base e build:** Verificar invariantes de GPR zero — rodada 5: especificar, implementar e testar
048. [ ] **Base e build:** Verificar reset de HI/LO e registradores de controle — rodada 5: especificar, implementar e testar
049. [ ] **Base e build:** Separar testes unitários por módulo — rodada 5: especificar, implementar e testar
050. [ ] **Base e build:** Adicionar resumo reproduzível de comandos de build — rodada 5: especificar, implementar e testar
051. [ ] **EE/R5900 e CP0:** Inventariar opcodes suportados no decoder
052. [ ] **EE/R5900 e CP0:** Inventariar opcodes ausentes do decoder
053. [ ] **EE/R5900 e CP0:** Validar operações aritméticas de 32 bits
054. [ ] **EE/R5900 e CP0:** Validar operações aritméticas de 64 bits
055. [ ] **EE/R5900 e CP0:** Validar overflow e exceções aritméticas
056. [ ] **EE/R5900 e CP0:** Validar operações lógicas imediatas
057. [ ] **EE/R5900 e CP0:** Validar comparações assinadas e não assinadas
058. [ ] **EE/R5900 e CP0:** Validar shifts fixos de 32 bits
059. [ ] **EE/R5900 e CP0:** Validar shifts variáveis de 32 bits
060. [ ] **EE/R5900 e CP0:** Validar shifts fixos de 64 bits
061. [ ] **EE/R5900 e CP0:** Validar shifts variáveis de 64 bits
062. [ ] **EE/R5900 e CP0:** Validar multiplicação e divisão HI/LO
063. [ ] **EE/R5900 e CP0:** Validar casos extremos de divisão
064. [ ] **EE/R5900 e CP0:** Validar branches condicionais
065. [ ] **EE/R5900 e CP0:** Validar jumps e links
066. [ ] **EE/R5900 e CP0:** Modelar delay slots com testes
067. [ ] **EE/R5900 e CP0:** Implementar syscall e validar exceção
068. [ ] **EE/R5900 e CP0:** Implementar break e validar exceção
069. [ ] **EE/R5900 e CP0:** Implementar traps suportados pelo EE
070. [ ] **EE/R5900 e CP0:** Definir comportamento explícito para opcode reservado
071. [ ] **EE/R5900 e CP0:** Inventariar registradores CP0 relevantes
072. [ ] **EE/R5900 e CP0:** Definir máscara e campos de Status
073. [ ] **EE/R5900 e CP0:** Definir campos de Cause
074. [ ] **EE/R5900 e CP0:** Implementar leitura controlada de CP0
075. [ ] **EE/R5900 e CP0:** Implementar escrita controlada de CP0
076. [ ] **EE/R5900 e CP0:** Modelar EXL e entrada em exceção
077. [ ] **EE/R5900 e CP0:** Modelar EPC e Cause.BD
078. [ ] **EE/R5900 e CP0:** Validar exceções aninhadas
079. [ ] **EE/R5900 e CP0:** Modelar seleção do vetor de exceção
080. [ ] **EE/R5900 e CP0:** Adicionar BadVAddr quando necessário
081. [ ] **EE/R5900 e CP0:** Modelar permissões de privilégio
082. [ ] **EE/R5900 e CP0:** Implementar instruções MFC0 e MTC0 necessárias
083. [ ] **EE/R5900 e CP0:** Validar efeitos de ERET
084. [ ] **EE/R5900 e CP0:** Validar interrupções pendentes
085. [ ] **EE/R5900 e CP0:** Adicionar testes por código de exceção
086. [ ] **EE/R5900 e CP0:** Inventariar opcodes suportados no decoder — rodada 2: especificar, implementar e testar
087. [ ] **EE/R5900 e CP0:** Inventariar opcodes ausentes do decoder — rodada 2: especificar, implementar e testar
088. [ ] **EE/R5900 e CP0:** Validar operações aritméticas de 32 bits — rodada 2: especificar, implementar e testar
089. [ ] **EE/R5900 e CP0:** Validar operações aritméticas de 64 bits — rodada 2: especificar, implementar e testar
090. [ ] **EE/R5900 e CP0:** Validar overflow e exceções aritméticas — rodada 2: especificar, implementar e testar
091. [ ] **EE/R5900 e CP0:** Validar operações lógicas imediatas — rodada 2: especificar, implementar e testar
092. [ ] **EE/R5900 e CP0:** Validar comparações assinadas e não assinadas — rodada 2: especificar, implementar e testar
093. [ ] **EE/R5900 e CP0:** Validar shifts fixos de 32 bits — rodada 2: especificar, implementar e testar
094. [ ] **EE/R5900 e CP0:** Validar shifts variáveis de 32 bits — rodada 2: especificar, implementar e testar
095. [ ] **EE/R5900 e CP0:** Validar shifts fixos de 64 bits — rodada 2: especificar, implementar e testar
096. [ ] **EE/R5900 e CP0:** Validar shifts variáveis de 64 bits — rodada 2: especificar, implementar e testar
097. [ ] **EE/R5900 e CP0:** Validar multiplicação e divisão HI/LO — rodada 2: especificar, implementar e testar
098. [ ] **EE/R5900 e CP0:** Validar casos extremos de divisão — rodada 2: especificar, implementar e testar
099. [ ] **EE/R5900 e CP0:** Validar branches condicionais — rodada 2: especificar, implementar e testar
100. [ ] **EE/R5900 e CP0:** Validar jumps e links — rodada 2: especificar, implementar e testar
101. [ ] **Memória e TLB:** Documentar mapa físico EE com referências
102. [ ] **Memória e TLB:** Separar endereços virtuais e físicos
103. [ ] **Memória e TLB:** Modelar segmentos diretos KSEG0/KSEG1
104. [ ] **Memória e TLB:** Definir estrutura de entrada TLB fiel à arquitetura
105. [ ] **Memória e TLB:** Modelar PageMask quando aplicável
106. [ ] **Memória e TLB:** Modelar ASID e bit global
107. [ ] **Memória e TLB:** Modelar EntryLo e permissões
108. [ ] **Memória e TLB:** Implementar lookup TLB determinístico
109. [ ] **Memória e TLB:** Detectar múltiplos hits TLB
110. [ ] **Memória e TLB:** Modelar invalid e modified faults
111. [ ] **Memória e TLB:** Modelar TLB refill e seus vetores
112. [ ] **Memória e TLB:** Integrar tradução aos loads
113. [ ] **Memória e TLB:** Integrar tradução aos stores
114. [ ] **Memória e TLB:** Integrar erros de alinhamento
115. [ ] **Memória e TLB:** Integrar exceções de endereço
116. [ ] **Memória e TLB:** Separar RAM de teste da memória física real
117. [ ] **Memória e TLB:** Adicionar regiões MMIO
118. [ ] **Memória e TLB:** Adicionar regiões reservadas e aliases
119. [ ] **Memória e TLB:** Adicionar testes de fronteira do mapa
120. [ ] **Memória e TLB:** Validar leitura/escrita end-to-end
121. [ ] **Memória e TLB:** Documentar mapa físico EE com referências — rodada 2: especificar, implementar e testar
122. [ ] **Memória e TLB:** Separar endereços virtuais e físicos — rodada 2: especificar, implementar e testar
123. [ ] **Memória e TLB:** Modelar segmentos diretos KSEG0/KSEG1 — rodada 2: especificar, implementar e testar
124. [ ] **Memória e TLB:** Definir estrutura de entrada TLB fiel à arquitetura — rodada 2: especificar, implementar e testar
125. [ ] **Memória e TLB:** Modelar PageMask quando aplicável — rodada 2: especificar, implementar e testar
126. [ ] **Memória e TLB:** Modelar ASID e bit global — rodada 2: especificar, implementar e testar
127. [ ] **Memória e TLB:** Modelar EntryLo e permissões — rodada 2: especificar, implementar e testar
128. [ ] **Memória e TLB:** Implementar lookup TLB determinístico — rodada 2: especificar, implementar e testar
129. [ ] **Memória e TLB:** Detectar múltiplos hits TLB — rodada 2: especificar, implementar e testar
130. [ ] **Memória e TLB:** Modelar invalid e modified faults — rodada 2: especificar, implementar e testar
131. [ ] **Memória e TLB:** Modelar TLB refill e seus vetores — rodada 2: especificar, implementar e testar
132. [ ] **Memória e TLB:** Integrar tradução aos loads — rodada 2: especificar, implementar e testar
133. [ ] **Memória e TLB:** Integrar tradução aos stores — rodada 2: especificar, implementar e testar
134. [ ] **Memória e TLB:** Integrar erros de alinhamento — rodada 2: especificar, implementar e testar
135. [ ] **Memória e TLB:** Integrar exceções de endereço — rodada 2: especificar, implementar e testar
136. [ ] **Memória e TLB:** Separar RAM de teste da memória física real — rodada 2: especificar, implementar e testar
137. [ ] **Memória e TLB:** Adicionar regiões MMIO — rodada 2: especificar, implementar e testar
138. [ ] **Memória e TLB:** Adicionar regiões reservadas e aliases — rodada 2: especificar, implementar e testar
139. [ ] **Memória e TLB:** Adicionar testes de fronteira do mapa — rodada 2: especificar, implementar e testar
140. [ ] **Memória e TLB:** Validar leitura/escrita end-to-end — rodada 2: especificar, implementar e testar
141. [ ] **Memória e TLB:** Documentar mapa físico EE com referências — rodada 3: especificar, implementar e testar
142. [ ] **Memória e TLB:** Separar endereços virtuais e físicos — rodada 3: especificar, implementar e testar
143. [ ] **Memória e TLB:** Modelar segmentos diretos KSEG0/KSEG1 — rodada 3: especificar, implementar e testar
144. [ ] **Memória e TLB:** Definir estrutura de entrada TLB fiel à arquitetura — rodada 3: especificar, implementar e testar
145. [ ] **Memória e TLB:** Modelar PageMask quando aplicável — rodada 3: especificar, implementar e testar
146. [ ] **Memória e TLB:** Modelar ASID e bit global — rodada 3: especificar, implementar e testar
147. [ ] **Memória e TLB:** Modelar EntryLo e permissões — rodada 3: especificar, implementar e testar
148. [ ] **Memória e TLB:** Implementar lookup TLB determinístico — rodada 3: especificar, implementar e testar
149. [ ] **Memória e TLB:** Detectar múltiplos hits TLB — rodada 3: especificar, implementar e testar
150. [ ] **Memória e TLB:** Modelar invalid e modified faults — rodada 3: especificar, implementar e testar
151. [ ] **IOP:** Documentar arquitetura do IOP
152. [ ] **IOP:** Definir estado e registradores do IOP
153. [ ] **IOP:** Definir mapa de memória IOP
154. [ ] **IOP:** Implementar reset IOP
155. [ ] **IOP:** Implementar decoder IOP mínimo
156. [ ] **IOP:** Implementar operações aritméticas básicas IOP
157. [ ] **IOP:** Implementar branches IOP
158. [ ] **IOP:** Implementar loads e stores IOP
159. [ ] **IOP:** Modelar interrupções IOP
160. [ ] **IOP:** Modelar comunicação EE/IOP
161. [ ] **IOP:** Modelar temporizadores IOP
162. [ ] **IOP:** Modelar DMA IOP
163. [ ] **IOP:** Integrar BIOS loader legalmente fornecido
164. [ ] **IOP:** Criar testes isolados IOP
165. [ ] **IOP:** Executar teste de integração EE/IOP
166. [ ] **IOP:** Documentar arquitetura do IOP — rodada 2: especificar, implementar e testar
167. [ ] **IOP:** Definir estado e registradores do IOP — rodada 2: especificar, implementar e testar
168. [ ] **IOP:** Definir mapa de memória IOP — rodada 2: especificar, implementar e testar
169. [ ] **IOP:** Implementar reset IOP — rodada 2: especificar, implementar e testar
170. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 2: especificar, implementar e testar
171. [ ] **IOP:** Implementar operações aritméticas básicas IOP — rodada 2: especificar, implementar e testar
172. [ ] **IOP:** Implementar branches IOP — rodada 2: especificar, implementar e testar
173. [ ] **IOP:** Implementar loads e stores IOP — rodada 2: especificar, implementar e testar
174. [ ] **IOP:** Modelar interrupções IOP — rodada 2: especificar, implementar e testar
175. [ ] **IOP:** Modelar comunicação EE/IOP — rodada 2: especificar, implementar e testar
176. [ ] **IOP:** Modelar temporizadores IOP — rodada 2: especificar, implementar e testar
177. [ ] **IOP:** Modelar DMA IOP — rodada 2: especificar, implementar e testar
178. [ ] **IOP:** Integrar BIOS loader legalmente fornecido — rodada 2: especificar, implementar e testar
179. [ ] **IOP:** Criar testes isolados IOP — rodada 2: especificar, implementar e testar
180. [ ] **IOP:** Executar teste de integração EE/IOP — rodada 2: especificar, implementar e testar
181. [ ] **IOP:** Documentar arquitetura do IOP — rodada 3: especificar, implementar e testar
182. [ ] **IOP:** Definir estado e registradores do IOP — rodada 3: especificar, implementar e testar
183. [ ] **IOP:** Definir mapa de memória IOP — rodada 3: especificar, implementar e testar
184. [ ] **IOP:** Implementar reset IOP — rodada 3: especificar, implementar e testar
185. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 3: especificar, implementar e testar
186. [ ] **IOP:** Implementar operações aritméticas básicas IOP — rodada 3: especificar, implementar e testar
187. [ ] **IOP:** Implementar branches IOP — rodada 3: especificar, implementar e testar
188. [ ] **IOP:** Implementar loads e stores IOP — rodada 3: especificar, implementar e testar
189. [ ] **IOP:** Modelar interrupções IOP — rodada 3: especificar, implementar e testar
190. [ ] **IOP:** Modelar comunicação EE/IOP — rodada 3: especificar, implementar e testar
191. [ ] **IOP:** Modelar temporizadores IOP — rodada 3: especificar, implementar e testar
192. [ ] **IOP:** Modelar DMA IOP — rodada 3: especificar, implementar e testar
193. [ ] **IOP:** Integrar BIOS loader legalmente fornecido — rodada 3: especificar, implementar e testar
194. [ ] **IOP:** Criar testes isolados IOP — rodada 3: especificar, implementar e testar
195. [ ] **IOP:** Executar teste de integração EE/IOP — rodada 3: especificar, implementar e testar
196. [ ] **IOP:** Documentar arquitetura do IOP — rodada 4: especificar, implementar e testar
197. [ ] **IOP:** Definir estado e registradores do IOP — rodada 4: especificar, implementar e testar
198. [ ] **IOP:** Definir mapa de memória IOP — rodada 4: especificar, implementar e testar
199. [ ] **IOP:** Implementar reset IOP — rodada 4: especificar, implementar e testar
200. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 4: especificar, implementar e testar
201. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2
202. [ ] **DMA e interrupções:** Definir estrutura de canal DMA
203. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR
204. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência
205. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste
206. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA
207. [ ] **DMA e interrupções:** Modelar completion flags
208. [ ] **DMA e interrupções:** Integrar interrupções de conclusão
209. [ ] **DMA e interrupções:** Modelar interrupções pendentes
210. [ ] **DMA e interrupções:** Conectar DMA EE a IOP
211. [ ] **DMA e interrupções:** Conectar DMA ao GIF
212. [ ] **DMA e interrupções:** Conectar DMA ao VIF0
213. [ ] **DMA e interrupções:** Conectar DMA ao VIF1
214. [ ] **DMA e interrupções:** Conectar DMA ao SIF
215. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro
216. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 2: especificar, implementar e testar
217. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 2: especificar, implementar e testar
218. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 2: especificar, implementar e testar
219. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 2: especificar, implementar e testar
220. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 2: especificar, implementar e testar
221. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA — rodada 2: especificar, implementar e testar
222. [ ] **DMA e interrupções:** Modelar completion flags — rodada 2: especificar, implementar e testar
223. [ ] **DMA e interrupções:** Integrar interrupções de conclusão — rodada 2: especificar, implementar e testar
224. [ ] **DMA e interrupções:** Modelar interrupções pendentes — rodada 2: especificar, implementar e testar
225. [ ] **DMA e interrupções:** Conectar DMA EE a IOP — rodada 2: especificar, implementar e testar
226. [ ] **DMA e interrupções:** Conectar DMA ao GIF — rodada 2: especificar, implementar e testar
227. [ ] **DMA e interrupções:** Conectar DMA ao VIF0 — rodada 2: especificar, implementar e testar
228. [ ] **DMA e interrupções:** Conectar DMA ao VIF1 — rodada 2: especificar, implementar e testar
229. [ ] **DMA e interrupções:** Conectar DMA ao SIF — rodada 2: especificar, implementar e testar
230. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro — rodada 2: especificar, implementar e testar
231. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 3: especificar, implementar e testar
232. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 3: especificar, implementar e testar
233. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 3: especificar, implementar e testar
234. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 3: especificar, implementar e testar
235. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 3: especificar, implementar e testar
236. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA — rodada 3: especificar, implementar e testar
237. [ ] **DMA e interrupções:** Modelar completion flags — rodada 3: especificar, implementar e testar
238. [ ] **DMA e interrupções:** Integrar interrupções de conclusão — rodada 3: especificar, implementar e testar
239. [ ] **DMA e interrupções:** Modelar interrupções pendentes — rodada 3: especificar, implementar e testar
240. [ ] **DMA e interrupções:** Conectar DMA EE a IOP — rodada 3: especificar, implementar e testar
241. [ ] **DMA e interrupções:** Conectar DMA ao GIF — rodada 3: especificar, implementar e testar
242. [ ] **DMA e interrupções:** Conectar DMA ao VIF0 — rodada 3: especificar, implementar e testar
243. [ ] **DMA e interrupções:** Conectar DMA ao VIF1 — rodada 3: especificar, implementar e testar
244. [ ] **DMA e interrupções:** Conectar DMA ao SIF — rodada 3: especificar, implementar e testar
245. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro — rodada 3: especificar, implementar e testar
246. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 4: especificar, implementar e testar
247. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 4: especificar, implementar e testar
248. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 4: especificar, implementar e testar
249. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 4: especificar, implementar e testar
250. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 4: especificar, implementar e testar
251. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1
252. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores
253. [ ] **VU0/VU1:** Definir memória micro/data VU
254. [ ] **VU0/VU1:** Implementar decoder vetorial inicial
255. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais
256. [ ] **VU0/VU1:** Implementar operações multiply vetoriais
257. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores
258. [ ] **VU0/VU1:** Implementar operações de clamp
259. [ ] **VU0/VU1:** Implementar loads/stores vetoriais
260. [ ] **VU0/VU1:** Modelar flags e status VU
261. [ ] **VU0/VU1:** Implementar microprograma de teste
262. [ ] **VU0/VU1:** Modelar VU0 macro mode
263. [ ] **VU0/VU1:** Modelar execução microprogramada VU1
264. [ ] **VU0/VU1:** Integrar VIF e transferências
265. [ ] **VU0/VU1:** Criar testes determinísticos VU
266. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 2: especificar, implementar e testar
267. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 2: especificar, implementar e testar
268. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 2: especificar, implementar e testar
269. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 2: especificar, implementar e testar
270. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 2: especificar, implementar e testar
271. [ ] **VU0/VU1:** Implementar operações multiply vetoriais — rodada 2: especificar, implementar e testar
272. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores — rodada 2: especificar, implementar e testar
273. [ ] **VU0/VU1:** Implementar operações de clamp — rodada 2: especificar, implementar e testar
274. [ ] **VU0/VU1:** Implementar loads/stores vetoriais — rodada 2: especificar, implementar e testar
275. [ ] **VU0/VU1:** Modelar flags e status VU — rodada 2: especificar, implementar e testar
276. [ ] **VU0/VU1:** Implementar microprograma de teste — rodada 2: especificar, implementar e testar
277. [ ] **VU0/VU1:** Modelar VU0 macro mode — rodada 2: especificar, implementar e testar
278. [ ] **VU0/VU1:** Modelar execução microprogramada VU1 — rodada 2: especificar, implementar e testar
279. [ ] **VU0/VU1:** Integrar VIF e transferências — rodada 2: especificar, implementar e testar
280. [ ] **VU0/VU1:** Criar testes determinísticos VU — rodada 2: especificar, implementar e testar
281. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 3: especificar, implementar e testar
282. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 3: especificar, implementar e testar
283. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 3: especificar, implementar e testar
284. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 3: especificar, implementar e testar
285. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 3: especificar, implementar e testar
286. [ ] **VU0/VU1:** Implementar operações multiply vetoriais — rodada 3: especificar, implementar e testar
287. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores — rodada 3: especificar, implementar e testar
288. [ ] **VU0/VU1:** Implementar operações de clamp — rodada 3: especificar, implementar e testar
289. [ ] **VU0/VU1:** Implementar loads/stores vetoriais — rodada 3: especificar, implementar e testar
290. [ ] **VU0/VU1:** Modelar flags e status VU — rodada 3: especificar, implementar e testar
291. [ ] **VU0/VU1:** Implementar microprograma de teste — rodada 3: especificar, implementar e testar
292. [ ] **VU0/VU1:** Modelar VU0 macro mode — rodada 3: especificar, implementar e testar
293. [ ] **VU0/VU1:** Modelar execução microprogramada VU1 — rodada 3: especificar, implementar e testar
294. [ ] **VU0/VU1:** Integrar VIF e transferências — rodada 3: especificar, implementar e testar
295. [ ] **VU0/VU1:** Criar testes determinísticos VU — rodada 3: especificar, implementar e testar
296. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 4: especificar, implementar e testar
297. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 4: especificar, implementar e testar
298. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 4: especificar, implementar e testar
299. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 4: especificar, implementar e testar
300. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 4: especificar, implementar e testar
301. [ ] **GS e vídeo:** Documentar registradores GS essenciais
302. [ ] **GS e vídeo:** Definir modelo de VRAM
303. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores
304. [ ] **GS e vídeo:** Implementar transferência host-to-local básica
305. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste
306. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários
307. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais
308. [ ] **GS e vídeo:** Implementar rasterização de triângulos
309. [ ] **GS e vídeo:** Implementar textura básica
310. [ ] **GS e vídeo:** Implementar blending básico
311. [ ] **GS e vídeo:** Implementar scissor e viewport
312. [ ] **GS e vídeo:** Modelar framebuffer e display buffer
313. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360
314. [ ] **GS e vídeo:** Adicionar testes de renderização de referência
315. [ ] **GS e vídeo:** Medir custo e gargalos do GS
316. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 2: especificar, implementar e testar
317. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 2: especificar, implementar e testar
318. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 2: especificar, implementar e testar
319. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 2: especificar, implementar e testar
320. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 2: especificar, implementar e testar
321. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários — rodada 2: especificar, implementar e testar
322. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais — rodada 2: especificar, implementar e testar
323. [ ] **GS e vídeo:** Implementar rasterização de triângulos — rodada 2: especificar, implementar e testar
324. [ ] **GS e vídeo:** Implementar textura básica — rodada 2: especificar, implementar e testar
325. [ ] **GS e vídeo:** Implementar blending básico — rodada 2: especificar, implementar e testar
326. [ ] **GS e vídeo:** Implementar scissor e viewport — rodada 2: especificar, implementar e testar
327. [ ] **GS e vídeo:** Modelar framebuffer e display buffer — rodada 2: especificar, implementar e testar
328. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360 — rodada 2: especificar, implementar e testar
329. [ ] **GS e vídeo:** Adicionar testes de renderização de referência — rodada 2: especificar, implementar e testar
330. [ ] **GS e vídeo:** Medir custo e gargalos do GS — rodada 2: especificar, implementar e testar
331. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 3: especificar, implementar e testar
332. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 3: especificar, implementar e testar
333. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 3: especificar, implementar e testar
334. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 3: especificar, implementar e testar
335. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 3: especificar, implementar e testar
336. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários — rodada 3: especificar, implementar e testar
337. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais — rodada 3: especificar, implementar e testar
338. [ ] **GS e vídeo:** Implementar rasterização de triângulos — rodada 3: especificar, implementar e testar
339. [ ] **GS e vídeo:** Implementar textura básica — rodada 3: especificar, implementar e testar
340. [ ] **GS e vídeo:** Implementar blending básico — rodada 3: especificar, implementar e testar
341. [ ] **GS e vídeo:** Implementar scissor e viewport — rodada 3: especificar, implementar e testar
342. [ ] **GS e vídeo:** Modelar framebuffer e display buffer — rodada 3: especificar, implementar e testar
343. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360 — rodada 3: especificar, implementar e testar
344. [ ] **GS e vídeo:** Adicionar testes de renderização de referência — rodada 3: especificar, implementar e testar
345. [ ] **GS e vídeo:** Medir custo e gargalos do GS — rodada 3: especificar, implementar e testar
346. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 4: especificar, implementar e testar
347. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 4: especificar, implementar e testar
348. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 4: especificar, implementar e testar
349. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 4: especificar, implementar e testar
350. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 4: especificar, implementar e testar
351. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces
352. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo
353. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio
354. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos
355. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host
356. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio
357. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360
358. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox
359. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles
360. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos
361. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO
362. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura
363. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual
364. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor
365. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos
366. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 2: especificar, implementar e testar
367. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 2: especificar, implementar e testar
368. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 2: especificar, implementar e testar
369. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 2: especificar, implementar e testar
370. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 2: especificar, implementar e testar
371. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio — rodada 2: especificar, implementar e testar
372. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360 — rodada 2: especificar, implementar e testar
373. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox — rodada 2: especificar, implementar e testar
374. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles — rodada 2: especificar, implementar e testar
375. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos — rodada 2: especificar, implementar e testar
376. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO — rodada 2: especificar, implementar e testar
377. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura — rodada 2: especificar, implementar e testar
378. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual — rodada 2: especificar, implementar e testar
379. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor — rodada 2: especificar, implementar e testar
380. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos — rodada 2: especificar, implementar e testar
381. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 3: especificar, implementar e testar
382. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 3: especificar, implementar e testar
383. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 3: especificar, implementar e testar
384. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 3: especificar, implementar e testar
385. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 3: especificar, implementar e testar
386. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio — rodada 3: especificar, implementar e testar
387. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360 — rodada 3: especificar, implementar e testar
388. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox — rodada 3: especificar, implementar e testar
389. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles — rodada 3: especificar, implementar e testar
390. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos — rodada 3: especificar, implementar e testar
391. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO — rodada 3: especificar, implementar e testar
392. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura — rodada 3: especificar, implementar e testar
393. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual — rodada 3: especificar, implementar e testar
394. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor — rodada 3: especificar, implementar e testar
395. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos — rodada 3: especificar, implementar e testar
396. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 4: especificar, implementar e testar
397. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 4: especificar, implementar e testar
398. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 4: especificar, implementar e testar
399. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 4: especificar, implementar e testar
400. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 4: especificar, implementar e testar
401. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real
402. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação
403. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA
404. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura
405. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável
406. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente
407. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo
408. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais
409. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos
410. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais
411. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo
412. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura
413. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento
414. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste
415. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo
416. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 2: especificar, implementar e testar
417. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 2: especificar, implementar e testar
418. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 2: especificar, implementar e testar
419. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 2: especificar, implementar e testar
420. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 2: especificar, implementar e testar
421. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente — rodada 2: especificar, implementar e testar
422. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo — rodada 2: especificar, implementar e testar
423. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais — rodada 2: especificar, implementar e testar
424. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos — rodada 2: especificar, implementar e testar
425. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais — rodada 2: especificar, implementar e testar
426. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo — rodada 2: especificar, implementar e testar
427. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura — rodada 2: especificar, implementar e testar
428. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento — rodada 2: especificar, implementar e testar
429. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste — rodada 2: especificar, implementar e testar
430. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo — rodada 2: especificar, implementar e testar
431. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 3: especificar, implementar e testar
432. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 3: especificar, implementar e testar
433. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 3: especificar, implementar e testar
434. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 3: especificar, implementar e testar
435. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 3: especificar, implementar e testar
436. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente — rodada 3: especificar, implementar e testar
437. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo — rodada 3: especificar, implementar e testar
438. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais — rodada 3: especificar, implementar e testar
439. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos — rodada 3: especificar, implementar e testar
440. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais — rodada 3: especificar, implementar e testar
441. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo — rodada 3: especificar, implementar e testar
442. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura — rodada 3: especificar, implementar e testar
443. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento — rodada 3: especificar, implementar e testar
444. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste — rodada 3: especificar, implementar e testar
445. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo — rodada 3: especificar, implementar e testar
446. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 4: especificar, implementar e testar
447. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 4: especificar, implementar e testar
448. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 4: especificar, implementar e testar
449. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 4: especificar, implementar e testar
450. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 4: especificar, implementar e testar
451. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon
452. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado
453. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC
454. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo
455. [ ] **Toolchain Xenon e XEX:** Validar elf2xex
456. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo
457. [ ] **Toolchain Xenon e XEX:** Converter para default.xex
458. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX
459. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso
460. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário
461. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon
462. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências
463. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build
464. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio
465. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível
466. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 2: especificar, implementar e testar
467. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 2: especificar, implementar e testar
468. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 2: especificar, implementar e testar
469. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 2: especificar, implementar e testar
470. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 2: especificar, implementar e testar
471. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo — rodada 2: especificar, implementar e testar
472. [ ] **Toolchain Xenon e XEX:** Converter para default.xex — rodada 2: especificar, implementar e testar
473. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX — rodada 2: especificar, implementar e testar
474. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso — rodada 2: especificar, implementar e testar
475. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário — rodada 2: especificar, implementar e testar
476. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon — rodada 2: especificar, implementar e testar
477. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências — rodada 2: especificar, implementar e testar
478. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build — rodada 2: especificar, implementar e testar
479. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio — rodada 2: especificar, implementar e testar
480. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível — rodada 2: especificar, implementar e testar
481. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 3: especificar, implementar e testar
482. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 3: especificar, implementar e testar
483. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 3: especificar, implementar e testar
484. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 3: especificar, implementar e testar
485. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 3: especificar, implementar e testar
486. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo — rodada 3: especificar, implementar e testar
487. [ ] **Toolchain Xenon e XEX:** Converter para default.xex — rodada 3: especificar, implementar e testar
488. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX — rodada 3: especificar, implementar e testar
489. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso — rodada 3: especificar, implementar e testar
490. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário — rodada 3: especificar, implementar e testar
491. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon — rodada 3: especificar, implementar e testar
492. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências — rodada 3: especificar, implementar e testar
493. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build — rodada 3: especificar, implementar e testar
494. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio — rodada 3: especificar, implementar e testar
495. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível — rodada 3: especificar, implementar e testar
496. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 4: especificar, implementar e testar
497. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 4: especificar, implementar e testar
498. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 4: especificar, implementar e testar
499. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 4: especificar, implementar e testar
500. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 4: especificar, implementar e testar

## Critérios de conclusão

- [ ] Build host reproduzível e suíte de testes executada com logs.
- [ ] Toolchain Xenon configurada e `default.xex` produzido e verificado.
- [ ] Runtime de vídeo/controles inicializado no Xbox 360 RGH.
- [ ] Subsistemas do PS2 integrados e testados por casos reproduzíveis.
- [ ] Boot de BIOS/jogo demonstrado legalmente, sem distribuir BIOS proprietária.
- [ ] Percentual geral recalculado a partir de evidências, não da quantidade de tarefas listadas.
