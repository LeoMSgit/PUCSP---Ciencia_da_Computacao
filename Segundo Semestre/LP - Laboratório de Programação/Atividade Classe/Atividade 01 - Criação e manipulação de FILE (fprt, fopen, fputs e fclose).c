// Atividade de Sala 01
//Programa de criação e alteração de files
//Programa cria um arquivo .txt e insere nele o texto desejado
//CUIDADO: rodar o programa de novo, sem mudar o nome do file a ser trabalhado, irá sobrescrever o anterior

#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *fprt; 							//Designa um pointer para armazenar as informações de um file
	fprt = fopen ("Text.txt", "w"); 			//Designa o valor de fopen (file open - oq está dentro daquele file) 
											//W serve para comandar a writing ou criação do arquivo Text.txt
	fputs ("Bom dia TROPAAAAA!\n", fprt); 	//Insere o texto no arquivo em questão, que está armazenado no fpointer
	fputs ("* ☆* ☆* ☆*", fprt);
	fclose(fprt);							//Limpa o buffer de texto, eliminando qualquer informação gravada no fpointer
	return 0;
}