
/* Exersice 4-13 :
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place
 */

#include <stdio.h>
#include <string.h>

#define MAXLNE 1000

int mgetline(char line[],int maxline);
void reverse(char s[]);

int main(void)
{
    char s[MAXLNE];

	printf("Enter a string to reverse: ");
    mgetline(s,MAXLNE);
    reverse(s);
    printf("%s\n",s);

    return 0;
}

int mgetline(char line[],int maxline)
{
    int i,c;

    for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c!= '\n';++i)
        line[i] = c;
    
    if( '\n' == c)
        line[i++] = '\n';
    
    line[i] = '\0';
}

void reverse(char s[])
{
    void reverser(char s[], int i, int len);

    reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place */
void reverser(char s[],int i, int len)
{
    int c,j;

    j = len - (i+1);

    if(i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverser(s,++i,len);
    }
}
