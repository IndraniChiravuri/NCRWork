#include <Windows.h>
#include <tchar.h>
#include <iostream>

long globalVar;

DWORD WINAPI Threadfunc1(LPVOID threadPar) {
	globalVar++;
	return 0;
}

DWORD WINAPI Threadfunc2(LPVOID threadPar) {
	globalVar++;
	return 0;
}

int main() {
	DWORD dwThreadId1, dwThreadId2;
	HANDLE threadHandlers[2];
	while (1) {
		globalVar = 0;
		threadHandlers[0] = CreateThread(NULL,
			0,
			Threadfunc1,
			NULL,
			0,
			&dwThreadId1);
		if (threadHandlers[0] == NULL) {
			printf("Error while creating first thread: %d\n", GetLastError());
			getchar();
			return 1;
		}
		threadHandlers[1] = CreateThread(NULL,
			0,
			Threadfunc2,
			NULL,
			0,
			&dwThreadId2);
		if (threadHandlers[1] == NULL) {
			printf("Error while creating second thread: %d\n", GetLastError());
			getchar();
			return 1;
		}
		WaitForMultipleObjects(2, threadHandlers, TRUE, INFINITE);
		CloseHandle(threadHandlers[0]);
		CloseHandle(threadHandlers[1]);

		printf("Global Var: %ld\n", globalVar);

		if (globalVar == 1)
			break;
	}
	getchar();
	return 0;
}