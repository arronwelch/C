
#include <stdio.h>

#define NSYM 100

union u_tag
{
    int ival;
    float fval;
    char *sval;
} u;

enum
{
    INT,
    FLOAT,
    STRING
};

struct
{
    char *name;
    int flags;
    int utype;
    union
    {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

int main(void)
{

    int utype = 0; /* initialization */

    if (utype == INT)
        printf("%d\n", u.ival);
    if (utype == FLOAT)
        printf("%f\n", u.fval);
    if (utype == STRING)
        printf("%s\n", u.sval);
    else
        printf("bad type %d in utype\n", utype);

    symtab[0].u.ival = 1;    /* the member ival */
    *symtab[0].u.sval = '0'; /* the first character of the string sval */
    symtab[0].u.sval[1] = '1';

    return 0;
}

/* a union only be initialized with a value of the type of its first member */
