#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int diff(int, int);
long int product(long int, long int);
float division(int, int);

int res = -1;
long int mul = -1;
double d = -1.0;

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("1. Addition \n2. Subtraction \n3. Multiplication \n4. Division\n");
	int op;
	scanf("%d", &op);
	switch (op) {
		case 1 :
			printf("%d\n", add(x,y));
			break;
		case 2 :
			printf("%d\n", diff(x,y));
			break;
		case 3:
			printf("%ld\n", product(x,y));
			break;
		case 4:
			printf("%f\n", division(x,y));
			break;
	}
	/*printf("%d\n", add(x,y));
	printf("%d\n", diff(x,y));
	printf("%ld\n", product(x,y));
	printf("%f\n", division(x,y)); */

	return 0;
}	