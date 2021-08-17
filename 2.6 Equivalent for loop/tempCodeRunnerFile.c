#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int mgetline(char line[],int lim);
void copy(char to[],char from[]);


int main(void)
{
    int len,max;
    char line[MAXLINE],maxline[MAXLINE];

    max =0;

    while((len=mgetline(line,MAXLINE)) > 0)