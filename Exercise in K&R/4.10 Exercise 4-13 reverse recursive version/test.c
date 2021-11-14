
/* Exersice test code
 *  
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int mgetline(char line[],int maxline);
void reverse(char str[]);
void reverse_inplace(char str[], int begin, int end);
void swap(char s[],int i,int j);

int main(void)
{
    char str[MAXLEN];

    printf("Enter a string to reverse:");
    //scanf("%s", str);//ERR ??? end until encountering whitespace, newline or EOF
    /* Test string:Are you OK ?*/
    mgetline(str,MAXLEN);
    reverse(str);
    printf("%s\n",str);

    return 0;
}

/* mgetline: get one input line */
int mgetline(char line[],int maxline)
{
    int i,c;

    for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c!= '\n';++i)
        line[i] = c;
    
    if( '\n' == c)
        line[i++] = '\n';
    
    line[i] = '\0';
}

/* reverse: interface function to reverse_inplace */
void reverse(char str[])
{
    reverse_inplace(str,0,strlen(str)-1);
}

/* reverse_inplace: reverse string s in place,recursive version */
void reverse_inplace(char str[], int begin, int end)
{
    if (begin >= end) /* exit condition */
        return;
    swap(str, begin, end);
    reverse_inplace(str,++begin,--end);
}

/* swap: interchange s[i] and s[j] */
void swap(char str[],int i,int j)
{
    char c;

    c      = str[i];
    str[i] = str[j];
    str[j] = c;
}
