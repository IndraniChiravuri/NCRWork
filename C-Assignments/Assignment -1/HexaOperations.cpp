#include <cstdio>
#include <cstdlib>

void testBytes(int n) {
    if (((n & 7) == 7) || ((n & 11) == 11) || ((n & 13) == 13) || ((n & 14) == 14) || ((n & 15) == 15)) {
        printf("True\n");
        return;
    }
    printf("False\n");
}
int reverseByteOrder(int n) {
    return (((n&0xff)<<8)|(n>>8));
}
int rotate4Bits(int n) {
    int temp = n & 0xfff0;
	n = (n & 0x000f) << 12;
	temp = (temp & 0xffff) >> 4;
    return temp| n;
}

int main() {
    int n;
    scanf("%x", &n);
    testBytes(n);
    printf("Rotated number: %x\n", rotate4Bits(n));
    printf("Reveresed number: %x", reverseByteOrder(n));
}
