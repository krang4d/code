#include "Usart.h"
using namespace ATMega16;

usart::usart()
    :nA(0xFF), nB(0xFE), nC(0xFF), nD(0xFF), f_cpu(8000000), baud(9600), ubrr(51) {
    init();
}

usart::~usart()
    :nA(0xFF), nB(0xFE), nC(0xFF), nD(0xFF), f_cpu(8000000), baud(9600), ubrr(51) {
    init();
}

void usart::init() {
    //  Port A Initialization
    DDRA = 0xFF;
    PORTA = 0xFF;
    //  Port B Initialization
    DDRB = 0xFF;
    PORTB = 0xFE;
    //  Port C Initialization
    DDRC = 0xFF;
    PORTC = 0xFF;
    //  Port D Initialization
    DDRD = 0xFF;
    PORTD = 0xFF;
    //  USART Initialization
    UBRRH = ubrr>>8;                                // Set baud rate
    UBRRL = ubrr;
    UCSRB = (1<<RXEN) | (1<<TXEN);                  // Enable receiver and transmitter
    UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);    // Set frame format: 8data, 2stop bit
}

byte_t usart::receive() {
    while ( !(UCSRA & (1<<RXC)) )                   // Waite for data to be received
	    ;
    return UDR;                                     // Get the return received data from buffer
}

void usart::transmit(byte_t data) {
    while ( !( UCSRA & (1<<UDRE)) )                 // Wait for empty transmit buffer
	    ;
    UDR = data;                                     // Put data into buffer, sends the data
}

byte_t* usart::pull_str(size_t n) { // получает строку с длинной n символов
    byte_t c, *p;
    //int n=15;
    p = (byte_t*)malloc(n*sizeof(byte_t)); //выделение памяти под получаемую строку
    //сюда нужно добавить проверку на то, что память выделена if (p != NULL) {;} esle ERROR("память не выделена");
    if (p != NULL)
    while((c = receive()) != '\0' && i < n) { //заполнение массива
        p[i] = c;
        ++i;
    }
    p[i] = '\0';
    return p;
}

void usart::push_str(byte_t *s, size_t len) { // отправляет строку с длинной len символов
    //int n = strlen(s)
    size_t i=0;
    byte_t c;
    while( len > 0 ) {
    c = *(s+i);
    transmit(c);
    --len;
    ++i;
    }
    transmit('\0');
}

byte_t usart::get_port(char &name_pt) const {
    if 	(!strncmp(name_pt, 'a', 1) || !strncmp(name_pt, 'A', 1))
		return nA;
    else if (!strncmp(name_pt, 'b', 1) || !strncmp(name_pt, 'B', 1))
		return nB;
    else if (!strncmp(name_pt, 'c', 1) || !strncmp(name_pt, 'C', 1))
		return nC;
    else if (!strncmp(name_pt, 'd', 1) || !strncmp(name_pt, 'D', 1))
		return nD;
}

byte_t usart::set_port(char &name_pt, byte_t &i_pt) {
    if 	(!strncmp(name_pt, 'a', 1) || !strncmp(name_pt, 'A', 1)) {
        if (i_pt <= 0xFF){
        nA = i_pt;
        return PORTA = i_pt;
        }
    }
    else if (!strncmp(name_pt, 'b', 1) || !strncmp(name_pt, 'B', 1)) {
        if (i_pt <= 0xFF){
        nB = i_pt;
        return PORTB = i_pt;
        }
    }
    else if (!strncmp(name_pt, 'c', 1) || !strncmp(name_pt, 'C', 1)) {
        if (i_pt <= 0xFF){
        nC = i_pt;
        return PORTC = i_pt;
        }
    }
    else if (!strncmp(name_pt, 'd', 1) || !strncmp(name_pt, 'D', 1)) {
        if (i_pt <= 0xFF){
        nD = i_pt;
        return PORTD = i_pt;
        }
    }
}

