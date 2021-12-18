/* Adding the Modulus operator and provision for negative numbers 
* Program is given the input in a single and and it print the output upon
* getting a \n character.
* For e.g:
*
* 10 10 + 100 + 2 *
*		240
*/

#include <stdio.h>   /* for printf() getchar() EOF */
#include <string.h>  /* for strcmp() */
#include <stdlib.h>  /* for atof() */
#include <math.h>    /* for fmod() */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                    push(atof(s));
                    break;
            case '+':
                    push(pop()+pop());
                    break;
            case '*':
                    push(pop()*pop());
                    break;
            case '-':
                    op2 = pop();
                    push(pop()-op2);
                    break;
            case '/':
                    op2 = pop();
                    if(op2 != 0.0)
                        push(pop()/op2);
                    else
                        printf("error:zero divisor\n");
                    break;
            case '%':
                    op2 = pop();
                    if(op2 != 0.0)
                        push(fmod(pop(),op2));
                    else
                        printf("erro:zero divisor\n");
                    break;
            case '\n':
                    printf("\t%.8g\n",pop());//use %e or %f, whichever is shorter
                    break;
            default:
                    printf("error: unknown command %s\n",s);
                    break;
        }
    }
    return 0;
}


#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f into value stack */
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h> /* for isdigit() */

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) 
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';/* only wihte space */

    if (!isdigit(c) && c != '.' && c != '-')
        return c;		/* not a number */

    i = 0;
    if (c == '-' || isdigit(c))    	// collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')      	// collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void)    /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* get a (possibly pushed-back) character */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
