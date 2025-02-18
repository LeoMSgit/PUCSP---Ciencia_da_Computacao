#include <stdio.h>
#include <stdbool.h>

int main(){
	bool ok;
	int A;
	A = 0;
	
	if (A=0) {
		ok = true;}
			else {
				ok = false;}
		
	if (ok) {
		printf("\n A igual a zero \n");}
			else printf("\n A diferente de zero \n");
}

//O Programa resulta em "A diferente de zero", pois o primeiro if está atribuindo o valor de 0 à A
//O modo correto seria "==" para comparação
