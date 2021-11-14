/**
 * Exercise 8-2:
 * Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
 * Compare code size and execution speed.
 */


#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20 /* max #files open at once */

typedef struct
{
    unsigned is_unbuf : 1 ;
    unsigned is_buf   : 1 ;
    unsigned is_read  : 1 ;
    unsigned is_write : 1 ;
    unsigned is_eof   : 1 ;
    unsigned is_err   : 1 ;
}flag_field;


typedef struct _iobuf
{
    int cnt;    /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of buffer */
    flag_field flag;   /* mode of file access */
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

#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 /* RW for owner, group, others */

/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flag.is_read == 0 && fp->flag.is_write == 0)
            break; /* found free file */
    if (fp >= _iob + OPEN_MAX)
        return NULL; /* no free slots */

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY,0);
    if(fd == -1) /* couldn't access name */
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag.is_unbuf = 0;
    fp->flag.is_buf = 1;
    fp->flag.is_eof = 0;
    fp->flag.is_err = 0;
    if (*mode == 'r')/* read */
    {
        fp->flag.is_read =1;
        fp->flag.is_write = 0;
    }
    else /* write */
    {
        fp->flag.is_read = 0;
        fp->flag.is_write = 1;
    }
    return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if (fp->flag.is_read == 0 ||
        fp->flag.is_eof  == 1 ||
        fp->flag.is_err  == 1 )
        return EOF;
    
    bufsize = (fp->flag.is_unbuf == 1) ? 1 : BUFSIZ;
    if(fp->base == NULL) /* no buffer yet */
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF; /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd,fp->ptr,bufsize);
    if (--fp->cnt < 0)
    {
        if (fp->cnt == -1)
            fp->flag.is_eof = 1;
        else
            fp->flag.is_err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

/**
 * The code size of the modified function was larger and the functions were slower.
 * Bit fields are machine dependent and may slow down execution.
 */