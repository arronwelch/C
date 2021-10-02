/*
 * [INPUT  ->]gcc -o main.exe main.c dcl.c gettoken.c
 * [INPUT  ->]./main.exe
 * [INPUT  ->]char (*(*x[3])())[5]
 * [OUTPUT ->]x: array[3] of pointer to function returning pointer to array[5] of char
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

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