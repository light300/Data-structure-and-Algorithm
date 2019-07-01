#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//ref https://www.geeksforgeeks.org/radix-sort/

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

void Count(int a[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (a[i]/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void Radix(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = findMax(arr, n);
    int exp;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (exp = 1; m/exp > 0; exp *= 10)
        Count(arr, n, exp);
}

int main()
{
    int a[] = {11,13,7,12,16,9,24,5,10,3};
    int n = 10;
    int i;
    
    Radix(a, n);
    
    for(i=0;i<10;i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}
