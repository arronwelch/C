#include <stdio.h>

#define NKEYS 23

char *keyword[NKEYS];
int keycount[NKEYS];

/* ench keyword is a pair */
char *word;
int count;

/* first way: */
struct key
{
    char *word;
    int count;
} keytab[NKEYS];

/* second way: */
struct key
{
    char *word;
    int count;
};

struct key keytab[NKEYS];

/* third way with initializers */
struct key
{
    char *word;
    int count;
} keytab[] =
    {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        /* ... */
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0};

/*  ...
 *  {"unsigned", 0},
 *  {"void", 0},
 *  {"volatile", 0},
 *  ...
 */

int main(void)
{
    printf("Hello,World!\n");

    return 0;
}
