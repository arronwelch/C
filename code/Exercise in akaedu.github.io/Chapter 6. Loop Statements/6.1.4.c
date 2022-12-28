#include <stdio.h>

int main(void)
{
	int n = 0;
	for (int i=1; i <= 100; ++i)
	{
		if(i/10 == 9)
		{
			n++;
			printf("%2d %d\n", i, n);
		}
		if(i%10 == 9)
		{
			n++;
			printf("%2d %d\n", i, n);
		}
	}
	printf("\n%d\n", n);

	return 0;
}
