#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

DWORD WINAPI thread_func(LPVOID thread) {
	for (int i = 1; i < 10000; i++) {
		printf("i : %d\n", i);
	}
	return 0;
}

int _tmain() {
	DWORD threadId;
	HANDLE threadHandler, dummyHandler;
	threadHandler = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &threadId);
	Sleep(5000);
	ResumeThread(threadHandler);
	WaitForMultipleObjects(1, &dummyHandler, TRUE, INFINITE);
	CloseHandle(threadHandler);
	CloseHandle(dummyHandler);
	getchar();
	return 0;
}