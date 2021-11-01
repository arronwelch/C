
#include <fcntl.h>
// #incldeu <sys/file.h> // Berkelay(BSD) version

int main()
{

    int fd;
    int mopen(char *name, int flags, int perms);

    char name[] = "filename";
    int flags = 0;
    int perms = 0;

    fd = mopen(name, flags, perms);

    flags = O_RDONLY; /* open for reading only */
    flags = O_WRONLY; /* open for writing only */
    flags = O_RDWR;   /* open for both reading and writing */

    fd = mopen(name, O_RDONLY, 0); //open an existing file for reading

    //the perms argument is always zero for the use of open that we will discuss.

    int  mcreat(char *name, int perms);
    fd = mcreat(name, perms);
}
