#include <cstdio>
#include <cstdlib>

int main() {
	char s[20];
	int num;
	scanf("%s",s);
	printf("%d\n", strlen(s));
	for(int i=0;i<strlen(s);i++) {
		if(islower(s[i]))
			s[i]=(char)toupper(s[i]) ;
		else if(isupper(s[i]))
			s[i]=(char)tolower(s[i]);
	}
	printf("%s\n",s );
	return 0;
}
