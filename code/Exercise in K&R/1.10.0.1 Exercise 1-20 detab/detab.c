#include <stdio.h>

#define TABNUM 8

int main()
{
  int c;
  unsigned int spaceCount;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      spaceCount = TABNUM;

      while (spaceCount)
      {
        putchar('.');//replace ' ' for display space
        --spaceCount;
      }
    }
    else
    {
      putchar(c);
    }
  }

  return 0;
}