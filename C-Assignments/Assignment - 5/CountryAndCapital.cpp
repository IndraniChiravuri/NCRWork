#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>

int main() {
	FILE *fp = NULL;
	fp = fopen("file2.txt","r");
	char line[50];
	size_t read;
	size_t len=0;
	if(fp == NULL) {
		perror("Error while opening the file");
		exit(-1);
	}
	int k = 0;
	char ch,capital[6][20],country[6][20];
	while((fgets(line,sizeof(line),fp))) {
		int i;
		read=strlen(line);
		for(i=0;i<read&&line[i]!='-';i++) {
			country[k][i]=line[i];

		country[k][i]='\0';
		i++;
		int j=0;
		for(;i<read;i++) {
			capital[k][j]=line[i];
			j++;
		}
		country[k][j]='\0';
		k++;
	}
	fclose(fp);
    printf("1. Get the capital of a specified country\n");
    printf("2. Get the country of specified capital\n");
    printf("3. Exit\n");
    int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    char st[20];
    char en[20];
    switch(choice) {
        case 1:
            scanf("%s",st);
            if(st[0]=='I') {
                printf("Capital of %s is %s\n",st, capital[0]);
            } else if(st[0]=='B') {
                printf("Capital of %s is %s\n",st, capital[1]);
            } else if(st[0]=='C') {
                printf("Capital of %s is %s\n",st, capital[2]);
            } else if(st[0]=='F') {
                printf("Capital of %s is %s\n",st, capital[3]);
            } else if(st[0]=='G') {
                printf("Capital of %s is %s\n",st, capital[4]);
            } else if(st[0]=='A') {
                printf("Capital of %s is %s\n",st, capital[5]);
            }


            break;
        case 2:
            scanf("%s",en);
            if(en[0]=='D'&&en[1]=='e') {
                printf("Country of %s is %s\n",en, country[0]);
            } else if(en[0]=='D'&&en[1]=='h') {
                printf("Country of %s is %s\n",en, country[1]);
            } else if(en[0]=='B'&&en[1]=='e') {
					printf("Country of %s is %s\n",en, country[2]);
            } else if(en[0]=='F'&&en[1]=='s') {
					printf("Country of %s is %s\n",en, country[3]);
            } else if(en[0]=='B'&&en[1]=='e') {
					printf("Country of %s is %s\n",en, country[4]);
            } else if(en[0]=='N') {
					printf("Country of %s is %s\n",en, country[5]);
            }


            break;
        case 3: exit(0);
		}
		return 0;
}
}