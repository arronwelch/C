#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a = 0x80000000;
    unsigned int b = 0x80000000;

    printf("a=%x\n", a);
    printf("b=%x\n", b);
    printf("a>>1 = %x\n", a >> 1);
    printf("b>>1 = %x\n", b >> 1);

    return 0;
}