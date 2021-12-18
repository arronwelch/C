/* 
 * Exercise 8-6:(page 189 K&R)
 * The standard library function calloc(n,size) returns a pointer to [n] objects
 * of size [size], with the storage initialized to zero. Write calloc, by calling
 * malloc or by modifying it.
 *
 * */
// #include <syscalls.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Hello,Ubuntu!\n");
	return 0;
}

/* calloc: allocate [n] objects of size size */
void *mcalloc(unsigned n, unsigned size)
{
    unsigned i, nb;
    char *p, *q;

    nb = n * size;
    if ((p = q = (char *)malloc(nb)) != NULL)
        for(i = 0; i < nb; i++)
            *p++ = 0;
    return q;
}
