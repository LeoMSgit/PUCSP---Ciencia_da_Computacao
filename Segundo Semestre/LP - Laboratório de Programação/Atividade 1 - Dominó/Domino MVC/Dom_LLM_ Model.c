// Dom_LLM_Model.c

#include <stdio.h>
#include <stdlib.h>
#include "Dom_LLM_Model.h"

void gerarPecas(PecaDomino pecas[]) {
    int indice = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[indice].lado1 = i;
            pecas[indice].lado2 = j;
            indice++;
        }
    }
}

void imprimirPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (pecas[j].lado1 == i) {
                printf("[%d|%d] ", pecas[j].lado1, pecas[j].lado2);
            }
        }
        printf("\n");
    }
}

void embaralharPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int sorteio = rand() % TOTAL_PECAS;
        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}
