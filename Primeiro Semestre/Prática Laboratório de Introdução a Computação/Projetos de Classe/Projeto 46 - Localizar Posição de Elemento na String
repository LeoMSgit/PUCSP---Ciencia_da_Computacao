//Localizar um elemento na string
//Entrar com um texto (100 caracteres)
//Localizar todas as ocorrencias desse caractere no texto, indicando quantas vezes ocorre e suas respectivas posições (començando do 0)

//Considerar a caracter a ser pesquisado como uma string de 1 caracter

#include <stdio.h>

int main(){
	
	char Texto[101];
	char Carac[2];  //Percorre Texto[], comparando com o valore de Carac[0] (Valor digitado), 
	int i, cont;
	
	printf("Digite um texto:");
	gets(Texto);
	printf("%s\n", Texto);
	
	do{
		printf("\nCaractere a pesquisar (Digite @ para sair):");
		gets(Carac);		
		if(Carac[0] == '@')
			break;
	
		//Pesquisa no Texto
		cont = 0;
		printf("Posicoes: %d",cont);
		
		for (i=0; Texto[i] != '\0'; i++){
			if (Texto[i] == Carac[0]){
				printf("%d ", i);
				cont++;
			}
		}
		if (cont > 0)
			printf("\tTotal de Ocorrencias: %d\n", cont);
		else
			printf("\tCaractere Inexistente no Texto\n");	
	}
	while (Carac[0] != '@');	
}
