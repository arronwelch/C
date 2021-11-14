
/***
 * Exercise 6-6: (page 145 K&R) 
 * Implement a simple version of the #define processor(i.e.,no arguments)
 * suitable for use with C programs, based on the routines of this section.
 * You may also find getch and ungetch helpful.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define HASHSIZE 101

struct nlist /* table entry: */
{
	struct nlist *next; /* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
char *mstrdup(char *);

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);

void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);

/* simple version of #define processor */
int main(void)
{
	char w[MAXWORD];
	struct nlist *p;

	while (getword(w, MAXWORD) != EOF)
		if (strcmp(w, "#") == 0) /* beginning of direct. */
			getdef();
		else if (!isalpha(w[0]))
			printf("%s", w); /* cannot be defined */
		else if ((p = lookup(w)) == NULL)
			printf("%s", w); /* not defined */
		else
			ungets(p->defn); /* push definition */

	return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np; /* found */
	return NULL;	   /* not found */
}

/* install: put (name,defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) /* not found */
	{
		np = (struct nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = mstrdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval]; //save previous pointer
		hashtab[hashval] = np;
	}
	else						/* already there */
		free((void *)np->defn); /* free previous defn */

	if ((np->defn = mstrdup(defn)) == NULL) /* strdup returns NULL if no space is available */
		return NULL;
	return np;
}

char *mstrdup(char *s) /* make a duplicate of s */
{
	char *p;

	p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
	if (p != NULL)					   /* malloc returns NULL if no space is available */
		strcpy(p, s);
	return p;
}

/* undef: remove a name and definition from the table */
void undef(char *s)
{
	int h;
	struct nlist *prev, *np;

	prev = NULL;
	h = hash(s); /* hash value of string s */

	for (np = hashtab[h]; np != NULL; np = np->next)
	{
		if (strcmp(s, np->name) == 0)
			break;
		prev = np; /* remenber previous entry */
	}

	if (np != NULL) /* found name */
	{
		if (prev == NULL) /* first in the hash list */
			hashtab[h] = np->next;
		else /* elsewhere in the hash list */
			prev->next = np->next;
		free((void *)np->name);
		free((void *)np->defn);
		free((void *)np); /* free allocated structure */
	}
}

/* getdef: get definition and install it */
void getdef(void)
{
	int c, i;
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

	skipblanks();
	if (!isalpha(getword(dir, MAXWORD)))
		error(dir[0], "getdef: expecting a directive after '#'");
	else if (strcmp(dir, "define") == 0)
	{
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha - name expected");
		else
		{
			skipblanks();
			for (i = 0; i < MAXWORD - 1; i++)
				if ((def[i] = getch()) == EOF || def[i] == '\n')
					break; /* end of definition */
			def[i] = '\0';
			if (i <= 0)
				error('\n', "getdef: incomplete define");
			else
				install(name, def);
		}
	}
	else if (strcmp(dir, "undef") == 0)
	{
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha in undef");
		else
			undef(name);
	}
	else
		error(dir[0], "getdef: expecting a directive after '#'");
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s)
{
	printf("error: %s\n",s);
	while (c != EOF && c != '\n')
		c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void)
{
	int c;

	while ((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possible pushed-back) character */
{
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ungets: push back s onto the input */
void ungets(char s[])
{
	int i;

	for (i = strlen(s) - 1; i >= 0 ; --i)
			ungetch(s[i]);
}