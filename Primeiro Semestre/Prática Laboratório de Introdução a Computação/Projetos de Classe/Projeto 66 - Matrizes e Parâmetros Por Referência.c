//Funções usando Matrizes Bidimensionais

//Criar uma Matriz 10x20
//Criar 3 funções que trabalharão sobre a matriza
//1 - Mostra a matriz
//2 - Dobra os valores da matriz e mostra
//3 - Altera os valores multiplos de 9 por 0

//MATRIZES SEMPRE UTILIZA PARAMETROS POR REFERENCIA, NAO NECESSITA DE PONTEIRO '*m'
//A Variável Matriz por si só já é um endereço, não necessitando de '&'
#include <stdio.h>

void fMostraMat(int m[10][20]);
void fDuplicaMat(int m[10][20]);
void fZeraNove(int m[10][20]);
int i,j;


int main ()
	{int m[10][20];
	int i, j;
	int n = 1;
	
	for (i=0; i < 10; i++)
		for (j=0; j < 20; j++)
			{m[i][j] = n;
			n++;
			}
	
	 // Imprime a matriz original
    printf("Matriz original:\n");
    fMostraMat(m);

    // Imprime a matriz com os valores duplicados
    fDuplicaMat(m);
    printf("\nMatriz duplicada:\n");
    fMostraMat(m);

    // Imprime a matriz com os valores duplicados E zerando os múltiplos de 9
    fZeraNove(m);
    printf("\nMatriz com múltiplos de 9 zerados:\n");
    fMostraMat(m);
	}
	
	
void fMostraMat(int m[10][20]) {		//Imprimir a Matriz m
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 20; j++)
            printf("%5d", m[i][j]);
        printf("\n");					
    }
}

void fDuplicaMat(int m[10][20]) {		//Dobra os valores da Matriz m, mudando permanentemente e sobrescrevendo todos seus valores, agora a "segunda" Matriz m é = "primeira" Matriz m*2
    for (i = 0; i < 10; i++)
        for (j = 0; j < 20; j++)
            m[i][j] *= 2;
}

void fZeraNove(int m[10][20]) {			//Troca todos os valores múltiplos de 9 da Matriz m ("segunda" Matriz m), também sobrescrevendo com uma "terceira" Matriz m
    for (i = 0; i < 10; i++)
        for (j = 0; j < 20; j++)
            if (m[i][j] % 9 == 0)
                m[i][j] = 0;
}
