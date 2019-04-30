#include <stdio.h>
#include <stdlib.h>

struct Term
{
	int coef;
	int exp;
};

struct Poly
{
	int n;
	struct Term *term;
};

void create(struct Poly *p)
{
	int i;

	printf("Enter number of terms: ");
	scanf("%d", &p->n);

	p->term = (struct Term *)malloc(p->n*sizeof(struct Term));

	printf("Enter terms\n");

	for(i=0;i<p->n;i++)
		scanf("%d%d", &p->term[i].coef, &p->term[i].exp);

}

void Display(struct Poly p)
{
	int i;

	for(i=0 ; i<p.n; i++)
		printf("%d*X^%d ", p.term[i].coef, p.term[i].exp);
	printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
	int i, j, k;
	struct Poly *sum;

	i=j=k=0;
	sum = (struct Poly *)malloc(sizeof(struct Poly));
	sum->term = (struct Term *)malloc((p1->n + p2->n)*sizeof(struct Term));

	while((i<p1->n) && (j<p2->n)) {
		if(p1->term[i].exp > p2->term[j].exp)
			sum->term[k++] = p1->term[i++];
		else if(p1->term[i].exp < p2->term[j].exp)
			sum->term[k++] = p2->term[j++];
		else{
			sum->term[k].exp = p1->term[i].exp;
			sum->term[k++].coef = p1->term[i++].coef + p2->term[j++].coef;
		}
	}
	for(;i<p1->n;i++) sum->term[k++] = p1->term[i];
	for(;j<p1->n;j++) sum->term[k++] = p2->term[j];
    sum->n = k;

	return sum;
}

int main()
{
	struct Poly p1, p2, *p3;

	create(&p1);
	create(&p2);

	p3 = add(&p1, &p2);

	Display(p1);
	Display(p2);
	Display(*p3);

	return 0;
}
