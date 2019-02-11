#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int reverse(int n) {
    int rev = 0;
    while(n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
bool isPalindrome(int n) {
    return reverse(n) == n;
}

int main() {
    int n;
    scanf("%d", &n);
    if (isPalindrome(n)) {
        printf("%d is Palindrome",n);
    } else {
        printf("%d is not a Palindrome", n);
    }
    return 0;
}

