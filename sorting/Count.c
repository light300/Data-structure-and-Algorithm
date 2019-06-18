#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int findMax(int a[], int n)
{
	int i, x;
	x = INT32_MIN;

	for (i = 0;i < n;i++) {
		if(a[i] > x)
			x = a[i];
	}

	return x;
}

void Count(int a[], int n)
{
	int i, j, max;
	int *c;

	max = findMax(a, n);

	c = (int *)malloc((max + 1) * sizeof(int));

	for(i = 0;i < (max + 1);i++)
		c[i] = 0;

	for(i = 0;i < n;i++)
		c[a[i]]++;

	i = 0;
	j = 0;

	while(j < (max + 1)) {
		if(c[j] > 0) {
			a[i++] = j;
			c[j]--;
		} else {
			j++;
		}
	}
}

int main()
{
	int a[] = {11,13,7,12,16,9,24,5,10,3};
	int n = 10;
	int i;

	Count(a, n);

	for(i=0;i<10;i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}
