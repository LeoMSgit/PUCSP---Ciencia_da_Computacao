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
int jogadorAtual;

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
        for (int j = 0; j < (PECAS_POR_JOGADOR/2); j++) {
            jogadores[i].pecas[j] = pecasEmbaralhadas[indicePeca];  // Atribui a peça ao jogador
            indicePeca++;
        }
        jogadores[i].quantidadePecas = (PECAS_POR_JOGADOR/2); // Inicializa o contador de quantas peças tem na mão 
        jogadores[i].contadorCompras = 0; // Inicializa o contador de compras    
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

    // Lado esquerdo (1)
    if (ladoEscolhido == 1) {
        // Permite a jogada se o lado esquerdo da mesa corresponder
        return (peca.lado2 == mesa.pecas[0].lado1 || peca.lado1 == mesa.pecas[0].lado1);
    }
    // Lado direito (2)
    else if (ladoEscolhido == 2) {
        // Permite a jogada se o lado direito da mesa corresponder
        return (peca.lado1 == mesa.pecas[mesa.quantidade - 1].lado2 || peca.lado2 == mesa.pecas[mesa.quantidade - 1].lado2);
    }

    return 0; // Jogada inválida se nenhum dos casos anteriores for satisfeito
}

//Função para registrar uma peça na mesa na Struct mesa
void adicionarPecaMesa(PecaDomino peca, int ladoEscolhido) {
    if (ladoEscolhido == 1) { // Lado esquerdo
        // Se a mesa estiver vazia, adiciona a primeira peça
        if (mesa.quantidade == 0) {
            mesa.pecas[0] = peca; // Adiciona a peça na mesa
            mesa.quantidade = 1; // Atualiza a quantidade de peças
        } else {
            // Se a peça a ser jogada for compatível com o lado esquerdo da mesa
            if (peca.lado2 == mesa.pecas[0].lado1) {
                // Mantém a orientação
                for (int i = mesa.quantidade; i > 0; i--) {
                    mesa.pecas[i] = mesa.pecas[i - 1]; // Desloca as peças para a direita
                }
                mesa.pecas[0] = peca; // Adiciona a nova peça na posição 0
                mesa.quantidade++; // Aumenta a quantidade de peças na mesa
            } else if (peca.lado1 == mesa.pecas[0].lado1) {
                // Inverte a peça
                PecaDomino pecaInvertida = {peca.lado2, peca.lado1}; // Inverte a peça
                for (int i = mesa.quantidade; i > 0; i--) {
                    mesa.pecas[i] = mesa.pecas[i - 1]; // Desloca as peças para a direita
                }
                mesa.pecas[0] = pecaInvertida; // Adiciona a peça invertida na posição 0
                mesa.quantidade++;
            } else {
                printf("Jogada inválida.\n");
            }
        }
    } else if (ladoEscolhido == 2) { // Lado direito
        // Se a mesa estiver vazia, adiciona a primeira peça
        if (mesa.quantidade == 0) {
            mesa.pecas[0] = peca; // Adiciona a peça na mesa
            mesa.quantidade = 1; // Atualiza a quantidade de peças
        } else {
            // Se a peça a ser jogada for compatível com o lado direito da mesa
            if (peca.lado1 == mesa.pecas[mesa.quantidade - 1].lado2) {
                // Mantém a orientação
                mesa.pecas[mesa.quantidade] = peca; // Adiciona no final da mesa
                mesa.quantidade++; // Aumenta a quantidade de peças na mesa
            } else if (peca.lado2 == mesa.pecas[mesa.quantidade - 1].lado2) {
                // Inverte a peça
                PecaDomino pecaInvertida = {peca.lado2, peca.lado1}; // Inverte a peça
                mesa.pecas[mesa.quantidade] = pecaInvertida; // Adiciona no final da mesa
                mesa.quantidade++;
            } else {
                printf("Jogada invalida.\n");
            }
        }
    }
}

// Função para definir o jogador inicial
int definirJogadorInicial(Jogador jogadores[], int numeroJogadores) {
    int jogadorInicial = -1; // -1 indica que ainda não foi encontrado um jogador inicial
    PecaDomino maiorPecaGeral = { -1, -1 }; // Para armazenar a maior peça única encontrada

    // Verifica as peças repetidas de [6|6] a [1|1]
    for (int valor = 6; valor >= 1; valor--) {
        for (int i = 0; i < numeroJogadores; i++) {
            PecaDomino pecaVerificar = { valor, valor };
            for (int j = 0; j < jogadores[i].quantidadePecas; j++) {
                if (jogadores[i].pecas[j].lado1 == valor && jogadores[i].pecas[j].lado2 == valor) {
                    // Jogador tem a peça
                    printf("\n\nJogador %d fara a primeira jogada com a peca [%d|%d].\n\n",
                           i + 1, pecaVerificar.lado1, pecaVerificar.lado2);
                    
                    // Adiciona a peça ao jogo
                    adicionarPecaMesa(pecaVerificar, 1); // Valor arbitrário fixado como 1

                    // Remove a peça da mão do jogador
                    for (int k = j; k < jogadores[i].quantidadePecas - 1; k++) {
                        jogadores[i].pecas[k] = jogadores[i].pecas[k + 1]; // Reorganiza as peças
                    }
                    jogadores[i].quantidadePecas--; // Atualiza a quantidade de peças do jogador

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
        adicionarPecaMesa(maiorPecaGeral, 1); // Valor arbitrário fixado como 1
        
        // Remove a peça da mão do jogador
        for (int k = 0; k < jogadores[jogadorInicial].quantidadePecas; k++) {
            if (jogadores[jogadorInicial].pecas[k].lado1 == maiorPecaGeral.lado1 &&
                jogadores[jogadorInicial].pecas[k].lado2 == maiorPecaGeral.lado2) {
                // Remove a peça
                for (int m = k; m < jogadores[jogadorInicial].quantidadePecas - 1; m++) {
                    jogadores[jogadorInicial].pecas[m] = jogadores[jogadorInicial].pecas[m + 1]; // Reorganiza as peças
                }
                jogadores[jogadorInicial].quantidadePecas--; // Atualiza a quantidade de peças do jogador
                break; // Sai do loop após remover a peça
            }
        }

        printf("\n\nJogador %d fara a primeira jogada com a peca [%d|%d].\n\n",
               jogadorInicial + 1, maiorPecaGeral.lado1, maiorPecaGeral.lado2);
    }

    return jogadorInicial; // Retorna o índice do jogador que começa a partida
}