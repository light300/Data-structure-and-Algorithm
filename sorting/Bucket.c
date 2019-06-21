#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
};

void Insert(struct Node **bins, int x)
{
    struct Node *t;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = bins[x];
    bins[x] = t;
}

int Delete(struct Node **bins, int x)
{
    struct Node *q;
    struct Node *p;
    p = bins[x];

    q = p;
    x = p->data;
    p = p->next;
    free(q);
    bins[x] = p;
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

void Bucket(int a[], int n)
{
    int i, j, max;
    //int *c;
    
    max = findMax(a, n);
    
    struct Node **bins;
    
    bins = (struct Node **)malloc((max + 1) * sizeof(struct Node *));
    
    //c = (int *)malloc((max + 1) * sizeof(int));
    
    for(i = 0;i < (max + 1);i++)
        bins[i] = NULL;
        //c[i] = 0;
    
    for(i = 0;i < n;i++) {
        //printf("%d\n", a[i]);
//        bins[a[i]] = (struct Node *)malloc(sizeof(struct Node));
        Insert(bins, a[i]);
        
        //c[a[i]]++;
    }
    
    i = 0;
    j = 0;
    
//    struct Node *tmp;
    
    while(i < (max + 1)) {
        while (bins[i] != NULL) {
            a[j++] = Delete(bins, i);
        }
        i++;
        //        tmp = bins[i];
        //        while (tmp != NULL) {
        //            q = tmp;
        //            a[j++] = tmp->data;
        //            tmp = tmp->next;
        //            free(q);
        //            Delete(bins, i);
    }
}

int main()
{
    int A[] = {11,3,7,12,16, 9,9,24,5,10,3};
    int n = 11;
    int i;
    
    Bucket(A, n);
    
    for(i = 0;i < n;i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
