/*
 *  Write a cross-referencer that prints a list of all words in a document, and for each word,
 *  a list of the line numbers on which it ocurrs. Remove noise words like "the","and",and so on.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
struct linklist /* linked list of line numbers */
{
    int lnum;
    struct linklist *ptr;
};

struct tnode /* the tree node */
{
    char *word;             /* points to the text */
    struct linklist *lines; /* line numbers */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child  */
};

struct tnode *addtreex(struct tnode *, char *, int);
int getword(char *, int);
int noiseword(char *);
void treexprint(struct tnode *);

int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while (getword(word, MAXWORD) != '$') /* use '$' terminate input */
        if (isalpha(word[0]) && noiseword(word) == -1)
            root = addtreex(root, word, linenum);
        else if (word[0] == '\n')
            linenum++;

    treexprint(root);

    return 0;
}

struct tnode *talloc(void);
char * mstrdup(char *);
struct linklist *lalloc(void);
void addln(struct tnode *, int );

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum)
{
    int cond;

    if (p == NULL)/* a new word has arrived */
    {
        p = talloc();/* make a new word */
        p->word = mstrdup(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp (w, p->word)) == 0)
        addln(p,linenum);
    else if (cond < 0)
        p->left = addtreex(p->left, w, linenum);
    else
        p->right = addtreex(p->right, w, linenum);

    return p;
}

/* addln: add a line number to the linked list */
void addln(struct tnode *p, int linenum)
{
    struct linklist *temp;

    temp = p->lines;
    while (temp->ptr != NULL && temp->lnum != linenum)
        temp = temp->ptr;
    
    if (temp->lnum != linenum)
    {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}

/* treexprint: in-oder print of tree p */
void treexprint(struct tnode *p)
{
    struct linklist *temp;

    if(p != NULL)
    {
        treexprint(p->left);
        printf("%10s: ", p->word);
        for( temp = p->lines; temp != NULL; temp = temp->ptr)
            printf("%4d ",temp->lnum);
        printf("\n");
        treexprint(p->right);
    }
}

/* lalloc: make a linklist node */
struct linklist *lalloc(void)
{
    return (struct linklist *) malloc(sizeof(struct linklist));
}

/* noiseword: identify word as a noise word */
int noiseword(char *w)
{
    static char *nw[] =
    {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) -1;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if((cond = strcmp(w,nw[mid])) < 0)
            high = mid -1;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
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

    while (isspace(c = getch()) && c!= '\n')
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
