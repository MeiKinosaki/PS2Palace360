# PS2Palace360 — plano sequencial de 500 etapas

**Status:** plano de execução; nenhuma caixa abaixo significa concluída. A contagem organiza o trabalho, não mede implementação já existente. Cada etapa só deve ser marcada como concluída depois de código integrado, teste executado e evidência registrada quando aplicável.

**Regra de progresso:** documentação, checklist ou código enviado sem build/teste não aumenta automaticamente a porcentagem de implementação funcional. O artefato final solicitado continua sendo `build/default.xex`; `ELF` é apenas intermediário. Não declarar boot de jogos ou compatibilidade sem teste real.

**Licença PCSX2:** o projeto upstream é GPL-3.0-or-later. Antes de importar código, registrar a revisão, manter avisos de copyright/licença, preservar a licença aplicável e preparar a distribuição do código-fonte correspondente. Referência: https://github.com/PCSX2/pcsx2

## Etapas

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
051. [ ] **EE/R5900:** Inventariar opcodes suportados no decoder
052. [ ] **EE/R5900:** Inventariar opcodes ausentes do decoder
053. [ ] **EE/R5900:** Validar operações aritméticas de 32 bits
054. [ ] **EE/R5900:** Validar operações aritméticas de 64 bits
055. [ ] **EE/R5900:** Validar overflow e exceções aritméticas
056. [ ] **EE/R5900:** Validar operações lógicas imediatas
057. [ ] **EE/R5900:** Validar comparações assinadas e não assinadas
058. [ ] **EE/R5900:** Validar shifts fixos de 32 bits
059. [ ] **EE/R5900:** Validar shifts variáveis de 32 bits
060. [ ] **EE/R5900:** Validar shifts fixos de 64 bits
061. [ ] **EE/R5900:** Validar shifts variáveis de 64 bits
062. [ ] **EE/R5900:** Validar multiplicação e divisão HI/LO
063. [ ] **EE/R5900:** Validar casos extremos de divisão
064. [ ] **EE/R5900:** Validar branches condicionais
065. [ ] **EE/R5900:** Validar jumps e links
066. [ ] **EE/R5900:** Modelar delay slots com testes
067. [ ] **EE/R5900:** Implementar syscall e validar exceção
068. [ ] **EE/R5900:** Implementar break e validar exceção
069. [ ] **EE/R5900:** Implementar traps suportados pelo EE
070. [ ] **EE/R5900:** Definir comportamento explícito para opcode reservado
071. [ ] **EE/R5900:** Inventariar opcodes suportados no decoder — rodada 2: especificar, implementar e testar
072. [ ] **EE/R5900:** Inventariar opcodes ausentes do decoder — rodada 2: especificar, implementar e testar
073. [ ] **EE/R5900:** Validar operações aritméticas de 32 bits — rodada 2: especificar, implementar e testar
074. [ ] **EE/R5900:** Validar operações aritméticas de 64 bits — rodada 2: especificar, implementar e testar
075. [ ] **EE/R5900:** Validar overflow e exceções aritméticas — rodada 2: especificar, implementar e testar
076. [ ] **EE/R5900:** Validar operações lógicas imediatas — rodada 2: especificar, implementar e testar
077. [ ] **EE/R5900:** Validar comparações assinadas e não assinadas — rodada 2: especificar, implementar e testar
078. [ ] **EE/R5900:** Validar shifts fixos de 32 bits — rodada 2: especificar, implementar e testar
079. [ ] **EE/R5900:** Validar shifts variáveis de 32 bits — rodada 2: especificar, implementar e testar
080. [ ] **EE/R5900:** Validar shifts fixos de 64 bits — rodada 2: especificar, implementar e testar
081. [ ] **EE/R5900:** Validar shifts variáveis de 64 bits — rodada 2: especificar, implementar e testar
082. [ ] **EE/R5900:** Validar multiplicação e divisão HI/LO — rodada 2: especificar, implementar e testar
083. [ ] **EE/R5900:** Validar casos extremos de divisão — rodada 2: especificar, implementar e testar
084. [ ] **EE/R5900:** Validar branches condicionais — rodada 2: especificar, implementar e testar
085. [ ] **EE/R5900:** Validar jumps e links — rodada 2: especificar, implementar e testar
086. [ ] **EE/R5900:** Modelar delay slots com testes — rodada 2: especificar, implementar e testar
087. [ ] **EE/R5900:** Implementar syscall e validar exceção — rodada 2: especificar, implementar e testar
088. [ ] **EE/R5900:** Implementar break e validar exceção — rodada 2: especificar, implementar e testar
089. [ ] **EE/R5900:** Implementar traps suportados pelo EE — rodada 2: especificar, implementar e testar
090. [ ] **EE/R5900:** Definir comportamento explícito para opcode reservado — rodada 2: especificar, implementar e testar
091. [ ] **EE/R5900:** Inventariar opcodes suportados no decoder — rodada 3: especificar, implementar e testar
092. [ ] **EE/R5900:** Inventariar opcodes ausentes do decoder — rodada 3: especificar, implementar e testar
093. [ ] **EE/R5900:** Validar operações aritméticas de 32 bits — rodada 3: especificar, implementar e testar
094. [ ] **EE/R5900:** Validar operações aritméticas de 64 bits — rodada 3: especificar, implementar e testar
095. [ ] **EE/R5900:** Validar overflow e exceções aritméticas — rodada 3: especificar, implementar e testar
096. [ ] **EE/R5900:** Validar operações lógicas imediatas — rodada 3: especificar, implementar e testar
097. [ ] **EE/R5900:** Validar comparações assinadas e não assinadas — rodada 3: especificar, implementar e testar
098. [ ] **EE/R5900:** Validar shifts fixos de 32 bits — rodada 3: especificar, implementar e testar
099. [ ] **EE/R5900:** Validar shifts variáveis de 32 bits — rodada 3: especificar, implementar e testar
100. [ ] **EE/R5900:** Validar shifts fixos de 64 bits — rodada 3: especificar, implementar e testar
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
151. [ ] **CP0 e exceções:** Inventariar registradores CP0 relevantes
152. [ ] **CP0 e exceções:** Definir máscara e campos de Status
153. [ ] **CP0 e exceções:** Definir campos de Cause
154. [ ] **CP0 e exceções:** Implementar leitura controlada de CP0
155. [ ] **CP0 e exceções:** Implementar escrita controlada de CP0
156. [ ] **CP0 e exceções:** Modelar EXL e entrada em exceção
157. [ ] **CP0 e exceções:** Modelar EPC e Cause.BD
158. [ ] **CP0 e exceções:** Validar exceções aninhadas
159. [ ] **CP0 e exceções:** Modelar seleção do vetor de exceção
160. [ ] **CP0 e exceções:** Adicionar BadVAddr quando necessário
161. [ ] **CP0 e exceções:** Modelar permissões de privilégio
162. [ ] **CP0 e exceções:** Implementar instruções MFC0 e MTC0 necessárias
163. [ ] **CP0 e exceções:** Validar efeitos de ERET
164. [ ] **CP0 e exceções:** Validar interrupções pendentes
165. [ ] **CP0 e exceções:** Adicionar testes por código de exceção
166. [ ] **CP0 e exceções:** Inventariar registradores CP0 relevantes — rodada 2: especificar, implementar e testar
167. [ ] **CP0 e exceções:** Definir máscara e campos de Status — rodada 2: especificar, implementar e testar
168. [ ] **CP0 e exceções:** Definir campos de Cause — rodada 2: especificar, implementar e testar
169. [ ] **CP0 e exceções:** Implementar leitura controlada de CP0 — rodada 2: especificar, implementar e testar
170. [ ] **CP0 e exceções:** Implementar escrita controlada de CP0 — rodada 2: especificar, implementar e testar
171. [ ] **CP0 e exceções:** Modelar EXL e entrada em exceção — rodada 2: especificar, implementar e testar
172. [ ] **CP0 e exceções:** Modelar EPC e Cause.BD — rodada 2: especificar, implementar e testar
173. [ ] **CP0 e exceções:** Validar exceções aninhadas — rodada 2: especificar, implementar e testar
174. [ ] **CP0 e exceções:** Modelar seleção do vetor de exceção — rodada 2: especificar, implementar e testar
175. [ ] **CP0 e exceções:** Adicionar BadVAddr quando necessário — rodada 2: especificar, implementar e testar
176. [ ] **CP0 e exceções:** Modelar permissões de privilégio — rodada 2: especificar, implementar e testar
177. [ ] **CP0 e exceções:** Implementar instruções MFC0 e MTC0 necessárias — rodada 2: especificar, implementar e testar
178. [ ] **CP0 e exceções:** Validar efeitos de ERET — rodada 2: especificar, implementar e testar
179. [ ] **CP0 e exceções:** Validar interrupções pendentes — rodada 2: especificar, implementar e testar
180. [ ] **CP0 e exceções:** Adicionar testes por código de exceção — rodada 2: especificar, implementar e testar
181. [ ] **CP0 e exceções:** Inventariar registradores CP0 relevantes — rodada 3: especificar, implementar e testar
182. [ ] **CP0 e exceções:** Definir máscara e campos de Status — rodada 3: especificar, implementar e testar
183. [ ] **CP0 e exceções:** Definir campos de Cause — rodada 3: especificar, implementar e testar
184. [ ] **CP0 e exceções:** Implementar leitura controlada de CP0 — rodada 3: especificar, implementar e testar
185. [ ] **CP0 e exceções:** Implementar escrita controlada de CP0 — rodada 3: especificar, implementar e testar
186. [ ] **CP0 e exceções:** Modelar EXL e entrada em exceção — rodada 3: especificar, implementar e testar
187. [ ] **CP0 e exceções:** Modelar EPC e Cause.BD — rodada 3: especificar, implementar e testar
188. [ ] **CP0 e exceções:** Validar exceções aninhadas — rodada 3: especificar, implementar e testar
189. [ ] **CP0 e exceções:** Modelar seleção do vetor de exceção — rodada 3: especificar, implementar e testar
190. [ ] **CP0 e exceções:** Adicionar BadVAddr quando necessário — rodada 3: especificar, implementar e testar
191. [ ] **CP0 e exceções:** Modelar permissões de privilégio — rodada 3: especificar, implementar e testar
192. [ ] **CP0 e exceções:** Implementar instruções MFC0 e MTC0 necessárias — rodada 3: especificar, implementar e testar
193. [ ] **CP0 e exceções:** Validar efeitos de ERET — rodada 3: especificar, implementar e testar
194. [ ] **CP0 e exceções:** Validar interrupções pendentes — rodada 3: especificar, implementar e testar
195. [ ] **CP0 e exceções:** Adicionar testes por código de exceção — rodada 3: especificar, implementar e testar
196. [ ] **CP0 e exceções:** Inventariar registradores CP0 relevantes — rodada 4: especificar, implementar e testar
197. [ ] **CP0 e exceções:** Definir máscara e campos de Status — rodada 4: especificar, implementar e testar
198. [ ] **CP0 e exceções:** Definir campos de Cause — rodada 4: especificar, implementar e testar
199. [ ] **CP0 e exceções:** Implementar leitura controlada de CP0 — rodada 4: especificar, implementar e testar
200. [ ] **CP0 e exceções:** Implementar escrita controlada de CP0 — rodada 4: especificar, implementar e testar
201. [ ] **IOP:** Documentar arquitetura do IOP
202. [ ] **IOP:** Definir estado e registradores do IOP
203. [ ] **IOP:** Definir mapa de memória IOP
204. [ ] **IOP:** Implementar reset IOP
205. [ ] **IOP:** Implementar decoder IOP mínimo
206. [ ] **IOP:** Implementar operações aritméticas básicas IOP
207. [ ] **IOP:** Implementar branches IOP
208. [ ] **IOP:** Implementar loads e stores IOP
209. [ ] **IOP:** Modelar interrupções IOP
210. [ ] **IOP:** Modelar comunicação EE/IOP
211. [ ] **IOP:** Modelar temporizadores IOP
212. [ ] **IOP:** Modelar DMA IOP
213. [ ] **IOP:** Integrar BIOS loader legalmente fornecido
214. [ ] **IOP:** Criar testes isolados IOP
215. [ ] **IOP:** Executar teste de integração EE/IOP
216. [ ] **IOP:** Documentar arquitetura do IOP — rodada 2: especificar, implementar e testar
217. [ ] **IOP:** Definir estado e registradores do IOP — rodada 2: especificar, implementar e testar
218. [ ] **IOP:** Definir mapa de memória IOP — rodada 2: especificar, implementar e testar
219. [ ] **IOP:** Implementar reset IOP — rodada 2: especificar, implementar e testar
220. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 2: especificar, implementar e testar
221. [ ] **IOP:** Implementar operações aritméticas básicas IOP — rodada 2: especificar, implementar e testar
222. [ ] **IOP:** Implementar branches IOP — rodada 2: especificar, implementar e testar
223. [ ] **IOP:** Implementar loads e stores IOP — rodada 2: especificar, implementar e testar
224. [ ] **IOP:** Modelar interrupções IOP — rodada 2: especificar, implementar e testar
225. [ ] **IOP:** Modelar comunicação EE/IOP — rodada 2: especificar, implementar e testar
226. [ ] **IOP:** Modelar temporizadores IOP — rodada 2: especificar, implementar e testar
227. [ ] **IOP:** Modelar DMA IOP — rodada 2: especificar, implementar e testar
228. [ ] **IOP:** Integrar BIOS loader legalmente fornecido — rodada 2: especificar, implementar e testar
229. [ ] **IOP:** Criar testes isolados IOP — rodada 2: especificar, implementar e testar
230. [ ] **IOP:** Executar teste de integração EE/IOP — rodada 2: especificar, implementar e testar
231. [ ] **IOP:** Documentar arquitetura do IOP — rodada 3: especificar, implementar e testar
232. [ ] **IOP:** Definir estado e registradores do IOP — rodada 3: especificar, implementar e testar
233. [ ] **IOP:** Definir mapa de memória IOP — rodada 3: especificar, implementar e testar
234. [ ] **IOP:** Implementar reset IOP — rodada 3: especificar, implementar e testar
235. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 3: especificar, implementar e testar
236. [ ] **IOP:** Implementar operações aritméticas básicas IOP — rodada 3: especificar, implementar e testar
237. [ ] **IOP:** Implementar branches IOP — rodada 3: especificar, implementar e testar
238. [ ] **IOP:** Implementar loads e stores IOP — rodada 3: especificar, implementar e testar
239. [ ] **IOP:** Modelar interrupções IOP — rodada 3: especificar, implementar e testar
240. [ ] **IOP:** Modelar comunicação EE/IOP — rodada 3: especificar, implementar e testar
241. [ ] **IOP:** Modelar temporizadores IOP — rodada 3: especificar, implementar e testar
242. [ ] **IOP:** Modelar DMA IOP — rodada 3: especificar, implementar e testar
243. [ ] **IOP:** Integrar BIOS loader legalmente fornecido — rodada 3: especificar, implementar e testar
244. [ ] **IOP:** Criar testes isolados IOP — rodada 3: especificar, implementar e testar
245. [ ] **IOP:** Executar teste de integração EE/IOP — rodada 3: especificar, implementar e testar
246. [ ] **IOP:** Documentar arquitetura do IOP — rodada 4: especificar, implementar e testar
247. [ ] **IOP:** Definir estado e registradores do IOP — rodada 4: especificar, implementar e testar
248. [ ] **IOP:** Definir mapa de memória IOP — rodada 4: especificar, implementar e testar
249. [ ] **IOP:** Implementar reset IOP — rodada 4: especificar, implementar e testar
250. [ ] **IOP:** Implementar decoder IOP mínimo — rodada 4: especificar, implementar e testar
251. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2
252. [ ] **DMA e interrupções:** Definir estrutura de canal DMA
253. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR
254. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência
255. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste
256. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA
257. [ ] **DMA e interrupções:** Modelar completion flags
258. [ ] **DMA e interrupções:** Integrar interrupções de conclusão
259. [ ] **DMA e interrupções:** Modelar interrupções pendentes
260. [ ] **DMA e interrupções:** Conectar DMA EE a IOP
261. [ ] **DMA e interrupções:** Conectar DMA ao GIF
262. [ ] **DMA e interrupções:** Conectar DMA ao VIF0
263. [ ] **DMA e interrupções:** Conectar DMA ao VIF1
264. [ ] **DMA e interrupções:** Conectar DMA ao SIF
265. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro
266. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 2: especificar, implementar e testar
267. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 2: especificar, implementar e testar
268. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 2: especificar, implementar e testar
269. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 2: especificar, implementar e testar
270. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 2: especificar, implementar e testar
271. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA — rodada 2: especificar, implementar e testar
272. [ ] **DMA e interrupções:** Modelar completion flags — rodada 2: especificar, implementar e testar
273. [ ] **DMA e interrupções:** Integrar interrupções de conclusão — rodada 2: especificar, implementar e testar
274. [ ] **DMA e interrupções:** Modelar interrupções pendentes — rodada 2: especificar, implementar e testar
275. [ ] **DMA e interrupções:** Conectar DMA EE a IOP — rodada 2: especificar, implementar e testar
276. [ ] **DMA e interrupções:** Conectar DMA ao GIF — rodada 2: especificar, implementar e testar
277. [ ] **DMA e interrupções:** Conectar DMA ao VIF0 — rodada 2: especificar, implementar e testar
278. [ ] **DMA e interrupções:** Conectar DMA ao VIF1 — rodada 2: especificar, implementar e testar
279. [ ] **DMA e interrupções:** Conectar DMA ao SIF — rodada 2: especificar, implementar e testar
280. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro — rodada 2: especificar, implementar e testar
281. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 3: especificar, implementar e testar
282. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 3: especificar, implementar e testar
283. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 3: especificar, implementar e testar
284. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 3: especificar, implementar e testar
285. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 3: especificar, implementar e testar
286. [ ] **DMA e interrupções:** Modelar prioridade e arbitragem DMA — rodada 3: especificar, implementar e testar
287. [ ] **DMA e interrupções:** Modelar completion flags — rodada 3: especificar, implementar e testar
288. [ ] **DMA e interrupções:** Integrar interrupções de conclusão — rodada 3: especificar, implementar e testar
289. [ ] **DMA e interrupções:** Modelar interrupções pendentes — rodada 3: especificar, implementar e testar
290. [ ] **DMA e interrupções:** Conectar DMA EE a IOP — rodada 3: especificar, implementar e testar
291. [ ] **DMA e interrupções:** Conectar DMA ao GIF — rodada 3: especificar, implementar e testar
292. [ ] **DMA e interrupções:** Conectar DMA ao VIF0 — rodada 3: especificar, implementar e testar
293. [ ] **DMA e interrupções:** Conectar DMA ao VIF1 — rodada 3: especificar, implementar e testar
294. [ ] **DMA e interrupções:** Conectar DMA ao SIF — rodada 3: especificar, implementar e testar
295. [ ] **DMA e interrupções:** Adicionar testes de cancelamento e erro — rodada 3: especificar, implementar e testar
296. [ ] **DMA e interrupções:** Inventariar canais DMA do PS2 — rodada 4: especificar, implementar e testar
297. [ ] **DMA e interrupções:** Definir estrutura de canal DMA — rodada 4: especificar, implementar e testar
298. [ ] **DMA e interrupções:** Modelar registers MADR/QWC/CHCR — rodada 4: especificar, implementar e testar
299. [ ] **DMA e interrupções:** Implementar validação de tamanho de transferência — rodada 4: especificar, implementar e testar
300. [ ] **DMA e interrupções:** Implementar transferência RAM a RAM de teste — rodada 4: especificar, implementar e testar
301. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1
302. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores
303. [ ] **VU0/VU1:** Definir memória micro/data VU
304. [ ] **VU0/VU1:** Implementar decoder vetorial inicial
305. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais
306. [ ] **VU0/VU1:** Implementar operações multiply vetoriais
307. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores
308. [ ] **VU0/VU1:** Implementar operações de clamp
309. [ ] **VU0/VU1:** Implementar loads/stores vetoriais
310. [ ] **VU0/VU1:** Modelar flags e status VU
311. [ ] **VU0/VU1:** Implementar microprograma de teste
312. [ ] **VU0/VU1:** Modelar VU0 macro mode
313. [ ] **VU0/VU1:** Modelar execução microprogramada VU1
314. [ ] **VU0/VU1:** Integrar VIF e transferências
315. [ ] **VU0/VU1:** Criar testes determinísticos VU
316. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 2: especificar, implementar e testar
317. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 2: especificar, implementar e testar
318. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 2: especificar, implementar e testar
319. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 2: especificar, implementar e testar
320. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 2: especificar, implementar e testar
321. [ ] **VU0/VU1:** Implementar operações multiply vetoriais — rodada 2: especificar, implementar e testar
322. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores — rodada 2: especificar, implementar e testar
323. [ ] **VU0/VU1:** Implementar operações de clamp — rodada 2: especificar, implementar e testar
324. [ ] **VU0/VU1:** Implementar loads/stores vetoriais — rodada 2: especificar, implementar e testar
325. [ ] **VU0/VU1:** Modelar flags e status VU — rodada 2: especificar, implementar e testar
326. [ ] **VU0/VU1:** Implementar microprograma de teste — rodada 2: especificar, implementar e testar
327. [ ] **VU0/VU1:** Modelar VU0 macro mode — rodada 2: especificar, implementar e testar
328. [ ] **VU0/VU1:** Modelar execução microprogramada VU1 — rodada 2: especificar, implementar e testar
329. [ ] **VU0/VU1:** Integrar VIF e transferências — rodada 2: especificar, implementar e testar
330. [ ] **VU0/VU1:** Criar testes determinísticos VU — rodada 2: especificar, implementar e testar
331. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 3: especificar, implementar e testar
332. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 3: especificar, implementar e testar
333. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 3: especificar, implementar e testar
334. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 3: especificar, implementar e testar
335. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 3: especificar, implementar e testar
336. [ ] **VU0/VU1:** Implementar operações multiply vetoriais — rodada 3: especificar, implementar e testar
337. [ ] **VU0/VU1:** Implementar operações MAC e acumuladores — rodada 3: especificar, implementar e testar
338. [ ] **VU0/VU1:** Implementar operações de clamp — rodada 3: especificar, implementar e testar
339. [ ] **VU0/VU1:** Implementar loads/stores vetoriais — rodada 3: especificar, implementar e testar
340. [ ] **VU0/VU1:** Modelar flags e status VU — rodada 3: especificar, implementar e testar
341. [ ] **VU0/VU1:** Implementar microprograma de teste — rodada 3: especificar, implementar e testar
342. [ ] **VU0/VU1:** Modelar VU0 macro mode — rodada 3: especificar, implementar e testar
343. [ ] **VU0/VU1:** Modelar execução microprogramada VU1 — rodada 3: especificar, implementar e testar
344. [ ] **VU0/VU1:** Integrar VIF e transferências — rodada 3: especificar, implementar e testar
345. [ ] **VU0/VU1:** Criar testes determinísticos VU — rodada 3: especificar, implementar e testar
346. [ ] **VU0/VU1:** Documentar diferenças entre VU0 e VU1 — rodada 4: especificar, implementar e testar
347. [ ] **VU0/VU1:** Definir estado vetorial e acumuladores — rodada 4: especificar, implementar e testar
348. [ ] **VU0/VU1:** Definir memória micro/data VU — rodada 4: especificar, implementar e testar
349. [ ] **VU0/VU1:** Implementar decoder vetorial inicial — rodada 4: especificar, implementar e testar
350. [ ] **VU0/VU1:** Implementar operações add/sub vetoriais — rodada 4: especificar, implementar e testar
351. [ ] **GS e vídeo:** Documentar registradores GS essenciais
352. [ ] **GS e vídeo:** Definir modelo de VRAM
353. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores
354. [ ] **GS e vídeo:** Implementar transferência host-to-local básica
355. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste
356. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários
357. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais
358. [ ] **GS e vídeo:** Implementar rasterização de triângulos
359. [ ] **GS e vídeo:** Implementar textura básica
360. [ ] **GS e vídeo:** Implementar blending básico
361. [ ] **GS e vídeo:** Implementar scissor e viewport
362. [ ] **GS e vídeo:** Modelar framebuffer e display buffer
363. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360
364. [ ] **GS e vídeo:** Adicionar testes de renderização de referência
365. [ ] **GS e vídeo:** Medir custo e gargalos do GS
366. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 2: especificar, implementar e testar
367. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 2: especificar, implementar e testar
368. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 2: especificar, implementar e testar
369. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 2: especificar, implementar e testar
370. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 2: especificar, implementar e testar
371. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários — rodada 2: especificar, implementar e testar
372. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais — rodada 2: especificar, implementar e testar
373. [ ] **GS e vídeo:** Implementar rasterização de triângulos — rodada 2: especificar, implementar e testar
374. [ ] **GS e vídeo:** Implementar textura básica — rodada 2: especificar, implementar e testar
375. [ ] **GS e vídeo:** Implementar blending básico — rodada 2: especificar, implementar e testar
376. [ ] **GS e vídeo:** Implementar scissor e viewport — rodada 2: especificar, implementar e testar
377. [ ] **GS e vídeo:** Modelar framebuffer e display buffer — rodada 2: especificar, implementar e testar
378. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360 — rodada 2: especificar, implementar e testar
379. [ ] **GS e vídeo:** Adicionar testes de renderização de referência — rodada 2: especificar, implementar e testar
380. [ ] **GS e vídeo:** Medir custo e gargalos do GS — rodada 2: especificar, implementar e testar
381. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 3: especificar, implementar e testar
382. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 3: especificar, implementar e testar
383. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 3: especificar, implementar e testar
384. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 3: especificar, implementar e testar
385. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 3: especificar, implementar e testar
386. [ ] **GS e vídeo:** Modelar formatos de pixel prioritários — rodada 3: especificar, implementar e testar
387. [ ] **GS e vídeo:** Implementar primitivas de desenho iniciais — rodada 3: especificar, implementar e testar
388. [ ] **GS e vídeo:** Implementar rasterização de triângulos — rodada 3: especificar, implementar e testar
389. [ ] **GS e vídeo:** Implementar textura básica — rodada 3: especificar, implementar e testar
390. [ ] **GS e vídeo:** Implementar blending básico — rodada 3: especificar, implementar e testar
391. [ ] **GS e vídeo:** Implementar scissor e viewport — rodada 3: especificar, implementar e testar
392. [ ] **GS e vídeo:** Modelar framebuffer e display buffer — rodada 3: especificar, implementar e testar
393. [ ] **GS e vídeo:** Implementar caminho de apresentação Xbox 360 — rodada 3: especificar, implementar e testar
394. [ ] **GS e vídeo:** Adicionar testes de renderização de referência — rodada 3: especificar, implementar e testar
395. [ ] **GS e vídeo:** Medir custo e gargalos do GS — rodada 3: especificar, implementar e testar
396. [ ] **GS e vídeo:** Documentar registradores GS essenciais — rodada 4: especificar, implementar e testar
397. [ ] **GS e vídeo:** Definir modelo de VRAM — rodada 4: especificar, implementar e testar
398. [ ] **GS e vídeo:** Implementar escrita/leitura de registradores — rodada 4: especificar, implementar e testar
399. [ ] **GS e vídeo:** Implementar transferência host-to-local básica — rodada 4: especificar, implementar e testar
400. [ ] **GS e vídeo:** Implementar transferência local-to-host de teste — rodada 4: especificar, implementar e testar
401. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces
402. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo
403. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio
404. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos
405. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host
406. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio
407. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360
408. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox
409. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles
410. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos
411. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO
412. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura
413. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual
414. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor
415. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos
416. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 2: especificar, implementar e testar
417. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 2: especificar, implementar e testar
418. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 2: especificar, implementar e testar
419. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 2: especificar, implementar e testar
420. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 2: especificar, implementar e testar
421. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio — rodada 2: especificar, implementar e testar
422. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360 — rodada 2: especificar, implementar e testar
423. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox — rodada 2: especificar, implementar e testar
424. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles — rodada 2: especificar, implementar e testar
425. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos — rodada 2: especificar, implementar e testar
426. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO — rodada 2: especificar, implementar e testar
427. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura — rodada 2: especificar, implementar e testar
428. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual — rodada 2: especificar, implementar e testar
429. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor — rodada 2: especificar, implementar e testar
430. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos — rodada 2: especificar, implementar e testar
431. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 3: especificar, implementar e testar
432. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 3: especificar, implementar e testar
433. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 3: especificar, implementar e testar
434. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 3: especificar, implementar e testar
435. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 3: especificar, implementar e testar
436. [ ] **Áudio, controles e mídia:** Adicionar teste de saída de áudio — rodada 3: especificar, implementar e testar
437. [ ] **Áudio, controles e mídia:** Definir interface de controles Xbox 360 — rodada 3: especificar, implementar e testar
438. [ ] **Áudio, controles e mídia:** Mapear botões PS2 para controle Xbox — rodada 3: especificar, implementar e testar
439. [ ] **Áudio, controles e mídia:** Implementar leitura de estado dos controles — rodada 3: especificar, implementar e testar
440. [ ] **Áudio, controles e mídia:** Documentar formatos de mídia aceitos — rodada 3: especificar, implementar e testar
441. [ ] **Áudio, controles e mídia:** Implementar interface de leitura ISO — rodada 3: especificar, implementar e testar
442. [ ] **Áudio, controles e mídia:** Validar limites e erros de leitura — rodada 3: especificar, implementar e testar
443. [ ] **Áudio, controles e mídia:** Integrar CD/DVD virtual — rodada 3: especificar, implementar e testar
444. [ ] **Áudio, controles e mídia:** Criar teste de leitura de setor — rodada 3: especificar, implementar e testar
445. [ ] **Áudio, controles e mídia:** Documentar BIOS e firmware não distribuídos — rodada 3: especificar, implementar e testar
446. [ ] **Áudio, controles e mídia:** Documentar SPU2 e interfaces — rodada 4: especificar, implementar e testar
447. [ ] **Áudio, controles e mídia:** Definir estado SPU2 mínimo — rodada 4: especificar, implementar e testar
448. [ ] **Áudio, controles e mídia:** Implementar registros e memória de áudio — rodada 4: especificar, implementar e testar
449. [ ] **Áudio, controles e mídia:** Modelar vozes e envelopes básicos — rodada 4: especificar, implementar e testar
450. [ ] **Áudio, controles e mídia:** Integrar mixer de áudio do host — rodada 4: especificar, implementar e testar
451. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real
452. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação
453. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA
454. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura
455. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável
456. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente
457. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo
458. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais
459. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos
460. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais
461. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo
462. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura
463. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento
464. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste
465. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo
466. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 2: especificar, implementar e testar
467. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 2: especificar, implementar e testar
468. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 2: especificar, implementar e testar
469. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 2: especificar, implementar e testar
470. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 2: especificar, implementar e testar
471. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente — rodada 2: especificar, implementar e testar
472. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo — rodada 2: especificar, implementar e testar
473. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais — rodada 2: especificar, implementar e testar
474. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos — rodada 2: especificar, implementar e testar
475. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais — rodada 2: especificar, implementar e testar
476. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo — rodada 2: especificar, implementar e testar
477. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura — rodada 2: especificar, implementar e testar
478. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento — rodada 2: especificar, implementar e testar
479. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste — rodada 2: especificar, implementar e testar
480. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo — rodada 2: especificar, implementar e testar
481. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 3: especificar, implementar e testar
482. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 3: especificar, implementar e testar
483. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 3: especificar, implementar e testar
484. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 3: especificar, implementar e testar
485. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 3: especificar, implementar e testar
486. [ ] **Boot, runtime e compatibilidade:** Criar configuração persistente — rodada 3: especificar, implementar e testar
487. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de seleção de jogo — rodada 3: especificar, implementar e testar
488. [ ] **Boot, runtime e compatibilidade:** Adicionar listagem de jogos locais — rodada 3: especificar, implementar e testar
489. [ ] **Boot, runtime e compatibilidade:** Adicionar favoritos — rodada 3: especificar, implementar e testar
490. [ ] **Boot, runtime e compatibilidade:** Adicionar capas opcionais — rodada 3: especificar, implementar e testar
491. [ ] **Boot, runtime e compatibilidade:** Adicionar menu de compatibilidade por jogo — rodada 3: especificar, implementar e testar
492. [ ] **Boot, runtime e compatibilidade:** Adicionar estado de salvamento apenas após arquitetura segura — rodada 3: especificar, implementar e testar
493. [ ] **Boot, runtime e compatibilidade:** Criar diagnóstico de travamento — rodada 3: especificar, implementar e testar
494. [ ] **Boot, runtime e compatibilidade:** Definir suite homebrew de teste — rodada 3: especificar, implementar e testar
495. [ ] **Boot, runtime e compatibilidade:** Executar primeira inicialização no hardware-alvo — rodada 3: especificar, implementar e testar
496. [ ] **Boot, runtime e compatibilidade:** Substituir bootstrap vazio por inicialização real — rodada 4: especificar, implementar e testar
497. [ ] **Boot, runtime e compatibilidade:** Definir ciclo principal de emulação — rodada 4: especificar, implementar e testar
498. [ ] **Boot, runtime e compatibilidade:** Definir scheduler EE/IOP/VU/DMA — rodada 4: especificar, implementar e testar
499. [ ] **Boot, runtime e compatibilidade:** Inicializar subsistemas em ordem segura — rodada 4: especificar, implementar e testar
500. [ ] **Boot, runtime e compatibilidade:** Criar logging configurável — rodada 4: especificar, implementar e testar
501. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon
502. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado
503. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC
504. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo
505. [ ] **Toolchain Xenon e XEX:** Validar elf2xex
506. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo
507. [ ] **Toolchain Xenon e XEX:** Converter para default.xex
508. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX
509. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso
510. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário
511. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon
512. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências
513. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build
514. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio
515. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível
516. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 2: especificar, implementar e testar
517. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 2: especificar, implementar e testar
518. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 2: especificar, implementar e testar
519. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 2: especificar, implementar e testar
520. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 2: especificar, implementar e testar
521. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo — rodada 2: especificar, implementar e testar
522. [ ] **Toolchain Xenon e XEX:** Converter para default.xex — rodada 2: especificar, implementar e testar
523. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX — rodada 2: especificar, implementar e testar
524. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso — rodada 2: especificar, implementar e testar
525. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário — rodada 2: especificar, implementar e testar
526. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon — rodada 2: especificar, implementar e testar
527. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências — rodada 2: especificar, implementar e testar
528. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build — rodada 2: especificar, implementar e testar
529. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio — rodada 2: especificar, implementar e testar
530. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível — rodada 2: especificar, implementar e testar
531. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 3: especificar, implementar e testar
532. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 3: especificar, implementar e testar
533. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 3: especificar, implementar e testar
534. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 3: especificar, implementar e testar
535. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 3: especificar, implementar e testar
536. [ ] **Toolchain Xenon e XEX:** Compilar primeiro alvo mínimo — rodada 3: especificar, implementar e testar
537. [ ] **Toolchain Xenon e XEX:** Converter para default.xex — rodada 3: especificar, implementar e testar
538. [ ] **Toolchain Xenon e XEX:** Verificar tamanho e checksum do XEX — rodada 3: especificar, implementar e testar
539. [ ] **Toolchain Xenon e XEX:** Publicar artefato somente após sucesso — rodada 3: especificar, implementar e testar
540. [ ] **Toolchain Xenon e XEX:** Manter ELF apenas como intermediário — rodada 3: especificar, implementar e testar
541. [ ] **Toolchain Xenon e XEX:** Separar build host de build Xenon — rodada 3: especificar, implementar e testar
542. [ ] **Toolchain Xenon e XEX:** Adicionar cache seguro de dependências — rodada 3: especificar, implementar e testar
543. [ ] **Toolchain Xenon e XEX:** Adicionar logs completos do build — rodada 3: especificar, implementar e testar
544. [ ] **Toolchain Xenon e XEX:** Adicionar verificação de artefato vazio — rodada 3: especificar, implementar e testar
545. [ ] **Toolchain Xenon e XEX:** Executar XEX no ambiente de teste disponível — rodada 3: especificar, implementar e testar
546. [ ] **Toolchain Xenon e XEX:** Registrar versão da toolchain libXenon — rodada 4: especificar, implementar e testar
547. [ ] **Toolchain Xenon e XEX:** Validar xenon-gcc no runner configurado — rodada 4: especificar, implementar e testar
548. [ ] **Toolchain Xenon e XEX:** Validar linker e flags PowerPC — rodada 4: especificar, implementar e testar
549. [ ] **Toolchain Xenon e XEX:** Validar linker script do alvo — rodada 4: especificar, implementar e testar
550. [ ] **Toolchain Xenon e XEX:** Validar elf2xex — rodada 4: especificar, implementar e testar

## Critérios de conclusão

- [ ] Build host reproduzível e suíte de testes executada com logs.
- [ ] Toolchain Xenon configurada e `default.xex` produzido e verificado.
- [ ] Runtime de vídeo/controles inicializado no Xbox 360 RGH.
- [ ] Subsistemas do PS2 integrados e testados por casos reproduzíveis.
- [ ] Boot de BIOS/jogo demonstrado legalmente, sem distribuir BIOS proprietária.
- [ ] Percentual geral recalculado a partir de evidências, não da quantidade de tarefas listadas.