void usart::old_set_ports(byte_t RA, byte_t RB, byte_t RC, byte_t RD) {
    byte_t R0 = 1;
    R0 = receive();
    if (R0 == 0) {
        RA = receive();
        RB = receive();
        RC = receive();
        RD = receive();
        transmit(0);
        PORTA = RA;
        PORTB = RB;
        PORTC = RC;
        PORTD = RD;
    }
}

void usart::print_port() const {
    char *str_status;
    sprintf(str_status, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
    size_t len = strlen(str_status);
    put_str(str_status, len);           // Transmit information data about ports  A, B, C, D;
}

char* usart::get_command(size_t cmd_size) {
    char* s = pull_str(cmd_size);
    return s;
}

void usart::set_command(char* s, commands cmd) {
    size_t n = cmd.get_size();
    for(size_t i = 0; i < n; i++) {
        if (!strncmp(s, cmd.get_name(i), strlen(cmd.get_name(i)))) {
        if (i>=0 && i<=255) {                 //Y0...Y255 (bit 0...7 port A)
            nA = i;
            PORTA = nA;           //write data into port A
        }
        else if (i>=256 && i<=263) {          //K0..K7 (bit 0...7 port B)
            nB ^= (byte_t)pow(2, (i-256));
            PORTB = nB;              //write data into port B
        }
        else if (i>=268 && i<=275) {          //K12..K19 (bit 0...7 port C)
            nC ^= (byte_t)pow(2, (i-268));
            PORTC = nC;           //write data into port C
        }
        else if (i>=264 && i<=267) {          //K8..K11 (bit 4...7 port D)
            nD ^= (byte_t)pow(2, (i-260));
            PORTD = nD;           //write data into port D
        }
        else if (i>=276 && i<=277) {          //K20, K21 (bit 2, 3 port D)
            nD ^= (byte_t)pow(2, (i-274));
            PORTD = nD;           //write data into port D
        }
        else if (i==278) {                    //STAT
            sprintf(stat, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
            size_t n = strlen(stat);
            put_str(stat, n);           // Transmit information data about ports  A, B, C, D;
        }
        }
        else push_str("error: command not found!", 25); // возможно придется делать перегрузку для push_str(const chat*, size_t)
    }
    free(s);
}
//void usart::zarya(size_t cmd_size) {
//    byte_t *s = pull_str(cmd_size);
//    size_t n = cmd.getsize();
//    for(size_t i = 0; i < n; i++) {
//        if (!strncmp(s, cmd.GetName(i), strlen(cmd.GetName(i)))) {
//        if (i>=0 && i<=255) {                 //Y0...Y255 (bit 0...7 port A)
//            nA = i;
//            PORTA = nA;           //write data into port A
//		}
//        else if (i>=256 && i<=263) {          //K0..K7 (bit 0...7 port B)
//            nB ^= (byte_t)pow(2, (i-256));
//            PORTB = nB;              //write data into port B
//		}
//        else if (i>=268 && i<=275) {          //K12..K19 (bit 0...7 port C)
//            nC ^= (byte_t)pow(2, (i-268));
//            PORTC = nC;           //write data into port C
//		}
//        else if (i>=264 && i<=267) {          //K8..K11 (bit 4...7 port D)
//            nD ^= (byte_t)pow(2, (i-260));
//            PORTD = nD;           //write data into port D
//		}
//        else if (i>=276 && i<=277) {          //K20, K21 (bit 2, 3 port D)
//            nD ^= (byte_t)pow(2, (i-274));
//            PORTD = nD;           //write data into port D
//		}
//        else if (i==278) {                    //STAT
//            sprintf(stat, "A:%d, B:%d, C:%d, D:%d", nA, nB, nC, nD);
//            size_t n = strlen(stat);
//            put_str(stat, n);           // Transmit information data about ports  A, B, C, D;
//		}
//	    }
//        else push_str("error: command not found!", 25); // возможно придется делать перегрузку для push_str(const chat*, size_t)
//	}
//    free(s);
//}
#endif
