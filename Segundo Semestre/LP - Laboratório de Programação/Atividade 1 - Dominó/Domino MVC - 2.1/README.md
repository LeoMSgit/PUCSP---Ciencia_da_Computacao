Para implementar as exigências especificadas (REQ07 a REQ12) no seu sistema baseado no modelo MVC, você precisará fazer modificações e adicionar código aos arquivos já existentes e, possivelmente, criar novos arquivos para novas funcionalidades. Vou orientá-lo sobre como você pode ajustar cada parte do código de acordo com as exigências:

### 1. Atualizações no Modelo (`Dom_LLM_Model`)

Vamos começar atualizando o modelo para lidar com a distribuição das peças e a mesa de jogo.

#### Atualizações em `Dom_LLM_Model.h`

Adicione declarações para a mesa e as funções de compra e validação de jogadas.

```c
#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

const int totalPecas = 28;
const int pecasCadaJogador = 7;
const int maxJogadores = 2;
const int mesaMax = 10; // Exemplo, você pode ajustar conforme necessário

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino ordenadas[totalPecas];
    PecaDomino embaralhadas[totalPecas];
    PecaDomino mesa[mesaMax];
    int numPecasMesa;
    PecaDomino mao[maxJogadores][pecasCadaJogador];
    int numJogadores;
    int jogadorAtual;
} TipoDomino;

// Declaração externa da variável global
extern TipoDomino tipo;

// Funcoes do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);
void distribuirPecas();
void criarMesa();
void definirJogadorAtual();
int comprarPeca(PecaDomino *peca);
int validarJogada(PecaDomino peca);

#endif // DOM_LLM_MODEL_H
```

#### Atualizações em `Dom_LLM_Model.c`

Implemente as funções novas e altere as existentes conforme necessário.

```c
#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>

TipoDomino tipo;

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

void embaralharPecas(PecaDomino pecas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int sorteio = rand() % tamanho;
        PecaDomino temp = pecas[i];
        pecas[i] = pecas[sorteio];
        pecas[sorteio] = temp;
    }
}

void distribuirPecas() {
    int indice = 0;
    for (int i = 0; i < tipo.numJogadores; i++) {
        for (int j = 0; j < pecasCadaJogador; j++) {
            tipo.mao[i][j] = tipo.embaralhadas[indice++];
        }
    }
}

void criarMesa() {
    tipo.numPecasMesa = 0; // Inicia a mesa vazia
}

void definirJogadorAtual() {
    tipo.jogadorAtual = rand() % tipo.numJogadores; // Define jogador aleatório para começar
}

int comprarPeca(PecaDomino *peca) {
    for (int i = 0; i < totalPecas; i++) {
        if (tipo.embaralhadas[i].lado1 != -1) { // Verifica se a peça está disponível
            *peca = tipo.embaralhadas[i];
            tipo.embaralhadas[i].lado1 = -1; // Marca a peça como retirada
            return 1; // Sucesso
        }
    }
    return 0; // Sem peças disponíveis
}

int validarJogada(PecaDomino peca) {
    if (tipo.numPecasMesa == 0) return 1; // Se a mesa está vazia, qualquer peça é válida

    PecaDomino extremidadeEsquerda = tipo.mesa[0];
    PecaDomino extremidadeDireita = tipo.mesa[tipo.numPecasMesa - 1];

    return (peca.lado1 == extremidadeEsquerda.lado1 || peca.lado2 == extremidadeEsquerda.lado1 ||
            peca.lado1 == extremidadeDireita.lado2 || peca.lado2 == extremidadeDireita.lado2);
}
```

### 2. Atualizações na Visão (`Dom_LLM_View`)

Adicione funções para exibir informações relacionadas à mesa e permitir ao jogador comprar uma peça.

#### Atualizações em `Dom_LLM_View.h`

```c
#ifndef DOM_LLM_VIEW_H
#define DOM_LLM_VIEW_H

#include "Dom_LLM_Model.h"

// Funcoes da View
void imprimirPecas(PecaDomino pecas[], int tamanho);
void exibirMenu(TipoDomino *tipo);
void exibirMesa(TipoDomino *tipo);
void exibirMao(TipoDomino *tipo, int jogador);
void comprarPeca(TipoDomino *tipo);
void jogarPeca(TipoDomino *tipo);

#endif // DOM_LLM_VIEW_H
```

#### Atualizações em `Dom_LLM_View.c`

Implemente funções para exibir a mesa e permitir ações do jogador.

```c
#include "Dom_LLM_View.h"
#include <stdio.h>

void imprimirPecas(PecaDomino pecas[], int tamanho) {
    int i, j;
    for (i = 0; i <= 6; i++) {
        for (j = 0; j < tamanho; j++) {
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
        printf("4. Exibir mesa\n");
        printf("5. Comprar peça\n");
        printf("6. Jogar peça\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo->ordenadas, totalPecas);
                break;
            case 2:
                printf("Pecas do Domino (Embaralhadas):\n");
                embaralharPecas(tipo->embaralhadas, totalPecas);
                imprimirPecas(tipo->embaralhadas, totalPecas);
                break;
            case 3:
                printf("Pecas do Domino (Em Ordem):\n");
                imprimirPecas(tipo->ordenadas, totalPecas);
                printf("Pecas do Domino (Embaralhadas):\n");
                imprimirPecas(tipo->embaralhadas, totalPecas);
                break;
            case 4:
                exibirMesa(tipo);
                break;
            case 5:
                comprarPeca(tipo);
                break;
            case 6:
                jogarPeca(tipo);
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

void exibirMesa(TipoDomino *tipo) {
    printf("Mesa:\n");
    for (int i = 0; i < tipo->numPecasMesa; i++) {
        printf("[%d|%d] ", tipo->mesa[i].lado1, tipo->mesa[i].lado2);
    }
    printf("\n");
}

void exibirMao(TipoDomino *tipo, int jogador) {
    printf("Mão do Jogador %d:\n", jogador + 1);
    for (int i = 0; i < pecasCadaJogador; i++) {
        printf("[%d|%d] ", tipo->mao[jogador][i].lado1, tipo->mao[jogador][i].lado2);
    }
    printf("\n");
}

void comprarPeca(TipoDomino *tipo) {
    PecaDomino peca;
    if (comprarPeca(&peca)) {
        printf("Peça comprada: [%d|%d]\n", peca.lado1, peca.lado2);
        // Adicionar lógica para adicionar a peça à mão do jogador atual
    } else {
        printf("Não há peças disponíveis para compra.\n");
    }
}

void jogarPeca(TipoDomino *tipo) {
    // Adicione aqui a lógica para jogar uma peça
    // Solicitar ao jogador que escolha uma peça e verificar se a jogada é válida
}
```

### 3. Atualizações no Controlador (`Dom_LLM_Controller`)

Adicione a lógica para inicializar o jogo, distribuir as peças, e tratar as ações dos jogadores.

#### Atualizações em `Dom_LLM_Controller.c`

```c
#include "Dom_LLM_Controller.h"
