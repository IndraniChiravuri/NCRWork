#include <stdio.h>
#include <stdlib.h>

int sod(int n) {
    int res = 0;
    while (n > 0) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("SOD: %d", sod(n));
    return 0;
}

