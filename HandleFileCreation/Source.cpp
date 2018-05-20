// Консольное приложение, C++
/** Source.cpp: определяет точку входа для консольного приложения.
Приложение создает текстовый файл Hello.txt, используя фукуцию CreateFile()
В текстовый файл записывается путь (место с которого выполняется запуск приложения) используя фукуции WriteFile() и GetCurrentDirectory();
Файловые дескрипторы закрываются с помощью функции CloseHandle()
-----------------------------------------------------------------------------------------------------------------
В случае успешного создания или открытия файла, процедура CreateFile() возвращает его хэндл.
В случае ошибки возвращается специальное значение INVALID_HANDLE_VALUE.
Подробности об ошибке выводятся с помощью функции GetLastError().
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