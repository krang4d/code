#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Usart.h"

using namespace std;

typedef unsigned int ui;
typedef unsigned char byte;

const int F_CPU 8000000;
const int BAUD 9600;
const int MYUBRR 51;  

byte USART_Receive() static
{
	while ( !(UCSRA & (1<<RXC)) )                   /* Waite for data to be received */
	    ;
	return UDR;                                     /* Get the return received data from buffer */
}

void USART_Transmit(byte data) static
{
	while ( !( UCSRA & (1<<UDRE)) )                 /* Wait for empty transmit buffer */
	    ;
	UDR = data;                                     /* Put data into buffer, sends the data */
}


void usart::init(ui&)
{
	//  Port A Initialization
	DDRA = 0xFF;
	PORTA = 0xFF;

	//   Port B Initialization
	DDRB = 0xFF;
	PORTB = 0xFE;

	//  Port C Initialization
	DDRC = 0xFF;
	PORTC = 0xFF;

	//  Port D Initialization
	DDRD = 0xFF;
	PORTD = 0xFF;

	//  USART Initialization
	UBRRH = (byte)(ubrr>>8);                        /* Set baud rate */
	UBRRL = (byte)ubrr;                             /*               */
	UCSRB = (1<<RXEN) | (1<<TXEN);                  /* Enable receiver and transmitter */
	UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);    /* Set frame format: 8data, 2stop bit */
}

int usart::get_port(const char &chpt) const
{
	if 	(strcmp(chpt, "a") == 0)
		return nA;
	else if (strcmp(chpt, "b") == 0)
		return nB;
	else if (strcmp(chpt, "c") == 0)
		return nC;
	else if (strcmp(chpt, "d") == 0)
		return nD;
}

int usart::set_port(char &chpt, ui &ipt)
{
	if 	(strcmp(chpt, "a") == 0)
		return PORTA = (byte)ipt;
	else if (strcmp(chpt, "b") == 0)
		return PORTB = (byte)ipt;
	else if (strcmp(chpt, "c") == 0)
		return PORTC = (byte)ipt;;
	else if (strcmp(chpt, "d") == 0)
		return PORTD = (byte)ipt;
}
void usart::print_port()
{
	char *status;
	sprintf(status, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
	put_str(status);           // Transmit information data about ports  A, B, C, D;
}
char* usart::get_str()
{
	byte c;
	int i=0;
	while( (c = USART_Receive()) != '\0' && i < 16)
	{
	*(cmd+i) = c;
	++i;
	}
	*(cmd+i) = '\0';

}
void usart::put_str(char *s)
{
	int n = strlen(s), i=0;
	byte c;
	while( n > 0 )
	{
	c = *(s+i);
	USART_Transmit(c);
	--n;
	++i;
	}
	USART_Transmit('\0');
}
void usart::set_atmega16(char* str)
{
	str = usart::Gets();
	for(i = 0; i <= 278; i++)
	{
	    if (strcmp(s, cmd[i]) == 0)
	    {
		if (i>=0 && i<=255)                 //Y0...Y255 (bit 0...7 port A)
		{
		        nA = i;
		        PORTA = (byte)nA;           //write data into port A
		}
		else if (i>=256 && i<=263)          //K0..K7 (bit 0...7 port B)
		{
		        nB ^= (ui)pow(2, (i-256));
		        PORTB = (byte)nB;           //write data into port B
		}
		else if (i>=268 && i<=275)          //K12..K19 (bit 0...7 port C)
		{
		        nC ^= (ui)pow(2, (i-268));
		        PORTC = (byte)nC;           //write data into port C
		}
		else if (i>=264 && i<=267)          //K8..K11 (bit 4...7 port D)
		{
		        nD ^= (ui)pow(2, (i-260));
		        PORTD = (byte)nD;           //write data into port D
		}
		else if (i>=276 && i<=277)          //K20, K21 (bit 2, 3 port D)
		{
		        nD ^= (ui)pow(2, (i-274));
		        PORTD = (byte)nD;           //write data into port D
		}
		else if (i==278)                    //STATUS
		{
		        sprintf(stat, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
		        USART_Puts(stat);           // Transmit information data about ports  A, B, C, D;
		}
	    }
	    else
		USART_Puts("error: bad command!");
	}

}

#endif
