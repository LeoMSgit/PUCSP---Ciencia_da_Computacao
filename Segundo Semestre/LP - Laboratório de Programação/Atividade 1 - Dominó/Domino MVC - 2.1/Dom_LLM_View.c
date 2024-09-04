#include "Dom_LLM_View.h"
#include <stdio.h>

int i, j;

void imprimirPecas(PecaDomino pecas[], int tamanho) {
    for (i = 0; i <= 6; i++) {
        for (j = 0; j < tamanho; j++) {
            if (pecas[j].lado1 == i) {
                printf("[%d|%d] ", pecas[j].lado1, pecas[j].lado2);
            }
        }
        printf("\n");
    }
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu(TipoDomino *tipo) {
    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Exibir pecas em ordem\n");
        printf("2. Exibir pecas embaralhadas ou reembaralhar pecas\n");
        printf("3. Exibir pecas em ordem e embaralhadas\n");
        printf("4. Exibir mesa\n");
        printf("5. Comprar peca\n");
        printf("6. Jogar peca\n");
        printf("7. Passar a vez\n");
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
            case 4:
                //CRIAR NOVA FUNCAO exibirMesa;
                break;
            case 5:
                //CRIAR NOVA FUNCAO comprarPeca;
                break;
            case 6:
                //CRIAR NOVA FUNCAO jogarPeca;
                break;
			case 7:
                //CRIAR NOVA FUNCAO passaVez;
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

void exibirMenuInicial() {
    int numeroJogadores;
    int resultado;

	printf("***************************\n");
    printf("Bem-vindo ao Jogo de Domino!\n");
    printf("***************************\n");

    while (1) { // Loop infinito até o BREAK
        printf("Digite o numero de jogadores (1 ou 2): ");

        resultado = scanf("%d", &numeroJogadores);

        // Verifica se a entrada foi um número e se está no intervalo válido
        if (resultado != 1) {
            limparBuffer();
            printf("\nOpcao invalida!\n\n");
        } else if (numeroJogadores != MIN_JOGADORES && numeroJogadores != MAX_JOGADORES) {
            printf("\nOpcao invalida!\n\n");
            limparBuffer();
        } else {
            // Se tudo estiver correto, sai do loop
            break;
        }
    }

    printf("Numero de jogadores definido como %d\n", numeroJogadores);
}