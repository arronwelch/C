/**
 * Exercise 5-10:
 * Write the program expr, which evaluates a reverse Polish expression from the command line,
 * where each operator or operand is a separate argument.
 * For example,
 * expr 2 3 4 + *
 * evaluates 2 * (3 + 4).
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER '0' /* signal that a number was found */

void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    double num;

    if (argc < 4)
    {
        printf("Usage: %s <expr>...\n",*argv);
        return -1;
    }

    while (--argc > 0)
    {
        ++argv;/* skip program name */
        if (num = atof(*argv))
            type = NUMBER;
        else
            type = **argv;/* the first character in string that *argv pointer to*/
        
        switch(type)
        {
            case NUMBER:
                push(num);
                break;
            case '*':/* argument '*' can't in windows10 powershell */
                push(pop() * pop());
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                {
                    printf("ERROR:zero divisor");
                    argc = 1;
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(),op2));
                else
                {
                    printf("ERROR:zero divisor");
                    argc = 1;
                }
                break;
            default:
                printf("ERROR:unknown command %s\n",*argv);
                argc = 1;
                break;
        }
    }
    printf("= %.8g\n",pop());/*print result*/
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

static int sp = 0; /* next free stack position */
static double val[MAXVAL]; /* value stack */

/* push: push f into value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ERROR:stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("ERROR:stack empty!\n");
        return 0.0f;
    }
}