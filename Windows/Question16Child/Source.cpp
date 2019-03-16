#include <Windows.h>
#include <tchar.h>
#include <iostream>

int _tmain(int argc, TCHAR *argv[]) {
	STARTUPINFO info;
	PROCESS_INFORMATION processInfo;
	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);
	ZeroMemory(&processInfo, sizeof(processInfo));

	if (!CreateProcess(TEXT("C:/Users/admin/Desktop/NCRWork/Windows/Question16Child/executable.exe"), (LPWSTR)(&pi.hProcess), NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &info, &processInfo)) {
		_tprintf(TEXT("Error while creating process: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	SetPriorityClass(processInfo.hProcess, BELOW_NORMAL_PRIORITY_CLASS);
	getchar();
	return 0;
}