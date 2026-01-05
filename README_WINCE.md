# MQuickJS WinCE (CeGCC) Port Patch Set

This ZIP does **not** include the upstream mquickjs sources. It provides:
- A **CeGCC/Windows CE** Makefile (`Makefile.wince`)
- A small **WinCE compatibility layer** (`wince/wince_compat.[ch]`)
- A minimal **readline replacement** for WinCE (`wince/readline_wince.c`)
- A **unified diff patch** (`patches/mquickjs_wince.patch`) showing the edits you should apply to upstream.

Why: In this chat environment, I cannot reliably fetch the entire upstream repository to repackage it. If you upload your `mquickjs` source tree (zip/tarball) here, I can apply these changes and return a full patched zip.

## Target
- Windows CE .NET 4.1 (ARM)
- Toolchain: CeGCC (`arm-mingw32ce-gcc`) located at `/home/builder/cegcc/bin`

## Quick build (after applying patch)
```sh
export PATH=/home/builder/cegcc/bin:$PATH
cd mquickjs
make -f Makefile.wince clean all
```

Outputs:
- `mqjs.exe`
- `example.exe`

## Typical CeGCC pitfalls addressed
- No POSIX `gettimeofday()` / `unistd.h` / TTY raw mode
- Limited console capabilities on WinCE
- Avoids `readline_tty.c` and replaces it with a simple `fgets`-based implementation
- Links against `coredll`

## If you want me to return a full patched source zip
Upload either:
- a zip of `bellard/mquickjs` (any commit), or
- paste your `git rev-parse HEAD` + `git diff` error logs

Then I can apply and validate (at least compile-level) the final tree.
