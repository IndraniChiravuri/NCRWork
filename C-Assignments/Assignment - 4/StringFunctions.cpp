#include <cstdio>
#include <cstdlib>
#include <cstring>

char rev[100];

int strcomp(char s[50],char t[50]) {
	int i=0;
	while(s[i]==t[i]) {
		if(s[i]=='\0')
			return 0;
		i++;
	}
	return s[i]-t[i];
}

char *strev(char s[50]) {
	int i=0,j=strlen(s)-1;
	while(i<strlen(s)) {
		rev[i]=s[j];
		i++;j--;
	}
	return rev;
}
char *strconcat(char *src,char *dest) {
	int i,j;
	for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

void strcopy(char *a,char *b) {
	int i=0;
	while((a[i]=b[i])!='\0')
	i++;
	return ;
}

int main() {
	char s[50],t[50],*cat;
    scanf("%s",s);
	scanf("%s",t);
	if(strcomp(s,t)==0) {
		printf("The strings are equal\n");
	} else {
		printf("The strings are unequal\n");
	}
	printf("Reverse of string %s is: %s\n", s, strev(s));
	cat = strconcat(s,t);
	printf("Concatenated string %s and %s is: %s\n", s, t, cat);
	strcopy(cat,"Joey Tribbianne");
	printf("Copied string is: %s\n", cat);
	return 0;
}