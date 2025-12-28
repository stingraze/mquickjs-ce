/*
 * WinCE replacement for readline_tty.c
 *
 * Provides the minimal API used by mqjs.c:
 *   - int readline_tty_init(void);
 *   - const char *readline_tty(ReadlineState *s, const char *prompt, BOOL multi_line);
 *   - BOOL readline_is_interrupted(void);
 *
 * This implementation is intentionally simple and does not attempt raw-mode,
 * history navigation, completion, or colored prompt handling. It reads a line
 * via fgets() into the command buffer provided by mqjs.c (s->term_cmd_buf).
 */
#include <stdio.h>
#include <string.h>

#include "readline_tty.h"

#ifdef _WIN32_WCE
#include "wince/wince_compat.h"
#endif

int readline_tty_init(void)
{
    /* Unknown terminal width on WinCE; 0 means "no wrapping hints". */
    return 0;
}

static void strip_eol(char *buf)
{
    size_t n = strlen(buf);
    while (n > 0 && (buf[n - 1] == '\n' || buf[n - 1] == '\r')) {
        buf[--n] = '\0';
    }
}

const char *readline_tty(ReadlineState *s, const char *prompt, BOOL multi_line)
{
    (void)multi_line;

    if (!s || !s->term_cmd_buf || s->term_cmd_buf_size <= 0)
        return NULL;

    if (prompt) {
        fputs(prompt, stdout);
        fflush(stdout);
    }

    /* fgets reads at most size-1 characters and NUL-terminates */
    if (!fgets((char *)s->term_cmd_buf, s->term_cmd_buf_size, stdin))
        return NULL;

    strip_eol((char *)s->term_cmd_buf);

    s->term_cmd_buf_len = (int)strlen((char *)s->term_cmd_buf);
    s->term_cmd_buf_index = s->term_cmd_buf_len;
    return (const char *)s->term_cmd_buf;
}

BOOL readline_is_interrupted(void)
{
    /* No signal/ctrl-c handling in this minimal WinCE backend. */
    return FALSE;
}
