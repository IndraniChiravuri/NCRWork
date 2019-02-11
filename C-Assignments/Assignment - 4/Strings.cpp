#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int n;
	scanf("%d",&n);
	char *s[n];
	for(int i = 0;i < n; i++) {
		s[i] = (char *)malloc(sizeof(char)*10);
		scanf("%s",s[i]);
	}
	for(int i = 0; i < n; i++) {
		printf("%s\n",s[i] );
	}
	for(int i=0;i<n;i++)
		free(s[i]);
	free(s);
	return 0;
}