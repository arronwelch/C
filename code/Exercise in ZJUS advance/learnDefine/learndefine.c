#include <stdio.h>

// const double PI = 3.14159;
#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2*PI // pi * 2

#define PRT printf("%f\n",PI); \
            printf("%f\n",PI2)

#define _DEBUG //no value MACRO, USE in condition compile

/*
 * __LINE__ //source file current line number
 * __FILE__ //source file'name
 * __DATE__ //compile date
 * __TIME__ //compile time
 * __STDC__
 **/

int main(void)
{
    // printf("%f\n",2*PI*3.0);
    // printf(FORMAT,2*PI*3.0);
    // PRT;
    printf("%s:%d\n",__FILE__,__LINE__);
    printf("%s:%s:%d\n",__DATE__,__TIME__,__STDC__);
    return 0;
}