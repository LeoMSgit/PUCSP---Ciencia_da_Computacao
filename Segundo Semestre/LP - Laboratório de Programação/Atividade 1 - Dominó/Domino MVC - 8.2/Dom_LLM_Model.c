// Dom_LLM_Model.h

#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>

// Definição das variáveis globais
TipoDomino tipo;
int numeroJogadores = MIN_JOGADORES;
Jogador jogadores[MAX_JOGADORES];

// Funções do Model
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
        int sorteio = rand() % tamanho;
        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}

void distribuirPecas(Jogador jogadores[], PecaDomino pecasEmbaralhadas[], int numJogadores) {
    int indicePeca = 0;  // Índice para rastrear de onde tirar as peças embaralhadas
    
    for (int i = 0; i < numJogadores; i++) {
        for (int j = 0; j < PECAS_POR_JOGADOR; j++) {
            jogadores[i].pecas[j] = pecasEmbaralhadas[indicePeca];  // Atribui a peça ao jogador
            indicePeca++;
        }
    }
}
