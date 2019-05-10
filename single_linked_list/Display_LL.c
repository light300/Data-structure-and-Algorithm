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

struct Node *Lsearch(struct Node *p, int key)
{
	struct Node *q = NULL;
	while (p != NULL) {
		if (key == p->data)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

struct Node *RLsearch(struct Node *p, int key)
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RLsearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;

	if (index < 0 || index > count(p))
		return;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;

	if (index == 0) {
		t->next = first;
		first = t;
	} else {
		for (i=0 ; i<index-1 ; i++)
			p = p->next;
		t->next = p->next;
		p->next = t;
	}
}

void SortedInsert(struct Node *p, int x)
{
	struct Node *t, *q=NULL;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;

	if (first == NULL) {
		first = t;
	} else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == first) {
			t->next = first;
			first = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct Node *p, int index)
{
	struct Node *q;
	int x = -1, i;

	if (index < 1 || index > count(p))
		return -1;
	if (index == 1) {
		q = first;
		x = first->data;
		first = first->next;
		free(q);
		return x;
	} else {
		for (i=0 ; i<index-1 && p ; i++ ) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x;
	}
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

	struct Node *temp;
	//temp = Lsearch(first, 10);
	//if (temp)
//		printf("Key is found: %d\n", temp->data);
//	else
//		printf("Key is not found.\n");

    temp = RLsearch(first, 7);
	if (temp)
		printf("Key is found: %d\n", temp->data);
	else
		printf("Key is not found.\n");

	Display(first);
	
	//Insert(first, 0, 30);
	//Display(first);

	//Insert(first, 3, 25);
	//Display(first);

	SortedInsert(first, 9);
	Display(first);
	
	printf("Deleted Element %d\n", Delete(first, 4));
	Display(first);

	return 0;
}
