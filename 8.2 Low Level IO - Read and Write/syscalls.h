
#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

// int n_read = read(int fd, char *buf, int n);
// int n_written = write(int fd, char *buf, int n);

int read(int fd, char *buf, int n);
int write(int fd, char *buf, int n);

#define BUFSIZE 100

#endif
