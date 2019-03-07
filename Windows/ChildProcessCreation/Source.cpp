#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, TCHAR* argv[], TCHAR *env[]) {
	STARTUPINFO info;
	PROCESS_INFORMATION processInfo;
	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);
	ZeroMemory(&processInfo, sizeof(processInfo));

	if (argc != 2) {
		printf("Insufficient Arguments!\n");
		printf("Error: %d\n", GetLastError());
		getchar();
		return FALSE;
	}

	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &info, &processInfo)) {
		_tprintf(_T("Process1 Creation Error: %d\n"), GetLastError());
		getchar();
		return FALSE;
	} else {
		_tprintf(_T("Process Created!\n"));
	}
	WaitForSingleObject(processInfo.hProcess, 50000);
	//_tprintf(_T("--"));
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	getchar();
	return TRUE;
}