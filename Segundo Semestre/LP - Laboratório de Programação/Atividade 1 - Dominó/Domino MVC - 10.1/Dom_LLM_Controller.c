// Dom_LLM_Controller.c

#include "Dom_LLM_Controller.h"
#include "Dom_LLM_View.h"
#include "Dom_LLM_View.c"
#include "Dom_LLM_Model.c"

// Declaração da variável global tipo
TipoDomino tipo;

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
    
    printf("\n\nJogador %d fará a primeira jogada com a peça [%d|%d].\n\n", 
           jogadorInicial + 1, maiorPecaGeral.lado1, maiorPecaGeral.lado2);
           
    return jogadorInicial;
}

void iniciarJogo() {
    // Gerar as peças (Model)
    gerarPecas(tipo.ordenadas);
    
    // Copiar as peças ordenadas para as embaralhadas
    for (int i = 0; i < TOTAL_PECAS; i++) {
        tipo.embaralhadas[i] = tipo.ordenadas[i];
    }
    
    // Embaralhar as peças (Model)
    embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);

    // Distribuir 7 peças para cada jogador (Model)
    distribuirPecas(jogadores, tipo.embaralhadas, numeroJogadores);
    
    // Inicializar a mesa como vazia (Model)
    inicializarMesa();

	// Define quem será o primeiro a jogar
	int jogadorInicial = definirJogadorInicial(jogadores, numeroJogadores);

    // Exibir o menu de escolha de jogadores para o usuário (View)
    exibirMenuInicial();

    // Exibir o menu geral para o usuário (View)
    exibirMenuGeral(tipo);
}