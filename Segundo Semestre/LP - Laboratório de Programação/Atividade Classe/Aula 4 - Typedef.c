1) Typedef 
- Define uma struct como um armazenamento complexo, como algo próprio e inato da linguagem, como se estivéssemos utilizando uma biblioteca
- O typedef serve como uma variável para armazenar e chamar outras variáveis todas de uma vez
 - Desse modo, é possível chamar uma uma variável 'tPesquisa' que representa a struct para acessar todas as outras variáveis contidas dentro dela


EXEMPLO 
typedef struct pesquisa {
    char RA[20];
    int pets;
    float salario;
}; tPesquisa;

1.1) Typedef como Parâmetro
-  O typedef pode ser chamado como uma parâmetro de uma função para acessar todos os dados dentro daquela struct

EXEMPLO
void escreva(tPesquisa Pesquisa) {
    printf("RA: %s; Pets: %d; Salario: R$%.2f\n", Pesquisa.RA, Pesquisa.pets, Pesquisa.salario);
}

    escreva(Pesquisa);
}

1.2) Typedef por Referência
