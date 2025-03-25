/* atividade L2 */
/* Arquivo: OthonLeonardoATL2.c
 Autores: Othon Luiz Franca de Souza e Silva; Leonardo Miguel dos Santos
 Data: 23/03/2025
 Descrição: verificar existência de duplicatas em uma matriz do pequeno sudoku
*/

#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

#define FANTASMA 63
#define TAM 9

void imprimirMatriz(unsigned char M[][]);
bool verificarRepetido(unsigned char V[]);

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
    char numeros;

    // "Função" Ler Arquivo
    arquivo = fopen("SUDOKU.txt", "r");
    if (arquivo != NULL) {
        while (((numeros = fgetc(arquivo)) != EOF) && (linha <= TAM)) {
            if (numeros >= '1' && numeros <= '9') {
                M[linha][coluna] = numeros - '0';
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

    // Implementação de Imprimir Matriz
    imprimirMatriz(M);

    // "Função" Verificar Sudoku -> Implementação de 'bool verificarRepetido'
    bool valido = TRUE;
    bool repLinha, repCol;

    // Verificar repetição nas linhas
    i = 1;
    while (i <= TAM && valido == TRUE) {
        unsigned char linha[TAM];
        for (j = 1; j <= TAM; j++) {
            linha[j - 1] = M[i][j];
        }
        repLinha = verificarRepetido(linha);
        if (repLinha == TRUE) {
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
            repCol = verificarRepetido(coluna);
            if (repCol == TRUE) {
                valido = FALSE;
            }
            j++;
        }
    }

    // Exibir resultado
    if (valido == TRUE) {
        printf("\nCORRETO\n");
    } else {
        printf("\nINCORRETO\n");
    }

    return 0;
}
