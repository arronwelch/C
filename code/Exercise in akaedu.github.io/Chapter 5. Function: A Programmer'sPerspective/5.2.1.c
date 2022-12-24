/* Incremental */

#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
//	double dx = x2 - x1;
//	double dy = y2 - y1;
//	/* printf("dx is %f\ndy is %f\n", dx, dy); */ /* Scaffold */
//	double dsquared = dx * dx + dy * dy;
//	/* printf("dsquared is %f\n", dsquared); */
//	double result = sqrt(dsquared);
//
//	return result;

	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double area(double radius)
{
	return 3.1416 * radius * radius;
}

double area_point(double x1, double y1, double x2, double y2)
{
	return area(distance(x1, y1, x2, y2));
}

int main(void)
{
	/* printf("distance is %f\n", distance(1.0, 2.0, 4.0, 6.0)); */
	printf("area_point is %f\n", area_point(1.0, 2.0, 4.0, 6.0));

	return 0;
}
