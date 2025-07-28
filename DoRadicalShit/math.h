#pragma once
#include "includes.h"

VOID
SeedXorshift32(
	_In_ DWORD dwSeed
);

DWORD
Xorshift32();