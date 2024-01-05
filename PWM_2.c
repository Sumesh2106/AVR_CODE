#include<avr/io.h>
#include<util/delay.h>
void FASTPWM_init(void)
{
	TCCR0=0x79;
	DDRB|=0x08;
	OCR0=255;
}
int main(void)
{
	_delay_ms(500);
	
	unsigned int duty;
	
	_delay_ms(500);
	
	FASTPWM_init();
	_delay_ms(10);
	
	while(1)
	{
		_delay_ms(100);
		
		for(duty=255;duty>0;duty--)
		{
			OCR0=duty;
			_delay_ms(20);
			
		}
		_delay_ms(200);
		for(duty=0;duty<=255;duty++)
		{
			OCR0=duty;
			_delay_ms(50);
			
		}
		_delay_ms(50);
	}
}