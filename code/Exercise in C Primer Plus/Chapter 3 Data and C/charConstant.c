#include <stdio.h>

int main(void)
{
	int fate = 'FATE';
	printf("\'F\' = %d\n",'F');
	printf("\'A\' = %d\n",'A');
	printf("\'T\' = %d\n",'T');
	printf("\'E\' = %d\n",'E');
	
	printf("fate = %d\n", fate);
	printf("('F' << 24) + ('A' << 16) + ('T' << 8) + 'E' = %d\n", ('F' << 24) + ('A' << 16) + ('T' << 8) + 'E');

	return 0;
}
