#include <stdio.h>
#include <stdlib.h>
#include "Booleano.h"

// Função para imprimir a matriz de forma visual
void imprimirMatriz(int matriz[10][10]) {
    for (int i = 1; i <= 9; i++) { // Começa de 1 até 9 para usar as linhas 1 a 9
        for (int j = 1; j <= 9; j++) { // Começa de 1 até 9 para usar as colunas 1 a 9
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se há números repetidos em uma linha ou coluna
bool verificarRepetido(int matriz[10][10]) {
    // Verificar repetição nas linhas
    for (int i = 1; i <= 9; i++) {
        bool linha[9] = {FALSE};
        for (int j = 1; j <= 9; j++) {
            int num = matriz[i][j] - 1; // Ajuste para índice zero (1-9)
            if (linha[num]) {
                return TRUE; // Número repetido na linha
            }
            linha[num] = TRUE;
        }
    }

    // Verificar repetição nas colunas
    for (int j = 1; j <= 9; j++) {
        bool coluna[9] = {FALSE};
        for (int i = 1; i <= 9; i++) {
            int num = matriz[i][j] - 1; // Ajuste para índice zero (1-9)
            if (coluna[num]) {
                return TRUE; // Número repetido na coluna
            }
            coluna[num] = TRUE;
        }
    }

    return FALSE; // Não encontrou repetições
}

int main() {
    FILE *arquivo;
    int matriz[10][10] = {0};  // Matriz 10x10 (com índices de 1 a 9 sendo usados)

    // Abrir o arquivo SUDOKU.txt
    arquivo = fopen("SUDOKU.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Ler os números do arquivo e armazená-los na matriz
    for (int i = 1; i <= 9; i++) { // Começar da linha 1 até 9
        for (int j = 1; j <= 9; j++) { // Começar da coluna 1 até 9
            if (fscanf(arquivo, "%1d", &matriz[i][j]) != 1) {
                printf("Erro na leitura do arquivo!\n");
                fclose(arquivo);
                return 1;
            }
        }
    }

    // Fechar o arquivo após a leitura
    fclose(arquivo);

    // Imprimir a matriz
    printf("Tabela Sudoku:\n");
    imprimirMatriz(matriz);

    // Verificar se há números repetidos
    if (verificarRepetido(matriz)) {
        printf("\nINCORRETO\n");
    } else {
        printf("\nCORRETO\n");
    }

    return 0;
}
