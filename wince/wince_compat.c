#include "wince_compat.h"

#ifdef _WIN32_WCE

/* Convert Windows FILETIME (100ns since 1601) -> Unix epoch seconds/usec */
int wince_gettimeofday(struct timeval *tv, void *tz) {
    (void)tz;
    if (!tv) return -1;

    SYSTEMTIME st;
    FILETIME ft;
    ULARGE_INTEGER uli;

    /* WinCE: GetSystemTimeAsFileTime may be absent; use GetSystemTime + SystemTimeToFileTime */
    GetSystemTime(&st);
    if (!SystemTimeToFileTime(&st, &ft)) {
        tv->tv_sec = 0;
        tv->tv_usec = 0;
        return 0;
    }

    uli.LowPart = ft.dwLowDateTime;
    uli.HighPart = ft.dwHighDateTime;

    /* 100ns ticks since 1601-01-01 */
    const uint64_t EPOCH_DIFFERENCE_100NS = 116444736000000000ULL; /* 1970-01-01 */
    uint64_t t = uli.QuadPart;

    if (t < EPOCH_DIFFERENCE_100NS) {
        tv->tv_sec = 0;
        tv->tv_usec = 0;
        return 0;
    }
    t -= EPOCH_DIFFERENCE_100NS;

    tv->tv_sec = (long)(t / 10000000ULL);
    tv->tv_usec = (long)((t % 10000000ULL) / 10ULL);
    return 0;
}

#endif
