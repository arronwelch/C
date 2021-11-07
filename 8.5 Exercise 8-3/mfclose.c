/**
 * Exercise 8-3:(page 179 K&R)
 * Design and write _flushbuf, fflush, and fclose.
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

#include <syscalls.h>

/* _flushbuf: allocate and flush output buffer */
int _flushbuf(int x, FILE *fp)
{
    unsigned nc; /* of chars to flush */
    int bufsize; /* size of buffer alloc */

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;/* error: invalid pointer */
    if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) /* no buffer yet */
    {
        if ((fp->base = (char *) malloc (bufsize)) == NULL)
        {
            fp->flag |= _ERR;
            return EOF; /* can't get buffer */
        }
    }
    else /* buffer already exists */
    {
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc)
        {
            fp->flag |= _ERR;
            return EOF; /* error: return EOF */
        }
    }
    fp->ptr = fp->base;/* beginning of buffer */
    *fp->ptr++ = (char) x; /* save current char */
    fp->cnt = bufsize - 1;
    return x;
}

/* fclose: close file */
int fclose(FILE *fp)
{
    int rc; /* return code */

    if ((rc = fflush(fp)) != EOF) /* anything to flush */
    {
        free(fp->base);/* free allocated buffer */
        fp->ptr = NULL;
        fp->cnt = 0;
        fp->base = NULL;
        fp->flag &= (_READ | _WRITE);
    }
    return rc;
}

/* fflush: flush buffer associated woth file fp */
int fflush(FILE *fp)
{
    int rc = 0;

    if (fp < _iob || fp >= _iob + OPEN_MAX)
        return EOF;
    if (fp->flag & _WRITE)
        rc = _flushbuf(0,fp);
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    return rc;
}
