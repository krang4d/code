#ifndef USART_H
#define USART_H

typedef unsigned int ui;
typedef unsigned char byte;

class usart
{
	private:
		unsigned char nA, nB, nC, nD;
	public:
		void init(ui&);
		int get_port(byte&) const;
		int set_port(byte&, int&);
        void print_port() const;
        void put_str(char*, int len);
        void set_atmega16();
}

#endif
