/* Review Questions 5-8.c */

/* 8. What will this program print?
 *    #include <stdio.h>
 *    #define TEN 10
 *    int main(void)
 *    {
 *       int n = 0;
 *       while (n++ < TEN)
 *           printf("%5d", n);
 *       printf("\n");
 *
 *       return 0;
 *    }
 */

#include <stdio.h>
#define TEN 10
int main(void)
{
   int n = 0;
   while (n++ < TEN)
       printf("%5d", n);
   printf("\n");

   return 0;
}

/* 8. It prints on one line the digits 1 through 10 in fields that are five columns wide and 
 *    then starts a new line:
 *    1    2    3    4    5    6    7    8    9   10
 */
