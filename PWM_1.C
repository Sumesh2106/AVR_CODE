#include<avr/io.h>
#include<util/delay.h>
void FASTPWM_init(void)
{
	TCCR1A=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
	TCCR1B=(1<<WGM12)|(1<<CS10);
	_delay_ms(5);
	ICR1=625;
	DDRD|=(1<<PD5);
	_delay_ms(5);
}
int main(void)
{
	_delay_ms(500);
	
	unsigned int duty;
	
	_delay-ms(500);
	
	FASTPWM_init();
	_delay_ms(10);
	
	while(1)
	{
		
		
	
		_delay_ms(200);
		for(duty=0;duty<=255;duty++)
		{
			OCR0=duty;
			_delay_ms(50);
			
		}
		_delay_ms(50);
			for(duty=255;duty>0;duty--)
		{
			OCR0=duty;
			_delay_ms(20);
			
		}
		_delay_ms(100);
	}
}