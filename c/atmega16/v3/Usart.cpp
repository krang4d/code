#include </usr/lib/avr/include/avr/iom16a.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Usart.h"

using namespace std;

typedef unsigned int ui;
typedef unsigned char byte;

inline const int F_CPU = 8000000;
inline const int BAUD = 9600;
inline const int MYUBRR = 51;

byte USART_Receive()
{
	while ( !(UCSRA & (1<<RXC)) )                   /* Waite for data to be received */
	    ;
	return UDR;                                     /* Get the return received data from buffer */
}

void USART_Transmit(byte data)
{
	while ( !( UCSRA & (1<<UDRE)) )                 /* Wait for empty transmit buffer */
	    ;
	UDR = data;                                     /* Put data into buffer, sends the data */
}

byte* get_str()
{
    byte c, *p;
    int n=15;
    p = (byte*)malloc(n*sizeof(byte)); //выделение память под массив
    while( (c = USART_Receive()) != '\0' && i < n) //заполнение массива
    {
        p[i] = c;
        ++i;
    }
    p[i] = '\0';
    return p;
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

int usart::get_port(const char &name_pt) const
{
    if 	(strcmp(name_pt, "a") == 0 || strcmp(name_pt, "A" == 0))
		return nA;
    else if (strcmp(name_pt, "b") == 0 || strcmp(name_pt, "A" == 0))
		return nB;
    else if (strcmp(name_pt, "c") == 0 || strcmp(name_pt, "A" == 0))
		return nC;
    else if (strcmp(name_pt, "d") == 0 || strcmp(name_pt, "A" == 0))
		return nD;
}

int usart::set_port(char &name_pt, ui &i_pt)
{
    if 	(strcmp(name_pt, "a") == 0 || strcmp(name_pt, "A" == 0))
    {
        nA = i_pt;
        return PORTA = (byte)i_pt;
    }
    else if (strcmp(name_pt, "b") == 0 || strcmp(name_pt, "B" == 0))
    {
        nB = i_pt;
        return PORTB = (byte)i_pt;
    }
    else if (strcmp(name_pt, "c") == 0 || strcmp(name_pt, "C" == 0))
    {
        nC = i_pt;
        return PORTC = (byte)i_pt;
    }
    else if (strcmp(name_pt, "d") == 0 || strcmp(name_pt, "D" == 0))
    {
        nD = i_pt;
        return PORTD = (byte)i_pt;
    }
}

usart::put_str(char *s, int len)
{
    //int n = strlen(s)
    i=0;
	byte c;
    while( len > 0 )
    {
	c = *(s+i);
	USART_Transmit(c);
	--n;
	++i;
	}
	USART_Transmit('\0');
}

void usart::print_port() const
{
    char *status;
    sprintf(status, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
    int len = strlen(status);
    put_str(status, len);           // Transmit information data about ports  A, B, C, D;
}

void usart::set_atmega16()
{
    const char *cmd[] =
            {
        "Y0",   "Y1",   "Y2",   "Y3",   "Y4",   "Y5",   "Y6",   "Y7",   "Y8",   "Y9",   "Y10",  "Y11",  "Y12",
        "Y13",  "Y14",  "Y15",  "Y16",  "Y17",  "Y18",  "Y19",  "Y20",  "Y21",  "Y22",  "Y23",  "Y24",  "Y25",
        "Y26",  "Y27",  "Y28",  "Y29",  "Y30",  "Y31",  "Y32",  "Y33",  "Y34",  "Y35",  "Y36",  "Y37",  "Y38",
        "Y39",  "Y40",  "Y41",  "Y42",  "Y43",  "Y44",  "Y45",  "Y46",  "Y47",  "Y48",  "Y49",  "Y50",  "Y51",
        "Y52",  "Y53",  "Y54",  "Y55",  "Y56",  "Y57",  "Y58",  "Y59",  "Y60",  "Y61",  "Y62",  "Y63",  "Y64",
        "Y65",  "Y66",  "Y67",  "Y68",  "Y69",  "Y70",  "Y71",  "Y72",  "Y73",  "Y74",  "Y75",  "Y76",  "Y77",
        "Y78",  "Y79",  "Y80",  "Y81",  "Y82",  "Y83",  "Y84",  "Y85",  "Y86",  "Y87",  "Y88",  "Y89",  "Y90",
        "Y91",  "Y92",  "Y93",  "Y94",  "Y95",  "Y96",  "Y97",  "Y98",  "Y99",  "Y100", "Y101", "Y102", "Y103",
        "Y104", "Y105", "Y106", "Y107", "Y108", "Y109", "Y110", "Y111", "Y112", "Y113", "Y114", "Y115", "Y116",
        "Y117", "Y118", "Y119", "Y120", "Y121", "Y122", "Y123", "Y124", "Y125", "Y126", "Y127", "Y128", "Y129",
        "Y130", "Y131", "Y132", "Y133", "Y134", "Y135", "Y136", "Y137", "Y138", "Y139", "Y140", "Y141", "Y142",
        "Y143", "Y144", "Y145", "Y146", "Y147", "Y148", "Y149", "Y150", "Y151", "Y152", "Y153", "Y154", "Y155",
        "Y156", "Y157", "Y158", "Y159", "Y160", "Y161", "Y162", "Y163", "Y164", "Y165", "Y166", "Y167", "Y168",
        "Y169", "Y170", "Y171", "Y172", "Y173", "Y174", "Y175", "Y176", "Y177", "Y178", "Y179", "Y180", "Y181",
        "Y182", "Y183", "Y184", "Y185", "Y186", "Y187", "Y188", "Y189", "Y190", "Y191", "Y192", "Y193", "Y194",
        "Y195", "Y196", "Y197", "Y198", "Y199", "Y200", "Y201", "Y202", "Y203", "Y204", "Y205", "Y206", "Y207",
        "Y208", "Y209", "Y210", "Y211", "Y212", "Y213", "Y214", "Y215", "Y216", "Y217", "Y218", "Y219", "Y220",
        "Y221", "Y222", "Y223", "Y224", "Y225", "Y226", "Y227", "Y228", "Y229", "Y230", "Y231", "Y232", "Y233",
        "Y234", "Y235", "Y236", "Y237", "Y238", "Y239", "Y240", "Y241", "Y242", "Y243", "Y244", "Y245", "Y246",
        "Y247", "Y248", "Y249", "Y250", "Y251", "Y252", "Y253", "Y254", "Y255",
        "K0",   "K1",   "K2",   "K3",   "K4",   "K5", "K6", "K7", "K8", "K9", "K10", "K11", "K12", "K13", "K14",
        "K15", "K16", "K17", "K18", "K19", "K20", "K21", "STATUS"
        };
    byte *s = get_str();
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
                int n = strlen(stat);
                put_str(stat, n);           // Transmit information data about ports  A, B, C, D;
		}
	    }
	    else
		USART_Puts("error: bad command!");
	}
    free(s);

}

usart::usart()
    :pA(255), pB(254), pC(255), pD(255)
{

}

usart::~usart()
{

}

#endif
