#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

int _tmain(int argc, TCHAR *argv[], TCHAR *env[]) {
	HANDLE hEvent = CreateEvent(NULL,
		FALSE,
		FALSE,
		TEXT("Sample Event")
	);
	getchar();
	return TRUE;

}