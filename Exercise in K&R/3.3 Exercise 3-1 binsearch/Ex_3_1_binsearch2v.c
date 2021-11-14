/* 
 * Exercise 3-1. 
 * Our binary search makes two tests inside the loop, when one would suffice(at the price of more tests outside.) 
 * Write a version with only one test inside the loop and measure the difference in run-time.
 */

#include<stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2v(int x,int v[],int n);

int main(void)
{
	int arr[]={2,4,6,7,9,29,45,46,49,50,51};
	printf("binsearch(9,arr,10) = %d \n",binsearch(9,arr,10));
    printf("binsearch2v(9,arr,10) = %d \n",binsearch2v(9,arr,10));

	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) 
    {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }

    return -1; /* no match */
}

int binsearch2v(int x,int v[],int n)
{
	int low,high,mid;
	
	low=0;
	high=n-1;
	
	mid = ( low + high ) / 2;

	while(low < high && x != v[mid])
	{
		if( x > v[mid])
			low = mid+1;
		else
			high = mid -1;

		mid = ( low + high)/2;
	}

	if(x==v[mid])
		return mid;
	else
		return -1;
}
