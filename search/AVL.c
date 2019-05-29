#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int heigh;
	struct Node *lchild;
	struct Node *rchild;
}*root=NULL;

int Nodeheigh(struct Node *p)
{
	int hl, hr;

	hl = p && p->lchild ? p->lchild->heigh : 0;
	hr = p && p->rchild ? p->rchild->heigh : 0;
	
	return hl > hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p)
{
	int hl, hr; 

	hl = p && p->lchild ? p->lchild->heigh : 0;
	hr = p && p->rchild ? p->rchild->heigh : 0;
			        
	return hl - hr;
}

struct Node *LLrotation(struct Node *p)
{
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;

	pl->rchild = p;
	p->lchild  = plr;
	p->heigh = Nodeheigh(p);
	pl->heigh = Nodeheigh(pl);

	if (root == p)
		root = pl;
	
	return pl;
}

struct Node *LRrotation(struct Node *p)
{
	struct Node *pl = p->lchild;
	struct Node *plr = pl->rchild;
	
	pl->rchild = plr->lchild;
	p->lchild = plr->rchild;

	plr->lchild = pl;
	plr->rchild = p;

	pl->heigh = Nodeheigh(pl);
	p->heigh = Nodeheigh(p);
	plr->heigh = Nodeheigh(plr);

	if (root = p)
		root = plr;

	return plr;
}

struct Node *RRrotation(struct Node *p)
{
	struct Node *pr = p->rchild;
	struct Node *prl = pr->lchild;

	pr->lchild = p;
	p->rchild = prl;

	p->heigh = Nodeheigh(p);
	pr->heigh = Nodeheigh(pr);

	if (root = p)
		root = pr;

	return pr;
}

struct Node *RLrotation(struct Node *p)
{
	struct Node *pr = p->rchild;
	struct Node *prl = pr->lchild;

	pr->lchild = prl->rchild;
	p->rchild = prl->lchild;

	prl->rchild = pr;
	prl->lchild = p;

	pr->heigh = Nodeheigh(pr);
	p->heigh = Nodeheigh(p);
	prl->heigh = Nodeheigh(prl);

	if (root == p)
		root = prl;

	return prl;
}

struct Node *Rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;

	if (p == NULL) {
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->heigh = 1;
		t->lchild = t->rchild = NULL;
		return t;
	}   

	if (key < p->data)
		p->lchild = Rinsert(p->lchild, key);
	else if (key > p->data)
		p->rchild = Rinsert(p->rchild, key);

	p->heigh = Nodeheigh(p);
	
	if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
		return LLrotation(p);
	else if (BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
		return LRrotation(p);
	else if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
		return RRrotation(p);
	else if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
		return RLrotation(p);
	return p;
}

void Inorder(struct Node *p)
{
	if (p) {
		Inorder(p->lchild);
		printf("%d ", p->data);
		Inorder(p->rchild);
	}
}

int main()
{
	root = Rinsert(root, 5);
	Rinsert(root, 10);
	Rinsert(root, 8);

	Inorder(root);
	printf("\n");

	return 0;
}
