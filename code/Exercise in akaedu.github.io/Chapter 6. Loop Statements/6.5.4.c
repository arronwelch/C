#include <stdio.h>

void diamond(int n, char c)
{
	if (n % 2 == 0) {
		printf("error number!\n");
		return;
	}

	int i, j;
	int start, end;
	start = end = n / 2;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < end+1; j++)
		{
			if (j >= start)
				printf("%c", c);
			else
				printf(" ");
		}
		if (i < n/2)
		{
			start--;
			end++;
		}
		else
		{
			start++;
			end--;
		}
		printf("\n");
	}
}

int main(void)
{
	diamond(3, '*');
	diamond(5, '+');
	diamond(4, '-');

	return 0;
}
