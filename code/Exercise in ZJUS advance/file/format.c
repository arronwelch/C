
/**
 * printf
 * %[flag][width][.prec][hlL]type
 * scanf
 * %[flag][type]
 *
 * */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%9d\n", 123);
    printf("%+9d\n", 123);  // sign
    printf("%+9d\n", -123); // sign
    printf("%09d\n", 123);  // leading zeros instead of with spaces.
    printf("%-9d\n", -123); // beginning at the left
    printf("% 9d\n", 123);  // leading space(no sign) if positive
    printf("% 9d\n", -123); // leading space(with a minus sign) if negative
    printf("%#o\n", 0123);
    printf("%#x\n", 0x1FC);
    printf("%#X\n", 0x1FC);
    printf("%#8.0f\n", 1.0);

    printf("%*.3f\n", 9, 1.0); // width == 9
    printf("%9.*f\n", 3, 1.0); //.prec == 3

    printf("%hhd\n", 12345);   // 0x3039 -> 0x39 (57dec)  "char"
    printf("%hhd\n", (char)12345);   // 0x3039 -> 0x39 (57dec)  "char"
    printf("%hd\n", 12345);    // "short"
    printf("%ld\n", 12345L);   // "long"
    printf("%lld\n", 12345LL); // "long long"
    printf("%Lf\n", 12345.0);  // "double"
    printf("%Lf\n", 12345.0L); // "long double"
    
    printf("%.3g\n", 12345.6); // "long double"

    int num = 0;
    printf("%d%n\n",123,&num);
    printf("num=%d\n",num);

    printf("%d45%n\n",123,&num);
    printf("num=%d\n",num);

    int var_cnt = scanf("%*d%d",&num);
    int char_cnt = printf("num=%d\n",num);
    printf("%d:%d\n",var_cnt,char_cnt);

    return 0;
}