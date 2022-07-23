/* Programming Exercises 5-4.c */

/*
4.  Write a program that asks the user to enter a height in centimeters and then displays the 
    height in centimeters and in feet and inches.Fractional centimeters and inches should
    be allowed,and the program should allow the user to continue entering heights until a
    nonpositive value is entered.A sample run should look like this:
    Enter a height in centimeters: 182
    182.0 cm = 5 feet, 11.7 inches
    Enter a height in centimeters (<=0 to quit): 168.7
    168.0 cm = 5 feet, 6.4
     inches
     Enter a height in centimeters (<=0 to quit): 0
     bye
*/

#include <stdio.h>

#define CM2FEET (30.48)
#define CM2INCH (2.54)

int main(void)
{
    float cm;
    int feet;
    float inch;

    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0)
    {
        feet = cm / CM2FEET;
        inch = (cm - feet * CM2FEET) / CM2INCH;
        printf("%.1f cm = %d feet, %.1f\ninches\n", cm, feet, inch);
        printf("Enter a height in centimeters(<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("bye\n");

    return 0;
}