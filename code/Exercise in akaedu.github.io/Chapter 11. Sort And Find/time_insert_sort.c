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
 * time = (n-1)*(c1+c2+c5+m*(c3+c4))
 */
