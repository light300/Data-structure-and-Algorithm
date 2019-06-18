#include <stdio.h>

void swap(int *x,int *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//reference https://www.geeksforgeeks.org/iterative-merge-sort/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;
			    
	/* create temp arrays */
	int L[n1], R[n2];
						    
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
														
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1) {
		arr[k++] = L[i++];
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2) {
		arr[k++] = R[j++];
	}
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
	// Same as (l+r)/2, but avoids overflow for large l and h
	int m = l+(r-l)/2;
								
	// Sort first and second halves
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);

	merge(arr, l, m, r);
	}
}

// reference https://blog.csdn.net/qq_40215528/article/details/84996508

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void IMergeSort(int arr[], int n)
{
    int curr_size;
	// For current size of subarrays to be merged curr_size varies from 1 to n/2
	int left_start; 
	// For picking starting index of left subarray to be merged				
	// Merge subarrays in bottom up manner.  First merge subarrays of
	// size 1 to create sorted subarrays of size 2, then merge subarrays
	// of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) {
	// Pick starting point of different subarrays of current size
		for (left_start=0; left_start<n-1; left_start += 2*curr_size) {
		// Find ending point of left subarray. mid+1 is starting point of right
			int mid = left_start + curr_size - 1;

			int right_end = min(left_start + 2*curr_size - 1, n-1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			merge(arr, left_start, mid, right_end);
		}
	}
}

int main()
{
	int a[] = {11,13,7,12,16,9,24,5,10,3,25};
	int n = 11;
	int i = 0;

	IMergeSort(a, n);
	//mergeSort(a, 0, n-1);

	for(i = 0;i < n;i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
