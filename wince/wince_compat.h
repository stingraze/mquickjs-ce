#pragma once
/*
 * wince_compat.h - portability helpers for Windows CE (CeGCC/newlib)
 *
 * Keep this header small and non-invasive: it is included by modified sources
 * when _WIN32_WCE is defined.
 */
#ifdef _WIN32_WCE

/* CeGCC typically provides windows.h and core APIs via coredll */
#include <windows.h>

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ssize_t
#if defined(_WIN32) || defined(_WIN32_WCE)
typedef long ssize_t;
#endif
#endif

/* Some WinCE libc variants miss these. Provide fallbacks. */
#ifndef HAVE_STRDUP
static __inline char *wince_strdup(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = (char*)malloc(n);
    if (!p) return NULL;
    memcpy(p, s, n);
    return p;
}
#define strdup wince_strdup
#endif

/* time helpers */
struct timeval {
    long tv_sec;
    long tv_usec;
};

int wince_gettimeofday(struct timeval *tv, void *tz);

/* sleep helpers */
static __inline void wince_usleep(unsigned usec) {
    /* Sleep() is in milliseconds */
    DWORD ms = (DWORD)((usec + 999) / 1000);
    Sleep(ms);
}

/* isatty stub: WinCE doesn't have POSIX ttys in the same way */
static __inline int wince_isatty(int fd) {
    (void)fd;
    return 0;
}

#endif /* _WIN32_WCE */
