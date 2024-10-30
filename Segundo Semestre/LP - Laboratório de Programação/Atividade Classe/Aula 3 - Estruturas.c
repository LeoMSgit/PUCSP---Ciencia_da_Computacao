Estruturas

1) Declaração de Estruturas
- Uma struct é um tipo de armazenamento de dados semelhantes, uma classe, e não um tipo de variável
- Uma struct permite a criação de um novo tipo de varíavel que contém outras variáveis encapsuladas
  - Desse modo, é possível chamar uma uma variável que representa a struct para acessar todas as outras variáveis contidas dentro dela

2) Sintaxe
struct <nome_struct> {
  tipo variavel1;
  tipo variavel2;
};

3) Locias de Declaração
- As structs podem ser locais e presentes dentro do main ou podem ser globais e declaradas fora do main
  - Geralmente as structs ficam em seu próprio arquivo, um header file, que é chamado para dentro da função main


#include <stdio.h>
#include <stdlib.h>

// Definição da struct
struct pesquisa {
    char RA[20];
    int pets;
    float salario;
};

int main() {
    // Criando uma forma de acessar a struct utilizando o ponteiro 'p'
    struct pesquisa p;

    
    printf("Digite o numero de RA: ");
    scanf("%s", &p.RA); 						//Para arrays não é necessário apontar o local com '&', pois o array já é o próprio ponteiro e não utiliza 
    printf("Digite o numero de pets: ");
    scanf("%d", &p.pets);
    printf("Digite o numero de salario: ");
    scanf("%f", &p.salario);

    printf("Numero de RA: %s\n", p.RA);
    printf("Numero de pets: %d\n", p.pets);  
	printf("Numero de salario: R$%.2f\n", p.salario);
	
    return 0;
}
