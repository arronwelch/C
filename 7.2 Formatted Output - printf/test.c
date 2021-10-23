
#include <stdio.h>

int main(void)
{
    //first new:
    printf("first new:\n");
    int a = 10;
    printf("%i\n", a); //d,i: int; decimal number

    //second new:
    printf("\nsecond new:\n");
    printf("%o\n", 12);  //o: int; unsigned octal number(without a leading zero)
    printf("%o\n", 012); //o: int; unsigned octal number(without a leading zero)

    //third new:
    printf("\nthird new:\n");
    printf("%x:%X\n", 10, 10);     //x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15
    printf("%x:%X\n", 010, 010);   //x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15
    printf("%x:%X\n", 0x10, 0X10); //x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15

    //4th new:
    printf("\n4th new:\n"); //u: int; unsigned decimal number
    printf("%u\n", -10);
    printf("%u\n", 10);
    printf("%u\n", 010);
    printf("%u\n", 0x10);

    //5th new:
    printf("\n5th new:\n");
    printf("%c\n", 'A'); //c: int;single character
    printf("%c\n", 65);  //c: int;single character

    //6th new:
    printf("\n6th new:\n");
    printf("%s\n", "string or char *;");   //s: char *;print characters from the string until a '\0' or the number of characters given by the precision.
    printf("%.4s\n", "string or char *;"); //s: char *;print characters from the string until a '\0' or the number of characters given by the precision.

    //7th new:
    printf("\n7th new:\n");
    printf("%f\n", 1.234);     //f: double; [-]m.dddddde, where the number of d's is given by the precision(default 6).
    printf("%f\n", -1.234);    //f: double; [-]m.dddddde, where the number of d's is given by the precision(default 6).
    printf("%f\n", -1.234e-5); //f: double; [-]m.dddddde, where the number of d's is given by the precision(default 6).

    //8th new:
    printf("\n8th new:\n");
    printf("%e\n", 1.123e-5);  //e,E: double; [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision(default 6).
    printf("%e\n", -1.123e-5); //e,E: double; [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision(default 6).
    printf("%e\n", -1.123e+5); //e,E: double; [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision(default 6).
    printf("%e\n", -1.123E+5); //e,E: double; [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision(default 6).
    printf("%E\n", -1.123e+5); //e,E: double; [-]m.dddddde+/-xx or [-]m.ddddddE+/-xx, where the number of d's is given by the precision(default 6).

    //9th new:
    printf("\n9th new:\n");
    printf("%g\n", 1.23456);     //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%g\n", 1.234560);    //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%g\n", 1.23456e-5);  //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%g\n", 1.234560e-5); //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%g\n", 1.23456e-4);  //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%g\n", 1.234560e-4); //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%G\n", 1.234560e-4); //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.
    printf("%G\n", 1.234560e-5); //g,G: double; use %e or %E if the exponent is less than -4 or greater than or equal to the precision;otherwise use %f;Trailing zeros and a trailing decimal point are not printed.

    //10th new:
    printf("\n10th new:\n");
    void *p;
    printf("%p\n",p);//p: void *; pointer(implementation-dependent representation).
    char *mypc;
    printf("%p\n",mypc);//p: void *; pointer(implementation-dependent representation).
    int *mypi;
    printf("%p\n",mypi);//p: void *; pointer(implementation-dependent representation).
    double *mypf;
    printf("%p\n",mypf);//p: void *; pointer(implementation-dependent representation).

    //11th new:
    printf("\n11th new:\n");
    printf("%%\n");//%: no argument is converted;print a %

    return 0;
}