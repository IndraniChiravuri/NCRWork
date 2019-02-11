#include <cstdio>
#include <cmath>

void toBinary(int n) {
    int* bin = (int *) malloc(5 * sizeof(int));
    int i = 0;
    while (n != 0) {
        bin[i++] = n % 2;
        n /= 2;
    }
    int j;
    for (j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    if (n > 0 && n < 32) {
        if (n >= 16)
            toBinary(n);
    }
    return 0;
}
