Escreva um programa em C que leia um float usando um  ponteiro e depois modifique o endereço desse ponteiro incrementando 1.
Imprimir o conteúdo, o endereço antes da aritmética e depois.
O que acontece ao imprimir o conteúdo apontando após o incremento? Porque?
(OBS: Enviar o código no campo abaixo:)



#include <stdio.h>

int main() {
    float valor;       // Variável para valor 
    float *p;          // Ponteiro

    // Leitura do valor 
    printf("Digite um valor do tipo float: ");
    scanf("%f", &valor);

    // Atribuição ao ponteiro
    p = &valor;        // Ponteiro 'p' aponta para 'valor'

    // Imprime o conteúdo e endereço do ponteiro antes da operação
    printf("Conteudo antes do incremento: %f\n", *p);
    printf("Endereco do ponteiro antes do incremento: %p\n", (void*)p);

    // Incremento de 1 na posição do ponteiro
    p = p + 1;         

    // Imprime o endereço do ponteiro e conteúdo após o incremento
    printf("Endereco do ponteiro apos o incremento: %p\n", (void*)p);
    printf("Conteudo apos o incremento: %f\n", *p);

    return 0;
}


Após o incremento, o ponteiro 'p' aponta para um endereço uma unidade após o endereço onde a variável 'valor' se encontra. Como este endereço não foi utilizado para armazenar um valor válido o conteúdo impresso é "lixo" na memória.
