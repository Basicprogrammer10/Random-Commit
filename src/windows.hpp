#ifndef RANDOM_COMMIT_WINDOWS_HPP
#define RANDOM_COMMIT_WINDOWS_HPP

#if (defined (_WIN32) || defined (_WIN64))
#include <windows.h>
#endif

void colorInit() {
#if (defined (_WIN32) || defined (_WIN64))
    DWORD l_mode;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hStdout, &l_mode);
    SetConsoleMode(hStdout, l_mode | 0x0004 | 0x0008);
#endif
}

#endif
