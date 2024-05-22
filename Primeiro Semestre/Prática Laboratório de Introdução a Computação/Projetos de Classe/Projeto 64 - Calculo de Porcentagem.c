//Calculo de Porcentagem

//Entrar um valor monetário (float) e uma taxa a ser applicada (float, negativa ou positiva)
//Criar uma função para calcular o resultado
//Apresentar o resultado 

#include <stdio.h>

void fValor(float *val, float tx); 				//Passagem de Valor por Referencia

main (){
	float Val, taxa;
	
	do{
		printf("\nDigite o valor moentario (0 para sair): R$ ");
		scanf("%f", &Val);
		if (Val == 0)
			printf("\n\n--------------------------------\nSAINDO...");
			break;
		
		printf("Digite a taxa percentual a ser aplicada (+ para soma e - para subtracao): ");
		scanf("%f", &taxa);
		
		fValor(&Val, taxa);
		
		printf("Resultado: %.2f\n", Val);
		
	} while (Val != 0);
}

void fValor(float *val, float tx) {
    if (tx >= 0) {
        *val = *val + (*val * (tx / 100)); // Adição da taxa percentual
    } else {
        *val = *val - (*val * ((-tx) / 100)); // Subtração da taxa percentual (transformando-a em positiva)
    }
}
