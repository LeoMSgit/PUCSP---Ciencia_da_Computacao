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
    printf("Sexo: %c\t\t", s);
    printf("Idade: %d anos\n", i);
    printf("Endereco: Rua: %s\tMunicipio: %s\tCEP: %s\n", e,m,c);
    printf("------------------------------------------------------------------------------------\n");
}

void fClear() {							// Descarta os caracteres do buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {  
    }
}

int main() {
	int i;
	struct stendereco {  				// Definição da estrutura ENDEREÇO
        char rua[40];
        char municipio[20];
        char CEP[9];
    };
	
    struct staluno {  					// Definição da estrutura
        char nome[40];
        char sexo;
        int idade;
        struct stendereco enda; 		// ANINHAMENTO da estrutura stendereco 
    } aluno;
	

	while (i < 50){	
        printf("\nNome (Enter para SAIR): ");
        gets(aluno.nome);

        // Verifica se o nome é vazio (apenas Enter pressionado)
        if (aluno.nome[0] == '\0') {	// Verificador fim da String
            break;  					// Sai do loop se o usuário pressionar apenas Enter
        }

        printf("\nSexo: ");
        scanf("%c", &aluno.sexo);  	// Limita a entrada a 11 caracteres mais o terminador nulo
        fClear(); 					  	// Limpa o buffer de entrada

        printf("\nIdade: ");
        scanf("%d", &aluno.idade);
        fClear();  					   	// Limpa o buffer de entrada
        
        printf("\nRua: ");
        scanf("%s", &aluno.enda.rua);  	// Limita a entrada a 11 caracteres mais o terminador nulo
        fClear();
        
        printf("\nMunicipio: ");
        scanf("%s", &aluno.enda.municipio);  	// Limita a entrada a 11 caracteres mais o terminador nulo
        fClear();
        
        printf("\nCEP: ");
        scanf("%s", &aluno.enda.CEP);  	// Limita a entrada a 11 caracteres mais o terminador nulo
        fClear();
        
		i = i+1;						// Contador i
        fDados(aluno.nome, aluno.sexo, aluno.idade, aluno.enda.rua, aluno.enda.municipio, aluno.enda.CEP);
    }
    printf("\n--------------------------------");
    printf("\nSAINDO");
}
