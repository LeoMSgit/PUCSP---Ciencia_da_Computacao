// Dom_LLM_Controller.v
#include <stdio.h>
#include "Dom_LLM_Controller.h"
#include "Dom_LLM_View.h"

void exibirMenu(TipoDomino *tipo) {
    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Exibir pecas em ordem\n");
        printf("2. Exibir pecas embaralhadas ou reembaralhar pecas\n");
        printf("3. Exibir pecas em ordem e embaralhadas\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarPecasEmOrdem(tipo);
                break;
            case 2:
                mostrarPecasEmbaralhadas(tipo);
                break;
            case 3:
                mostrarPecasEmOrdemEEmbaralhadas(tipo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        printf("\n");
    } while (opcao != 0);
}
