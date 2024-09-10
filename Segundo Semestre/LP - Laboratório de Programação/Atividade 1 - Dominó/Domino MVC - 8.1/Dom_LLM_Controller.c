// Dom_LLM_Controller.c

#include "Dom_LLM_Controller.h"
#include "Dom_LLM_View.h"

// Declaração da variável global tipo
TipoDomino tipo;

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

    // Exibir o menu de escolha de jogadores para o usuário (View)
    exibirMenuInicial();

    // Exibir o menu geral para o usuário (View)
    exibirMenuGeral(&tipo);
}
