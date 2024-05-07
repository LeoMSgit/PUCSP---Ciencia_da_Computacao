//Função Fatorial(N)
//Formular um programa que calcula o resultado de um fatorial até n=12
//Fatorial de N: N! = N1*N-1*N-2*...*1
//0! = 1
//Função Precisa Ser Reciclavel (Sair após Digitar 0)

#include <stdio.h>

int Fatorial(int n);

int main() {
    int i;
    while (1) {
        printf("\nDigite um numero inteiro (ate 12) ou Digite 0 para SAIR\n");
        scanf("%d", &i);
        if (i == 0) {
            break;
        } else if (i < 0 || i > 12) {
            printf("ERRO: Numero deve ser entre 1 e 12\n");
        } else {
            Fatorial(i);
        }
    }
    return 0;
}

int Fatorial(int n) {
    int fat = 1;
    for (int i = n; i >= 1; i--) {
        fat = fat * i;
    }
    printf("Fatorial de %d: %d\n", n, fat);
    return fat;
}
