#include <Windows.h>
#include <tchar.h>
#include <iostream>

DWORD WINAPI Thread_func(LPVOID threadPar) {
	_tprintf(TEXT("In Second Thread Function\n"));
	return 0;
}

int main() {
	DWORD dwThread;
	HANDLE threadHandler = CreateThread(NULL, 0, Thread_func, NULL, 0, &dwThread);
	if (threadHandler == NULL) {
		_tprintf(TEXT("Erroe while creating thread: %d\n", GetLastError()));
		getchar();
		return 0;
	}

	DWORD dwRe = WaitForSingleObject(threadHandler, INFINITE);
	DWORD dwExitCode;
	BOOL flag = GetExitCodeThread(threadHandler, &dwExitCode);
	if (flag == 0) {
		_tprintf(TEXT("Exit Code Failed: %d\n", GetLastError()));
		getchar();
		return 0;
	}
	DWORD dwExitThread = 31;
	flag = TerminateThread(threadHandler, dwExitThread);

	if (flag == 0) {
		_tprintf(TEXT("Error while terminating thread: %d\n", GetLastError()));
		getchar();
		return 0;
	}
	GetExitCodeThread(threadHandler, &dwExitThread);
	_tprintf(TEXT("Second thread Exit code: %d\n", dwExitThread));
	CloseHandle(threadHandler);
	
	getchar();
	return 0;
}