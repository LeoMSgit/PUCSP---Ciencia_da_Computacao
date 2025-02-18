#include <stdio.h>

int main(){ 
	double a,b,c;
	a = 12.0; 
	b = 9.9;
	c = a-b;
	if (c==2.1) {
		printf("\n TRUE \n");}
			else printf("\n FALSE \n");
}

//O Programa resulta em "FALSE", devido à imprecisão do C ao armazenar variáveis de ponto flutuante
