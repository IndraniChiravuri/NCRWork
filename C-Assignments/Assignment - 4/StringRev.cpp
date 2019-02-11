#include <cstdio>
#include <cstdlib>

void reverse(char *s,int low,int high) {
	if(low >= high) {
		return;
	}
	char ch=s[low];
	s[low]=s[high];
	s[high]=ch;
	reverse(s,low+1,high-1);
	return ;
}
int main() {
	char s[50];
	scanf("%[^\n]s",s);
	reverse(s,0,strlen(s)-1);
	printf("%s\n", s);
	return 0;
}