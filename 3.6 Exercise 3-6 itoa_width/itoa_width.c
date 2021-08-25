
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
void itob(int n,char s[],short base);
int reverse_width(char s[],int width);
void itoa_width(int n,char s[],short base,int width);


int main(void)
{
	int number;
	char str[MAXLINE];

 /*	number=-2345645; */
	
	number = -2147483648;

	
	printf("Integer %d printed as",number);    
	itoa(number,str);
	printf("\n DEC String:%s",str);

    itob(number,str,16);
    printf("\n HEX String:%s",str);

    itob(number,str,8);
    printf("\n OCT String:%s",str);

    itob(number,str,2);
    printf("\n BIN String:%s",str);

	itoa_width(number,str,10,16);
	printf("\n DEC String width:%s",str);

	return 0;
}

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

int reverse_width(char s[],int width)
{
	int i,j,len;
    char str_copy[MAXLINE];
    len = strlen(s)-1;

	for(i=0,j=len;i<j;i++,j--)
		str_copy[j]=s[i],str_copy[i]=s[j];    
    str_copy[len+1]='\0';

    for(i=0;i < width-len;i++)
        s[i] = ' ';
    
    for(j=0;i< width;i++,j++)
        s[i] = str_copy[j];
    
    s[i] = '\0';

    return 0;
}

void itob(int n,char s[],short base)
{
	int i,sign,temp;

	sign=n;	
	i = 0;

	do
	{
        temp = abs(n % base);
        if(16 == base && temp >= 10 && temp <= 15)
		    s[i++]= temp + 'A';
        else
            s[i++]= temp + '0';
	}while((n/=base)!=0);

    if(16 == base)
        s[i++]='x',s[i++]='0';
    else if(8 == base)
        s[i++]='0';
	
	if( sign < 0)
		s[i++]='-';

	s[i]='\0';

	reverse(s);
}

void itoa_width(int n,char s[],short base,int width)
{
	int i,sign,temp;

	sign=n;	
	i = 0;

	do
	{
        temp = abs(n % base);
        if(16 == base && temp >= 10 && temp <= 15)
		    s[i++]= temp + 'A';
        else
            s[i++]= temp + '0';
	}while((n/=base)!=0);

    if(16 == base)
        s[i++]='x',s[i++]='0';
    else if(8 == base)
        s[i++]='0';
	
	if( sign < 0)
		s[i++]='-';

	s[i]='\0';

	reverse_width(s,width);
}