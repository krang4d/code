#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include"data.h"
#include"menu.h"
#include"in_out.h"
#include"do_it.h"

void menu(const menu_items *pos, int n)
{
    extern student *stud_ptr;
    extern int cur_n;
    student *p = stud_ptr;
    int ns = cur_n;

    /*char item_text[][64] =
	{
		"Ввод данных",
        "Обработка данных",
		"Вывод результатов"
	};

    const int n = sizeof item_text / sizeof item_text[0];*/

    int i, r;
	while(1)
	{
		do
		{
            system("clear");
			for(i=0; i<n; ++i)
                printf("%d. %s\n", i+1, pos[i].text);
			printf("%d. %s\n", 0, "Выход");
			printf("\nВаш выбор: ");

            fflush(stdin);
        }
        while( scanf("%d", &r)!=1 || r<0 || r>n );
        //system("clear");

        if(--r < 0) break;
            ns = pos[r].action(p, ns);
        //printf("\n");

        /*switch( r )
		{
        case 1:	input_all();	break;
        case 2: process_all(p, ns);	break;
        case 3: print_all(p, ns);	break;
		case 0: return;
        }
        //scanf("%i", &in);
        */
        printf("\nОбработано записей %d\n", ns);
        system("sleep 2");
    }
}
