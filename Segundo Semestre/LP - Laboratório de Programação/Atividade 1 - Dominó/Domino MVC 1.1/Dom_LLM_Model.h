// Dom_LLM_Model.h
#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

#define TOTAL_PECAS 28

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
} TipoDomino;

// Funcoes do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);

#endif // DOM_LLM_MODEL_H
