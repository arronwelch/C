/* Review Questions 5-4.c */

/*
 * 4. You suspect that there are some errors in the next program. Can you find them?
 * 1 int main(void)
 * 2 {
 * 3  int i = 1;
 * 4   float n;
 * 5   printf("Watch out! Here come a bunch of fractions!\n");
 * 6   while ( i < 30 )
 * 7    n = 1/i;
 * 8    printf(" %f", n);
 * 9   printf("That's all, folks!\n");
 * 10  return;
 * 11 }
 */

#include <stdio.h>	// Line 0: Should include <stdio.h>

 int main(void)
 {
   int i = 1;		// Line 3: Should end in a semicolon, not a comma.
   float n;
   printf("Watch out! Here come a bunch of fractions!\n");
   while ( i++ < 30 )
/* Line 6: The while statement sets up an infinite loop because the value of i remains 1 
 * and is always less than 30. Presumably, we meant to write while(i++ < 30).
 */
   {
     n = 1.0/i;
     printf(" %f\n", n);
   }
/* Line 6-8: The indentation implies that we wanted lines 7 and 8 to form a block, but the
 * lack of braces means that the while loop include only line 7.Brace should be added.
 */

/* Line 7: Because 1 and i are both integers, the result of the division will be 1 when i is 1,
 * and 0 for all large values. Using n = 1.0 / i; Would cause i to be converted to floating 
 * point before division and would yield nonzero answers.
 */
   printf("That's all, folks!\n");
/* Line 8: We omitted a newline character (\n) in the control statement.This causes the 
 * numbers to be printed on one line, if possible.
 *
 */
   return 0;		// Line 10: should be return 0;
 }
