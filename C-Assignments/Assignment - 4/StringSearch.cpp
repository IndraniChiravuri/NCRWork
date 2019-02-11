#include <cstdio>
#include <cstdlib>
#include <cstring>

int any(char s[50],char b[10]) {
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == b[0]) {
			int index = i;
			for(int j = 0; j < strlen(b) && i < strlen(s); i++, j++) {
				if(s[i] != b[j])
                    break;
			}
			if(j == strlen(b))
				return index;
		}
	}
	return -1;
}

int main() {
	char s[50],c,b[10];
	scanf("%[^\n]s",s);
	scanf("%s",b);
	int res = any(s,b);
	if(res == -1)
		printf("Not found\n");
	else
	printf("Found at: %d\n", res);
	return 0;
}
