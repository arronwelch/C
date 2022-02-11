
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
    for(int i=0; s[i] != '\0';i++,cnt++)
    {
        substr[cnt] = s[i];
        for(int j=0;j<cnt;j++)
        {
            if(substr[cnt] == substr[j])
            {
                cnt = 0;
                substr[cnt] = s[i];
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
2016637367
79784533
198243628
12265700
631875103
56966682

*/