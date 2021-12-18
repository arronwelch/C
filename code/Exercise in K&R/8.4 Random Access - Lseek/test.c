
#include <stdio.h>
#include <stdlib.h>
// #include <fcntl.h>
#include <io.h>

// long lseek(int fd, long offset, int origin);

// lseek(sd,0L,2);//end of the file
// lseek(sd,0L,0;//get back to the beginning("rewind")

// #include "syscalls.h"

int get(int fd, long pos, char *buf, int n);

int main()
{
    // long fseek(FILE * fp, long offset, int origin);

    return 0;
}

/* get: read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0) /* get to pos */
        return read(fd, buf, n);
    else
        return -1;
}
