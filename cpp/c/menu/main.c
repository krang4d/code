#include <stdlib.h>

#include"menu.h"
#include"in_out.h"
#include"do_it.h"

void latter(void)
{
    system("gedit&");
}

int main(void)
{
    menu_items pos[] =
        {
            {"Ввод данных",         input_all       },
            {"Обработка данных",    process_all     },
         //   {"Написать писмо",      latter          },
            {"Вывод результатов",   print_all       }
        };
    menu(pos, (int)sizeof pos / (int)sizeof *pos);
    return 0;
}
