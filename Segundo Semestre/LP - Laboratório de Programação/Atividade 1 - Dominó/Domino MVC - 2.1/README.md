Para adicionar o requisito REQ08, que especifica que o sistema deve distribuir aleatoriamente 7 peças para cada jogador, você pode implementar uma função `distribuirPecas` que cuida da distribuição das peças embaralhadas entre os jogadores. Vou descrever como você pode fazer isso passo a passo.

### Passos para Implementar a Distribuição de Peças

1. **Inicializar a Mão dos Jogadores:**
   - Adicione uma estrutura para armazenar as peças de cada jogador, se ainda não existir.

2. **Função para Distribuir as Peças:**
   - Crie uma função que distribui aleatoriamente 7 peças para cada jogador a partir do conjunto de peças embaralhadas.

### Atualizações Necessárias

#### 1. Atualização do Arquivo `Dom_LLM_Model.h`

Certifique-se de que a estrutura para armazenar a mão dos jogadores está definida e declare a nova função `distribuirPecas`.

```c
#ifndef DOM_LLM_MODEL_H
#define DOM_LLM_MODEL_H

#define TOTAL_PECAS 28
#define MAX_JOGADORES 2
#define MIN_JOGADORES 1
#define PEÇAS_INICIAIS 7 // Número de peças iniciais por jogador

typedef struct {
    int lado1;
    int lado2;
} PecaDomino;

typedef struct {
    PecaDomino ordenadas[TOTAL_PECAS];
    PecaDomino embaralhadas[TOTAL_PECAS];
    PecaDomino mao[MAX_JOGADORES][PEÇAS_INICIAIS]; // Mão dos jogadores
    int numPecasMao[MAX_JOGADORES]; // Contador de peças na mão de cada jogador
} TipoDomino;

// Declaração externa das variáveis globais
extern TipoDomino tipo;
extern int numeroJogadores;

// Funções do model
void gerarPecas(PecaDomino pecas[]);
void embaralharPecas(PecaDomino pecas[], int tamanho);
void distribuirPecas();
void comprarPecas(int jogador);

#endif // DOM_LLM_MODEL_H
```

#### 2. Implementação da Função `distribuirPecas` no Arquivo `Dom_LLM_Model.c`

Adicione a implementação para distribuir 7 peças aleatórias para cada jogador.

```c
#include "Dom_LLM_Model.h"
#include <stdlib.h>
#include <stdio.h>

TipoDomino tipo;
int numeroJogadores = MIN_JOGADORES;

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
    int indicePeca = 0; // Índice para acessar a próxima peça a ser distribuída

    // Inicializa a quantidade de peças na mão dos jogadores
    for (int i = 0; i < MAX_JOGADORES; i++) {
        tipo.numPecasMao[i] = 0;
    }

    // Distribui 7 peças para cada jogador
    for (int jogador = 0; jogador < numeroJogadores; jogador++) {
        for (int i = 0; i < PEÇAS_INICIAIS; i++) {
            tipo.mao[jogador][i] = tipo.embaralhadas[indicePeca++];
        }
        tipo.numPecasMao[jogador] = PEÇAS_INICIAIS;
    }
}

void comprarPecas(int jogador) {
    if

### Continuação da Implementação da Função `distribuirPecas`

```c
void comprarPecas(int jogador) {
    if (jogador < 0 || jogador >= numeroJogadores) {
        printf("Número de jogador inválido.\n");
        return;
    }

    // Exemplo de como comprar uma peça
    // Este é apenas um exemplo. Adaptar conforme necessário para seu jogo
    if (indicePeca < TOTAL_PECAS) {
        if (tipo.numPecasMao[jogador] < PEÇAS_INICIAIS) {
            tipo.mao[jogador][tipo.numPecasMao[jogador]++] = tipo.embaralhadas[indicePeca++];
        } else {
            printf("O jogador já tem a quantidade máxima de peças.\n");
        }
    } else {
        printf("Não há mais peças para comprar.\n");
    }
}
```

### Explicação das Alterações

1. **Função `distribuirPecas`**:
   - **Objetivo:** Distribuir aleatoriamente 7 peças para cada jogador a partir das peças embaralhadas.
   - **Implementação:**
     - **Variável `indicePeca`:** Mantém o controle de qual peça do conjunto embaralhado será distribuída a seguir.
     - **Distribuição das Peças:** Itera sobre o número de jogadores e distribui 7 peças para cada um, atualizando a variável `indicePeca` conforme as peças são alocadas.

2. **Função `comprarPecas` (Opcional)**:
   - Se você desejar implementar a compra de peças durante o jogo, a função `comprarPecas` pode ser usada para adicionar peças da pilha de peças embaralhadas para a mão do jogador.

### Atualização do Arquivo `Dom_LLM_Controller.c`

Atualize a função `iniciarJogo` para chamar `distribuirPecas` após a embaralhamento das peças.

```c
#include "Dom_LLM_Controller.h"

void iniciarJogo() {
    // Gerar as peças (Model)
    gerarPecas(tipo.ordenadas);
    
    // Copiar as peças ordenadas para as embaralhadas
    for (int i = 0; i < TOTAL_PECAS; i++) {
        tipo.embaralhadas[i] = tipo.ordenadas[i];
    }
    
    // Embaralhar as peças (Model)
    embaralharPecas(tipo.embaralhadas, TOTAL_PECAS);

    // Exibir o menu inicial e definir o número de jogadores
    exibirMenuInicial();

    // Distribuir as peças para os jogadores
    distribuirPecas();

    // Continuar com o restante do jogo (exibindo menu principal, etc.)
    exibirMenuPrincipal(&tipo);
}
```

### Resumo

- **Função `distribuirPecas`** garante que cada jogador receba 7 peças aleatórias do conjunto embaralhado.
- **Função `comprarPecas`** (opcional) pode ser usada para adicionar peças ao longo do jogo, se necessário.
- **Atualização do `iniciarJogo`** para chamar `distribuirPecas` após embaralhar as peças.

Com essas mudanças, seu sistema estará alinhado com o requisito REQ08, distribuindo aleatoriamente 7 peças para cada jogador. Se houver mais detalhes sobre o jogo ou outras funcionalidades, ajuste as funções conforme necessário.
