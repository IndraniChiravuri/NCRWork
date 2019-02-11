#include <cstdio>
#include <cstdlib>
#include <cstring>


int main() {
	int n;
	scanf("%d",&n);
	char s[n][20];
	for(int i=0;i<n;i++) {
		scanf("%s",s[i]);
	}
	for(int i=0;i<n-1;i++) {
		int min_index=i;
		char temp[20];
		strcpy(temp,s[i]);
		for(int j=i+1;j<n;j++) {
			if(strcmp(temp,s[j])>0) {
				strcpy(temp,s[j]);
				min_index=j;
			}
		}
		if(min_index!=i) {
			char temp2[20];
			strcpy(temp2,s[i]);
			strcpy(s[i],s[min_index]);
			strcpy(s[min_index],temp2);
		}
	}
	for(int i=0;i<n;i++)
		printf("%s  ", s[i]);
	printf("\n");
	return 0;
}