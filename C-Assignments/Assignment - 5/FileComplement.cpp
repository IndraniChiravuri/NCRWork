#include<cstdio>
#include<cstdlib>
#include<cstring>

int main(int argc, char const *argv[]) {
	if(argc < 2) {
		perror("Insufficient Command Line Arguements\n");
		exit(-1);
	}
	FILE *fp = NULL;
	char complement[500], original[500], ch;
	fp = fopen(argv[1],"r");
	int i = 0;
	while((ch=fgetc(fp))!=EOF) {
		original[i] = ch;
		complement[i] = (char)(~((int)ch));
		i++;
	}
	original[i] = '\0';
	complement[i] = '\0';
	printf("%s\n",complement);
	fclose(fp);
	return 0;
}