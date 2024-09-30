// Dom_LLM_Model.h

#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // Biblioteca para usar o tipo bool

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
    // Verifica se a mesa está vazia
    if (mesa.quantidade == 0) {
        // Se a mesa estiver vazia, qualquer peça pode ser jogada
        return 1;
    }

    // Lado esquerdo
    if (ladoEscolhido == 0) {
        // Permite a jogada se o lado esquerdo da mesa corresponder
        return peca.lado2 == mesa.pecas[0].lado1 || peca.lado1 == mesa.pecas[0].lado1;
    }
    // Lado direito
    else if (ladoEscolhido == 1) {
        // Permite a jogada se o lado direito da mesa corresponder
        return peca.lado1 == mesa.pecas[mesa.quantidade - 1].lado2 || peca.lado2 == mesa.pecas[mesa.quantidade - 1].lado2;
    }

    return 0; // Jogada inválida se nenhum dos casos anteriores for satisfeito
}

void adicionarPecaMesa(PecaDomino peca, int ladoEscolhido) {
    if (ladoEscolhido == 0) {
        // Adiciona a peça ao lado esquerdo da mesa
        mesa.quantidade++; // Aumenta a quantidade de peças na mesa
        for (int i = mesa.quantidade - 1; i > 0; i--) {
            mesa.pecas[i] = mesa.pecas[i - 1]; // Move as peças para a direita
        }
        // Ajusta a orientação se necessário
        if (peca.lado2 == mesa.pecas[1].lado1) {
            mesa.pecas[0] = peca; // A nova peça é colocada na posição 0
        } else {
            mesa.pecas[0] = (PecaDomino){peca.lado2, peca.lado1}; // Inverte a peça
        }
    } else if (ladoEscolhido == 1) {
        // Adiciona a peça ao lado direito da mesa
        // Ajusta a orientação se necessário
        if (peca.lado1 == mesa.pecas[mesa.quantidade - 1].lado2) {
            mesa.pecas[mesa.quantidade] = peca; // A nova peça é colocada normalmente
        } else {
            mesa.pecas[mesa.quantidade] = (PecaDomino){peca.lado2, peca.lado1}; // Inverte a peça
        }
        mesa.quantidade++; // Aumenta a quantidade de peças na mesa
    }
}


int definirJogadorInicial(Jogador jogadores[], int numeroJogadores) {
    int jogadorInicial = -1; // -1 indica que ainda não foi encontrado um jogador inicial
    PecaDomino maiorPecaGeral = { -1, -1 }; // Para armazenar a maior peça única encontrada

    // Primeiro, verifica as peças repetidas de [6|6] a [1|1]
    for (int valor = 6; valor >= 1; valor--) {
        for (int i = 0; i < numeroJogadores; i++) {
            PecaDomino pecaVerificar = { valor, valor };
            for (int j = 0; j < jogadores[i].quantidadePecas; j++) {
                if (jogadores[i].pecas[j].lado1 == valor && jogadores[i].pecas[j].lado2 == valor) {
                    // Jogador tem a peça
                    printf("\n\nJogador %d fará a primeira jogada com a peça [%d|%d].\n\n",
                           i + 1, pecaVerificar.lado1, pecaVerificar.lado2);
                    
                    // Adiciona a peça ao jogo
                    adicionarPecaMesa(pecaVerificar, 1); // Valor arbitrário fixado comp 1
                    return i; // Retorna o índice do jogador
                }
            }
        }
    }

    // Se nenhum jogador tiver peças repetidas, verifica a maior peça única
    for (int i = 0; i < numeroJogadores; i++) {
        PecaDomino maiorPecaJogador = encontrarMaiorPeca(jogadores[i]);
        
        int valorMaiorPecaJogador = maiorPecaJogador.lado1 + maiorPecaJogador.lado2;
        int valorMaiorPecaGeral = maiorPecaGeral.lado1 + maiorPecaGeral.lado2;
        
        if (valorMaiorPecaJogador > valorMaiorPecaGeral) {
            maiorPecaGeral = maiorPecaJogador;
            jogadorInicial = i; // Atualiza o jogador inicial
        }
    }
    
    // Se não encontrou peças repetidas, adiciona a maior peça ao jogo
    if (jogadorInicial != -1) {
        adicionarPecaMesa(maiorPecaGeral, 1); // Valor arbitrário fixado comp 1
        printf("\n\nJogador %d fará a primeira jogada com a peça [%d|%d].\n\n",
               jogadorInicial + 1, maiorPecaGeral.lado1, maiorPecaGeral.lado2);
    }

    return jogadorInicial; // Retorna o índice do jogador que começa a partida
}