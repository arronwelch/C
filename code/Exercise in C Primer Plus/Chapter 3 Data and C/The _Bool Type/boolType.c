#include <stdio.h>
#include <stdbool.h>

/* Macro name             |  Expands to
bool                         _Bool
true                         Integer constant 1
false                        Integer constant 0
_bool_true_false_are_defined Integer constant 1
*/

int main(void)
{
	bool a = true, b = false;
	printf("a&&b = %d\n", a&&b);
	printf("a||b = %d\n", a||b);
	printf("!b = %d\n", !b);

	return 0;
}
