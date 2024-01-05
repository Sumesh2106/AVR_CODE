#include<avr/io.h>
#include<usart_com.h>
#include<stdio.h>
#include<util/delay.h>
int main(void)
{
	DDRB=0x03;
	DDRA=0x00;		//initialising the adc pin ass input
	
	ADMUX=0x60;			//enabling adc0 channel as adc& 
	
	ADCSRA|=0XA3;		//bit 7:ACEN:ADC Enabled ,Bits 2 : 0  Prescaler Select Bits ,ADPS1=1,ADPS2=1.

	char_write('a');
	_delay_ms(20);
	while(1)
	{
		ADCSRA|=0x40;		//A2D Start Converion-on
		
		while((ADCSRA&ADIF)==1);
		
		int data=ADCH;
		int data1;
		ADCSRA&=~(0x40);	//A2D Start Conversion-off
		_delay_ms(10);
		
		char_write(data);
		char_write(13);
		sscanf(data,"%d",&data1);
		char_write(data1);
	}
}