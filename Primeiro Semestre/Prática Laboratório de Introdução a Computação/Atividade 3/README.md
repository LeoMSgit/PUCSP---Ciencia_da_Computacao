PUCSP/1ºsem 2024 LIC-prática<br />
Laboratório de Introdução à Computação - prof. Eli Banks<br />
Atividade 03<br />
Exercício individual, a ser entregue via ambiente Teams com o código: XXXXX-Ativ03 onde: XXXXX corresponde às letras iniciais do nome do aluno (usar o hífen “-“ como separação no código)<br />
Implementar o seguinte programa codificado em linguagem C usando apenas a tela texto:<br />
Definição do programa:<br />
Solicitar uma data no formato DD/MM/AAAA, fazendo a consistência se a digitação está correta quanto ao seu formato e validade.<br />
A seguir, calcular e apresentar:<br />
1. a quantidade de dias completos já decorridos desde o início desse ano até essa data especificada (inclusive).<br />
2. a quantidade de dias que ainda faltam até o final do ano em questão.<br />
3. a quantidade total de dias do ano em questão (deve ser a soma das 2 respostas anteriores)<br />
Orientações para a implementação do programa:<br />
Para resolver este problema, deverão ser desenvolvidas e utilizadas as seguintes funções:<br />
int fAnoBissexto(int a) //retorna 1 se o ano é bissexto, ou 0 se não for.<br />
int fDataValida(int d, int m, int a) //verifica se uma data é válida indicando qual o erro (dia, mês e/ou ano errado)<br />
int fDiasInicioAno(int d, int m, int a) //retorna a quantidade de dias desde o início do ano até a data inclusive.<br />
int fDiasFimAno(int d, int m, int a) //retorna a quantidade de dias que faltam para o fim do ano, caso necessario, usar a função anterior fDiasInicioAno()<br />
Observações:<br />
A data informada deverá ser consistida quanto à sua validade e deverá estar entre 01/01/1600 e 31/12/5000.<br />
O programa deve ser reciclável, saindo fora somente se o dia for zero.<br />
(avise o operador dessa possibilidade).<br />
Dicas:<br />
Verificar se o ano é bissexto ANTES de qualquer cálculo, pois você vai precisar saber disso quando processar qualquer data de qualquer mês do ano.<br />
A quantidade de dias dos meses varia (meses: 4, 6, 9 e 11 possuem 30 dias, os outros 31 e o mês de fevereiro 28 ou 29 dependendo se ano é bissexto ou não).<br />
Um ano é bissexto quando for divisível por 4 e não por 100 ou então quando o ano é divisível por 400<br />
Testar exaustivamente com datas limites: dias 01/01, 01/03, 31/12, etc.  anos não bissextos e anos bissextos<br />
Exemplos e respostas p/testes:<br />
 Data 28/06/2022 179 dias desde o inicio e 186 até o fim do ano<br />
 Data 28/06/2020 180 dias desde o inicio e 186 até o fim do ano<br />
 Data 07/09/1822 250 dias desde o inicio e 115 até o fim do ano<br />
 Data 25/12/2000 360 dias desde o inicio e 6 até o fim do ano<br />
Além do programa correto, serão considerados:<br />
- o código do programa e o cabeçalho rigorosamente conforme padronizados (veja no Teams na aba Arquivos o texto: “Seja Organizado” <br />
- os comentários pertinentes<br />
- a lógica adotada<br />
- a clareza na apresentação do programa-fonte (endentações corretas, variáveis bem definidas, etc)<br />
- a interface amigável ao usuário do programa que não deixa dúvidas.<br />
- seja criativo e compreenda o problema proposto como um projeto prático, tornando-o o mais amigável possível.<br />
