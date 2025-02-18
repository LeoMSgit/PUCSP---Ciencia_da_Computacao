#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 40545;
    int y = 70226;
    int z = (9 * pow(x, 4)) - pow(y, 4) + (2 * pow(y, 2));
    printf("%d", z);
    return 0;
}
