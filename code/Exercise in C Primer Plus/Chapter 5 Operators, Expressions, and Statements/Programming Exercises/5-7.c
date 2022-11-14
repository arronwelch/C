/* Programming Exercises 5-7.c */

/*
7.	Write a program that requests a type double number and prints the value of the number
	cubed. Use a function of your own design to cube the value and print it.The main()
	program should pass the entered value to this function.
*/

#include <stdio.h>

double my_cube(double val)
{
	return val*val*val;
}

int main(void)
{
	double input, output;

	printf("Enter a number to cube: \n");
	scanf("%lf", &input);
	output = my_cube(input);
	printf("%lf cubed is %lf\n", input, output);

	return 0;
}
