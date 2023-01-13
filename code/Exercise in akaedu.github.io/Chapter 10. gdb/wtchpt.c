#include <stdio.h> /* gdb:breakpoint */

int main(void)
{
	int sum = 0, i = 0;
	char input[5];

	while(1) {
		scanf("%s", input);
		sum = 0;
		for (i = 0; input[i] != '\0'; i++) {
			if (input[i] < '0' || input[i] > '9') {
				printf("Invalid input!\n");
				sum = -1;
				break;
			}
			sum = sum*10 + input[i] - '0';
		}
		printf("input=%d\n", sum);
	}
	return 0;
}
