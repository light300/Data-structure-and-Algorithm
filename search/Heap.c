#include <stdio.h>

void Insert(int h[], int n) {
	int i = n;
	int temp;
	temp = h[i];

	while (i > 1 && temp > h[i/2]) {
		h[i] = h[i/2];
		i = i / 2;
	}
	h[i] = temp;
}

int Delete(int h[], int n) {
	int i, j, x, temp, val;
	val = h[1];
	x = h[n];
	h[1] = h[n];
	h[n] = val;
	i = 1;
	j = 2 * i;

	while (j < n - 1) {
		if (h[j+1] > h[j]) {
			j = j + 1;
		}
		if (h[i] < h[j]) {
			temp = h[i];
			h[i] = h[j];
			h[j] = temp;
			i = j;
			j = 2 * j;
		} else {
			break;
		}
	}
	return val;
}

int main()
{
	int h[] = {0,10,20,30,25,5,40,35}; //40,25,35,10,5,20,30
	int i;

	for (i = 2;i <= 7;i++) {
		Insert(h, i);
	}

	for (i = 7;i > 1;i--) {
		Delete(h, i);
	}

	for (i = 1;i <= 7;i++) {
		printf("%d ", h[i]);
	}
	printf("\n");

	return 0;
}
