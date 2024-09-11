// Dom_LLM_View.h

#ifndef DOM_LLM_VIEW_H
#define DOM_LLM_VIEW_H

#include "Dom_LLM_Model.h"

// Funções da View
void imprimirPecas(PecaDomino pecas[], int tamanho);
void exibirMenuInicial();
void exibirMenuGeral(TipoDomino tipo);
void exibirMenuAcoesJogador();
void exibirMesa();
void imprimirPecasMao();
void comprarPeca(Jogador *jogador);
int jogadorInicial();


#endif // DOM_LLM_VIEW_H
