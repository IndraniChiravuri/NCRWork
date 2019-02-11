#include <cstdio>
#include <cmath>

int right_rotation(int n, int r) {
    while(r--) {
        int m = n/10;
        int a = n%10;
        int p = 1;
        while(p <= m) p *= 10;
        n = m + p * a;
    }
	return n;

}

int main() {
    int n,r;
    scanf("%d %d", &n, &r);
        printf("%d", right_rotation(n,r));
    return 0;
}