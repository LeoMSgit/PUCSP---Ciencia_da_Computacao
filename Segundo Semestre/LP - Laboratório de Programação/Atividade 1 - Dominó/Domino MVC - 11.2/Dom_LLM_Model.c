// Dom_LLM_Model.h

#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>

// Definição das variáveis globais
TipoDomino tipo;
int numeroJogadores = MIN_JOGADORES;
Jogador jogadores[MAX_JOGADORES];
Monte monte;
Mesa mesa;

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
    int indicePeca = 0;  // De onde tirar as peças embaralhadas
    
    for (int i = 0; i < numJogadores; i++) {
        for (int j = 0; j < PECAS_POR_JOGADOR; j++) {
        	int sorteio = rand() % (TOTAL_PECAS - indicePeca);
        	pecasEmbaralhadas[indicePeca + sorteio] = pecasEmbaralhadas[indicePeca];
            jogadores[i].pecas[j] = pecasEmbaralhadas[indicePeca];  // Atribui a peça ao jogador
            indicePeca++;
        }
    }
}

void inicializarMonte(PecaDomino pecas[], int quantidadeDistribuida) {
    int indiceMonte = 0;

    // Calcula as peças restantes no monte após a distribuição
    for (int i = quantidadeDistribuida; i < TOTAL_PECAS; i++) {
        monte.pecasRestantes[indiceMonte] = pecas[i];
        indiceMonte++;
    }

    monte.quantidadeRestante = TOTAL_PECAS - quantidadeDistribuida;
    embaralharPecas(monte.pecasRestantes, monte.quantidadeRestante); // Embaralha o monte
}

void inicializarMesa() {
    tipo.mesa.quantidade = 0;  // Inicializa a mesa como vazia
}

PecaDomino encontrarMaiorPeca(Jogador jogador) {
    PecaDomino maiorPeca = jogador.pecas[0];
    
    for (int i = 1; i < PECAS_POR_JOGADOR; i++) {
        int valorAtual = jogador.pecas[i].lado1 + jogador.pecas[i].lado2;
        int valorMaior = maiorPeca.lado1 + maiorPeca.lado2;

        if (valorAtual > valorMaior) {
            maiorPeca = jogador.pecas[i];
        }
    }
    
    return maiorPeca;
}

int definirJogadorInicial(Jogador jogadores[], int numeroJogadores) {
    int jogadorInicial = 0;
    PecaDomino maiorPecaGeral = encontrarMaiorPeca(jogadores[0]);
    
    for (int i = 1; i < numeroJogadores; i++) {
        PecaDomino maiorPecaJogador = encontrarMaiorPeca(jogadores[i]);
        
        int valorMaiorPecaJogador = maiorPecaJogador.lado1 + maiorPecaJogador.lado2;
        int valorMaiorPecaGeral = maiorPecaGeral.lado1 + maiorPecaGeral.lado2;
        
        if (valorMaiorPecaJogador > valorMaiorPecaGeral) {
            maiorPecaGeral = maiorPecaJogador;
            jogadorInicial = i;
        }
    }
    
    printf("\n\nJogador %d fara a primeira jogada com a peca [%d|%d].\n\n", 
           jogadorInicial + 1, maiorPecaGeral.lado1, maiorPecaGeral.lado2);
           
    return jogadorInicial;
}