#include<stdlib.h>
#include"data.h"
#include"do_it.h"
#include"in_out.h"

static int min_pos(const int a[], int n)
{
    int i, min, imin;
    for(min=a[imin=0], i=1; i<n; ++i)
        if(a[i]<min) min=a[imin=i];
    return imin;
}

static int checked(const student *p, int base)
{
    int j = min_pos(p->grade, sizeof(p->grade)/sizeof(p->grade[0]));
    return p->grade[j] == base;
}

int process_all(student *p, int n)
{
    int k,i;
    student * const q = malloc(n*sizeof(student));
    if(!q)
    {
        printf("Ошибка выделения динамической памяти\n");
        return n;
    }

    for(k=i=0; i<n; ++i)
        if(checked(p+i, 5)) q[k++] = p[i];
    printf("Наши отличники\n");
    print_all(q,k);

    for(k=i=0; i<n; ++i)
        if(checked(p+i, 4)) q[k++] = p[i];
    printf("Наши хорошисты\n");
    print_all(q,k);

    for(k=i=0; i<n; ++i)
        if(checked(p+i, 3)) q[k++] = p[i];
    printf("Наши троечники\n");
    print_all(q,k);

    for(k=i=0; i<n; ++i)
        if(checked(p+i, 2)) q[k++] = p[i];
    printf("Позор двоечники\n");
    print_all(q,k);
    free(q);
    return n;
}
