
//now is the time for all good men to come to the aid of their party $
//   1 aid   1 all   1 come   1 for   1 good   1 is   1 men   1 now   1 of   1 party   2 the   1 their   1 time   2 to
/*
 *            now
 *            /  \
 *           /    \
 *          is    the
 *         / \     /  \
 *        /   \   /    \
 *      for  men of     time
 *      / \       \      / \ 
 *     /   \       \    /   \
 *   all good   party their to
 *   /  \
 *  /    \
 * aid  come
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tnode /* the tree node: */
{
    char *word;          /* points to the test */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != '$') /* use '$' terminate input */
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);

    return 0;
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
