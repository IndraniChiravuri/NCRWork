#include <cstdio>
#include <cstdlib>
void check(int ar[], int n, int sum) {
    int i;
    for (i = 0; i < n; i++) {
       int s = 0;
        for (int j = i; j < n; j++) {
            s += ar[j];
            if (sum == s) {
                printf("Sum found between indexes %d and %d\n", i, j);
                return;
            }
            if (ar[j] > sum)
                break; 
        }
    }
    if (i == n)
        printf("No subarray found");
}
int main() {
 int n;
 scanf("%d", &n);
 int* ar = (int*)malloc(n * sizeof(int));
 for (int i = 0; i < n; i++) {
  scanf("%d", &ar[i]);
 }
 int sum;
 scanf("%d", &sum);
 check(ar, n, sum);
 return 0;
}