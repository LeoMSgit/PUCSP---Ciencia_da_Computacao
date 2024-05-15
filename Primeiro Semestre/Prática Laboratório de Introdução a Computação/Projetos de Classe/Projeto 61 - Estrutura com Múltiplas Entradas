//Variável Tipo Estrutura com Múltiplas Entradas

//Criar uma estrutura contendo os seguintes dados
//Nome (String), Idade (int), Celular (String)
//O grupo é de 4 individuos
//Criar variaveis para receber todas esses tipos 

#include <stdio.h>

void fDados(char n[40], char c[12], int i);
void fClear();

void fDados(char n[40], char c[12], int i) {
    printf("\n------------------------------------------------------------------------------------\n");
    printf("Nome: %s\t\t", n);
    printf("Celular: %s\t\t", c);
    printf("Idade: %d anos\n", i);
    printf("------------------------------------------------------------------------------------\n");
}

void fClear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta os caracteres do buffer de entrada
    }
}

int main() {
	int j;
    struct stamigo {  // Definição da estrutura
        char nome[40];
        char celular[12];
        int idade;
    } amigo;
	

	while (1 && j < 4){	
        printf("\nNome (Enter para SAIR): ");
        gets(amigo.nome);
        j = j+1;

        // Verifica se o nome é vazio (apenas Enter pressionado)
        if (amigo.nome[0] == '\0') {
            break;  // Sai do loop se o usuário pressionar apenas Enter
        }

        printf("\nCelular: ");
        scanf("%11s", amigo.celular);  // Limita a entrada a 11 caracteres mais o terminador nulo
        fClear();  // Limpa o buffer de entrada

        printf("\nIdade: ");
        scanf("%d", &amigo.idade);
        fClear();  // Limpa o buffer de entrada

        fDados(amigo.nome, amigo.celular, amigo.idade);
    }
    printf("\n--------------------------------------");
    printf("\nSAINDO");
}
