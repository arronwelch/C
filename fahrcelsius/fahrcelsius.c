
/* review C language
   Exercise 2 print Fahrenheit-Celsius table
   2021-08-02 */

#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0,20,...,300 */
int main()
{
    // int fahr,celsius;
    // int lower,upper,step;

    float fahr,celsius;// To get more accurate answers , use floating-point arithmetic instead of integer
    float lower,upper,step;

    lower = 0;       /* lower limit of temperature scale */ 
    upper = 300;     /* upper limit */  
    step = 20;       /* step size */

    fahr = lower;
    while (fahr <= upper) {// The position of braces is less
                           // important, although people hold passionate beliefs.
        // celsius = 5 * (fahr-32) / 9;
        // celsius = (5/9) * (fahr-32.0);//this is an incorrect statement!!!
        celsius = (5.0/9.0) * (fahr-32.0);//more natural way
        // printf("%d\t%d\n",fahr,celsius);// with each % indicating where one of the other (second, 
                                           // third, ...) arguments is to be substituted, and in what form it is to be printed. 
        // printf("%3d\t%6d\n",fahr,celsius);// printf statement with a width.
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
}
