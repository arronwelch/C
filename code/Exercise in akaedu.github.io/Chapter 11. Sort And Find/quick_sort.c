/* quick_sort.c
 * O(nlogn)
 */

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

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d mid = %d\n",
			start, mid, mid+1, end,
			a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], mid);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
		printf("quick (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d mid = %d\n",
			start, mid, mid+1, end,
			a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], mid);
	}
}

int main(void)
{
	quicksort(0, LEN-1);
	return 0;
}
