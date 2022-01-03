
#include <stdio.h>

typedef union
{
    int i;
    char ch[sizeof(int)];
} CHI;

int main()
{
    CHI chi;
    size_t i;
    chi.i = 0x12345678;

    printf("X86 is littile endian:\n");
    for (i = 0; i < sizeof(int); i++)
    {
        printf("%p:0x%02hhX\n", &chi.ch[i], chi.ch[i]);
    }
    printf("\n");

    /*
    X86 is littile endian:
        0x7fffffffdc14:0x78
        0x7fffffffdc15:0x56
        0x7fffffffdc16:0x34
        0x7fffffffdc17:0x12
     */

    return 0;
}
