/*
 *  char **argv
 *  -> argv: pointer to pointer to char
 * 
 *  int (*daytab)[13]
 *  -> daytab: pointer to array[13] of int
 * 
 *  int *daytab[13]
 *  -> daytab: array[13] of pointer to int
 * 
 *  void *comp()
 *  -> comp: function returning pointer to void
 * 
 *  void (*comp)()
 *  -> comp: pointer to function returning void
 * 
 *  char (*(*x())[])()
 *  -> x: function returning pointer to array[] of pointer to function returning char
 * 
 *  char (*(*x[3])())[5]
 *  x: array[3] of pointer to function returning pointer to array[5] of char
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

/* global */
int tokentype;           /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

int main() /* convert declaraton to words */
{
    while (gettoken() != EOF)/* 1st token on line */
    {
        strcpy(datatype,token);/* is the datatype */
        out[0] = '\0';
        dcl();/* parse rest of line */
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator  */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') /* (dcl) */
    {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS) /* parentheses,round brackets() */
            strcat(out, " function returning");
        else /* square brackets[token] */
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int gettoken(void)/* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while ( (c = getch()) == ' ' || c == '\t')
        ;
    
    if( c == '(')
    {
        if ( (c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for ( *p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for ( *p++ = c; isalnum(c = getch());)
            *p++ =c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
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

/* undcl: convert word descriptions to declarations */
void undcl(void)
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*')
            {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s",token, out);
                strcpy(out, temp);
            }
            else
                printf("invalid input at %s\n",token);
    }
}