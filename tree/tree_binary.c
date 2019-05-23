#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

int count(struct Node *root)
{
	if(root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}

int height(struct Node *root)
{
	int x=0, y=0;

	if(root==NULL)
		return 0;
	x = height(root->lchild);
	y = height(root->rchild);
	if(x>y)
		return x+1;
	else
		return y+1;
}

int count_node(struct Node *p)
{
	int x=0, y=0;

	if(p != NULL) {
		x = count_node(p->lchild);
		y = count_node(p->rchild);
		//all node
		if (p->lchild == NULL && p->rchild == NULL)
		/*
		if (p->lchild != NULL && p->rchild != NULL) //leaf
		if (p->lchild  && p->rchild) //degree 2
		if (p->lchild || p->rchild) //degree 1 or 2
		if (p->lchild != NULL ^ p->rchild != NULL) //degree 1
		*/
			return x + y + 1;
		else
			return x + y;
	}
		return 0;
}

int main()
{
	Tree_create();

	printf("Preorder\n");
	Preorder(root);
	printf("\n");
	printf("Inorder\n");
	Inoreder(root);
	printf("\n");
	printf("Postorder\n");
	Postorder(root);
	printf("\n");

	printf("Count is %d\n", count(root));
	printf("Height is %d\n", height(root));
    
	printf("Count node is %d\n", count_node(root));
	
	return 0;
}
