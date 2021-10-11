/*
 * Exercise 6-4:(page 143 K&R)
 * Write a program that prints distinct words in its input sorted into decreasing order
 * of frequency of occurrence. Precede each word by its count.
 */

/*

now is the time for all good men to come to the aid of their party $
 2:                 the
 2:                  to
 1:                 all
 1:                come
 1:                good
 1:                  is
 1:                 aid
 1:                 now
 1:                  of
 1:               party
 1:                 for
 1:               their
 1:                time
 1:                 men

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NDISTINCT 1000

struct tnode /* the tree node */
{
    char *word; /* points to the text */
    int count; /* number of occurrences */
    struct tnode *left;/* left child */
    struct tnode *right;/* right child */
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *,int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode *list[NDISTINCT]; /* pointers to tree nodes */
int ntn = 0; /* number of tree nodes */

/* print distinct words sorted in decreasing order of freq. */
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    int i;

    root = NULL;
    while (getword(word, MAXWORD) != '$') /* use '$' terminate input */
        if (isalpha(word[0]))
            root = addtree(root,word);
    
    treestore(root);
    sortlist();
    for(i = 0; i < ntn; i++)
        printf("%2d:%20s\n",list[i]->count,list[i]->word);

    return 0;
}

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p)
{
    if ( p != NULL)
    {
        treestore(p->left);
        if (ntn < NDISTINCT)
            list[ntn++] = p;
        treestore(p->right);
    }
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist(void)
{
    int gap, i, j;
    struct tnode *temp;

    for (gap = ntn/2; gap > 0; gap /= 2)
        for( i = gap; i < ntn; i++)
            for(j = i - gap; j >= 0; j -= gap)
            {
                if ((list[j]->count) >= (list[j+gap]->count))
                    break;
                temp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = temp;
            }
}
struct tnode *talloc(void);
char *mstrdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) /* a new word has arrived */
    {
        p = talloc(); /* make a new node */
        p->word = mstrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;    /* repeated word */
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s", p->count, p->word);
        treeprint(p->right);
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
