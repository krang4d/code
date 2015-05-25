#ifndef MENU_H
#define MENU_H
#include"data.h"

typedef struct
{
    const char *text;
    int (*action)(student *, int);
}menu_items;

void menu(const menu_items *pos, int n);

#endif
