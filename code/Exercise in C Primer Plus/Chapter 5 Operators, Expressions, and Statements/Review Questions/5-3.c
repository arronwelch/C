/* Review Questions 5-3.c */

/*
 * 3. Evaluate each of the following expressions:
 *       a. 30.0 / 4.0 * 5.0;
 *       b. 30.0 / (4.0 * 5.0);
 *       c. 30 / 4 * 5;
 *       d. 30 * 5 / 4;
 *       e. 30 / 4.0 * 5;
 *       f. 30 / 4 * 5.0;
 */

#include <stdio.h>

int main(void)
{
	printf("%f\n", 30.0 / 4.0 * 5.0  );
	printf("%f\n", 30.0 / (4.0 * 5.0));
	printf("%d\n", 30 / 4 * 5        );
	printf("%d\n", 30 * 5 / 4        );
	printf("%f\n", 30 / 4.0 * 5      );
	printf("%f\n", 30 / 4 * 5.0      );

	return 0;
}
