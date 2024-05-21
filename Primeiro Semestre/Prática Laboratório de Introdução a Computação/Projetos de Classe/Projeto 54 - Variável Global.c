//Matrizes Bidimensionais com Variáveis Globais
//Formular uma tabela de 10 linhas e 20 colunas
//Preencher com números em ordem crescente de 10 em 10
//Apresentar na tela a tabela

//Variáveis Globais Ocupam muito espaço e devem ser usadas com juízo e cuidado, pois serão rodadas TODAS as vezes que o progama for rodado. Porém permitem uma alteração fácil de todas as varíaveis de um código.

#include <stdio.h>
int QTLINHA = 10;
int QTCOLUNA = 20;

int main ()
	{int Mat[QTLINHA][QTCOLUNA];
	int i, j;
	int n = 1;
	
	for (i=0; i < QTLINHA; i++)
		for (j=0; j < QTCOLUNA; j++)
			{Mat[i][j] = n*10;
			n++;
			}
	
	for (i=0; i < QTLINHA; i++)
		{for (j=0; j < QTCOLUNA; j++)
			printf("%5d", Mat[i][j]);
		printf("\n");
		}
	}
