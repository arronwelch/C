#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s) {
	int left = 0, right = 0;
	int max = 0;

	int len = strlen(s);
	if ( len == 0 || len == 1)
		return len;

	while(s[right+1] != '\0')
	{
		right++;
		for (int i = left; i < right; i++)
		{
			if (s[i] == s[right])
			{
				left = i + 1;
				break;
			}
		}
		if ( right - left + 1 > max)
			max = right - left + 1;
	}
	return max;
}

int main()
{
	char *s1 = "abcabcbb";
	char *s2 = "bbbbb";
	char *s3 = "pwwkew";
	printf("s1 = %s : %d\n", s1, lengthOfLongestSubstring(s1));
	printf("s2 = %s : %d\n", s2, lengthOfLongestSubstring(s2));
	printf("s3 = %s : %d\n", s3, lengthOfLongestSubstring(s3));
}
