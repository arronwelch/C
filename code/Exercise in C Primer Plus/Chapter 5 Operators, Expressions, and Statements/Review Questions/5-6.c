/* Review Questions 5-6.c */

/*
 * 6. What will this program print?
 *    #include <stdio.h>
 *    #define FORMAT "%s! C is cool!\n"
 *    int main(void) {
 *        int num = 10;
 *        printf(FORMAT, FORMAT);
 *        printf("%d\n", ++num);
 *        printf("%d\n", num++);
 *        printf("%d\n", num--);
 *        printf("%d\n", num);
 *
 *        return 0;
 *    }
 */

 #include <stdio.h>
 #define FORMAT "%s! C is cool!\n"
 int main(void) {
     int num = 10;
     printf(FORMAT, FORMAT);
     printf("%d\n", ++num);
     printf("%d\n", num++);
     printf("%d\n", num--);
     printf("%d\n", num);

     return 0;
 }

/*
 * 6. Here is the output:
 *     %s! C is cool!
 *     ! C is cool!
 *     11
 *     11
 *     12
 *     11
 *
 *    Let's explain. The first printf() statement is the same as this:
 *    printf("%s! C is cool!\n", "%s! C is cool!\n");
 *    The second print statement first increment num to 11 and then prints the value. The
 *    third print statement prints num, which is 11, and then increment it to 12. The fourth
 *    print statement prints the current value of num, which still 12, and then decrements num
 *    to 11. The final print statement prints current value of num, which is 11.
 */
