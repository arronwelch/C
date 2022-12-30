#include <stdio.h>

struct complex_struct0 {
	double x, y;
};

struct complex_struct1 {
	double x, y;
} z1, z2;

struct complex_struct1 z3, z4;

struct {
	double x, y;
} z5, z6;

struct complex_struct { double x, y; };

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	z1.x = z1.x + z2.x;
	z1.y = z1.y + z2.y;
	return z1;
}

int main(void)
{
	struct complex_struct z;
	double x = 3.0;
	z.x = x;
	z.y = 4.0;
	if (z.y < 0)
		printf("z=%f%fi\n", z.x, z.y);
	else
		printf("z=%f+%fi\n", z.x, z.y);

	struct complex_struct zz = { 3.0, 4.0 };
	struct complex_struct zz1 = { x, 4.0 }; /* zz1.x = 3.0, zz1.y = 4.0 */
	struct complex_struct zz2 = { 3.0, }; /* zz2.x = 3.0, zz2.y = 0.0 */
	struct complex_struct zz3 = { 0 }; /* zz3.x = 0.0, zz3.y = 0.0 */
	struct complex_struct zz4 = { .y = 4.0 }; /* zz4.x = 0.0, zz4.y = 4.0 */
	struct complex_struct zz5 = zz4;
	zz4 = zz5;
	zz = add_complex(zz, zz);
	printf("z=%f+%fi\n", zz.x, zz.y);

	return 0;
}
