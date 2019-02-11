#include <cstdio>
#include <cstdlib>

void delete(char s[50],char c) {
	int k = 0;
	for(int i = 0; i < strlen(s); i++) {
		if(s[i]==c)
			continue;
		s[k++]=s[i];
	}
	s[k]='\0';
}

int main() {
	char s[50],c,res[50];
	scanf("%s %c",s,&c);
	delete(s,c);
	printf("%s\n",s);
	return 0;
}