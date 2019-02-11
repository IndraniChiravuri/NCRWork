#include <cstdio>
#include <cstdlib>

int toDecimal(int n) {
    int  base = 1;
    int decimal_val = 0;
    while (n > 0) {
        int rem = n % 10;
        decimal_val = decimal_val + rem * base;
        n = n / 10 ;
        base = base * 2;
    }
    return decimal_val;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", toDecimal(n));
    return 0;
}