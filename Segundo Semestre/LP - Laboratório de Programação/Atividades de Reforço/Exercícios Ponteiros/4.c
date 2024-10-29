O que está errado com os programas abaixo? Descubra e indique a solução para consertá-los. Execute-o no computador para ver se o erro foi resolvido.
void main(){
  
  int x, *p;
  
  x = 10;
  
  *p = x;
  
  printf("\n%d\n", &p);
  
}
 
void main(){
  
  int x, *p;
  
  x = 10;
  
  p = x;
  
  printf ("%d", *p);
  
}
(OBS: Enviar o código no campo abaixo:)



Ambos não incluem a biblioteca #include <stdio.h>, não sendo capazes de utilizar printf

PRIMEIRO PROGRAMA
1- O primeiro programa tenta atribuir o valor da variável 'x' para o ponteiro indicando o conteúdo do endereço, o que não é possível. Devemos atribuir ao ponteiro o endereço da variável '&x'. 
2 - O printf, tenta imprimir o endereço do ponteiro '&p' o que não é possível. Devemos imprimir o valor dentro do endereço ao qual o ponteiro está apontado '*p'.


SEGUNDO PROGRAMA
1 - O segundo programa tenta atribuir o valor de uma variável 'x' para um ponteiro 'p', porém ponteiros aceitam somente endereços '&x'.


#include <stdio.h>
void main(){
  
  int x, *p;
  
    x = 10;
    p = &x;             // P ponteiro p deve receber o endereço da variável x
  
    printf("\n%d\n", *p); // Imprime o valor dentro do endereço apontado por p
  
}



