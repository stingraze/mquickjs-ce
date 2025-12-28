#pragma once
/* Minimal errno.h for Windows CE / CeGCC builds.
 * This avoids CeGCC's include_next errno.h behavior that can fail in some setups.
 */
#ifndef _WINCE_ERRNO_H
#define _WINCE_ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

extern int errno;

/* Common errno values (POSIX-like). Values are conventional; adjust if needed. */
#ifndef EPERM
#define EPERM 1
#endif
#ifndef ENOENT
#define ENOENT 2
#endif
#ifndef ESRCH
#define ESRCH 3
#endif
#ifndef EINTR
#define EINTR 4
#endif
#ifndef EIO
#define EIO 5
#endif
#ifndef ENXIO
#define ENXIO 6
#endif
#ifndef E2BIG
#define E2BIG 7
#endif
#ifndef ENOEXEC
#define ENOEXEC 8
#endif
#ifndef EBADF
#define EBADF 9
#endif
#ifndef ECHILD
#define ECHILD 10
#endif
#ifndef EAGAIN
#define EAGAIN 11
#endif
#ifndef ENOMEM
#define ENOMEM 12
#endif
#ifndef EACCES
#define EACCES 13
#endif
#ifndef EFAULT
#define EFAULT 14
#endif
#ifndef EBUSY
#define EBUSY 16
#endif
#ifndef EEXIST
#define EEXIST 17
#endif
#ifndef EXDEV
#define EXDEV 18
#endif
#ifndef ENODEV
#define ENODEV 19
#endif
#ifndef ENOTDIR
#define ENOTDIR 20
#endif
#ifndef EISDIR
#define EISDIR 21
#endif
#ifndef EINVAL
#define EINVAL 22
#endif
#ifndef ENFILE
#define ENFILE 23
#endif
#ifndef EMFILE
#define EMFILE 24
#endif
#ifndef ENOSPC
#define ENOSPC 28
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WINCE_ERRNO_H */
