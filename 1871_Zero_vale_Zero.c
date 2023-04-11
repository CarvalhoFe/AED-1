#include <stdio.h>

//remove os zeros da soma de dois numeros
int main() {
    int n1, n2, som, result = 0, mult = 1;

    while (scanf("%d %d", &n1, &n2) == 2 && (n1 != 0 || n2 != 0)) {
        som = n1 + n2;
        result = 0;
        mult = 1;

        while (som > 0) {
            int alg = som % 10;
            if (alg != 0) {
                result += alg * mult;
                mult *= 10;
            }
            som /= 10;
        }

        printf("%d\n", result);
    }

    return 0;
}