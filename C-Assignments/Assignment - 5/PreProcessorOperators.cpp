#include<cstdio>
#include<cstdlib>

#define Book(name, author) #name "is written by " #author
#define print(s) printf("Token" #s " = %d\n", token##s)

int main() {
    int token9 = 100;
    print(9);
    printf("%s", Book(ASCII, RITCHIE));
    return 0;
}