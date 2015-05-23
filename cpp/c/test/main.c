#include <stdio.h>

typedef union{
    int a;
    int b;
} ion;

ion ua;
int f1(int*);
//int f2(int);

int main(void)
{
    int i;
    printf("f1()=%i, i= %i \n", ua.a, i= f1(&ua.a));
    printf("f1()=%i, i= %i \n", ua.a, i= f1(&ua.a));
    printf("f1()=%i, i= %i \n", ua.a, i= f1(&ua.a));
    printf("f1()=%i, i= %i \n", ua.a, i= f1(&ua.a));
    return 0;
}

int f1(int* a)
{
    static int i;
    ++*a;
    return ++i;

}

/*int f2(int a)
{
    ;
}
*/

