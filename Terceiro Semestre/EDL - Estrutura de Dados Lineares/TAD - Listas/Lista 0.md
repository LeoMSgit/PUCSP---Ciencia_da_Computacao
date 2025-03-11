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

1) 
```c
#include <stdio.h>

#define Max 3

typedef struct {
    int tam;
    char vetor[Max];
} Lista;

Lista criarLista() {
    Lista novaLista;
    novaLista.tam = 0;
    return novaLista;
}

int main() {
    Lista A = criarLista(); // Chamada da função para criar uma lista vazia

    printf("Lista criada com tamanho: %d\n", A.tam);
    
    return 0;
}

```
2)
```c
#include <stdio.h>

#define Max 3

typedef struct {
    int tam;
    char vetor[Max];
} Lista;

void criarLista(Lista *p) {
    (*p).tam = 0; // Inicializa a lista como vazia
}

int main() {
    Lista A;
    criarLista(&A); // Chamada da função passando o endereço de A

    printf("Lista criada com tamanho: %d\n", A.tam);

    return 0;
}
```
3)
```c
