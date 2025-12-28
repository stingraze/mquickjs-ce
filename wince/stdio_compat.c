/*
 * stdio_compat.c - minimal stdio/errno compatibility for WinCE/CeGCC
 *
 * Some CeGCC/newlib builds used with WinCE may not provide perror().
 * Provide a small replacement that reports GetLastError().
 */
#ifdef _WIN32_WCE
#include <windows.h>
#include <stdio.h>

void perror(const char *s)
{
    DWORD e = GetLastError();
    if (s && *s) {
        fprintf(stderr, "%s: ", s);
    }
    fprintf(stderr, "Win32 error %lu\n", (unsigned long)e);
}
#endif
