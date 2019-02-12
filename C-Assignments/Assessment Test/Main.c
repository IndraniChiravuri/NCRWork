#include <stdio.h>
#include <stdlib.h>

void count();
void findAndReplace();
void removeComments();
void replaceTabs();

int main() {
	int choice;
	while(1) {
		printf("\n1. Count the number of alphabets, digits, spaces and special characters\n");
		printf("2. Find a string and replace it\n");
		printf("3. Remove comment lines\n");
		printf("4. Replace tabs with \t\n");
		printf("5. Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: count(); break;
			case 2: findAndReplace(); break;
			case 3: removeComments(); break;
			case 4: replaceTabs(); break;
			default: exit(0);
		}
	}
	return 0;
}