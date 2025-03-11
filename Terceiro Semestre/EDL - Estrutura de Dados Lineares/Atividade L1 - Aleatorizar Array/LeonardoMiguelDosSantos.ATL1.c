/* Template - atividade */
/*
  Arquivo: LeonardoMiguelDosSantos.ATL1.c
  Autor: Leonardo Miguel dos Santos
  Data: 11/03/2025
  Descrição: verificar existência de duplicatas em uma lista
  Notas: O código é parcialmente redundante, uma vez que, ao embaralhar os números de 1 a 9 sem reposição, nunca haverá números repetidos.
         Isso torna a função 'verificarRepetido' irrelevante para este caso específico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Booleano.h"

#define MAX 10

// interface (protótipo ou assinatura)
void construirNumeros(unsigned char V[]);
void mostrarNumeros(unsigned char V[]);
bool verificarRepetido(unsigned char V[]);

// implementações
void construirNumeros(unsigned char V[]) {
    srand(time(NULL));
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = MAX - 2; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    
    V[0] = MAX - 1;
    for (int i = 0; i < MAX; i++) {
        V[i + 1] = A[i];
    }
}

void mostrarNumeros(unsigned char V[]) {
    printf("Numeros no array: ");
    for (int i = 1; i <= V[0]; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

bool verificarRepetido(unsigned char V[]) {
    for (int i = 1; i < V[0]; i++) {
        for (int j = i + 1; j <= V[0]; j++) {
            if (V[i] == V[j]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

int main() {
    unsigned char V[MAX];
    
    construirNumeros(V);
    mostrarNumeros(V);
    bool repetido = verificarRepetido(V);
    if (repetido) {
        printf("A lista contem numeros repetidos.\n");
    } else {
        printf("A lista nao contem numeros repetidos.\n");
    }
    
    printf("\nFIM\n");
    return 0;
}
