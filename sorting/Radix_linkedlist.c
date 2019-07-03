#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
};

void Insert(struct Node **bins, int x, int elem)
{
    struct Node *t;
    struct Node *q, *p;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    
    t->data = elem;
    t->next = NULL;
    
    p = bins[x];
    q = p;
    
    if (bins[x] == NULL) {
        bins[x] = t;
    } else {
//        bins[x]->next = t;
        while(p && p->data < elem){
            q = p;
            p = p->next;
        }
        if(p == bins[x]) {
            t->next = bins[x];
            bins[x] = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
    
}

int Delete(struct Node **bins, int i)
{
    struct Node *q;
    struct Node *p;
    int x;
    p = bins[i];

    q = p;
    x = p->data;
    p = p->next;
    free(q);
    bins[i] = p;
    return x;
}

int findMax(int a[], int n)
{
    int i, x;
    x = INT32_MIN;
    
    for (i = 0;i < n;i++) {
        if(a[i] > x)
            x = a[i];
    }
    
    return x;
}

void Radix(int a[], int n)
{
    int i, j, max, ind;
    //int *c;
    
    max = findMax(a, n);
    
    struct Node **bins;
    
    bins = (struct Node **)malloc((11) * sizeof(struct Node *));
    
    //c = (int *)malloc((max + 1) * sizeof(int));
    
    for(i = 0;i < 11;i++)
        bins[i] = NULL;
        //c[i] = 0;
    
    int div = 1;
    
    while ((max/div)%10 > 0) {
        
        for(i = 0;i < n;i++) {
            //printf("%d\n", (a[i]/div)%10);
            //        bins[a[i]] = (struct Node *)malloc(sizeof(struct Node));
            ind = (a[i]/div)%10;
            Insert(bins, ind, a[i]);
            
            //c[a[i]]++;
        }
        
        i = 0;
        j = 0;
        
        //    struct Node *tmp;
        
        while(i < 11) {
            while (bins[i] != NULL) {
                a[j++] = Delete(bins, i);
            }
            i++;
        }
        
        div *= 10;
    }
}

int main()
{
    int A[] = {11,3,96,37,923,156,20,1};
    int n = 8;
    int i;
    
    Radix(A, n);
    
    for(i = 0;i < n;i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
