ATIVIDADE L3 – laboratório
Comparação de tempo em algoritmos de ordenação n2
INSTRUÇÕES
1) A atividade deve ser feita em grupos de 4 alunos e finalizada em 06/05/2025.
2) Na data especificada deve ser entregue:
a) um único arquivo identificado por <nome_sobrenome>ATL3.c, contendo o nome e sobrenome de
um único dos alunos do grupo.
b) O cabeçalho do programa deve ser como mostra o modelo:
/* atividade L3 */
/* Arquivo: <nome_sobrenome>ATL3.c
 Autores: <nomes completos dos 4 alunos>
 Data: 06/05/2025
 Descrição: comparar tempo de execução de algoritmos de ordenação
*/
3) O arquivo entregue deve conter SOMENTE o arquivo fonte.
4) Os códigos entregues serão testados em um programa de testes e avaliados nos quesitos:
• Conformidade com todas as instruções dadas no curso.
• Algoritmos utilizados nas implementações.
• Produção de saídas corretas em todos os testes realizados
• Programas não compilados terão nota de avaliação igual a 0.5
5) Na data de entrega o programa deve ser executado e a folha de respostas deverá ser preenchida com os
resultados obtidos.
COMPARAÇÃO DOS TEMPOS DE EXECUÇÃO DOS ALGORITMOS DE ORDENAÇÃO
a) O programa entregue deve permitir a comparação dos tempos de execução de três
algoritmos de ordenação – BubbleSort, SelectionSort, InsertionSort.
b) O arquivo “tempoSorting.c” contém as estruturas de dados, diretivas e algumas
implementações e deve ser usado para fazer o programa da atividade. É preciso completar
a função main para obter os resultados desejados.
c) O arquivo “sortingListaInt.h” contém as implementações dos três algoritmos de ordenação,
SelectionSort, InsertionSort e BubbleSort e deve ser utilizado, sem modificações.
Efetuamos medidas de tempo de execução desses
processos, com uma mesma lista aleatória, e obtivemos o
seguinte gráfico que mostra uma pequena diferença entre
os tempos de execução de cada um dos três processos.
Figura 1
Comparar, por meio do programa, os tempos de execução
com N = tamanho da lista, 10000 ≤ N ≤ 150000.
