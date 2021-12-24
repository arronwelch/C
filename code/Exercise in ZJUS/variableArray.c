
#include <stdio.h>

int main()
{
    int x;
    double sum = 0;
    int cnt,cnt_index = 0;
    printf (" please input number cnt = ");
    scanf("%d", &cnt);

    if(cnt > 0)
    {
        int number[cnt];//C99 ONLY
        scanf("%d",&x);
        while (x != -1 && cnt_index < cnt)
        {
            number[cnt_index] = x;
            sum += x;
            cnt_index++;
            scanf("%d", &x);
        }
        int i;
        double average = sum / cnt_index;
        printf("average = %f \n", average);
        printf("bigger than average number is: ");
        for (i = 0; i < cnt_index; i++)
        {
            if (number[i] > average)
            {
                printf("%d ", number[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
