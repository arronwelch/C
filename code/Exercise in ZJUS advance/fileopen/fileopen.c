#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *fp = fopen("12.in", "r");
    if (fp)
    {
        int num;
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        fclose(fp);
    }
    else
    {
        printf("Can't Open File!\n");
    }

    return 0;
}
