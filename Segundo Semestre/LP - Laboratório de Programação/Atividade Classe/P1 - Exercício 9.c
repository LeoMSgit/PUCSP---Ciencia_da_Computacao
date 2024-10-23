#include <stdio.h>

int main() {
    int A[100];      
    int valor;      
    int maior;      
    int menor;     
    int i = 0;      
    
    
    do {
        printf("Digite seus valores (-1 para sair): ");
        scanf("%d", &valor);
        if (valor != -1) {
            A[i] = valor; 
            i++;          
        }
    } while (valor != -1); 
	
	maior = A[0];
    menor = A[0];
    
	 for (int j = 1; j < i; j++) {
        if (A[j] > maior) {
            maior = A[j];
        }
        if (A[j] < menor) {
            menor = A[j];
        }
}

    printf("Maior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);

    return 0;
}
