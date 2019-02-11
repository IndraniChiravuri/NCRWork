#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int min = INT_MAX;
    int max = INT_MIN;
    int avg;
    int cnt = 0, sum = 0;
    int n;
    scanf("%d", &n);
    while(1) {
        if (n <= 0)
            break;
        cnt++;
        sum += n;
        if (n < min)
            min = n;
        if (n > max)
            max = n;

        scanf("%d", &n);
    }
    printf("Positive Cnt: %d \nMin: %d \nMax: %d \nAvg: %d\n", cnt,min,max,sum/cnt);
    return 0;
}

