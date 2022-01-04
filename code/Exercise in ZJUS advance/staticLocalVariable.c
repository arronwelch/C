#include <stdio.h>

int f1(void);
int f2(void);

int gAll;

int main(int argc, char const *argv[])
{
    f1();
    f1();
    f1();
    printf("\n");
    f2();
    f2();
    f2();
    return 0;
}

int f1(void)
{
    int normalLocalVariable = 0;
    static int all = 1;//special external variable
    //external variable address
    //static - local varaible access
    printf("&gAll=%p\n",&gAll);
    printf("&all=%p\n",&all);
    printf("&normalLocalVariable=%p\n",&normalLocalVariable);
    printf("in %s all = %d\n", __func__, all);
    all+= 2;
    printf("agn in %s all = %d\n", __func__, all);
    return all;
}

int f2(void)
{
    int all = 1;
    printf("in %s all = %d\n", __func__, all);
    all+= 2;
    printf("agn in %s all = %d\n", __func__, all);
    return all;
}