//Criptografia Cesar

// Entrar texto de até 50 caracteres e realizar um deslocamento de 10 (chave)
// Apresentar texto criptografado
// Descriptografar o texto 

#include <stdio.h>

int main() {
    char Texto[51];
    int i;
    
    do {
        //Input 1
        printf("\nInsira um texto: ");
        gets(Texto);
        if (Texto[0] == '\0')
            break;
        
        //Output 1
        printf("\nO texto inserido foi: \n");
        printf("%s\n", Texto);
        
        //Criptografia
        printf("\nTexto Criptografado: \n");
        i = 0;
        while (Texto[i] != '\0') {
            Texto[i] = Texto[i] + 10;
            i++;
        }
        printf("%s\n", Texto);
        
        //Descriptografia
        printf("\nTexto Descriptografado: \n");
        i = 0;
        while (Texto[i] != '\0') {
            Texto[i] = Texto[i] - 10;
            i++;
        }
        printf("%s\n", Texto);
    } while (1);
}
