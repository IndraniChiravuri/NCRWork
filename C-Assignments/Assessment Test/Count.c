#include <stdio.h>
#include <stdlib.h>

void count() {

	FILE *fp=NULL;
	fp=fopen("file1.txt","r");

	if(fp==NULL) {
		perror("Error while opening the File - file1.txt\n");
		exit(-1);
	}

	int alphaCnt = 0;
	int digCnt = 0;
	int spacesCnt = 0;
	int spCnt = 0;
	char ch;
	while((ch=fgetc(fp))!=EOF) {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			alphaCnt++;
		else if (ch == ' ') 
			spacesCnt++;
		else if (ch >= '0' && ch <= '9')
			digCnt++;
		else  
			spCnt++;
	}

	fclose(fp);
	printf("Alpha Count: %d\t Digit Count: %d\t Spaces Count: %d\t Special Character Count: %d\t \n", alphaCnt, digCnt, spacesCnt, spCnt);
}