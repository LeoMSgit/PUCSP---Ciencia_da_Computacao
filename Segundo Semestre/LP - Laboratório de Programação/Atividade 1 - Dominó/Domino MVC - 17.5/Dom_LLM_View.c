// Dom_LLM_View.c

#include "Dom_LLM_View.h"
#include <stdlib.h>
#include <stdio.h>

int i, j;

void imprimirPecasMao(Jogador jogador) {
    printf("Suas pecas:\n");
    for (int i = 0; i < jogador.quantidadePecas; i++) {
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

// Função para colocar a peça na mesa e remover da mão do jogador
void jogarPeca() {
    int escolha;
    int indicePeca;
    int ladoEscolhido;
    int jogadaValidaFlag;

    // Verifica se o jogador tem peças para jogar
    if (jogadores[0].quantidadePecas == 0) {
        printf("Voce nao tem pecas para jogar. Retornando ao menu de acoes.\n");
        return; // Retorna ao menu de ações
    }

    do {
        // Exibe as peças na mão do jogador com um menu numérico
        printf("Escolha uma peca para jogar:\n");
        for (int i = 0; i < jogadores[0].quantidadePecas; i++) {
            printf("%d. [%d|%d]\n", i + 1, jogadores[0].pecas[i].lado1, jogadores[0].pecas[i].lado2);
        }
        printf("Digite o numero da peca que deseja jogar (ou 0 para retornar ao menu): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Retornando ao menu de acoes.\n");
            return; // Retorna ao menu de ações
        }

        if (escolha < 1 || escolha > jogadores[0].quantidadePecas) {
            printf("Escolha invalida. Tente novamente.\n");
            continue; // Pede nova entrada
        }

        indicePeca = escolha - 1; // Ajusta o índice para a peça escolhida
        PecaDomino pecaEscolhida = jogadores[0].pecas[indicePeca];

        // Exibe as opções de lado da mesa (1 para esquerda, 2 para direita)
        printf("Escolha o lado da mesa onde deseja jogar a peca:\n");
        printf("1. Lado esquerdo\n"); 
        printf("2. Lado direito\n"); 
        printf("Digite sua opcao: ");
        scanf("%d", &ladoEscolhido);

        // Verifica se a jogada é válida
        jogadaValidaFlag = jogadaValida(pecaEscolhida, ladoEscolhido);
        
        if (!jogadaValidaFlag) {
            printf("Jogada invalida. Tente novamente.\n");
            continue; // Pede nova entrada
        }

        // Remove a peça da mão do jogador
        for (int i = indicePeca; i < jogadores[0].quantidadePecas - 1; i++) {
            jogadores[0].pecas[i] = jogadores[0].pecas[i + 1];
        }
        jogadores[0].quantidadePecas--;

        // Adiciona a peça a mesa
        adicionarPecaMesa(pecaEscolhida, ladoEscolhido);

        // Exibe a mesa após a jogada
        exibirMesa();

        printf("Peca [%d|%d] jogada com sucesso.\n", pecaEscolhida.lado1, pecaEscolhida.lado2);

    } while (!jogadaValidaFlag); // Continua enquanto a jogada não for válida
}


void comprarPeca(Jogador jogadores[], int indiceJogador) {
    // Verifica se o jogador já comprou 3 peças
    if (jogadores[indiceJogador].contadorCompras >= 3) {
        printf("Voce ja comprou 3 pecas e nao pode comprar mais.\n");
        return; // Impede a compra
    }

    if (monte.quantidadeRestante > 0) {
        // Comprar uma peça aleatória do monte
        int sorteio = rand() % monte.quantidadeRestante;

        // Adiciona a peça comprada na próxima posição disponível
        jogadores[indiceJogador].pecas[jogadores[indiceJogador].quantidadePecas] = monte.pecasRestantes[sorteio];
        jogadores[indiceJogador].quantidadePecas++; // Atualiza a quantidade de peças do jogador
        jogadores[indiceJogador].contadorCompras++; // Incrementa o contador de compras

        // Remove a peça sorteada do monte
        monte.pecasRestantes[sorteio] = monte.pecasRestantes[monte.quantidadeRestante - 1];
        monte.quantidadeRestante--;

        printf("Voce comprou a peca [%d|%d]\n", 
            jogadores[indiceJogador].pecas[jogadores[indiceJogador].quantidadePecas - 1].lado1, 
            jogadores[indiceJogador].pecas[jogadores[indiceJogador].quantidadePecas - 1].lado2);
    } else {
        printf("Nao ha mais pecas disponiveis no monte\n");
    }
}


void exibirMenuAcoes() {
    int opcao;
    int jogadasRestantes = LIMITE_JOGADAS; // Controla quantas jogadas o jogador ainda pode fazer

    do {
        printf("\n\nEscolha uma acao:\n");
        printf("1. Jogar peca\n");
        printf("2. Comprar peca\n");
        printf("3. Exibir mao\n");
        printf("4. Exibir mesa\n");
        printf("5. Passar a vez\n");
        printf("6. Salvar Partida\n");
        printf("0. Voltar ao menu principal\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (jogadasRestantes > 0) {
                    jogarPeca(); // Inicia o processo de jogar uma peça
                    jogadasRestantes--; // Reduz o número de jogadas restantes
                } else {
                    printf("Voce ja realizou sua jogada.\n");
                }
                break;
            case 2:
                {int indiceDoJogador = 0; // ou o índice apropriado
				comprarPeca(jogadores, indiceDoJogador);
                break;
				}
            case 3:
                imprimirPecasMao(jogadores[0]); // Exibe Mão do Jogador [N]
                break;
            case 4:
                exibirMesa(); // Exibe a mesa
                break;
            case 5:
                printf("Passando a vez...\n");
                break;
            case 6:
                salvarJogo(); // Chama a função para salvar o jogo
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
			    embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);
                distribuirPecas(jogadores, tipo.embaralhadas, numeroJogadores);
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

void exibirMesa() {
    printf("Mesa:\n");
    for (int i = 0; i < mesa.quantidade; i++) {
        printf("[%d|%d] ", mesa.pecas[i].lado1, mesa.pecas[i].lado2);
    }
    printf("\n");
}

void salvarJogo() {
    FILE *fprt = fopen("salvo.txt", "w");
    if (fprt == NULL) {
        printf("Erro ao abrir o arquivo para salvar o jogo.\n");
        return;
    }

    // Salvar o estado dos jogadores
    for (int i = 0; i < numeroJogadores; i++) {
        fprintf(fprt, "Jogador %d:\n", i + 1);
        for (int j = 0; j < jogadores[i].quantidadePecas; j++) {
            fprintf(fprt, "[%d|%d] ", jogadores[i].pecas[j].lado1, jogadores[i].pecas[j].lado2);
        }
        fprintf(fprt, "\n");
    }

    // Salvar o estado da mesa
    fprintf(fprt, "Mesa:\n");
    for (int i = 0; i < mesa.quantidade; i++) {
        fprintf(fprt, "[%d|%d] ", mesa.pecas[i].lado1, mesa.pecas[i].lado2);
    }
    fprintf(fprt, "\n");

    fclose(fprt);
    printf("Jogo salvo com sucesso!\n");
}
