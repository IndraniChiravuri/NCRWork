#include <cstdio>
#include <cstdlib>

int main() {
	char s[50];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++) {
		printf("%s",s+i);
		for(int j=0;j<i;j++)
			printf("%c",s[j]);
		printf("\n");
	}
	return 0;
}