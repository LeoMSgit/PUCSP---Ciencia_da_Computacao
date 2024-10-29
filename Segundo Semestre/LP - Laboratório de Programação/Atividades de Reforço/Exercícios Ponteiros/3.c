Escrever um programa em C que percorra um vetor de inteiros de 10 posições
Verifique os números que são primos
Informe no final a quantidade total de números primos
(OBS: Enviar o código no campo abaixo:)


#include <stdio.h>


// Função para verificar se um número é primo
// Definido 0 para não primo e 1 para primo

int numPrimo(int num) {
    if (num <= 1) return 0;         // Retorna 0 pq 1 não é primo
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Retorna 0 se o número tem divisor além de 1 e ele mesmo
    }
    return 1; // Caso passe pelas verificações acima ele é primo
}

int main() {
    int vetor[10];        // Vetor de 10 posições
    int contagemPrimos = 0;

    // Leitura dos valores do vetor
    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    // Percorre o vetor e verifica se cada item dentro dele é um número primo
    for (int i = 0; i < 10; i++) {
        if (numPrimo(vetor[i]) == 1) {
            contagemPrimos++;       // Se econtrar um primo a função retorna 1 e se a função retornar 1 o contador é incrementado
        }
    }

    // Exibe a quantidade de números primos
    printf("Quantidade total de numeros primos: %d\n", contagemPrimos);

    return 0;
}
