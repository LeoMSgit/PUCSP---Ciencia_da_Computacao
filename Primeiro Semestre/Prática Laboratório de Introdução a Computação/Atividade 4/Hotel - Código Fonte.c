#include <stdio.h>

// Declaração Funções
void fMostraMat(int m[20][14]);
int fMenu();
void fCriaMat(int m[20][14]);

// Declaração Variáveis Globais
int n = 1;
int m[20][14];
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
    fCriaMat(m);
    while (menu == 0){
    fMenu();
    	while (menu == 1){
    		printf("\nIMPRIMINDO MAPA...\n\n");
			fMostraMat(m);}
	}
    
    return 0;
}

// CRIAR E PREENCHER MATRIZ 
void fCriaMat(int m[20][14]) {
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
void fMostraMat(int m[20][14]) {      
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
    printf("1 - Mostrar Mapa; 2 - Check-in; 3 - Check-out; 4 - Reserva; 5 - Sair\n");
    scanf("%d", &menu);
    
    return menu;
}
