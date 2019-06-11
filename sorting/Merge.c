#include <stdio.h>

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void Merge(int A[],int l,int mid,int h)
{
	int i, j, k;
	int B[20]={0};
	i = l;
	j = mid + 1;
	k = l;

	while(i<=mid && j<=h) {
		if(A[i]<A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	for(;i<=mid;i++)
	    B[k++] = A[i];
	for(;j<=h;j++)
		B[k++] = A[j];
	for(i=l;i<=h;i++)
		A[i] = B[i];
}

void IMergeSort(int A[],int n)
{
	int p,l,h,mid,i;
     
	for(p=2;p<=n;p=p*2) {
		for(i=0;i+p-1<=n;i=i+p) {
			l = i;
			h = i + p - 1;
			mid = (l+h) / 2;
			Merge(A, l, mid, h);
		}
	}
	if(p/2 < n)
		Merge(A, 0, p/2 - 1, n);
}

int main()
{
	int a[] = {11,13,7,12,16,9,24,5,10,3,25};
	int n = 11;
	int i = 0;

	IMergeSort(a, n);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
