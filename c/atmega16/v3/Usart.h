#ifndef USART_H
#define USART_H

typedef unsigned int ui;
typedef unsigned char byte;

class usart
{
	private:
		byte nA, nB, nC, nD;
	public:
		void init(ui&);
		int get_port(byte&) const;
		int set_port(byte&, int&);
        void print_port() const;
        void put_str(char*, int);
        void set_atmega16();
        usart();
        ~usart();
}

#endif
