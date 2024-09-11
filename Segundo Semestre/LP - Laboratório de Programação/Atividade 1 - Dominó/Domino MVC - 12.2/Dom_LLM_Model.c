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

// Função para distribuir as peças para os jogadores
void distribuirPecas(Jogador jogadores[], PecaDomino pecasEmbaralhadas[], int numJogadores) {
    int indicePeca = 0;  // De onde tirar as peças embaralhadas

    for (int i = 0; i < numJogadores; i++) {
        for (int j = 0; j < PECAS_POR_JOGADOR; j++) {
            jogadores[i].pecas[j] = pecasEmbaralhadas[indicePeca];  // Atribui a peça ao jogador
            indicePeca++;
        }
        jogadores[i].quantidadePecas = PECAS_POR_JOGADOR;
    }

    // Inicializar o monte com as peças restantes
    inicializarMonte(pecasEmbaralhadas, indicePeca);
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

int jogadaValida(PecaDomino peca, int ladoEscolhido) {
    if (ladoEscolhido == 0) { // Lado esquerdo
        if (mesa.quantidade == 0) return 1; // Se a mesa está vazia, qualquer peça é válida
        return peca.lado1 == mesa.pecas[0].lado1 || peca.lado2 == mesa.pecas[0].lado1;
    } else if (ladoEscolhido == 1) { // Lado direito
        if (mesa.quantidade == 0) return 1; // Se a mesa está vazia, qualquer peça é válida
        return peca.lado1 == mesa.pecas[mesa.quantidade - 1].lado2 || peca.lado2 == mesa.pecas[mesa.quantidade - 1].lado2;
    }
    return 0; // Jogada inválida
}

void adicionarPecaMesa(PecaDomino peca, int ladoEscolhido) {
    if (ladoEscolhido == 0) { // Adiciona ao lado esquerdo
        for (int i = mesa.quantidade; i > 0; i--) {
            mesa.pecas[i] = mesa.pecas[i - 1];
        }
        mesa.pecas[0] = peca;
    } else { // Adiciona ao lado direito
        mesa.pecas[mesa.quantidade] = peca;
    }
    mesa.quantidade++;
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