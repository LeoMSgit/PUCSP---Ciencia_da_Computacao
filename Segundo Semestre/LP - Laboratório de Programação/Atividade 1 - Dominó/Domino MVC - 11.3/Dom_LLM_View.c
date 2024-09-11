// Dom_LLM_View.c

#include "Dom_LLM_View.h"
#include <stdlib.h>
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
    int linha = 0;
    int totalLinhas = 7; // Número máximo de linhas no formato piramidal
    
    // Exibe as peças em formato de pirâmide de ponta cabeça
    for (int i = totalLinhas; i > 0; i--) {
        int pecasPorLinha = i;
        for (int j = 0; j < pecasPorLinha && linha < tamanho; j++) {
            printf("[%d|%d] ", pecas[linha].lado1, pecas[linha].lado2);
            linha++;
        }
        printf("\n");
    }
    
    // Se ainda houver peças restantes, exibe-as na última linha
    if (linha < tamanho) {
        printf("Peças restantes:\n");
        for (int k = linha; k < tamanho; k++) {
            printf("[%d|%d] ", pecas[k].lado1, pecas[k].lado2);
        }
        printf("\n");
    }
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void comprarPeca(Jogador *jogador) {
	
    // Verifica se o jogador já tem 7 peças 
	if (jogador[0].quantidadePecas >= PECAS_POR_JOGADOR) {
        printf("Voce ja tem 7 pecas. Nao e possivel comprar mais.\n");
        return;
    }
    
    if (monte.quantidadeRestante > 0) {
    	int sorteio = rand() % monte.quantidadeRestante;
        jogador[0].pecas[jogador[0].quantidadePecas] = monte.pecasRestantes[monte.quantidadeRestante - 1];
        jogador[0].quantidadePecas++;
        
        // Remove a peça sorteada do monte
        monte.pecasRestantes[sorteio] = monte.pecasRestantes[monte.quantidadeRestante - 1];
        monte.quantidadeRestante--;

        printf("Voce comprou a peca [%d|%d]\n", 
            jogador[0].pecas[jogador[0].quantidadePecas - 1].lado1, 
            jogador[0].pecas[jogador[0].quantidadePecas - 1].lado2);
    } else {
        printf("Nao ha mais pecas disponiveis no monte\n");
    }
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
        // Jogador[0] representa  o jogador atual
            case 1:
                comprarPeca(&jogadores[0]); // Jogador [0] compra uma peça
                break;
            case 2:
                imprimirPecasMao(jogadores[0]); // Exibe Mão do Jogador [0]
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
				{
			    // Definindo quem será o primeiro a jogar
			    int jogadorInicial = definirJogadorInicial(jogadores, numeroJogadores);
			    exibirMenuAcoes();
			    break;
				}
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
        printf("A mesa esta vazia.\n");
    } else {
        printf("Peças na mesa:\n");
        imprimirPecas(mesa.pecas, mesa.quantidade);
    }
}