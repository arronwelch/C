#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
	{
		return z.a;
	}
	else if (z.t == POLAR)
	{
		return z.a * cos(z.b);
	}
	else
	{
		printf("coordinate_type is error!\n");
		return 0;
	}
}

double img_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
	{
		return z.b;
	}
	else if (z.t == POLAR)
	{
		return z.a * sin(z.b);
	}
	else
	{
		printf("coordinate_type is error!\n");
		return 0;
	}
}

double magnitude(struct complex_struct z)
{
	if (z.t == POLAR)
	{
		return z.a;
	}
	else if (z.t == RECTANGULAR)
	{
		return sqrt(z.a * z.a + z.b * z.b);
	}
	else
	{
		printf("coordinate_type is error!\n");
		return 0;
	}
}

double angle(struct complex_struct z)
{
	if (z.t == POLAR)
	{
		return z.b;
	}
	else if (z.t == RECTANGULAR)
	{
		return atan2(z.b, z.a);
	}
	else
	{
		printf("coordinate_type is error!\n");
		return 0;
	}
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
								img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
								img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
								angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
								angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z)
{
	if (img_part(z) < 0)
		printf("%f%fi\n", real_part(z), img_part(z));
	else
		printf("%f+%fi\n", real_part(z), img_part(z));
}

int main(void)
{
	struct complex_struct z = make_from_real_img(3.0, 4.0);
	print_complex(z);
	struct complex_struct z1 = add_complex(z, z);
	print_complex(z1);
	struct complex_struct z2 = sub_complex(z, z1);
	print_complex(z2);
	struct complex_struct z3 = mul_complex(z, z2);
	print_complex(z3);
	struct complex_struct z4 = div_complex(z3, z);
	print_complex(z4);

	return 0;
}
