PUCSP/1ºsem 2024 LIC-prática
Laboratório de Introdução à Computação -
prof. Eli Banks
Atividade 03
Exercício individual, a ser entregue via ambiente
Teams com o código:
XXXXX-Ativ03 
onde: XXXXX corresponde às letras iniciais do nome do aluno
 (usar o hífen “-“ como separação no código)
Implementar o seguinte programa codificado em linguagem C usando
apenas a tela texto:
Definição do programa:
Solicitar uma data no formato DD/MM/AAAA, fazendo a consistência se a
digitação está correta quanto ao seu formato e validade.
A seguir, calcular e apresentar:
1. a quantidade de dias completos já decorridos desde o início desse ano
até essa data especificada (inclusive). 
2. a quantidade de dias que ainda faltam até o final do ano em questão.
3. a quantidade total de dias do ano em questão (deve ser a soma das 2
respostas anteriores)
Orientações para a implementação do programa:
Para resolver este problema, deverão ser desenvolvidas e utilizadas as
seguintes funções:
int fAnoBissexto(int a) //retorna 1 se o ano é bissexto, ou 0 se não for.
int fDataValida(int d, int m, int a) //verifica se uma data é válida
indicando qual o erro (dia, mês e/ou ano errado)
int fDiasInicioAno(int d, int m, int a) //retorna a quantidade de dias
desde o início do ano até a data inclusive.
int fDiasFimAno(int d, int m, int a) //retorna a quantidade de dias que
faltam para o fim do ano, caso necessario, usar a função anterior
fDiasInicioAno()
Observações:
A data informada deverá ser consistida quanto à sua validade e deverá
estar entre 01/01/1600 e 31/12/5000.
O programa deve ser reciclável, saindo fora somente se o dia for zero.
(avise o operador dessa possibilidade).
Dicas:
Verificar se o ano é bissexto ANTES de qualquer cálculo, pois você vai
precisar saber disso quando processar qualquer data de qualquer mês do
ano.
A quantidade de dias dos meses varia (meses: 4, 6, 9 e 11 possuem 30 dias,
os outros 31 e o mês de fevereiro 28 ou 29 dependendo se ano é bissexto
ou não). 
Um ano é bissexto quando for divisível por 4 e não por 100 ou então
quando o ano é divisível por 400
Testar exaustivamente com datas limites: dias 01/01, 01/03, 31/12, etc. de
anos não bissextos e anos bissextos
Exemplos e respostas p/testes:
 Data 28/06/2022 179 dias desde o inicio e 186 até o fim do ano
 Data 28/06/2020 180 dias desde o inicio e 186 até o fim do ano
 Data 07/09/1822 250 dias desde o inicio e 115 até o fim do ano
 Data 25/12/2000 360 dias desde o inicio e 6 até o fim do ano
Além do programa correto, serão considerados:
- o código do programa e o cabeçalho rigorosamente conforme 
padronizados (veja no Teams na aba Arquivos o texto: “Seja Organizado” 
- os comentários pertinentes
- a lógica adotada
- a clareza na apresentação do programa-fonte (endentações corretas, 
variáveis bem definidas, etc)
- a interface amigável ao usuário do programa que não deixa dúvidas.
- seja criativo e compreenda o problema proposto como um projeto prático, 
tornando-o o mais amigável possível.
