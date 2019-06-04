#include <stdio.h>

void Insert(int a[], int n)
{
	int i, j ,x;

	for(i = 1;i < n;i++) {
		j = i - 1;
		x = a[i];
		while(j > -1 && a[j] > x) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}

int main()
{
	int a[] = {3,7,9,10,6,5,12,4,11,2};
	int n = 10;
	//int a[] = {3,7,9,10};
	//int n = 4;
	int i;

	Insert(a, n);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
