#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, TCHAR *argv[], TCHAR *env[]) {
	STARTUPINFO info1, info2;
	PROCESS_INFORMATION processInfo1, processInfo2;
	ZeroMemory(&info1, sizeof(info1));
	info1.cb = sizeof(info1);
	ZeroMemory(&processInfo1, sizeof(processInfo1));
	ZeroMemory(&info2, sizeof(info2));
	info2.cb = sizeof(info2);
	ZeroMemory(&processInfo2, sizeof(processInfo2));

	if (argc != 3) {
		printf("Insufficient Arguments!\n");
		printf("Error: %d\n", GetLastError());
		getchar();
		return FALSE;
	}

	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &info1, &processInfo1)) {
		printf("Process1 Creation Error: %d\n", GetLastError());
		getchar();
		return FALSE;
	}

	printf_s("Process Handler: %d\n", processInfo1.hProcess);
	printf_s("Process1 id: %d\n", processInfo1.dwProcessId);
	DWORD dwReturnValue = WaitForSingleObject(processInfo1.hProcess, INFINITE);
	printf_s("Wait for single object output: %d\n", dwReturnValue);

	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &info2, &processInfo2)) {
		printf("Process 2 creation Error: %d\n", GetLastError());
		getchar();
		return FALSE;
	}

	printf_s("Process 2 Handler: %d\n", processInfo2.hProcess);
	printf_s("Process 2 id: %d\n", processInfo2.dwProcessId);
	dwReturnValue = WaitForSingleObject(processInfo2.hProcess, INFINITE);
	printf_s("Wait for single object output: %d\n", dwReturnValue);

	getchar();
	return TRUE;
}