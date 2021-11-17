#include <stdio.h>

/* Exercsise 1-6.
 * Verify that the expression getchar() != EOF is 0 or 1.
 * Exercise 1-7. 
 * Write a program to print the value of EOF.
 */
int main()
{
    printf("%d\n",getchar() != EOF);//Verify that the expression getchar() != EOF is 0 or 1
    printf("%d",EOF);//print the value of EOF
    
    return 0;
}
