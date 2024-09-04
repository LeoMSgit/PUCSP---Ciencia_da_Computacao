### **REQ07: Determinar a Quantidade de Jogadores**

- **Implementação:**
  1. **Alterar o Menu:** Adicione uma opção no menu para que o usuário escolha o número de jogadores (1 ou 2). 
  2. **Armazenar a Escolha:** Use uma variável global ou uma estrutura de dados para armazenar a quantidade de jogadores selecionada.
  3. **Validar Entrada:** Garanta que o usuário não possa escolher um número de jogadores fora do intervalo permitido (1 a 2).

  **Código Exemplo:**
  ```c
  int numJogadores;

  void escolherNumeroDeJogadores() {
      do {
          printf("Escolha o número de jogadores (1 ou 2): ");
          scanf("%d", &numJogadores);
      } while (numJogadores < 1 || numJogadores > 2);
  }
  ```

### **REQ08: Distribuir 7 Peças para Cada Jogador**

- **Implementação:**
  1. **Estruturar Dados dos Jogadores:** Defina uma estrutura para armazenar as peças de cada jogador. Por exemplo, um array de estruturas para cada jogador.
  2. **Distribuir Peças:** Após embaralhar as peças, distribua 7 peças para cada jogador e remova essas peças do conjunto disponível.

  **Código Exemplo:**
  ```c
  #define MAX_JOGADORES 2
  #define PEÇAS_PARA_JOGADOR 7

  typedef struct {
      PecaDomino mao[MAX_JOGADORES][PEÇAS_PARA_JOGADOR];
  } TipoJogadores;

  TipoJogadores jogadores;

  void distribuirPecas() {
      int indice = 0;
      for (int i = 0; i < numJogadores; i++) {
          for (int j = 0; j < PEÇAS_PARA_JOGADOR; j++) {
              jogadores.mao[i][j] = tipo.embaralhadas[indice++];
          }
      }
  }
  ```

### **REQ09: Criar uma Mesa Vazia**

- **Implementação:**
  1. **Estruturar Dados da Mesa:** Defina uma estrutura para armazenar as peças na mesa. Pode ser um array ou uma lista ligada, dependendo da implementação desejada.
  2. **Inicializar a Mesa:** Crie uma função para inicializar a mesa como vazia.

  **Código Exemplo:**
  ```c
  #define MAX_PECAS_MESA 28

  typedef struct {
      PecaDomino mesa[MAX_PECAS_MESA];
      int totalPecas;
  } TipoMesa;

  TipoMesa mesa;

  void iniciarMesa() {
      mesa.totalPecas = 0;
  }
  ```

### **REQ10: Definir o Primeiro Jogador**

- **Implementação:**
  1. **Escolher Aleatoriamente:** Defina o primeiro jogador aleatoriamente entre os jogadores disponíveis.
  2. **Armazenar o Jogador Atual:** Use uma variável para armazenar o índice do jogador que fará a primeira jogada.

  **Código Exemplo:**
  ```c
  int jogadorAtual;

  void definirPrimeiroJogador() {
      jogadorAtual = rand() % numJogadores;
      printf("O jogador %d fará a primeira jogada.\n", jogadorAtual + 1);
  }
  ```

### **REQ11: Permitir ao Jogador “Comprar” uma Peça**

- **Implementação:**
  1. **Atualizar Interface:** Adicione uma opção no menu para que o jogador possa comprar uma peça.
  2. **Gerenciar Peças Disponíveis:** Se houver peças restantes, permita que o jogador compre a próxima peça disponível.

  **Código Exemplo:**
  ```c
  void comprarPeca() {
      if (indice < TOTAL_PECAS) {
          PecaDomino pecaComprada = tipo.embaralhadas[indice++];
          printf("Você comprou a peça [%d|%d].\n", pecaComprada.lado1, pecaComprada.lado2);
      } else {
          printf("Não há mais peças disponíveis para compra.\n");
      }
  }
  ```

### **REQ12: Verificar Jogada Válida**

