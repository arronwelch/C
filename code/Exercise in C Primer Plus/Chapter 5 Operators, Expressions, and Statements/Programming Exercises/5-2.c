/* Programming Exercises 5-2.c */

/*
2.  Write a program that asks for an integer and then prints all the integers from(and
    includeing) that value up to (and including) a value larger by 10.(That is, if the 
    input is 5, the output runs from 5 to 15).Be sure to separate each output value by 
    a space or tab or newline.
*/

#include <stdio.h>

int main(void)
{
    int n, m;

    printf("Please enter an integer:\n");
    scanf("%d", &n);
    m = n + 10;
    while ( n <= m)
    {
        printf("%d ", n);
        n++;
    }
    printf("\n");

    return 0;
}