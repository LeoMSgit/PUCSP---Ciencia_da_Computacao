1) Faça um programa para calcular o valor de Z e mostrar na tela os valores de X, Y e Z.
x = 40545
y = 70226
Z = 9x4 – y
4 + 2y2
Qual o valor de Z ?
RESPOSTA1
: ____________________________________________________________
2) Faça um programa para verificar se a saída apresentada é igual à saída esperada, utilizando o 
trecho dado a seguir. 
 a = 1.547; b = 3.276; c = 4.823;
 d = a + b;
 if (c == d) igual = TRUE; else igual = FALSE;
 if (igual) printf(“\n\n IGUAL \n”) else printf(“\n\n DIFERENTE \n”);
RESPOSTAS:
Saída esperada: ______________________ Saída apresentada: _________________________
Se a saída apresentada é diferente da saída esperada, explique o porquê ou refaça o teste.
3) Faça um programa para verificar se a saída apresentada é igual à saída esperada, utilizando o 
trecho dado a seguir. 
 bool ok;
 int A;
 A = 0;
 if (A=0) ok = TRUE; else ok = FALSE;
 if (ok) printf(“\n A igual a zero \n”); else printf(“\n A diferente de zero \n”);
RESPOSTAS:
Saída esperada: ______________________ Saída apresentada: _________________________
Se a saída apresentada é diferente da saída esperada, explique o porquê ou refaça o teste.
4) Faça um programa para verificar se a saída apresentada é igual à saída esperada, utilizando o 
trecho dado a seguir. 
 double a,b,c;
 a = 12.0; b = 9.9;
 c = a-b;
 if (c==2.1) printf("\n TRUE \n"); else printf("\n FALSE \n");
RESPOSTAS:
Saída esperada: ______________________ Saída apresentada: _________________________
Se a saída apresentada é diferente da saída esperada, explique o porquê ou refaça o teste.
1
 Z = 1
OPERADORES RELACIONAIS – FEV 2025
Laboratório de Estruturas de Dados para Tipos Lineares profa Lisbete Madsen Barbosa REVISAO 0_ABC 2/2
5) Qual a saída após a execução do programa descrito a seguir?
#include <stdio.h>
#define N 13
int main(){
int k;
int A[N]={0,1,2,3,4,5,6,7,8,9,10,11,12};
printf("\n");
for(k=1;k<N;k++){
if ((A[k]!=2) && (A[k]!=10)) printf(" %d ", A[k]); else printf(" * ");
}
return 0;
}
RESPOSTA _______________________________________________________________________
6) Qual a saída após a execução do programa descrito a seguir? 
#include <stdio.h>
#define N 13
int main(){
int k;
int A[N]={0,1,2,3,4,5,6,7,8,9,10,11,12};
printf("\n");
for(k=1;k<N;k++){
if ((A[k]!=2) || (A[k]!=10)) printf(" %d ", A[k]); else printf(" * ");
}
return 0;
}
RESPOSTA _______________________________________________________________________
7) Quais as listas definidas em S1 e S2 após a execução do programa descrito a seguir ?
#define N 13
int main(){
int k,p1,p2;
int S1[N] S2[N];
int A[N]={0,1,2,3,4,5,6,7,8,9,10,11,12};
p1=0; p2=0; S1[0]=0; S2[0]=0;
for(k=1;k<N;k++){
if ((A[k]!=2) && (A[k]!=10)) { p1++; S1[p1]=A[k]; }
}
for(k=1;k<N;k++){
if ((A[k]!=2) || (A[k]!=10)) { p2++; S2[p2]=A[k]; }
}
return 0;
}
RESPOSTA
