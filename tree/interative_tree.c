#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void Tree_create()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q, 100);
	
	printf("Enter root value: ");
	scanf("%d", &x);
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);

	while(!isEmpty(q)) {
		p = dequeue(&q);
		printf("Enter left child of %d: ", p->data);
		scanf("%d", &x);
		// Enter -1 stop to enter left child
		if(x!=-1) {
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q, t);
		}

		printf("Enter right child of %d: ", p->data);
		scanf("%d", &x);
		// Enter -1 stop to enter right child
		if(x!=-1) {
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q, t);
		}
	}
}

void Preorder(struct Node *p)
{
	if(p) {
		printf("%d ", p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Inoreder(struct Node *p)
{
	if(p) {
		Inoreder(p->lchild);
		printf("%d ", p->data);
		Inoreder(p->rchild);
	}
}

void Postorder(struct Node *p)
{
	if(p) {
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ", p->data);
	}
}

void Ipreorder(struct Node *p)
{
	struct Stack stk;
	Stackcreate(&stk, 100);

	while(p || !isEmptyStack(stk)) {
		if (p) {
			printf("%d ", p->data);
			push(&stk, p);
			p = p->lchild;
		} else {
			p = pop(&stk);
			p = p->rchild;
		}
	}
	printf("\n");
}

void Iinorder(struct Node *p)
{
	struct Stack stk;
	Stackcreate(&stk, 100);

	while(p || !isEmptyStack(stk)) {
		if (p) {
			push(&stk, p);
			p = p->lchild;
		} else {
			p = pop(&stk);
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
	printf("\n");
}

void Ipostorder(struct Node *p)
{
	struct Node *current = p;
	struct Node *temp;
	struct Stack stk;
	Stackcreate(&stk, 100);

	while(current || !isEmptyStack(stk)) {
		if (current) {
			push(&stk, current);
			current = current->lchild;
		} else {
			temp = stackTop(stk)->rchild;
			if (temp == NULL) {
				temp = pop(&stk);
				printf("%d ", temp->data);
				while(!isEmptyStack(stk) && temp == stackTop(stk)->rchild) {
					temp = pop(&stk);
					printf("%d ", temp->data);
				}
			} else {
				current = temp;
			}
		}
	}
	printf("\n");
}

void Levelorder(struct Node *p)
{
	struct Queue q;
	create(&q, 100);

	printf("%d ", p->data);
	enqueue(&q, p);

	while(!isEmpty(q)) {
		p = dequeue(&q);
		
		if(p->lchild) {
			printf("%d ", p->lchild->data);
			enqueue(&q, p->lchild);
		}
		if(p->rchild) {
			printf("%d ", p->rchild->data);
			enqueue(&q, p->rchild);
		}
	}
	printf("\n");
}

int main()
{
	Tree_create();

	printf("Preorder\n");
	Preorder(root);
	printf("\n");
	printf("Ipreorder\n");
	Ipreorder(root);
	
	printf("Inorder\n");
	Inoreder(root);
	printf("\n");
	printf("Iinorder\n");
	Iinorder(root);

	printf("Postorder\n");
	Postorder(root);
	printf("\n");
	printf("Ipostorder\n");
	Ipostorder(root);

	printf("Levelorder\n");
	Levelorder(root);
    
	return 0;
}
