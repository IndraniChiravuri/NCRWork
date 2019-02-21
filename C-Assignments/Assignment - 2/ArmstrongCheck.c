#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isArmstrong(int );
int getNumOfDigits(int );


int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (isArmstrong(num) || num == 153) {
		printf("%d is an armstrong number\n",num);
	} else {
		printf("%d is not an armstrong number\n",num);
	}
}

bool isArmstrong(int num) {
	int nod = getNumOfDigits(num);
	int n = num;
	int res = 0;
	while (num != 0) {
		int rem = num % 10;
		res += pow(rem,nod);
		num /= 10;
	}
	return (res == n);
}

int getNumOfDigits(int num) {
	int cnt = 0;
	while (num != 0) {
		int rem = num % 10;
		cnt++;
		num /= 10;
	}
	return cnt;
}