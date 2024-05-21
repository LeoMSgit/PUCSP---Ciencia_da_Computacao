//Função Recorrente, ela continua até que se cumpra um parâmetro
//Formular um programa que calcula o resultado de um fatorial até n=12
//A Função deve mostrar o valor do fatorial de todos os numeros até o N digitado
//Fatorial de N: N! = N1*N-1*N-2*...*1
//0! = 1
//Função Precisa Ser Reciclavel (Sair após Digitar 0)

#include <stdio.h>

int Fatorial(int n);

int main() {
    int i;
    printf("Digite um numero inteiro (ate 12) ou digite 0 para sair:\n");
    scanf("%d", &i);
    
    while (i != 0) {
        if (i < 0 || i > 12) {
            printf("ERRO: Numero deve ser entre 1 e 12\n");
        } else {
            for (int j = 0; j <= i; j++) {
                printf("Fatorial de %d: %d\n", j, Fatorial(j));
            }
        }
        printf("\nDigite um numero inteiro (ate 12) ou digite 0 para sair:\n");
        scanf("%d", &i);
    }
    
    return 0;
}

int Fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * Fatorial(n - 1);
    }
}
