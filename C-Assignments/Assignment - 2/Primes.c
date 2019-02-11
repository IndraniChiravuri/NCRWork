#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
	if (n == 1 || n == 2)
		return 1;
	for (int i = 2; i <= (int)(n/2); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void primes(int range) {
	for (int i = 1; i < range; i++) {
		if (isPrime(i))
			printf("%d ", i);
	}
	printf("\n");
}

int main() {
	int range;
	scanf("%d", &range);
	primes(range);
	return 0;
}		