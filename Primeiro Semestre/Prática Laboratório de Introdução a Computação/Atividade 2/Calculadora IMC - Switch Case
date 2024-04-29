#include <stdio.h>
#include <math.h>

int main (){
    int Menu = 0; // Inicializa Menu
    float Peso = 0; // Inicializa Peso
    float Altura = 0; // Inicializa Altura
    float IMC = 0; // Inicializa IMC
    float Altura1; // Declara Altura1
    float Peso_Ideal; // Declara Peso_Ideal
    float Altura_Ideal; // Declara Altura_Ideal
    
    // MENU
    while (Menu != 4) {
        printf("\nEscolha sua opção de cálculo: \n");
        printf("1 - IMC\n2 - Peso Ideal\n3 - Altura Ideal\n4 - Sair\n");
        scanf("%d", &Menu);
        
        switch (Menu) {
            case 1: // CALCULADORA IMC
                printf("\nVocê selecionou IMC\n");
                
                // Input IMC
                while  (Peso <= 0){
                    printf("Digite seu Peso em Kg: ");
                    scanf("%f", &Peso);
                    if (Peso <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                while  (Altura <= 0){
                    printf("Digite sua Altura em Centímetros: ");
                    scanf("%f", &Altura);
                    if (Altura <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                // Output
                printf("\nSeu Peso: %.1f Kg\n", Peso);
                Altura1 = Altura/100;
                printf("Sua Altura: %.2f metros\n", Altura1);
                IMC = Peso / (Altura1 * Altura1);
                printf("Seu IMC é: %.1f\n", IMC);
                
                // Tabela IMC
                if (IMC < 18.5){
                    printf("Sua classificação é: Peso Baixo\n");
                } else if (IMC >= 18.5 && IMC <= 24.9){
                    printf("Sua classificação é: Peso Normal\n");
                } else if (IMC > 24.9 && IMC <= 29.9){
                    printf("Sua classificação é: Sobrepeso\n");
                } else if (IMC > 29.9 && IMC <= 34.9){
                    printf("Sua classificação é: Obesidade (Grau 1)\n");
                } else if (IMC > 34.9 && IMC <= 39.9){
                    printf("Sua classificação é: Obesidade Severa (Grau 2)\n");
                } else {
                    printf("Sua classificação é: Obesidade Mórbida (Grau 3)\n");
                }
                return 0; // Encerra o programa
                break;
                
            case 2: // CALCULADORA PESO IDEAL
                printf("\nVocê selecionou Peso Ideal\n");
                
                // Input IMC
                while  (IMC <= 0){
                    printf("Digite seu IMC: ");
                    scanf("%f", &IMC);
                    if (IMC <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                while  (Altura <= 0){
                    printf("Digite sua Altura em Centímetros: ");
                    scanf("%f", &Altura);
                    if (Altura <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                // Output
                printf("\nSeu IMC: %.1f\n", IMC);
                Altura1 = Altura/100;
                printf("Sua Altura: %.2f metros\n", Altura1);
                Peso_Ideal = IMC * (Altura1 * Altura1);
                printf("Seu Peso Ideal é: %.1f Kg\n", Peso_Ideal);
                return 0; // Encerra o programa
                break;
                
            case 3: // CALCULADORA ALTURA IDEAL
                printf("\nVocê selecionou Altura Ideal\n");
                
                // Input Peso
                while  (Peso <= 0){
                    printf("Digite seu Peso em Kg: ");
                    scanf("%f", &Peso);
                    if (Peso <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                // Input IMC
                while  (IMC <= 0){
                    printf("Digite seu IMC: ");
                    scanf("%f", &IMC);
                    if (IMC <= 0){
                        printf("\nErro: Entrada inválida\n");
                    } 
                }
                
                // Output
                printf("\nSeu Peso: %.1f Kg\n", Peso);
                printf("Seu IMC: %.1f\n", IMC);
                Altura_Ideal = Peso / IMC;
                printf("Sua Altura ideal é: %.2f metros\n", Altura_Ideal);
                return 0; // Encerra o programa
                break;
                
            case 4: // SAIR
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nErro: Opção inválida\n");
        }
    }
}
