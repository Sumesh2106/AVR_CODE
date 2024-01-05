
#include<avr/io.h>
#include<util/delay.h>


void FASTPWM_init(void)
{
	TCCR0=0x79;		//INVERT
    TCCR1A = (1 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);		//NON INVERT
	TCCR1B = (1 << WGM12) | (1 << CS10);
	TCCR2=0x79;		//INVERT
	DDRB|=0x08;
	DDRD|=(1<<PD5)|(1<<PD4)|(1<<PD7);

	_delay_ms(5);
	//ICR1=625;
	
	OCR0=0;
	OCR1A = 0;
    OCR1B = 0;	OCR2=0;
	
	_delay_ms(5);
}
int main(void)
{
	_delay_ms(500);
	
//	unsigned int duty;
	
	_delay_ms(500);
	
	FASTPWM_init();
	_delay_ms(10);
	
	while(1)
	{
		
		
	
		_delay_ms(200);
		for (int i = 0; i <= 255; i++) 
		{
          
			
			OCR0=i;
			_delay_ms(30);
        }
		_delay_ms(200);
		for (int i = 255; i >= 0; i--) 
		{
            
            OCR0 = i;
			_delay_ms(30);
        }
		_delay_ms(200);
		for (int i = 0; i <= 255; i++) 
		{
            
            OCR1A= i;
			
			_delay_ms(30);
        }


        
        // Gradually decrease the duty cycle for OC1A and OC1B
        _delay_ms(200);
		for (int i = 255; i >= 0; i--) 
		{
            
            OCR1A = i;
			_delay_ms(30);
        }
		_delay_ms(200);
		for (int i = 0; i <= 255; i++) 
		{
          
			
			OCR1B=i;
			_delay_ms(30);
        }
		_delay_ms(200);
		for (int i = 255; i >= 0; i--) 
		{
            
            OCR1B= i;
			_delay_ms(30);
        }
		_delay_ms(200);
	
		
		for (int i = 0; i <= 255; i++) 
		{
          
			
			OCR2=i;
			_delay_ms(30);
        }
		_delay_ms(200);
		for (int i = 255; i >= 0; i--) 
		{
            
            OCR2 = i;
			_delay_ms(30);
        }
		_delay_ms(200);	
        
		
 
	}
}