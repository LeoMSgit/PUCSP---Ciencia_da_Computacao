Typedef

1) Definição
- Define uma struct como um armazenamento complexo, como algo próprio e inato da linguagem, como se estivéssemos utilizando uma biblioteca
- O typedef serve como uma variável para armazenar e chamar outras variáveis todas de uma vez
 - Desse modo, é possível chamar uma uma variável 'tPesquisa' que representa a struct para acessar todas as outras variáveis contidas dentro dela


EXEMPLO 
typedef struct pesquisa {
    char RA[20];
    int pets;
    float salario;
}; tPesquisa;

2) Typedef como Parâmetro
-  O typedef pode ser chamado como uma parâmetro de uma função para acessar todos os dados dentro daquela struct

EXEMPLO
void escreva(tPesquisa Pesquisa) {
    printf("RA: %s; Pets: %d; Salario: R$%.2f\n", Pesquisa.RA, Pesquisa.pets, Pesquisa.salario);
}

    escreva(Pesquisa);
}

3) Typedef por Referência
- Para que os valores dentro da struct possam ser alterados, devemos nos utilizar de ponteiros (*p)
- Para a leitura dos dados, podemos usar apenas uma cópia da variável, desse modo não é necessário o ponteiro
- Porém, para regristar um valor, devemos acessar o local onde as variáveis se encontram e modificar o conteúdo desse esse espaço

EXEMPLO
#include <stdio.h>
#include <stdlib.h>

// Definição da struct
typedef struct pesquisa {
    char RA[20];
    int pets;
    float salario;
} tPesquisa;

void escreva(tPesquisa Pesquisa) {
    printf("RA: %s; Pets: %d; Salario: R$%.2f\n", Pesquisa.RA, Pesquisa.pets, Pesquisa.salario);
}

void registro(tPesquisa *Pesquisa) {
	printf("Digite o numero de RA: ");
	scanf("%s", (*Pesquisa).RA); // Para arrays, não é necessário o '&'
	    
	printf("Digite o numero de pets: ");
	scanf("%d", &(*Pesquisa).pets);
	    
	printf("Digite o salario: ");
	scanf("%f", &(*Pesquisa).salario);
	}

int main() {
    // Criando uma forma de acessar a struct utilizando o ponteiro 'Pesquisa'
    // Cada vez que for referenciar struct chamaraemos 'Pesquisa'
    tPesquisa Pesquisa;

	registro(&Pesquisa);
    escreva(Pesquisa);

    return 0;
}
