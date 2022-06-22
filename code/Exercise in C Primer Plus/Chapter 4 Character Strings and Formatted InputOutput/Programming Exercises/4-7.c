/* Programming Exercises 4.7 */

// Write a program that sets a type double variable to 1.0/3.0 and a type float variable
// to 1.0/3.0. Display each result three times --- once showing four digits to the right of the
// decimal, once showing 12 digits to the right of the decimal, and once showing 16 digits
// to the right of the decimal. Also have the program include float.h and display the 
// value of FLT_DIG and DBL_DIG. Are the displayed values of 1.0/3.0 consistent with these
// values?

#include <stdio.h>
#include <float.h>

int main(void)
{
	float flt= 1.0/3.0;
	double dbl = 1.0/3.0;

	printf("In your system FLT_DIG = %d\n", FLT_DIG);
	printf("In your system DBL_DIG = %d\n", DBL_DIG);

	printf("flt in  4 digit = %.4f\n", flt);
	printf("flt in 12 digit = %.12f\n", flt);
	printf("flt in 16 digit = %.16f\n", flt);

	printf("dbl in  4 digit = %.4f\n", dbl);
	printf("dbl in 12 digit = %.12f\n", dbl);
	printf("dbl in 16 digit = %.16f\n", dbl);

	return 0;
}
