/*
 * Exercise 6-2:
 * write a program that reads a C program and prints in alphabetic order each group of variable names that
 * are identical in the first 6 characters, but different somewhere thereafter.Don't count words within strings and comments.
 * Make 6 a parameter that can be set from the command line.
 */


//"args": ["-3"],
//now is the time for all good men to come to the aid of their party $
//the
//their

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode /* the tree node */
{
    char *word;          /* points to the text */
    int match;           /* match found */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);

/* print in alphabetic order each group of variable names */
/* identical in the first num characters (default 6) */
int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO; /* YES if match was found */
    int num;        /* number of the first ident. chars */

    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != '$') /* use '$' terminate input */
    {
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtreex(root, word, num, &found);
        found = NO;
    }
    treexprint(root);

    return 0;
}

struct tnode *talloc(void);
char *mstrdup(char *);
int compare(char *, struct tnode *, int, int *);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
    int cond;

    if (p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new tree */
        p->word = mstrdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    }
    else if ((cond = compare(w, p, num, found)) < 0)
        p->left = addtreex(p->left, w, num, found);
    else if (cond > 0)
        p->right = addtreex(p->right, w, num, found);

    return p;
}

/* compare: compare words and update p->match */
int compare(char *s, struct tnode *p, int num, int *found)
{
    int i;
    char *t = p->word;

    for (i = 0; *s == *t; i++, s++, t++)
        if (*s == '\0')
            return 0;

    if (i >= num) /* identical in first num chars ? */
    {
        *found = YES;
        p->match = YES;
    }

    return *s - *t;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
    if (p != NULL)
    {
        treexprint(p->left);
        if (p->match)
            printf("%s\n", p->word);
        treexprint(p->right);
    }
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *mstrdup(char *s) /* make a duplicate of s */
{
    char *p;

    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)                     /* malloc returns NULL if no space is available */
        strcpy(p, s);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') /* alphanumeric characters and underscores */
    {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_')
            {
                ungetch(*w);
                break;
            }
    }
    else if (c == '\'' || c == '"') /* string constants */
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c)
            {
                w++;
                break;
            }
            else if (*w == EOF)
                break;
    }
    else if (c == '/')
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);

    *w = '\0';
    return c;
}

/* comment: skip over comment and return a character */
int comment(void)
{
    int c, getch(void);
    void ungetch(int);

    while ((c = getch()) != EOF)
        if (c == '*')
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);

    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possible pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
