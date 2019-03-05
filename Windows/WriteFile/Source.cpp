#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, LPTSTR argv[]) {
	HANDLE hFile;
	TCHAR data[] = TEXT("Spend 24 hours I need more hours with you!");

	if (argc != 2) {
		_tprintf(_T("Insufficient arguments! (filename.exe file)\n"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1],
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (hFile == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Error while opening file: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File opened successfully!\n"));
	DWORD dwData;
	BOOL flag = WriteFile(hFile, data, sizeof(data), &dwData, NULL);
	if (flag == 0) {
		_tprintf(_T("Error while writing the file: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	CloseHandle(hFile);
	_tprintf(_T("Contents of %s: \n%s"), argv[1], data);
	getchar();
	return 0;
}