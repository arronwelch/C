
#include <fcntl.h>
// #incldeu <sys/file.h> // Berkelay(BSD) version

int fd;
// int open(char *name, int flags, int perms);

char name[] = "filename";
int flags = -1;


fd = open(name, flags, perms);

O_RDONLY /* open for reading only */
O_WRONLY /* open for writing only */
O_RDWR /* open for both reading and writing */



