#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define FANTASMA 63
#define TAM 9

void imprimirMatriz(unsigned char M[10][10]) {
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
    int i = 0, j;
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

int main() {
    unsigned char M[10][10];
    FILE *arquivo;
    int i, j, linha = 1, coluna = 1;
    char caractere;

    // Leitura do arquivo
    arquivo = fopen("SUDOKU.txt", "r");
    if (arquivo != NULL) {
        while (((caractere = fgetc(arquivo)) != EOF) && (linha <= TAM)) {
            if (caractere >= '1' && caractere <= '9') {
                M[linha][coluna] = caractere - '0';
                coluna++;
                if (coluna > TAM) {
                    coluna = 1;
                    linha++;
                }
            }
        }
        fclose(arquivo);
    } else {
        for (i = 1; i <= TAM; i++) {
            for (j = 1; j <= TAM; j++) {
                M[i][j] = FANTASMA;
            }
        }
    }

    // Exibição da matriz
    imprimirMatriz(M);

    // Verificação do Sudoku
    bool valido = TRUE;
    bool verRepLinha, verRepCol;

    // Verificar repetição nas linhas
    i = 1;
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

    // Verificar repetição nas colunas
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

    // Exibir resultado
    if (valido == TRUE) {
        printf("CORRETO\n");
    } else {
        printf("INCORRETO\n");
    }

    return 0;
}
