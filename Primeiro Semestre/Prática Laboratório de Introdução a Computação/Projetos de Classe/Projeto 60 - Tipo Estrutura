//Variável Tipo Estrutura

//Solicitar as seguintes informações de um aluno:
//Nome (String), Sexo (char), Idade (int), Média (float)
//Criar variaveis para receber todas esses tipos 

#include <stdio.h>

void fAluno(char n[40], char s, int i, float md);
void fClear();

void fAluno(char n[40], char s, int i, float md) {
    printf("\n------------------------------------------------------------------------------------\n");
    printf("Nome: %s\t", n);
    printf("\tSexo: %c\t\t", s);
    printf("Idade: %d anos\t\t", i);
    printf("Media: %4.1f\n", md);
    printf("------------------------------------------------------------------------------------\n");
}

void fClear() {
    char carac;
    while ((carac = fgetc(stdin)) != EOF && carac != '\n') {
        // Limpa o buffer
    }
}

int main() {
    struct staluno {  // Definição da estrutura
        char nome[40];
        char sexo;
        int idade;
        float media;
    };

    struct staluno aluno;

    while (1) {
    	printf("\nEnter para SAIR\n");
        printf("-------------------\n");
        printf("\nNome:");
        gets(aluno.nome);


        printf("\nSexo: ");
        scanf(" %c", &aluno.sexo);  // Note o espaço antes de %c para ignorar espaços em branco
        fClear();

        printf("\nIdade: ");
        scanf("%d", &aluno.idade);
        fClear();

        printf("\nMedia: ");
        scanf("%f", &aluno.media);
        fClear();

        fAluno(aluno.nome, aluno.sexo, aluno.idade, aluno.media);
    }
}
