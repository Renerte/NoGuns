#include <Windows.h>
#include <iostream>

BOOL CALLBACK windowProc(_In_ HWND hWnd, _In_ LPARAM lParam) {
	wchar_t* class_buffer;
	class_buffer = new wchar_t[256];

	GetClassName(hWnd, class_buffer, 256);

	if (wcscmp(class_buffer, L"Valve001") == 0) {
		DWORD pId = 0;
		GetWindowThreadProcessId(hWnd, &pId);
		HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, FALSE, pId);
		std::wcout << L"Valve Source game detected! Termination attempted!" << std::endl;
		TerminateProcess(processHandle, 0);
		CloseHandle(processHandle);
	}
	delete[] class_buffer;
	return TRUE;
}

int main() {
	BOOL works = TRUE;
	while (works == TRUE) {
		works = EnumWindows(*windowProc, NULL);
		Sleep(1000);
	}
	return 0;
}