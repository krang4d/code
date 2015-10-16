#ifndef USART_H
#define USART_H

#include </usr/lib/avr/include/avr/iom16a.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <commands.h>

namespace ATMega16 {
#define COMMAND_SIZE 8 // длинна комманды

typedef unsigned char byte_t;

class usart {
    private:
        unsigned int f_cpu;
        unsigned int baud;
        unsigned int ubrr;
        byte_t nA, nB, nC, nD;
        commands cmd;

    protected:
        void init();                                    // инициализация контроллера
        void transmit(byte_t data);                     // отправка символа
        byte_t receive();                               // получение символа
        byte_t* pull_str(size_t n);                     // получение строки с указанной длинной (n)
        void push_str(byte_t *s, size_t len);           // отправка строку с указанной длинной (len)
        byte_t get_port(char &name_pt) const;           // получение значения пота (name_pt)
        byte_t set_port(char &name_pt, byte_t &i_pt);   // установка значения (i_pt) порта (name_pt)
        void old_set_ports(char RA, char RB, char RC, char RD); //первая версия программы для контроллера

	public:
        usart();
        ~usart();
        char* get_command(size_t cmd_size);
        void set_command(char*, commands);
        void print_port() const;                        // отправка статуса по портам контроллера
        //void zarya(size_t cmd_size);                  // отработка полученной комманды
};
}
#endif
