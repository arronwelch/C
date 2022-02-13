
#include <stdio.h>
#include <string.h>

#define MAX_LEN (50000+1)
int lengthOfLongestSubstring(char * s);

int main(void)
{
    // char s[] = "";
    char s[] = "dvdf";

    // char s[MAX_LEN] = {0};
    // while(scanf("%s",s))
        printf("%d",lengthOfLongestSubstring(s));

    return 0;
}

// original:
// #define MAX_LEN (50000+1)
// int lengthOfLongestSubstring(char * s)
// {
//     int max=0,cnt = 0;
//     char substr[MAX_LEN] = {0};
//     for(int i=0; s[i+cnt] != '\0';cnt++)
//     {
//         substr[cnt] = s[i+cnt];
//         for(int j=0;j<cnt;j++)
//         {
//             if(substr[cnt] == substr[j])
//             {
//                 cnt = 0;
//                 substr[cnt] = s[i+cnt];
//                 i++;
//                 cnt--;
//                 break;
//             }
//         }
//         if(cnt > max)
//             max = cnt;
//     }
//     if(s[0] == '\0')
//         return 0;
//     else
//         return max+1;
// }

//3. Longest Substring Without Repeating Characters
//Given a string s, find the length of the longest substring without repeating characters.
// rebuilding with sliding window
int lengthOfLongestSubstring(char * s){
    int left = 0, right = 0;// sliding window initialization
    int max = 0;

    int len = strlen(s);
    if( len == 0 || len == 1 )
        return len;

    while(s[right+1] != '\0')
    {
        right++;//right shift
        for (int i = left; i < right; i++)
        {
            if(s[i] == s[right])
            {
                left = i + 1;//right shift
                break;
            }
        }
        if(right-left+1 > max)
            max = right - left + 1;
    }

    return max;
}


// rebuilding with sliding window & hash
//

/*
人生的每一天都是独一无二的，爱生活，爱自己，其实就是每天简简单单的吃饭睡觉，刷刷洗洗；
不在乎别人的眼光，勇往直前；
每天给父母打个电话；

leetcode网上面的练习，对应题目编号如下：
字符串：3，49，30
线性表：86，16，27，732
队列：641，406，899
栈：143，331，445
哈希表：17，36，128
dfs：105，112，98，494，547，1254
bfs：1091，1129，102，101，752
上面困难等级的题目先不做，把简单和中等题目做完
注意：练习题目在力扣网上做，正式机考在牛客网上。
两个网站的编程题形式有差别，牛客网需要自己构造输入和输出。
*/