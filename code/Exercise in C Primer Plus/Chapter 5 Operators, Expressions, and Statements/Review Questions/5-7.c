/* Review Questions 5-7.c */

/* 7. What will the following program print?
 * #include <stdio.h>
 * int main(void)
 * {
 *    char c1, c2;
 *    int diff;
 *    float num;
 *
 *    c1 = 'S';
 *    c2 = 'O';
 *    diff = c1 - c2;
 *    num = diff;
 *    printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num);
 *
 *    return 0;
 * }
 */

 #include <stdio.h>
 int main(void)
 {
    char c1, c2;
    int diff;
    float num;
 
    c1 = 'S';
    c2 = 'O';
    diff = c1 - c2;
    num = diff;
    printf("%c%c%c:%d %3.2f\n", c1, c2, c1, diff, num);
 
    return 0;
}

/* 7. Here is the output:
 *    SOS:4 4.00
 *
 *    The expression c1 - c2 has the same value as 'S' - 'O', which in ASCII is 83 - 79.
 */
