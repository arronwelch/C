
#include <stdio.h>

int main(void)
{
    //first new:
    printf("first new:\n");
    int a = 10;
    printf("%i\n", a); //d,i: int; decimal number

    //second new:
    printf("\nsecond new:\n");
    printf("%o\n", 12);//o: int; unsigned octal number(without a leading zero)
    printf("%o\n", 012);//o: int; unsigned octal number(without a leading zero)

    //third new:
    printf("\nthird new:\n");
    printf("%x:%X\n",10,10);//x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15
    printf("%x:%X\n",010,010);//x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15
    printf("%x:%X\n",0x10,0X10);//x,X: int; unsigned hexadecimal number(without a leading 0x or 0X),using abcdef or ABCDEF for 10, ... ,15

    //4th new:
    printf("\n4th new:\n");
    printf("%u\n",-10);
    printf("%u\n", 10);
    printf("%u\n", 010);
    printf("%u\n", 0x10);

    return 0;
}