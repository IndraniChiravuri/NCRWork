#include <cstdio>
#include <cstdlib>

struct struct_data {
    int x;
    char ch;
};

union union_data {
    int x;
    char ch;
};
int main() {
    struct struct_data sd;
    union union_data ud;
    printf("Struct Size: %d \nUnion Size: %d\n", sizeof(sd), sizeof(ud));
	return 0;
}