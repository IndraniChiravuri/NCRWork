#include <Windows.h>
#include <iostream>
#include <string.h>
#include <tchar.h>

using namespace std;

int _tmain(int argc, LPTSTR argv[]) {
	CHAR ch = 'I';
	WCHAR wChar = L'I';

	CHAR arr[] = "ANSI";
	WCHAR wArr[] = L"Wide Char";

	cout << "ch: " << ch << endl;
	cout << "wChar: " << wChar << endl;
	cout << "arr: " << arr << endl;
	cout << "len(arr): " << strlen(arr) << endl;
	cout << "wArr: " << wArr << endl;
	cout << "len(wArr): " << wcslen(wArr) << endl;

	int flag = IsTextUnicode(arr, strlen(arr), NULL);
	if (flag == 0)
		cout << "arr is not unicode" << endl;
	else if (flag == 1)
		cout << "arr is unicode" << endl;
	else {
		cout << "Error: " << GetLastError();
		return FALSE;
	}

	flag = IsTextUnicode(wArr, sizeof(wArr), NULL);
	if (flag == 0)
		cout << "wArr is not unicode" << endl;
	else if (flag == 1)
		cout << "wArr is unicode" << endl;
	else {
		cout << "Error: " << GetLastError();
		return FALSE;
	}

	int len = MultiByteToWideChar(CP_UTF8, 0, arr, -1, NULL, 0);
	if (len == 0) {
		cout << "Error: " << GetLastError();
		return FALSE;
	}
	WCHAR* result = new WCHAR[len];
	flag = MultiByteToWideChar(CP_UTF8, 0, arr, strlen(arr), result, wcslen(result));

	if (flag == 0) {
		cout << "Error: " << GetLastError();
		return FALSE;
	}
	cout << "arr is converted to widechar: " << result << endl;

	len = WideCharToMultiByte(CP_UTF8, 0, wArr, -1, NULL, 0, NULL, NULL);
	if (len == 0) {
		cout << "Error: " << GetLastError();
		return FALSE;
	}
	CHAR* result2 = new CHAR[len];
	flag = WideCharToMultiByte(CP_UTF8, 0, wArr, wcslen(wArr), result2, strlen(result2), NULL, NULL);
	if (flag == 0) {
		cout << "Error: " << GetLastError();
		return FALSE;
	}
	cout << "wArr converted to ANSI: " << result2 << endl;
	getchar();
	return TRUE;
}