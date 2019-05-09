#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *t, *last;

	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i=1 ; i<n ; i++) {
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void RDisplay(struct Node *p)
{
	if (p != NULL) {
		printf("%d ", p->data);
		RDisplay(p->next);
	}	
}

int count(struct Node *p)
{
	int l=0;
	while (p) {
		l++;
		p = p->next;
	}
	return l;
}

int Rcount(struct Node *p)
{
	if (p != NULL) {
		return Rcount(p->next) + 1;
	} else {
		return 0;
	}
}

int sum(struct Node *p)
{
	int s=0;
	while (p) {
		s+=p->data;
		p = p->next;
	}
	return s;
}

int Rsum(struct Node *p)
{
	if (p != NULL) {
		return Rsum(p->next) + p->data;
	} else {
		return 0;
	}
}

int Max(struct Node *p)
{
	int max = INT32_MIN;

	while (p) {
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int RMax(struct Node *p)
{
	int x=0;
	if (p == 0)
		return INT32_MIN;
	x = RMax(p->next);
	return x > p->data ? x:p->data;
}

int main()
{
	int A[] = {3,5,7,10,15};

	//create function: input Array and number of Array elements which will create a linked list data type array
	create(A, 5);

	//display function will display all data in linked list
	Display(first);

	//Using recursion method to display function will display all data in linked list
	RDisplay(first);
	printf("\n");

	printf("Length is %d\n", count(first));
	printf("Length is %d\n", Rcount(first));

	printf("Sum is %d\n", sum(first));
	printf("Sum is %d\n", Rsum(first));

	printf("Maximum numbe in linked list is %d\n", Max(first));
	printf("Maximum numbe in linked list is %d\n", RMax(first));

	return 0;
}
