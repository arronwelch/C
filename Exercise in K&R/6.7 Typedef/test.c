
#include <stdio.h>
#include <stdlib.h> /* malloc() */

#define MAXLINES 100

typedef int Length;

Length len, maxlen;
Length *length[MAXLINES];

typedef char *String;

String p, lineptr[MAXLINES], alloc(int);
int strcmp(String, String);
//p = (String)malloc(100);//error use

typedef struct tnode *Treeptr;

typedef struct tnode
{                        /* the tree node: */
    char *word;          /* points to the test */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
} Treenode;

Treeptr talloc(void);

typedef int (*PFI) (char *, char *);
/* creates the type PFI, for "pointer to function(of two char * arguments) returning int," */

PFI mstrcmp, numcmp;/* 'm' is my strcmp func */

int main(void)
{
    p = (String)malloc(100); //correct use

    return 0;
}

Treeptr mtalloc(void)
{
    return (Treeptr) malloc(sizeof(Treenode));
}
