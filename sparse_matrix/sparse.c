#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int i;
	int j;
	int x;
};

struct Sparse
{
	int m;
	int n;
	int num;
	struct Element *ele;
};

void create(struct Sparse *s)
{
	int i;

	printf("Enter Dimensions: ");
	scanf("%d%d", &s->m, &s->n);
	printf("Number of non-zero: ");
	scanf("%d", &s->num);

	s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

	for(i=0; i<s->num; i++)
	{
		scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
	}
}

void Display(struct Sparse s)
{
	int i, j;
	int k=0;

	for(i=0;i<s.m;i++){
		for(j=0;j<s.n;j++){
			if((i == s.ele[k].i) && (j == s.ele[k].j))
				printf("%d  ", s.ele[k++].x);
			else
				printf("0  ");
		}
		printf("\n");
	}
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
	struct Sparse *sum;
	int i, j, k;

	i=j=k=0;

	sum = (struct Sparse *)malloc(sizeof(struct Sparse));
	sum->ele = (struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));

	while((i<s1->num) && (j<s2->num)) {
		if(s1->ele[i].i<s2->ele[j].i)
			sum->ele[k++] = s1->ele[i++];
		else if(s1->ele[i].i>s2->ele[j].i)
			sum->ele[k++] = s2->ele[j++];
		else {
			if(s1->ele[i].j<s2->ele[j].j)
				sum->ele[k++] = s1->ele[i++];
			else if(s1->ele[i].j>s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else
			{
				sum->ele[k] = s1->ele[i];
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
			}
		}
	}
	for(;i<s1->num;i++) sum->ele[k++] = s1->ele[i];
	for(;j<s2->num;j++) sum->ele[k++] = s2->ele[j];
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = k;

	return sum;
}

struct Sparse *transpose(struct Sparse *a)
{
	struct Sparse *b;
	b = (struct Sparse *)malloc(sizeof(struct Sparse));
	b->ele = (struct Element *)malloc((a->num)*sizeof(struct Element));

	b->m = a->n;
	b->n = a->m;
	b->num = a->num;

	int rowterms[100], startingpos[100];
	int i, j;
	int numCols = a->n;
	int numTrems = a->num;

	if(numTrems > 0){
		for(i=0; i<numCols; i++)
			rowterms[i] = 0;
		for(i=0; i<numTrems; i++)
			rowterms[a->ele[i].j]++;
		startingpos[0] = 0;
		for(i=1; i<numCols; i++)
			startingpos[i] = startingpos[i-1] + rowterms[i-1];
		for(i=0; i<numTrems; i++) {
			j = startingpos[a->ele[i].j]++;
			b->ele[j].i = a->ele[i].j;
			b->ele[j].j = a->ele[i].i;
			b->ele[j].x = a->ele[i].x;
		}
	}

	return b;
}

int main()
{
	struct Sparse s1, s2, *s3, *s4;

	create(&s1);
	//create(&s2);
	
	//s3 = add(&s1, &s2);
	s4 = transpose(&s1);

	printf("First\n");
	Display(s1);
	//printf("Second\n");
	//Display(s2);
	//printf("Sum\n");
	//Display(*s3);
	printf("Transpose\n");
	Display(*s4);

	return 0;
}
