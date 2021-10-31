
// int n_read = read(int fd, char *buf, int n);
// int n_written = write(int fd, char *buf, int n);

#include <stdio.h>
#include "syscalls.h"
#undef getchar // it is implemented as a macro

int main() /* copy input to output */
{
    char buf[BUFSIZE];
    int n;

    while ((n = read(0,buf,BUFSIZE)) > 0)
        write(1,buf,n);

    return 0;
}

/* getchar: unbuffered single character input */
int mfgetchar(void)
{
    char c;

    return (read(0,&c, 1) == 1) ? (unsigned char) c : EOF;
}

/* getchar: simple buffered version */
int getchar(void)
{
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    if ( 0 == n ) /* buffer is empty */
    {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
