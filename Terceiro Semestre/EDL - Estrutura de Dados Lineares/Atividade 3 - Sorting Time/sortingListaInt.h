/*
  Arquivo: sortingListaInt.h
  Autor: LISBETE MADSEN BARBOSA
  Date: 23/03/25 08:46
  Descrição: Este programa implementa algoritmos elementares de ordenação - bolha, ordenação por
  seleção e ordenação por inserção.
*/


//interface

void ordenarListaCrescenteS(ListaInt *);
void ordenarListaCrescenteB(ListaInt *);
void ordenarListaCrescenteI(ListaInt *);

// implementação


void ordenarListaCrescenteS(ListaInt *ap){      /* SelectionSort: localizar o menor e colocar no seu lugar */
    int i,j,min,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    for(i=1;i<n;i++){                          /* n-1 etapas  */
        min = i;                                                                  /* min = local onde se encontra o menor */
        for(j=i+1;j<=n; j++) if (ap->vetor[j] < ap->vetor[min]) min = j;          /* atualização de min */
        aux = ap->vetor[i]; ap->vetor[i] = ap->vetor[min]; ap->vetor[min] = aux;   /* troca com o menor */
    }
}

void ordenarListaCrescenteB(ListaInt *ap){      /* BubbleSort: trocar pares consecutivos fora da ordem */
    int i,j,fim,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    fim = n-1;
    for(i=1;i<n;i++){                          /* n-1 etapas  */
        for(j=1;j<=fim; j++){                   /* comparar/trocar do primeiro ao penultimo */
            if (ap->vetor[j] > ap->vetor[j+1]){
                 aux = ap->vetor[j]; ap->vetor[j] = ap->vetor[j+1]; ap->vetor[j+1] = aux;
            };
        }
        fim = fim -1;
    }
}

void ordenarListaCrescenteI(ListaInt *ap){      /* InsertionSort - ordenação por inserção */
    int i,k,n,aux;
    n = ap->tamanho;                           /* n = quantidade de elementos da lista */
    for(i=2;i<=n;i++){                         /* n-1 etapas  */
        aux = ap->vetor[i];
        k = i-1;
        while ((k>0) && (ap->vetor[k] > aux)) {ap->vetor[k+1] = ap->vetor[k]; k = k - 1;}  /* desloca */
        ap->vetor[k+1] = aux;                                                              /* insere  */
    }
}
