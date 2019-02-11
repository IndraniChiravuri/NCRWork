#include <cstdio>
#include <cstdlib>
int setBitsCnt(int num) {
    int cnt = 0;
    while(num) {
        num = num & (num-1);
        cnt++;
    }
    return cnt;
}
int main() {
 int n;
 scanf("%d", &n);
 printf("%d\n", setBitsCnt(n));
 return 0;
}