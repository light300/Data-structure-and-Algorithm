#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*top=NULL;

void push(int x)
{
	struct Node *t;
	t = (struct Node *)malloc(sizeof(struct Node));

	if(t == NULL)
		printf("Stack is full\n");
	else {
	t->data = x;
	t->next = top;
	top = t;
	}
}

int pop()
{
	struct Node *t;
	int x;

	if(top == NULL)
		printf("Stack is Empty\n");
	else {
		t = top;
		top = top->next;
		x = t->data;
		free(t);
	}
	return x;
}

int peek(int index)
{
	int x = -1, i;
	struct Node *p;
	p = top;

	for(i=0 ; p!=NULL && i<index-1 ; i++) {
		p = p->next;
	}
	if(p != NULL)
		return p->data;
	else {
		return -1;
	}		
}

void Display()
{
	struct Node *p;
	p = top;
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	Display();

	//printf("%d \n", pop());
	printf("%d \n", peek(3));

	return 0;
}
