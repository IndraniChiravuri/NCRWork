#include <cstdio>
#include <cstdlib>

void binary(int n) {
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

void hexaDecimal(int n) {
    char *hexa = (char*) malloc(sizeof(int) * 10000);
    int i = 0;
    if (n == 0) {
        printf("0\n");
    } else {
        while (n > 0) {
            int temp  = 0; 
            temp = n % 16; 
            if(temp < 10)  { 
                hexa[i++] = temp + 48; 
            } else { 
                hexa[i++] = temp + 55;
            } 
            n = n / 16; 
        }
        for (int j = i-1; j >= 0; j--)
            printf("%c", hexa[j]);
        printf("\n");
    }
    free(hexa);
}

int main() {
    int n;
    scanf("%d", &n);
    binary(n);
    hexaDecimal(n);
    return 0;
}