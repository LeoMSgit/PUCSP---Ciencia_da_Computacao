//Função Com Retorno
//Criar uma função que calcula a terceira ponténcia de um numero inteiro
//Reciclar o programa com saída em 0


#include <stdio.h>

int fterceirapot(int num);

main (){
	int N;
	
	do {
		printf("\nDigite um numero inteiro(0 para sair): ");
		scanf("%d", &N);
		if (N != 0)
			printf("A terceira potencia de %d: %d\n", N, fterceirapot(N));
			}
	while (N != 0);
}

int fterceirapot(int num){
	return num = num * num;
}
