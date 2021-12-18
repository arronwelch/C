
/* review C language
   Exercise 2 print Fahrenheit-Celsius table
   2021-08-02 */

#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0,20,...,300 */

void Fahr2Celsius(void);
void Celsius2Fahr(void);
void Fahr2CelsiusFor(void);
void Fahr2CelsiusForReverse(void);
void Fahr2CelsiusForDefine(void);

int main()
{
    // printf("\n[Run Fahr2Celsius()]\n");
    // Fahr2Celsius();
    // printf("\n[Run Celsius2Fahr()]\n");
    // Celsius2Fahr();
    // printf("\n[Run Fahr2CelsiusFor()]\n");
    // Fahr2CelsiusFor();
    // printf("\n[Run Fahr2CelsiusForReverse()]\n");
    // Fahr2CelsiusForReverse();
    printf("\n[Run Fahr2CelsiusForDefine()]\n");
    Fahr2CelsiusForDefine();
}

void Fahr2Celsius(void)
{
    // int fahr,celsius;
    // int lower,upper,step;

    float fahr,celsius;// To get more accurate answers , use floating-point arithmetic instead of integer
    float lower,upper,step;

    lower = 0;       /* lower limit of temperature scale */ 
    upper = 300;     /* upper limit */  
    step = 20;       /* step size */

    fahr = lower;
    printf("fahr\tcelsius\n",fahr,celsius);
    while (fahr <= upper) {// The position of braces is less
                           // important, although people hold passionate beliefs.
        // celsius = 5 * (fahr-32) / 9;
        // celsius = (5/9) * (fahr-32.0);//this is an incorrect statement!!!
        celsius = (5.0/9.0) * (fahr-32.0);//more natural way
        // printf("%d\t%d\n",fahr,celsius);// with each % indicating where one of the other (second, 
                                           // third, ...) arguments is to be substituted, and in what form it is to be printed. 
        // printf("%3d\t%6d\n",fahr,celsius);// printf statement with a width.
        // printf("%3.0f\t%6.1f\n",fahr,celsius);
        printf("%6.2f\t%6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
}

void Celsius2Fahr(void)
{
    float fahr,celsius;// To get more accurate answers , use floating-point arithmetic instead of integer
    float lower,upper,step;

    lower = 0;       /* lower limit of temperature scale */ 
    upper = 300;     /* upper limit */  
    step = 20;       /* step size */

    celsius = lower;
    printf("celsius\tfahr\n",fahr,celsius);
    while (celsius <= upper) {// The position of braces is less
                           // important, although people hold passionate beliefs.
        // celsius = 5 * (fahr-32) / 9;
        // celsius = (5/9) * (fahr-32.0);//this is an incorrect statement!!!
        //celsius = (5.0/9.0) * (fahr-32.0);//more natural way
        fahr = celsius * (9.0/5.0) + 32.0;
        // printf("%d\t%d\n",fahr,celsius);// with each % indicating where one of the other (second, 
                                           // third, ...) arguments is to be substituted, and in what form it is to be printed. 
        // printf("%3d\t%6d\n",fahr,celsius);// printf statement with a width.
        // printf("%3.0f\t%6.1f\n",fahr,celsius);
        // printf("%6.2f\t%6.1f\n",fahr,celsius);
        printf("%6.1f\t%6.2f\n",celsius,fahr);
        celsius = celsius + step;
    }
}

/* print Fahrenheit-Celsius table */
void Fahr2CelsiusFor(void)
{
    int fahr;

    printf("fahr\tcelsius\n");
    for (fahr = 0; fahr <= 300;fahr = fahr + 20)
        printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32));
}

/* print Fahrenheit-Celsius table */
void Fahr2CelsiusForReverse(void)
{
    int fahr;

    printf("fahr\tcelsius\n");
    for (fahr = 300; fahr >= 0;fahr = fahr - 20)
        printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32));
}

/* print Fahrenheit-Celsius table */
#define LOWER     0    /* lower limit of table */ 
#define UPPER     300  /* upper limit */ 
#define STEP      20   /* step size */
void Fahr2CelsiusForDefine(void)
{
    int fahr;

    printf("fahr\tcelsius\n");
    for (fahr = LOWER; fahr <= UPPER;fahr = fahr + STEP)
        printf("%3d %6.1f\n",fahr, (5.0/9.0)*(fahr-32));
}