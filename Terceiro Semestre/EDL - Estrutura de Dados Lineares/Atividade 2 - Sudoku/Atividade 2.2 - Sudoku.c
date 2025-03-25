/* atividade L2 */
/* Arquivo: seu_nome_ATL2.c
Autores: Nome1 Nome2 Nome3 Nome4
Data: 01/04/2025
Descrição: verificar existência de duplicatas em uma matriz do pequeno sudoku
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define FANTASMA 63
#define TAM 9


void lerArquivoParaMatriz(unsigned char M[10][10], char *file) {
    FILE *arquivo;
    arquivo = fopen(file, "r");
    int i, j, linha = 1, coluna = 1;
    char caractere;

    if (arquivo != NULL) {
    	while (((caractere = fgetc(arquivo)) != EOF) && (linha<=TAM)) {
        	if (isdigit(caractere) && (caractere !='\n')) {
            	M[linha][coluna] = caractere - '0';
            	coluna++;
            	if (coluna > TAM) {
                	coluna = 1;
                	linha++;
            	}
        	}
    	}
	} else {
		for (i = 1; i <= TAM; i++) {
        	for (j = 1; j <= TAM; j++) {
            	M[i][j] = FANTASMA;
        	}
    	}
	}
    fclose(arquivo);
}

void exibirMatriz(unsigned char M[10][10]) {
    int i, j;

    printf("Matriz:\n");
    for (i = 1; i <= TAM; i++) {
        for (j = 1; j <= TAM; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

bool verificarRepetido(unsigned char V[]) {
    int i = 0;
	int j;
	bool resultado = FALSE;
    while (i < TAM && resultado == FALSE) {
        j = i + 1;
        while (j < TAM && resultado == FALSE) {
            if (V[i] == V[j]) {
                resultado = TRUE;
            }
            j++;
        }
        i++;
    }
    return resultado;
}


void verificarSudoku(unsigned char M[10][10]) {
    int i = 1;
	int j;
    bool valido = TRUE;
    bool verRepLinha, verRepCol;

    //VERIFICAR REPETIÇÃO NAS LINHAS
    while (i <= TAM && valido == TRUE) {
        unsigned char linha[TAM];
        for (j = 1; j <= TAM; j++) {
            linha[j - 1] = M[i][j];
        }
        verRepLinha = verificarRepetido(linha);
        if (verRepLinha == TRUE) {
            valido = FALSE;
        }
        i++;
    }

    //VERIFICAR REPETIÇÃO NAS COLUNAS
    if (valido == TRUE) {
        j = 1;
        while (j <= TAM && valido == TRUE) {
            unsigned char coluna[TAM];
            for (i = 1; i <= TAM; i++) {
                coluna[i - 1] = M[i][j];
            }
            verRepCol = verificarRepetido(coluna);
            if (verRepCol == TRUE) {
                valido = FALSE;
            }
            j++;
        }
    }
    
    if (valido == TRUE) {
        printf("CORRETO\n");
    } else {
        printf("INCORRETO\n");
    }
}
int main() {
    unsigned char M[10][10];

    // 1. Ler o arquivo e armazenar na matriz
    lerArquivoParaMatriz(M, "SUDOKU.txt");

    // 2. Exibir a matriz (opcional, mas útil para verificar a leitura)
    exibirMatriz(M);

    // 3. Verificar se é uma solução de Sudoku
	verificarSudoku(M);

    return 0;
}
