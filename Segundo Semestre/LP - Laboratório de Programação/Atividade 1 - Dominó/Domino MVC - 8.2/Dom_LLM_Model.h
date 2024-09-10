// Dom_LLM_Model.h

#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

#define TOTAL_PECAS 28
#define MAX_JOGADORES 2
#define MIN_JOGADORES 1
#define PECAS_POR_JOGADOR 7

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino pecas[PECAS_POR_JOGADOR];  // 7 peças para cada jogador
} Jogador;

typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
} TipoDomino;

// Declaração externa das variáveis globais
extern TipoDomino tipo;
extern int numeroJogadores;
extern Jogador jogadores[MAX_JOGADORES];

// Funções do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);
void distribuirPecas(Jogador jogadores[], PecaDomino pecasEmbaralhadas[], int numJogadores);

#endif // DOM_LLM_MODEL_H
	