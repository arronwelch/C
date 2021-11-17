
// void *memset(void *str, int c, size_t n)

#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];

    strcpy(str, "This is string.h library function");
    puts(str);

    memset(str, '$', 7);
    puts(str);

    int array[1024] = { [ 0 ... 1023 ] = -1 };
    for(int i=0;i<1024;i++)
        printf("%d:%d\n",i,array[i]);

    return 0;
}

//This is string.h library function
//$$$$$$$ string.h library function
