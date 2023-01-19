/* time_insert_sort.c */

#include <stdio.h>

#define LEN 5
int a[LEN] = { 10, 5, 2, 4, 7 };

void insertion_sort(void)
{
	int i, j, key;
	for (j = 1; j < LEN; j++) {
		printf("%d, %d, %d, %d, %d\n",
			a[0], a[1], a[2], a[3], a[4]);
		key = a[j];					/* c1 */
		i = j - 1;					/* c2 */
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];				/* c3 */
			i--;					/* c4 */
		}
		a[i+1] = key;					/* c5 */
	}
	printf("%d, %d, %d, %d, %d\n",
		a[0], a[1], a[2], a[3], a[4]);
}

int main(void)
{
	insertion_sort();
	return 0;
}

/*
 * 10, 7, 5, 4, 2
 * 7, 10, 5, 4, 2 m = 1
 * 5, 7, 10, 4, 2 m = 2
 * 4, 5, 7, 10, 2 m = 3
 * 2, 4, 5, 7, 10 m = 4
 */

/*
 * time = (n-1)*(c1+c2+c5+m*(c3+c4))
 * Best Case:
 * 	m = 0
 * 	time = (c1+c2+c5)*n - (c1+c2+c5)
 * 	time = a*n + b // Linear Function with n
 * Worst Case:
 * 	m = 1+2+3+...+(n-1)
 * 	time = (n-1)*(c1+c2+c5+m*(c3+c4))
 * 	time = a*n*n + b*n + c // Quadratic Function with n
 * Average Case:
 * 	m = (1+2+3+...+(n-1))/2
 * 	time = (n-1)*(c1+c2+c5+m*(c3+c4))
 * 	time = a*n*n + b*n + c // Quadratic Function with n
 * O-notation(low -> high):
 * 	O(lgn), O(sqrt(n)), O(n), O(nlgn), O(n^2), O(n^3), O(2^n), O(n!)
 * Big-O notation:
 * 	O-notation is equal to, Big-O-notation is equal to and less than
 * Upper Bound is constant
 */
