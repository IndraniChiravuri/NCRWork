#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

DWORD WINAPI thread_func2(LPVOID threadPar) {
	printf("In second thread function\n");
	Sleep(8000);
	return 0;
}

DWORD WINAPI thread_func1(LPVOID threadPar) {
	printf("In first thread function\n");
	DWORD threadId;
	HANDLE thread;

	DWORD exitCode;
	thread = CreateThread(NULL, 0, thread_func2, NULL, CREATE_SUSPENDED, &threadId);
	ResumeThread(thread);

	Sleep(2000);
	TerminateThread(thread, 2);
	Sleep(2000);
	GetExitCodeThread(thread, &exitCode);

	printf("Exit code of 2nd thread is: %d\n", exitCode);
	return 0;
}

int main() {
	DWORD threadId;
	HANDLE thread = CreateThread(NULL, 0, thread_func1, NULL, CREATE_SUSPENDED, &threadId);
	ResumeThread(thread);
	WaitForSingleObject(thread, INFINITE);

	getchar();
	return 0;
}