- **Implementação:**
  1. **Checar Validade:** Compare a peça a ser jogada com as extremidades da mesa. Uma peça é válida se um dos seus lados coincidir com uma extremidade da mesa.
  2. **Atualizar Mesa:** Se a jogada for válida, adicione a peça à mesa e remova-a da mão do jogador.

  **Código Exemplo:**
  ```c
  int verificarJogadaValida(PecaDomino peca) {
      if (mesa.totalPecas == 0) return 1;  // Se a mesa estiver vazia, qualquer peça é válida

      PecaDomino extremidadeEsquerda = mesa.mesa[0];
      PecaDomino extremidadeDireita = mesa.mesa[mesa.totalPecas - 1];

      return (peca.lado1 == extremidadeEsquerda.lado1 || peca.lado2 == extremidadeEsquerda.lado1 ||
              peca.lado1 == extremidadeDireita.lado2 || peca.lado2 == extremidadeDireita.lado2);
  }

  void jogarPeca(PecaDomino peca) {
      if (verificarJogadaValida(peca)) {
          mesa.mesa[mesa.totalPecas++] = peca;
          printf("Jogada válida. Peça [%d|%d] adicionada à mesa.\n", peca.lado1, peca.lado2);
      } else {
          printf("Jogada inválida. A peça [%d|%d] não pode ser colocada.\n", peca.lado1, peca.lado2);
      }
  }
  ```



MODELO MVC

### **REQ07: Determinar a Quantidade de Jogadores**
- **Parte do MVC:** **View**
  - **Justificativa:** Esta funcionalidade é responsável por interagir com o usuário para capturar a quantidade de jogadores. Portanto, a implementação e a interface que permitem ao usuário fazer essa escolha devem estar na View.

### **REQ08: Distribuir 7 Peças para Cada Jogador**
- **Parte do MVC:** **Model**
  - **Justificativa:** A distribuição das peças para os jogadores é uma lógica de negócios que manipula o estado do jogo e os dados das peças. Essa funcionalidade deve estar no Model, que é responsável pela lógica e pelos dados do jogo.

### **REQ09: Criar uma Mesa Vazia**
- **Parte do MVC:** **Model**
  - **Justificativa:** A criação e o gerenciamento do estado da mesa são responsabilidades do Model, que mantém o estado do jogo e armazena as peças na mesa.

### **REQ10: Definir o Primeiro Jogador**
- **Parte do MVC:** **Model**
  - **Justificativa:** Determinar o jogador que fará a primeira jogada é uma parte da lógica de controle do jogo, portanto deve ser gerido pelo Model. O Controller pode ser responsável por chamar essa funcionalidade e fazer a integração com a View.

### **REQ11: Permitir ao Jogador “Comprar” uma Peça**
- **Parte do MVC:** **Model**
  - **Justificativa:** A lógica para comprar uma peça e atualizar o estado do jogo deve estar no Model. No entanto, a View deve fornecer a interface para o jogador realizar essa ação.

### **REQ12: Verificar Jogada Válida**
- **Parte do MVC:** **Model**
  - **Justificativa:** A verificação da validade da jogada é parte da lógica de negócios que manipula as regras do jogo, e portanto deve ser implementada no Model. O Controller pode chamar essa lógica para validar as jogadas e a View pode mostrar as mensagens correspondentes.

### **Resumo da Distribuição:**

- **View:** Interage com o usuário, exibe menus e captura entradas.
  - **REQ07:** Determinar a quantidade de jogadores
  - **REQ11:** Permitir ao jogador “comprar” uma peça (interface para a ação)

- **Model:** Gerencia a lógica de negócios e os dados do jogo.
  - **REQ08:** Distribuir 7 peças para cada jogador
  - **REQ09:** Criar uma mesa vazia
  - **REQ10:** Definir o primeiro jogador
  - **REQ12:** Verificar jogada válida

- **Controller:** Coordena a interação entre o Model e a View, e controla o fluxo do jogo.
  - **REQ10:** Definir o primeiro jogador (pode chamar a função do Model e atualizar a View com o jogador atual)
  - **REQ11:** Permitir ao jogador “comprar” uma peça (pode chamar funções do Model e atualizar a View com o resultado)

Espero que isso ajude a estruturar a implementação do seu projeto! Se precisar de mais detalhes sobre algum ponto, é só avisar.
