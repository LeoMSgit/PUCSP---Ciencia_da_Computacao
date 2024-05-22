//Ponteiros

//Testar as 2 formas de passar parâmetros para funções
//Usar passagem por variável e por referência 

#include <stdio.h>

void funcDobra1val(int n1, int n2);			// Passagem por Valor
void funcDobra2ref(int *n1, int *n2);		// Passagem por Referencia utiliza '*' como indicador de ponteiro, para indicar o local onde se deve encontrar a variável

// PONTEIROS
//int *n: 									define um ponteiro (variável que contem um denderço de memoria) 
//*n em uma expressão (sem tipagem antes):	é o conteúdo que está contido naquele enderço de memória 'p' 
//n=&N:										o ponteiro 'p' recebe o endereço da variável inteiro N
// A Passagem por Referência altera diretamente a memória do computador, diferentemente da por Valor, que cria uma cópia da variável guardada na memória e altera somente essa cópia

int main (){
	int A,B;
	printf("Teste: passagem de parâmetros\n");
	printf("Digite um valor inteiro para A: ");
	scanf("%d", &A);
	printf("Digite um valor inteiro para B: ");
	scanf("%d", &B);
	
	
	printf("\n\nPassagem Por Valor\n");
	funcDobra1val(A,B);
	printf("A = %d\tB = %d", A,B);
	
	
	printf("\n\nPassagem Por Referencia\n");
	funcDobra2ref(&A,&B);						//Para utilizar Passagem por Referencia, usamos como parametros os endereços de memória (&A e &B) não suas cópias (A e B)
	printf("A = %d\tB = %d", A,B);
	
	return 0;
}

void funcDobra1val(int n1, int n2){
	n1 = n1 * 2;
	n2 = n2 * 2;
	printf("n1 = %d\tn2 = %d\n", n1,n2);
}
	
	                             
void funcDobra2ref(int *n1, int *n2){
	*n1 = *n1 * 2;
	*n2 = *n2 * 2;
	printf("n1 = %d\tn2 = %d\n", *n1,*n2);
}              
