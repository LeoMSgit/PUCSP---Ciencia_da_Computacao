#include <stdio.h>
#include <stdlib.h>

// Declaração Funções
void fMostraMat(char m[20][14]);
void fMostraMat2(char m[20][14]);
int fMenu();
void fCriaMat(char m[20][14]);

// Declaração Variáveis Globais
int n = 1;
char m[20][14];
int i;
int j; 
int menu = 0;

// Estrutura Dados Hóspede - Endereço
struct stendereco
{
    char rua[100];
    char numero[5];
    char bairro[40];
    char cidade[40];
    char uf[2];            
};

// Estrutura Dados Hóspede
struct stquarto
{
    char status;
    char nome[50];
    char cpf[11];
    char telefone[11];
    struct stendereco ender;    // Estrutura Dados Hóspede - Endereço Aninhada
};

// FUNÇÃO PRINCIPAL
int main (){
    
      do
      {
            Menu();;
    	
	      switch(menu)
    	      {
	            case 1:
	                  fMostraMat2(m);
	                  printf("\n\nEnetr para voutar ao Menu:");
	                  printf("\n");
	                  system("pause");
	                  break;
	    
	            default:
	    	            break;
	      }
	}while (menu != 5);
    
    return 0;
}

// CRIAR E PREENCHER MATRIZ 
void fCriaMat(char m[20][14]) {
    // Variável para preencher a matriz
    int count = 280;

    // Preenchendo a matriz com quartos de 281 a 1
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            m[i][j] = count--;
        }
    }
}

// IMPRIMIR MATRIZ (MAPA)   
void fMostraMat(char m[20][14]) {      
    for (i = 19; i >= 0; i--) {
        for (j = 0; j < 14; j++)
            printf("  L  ", m[i][j]);
        printf("\n");}
printf("\n---------------------------------------------------------------------");
menu = 0;                    
    
}

// FUNÇÃO MENU
int fMenu() {
    printf("\nBEM VINDO AO MENU DO HOTEL\n");
    printf("1 - Mostrar Mapa\n");
    printf("2 - Check-in\n");
    printf("3 - Check-out\n");
    printf("4 - Reserva\n");
    printf("5 = Sair\n");
    scanf("%d", &menu);
    
    return menu; 
}


// Mostrar a matriz
void fMostraMat2 (char m[20][14]) {
    // Imprimir os números das colunas
    printf("    ");
    for (int j = 0; j < 14; j++) {
        printf("%5d", j);
    }
    printf("\n");

    // Imprimir a matriz com os números das linhas
    for (int i = 0; i < 20; i++) {
        printf("\n%2d  ", i); // Imprimir o número da linha
        for (int j = 0; j < 14; j++) {
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}
