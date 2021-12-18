/* Modified version of itoa; to handle the situation of MIN_INT of limits.h
in the previous number = -2147483648 would fail at n =-n,because the max value of integer is 2147483647
modifying itoa to handle these situations. 
sign is stored as  the number itself, absolute value of each digit is stored in the string and 
while loop is tested not for 0
itoa: convert an integer to string */

#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

#define abs(x) ( (x) > 0 ? (x): -(x))

void itoa(int n,char s[]);
void reverse(char s[]);


int main(void)
{
    int number;
    char str[MAXLINE];

 /*	number=-2345645; */
    
    number = -2147483648;

    
    printf("Integer %d printed as\n String:",number);

    itoa(number,str);

    printf("%s",str);

    return 0;
}

// /* itoa: convert n to characters in s */
// void itoa(int n, char s[])
// {
//     int i, sign;
//     if ((sign = n) < 0)  /*record sign */
//         n = -n;          /* make n positive */
// 		printf("n = %d \n",n);
//     i = 0;
//     do {  /* generate digits in reverse order */
//         s[i++] = n % 10 + '0';  /* get next digit */
// 		printf("s[%d] = %d \n",i-1,s[i]);
//     } while (( n /= 10) > 0);   /* delete it */

//     if (sign < 0)
//         s[i++] = '-';
// 	printf("s[%d] = %d \n",i-1,s[i-1]);
//     s[i] = '\0';
// 	printf("s[%d] = %d \n",i,s[i]);
//     reverse(s);
// }

void itoa(int n,char s[])
{
    int i,sign;

    sign=n;	

    i = 0;

    do
    {
        s[i++]= abs(n%10) + '0';
    
    }while((n/=10)!=0);
    
    if( sign < 0)
        s[i++]='-';

    s[i]='\0';

    reverse(s);
}

void reverse(char s[])
{
    int c,i,j;

    for(i=0,j=strlen(s)-1;i<j;i++,j--)
        c=s[i],s[i]=s[j],s[j]=c;
}
