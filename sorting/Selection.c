#include <stdio.h>

void swap(int *x, int *y)
{
	 int temp=*x;
	 *x=*y;
	 *y=temp;
}

void Selection(int A[],int n)
{
	int i,j,k;

	for(i=0;i<n-1;i++) {
		for(j=k=i;j<n;j++) {
			if(A[j]<A[k])
				k=j;
		}
		swap(&A[i],&A[k]);
	}
}

int main()
{
	int a[] = {3,7,9,10,6,5,12,4,11,2};
	int n = 10;
	//int a[] = {3,7,9,10};
	//int n = 4;
	int i;

	Selection(a, n);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
