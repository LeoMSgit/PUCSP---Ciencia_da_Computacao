#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>

// Definição das variáveis globais
TipoDomino tipo;
int numeroJogadores = MIN_JOGADORES; // Inicializa com o mínimo de jogadores

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

void embaralharPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int sorteio = rand() % TOTAL_PECAS;
        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}
