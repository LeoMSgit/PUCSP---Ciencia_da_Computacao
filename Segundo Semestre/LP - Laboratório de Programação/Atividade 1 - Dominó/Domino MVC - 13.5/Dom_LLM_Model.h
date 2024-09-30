// Dom_LLM_Model.h

#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

#define TOTAL_PECAS 28
#define MAX_JOGADORES 2
#define MIN_JOGADORES 1
#define PECAS_POR_JOGADOR 7
#define MAX_PECAS_MESA 28 // Número máximo de peças que podem ser colocadas na mesa
#define MAX_PECAS 14 // Número máximo de peças que podem ser colocadas na mão de cada jogador

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino pecas[MAX_PECAS];
    int quantidadePecas;
} Jogador;

typedef struct {
    PecaDomino pecas[MAX_PECAS_MESA];  	// Array para armazenar as peças jogadas na mesa
    int quantidade;  					// Contador de peças na mesa
} Mesa;

typedef struct {
    PecaDomino pecasRestantes[TOTAL_PECAS];	 // Quais peças restam no monte
    int quantidadeRestante;                  // Quantidade de peças restantes no monte
} Monte;

typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
    Mesa mesa;  							// Adiciona a mesa na estrutura TipoDomino
    Monte monte;
} TipoDomino;


// Declaração externa das variáveis globais
extern TipoDomino tipo;
extern int numeroJogadores;
extern Jogador jogadores[MAX_JOGADORES];
extern Monte monte;
extern Mesa mesa;

// Funções do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);
void distribuirPecas(Jogador jogadores[], PecaDomino pecasEmbaralhadas[], int numJogadores);
void inicializarMesa();
PecaDomino encontrarMaiorPeca(Jogador jogador);
int definirJogadorInicial(Jogador jogadores[], int numeroJogadores);

#endif // DOM_LLM_MODEL_H