#include <stdio.h>

int main(void)
{
	int a = 1;
	scanf("%d", &a);
	printf("a:%d\n", a);

	float b1 = 2.1, b2 = 2.2;
	scanf("%f %E", &b1, &b2);
	printf("b:%.2f %.2E\n", b1, b2);

	char str3[BUFSIZ];
	scanf("%s", str3);
	printf("c:%s\n", str3);

	char str4[BUFSIZ];
	int d4;
	scanf("%s %d", str4, &d4);
	printf("d:%s %d\n", str4, d4);

	char str5[BUFSIZ];
	int e5;
	scanf("%*s %d", &e5);
	printf("e:%d\n", e5);

	return 0;
}
