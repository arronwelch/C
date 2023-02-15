/* countbit.c */

#include <stdio.h>

int countbit(unsigned int x);

int countbit(unsigned int x)
{
	int cnt = 0;
	while(x)
	{
		if (x & 0x01) cnt++;
		x >>= 1;
	}
	return cnt;
}

int main(void)
{
	unsigned int data = 0b11010110;
	printf("0x%02x 1'cnt = %d\n", data, countbit(data));

	return 0;
}
