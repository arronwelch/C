
// int a[10];

// int *pa;
// pa = &a[10];//sets pa to point to element zero of a;this is,pa contains the address of a[0].

// int x = *pa;//copy the contents of a[0] into x.

// *(pa+1) //refers to the contents of a[1].

// pa = a;//pa and a have identical values.

// /* strlen: return length of string s */
// int strlen(char *s)
// {
//     int n;

//     for(n = 0; *s != '\0'; s++)
//         n++;
//     return n;
// }

// strlen("hello,world"); /* string constanty */
// strlen(array); /* char array[100] */
// strlen(ptr); /* char *ptr */

// //as formal parameters in a function definition,
// char s[];
// //and
// char *s;
// //are equivalent;

// f(&a[2]);
// //and
// f(a+2);
// //both pass to the function f the address of the subarray that starts at a[2].

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
    {
        allocp += n;
        return allocp - n; /* return old position */
    }
    else
        return 0;/* not enough room */
}

void afree(char *p)/* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

/* strlen: return length of string s */
int strlen(char *s)
{
    char *p = s;

    while( *p != '\0')
        p++;
    return p-s;
}

#include <stddef.h>
/* strlen: return length of string s */
ptrdiff_t strlen(char *s) //large enough to hold the signed difference of two pointer values
{
    char *p = s;

    while( *p != '\0')
        p++;
    return p-s;
}

/* strlen: return length of string s */
size_t strlen(char *s)
{
    char *p = s;

    while( *p != '\0')
        p++;
    return p-s;
}