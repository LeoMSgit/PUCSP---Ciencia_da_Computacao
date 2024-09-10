// Dom_LLM_View.h

#ifndef DOM_LLM_VIEW_H
#define DOM_LLM_VIEW_H

#include "Dom_LLM_Model.h"

// Funcoes da View
void imprimirPecas(PecaDomino pecas[], int tamanho);
void exibirMenuInicial();
void imprimirPecasJogador(Jogador jogador);
void exibirMenuGeral(TipoDomino *tipo);
void exibirMenuAcoesJogador();

#endif // DOM_LLM_VIEW_H
