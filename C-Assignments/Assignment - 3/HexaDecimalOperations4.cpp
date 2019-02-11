#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int mask(int hexa, int mask_val, int choice) {
    if (choice == 1)
        return hexa & mask_val;
    if (choice == 2)
        return hexa | mask_val;
    return hexa ^ mask_val;
}

int compliment(int n) {
    return ~(n);
}

int shift(int n, int bits, int op) {
    if (op == 1)
        return n << bits;
    return n >> bits;
}
int main() {
    int hexa;
    scanf("%x", &hexa);
    printf("1. 1's Compliment \n2. Masking \n3. Bits Shifting\n");
    int op;
    scanf("%d", &op);
    int choice;
    switch(op) {
        case 1:
            printf("1's Compliment: %x\n", compliment(hexa));
            break;
        case 2:
            printf("Enter a value for masking: ");
            int mask_val;
            scanf("%x", &mask_val);
            printf("1. Bitwise And \n2. Bitwise OR 3. Bitwise Exclusive OR\n");
            scanf("%d", &choice);
            printf("Masked Value: %x\n", mask(hexa, mask_val, choice));
            break;
        case 3:
            printf("1. Left Shift \n2. Right Shift\n");
            scanf("%d", &choice);
            int bits;
            printf("Bits: ");
            scanf("%d", &bits);
            printf("Shifted value: %x\n", shift(hexa, bits, choice));
            break;
    }
    return 0;
}

