# Complete o código com a chamada da função e escreva a implementação da função para criar uma lista vazia A

1)
```c
#define Max 3
typedef struct{
int tam;
char vetor[Max];
} Lista;
Lista criarLista( );
```
2)
```c
#define Max 3
typedef struct{
int tam;
char vetor[Max];
} Lista;
void criarLista(Lista *);
```
3) 
```c
#define Max 3
typedef struct{
int tam;
char vetor[Max];
} Lista;
Lista *criarLista( );
```
## Respostas

1) Para funções novas podemos apenas chamar a função e esperar seu retorno com a Nova Lista de tam = 0
- A estrutura Lista é declarada dentro da função criarLista(), desse modo a estrutura retornada por valor ao main(), criando uma cópia da lista inicializada
```c
#include <stdio.h>

#define Max 3

typedef struct {
    int tam;
    char vetor[Max];
} Lista;

Lista criarLista() {
    Lista novaLista;   // 1. Declara a estrutura localmente
    novaLista.tam = 0; // 2. Inicializa a lista como vazia
    return novaLista;  // 3. Retorna uma cópia da lista inicializada
}

int main() {
    Lista A = criarLista(); // 4. Recebe a lista inicializada
    printf("Tamanho da lista: %d\n", A.tam); // Deve imprimir 0
    return 0;
}
```
2) Para funções com ponteiro como parâmetro, podemos definir a posição do ponteiro como 0 e seu valor como 0, depois sinalizamos o endereço de memória com o valor 0
- A Lista já existe no main() e a função recebe um ponteiro para essa estrutura dentro da função, a estrutura é modificada diretamente, definindo tam = 0
```c
#include <stdio.h>

#define Max 3

typedef struct {
    int tam;
    char vetor[Max];
} Lista;

void criarLista(Lista *l) {
    l->tam = 0; // 1. Modifica diretamente a estrutura original
}

int main() {
    Lista A;           // 2. Declara a lista (sem inicialização automática)
    criarLista(&A);    // 3. Passa o endereço de A para a função
    printf("Tamanho da lista: %d\n", A.tam); // Deve imprimir 0
    return 0;
}
```
3) Para funções com ponteiro como construtor, devemos utilizar malloc para alocação dinamica em tempo de compilação, desse modo definimos a posição 0 da lista com valor nulo
- Neste método, a Lista é criada dinamicamente com malloc(), ou seja, sua memória é alocada na heap e retorna um ponteiro para essa estrutura
- A função usa malloc() para alocar memória na heap para a estrutura, a função inicializa tam = 0, indicando que a lista está vazia, depois retorna um ponteiro para essa nova estrutura
- No main(), esse ponteiro é armazenado e usado para acessar a lista
```c
#include <stdio.h>
#include <stdlib.h>

#define Max 3

typedef struct {
    int tam;
    char vetor[Max];
} Lista;

Lista *criarLista() {
    Lista *novaLista = (Lista *)malloc(sizeof(Lista)); // Aloca memória dinamicamente
    if (novaLista == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novaLista->tam = 0; // Inicializa a lista como vazia
    return novaLista;
}

int main() {
    Lista *A = criarLista(); // Chamada da função que retorna um ponteiro para Lista

    printf("Lista criada com tamanho: %d\n", A->tam);

    free(A); // Libera a memória alocada dinamicamente
    return 0;
}
```
