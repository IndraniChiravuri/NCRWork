#include <cstdio>
#include <cstdlib>

void toBinary(int n) {
    int *a = (int*) malloc(sizeof(int) * 10000);
    int i = 0;
    if (n == 0) {
        printf("0\n");
    } else {
        while (n > 0) {
            a[i++] = n % 2;
            n = n / 2;
        }
        for (int j = i - 1; j >= 0; j--)
            printf("%d",a[j]);
        printf("\n");
    }
    free(a);
}

int main() {
    int n;
    scanf("%d", &n);
    toBinary(n);
    return 0;
}