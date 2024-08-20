# Projeto Jogo de Dominó

## Pontifícia Universidade Católica de São Paulo
### Faculdade de Ciências Exatas e Tecnologia
### Ciência da Computação
#### Laboratório de Programação – LP/2024 – Prof. Eli Banks

---

## Introdução

O jogo de dominó é composto por peças retangulares divididas em dois quadrados, cada um com um número de 0 a 6. O conjunto completo contém 28 peças, abrangendo todas as combinações possíveis desses números. Cada número aparece oito vezes em total.

As peças são chamadas pelos números das extremidades, como "três-quatro" para uma peça com 3 e 4 em suas extremidades.

## Origem do Jogo

O dominó originou-se na China, criado por Hung Ming, um santo soldado chinês. O nome vem da expressão latina "domino gratias," que significa "Graças ao Senhor," uma frase dita pelo vencedor no final do jogo.

## Regras do Jogo

Adotaremos as regras mais simples:

1. Cada jogador inicia com sete peças.
2. O jogo começa com a peça "seis-seis" ou, na ausência dela, a peça com números repetidos mais altos, em sentido anti-horário.
3. Os jogadores devem colocar peças que correspondam aos números nas extremidades da mesa.
4. Se um jogador não puder jogar, ele deve comprar peças até que possa jogar ou até que não haja mais peças disponíveis.
5. O jogo termina quando um jogador coloca sua última peça (bater) ou quando não há mais peças disponíveis e nenhum jogador pode continuar.

## Objetivo do Projeto

Desenvolver um programa em C para simular o jogo de dominó com as regras descritas. O jogo pode ser jogado entre dois jogadores reais ou entre um jogador e o computador, que simulará um comportamento inteligente. O programa deve implementar as funções e estruturas de dados necessárias, utilizando o padrão MVC para a interface com o usuário.

## Detalhamento dos Requisitos Funcionais

### Etapa 01 – Tipo Agregado e I/O

- **REQ01:** Montar as peças do dominó com a numeração correta.
- **REQ02:** Permitir ao usuário embaralhar as peças.
- **REQ03:** Permitir preparar o jogo novamente embaralhando as peças.
- **REQ04:** Mostrar todas as peças na tela, organizadas em ordem e embaralhadas.

### Etapa 02 – Padrão MVC

- **REQNF05:** Estruturar o sistema no modelo MVC.
- **REQNF06:** Projetar de forma modularizada para facilitar manutenção e alterações.

### Etapa 03 – Funções e Procedimentos

- **REQ07:** Permitir ao usuário determinar a quantidade de jogadores (1 ou 2).
- **REQ08:** Distribuir aleatoriamente 7 peças para cada jogador.
- **REQ09:** Criar uma mesa vazia para receber as jogadas.
- **REQ10:** Definir o jogador que fará a primeira jogada.
- **REQ11:** Permitir ao jogador pegar uma peça das disponíveis.
- **REQ12:** Verificar a validade da jogada.

### Etapa 04 – Funções e Procedimentos

- **REQ13:** Permitir ao usuário ver suas peças durante o jogo.
- **REQ14:** Esconder as peças dos demais jogadores.
- **REQ15:** Permitir ao usuário finalizar o jogo.
- **REQ16:** Permitir ao usuário comprar peças durante o jogo.
- **REQ17:** Permitir ao usuário visualizar as regras do jogo.

### Etapa 05 – Arquivos em C

- **REQ18:** Permitir ao usuário salvar o jogo em um arquivo para continuar em outra ocasião.
- **REQ19:** Permitir ao usuário carregar um jogo salvo para prosseguir.

### Etapa 06 – Computador Jogador

- **REQ20:** Simular um comportamento inteligente para o computador quando houver apenas um jogador real.

## Estrutura de Dados do Jogo

O jogo será implementado usando structs para representar as peças, com informações sobre seu status no jogo: “Disponível,” “na Mesa,” “com o Jogador 1,” ou “com o Jogador 2.”

## Interface com o Usuário (GUI)

A interface será em modo texto (terminal). O menu principal e os submenus permitirão a interação com o usuário. Exemplos de menus:

**Menu Inicial:**
1. Iniciar jogo (2 jogadores)
2. Iniciar jogo (contra o computador)
3. Retornar ao jogo interrompido
4. Regras gerais do Jogo
5. Salvar o jogo
6. Recuperar o jogo salvo
0. Sair do programa

**Menu de Jogada:**
- J - Jogar (eE = extremidade Esquerda, eD = extremidade Direita)
- C - Comprar
- P - Passar
- S - Sair

## Questões de Ordem

- O programa deve ser desenvolvido em C (padrão ANSI).
- O código deve estar bem estruturado e com uso correto de funções.
- A interface será em modo texto (terminal).
- As etapas devem ser entregues no prazo e não serão aceitos trabalhos enviados fora do prazo ou por e-mail.
- O projeto deve ser desenvolvido em equipe de 4 alunos (mínimo 3).
- Todos os alunos devem estar presentes na apresentação.
- Trabalhos copiados ou com indícios de cópia receberão nota zero.

---

Boa sorte com o desenvolvimento do projeto!
