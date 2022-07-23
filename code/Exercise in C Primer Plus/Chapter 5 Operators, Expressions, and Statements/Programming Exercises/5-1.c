/* Programming Exercises 5-1.c */

/*
1.	Write a program that converts time in minutes to time in hours and minutes.Use
	#define or const to create a symbolic constant for 60.Use a while loop to allow the
	user to enter values repeatedly and terminate the loop if a value for the time of 0 
	or less is entered.
*/

#include <stdio.h>
#define M_TO_H 60

int main(void)
{
	int min;	// time in minutesC
	int hour;
	int left;
	printf("This program converts minutes to hours and minutes.\n");
	printf("Just enter the number of minutes.\n");
	printf("Enter 0 or less to end the program.\n");
	scanf("%d", &min);
	while(min > 0)
	{
		hour = min / M_TO_H;
		left = min % M_TO_H;
		printf("%d min is %d hour, %d min.\n", min, hour, left);
		printf("Next input?\n");
		scanf("%d", &min);
	}
	printf("Bye!\n");

	return 0;
}
