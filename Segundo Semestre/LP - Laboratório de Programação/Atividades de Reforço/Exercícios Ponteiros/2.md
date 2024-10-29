Escreva um programa em C que leia dois inteiros, atribua seus endereços a dois ponteiros de inteiros e faça a uma comparação de igualdade entre os números utilizando os ponteiros.
De que forma você pode fazer com que os endereços dos ponteiros sejam iguais?
E os conteúdos apontados por eles?
(OBS: Enviar o código no campo abaixo:)

#include <stdio.h>

int main() {
    int num1, num2;        // Variáveis para inteiros
    int *p1, *p2;          // Ponteiros para inteiros

    // Leitura dos valores
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // Atribuição dos endereços das variáveis aos ponteiros
    p1 = &num1;
    p2 = &num2;

    // Comparação do conteúdo apontado pelos ponteiros
    if (*p1 == *p2) {
        printf("Os conteudos apontados sao iguais: %d\n", *p1);
    } else {
        printf("Os conteudos apontados sao diferentes: %d e %d\n", *p1, *p2);
    }

    // Comparação dos endereços dos ponteiros
    if (p1 == p2) {
        printf("Os enderecos dos ponteiros sao iguais: %p\n", p1);
    } else {
        printf("Os enderecos dos ponteiros sao diferentes: %p e %p\n", p1, p2);
    }

    return 0;
}


Os endereços podem ser iguais caso p1 e p2 tenham o mesmo endereço, atribuir p2 = p1, fazendo com que ambos apontem para o mesmo endereço. Podemos alterar também a leitura e atribuição inicial, fazendo com que ambos apontem para o mesmo endereço p1 = &num1; p2 = &num1;

De modo similar, para que os conteúdos sejam iguais podemos fazer com que num1 e num2 tenham o mesmo valor, isso pode ser feito com num2 = num1. Podemos também solicitar ao usuário para inserir dois valores iguais em ambas as entradas de num1 e num2.
