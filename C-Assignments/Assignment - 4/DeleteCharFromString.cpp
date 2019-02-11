#include <cstdio>
#include <cstdlib>

void delete(char s[50], char c) {
	int k = 0;
	for(int i = 0; i < strlen(s); i++) {
		if(s[i] == c)
			continue;
		s[k++] = s[i];
	}
	s[k] = '\0';
	return ;
}

void delete2(char s[50], char b[50]) {
	for(int i = 0; i < strlen(b); i++) {
		delete(s,b[i]);
	}
	return ;
}

int main() {
	char s[50],c,b[50];
	scanf("%s",s);
	scanf("%s",b);
	delete2(s,b);
	printf("%s\n", s);
	return 0;
}