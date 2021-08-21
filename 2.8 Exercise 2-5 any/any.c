
/* 
 *  Exercise 2-5. 
 *  Write the function any(s1,s2), which returns the first location in a string s1
 *  where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 *  (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */

#include <stdio.h>

unsigned int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "Abc123.";
    char s2[] = "2c34b";

    printf("%s\n",s1);
    printf("%s\n",s2);

    printf("%s\n",s1+any(s1,s2));

    return 0;
}

/* any: return the first location in s1 from s2 */
unsigned int any(char s1[], char s2[])
{
    int i,j,k;
    char * cp;
    for(i = j =0;s1[i] != '\0'; i++)
    {
        for(k = 0; s2[k] != '\0' && s1[i] != s2[k];k++)
            ;
        if(s2[k] == s1[i])
            return i;
    }

    return -1;
}