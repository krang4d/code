#include"in_out.h"
#include"data.h"
#include<stdio.h>

int input_all(student *p, int n)
{
    printf("input_all %p\n", p);
    return n;
}

static void print_stud(const student *p)
{
    int j;
    printf("%-*s\t", (int)sizeof(p->name), p->name);
    for(j=0; j<(int)sizeof(p->grade)/(int)sizeof(p->grade[0]); ++j)
        printf("%2d", p->grade[j]);
    printf("\n");
}

void print_all(student *p, int n)
{
    int i;
    for(i=0; i<n; ++i)
        print_stud(p+i);
    //printf("\n");
}
