
/**
 * #define cube(x) ((x)*(x)*(x))
 * */

#include <stdio.h>

#define cube(x) ((x) * (x) * (x))
#define RADTODEG1(x) (x * 57.29578)
#define RADTODEG2(x) (x) * 57.29578
#define RADTODEG(x) ((x)*57.29578)

#define MAX(a, b) ((a)<(b)?((b):(a)))
#define MIN(a, b) ((a)>(b)?((b):(a)))

//# ##
#define paste(front,back) front ## back

#define tempfile(dir) #dir "%s"

#define cat(x,y) x ## y
#define xcat(x,y) cat(x,y)

int main(void)
{
    // printf("%d\n",cube(5));
    int i;
    scanf("%d", &i);
    printf("%d\n", cube(i));
    printf("%d\n", cube(i + 2));

    printf("%f\n", RADTODEG1(5 + 2));
    printf("%f\n", 180 / RADTODEG2(1));

    printf("%f\n", RADTODEG(5 + 2));
    printf("%f\n", 180 / RADTODEG(1));

    char name1[] = "paste" "front";
    printf("%s\n", paste(name,1));

    printf(tempfile(/usr/temp) "\n",__FILE__);

    int var123 = 123;
    printf("%d\n",cat(var,123));
    printf("%d\n",xcat(xcat(var1,2),3));

    return 0;
}
