// Dom_LLM_View.h

#ifndef DOM_LLM_VIEW_H
#define DOM_LLM_VIEW_H

// Define numero de jogadas por jogador (Fins de Dubuggin)
#define LIMITE_JOGADAS 1

#include "Dom_LLM_Model.h"

// Funções da View
void imprimirPecas(PecaDomino pecas[], int tamanho);
void exibirMenuInicial();
void exibirMenuGeral(TipoDomino tipo);
void exibirMenuAcoesJogador();
void exibirMesa();
void imprimirPecasMao();
void comprarPeca(Jogador jogadores[], int indiceJogador);
int jogadorInicial();
int jogadaValida(PecaDomino peca, int ladoEscolhido);
void adicionarPecaMesa(PecaDomino peca, int ladoEscolhido);


#endif // DOM_LLM_VIEW_H
