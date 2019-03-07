#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

DWORD WINAPI thread_func(LPVOID lpPar) {
	for (int i = 0; i < 10; i++) {
		printf("i : %d\n", i);
		Sleep(5000);
	}
	return 0;
}

int main() {
	DWORD threadId1, threadId2;
	HANDLE handlers[2];
	handlers[0] = CreateThread(NULL, 0, thread_func, NULL, 0, &threadId1);
	handlers[1] = CreateThread(NULL, 0, thread_func, NULL, 0, &threadId2);

	if (handlers[0] == NULL || handlers[1] == NULL) {
		printf("Unable to create thread");
		getchar();
		return FALSE;
	}
	WaitForMultipleObjects(2, handlers, TRUE, INFINITE);
	CloseHandle(handlers[0]);
	CloseHandle(handlers[1]);

	getchar();
	return TRUE;
}