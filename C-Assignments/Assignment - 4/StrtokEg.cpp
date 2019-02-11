#include <cstdio>
#include <cstdlib>

char * strtokf(char *str,char *delim) {
	static char *pos= NULL;
	char *start=NULL;
	if(str) {
		pos=str;
	}
	if(pos) {
		while (*pos && strchr(delim, *pos))
            pos++;
        if (*pos)  {
            start = pos;
            while (*pos && !strchr(delim, *pos))
                pos++;
            if (*pos)
                *pos++ = '\0';
        }
	}
	return start;
}

int main() {
	char s[50];
	scanf("%[^\n]s",s);
	char delim[10];
	scanf(" %[^\n]s\n",delim);
	char *token;
   	token = strtokf(s, delim);
    while( token != NULL ) {
      printf( "%s\n", token );
      token = strtokf(NULL, delim);
    }

	return 0;
}