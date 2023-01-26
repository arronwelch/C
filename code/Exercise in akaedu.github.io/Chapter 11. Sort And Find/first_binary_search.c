/* first_binary_search.c */

#include <stdio.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

/* Callee
 * Contract, Precondition, Invariant, Maintenance, Postcondition
 * Eiffel, Bertrand Meyer, Design by Contract(DbC)
 */
int binarysearch(int number)
{
	int mid, start = 0, end = LEN - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		if (a[mid] < number)
			start = mid + 1;
		else if (a[mid] > number)
			end = mid - 1;
		else {
			while (a[mid] == number && a[mid-1] == number)
				mid--;
			return mid;
		}
	}
	return -1;
}

/* Caller */
int main(void)
{
	int search_element = 2;
	printf("binary search %d: %d\n", search_element, binarysearch(search_element));

	return 0;
}

