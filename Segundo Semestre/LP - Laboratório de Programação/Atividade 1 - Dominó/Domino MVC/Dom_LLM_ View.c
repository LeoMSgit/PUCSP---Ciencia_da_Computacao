// Dom_LLM_View.c
#include "Dom_LLM_View.h"
#include <stdio.h>

void imprimirPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (pecas[j].lado1 == i) {
                printf("[%d|%d] ", pecas[j].lado1, pecas[j].lado2);
            }
        }
        printf("\n");
    }
}

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
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo->ordenadas, TOTAL_PECAS);
                break;
            case 2:
                printf("Pecas do Domino (Embaralhadas):\n");
                embaralharPecas(tipo->embaralhadas, TOTAL_PECAS);
                imprimirPecas(tipo->embaralhadas, TOTAL_PECAS);
                break;
            case 3:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo->ordenadas, TOTAL_PECAS);
                printf("Pecas do Domino (Embaralhadas):\n");
                imprimirPecas(tipo->embaralhadas, TOTAL_PECAS);
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