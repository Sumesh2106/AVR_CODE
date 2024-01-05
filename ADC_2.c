#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRB=0x0f;
	DDRA=0x00;		//initialising the adc pin ass input
	
	ADMUX|=0x60;			//enabling adc0 channel as adc& 
	
	
	ADCSRA|=0X83;		//bit 7:ACEN:ADC Enabled ,Bits 2 : 0  Prescaler Select Bits ,ADPS1=1,ADPS2=1.

	
	while(1)
	{
		ADCSRA|=0x40;		//A2D Start Converion-on
		
		while((ADCSRA&ADIF)==1);
		
		int data=ADCH;
		
		ADCSRA&=~(0x40);	//A2D Start Conversion-off
		
		_delay_ms(500);
		
		ADCSRA|=(1<<ADATE);
		
		if(ADMUX == 0X60)
		{
			_delay_ms(100);
			if(data>150)
			{
				PORTB|=0x01;
				
				PORTB&=~(0x02);
			}
			
			else
			{
				PORTB&=~(0x01);
				PORTB|=0x02;
			}
		}

		if(ADMUX == 0x61)
		{
			if(data>150)
			{
				PORTB&=~(0x08);
				PORTB|=0x04;
			}
			
			else
			{
				PORTB|=0x08;
				PORTB&=~(0x04);
			}
		}
		//ADMUX|=(1<<MUX0);


		
	}
}