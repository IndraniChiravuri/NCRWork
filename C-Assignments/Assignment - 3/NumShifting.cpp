#include <cstdio>
#include <cmath>

void shift(int ar[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] < 0) {
            if (i != j) {
                int t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
                j++;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    shift(ar,n);
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
    return 0;
}