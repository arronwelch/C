
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 1000 /* define the string max length */

/* functions declaration:type is key */
void itoa(int, char []);
int itoar(int, char [],int);

/* itoa:interface function to itoar */
void itoa(int n,char s[])
{
    itoar(n,s,0);
}

/* itoar: convert n to characters in s, recursive version */
int itoar(int n, char s[], int i)
{
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        i = itoar(n / 10, s, i); /* recursivr call */
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    return i;/* return the updated value of i */
}

int main(void)
{
    char str[MAXLEN];

    itoa(996,str);
    printf("%s\n",str);

    itoa(-2345,str);
    printf("%s\n",str);

    itoa(INT_MAX,str);
    printf("%s\n",str);

    itoa(INT_MIN,str);//ERR
    printf("%s\n",str);

    return 0;
}