#include<cstdio>
#include<cstdlib>

int main() {
    FILE *fp = NULL;
    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        printf("Error while opening file -- file.txt");
        exit(-1);
    }
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}