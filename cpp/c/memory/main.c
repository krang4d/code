#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[], const char* env[])
{
    int *p;
    int i, n=5;

    p = (int*)malloc(5*sizeof(int)); //выделение память под массив
    printf("p = %p\n\n", p);
    if (!p)
    {
        printf("Неудалось выделить память для p %p\n", p );
    }
    else
        //printf("Размер p = %i\n", sizeof(p));
        for(i=0; i<n; i++) //заполнение массива
        {
            p[i] = i;
            printf("p%i = %i\n", i, p[i]);
        }
    {//увеличение объёма память для массива
        n *= 2;
        int *pp = (int*)realloc(p,n*sizeof(int));
        if(!pp)
        {
            printf("Неудалось увеличить объём памяти для pp %p (p = %p, pp = %p)\n", pp, p, pp);
        }
        else
        {
            p = pp;
            printf("p = %p\n\n", pp);
            //printf("Размер pp = %i\n", sizeof(pp));
            for(i=0; i<(n); i++)
            {//заполнение массива
                p[i] = i;
                printf("p%i = %i\n", i, p[i]);
            }
         }
    }
    free(p); //освобождение выделеннoй под массив памяти

    if (argc == 1)
        printf("Use: memory.exe param1 param2\nname: %s\npath: %s", argv[0], argv[1]);
    while (*argv)
        puts(*argv++);
    printf("\n");

    while(*env!=NULL)
        puts(*env++);

    return 0;
}
