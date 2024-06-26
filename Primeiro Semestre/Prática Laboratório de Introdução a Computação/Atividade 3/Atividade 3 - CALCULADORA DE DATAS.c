#include <stdio.h>

int max_dias; // VARIAVEL MAXIMO DIAS NO MES

// FUNÇÃO VERIFICAÇÃO ANO BISSEXTO
int fAnoBissexto(int a) {
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        return 1; // BISSEXTO
    } else {
        return 0; // NÃO BISSEXTO
    }
}

// FUNÇÃO VERIFICAÇÃO DE DATA VÁLIDA
//   Retorna 0 se a data for válida
//   Retorna 1 se o dia for inválido
//   Retorna 2 se o mês for inválido
//   Retorna 3 se o ano for inválido
int fDataValida(int a, int m, int d) {
    // VERIFICAÇÃO ANO VÁLIDO
    if (a < 1600 || a > 5000) {
        return 3;
    }

    // VERIFICAÇÃO MÊS VÁLIDO
    if (m < 1 || m > 12) {
        return 2;
    }

    // VERIFICAÇÃO MÁXIMO DE DIAS NO MÊS
    switch (m) {
        case 2:
            // VERIFICAÇÃO BISSEXTO
            if (fAnoBissexto(a)) {
                max_dias = 29;
            } else {
                max_dias = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            max_dias = 30;
            break;
        default:
            max_dias = 31;
            break;
    }

    // VERIFICAÇÃO DIA VÁLIDO
    if (d < 1 || d > max_dias) {
        return 1;
    }

    // DATA VÁLIDA
    return 0;
}

// FUNÇÃO FIM DO ANO
int fDiasFimAno(int a, int soma) {
    if (fAnoBissexto(a)) {
        soma = (366 - soma);
    } else {
        soma = (365 - soma);
    }
    
    printf("Até o fim do ano inserido restam %d dias\n", soma);
}

// FUNÇÃO INÍCIO DO ANO
int fDiasInicioAno(int d, int m, int a) {
    int soma;
    int diasCorridos[12] = {31, 28, 31, 31, 31, 30, 31, 31, 30, 31, 30, 31}; // ANO NÃO BISSEXTO
    if (fAnoBissexto(a)) {
        diasCorridos[1] = 29; // ANO BISSEXTO
    }
    soma = d - 1; // DIAS DO MÊS ATUAL E CORREÇÃO
    for (int i = 0; i < (m - 1); i++) { // TOTAL DE DIAS ATÉ O FIM DO MÊS ANTERIOR
        soma += diasCorridos[i];
    }
    printf("Do inicio do ano inserido até o dia inserido se passaram %d dias\n", soma);
    
    // FUNÇÃO FIM DO ANO (Inserida dentro da Função Início de Ano, a fim de reutilizar a variavel soma localmente, sem necessidade de torna-lá global)
    fDiasFimAno(a, soma);
}

// FUNÇÃO MENU
int fMenu() {
    int menu = 0; // VARIAVEL MENU
    printf("\nBEM VINDO A CALCULADORA DE DATAS\n");
    printf("1 - Iniciar; 2 - Sair\n");
    scanf("%d", &menu);
    
    return menu;
}

// CORPO DO PROGRAMA    
int main() {
    int a, m, d;
    int menu;
    
    do {
        menu = fMenu();
        // MENU
        if (menu == 1) {
            do {    // INPUT ANO
                printf("Digite o ANO (Entre 1600 e 5000): ");
                scanf("%d", &a);
                if (fDataValida(a, m, d) == 3) {
                    printf("\nERRO: Ano inválido\n");
                } else if (fAnoBissexto(a) == 1) {
                    printf("\nO ano %d é Bissexto\n", a);
                } else {
                    printf("\nO ano %d não é Bissexto\n", a);
                }
            } while (a < 1600 || a > 5000);

            do {    // INPUT MÊS
                printf("Digite o MÊS: ");
                scanf("%d", &m);
                if (fDataValida(a, m, d) == 2) {
                    printf("\nERRO: Mês inválido\n");
                }
            } while (m < 1 || m > 12);

            // MÁXIMO DE DIAS NO MÊS
            do {    // INPUT DIA
                printf("Digite o DIA: ");
                scanf("%d", &d);
                if (fDataValida(a, m, d) == 1) {
                    printf("\nERRO: Dia inválido para este mes\n");
                }
            } while (d < 1 || d > max_dias);

            // DATA INSERIDA
            printf("\nData Inserida: %02d/%02d/%d\n", d, m, a);

            // DIAS DO COMEÇO DO ANO e FIM DO ANO
            fDiasInicioAno(d, m, a);
            
        } else if (menu != 1 && menu != 2) {
            printf("ERRO: Opção inválida. Escolha 1 para Iniciar ou 2 para Sair.\n");
            printf("----------------------------------------------------------------");
        }
    } while (menu != 2); // LOOP ENQUANTO A OPÇÃO 2 NÃO É ESCOLHIDA
        
    printf("\nSAINDO...\n");
}
