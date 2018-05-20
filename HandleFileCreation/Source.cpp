// ���������� ����������, C++
/** Source.cpp: ���������� ����� ����� ��� ����������� ����������.
���������� ������� ��������� ���� Hello.txt, ��������� ������� CreateFile()
� ��������� ���� ������������ ���� (����� � �������� ����������� ������ ����������) ��������� ������� WriteFile() � GetCurrentDirectory();
�������� ����������� ����������� � ������� ������� CloseHandle()
-----------------------------------------------------------------------------------------------------------------
� ������ ��������� �������� ��� �������� �����, ��������� CreateFile() ���������� ��� �����.
� ������ ������ ������������ ����������� �������� INVALID_HANDLE_VALUE.
����������� �� ������ ��������� � ������� ������� GetLastError().
*/


#include "stdafx.h"
#include <windows.h>
#include <stdio.h>


int main(int argc, CHAR* argv[]) {
	CHAR Buffer[256];
	DWORD nLenCurDir;
	HANDLE hOut;

	CHAR fileName[30] = TEXT("Hello.txt");

	hOut = CreateFile(fileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		printf("ERROR %x \n", GetLastError());
		return 3;
	}

	nLenCurDir = GetCurrentDirectory(256, Buffer);

	WriteFile(hOut, Buffer, 256, NULL, NULL);

	CloseHandle(hOut);

	return 0;
}