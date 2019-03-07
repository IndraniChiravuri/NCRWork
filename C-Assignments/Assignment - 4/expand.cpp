#include <cstdio>
#include <cstdlib>

int expand(char input[], char result[]) {
	int i = 0, j = 0;
	while(input[i] != '\0') {
        result[j++] = input[i++];
        while ((input[i] != '-') && (input[i] != '\0')) // NO EXPANSION NEEDED
            result[j++] = input[i++];
        if (input[i] != '\0') {
            int low = i - 1;
            int high = i + 1;
            int valid = 0, validr = 0;
            if (input[low] >= 'A' && (input[high] >= 'A') && (input[high] >= input[low])) // CHECKING WHETHER THE INPUT IN IS ORDER OR NOT
                valid = 1;
            else if (input[low] >= 'a' && (input[high] >= 'a') && (input[high] >= input[low]))
                valid = 1;
            else if (input[low] >= '0' && (input[high] >= '0') && (input[high] >= input[low]))
                valid = 1;
            else
                return 0;
            if (valid) {
                for (int k = input[i-1]+1; k < input[i+1]; k++)
                    result[j++] = k;
                i++;
            }
        } else
            break;
	}
	result[j] = '\0';
	return 1;
}

int main() {
	char s1[50],s2[100];
	scanf("%[^\n]s",s1);
	if(expand(s1,s2))
		printf("Result: %s\n",s2);
	else
		printf("Invalid Input\n");
	return 0;
}