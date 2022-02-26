
#include <stdio.h>

int main()
{
	asm volatile("cli");// CLI
	while(1);

	return 0;
}
