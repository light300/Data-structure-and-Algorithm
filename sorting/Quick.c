#include <stdio.h>

void swap(int *x, int *y)
{
	 int temp=*x;
	 *x=*y;
	 *y=temp;
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];
	int i=l,j=h;
	do
	{
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);

		if(i<j)swap(&A[i],&A[j]);
	}while(i<j);

	swap(&A[l],&A[j]);
	return j;
}

void Quick(int A[],int l,int h)
{
    int j;

	if(l<h) {
		j = partition(A,l,h);
		Quick(A,l,j);
		Quick(A,j+1,h);
	}
}

int main()
{
	int a[] = {3,7,9,10,6,5,12,4,11,2};
	int n = 10;
	int i;

	Quick(a, 0, n);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
