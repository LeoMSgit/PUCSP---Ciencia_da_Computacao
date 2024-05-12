1) Objetivo<br />
Desenvolver um Algorítimo que calcule o menor numero de notas de P$ 5 e P$ 3, que são necessárias para compor um valor N.

2) Raciocínio Lógico<br />
Para verificar-se qual o numero mínimo de notas de P$ 5 e P$ 3, devemos dividir o valor desejado N primeiramente por 5, pois esse é o maior valor das notas de P$, repentido o processo agora com o QUOCIENTE até encontrarmos um caso em que o RESTO seja DIFERENTE de 0. Nesse momento devemos trocamos o DIVISOR da equação por 3 e repetir o processo de divisões sucessivas até o RESTO ser igual a 0 E o QUOCIENTE for MENOR do que 3. 
Caso a divisão resulte em RESTO DIFERENTE de 0, podemos “devolver” um agrupamento de 5 unidades ao REDUZIR em 1 o número de notas de P$ 5 encontradas e ADICIONAR 5 ao valor do DIVIDENDO, se ainda não for suficiente para que o RESTO seja DIFENTE de 0, repetimos o processo até encontrarmos um valor que satisfaça essa condição.

3) Análise do Problema<br />
• Análise dos Dados
- Os dados processados são números naturais maiores, pois se tratam de valores monetários
• Dados de Entrada
- A entrada é composta por apenas um valor numérico natural, o valor que desejamos dividir por 5 e 3. O valor da entrada deve ser maior ou igual a 8, uma vez que o enunciado menciona que nada custa meno de P$ 8
• Dados de Saída
- A saída é composta por dois valores numéricos naturais, um correspondente ao total de notas de 5 utilizadas para formar o valor inserido na entrada e outro o de notas de 3 utilizadas para formar o valor inserido na entrada
• Variável de Entrada
- N (natural)
• Variáveis de Saída
- P (natural, representando a quantidade de notas P$ 5) e Q (natural, representando a quantidade de notas P$ 3)

4) Corpo do Algorítimo (Fórumla Geral)<br />

calcularPinguins ( )<br />
&ensp;leia(N);<br />
&ensp;R ← 0; P ← 0; Q ← 0; S ← 1; i = 0;<br />
<br />
&ensp;P ← N DIV 5;<br />
&ensp;R ← N MOD 5;<br />
<br />
&ensp;enquanto (R ≠ 0) faça<br />
&ensp;&ensp;enquanto (R < 3) faça<br />
&ensp;&ensp;&ensp;P ← P - 1;<br />
&ensp;&ensp;&ensp;R ← R + 5;<br />
&ensp;&ensp;&ensp;i ← i +1;<br />
<br />
&ensp;Q ← (R DIV 3) + i;<br />
&ensp;R ← R MOD 3;<br />
<br />
&ensp;imprima (P, Q);<br />
