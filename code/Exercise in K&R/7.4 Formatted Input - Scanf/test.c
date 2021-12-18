
// int scanf(char *format, ...);
// int sscanf(char *string, char *format, ...);

#include <stdio.h>

/* rudimentary calculator */
int main(void)
{
    double sum, v;

    sum = 0;
    while (scanf("%lf",&v) == 1)
        printf("\t%.2f\n",sum += v);
    
    return 0;
}