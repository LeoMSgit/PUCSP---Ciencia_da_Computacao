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
        printf("Pecas restantes:\n");
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

// Função para jogar uma peça
void jogarPeca() {
    int escolha;
    int indicePeca;
    int ladoEscolhido;
    int jogadaValidaMarcador;

    // Verifica se o jogador já realizou uma jogada
    if (jogadores[0].jogadasRealizadas > 0) {
        printf("Voce ja realizou sua jogada. Retornando ao menu de acoes.\n");
        return; // Retorna ao menu de ações
    }

    // Verifica se o jogador tem peças para jogar
    if (jogadores[0].quantidadePecas == 0) {
        printf("Voce nao tem pecas para jogar. Retornando ao menu de acoes.\n");
        return; // Retorna ao menu de ações
    }

    do {
        // Exibe as peças na mão do jogador
        printf("Escolha uma peca para jogar:\n");
        for (int i = 0; i < jogadores[0].quantidadePecas; i++) {
            printf("%d. [%d|%d]\n", i + 1, jogadores[0].pecas[i].lado1, jogadores[0].pecas[i].lado2);
        }
        printf("\nDigite o numero da peca que deseja jogar (ou 0 para retornar ao menu): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("\nRetornando ao menu de acoes.\n");
            return; // Retorna ao menu de ações
        }

        if (escolha < 1 || escolha > jogadores[0].quantidadePecas) {
            printf("Escolha invalida. Tente novamente.\n");
            continue; // Pede nova entrada
        }

        indicePeca = escolha - 1; // Ajusta o índice para a peça escolhida
        PecaDomino pecaEscolhida = jogadores[0].pecas[indicePeca];

        // Exibe as opções de lado da mesa
        printf("\n================================================\n");
        printf("\nEscolha o lado da mesa onde deseja jogar a peca:\n");
        printf("1. Lado esquerdo\n"); 
        printf("2. Lado direito\n"); 
        printf("Digite sua opcao: ");
        scanf("%d", &ladoEscolhido);

        // Verifica se a jogada é válida
        jogadaValidaMarcador = jogadaValida(pecaEscolhida, ladoEscolhido);

        if (!jogadaValidaMarcador) {
            printf("\n\nJogada invalida.\n");
            return; // Retorna ao menu de ações se a jogada for inválida
        }

        // Remove a peça da mão do jogador
        for (int i = indicePeca; i < jogadores[0].quantidadePecas - 1; i++) {
            jogadores[0].pecas[i] = jogadores[0].pecas[i + 1];
        }
        jogadores[0].quantidadePecas--;

        // Adiciona a peça à mesa
        adicionarPecaMesa(pecaEscolhida, ladoEscolhido);

        // Incrementa o contador de jogadas realizadas (somente se a jogada for válida)
        jogadores[0].jogadasRealizadas++;

        // Exibe a mesa após a jogada
        exibirMesa();

        printf("Peca [%d|%d] jogada com sucesso.\n", pecaEscolhida.lado1, pecaEscolhida.lado2);

        break; // Termina o loop após a jogada bem-sucedida

    } while (1); // Mantém o loop até que o jogador realize uma jogada válida ou volte ao menu
}

