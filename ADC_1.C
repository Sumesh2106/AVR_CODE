#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRB=0x03;
	DDRA=0x00;		//initialising the adc pin ass input
	
	ADMUX=0x60;			//enabling adc0 channel as adc& 
	
	ADCSRA|=0X83;		//bit 7:ACEN:ADC Enabled ,Bits 2 : 0  Prescaler Select Bits ,ADPS1=1,ADPS2=1.

	
	while(1)
	{
		ADCSRA|=0x40;		//A2D Start Converion-on
		
		while((ADCSRA&ADIF)==1);
		
		int data=ADCH;
		
		ADCSRA&=~(0x40);	//A2D Start Conversion-off
		
		if(data>150)
		{
			PORTB=0x01;
		}
		
		else
		{
			PORTB=0x02;
		}
	}
}