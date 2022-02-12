
#include <stdio.h>
#define MAX_LEN (50000+1)
int lengthOfLongestSubstring(char * s);

int main(void)
{
    char s[] = "dvdf";
    // char s[MAX_LEN] = {0};
    // while(scanf("%s",s))
        printf("%d",lengthOfLongestSubstring(s));

    return 0;
}

#define MAX_LEN (50000+1)
int lengthOfLongestSubstring(char * s)
{
    int max=0,cnt = 0;
    char substr[MAX_LEN] = {0};
    for(int i=0; s[i+cnt] != '\0';cnt++)
    {
        substr[cnt] = s[i+cnt];
        for(int j=0;j<cnt;j++)
        {
            if(substr[cnt] == substr[j])
            {
                cnt = 0;
                substr[cnt] = s[i+cnt];
                i++;
                cnt--;
                break;
            }
        }
        if(cnt > max)
            max = cnt;
    }
    if(s[0] == '\0')
        return 0;
    else
        return max+1;
}

/*
人生的每一天都是独一无二的，爱生活，爱自己，其实就是每天简简单单的吃饭睡觉，刷刷洗洗；
不在乎别人的眼光，勇往直前；
每天给父母打个电话；
*/