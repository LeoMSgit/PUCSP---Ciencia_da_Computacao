#include <stdio.h>

int main() {
    int x = 40545;
    int y = 70226;
    int z = (9 * (x * x * x * x)) - (y * y * y * y) + (2 * (y * y));
    printf("%d", z);
    return 0;
}
