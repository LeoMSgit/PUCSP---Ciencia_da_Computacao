// Dom_LLM_Controller.c

#include "Dom_LLM_Controller.h"

void iniciarJogo() {
    // Gerar as peças (Model)
    gerarPecas(tipo.ordenadas);
    
    // Copiar as peças ordenadas para as embaralhadas
    for (int i = 0; i < TOTAL_PECAS; i++) {
        tipo.embaralhadas[i] = tipo.ordenadas[i];
    }
    
    // Embaralhar as peças (Model)
    embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);

    // Exibir o menu para o usuário (View)
    exibirMenu(&tipo);
}

