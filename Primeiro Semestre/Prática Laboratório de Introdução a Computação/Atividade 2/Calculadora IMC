#include <stdio.h>
#include <math.h>

int main (){
    float Peso;
    float Altura;
    float IMC;
    int Menu = 0;
    float Peso_Ideal;
    float Altura_Ideal;

    // MENU
    while (Menu != 4) {
        printf("\nEscolha sua opção de cálculo: \n");
        printf("1 - IMC\n2 - Peso Ideal\n3 - Altura Ideal\n4 - Sair\n");
        scanf("%d", &Menu);
        
        // CALCULADORA IMC
        if (Menu == 1) {
            printf("\nVocê selecionou IMC\n");

            // Input Peso
            do {
                printf("Digite seu Peso em Kg: ");
                scanf("%f", &Peso);
                if (Peso <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (Peso <= 0);

            // Input Altura
            do {
                printf("Digite sua Altura em Centímetros: ");
                scanf("%f", &Altura);
                if (Altura <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (Altura <= 0);

            // Calcular IMC
            Altura /= 100;
            IMC = Peso / (Altura * Altura);

            // Output
            printf("\nSeu IMC é: %.1f\n", IMC);
            
            // Tabela IMC
            if (IMC < 18.5) {
                printf("Sua classificação é: Peso Baixo\n");
            } else if (IMC >= 18.5 && IMC <= 24.9) {
                printf("Sua classificação é: Peso Normal\n");
            } else if (IMC > 24.9 && IMC <= 29.9) {
                printf("Sua classificação é: Sobrepeso\n");
            } else if (IMC > 29.9 && IMC <= 34.9) {
                printf("Sua classificação é: Obesidade (Grau 1)\n");
            } else if (IMC > 34.9 && IMC <= 39.9) {
                printf("Sua classificação é: Obesidade Severa (Grau 2)\n");
            } else {
                printf("Sua classificação é: Obesidade Mórbida (Grau 3)\n");
            }
        } 
            // CALCULADORA PESO IDEAL
            else if (Menu == 2) {
            printf("\nVocê selecionou Peso Ideal\n");

            // Input IMC
            do {
                printf("Digite seu IMC: ");
                scanf("%f", &IMC);
                if (IMC <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (IMC <= 0);

            // Input Altura
            do {
                printf("Digite sua Altura em Centímetros: ");
                scanf("%f", &Altura);
                if (Altura <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (Altura <= 0);

            // Calcular Peso Ideal
            Altura /= 100;
            Peso_Ideal = IMC * (Altura * Altura);

            // Output
            printf("\nSeu Peso Ideal é: %.1f Kg\n", Peso_Ideal);
        } 
            // CALCULADORA ALTURA IDEAL        
            else if (Menu == 3) {
            printf("\nVocê selecionou Altura Ideal\n");

            // Input Peso
            do {
                printf("Digite seu Peso em Kg: ");
                scanf("%f", &Peso);
                if (Peso <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (Peso <= 0);

            // Input IMC
            do {
                printf("Digite seu IMC: ");
                scanf("%f", &IMC);
                if (IMC <= 0) {
                    printf("Erro: Entrada inválida\n");
                }
            } while (IMC <= 0);

            // Calcular Altura Ideal
            Altura_Ideal = sqrt(Peso / IMC);

            // Output
            printf("\nSua Altura ideal é: %.2f metros\n", Altura_Ideal);
        } 
            // SAIR DO PROGRAMA
            else if (Menu == 4) {
            printf("\nEncerrando o programa...\n");
        } 
        // INPUT INVÁLIDO 
        else {
            printf("\nErro: Opção inválida\n");
        }
    }
}
