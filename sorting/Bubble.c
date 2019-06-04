#include <stdio.h>

void swap(int *x, int *y)
{
	*x = *x ^ *y;
	*y = *y ^ *x;
	*x = *x ^ *y;
}

void Bubble(int a[], int n)
{
	int i, j, flag;

	for(i = 0;i < n-1;i++) {
		flag = 0;
		for(j = 0;j < n-1-i;j++) {
			if(a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				flag = 1;
			}
		}
		if(flag == 0) {
			break;
		}
	}
}

int main()
{
	int a[] = {3,7,9,10,6,5,12,4,11,2};
	int n = 10;
	//int a[] = {3,7,9,10};
	//int n = 4;
	int i;

	Bubble(a, n);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
