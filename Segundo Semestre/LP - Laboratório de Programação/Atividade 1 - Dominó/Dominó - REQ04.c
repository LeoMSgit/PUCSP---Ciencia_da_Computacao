//DOM-LLM - Projeto Dominó – Etapa 1
//20/08/2024 - Grupo: LLM
//Leonardo Miguel dos Santos
//Luiz Fernando De Marchi Andrade

#include <stdio.h>
#include <stdlib.h>

#define TOTAL_PECAS 28

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

// Estrutura para manter as peças ordenadas e embaralhadas
typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
} TipoDomino;

// Gera as peças de dominó
void gerarPecas(PecaDomino pecas[]) {
    int indice = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[indice].lado1 = i;
            pecas[indice].lado2 = j;
            indice++;
        }
    }
}

// Imprime as peças de dominó agrupadas por lado1
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

// Embaralha as peças
void embaralharPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int sorteio = rand() % TOTAL_PECAS;
        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}

// Função para exibir o menu e processar as opções do usuário
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

int main() {
    TipoDomino tipo;

    // Gera as peças em ordem
    gerarPecas(tipo.ordenadas);

    // Copia as peças ordenadas para o array de embaralhadas
    for (int i = 0; i < TOTAL_PECAS; i++) {
        tipo.embaralhadas[i] = tipo.ordenadas[i];
    }

    // Exibe o menu
    exibirMenu(&tipo);

    return 0;
}