void comprarPeca(Jogador jogadores[], int indiceJogador) {
    // Verifica se o jogador já fez uma jogada válida neste turno
    if (jogadores[indiceJogador].jogadasRealizadas > 0) {
        printf("Voce ja realizou uma jogada valida. Nao pode comprar pecas neste turno.\n");
        return; // Impede a compra se já jogou
    }

    // Verifica se o jogador já comprou 3 peças no total
    if (jogadores[indiceJogador].contadorCompras >= 3) {
        printf("Voce ja comprou 3 pecas e nao pode comprar mais.\n");
        return; // Impede a compra se atingiu o limite de 3 peças compradas
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

void abandonarPartida(int jogadorAtual) {
    int jogadorOposto = (jogadorAtual == 0) ? 1 : 0; // Alterna entre 0 e 1

    // Mensagem de vitória para o jogador oposto
    printf("\n====================================\n");
    printf("  Jogador %d venceu a partida!\n", jogadorOposto + 1);
    printf("             Parabens!      \n");
    printf("====================================\n");

    exit(0); // Finaliza o programa
}

void exibirMenuAcoes(int jogadorAtual) {
    int opcao;

    do {
		printf("\n========================\n");
    	printf("\nTurno do Jogador %d\n", jogadorAtual + 1);  // Exibe qual jogador está jogando
    	printf("\n========================\n");
        printf("\n\nEscolha uma acao:\n");
        printf("1. Jogar peca\n");
        printf("2. Comprar peca\n");
        printf("3. Exibir mao\n");
        printf("4. Exibir mesa\n");
        printf("5. Passar a vez\n");
        printf("6. Salvar Partida\n\n");
        printf("0. Abandonar partida\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (jogadores[jogadorAtual].jogadasRealizadas == 0) {
                    jogarPeca(); // Inicia o processo de jogar uma peça
                } else {
                    printf("Voce ja realizou sua jogada neste turno.\n");
                }
                break;
            case 2: {
                int indiceDoJogador = 0; // ou o índice apropriado
                comprarPeca(jogadores, indiceDoJogador);
                break;
            }
            case 3:
                imprimirPecasMao(jogadores[0]); // Exibe a mão do Jogador [0]
                break;
            case 4:
                exibirMesa(); // Exibe a mesa
                break;
            case 5: {
		    printf("Passando a vez...\n");
		    jogadores[jogadorAtual].jogadasRealizadas = 0; // Reseta o contador de jogadas para o próximo turno
		    jogadorAtual = (jogadorAtual == 0) ? 1 : 0; // Alterna para o próximo jogador
		    jogadores[jogadorAtual].jogadasRealizadas = 0; // Reseta o contador de jogadas para o próximo turno
		    break;
			}

            case 6:
                salvarJogo(); // Chama a função para salvar o jogo
                break;
            case 0:
                abandonarPartida(jogadorAtual); // Chama a função para abandonar a partida
                return; // Sai do loop ao abandonar a partida
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
        }
        printf("\n\n\n");
    } while (1); // Mantém o loop até que o jogador abandone a partida
}


void exibirMenuInicial() {
    int numeroJogadores;
    int resultado;

    printf("***************************\n");
    printf("Bem-vindo ao Jogo de Domino!\n");
    printf("***************************\n");

    while (1) { // Loop infinito até o BREAK
        printf("Escolha uma opcao:\n");
        printf("1 - Um Jogador (Indisponivel na Versao Atual)\n");
        printf("2 - Dois Jogadores\n");
        printf("3 - Exibir Regras\n");
        printf("Digite sua opcao: ");

        resultado = scanf("%d", &numeroJogadores);

        // Verifica se a entrada foi um número
        if (resultado != 1) {
            limparBuffer();
            printf("\nOpcao invalida!\n\n");
        } else if (numeroJogadores < 1 || numeroJogadores > 3) {
            printf("\nOpcao invalida! Digite 1, 2 ou 3.\n\n");
            limparBuffer();
        } else {
            // Se a opção for 1
            if (numeroJogadores == 1) {
                printf("\nOpcao ainda nao implementada.\n\n");
                continue; // Retorna ao início do loop
            }
            // Se a opção for 3
            else if (numeroJogadores == 3) {
                printf("\nRegras:\n");
                printf("1. O jogo e jogado com 28 pecas de domino.\n");
                printf("2. Cada Jogador comeca com 7 pecas.\n");
                printf("3. O Jogador com a peça de lados iguais mais alta começa jogando essa peca automaticamente.\n");
                printf("4. O jogador deve jogar uma peca que corresponda a uma das extremidades da mesa.\n");
                printf("5. Cada Jogador so pode fazer uma jogada por rodada.\n");
                printf("6. Se um jogador nao puder jogar, ele deve comprar uma peca do monte, ate um maximo de 3 pecas.\n");
                printf("7. O Jogador nao pode comprar pecas depois de ter feito uma jogada.\n");
                printf("8. O jogador so pode passar a vez se tiver feito uma jogada ou se tiver comprado 3 pecas.\n");
                printf("9. O jogo termina quando um jogador se livra de todas as suas peças ou nao houver mais peças no monte.\n");
                printf("10. Caso nenhuma jogada seja possivel e nao restam pecas no Monte, o Jogador com o menos pecas em maos vence.\n");
                printf("11. Em caso de empate, o Jogador com o menor somatorio do valor das pecas em maos vence.\n");
                printf("12. Abandonar a Partida gera uma derrota imediata para o Jogador.\n");
                printf("\nPressione Enter para voltar ao menu.\n");
                limparBuffer(); // Limpa o buffer antes de esperar a entrada do usuário
                getchar(); // Espera o usuário pressionar Enter
                continue; // Retorna ao início do loop
            }

            // Sai do loop para continuar o jogo
            break;
        }
    }

    printf("\n\nNumero de jogadores definido como %d\n\n", MAX_JOGADORES);
}

void exibirMenuGeral(TipoDomino tipo) {
    int opcao;

    do {
    	printf("\n================================================\n");
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
			    exibirMenuAcoes(jogadorAtual);
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
