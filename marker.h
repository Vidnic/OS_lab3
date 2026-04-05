#pragma once
#include <windows.h>

struct ThreadData {
    int id;
    int* array;
    int size;
    HANDLE startEvent;
    HANDLE continueEvent;
    HANDLE stopEvent;
    HANDLE cannotContinueEvent;
};

DWORD WINAPI MarkerThread(LPVOID lpParam);