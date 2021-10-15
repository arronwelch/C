
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

// exercise code

struct nlist /* table entry: */
{
	struct nlist *next; /* next entry in chain */
	char *name;			/* defined name */
	char *defn;			/* replacement text */
};

#define HASHSIZE 101

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

// for (ptr = head; ptr != NUll; ptr = ptr->next)
/*
 * the for loop in lookup is the standard idiom for walking along a linked list
 */

// struct nlist *lookup(char *);
// char *mstrdup(char *);

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

/* uninstall: remove (name) in hashtab */
int uninstall(char *name)
{
	unsigned hashval;

	if (lookup(name) == NULL) /* not found */
	{
		printf("not found \"%s\"", name);
		return 0;
	}
	else /* already there */
	{
		hashval = hash(name);
		free((void *)hashtab[hashval]); /* free previous defn */
		hashtab[hashval] = NULL;
		printf("undef \"%s\"", name);
		return 1;
	}
}