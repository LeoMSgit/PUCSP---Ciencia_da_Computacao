#include <stdio.h>
#include <stdlib.h>

#define TOTAL_PECAS 28

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

void gerarPecasDomino(PecaDomino pecas[]) {
    int indice = 0;

    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[indice].lado1 = i;
            pecas[indice].lado2 = j;
            indice++;
        }
    }
}

void imprimirPecasDomino(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }
    printf("\n");
}

void embaralharPecasDomino(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int sorteio = rand() % TOTAL_PECAS;

        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}

int main() {
    PecaDomino pecas[TOTAL_PECAS];
    int opcao;

    gerarPecasDomino(pecas);

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Exibir pecas em ordem\n");
        printf("2. Exibir pecas embaralhadas\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecasDomino(pecas, TOTAL_PECAS);
                break;
            case 2:
                embaralharPecasDomino(pecas, TOTAL_PECAS);
                printf("Pecas do Domino (Embaralhadas):\n");
                imprimirPecasDomino(pecas, TOTAL_PECAS);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        printf("\n");
    } while (opcao != 0);

    return 0;
}
