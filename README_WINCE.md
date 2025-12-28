# MQuickJS WinCE (CeGCC) Port Patch Set

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
