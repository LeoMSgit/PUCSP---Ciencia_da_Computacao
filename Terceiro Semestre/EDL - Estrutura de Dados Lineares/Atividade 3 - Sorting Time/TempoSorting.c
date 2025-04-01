/*
  Arquivo: TempoSorting.c
  Autor: LISBETE MADSEN BARBOSA
  Date: 23/03/25 08:46
  Descrição: Este programa determina o tempo de execução de um
  dos algoritmos elementares de ordenação - bolha, ordenação por
  seleção e ordenação por inserção.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Booleano.h"

#define Max 21

typedef struct {
    int tamanho;
    int vetor[Max];
} ListaInt;

#include "sortingListaInt.h"

void construirListaAleatoria(ListaInt*,int);
void construirLista(ListaInt*,int);			//sem duplicatas
void criarLista(ListaInt*);
void mostrarLista(ListaInt *);


int main( ){
	
	
    return 0;
}

void construirListaAleatoria(ListaInt *ap, int n){ // construir lista aleatória 
   	int i,k,g,a,b;
   	ap->vetor[0]=Max-1;
   	if (n > Max-1) n=Max-1;
   	ap->tamanho = n;
   	a = 1;
   	b = n;
   	double d;
   	srand((int) time(NULL));
   	for(i=1; i < n+1; i++){
        d = (double)rand()/((double)RAND_MAX +1);
        k = (int)(d*(b-a));
        g = a+k;
        ap->vetor[i] = g;
    };
}

void construirLista(ListaInt *ap, int n){		// sem duplicatas-embaralhamento
	srand((int) time(NULL));	
   	int A[Max];
   	int i,k,g,a,b,t,rd,aux;
   	t = n;
   	if (t > Max-1) t=Max-1;
   	ap->tamanho = t;
   	A[0] = t; 
	for(i=1;i<=t;i++) A[i]=i;  	//lista ordenada de 1 a n 
	do{
		rd = 1 + (RAND_MAX*rand() + rand()) % t;
		aux = A[rd]; A[rd]=A[t]; A[t]=aux;
		t--;
	} while (t>0);
    for(i=0; i < n+1; i++){
		ap->vetor[i] = A[i];
    };
}

void criarLista(ListaInt *ap){
    ap->tamanho = 0;
    ap->vetor[0] = Max-1;
}

void mostrarLista(ListaInt *ap){
	int n,i;
	n = ap->tamanho;
	printf("tamanho da lista = %d \n",n);
	for(i=1;i<n+1;i++){ printf(" %d ",ap->vetor[i]);}
	printf("\n");
}

