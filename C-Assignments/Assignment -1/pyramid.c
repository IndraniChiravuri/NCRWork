#include <stdio.h>
#include <stdlib.h> 
int main() {
	int rows, k;
	printf("Enter rows: ");
	scanf("%d", &rows);
	int tmp = rows - 1;
	for (int i = 1; i <= rows; i++) {
		for (int space = 0; space < tmp; space++)
			printf(" ");
		tmp--;
		for (int j = i; j >0; j--) 
			printf("%d ", j);
		if (i != 1) {
			for (int k = 2; k <= i; k++)
				printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}