#define F_CPU 7372000
#define S_MOTOR_DATA_OUT PORTC

#include "Lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

SIGNAL(TIMER0_OVF_vect);

unsigned char getch(void);
void putch(unsigned char data);

unsigned char stepm[] = {0x1, 0x3, 0x2, 0x6, 0x4, 0xc, 0x8, 0x9, 0x1};
unsigned char mot_cnt = 0;

int main(void)
{
    /*터미널*/
    unsigned char text[] = "   -----------HOME SYSTEM---------- \r\n";
    unsigned char text1[] = "   ----------- MENU ---------------   \r\n";
    unsigned char text2[] = "1. TV Y/N   \r\n";
    unsigned char text3[] = "2. home switch a = 1 room , b= room c = 3 room  \r\n";
    unsigned char text4[] = "3. electric fan on = e / off = w   \r\n";
    unsigned char text5[] = "4. when it gets dark ON/OFF   \r\n";
    unsigned char echo = "echo>> ";
    unsigned char i =0;
    unsigned char c;

    TCCR0 = 0x07;
    TCNT0 = 0xff - 40;

    sei();
    
    //LCD 문자
    Byte str1[] = "TV ON";
    Byte str2[] = "TV OFF";

    DDRA = 0xff; //led 출력
    DDRB = 0xff; //lcd 출력
    DDRC = 0xff; //모터 코드
    DDRE = 0xfe;
    DDRG = 0xff; //RS, RW, E

    //통신 레지스터
    UCSR0A = 0x00;
    UCSR0B = 0x18;
    UCSR0C = 0x06;
    UBRR0H = 0x00;
    UBRR0L = 0x03;

    while(text[i]!='\0') putch(text[i++]);
    i=0;
    while(text1[i]!='\0') putch(text1[i++]);
    i=0;
    while(text2[i]!='\0') putch(text2[i++]);
    i=0;
    while(text3[i]!='\0') putch(text3[i++]);
    i=0;
    while(text4[i]!='\0') putch(text4[i++]);
    i=0;
    while(text5[i]!='\0') putch(text5[i++]);
    i=0;
    while(echo[i]!='\0') puch(echo[i++]);

    Lcd_Init();

    while(1)
    {
        c=getch();
        putch(c);

        //led 불켜기

        if((c=='O')|}(c=='o')) PORTA = 0xff;
        if((c=='X')|}(c=='x')) PORTA = 0x00;

        if((c=='A')|}(c=='a')) PORTA = 0x01; //1번방 불켜기
        if((c=='B')|}(c=='b')) PORTA = 0x02; //2번방 불켜기
        if((c=='C')|}(c=='c')) PORTA = 0x04; //3번방 불켜기

        if((c=='E')|}(c=='e'))
        {
            TIMSK |= 1<<TOIE0;
        }
        if((c=='W')|}(c=='w'))
        {
            TIMSK &= 0<<TOIE0;
        }

        //lcd 켜기

        if((c=='Y')|}(c=='y'))
        {
            Lcd_Pos(0,0);
            Lcd_STR(str1);
            _delay_ms(50);
        }
        if((c=='N')|}(c=='n'))
        {
            Lcd_Pos(0,0);
            Lcd_STR(str2);
            _delay_ms(50);
        }
    }
}

void putch(unsigned char data)
{
    while((UCSR0A&0x20)==0);
    UDR0 = data;
    UCSR0A |=0x20;
}

unsigned char getch(void)
{
    while(!(UCSR0A&(1<<RXC0)));
    return UDR0;
}

SIGNAL(TIMER0_OVF_vect)
{
    TCNT0 = 0xff - 40;

    S_MOTOR_DATA_OUT = stepm[mot_cnt];
    if(mot_cnt++ == 7) mot_cnt = 0;
}