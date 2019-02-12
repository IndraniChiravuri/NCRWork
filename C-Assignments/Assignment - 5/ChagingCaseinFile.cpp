#include<cstdio>
#include<cstdlib>
#include<cctype>

int main(int argc, char const *argv[]) {
	FILE *fp = NULL;
	char ch;
	fp = fopen("file.txt","r");
	if(fp == NULL) {
		perror("Error while opening file\n");
		exit(-1);
	}
	char content[500];
	int i = 0;
	while((ch = fgetc(fp)) != EOF) {
		if(islower(ch))
			content[i] = (char)toupper(ch);
		else
			content[i] = (char)tolower(ch);
		if(ftell(fp) == 5) {
			fseek(fp,10,SEEK_CUR);
		}
		i++;
	}
	printf("%s\n",content);
	fclose(fp);
	return 0;
}