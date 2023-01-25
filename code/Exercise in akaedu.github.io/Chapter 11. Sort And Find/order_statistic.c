/* order_statistic.c */

#include <stdio.h>

#define LEN 8
/*             0  1  2  3  4  5  6  7 */
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
	int i = start, j = end;
	int pivot = start, temp = 0;
	while (i < j) {
		while (a[i] <= a[pivot] && i < end)
			i++;
		while (a[j] > a[pivot])
			j--;
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[pivot];
	a[pivot] = a[j];
	a[j] = temp;

	return j;
}

/* search k-th order statistic element between start and end */
int order_statistic(int start, int end, int k)
{
	int mid, i;
	mid = partition(start, end);
	printf("mid = %d\t", mid);
	i = mid - start + 1;
	printf("i = %d\n", i);
	if (k == i)
		return a[i];
	else if (k > i)
		return order_statistic(mid+1, end, k-i);
	else
		return order_statistic(start, mid-1, k);
}

int main(void)
{
	printf("k-th order statistic element between start and end: %d\n",
			order_statistic(0, LEN-1, 3));
	return 0;
}
