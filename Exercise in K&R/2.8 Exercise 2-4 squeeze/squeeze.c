
/* 
 * Exercise 2-4. 
 * Write an alternative version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in the string s2.
 */


#include <stdio.h>

void squeeze1(char s[], int c);
void squeeze2(char s1[],char s2[]);

int main(void)
{
    char s1[] = "Abc123.";
    char s2[] = "2c";
    squeeze1(s1,'1');
    printf("%s\n",s1);

    squeeze2(s1,s2);
    printf("%s\n",s1);

    return 0;
}

/* squeeze1: delete all c from s */
void squeeze1(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze2: delete all char in s1 from s2 */
void squeeze2(char s1[],char s2[])
{
    int i, j, z;
    unsigned int isSame = 0;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        for(z = 0; s2[z] != '\0'; z++ ) 
        {
            if(s1[i] == s2[z])
            {
                isSame = 1;
                break;
            }                
            else
                isSame = 0;
        }
        if(isSame == 0)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}