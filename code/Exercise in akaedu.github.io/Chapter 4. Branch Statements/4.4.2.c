#include <stdio.h>

void print_day(int day)
{
	switch(day) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("Weekday\n");
		break;
	case 6:
	case 7:
		printf("Weekend\n");
		break;
	default:
		printf("Illegal day number!\n");
		break;
	}
}

int main(void)
{
	print_day(2);
	return 0;
}
