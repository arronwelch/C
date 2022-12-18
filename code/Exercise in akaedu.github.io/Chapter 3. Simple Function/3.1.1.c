/* Chapter 3. Simple Function */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double pi = 3.1416;
	printf("sin(pi/2)=%f\nln1=%f\n", sin(pi/2), log(1.0));
	return 0;
}

/*
 * $ gcc main.c -lm
 * $ ./a.out
 * $ sin(pi/2)=1.000000
 * $ ln1=0.000000
 */
