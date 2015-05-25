#ifndef DATA_H
#define DATA_H

#define N 10
#define M 32
#define K 3

typedef struct
{
    char name[M];
    int grade[K];
}student;

extern student *stud_ptr;
extern int cur_n;
#endif
