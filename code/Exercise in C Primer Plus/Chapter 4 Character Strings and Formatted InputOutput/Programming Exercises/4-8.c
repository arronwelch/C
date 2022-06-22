/* Programming Exercises 4.8 */

// Write a program that asks the user to enter the number of miles traveled and the number
// of gallons of gasoline consumed. It should then calculate and display the miles-per-gallon
// value, showing one place to the right of the decimal. Next, using the fact that one gallon
// is about 3.785 liters and one mile is about 1.609 kilometers, it should convert the mile-
// per-gallon value to a liters-per-100-km value, the usual European way of expressing fuel
// consumption, and display the result, showing one place to the right of the decimal. Note
// that the U.S. scheme measures the distance traveled per amount of fuel (higher is better),
// whereas the European scheme measures the amount of fuel per distance (lower is better).
// Use symbolic constants (using const or #define) for the two conversion factors.

#include <stdio.h>

#define GALLON 3.785
#define MILE 1.609

int main(void)
{
	float miles, gallons, miles_per_gallon, liters_per_100_km;

	printf("Please enter the number of miles traveled\n");
	scanf("%f", &miles);
	printf("and the number of gallons of gasoline consumed.\n");
	scanf("%f", &gallons);

	miles_per_gallon = miles / gallons;
	printf("the miles-per-gallon value is %.1f\n", miles_per_gallon);

	liters_per_100_km = gallons * GALLON / ( miles * MILE * 100);
	printf("the liters-per-100-km is %.1f\n", liters_per_100_km);

	return 0;
}
