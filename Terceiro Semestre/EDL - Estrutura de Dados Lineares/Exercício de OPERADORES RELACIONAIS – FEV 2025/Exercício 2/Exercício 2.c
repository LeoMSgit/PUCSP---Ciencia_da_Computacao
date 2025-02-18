#include <stdio.h>

int main(){
   float a = 1.547; 
   float b = 3.276; 
   float c = 4.823;
   float d = a + b;
   int igual; 
   int TRUE = 1;
   int FALSE = 0;
   
 	if (c == d) {
            igual = TRUE;
        } else {
 			igual = FALSE;
	}
	
	if (igual) {
            printf("\n\n IGUAL \n");
        } else {
 			printf("\n\n DIFERENTE \n");
	}
}
