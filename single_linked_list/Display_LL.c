#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create(struct Node *p, int A[], int n)
{
	int i;
	struct Node *t, *last;

	/*first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;*/
	//p = (struct Node *)malloc(sizeof(struct Node));
	p->data = A[0];
	p->next = NULL;
	last = p;

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

int isSorted(struct Node *p)
{
	int x = -65536;
	
	while (p != NULL) {
		if (p->data < x)
			return 0;
		x = p->data;
		p = p->next;
	}
	return 1;
}

void RemoveDuplicate(struct Node *p)
{
	struct Node *q;
	q = p->next;

	while(q != NULL) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		} else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void Reverse1(struct Node *p)
{
	int *A, i=0;
	struct Node *q = p;
	A = (int *)malloc(sizeof(int) * count(p));

	while (q != NULL) {
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;
	while (q != NULL) {
		q->data = A[i];
		q = q->next;
		i--;
	}
}

void Reverse2(struct Node *p)
{
	struct Node *q = NULL;
	struct Node *r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
	if (p) {
		Reverse3(p, p->next);
		p->next = q;
	} else {
		first = q;
	}
}

void Conact(struct Node *p, struct Node *q)
{
	third = p;

	while (p->next != NULL) {
		p = p->next;
	}
	p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
	struct Node *last;
	if (p->data < q->data) {
		third = last = p;
		p = p->next;
		third->next = NULL;
	} else {
		third = last = q;
		q = q->next;
		third->next = NULL;
	}
	while (p && q) {
		if (p->data < q->data) {
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		} else {
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if (p) last->next = p;
	if (q) last->next = q;
}

int isLoop(struct Node *f)
{
	struct Node *p, *q;
	p = q = f;

	do {
		p = p->next;
		q = q->next;
		q = q!=NULL ? q->next:q;
	} while(p && q && p!=q);
	if (p == q)
		return 1;
	else
		return 0;
}

int main()
{
	int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
	//create function: input Array and number of Array elements which will create a linked list data type array
	first = (struct Node *)malloc(sizeof(struct Node));
	create(first, A, 5);
	second = (struct Node *)malloc(sizeof(struct Node));
	create(second, B, 5);

	//display function will display all data in linked list
	Display(first);
	Display(second);
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

	//SortedInsert(first, 9);
	//Display(first);
	
	printf("Deleted Element %d\n", Delete(first, 4));
	Display(first);

	printf("Is Linked list sort? %d\n", isSorted(first));

    RemoveDuplicate(first);
    Display(first);

	// 3 methods to implement reverse the linked list
	//Reverse1(first);
    //Display(first);
	//Reverse2(first);
    //Display(first);
	//Reverse3(NULL, first);
    //Display(first);
	
	printf("Conact or Merge\n");
	//Conact(first, second);
	Merge(first, second);
	Display(third);
	
	// check the linked list is loop or not
	struct Node *t1, *t2;
	t1 = first->next->next;
	t2 = first->next->next->next->next;
	t2->next = t1;

	printf("Is loop? %d\n", isLoop(first));

	return 0;
}
