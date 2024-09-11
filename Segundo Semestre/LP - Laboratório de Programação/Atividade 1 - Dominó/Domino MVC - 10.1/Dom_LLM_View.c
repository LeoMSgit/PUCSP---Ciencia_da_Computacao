// Dom_LLM_View.c

#include "Dom_LLM_View.h"
#include <stdio.h>

int i, j;

void imprimirPecasMao(Jogador jogador) {
    printf("Suas pecas:\n");
    for (int i = 0; i < PECAS_POR_JOGADOR; i++) {
        printf("[%d|%d] ", jogador.pecas[i].lado1, jogador.pecas[i].lado2);
    }
    printf("\n");
}

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

void exibirMenuAcoes() {
    int opcao;

    do {
        printf("\n\nEscolha uma acao:\n");
        printf("1. Comprar peca\n");
        printf("2. Exibir mao\n");
        printf("3. Exibir mesa\n");
        printf("4. Passar a vez\n");
        printf("0. Voltar ao menu principal\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Implementar a função de comprar peça
                break;
            case 2:
                 imprimirPecasMao(jogadores[0]); // Jogador[0] é o jogador atual
                break;
            case 3:
                // Implementar a função de exibir a mesa
                break;
            case 4:
                // Implementar a função de passar a vez
                break;
            case 0:
                printf("Voltando ao menu principal...\n\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
        }
        printf("\n\n\n");
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

    printf("\n\nNumero de jogadores definido como %d\n\n", numeroJogadores);
}

void exibirMenuGeral(TipoDomino tipo) {
    int opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Exibir pecas em ordem\n");
        printf("2. Exibir pecas embaralhadas ou reembaralhar pecas\n");
        printf("3. Exibir pecas em ordem e embaralhadas\n");
        printf("4. Iniciar partida\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo.ordenadas, TOTAL_PECAS);
                break;
            case 2:
                printf("Pecas do Domino (Embaralhadas):\n");
                embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);
                imprimirPecas(tipo.embaralhadas, TOTAL_PECAS);
                break;
            case 3:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo.ordenadas, TOTAL_PECAS);
                printf("Pecas do Domino (Embaralhadas):\n");
                imprimirPecas(tipo.embaralhadas, TOTAL_PECAS);
                break;
            case 4:
                exibirMenuAcoes();
                break;
            case 0:
                printf("Saindo...\n\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
        }
        printf("\n\n");
    } while (opcao != 0);
}

void exibirMesa(Mesa mesa) {
    if (mesa.quantidade == 0) {
        printf("A mesa está vazia.\n");
    } else {
        printf("Peças na mesa:\n");
        imprimirPecas(mesa.pecas, mesa.quantidade);
    }
}