#include <cstdio>
#include <cmath>

int main() {
	char *s[]= { "we will teach you how to ", "Move a mountain " , "Level a building " ,"Erase the past ","Make a million "};
	int cnt =0;
	for(int i=0;i<5;i++) {
		for(int j=0;j<strlen(s[i]);j++)
			if(s[i][j]=='e')
				cnt ++;
	}
	printf("Number of e's: %d\n", cnt);
	return 0;
}