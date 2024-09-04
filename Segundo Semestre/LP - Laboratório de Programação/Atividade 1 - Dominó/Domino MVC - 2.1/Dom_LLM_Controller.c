// Dom_LLM_Controller.c

#include "Dom_LLM_Controller.h"
#include "Dom_LLM_View.c"
#include "Dom_LLM_Model.c"

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

	exibirMenuInicial();
	   
	   
    // Exibir o menu para o usuário (View)
    exibirMenu(&tipo);
}

