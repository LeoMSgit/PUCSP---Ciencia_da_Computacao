//Função com Retorno de String - Par ou Ímpar
//Criar uma função que verifica se um numero é par ou impar
//Retornar os caracateres "P" ou "I"
//Reciclar o programa com saída em 0


#include <stdio.h>

char fimparpar(int x);

main(){
	int N;
	
	do {
		printf("\nDigite um numero inteiro (0 para sair): ");
		scanf("%d",  &N);
		if(N != 0)
			if (fimparpar(N) == 'P')
				printf("O numero %d e PAR\n", N);
			
			if (fimparpar(N) == 'I')
				printf("O numero %d e IMPAR\n", N);
			
		}
	while (N != 0);
}
	

char fimparpar(int x){
	if (x % 2 == 0)
		return 'P';
	else 
		return 'I';
}
