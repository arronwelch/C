
// cat x.c, y.c

#include <stdio.h>

FILE *fp;                            /* fp is a pointer to a FILE */
FILE *fopen(char *name, char *mode); /* fopen returns a pointer to a FILE */
/* FILE is a type name,like int, not a structure tag */

int getc(FILE *FP);
int putc(int c, FILE *fp);

#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout);

int fscanf(FILE *fp, char *format, ...);
int fprintf(FILE *FP, char *format, ...);

int main(void)
{
    char *name = "test.c";
    char *mode = "r";
    fp = fopen(name,mode);

    return 0;
}