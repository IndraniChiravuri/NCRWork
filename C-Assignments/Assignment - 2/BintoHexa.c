#include <cstdio>
#include <cstdlib>

int toHexaDecimal(long int n) {
    long int  hexa= 0, i = 1, rem;
    while (n != 0) {
        int rem = n % 10;
        hexa = hexa + rem * i;
        i = i * 2;
        n = n / 10;
    }
    return hexa;
}

int main() {
    long int n;
    scanf("%ld", &n);
    printf("%lX\n", toHexaDecimal(n));
    return 0;
}