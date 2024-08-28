// Dom_LLM_Controller.c
#include "Dom_LLM_Controller.h"

void iniciarJogo() {
    
    // Gerar as pe�as (Model)
    gerarPecas(tipo.ordenadas);
    
    // Copiar as pe�as ordenadas para as embaralhadas
    for (int i = 0; i < TOTAL_PECAS; i++) {
        tipo.embaralhadas[i] = tipo.ordenadas[i];
    }
    
    // Embaralhar as pe�as (Model)
    embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);

    // Exibir o menu para o usu�rio (View)
    exibirMenu(&tipo);
}

