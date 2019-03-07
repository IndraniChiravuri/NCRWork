#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

char rev[100];

int length(char* str) {
    int cnt = 0,i = 0;
    while(str[i++] != '\0') {
        cnt++;
    }
    return cnt;
}

int strcomp(char s[50],char t[50]) {
    if (length(s) < length(t))
        return INT_MIN;
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
	/*if (length(dest) < length(src))
        return NULL; */
	for (i = 0; src[i] != '\0'; i++);
    for (j = 0; dest[j] != '\0'; j++)
        src[i+j] = dest[j];
    src[i+j] = '\0';
    return src;
}

int strcopy(char *a,char *b) {
	int i = 0;
	if (length(a) < length(b)) {
        printf("Invalid input\n");
        return 0;
	}
	while((a[i]=b[i])!='\0')
	i++;
	return 1;
}

int main() {
	char str[50],str2[50],*cat;
	int ret;
	printf("1. String Length 2. String Copy 3. String Comparision 4. String Reverse 5. String Concatinate\n");
	int choice;
	scanf("%d", &choice);
	printf("Enter string: ");
	scanf("%s",str);
	switch(choice) {
        case 1:
            printf("Length: %d", length(str));
            break;
        case 2:
            printf("Enter a string to be copied: ");
            scanf("%s",str2);
            ret = strcopy(str,str2);
            if (ret)
                printf("Copied String: %s\n", str);
            break;
        case 3:
            printf("Enter a string to compare: ");
            scanf("%s",str2);
            ret = strcomp(str,str2);
            if (ret == INT_MIN)
                printf("Invalid input\n");
            else if(ret == 0) {
                printf("The strings are equal\n");
            } else {
                printf("The strings are unequal\n");
            }
            break;
        case 4:
            printf("Reversed String: %s", strev(str));
            break;
        case 5:
            printf("Enter string2: ");
            scanf("%s",str2);
            cat = strconcat(str, str2);
            if (cat == NULL)
                printf("Invalid Input\n");
            else
                printf("Concatenated String: %s", cat);
            break;
	}
	return 0;
}