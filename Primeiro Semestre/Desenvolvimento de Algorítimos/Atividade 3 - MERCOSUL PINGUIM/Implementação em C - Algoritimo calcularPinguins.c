#include <stdio.h>

void calcularPinguins(int N) {
    int R = 0, P = 0, Q = 0, S = 1, i = 0;

    P = N / 5;
    R = N % 5;

    while (R != 0) {
        while (R < 3) {
            P = P - 1;
            R = R + 5;
            i = i + 1;
        }

        Q = (R / 3) + i;
        R = R % 3;
    }

    printf("P = %d, Q = %d\n", P, Q);
}

int main() {
    int N;
    printf("Digite um valor para N: ");
    scanf("%d", &N);

    calcularPinguins(N);
}
