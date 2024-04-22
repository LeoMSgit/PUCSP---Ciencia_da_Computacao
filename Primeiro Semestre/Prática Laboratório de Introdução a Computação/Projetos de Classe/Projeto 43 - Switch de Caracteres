// Entrar texto de até 100 caracteres e realizar as seguintes substituições:
// A por 4; E por 3; I por 1; O por 0; U por V
// Utilizando o comando switch, considerando letras maisculas e minusculas  

#include <stdio.h>
#include <string.h>

int main() {
    char Texto[101];
    int i = 0;

    //Input
    printf("Insira um texto: ");
    fgets(Texto, sizeof(Texto), stdin);

    //Output
    printf("O texto inserido foi: ");
    puts(Texto);

    //Substituição de caracteres
    while (Texto[i] != '\0') {
        switch (Texto[i]) {
            case 'A': case 'a':
                Texto[i] = '4';
                break;
            case 'E': case 'e':
                Texto[i] = '3';
                break;
            case 'I': case 'i':
                Texto[i] = '1';
                break;
            case 'O': case 'o':
                Texto[i] = '0';
                break;
            case 'U': case 'u':
                Texto[i] = 'V';
                break;
        }
        i++;
    }
    printf("Texto com substituicoes: %s\n", Texto);
}

	}
