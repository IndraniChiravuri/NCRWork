#include <Windows.h>
#include <string.h>
#include <stdio.h>
//#include <shellapi.h>

int main() {
	LPWSTR *args;
	int argsCnt;
	args = CommandLineToArgvW(GetCommandLine(), &argsCnt);

	if (args == NULL) {
		wprintf(L"Insufficient arguments!");
		getchar();
		return -1;
	}
	else {
		for (int i = 0; i < argsCnt; i++) {
			printf_s("%d: %ws\n", i, args[i]);
		}
	}
	getchar();
	return 0;
}
