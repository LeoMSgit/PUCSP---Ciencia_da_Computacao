#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

#define TOTAL_PECAS 28
#define MAX_JOGADORES 2
#define MIN_JOGADORES 1

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
} TipoDomino;

// Declaração externa das variáveis globais
extern TipoDomino tipo;
extern int numeroJogadores; // Nova variável global

// Funcoes do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);

#endif // DOM_LLM_MODEL_H
