/* Programming Exercises 5-9.c */

/*
9.	Write a program that requests the user to enter a Fahrenheit temperature. The program
	should read the temperature as a type double number and pass it as an argument to
	a user-supplied function called Temperatures(). This function should calculate the
	Celsius equivalent and the Kelvin equivalent and display all three temperatures with a
	precision of two places to the right of the decimal. It should identify each value with the
	temperature scale it represents. Here is the formula for converting Fahrenheit to Celsius:
	Celsius = 5.0 / 9.0 * (Fahrenheit - 32.0)
	The Kelvin scale, commonly used in science, is s scale in which 0 represents absolute
	zero, the lower limit to possible temperatures. Here is the formula for converting Celsius
	to Kelvin:
	Kelvin = Celsius + 237.16
	The Temperatures() function should use const to create symbolic representations of
	the three constants that appear in the conversions. The main() function should use
	a loop to allow the user to enter temperatures repeatedly, stopping when a q or other
	nonnumeric value is entered. Use the fact that scanf() returns the number of items
	read, so it will return 1 if it reads a number, but it won't return 1 if the user enters q.The
	== operator tests for equality, so you can use it to compare the return value of scanf()
	with 1.
*/

#include <stdio.h>

void Temperatures(double Fahrenheit)
{
	double Celsius, Kelvin;
	const double K1 = 5.0 / 9.0;
	const double K2 = 32.0;
	const double K3 = 273.16;

	Celsius = K1 * (Fahrenheit - K2);
	Kelvin = Celsius + K3;
	printf("%-10s | %-10s | %-10s\n","Fahrenheit", "Celsius", "Kelvin");
	printf("%-10.2lf | %-10.2lf | %-10.2lf\n", Fahrenheit, Celsius, Kelvin);
}

int main()
{
	double Fahrenheit;
	printf("Enter a Fahrenheit temperature: ");

	// scanf return the number of successful converted and assigned
	while(scanf("%lf", &Fahrenheit) == 1)
	{
		Temperatures(Fahrenheit);
		printf("Enter a Fahrenheit temperature: ");
	}
	printf("Done\n");
}
