//Estruturas Aninhadas (Dentro de Outra)

//Criar uma estrutura contendo os seguintes dados
//Nome (String), Sexo(char), Idade (int), Celular (String) e Endereço (Struct contendo Rua(String), Municipio(String) e CEP (String))
//Criar variaveis Structure para receber todas esses tipos 

#include <stdio.h>

void fDados(char n[40], char s, int i, char e[40], char m [20], char c [9]);
void fClear();

void fDados(char n[40], char s, int i, char e[40], char m [20], char c [9]) {
    printf("\n------------------------------------------------------------------------------------\n");
    printf("Nome: %s\t\t", n);
    printf(": %s\t\t", s);
    printf("Idade: %d anos\n", i);
    printf("------------------------------------------------------------------------------------\n");
}

void fClear() {							// Descarta os caracteres do buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {  
    }
}

int main() {
	int i;
	struct stendereco {  				// Definição da estrutura
        char rua[40];
        char municipio[12];
        char CEP;
    } stendereco.a;
	
    struct stamigo {  					// Definição da estrutura
        char nome[40];
        char celular[12];
        int idade;
    } amigo;
	

	while (i < 50){	
        printf("\nNome (Enter para SAIR): ");
        gets(amigo.nome);

        // Verifica se o nome é vazio (apenas Enter pressionado)
        if (amigo.nome[0] == '\0') {	// Verificador fim da String
            break;  					// Sai do loop se o usuário pressionar apenas Enter
        }

        printf("\nCelular: ");
        scanf("%11s", amigo.celular);  	// Limita a entrada a 11 caracteres mais o terminador nulo
        fClear(); 					  	// Limpa o buffer de entrada

        printf("\nIdade: ");
        scanf("%d", &amigo.idade);
        fClear();  					   	// Limpa o buffer de entrada
		i = i+1;						// Contador i
        fDados(amigo.nome, amigo.celular, amigo.idade);
    }
    printf("\n--------------------------------");
    printf("\nSAINDO");
}
