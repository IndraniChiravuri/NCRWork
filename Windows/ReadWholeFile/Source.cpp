#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#define size 20000

using namespace std;


int _tmain(int argc, LPTSTR argv[]) {
	HANDLE hFile;
	TCHAR data[size];

	if (argc != 2) {
		_tprintf(_T("Insufficient arguments! (filename.exe file)\n"));
		getchar();
		return FALSE;
	}
	hFile = CreateFile(argv[1], // NAME OF FILE
		GENERIC_READ, // OPEN MODE
		0, // SHARE MODE
		NULL, // SECURITY ATTRIBUTES
		OPEN_EXISTING, // CREATION DISPOSITION
		FILE_ATTRIBUTE_NORMAL, //FLAGS AND ATTRIBUTES
		NULL // TEMPLATE FILE
	);

	if (INVALID_HANDLE_VALUE == hFile) {
		_tprintf(_T("Error while opening file: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File opened successfully!\n"));
	DWORD dwData;
	//Reading File Data
	while (1) {
		ZeroMemory(data, size);
		BOOL flag = ReadFile(hFile, data, size, &dwData, NULL);
		if (flag == 0) {
			_tprintf(_T("Error while reading the file: %d\n"), GetLastError());
			getchar();
			return FALSE;
		}
		if (flag && dwData == 0) {
			_tprintf(_T("Reached EOF\n"));
			break;
		}
		CloseHandle(hFile);
		_tprintf(_T("Contents of %s: \n%s"), argv[1], data);
	}
	getchar();
	return TRUE;
}