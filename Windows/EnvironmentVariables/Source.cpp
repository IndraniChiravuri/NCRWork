#include<stdio.h>
#include<Windows.h>
#include<shellapi.h>
#include<string.h>
#include<tchar.h>

void dump(PTSTR envBlock[]) {
	int curr = 0;
	PTSTR * pEle = (PTSTR *)envBlock;
	PTSTR pCurr = NULL;
	while (pEle != NULL) {
		pCurr = (PTSTR)(*pEle);
		if (pCurr == NULL) {
			pEle = NULL;
		} else {
			_tprintf(TEXT("[%u]  %S \r \n"), curr, pCurr);
			curr++;
			pEle++;
		}
	}

}
int main(int argc, TCHAR *argv[], TCHAR *env[]) {
	dump(env);
	TCHAR envString[] = TEXT("%windir%");
	TCHAR buffer[MAX_PATH];
	DWORD flag = ExpandEnvironmentStrings(envString, buffer, MAX_PATH);;
	if (!flag) {
		printf_s("%d \n", GetLastError());
		return 0;
	} else {
		printf_s("PATH: %s \n", buffer);
	}
	getchar();
	return 0;
}