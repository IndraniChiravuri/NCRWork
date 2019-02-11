#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char str[80];
    scanf("%[^\n]s", str);
    int alphaCnt = 0;
    int digCnt = 0;
    int blanksCnt = 0;
    int tabsCnt = 0;
    register int i = 0;
    //printf("%s\n", str);
    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            alphaCnt++;
        else if (isdigit(str[i]))
            digCnt++;
        else if (str[i] == ' ')
            blanksCnt++;
        else
            tabsCnt++;
		i++;
    }
    printf("%d %d %d %d\n", alphaCnt, digCnt, blanksCnt, tabsCnt);
    return 0;
}
