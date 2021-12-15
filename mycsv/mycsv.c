
#include <stdio.h>

int main()
{
    FILE *fp = fopen("mydata.csv", "w");
    printf("16 Bit:\n\n");

    for (int n = 0; n < 4; n++)
        fprintf(fp, "%10.4d\t %.4x %.4x\n", n, n + 1, n + 2);

    return 0;
}