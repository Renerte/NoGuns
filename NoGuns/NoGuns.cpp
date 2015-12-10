#include <Windows.h>
#include <iostream>

BOOL CALLBACK windowProc(_In_ HWND hWnd, _In_ LPARAM lParam) {
	wchar_t* class_buffer;
	class_buffer = new wchar_t[256];

	GetClassName(hWnd, class_buffer, 256);

	if (wcscmp(class_buffer, L"Valve001") == 0) {
		std::wcout << L"Valve Source game detected!" << std::endl;
	}
	delete[] class_buffer;
	return TRUE;
}

int main() {
	while (true) {
		BOOL works = EnumWindows(*windowProc, NULL);
		Sleep(1000);
	}
	return 0;
}