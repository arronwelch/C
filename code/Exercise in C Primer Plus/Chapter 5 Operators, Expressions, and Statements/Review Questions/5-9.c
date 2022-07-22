/* Review Questions 5-9.c */

/* 9. Modify the last program so that it prints the letters a through g instead.
 */

// #include <stdio.h>
// #define TEN 6
// int main(void)
// {
//    int n = -1;
//    while (n++ < TEN)
//        printf("%5c", n + 'a');
//    printf("\n");
// 
//    return 0;
// }

#include <stdio.h>

int main(void)
{
	char ch = 'a';
	while(ch <= 'g')
		printf("%5c", ch++);
	printf("\n");

	return 0;
}

/* 9. Here is one possibility, which assumes that the letters are coded consecutively, as is the
      case for ASCII:
    a    b    c    d    e    f    g
 */
