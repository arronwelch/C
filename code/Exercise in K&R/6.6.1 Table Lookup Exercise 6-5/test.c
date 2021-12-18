

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// exercise code

struct nlist /* table entry: */
{
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */
unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
char *mstrdup(char *);

int main(void)
{

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
    return NULL;       /* not found */
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
    else                        /* already there */
        free((void *)np->defn); /* free previous defn */

    if ((np->defn = mstrdup(defn)) == NULL) /* strdup returns NULL if no space is available */
        return NULL;
    return np;
}

char *mstrdup(char *s) /* make a duplicate of s */
{
    char *p;

    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)                     /* malloc returns NULL if no space is available */
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

/**
 * Exercise 6-5:(page 145 K&R)
 * Write a function undef that will remove a name and definition from the table
 * maintained by lookup and install
*/

// unsigned hash(char *);

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
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);/* free allocated structure */
    }
}