
/**
 * Exercise 8-4: (page 179 K&R)
 * The standard library function
 *      int fseek(FILE *fp, long offset, int origin)
 * is identical to lseek except that fp is a file pointer instead of a file desciptor
 * and the return value is an int status, not a position. Write fseek. Make sure that
 * your fseek coordinates properly with the buffering done for the other function of the library.
 */

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 /* max #files open at once */

typedef struct _iobuf
{
    int cnt;    /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of buffer */
    int flag;   /* mode of file access */
    int fd;     /* file descriptor */
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags
{
    _READ = 01,  /* file open for reading */
    _WRITE = 02, /* file open for writing */
    _UNBUF = 04, /* file is unbuffered */
    _EOF = 010,  /* EOF has occurred on this file */
    _ERR = 020   /* error occurred on this file */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0                  \
                     ? (unsigned char)*(p)->ptr++ \
                     : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0        \
                        ? *(p)-ptr++ = (x) \
                        : _flushbuf((x), (p)))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

///////////////////////////////////////////////////////////////////////////

#include "syscalls.h"

/* fseek: seek with a file pointer */
int fseek(FILE *fp, long offset, int origin)
{
    unsigned nc; /* of chars to flush */
    long rc = 0; /* return code */
    
    if (fp->flag & _READ)
    {
        if (origin == 1)        /* from current position ? */
            offset -= fp->cnt;  /* remenber chars in buffer */
        rc = lseek(fp->fd, offset, origin);
        fp->cnt = 0; /* no characters buffered */
    }
    else if (fp->flag & _WRITE)
    {
        if((nc = fp->ptr - fp->base) > 0)
            if (write(fp->fd, fp->base, nc) != nc)
                rc = -1;
        if (rc != -1) /* no errors yet ? */
            rc = lseek(fp->fd, offset, origin);
    }
    return (rc == -1) ? -1 : 0;
}
