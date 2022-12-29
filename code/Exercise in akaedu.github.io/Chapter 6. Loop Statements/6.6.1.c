#include <stdio.h>

int main(void)
{
	int i, j;
	int n = 10, error_condition = 0;
	for (i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			printf("i = %d, j = %d\n", i, j);
			error_condition++;
			if (error_condition == 5)
				goto error;
		}
	printf("before error\n");
error:
	// error handler
	printf("after error\n");

	return 0;
}
