#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>

#include<Format.h>
int main(void)

{
	DDRA=0x00;
	
	_delay_ms(1000);
	serial_init();
	_delay_ms(1000);
	
	ADMUX|=0X60;
	ADCSRA|=0X83;
	_delay_ms(900);
	char_write('1');
	_delay_ms(900);
	
	while(1)
	{
		ADMUX=0x60;
		_delay_ms(500);
		
		ADCSRA|=0x40;
		
		while((ADCSRA&ADIE)==1);
		_delay_ms(500);
		ADCSRA&=~(0x40);
		
		int data=ADC;
		_delay_ms(5);
		char_write(13);
		_delay_ms(5);
		
		string_write("ADC0:");
		_delay_ms(5);
		ascii_dec(data);
		
		ADMUX=0x61;
		_delay_ms(500);
		
		ADCSRA|=0x40;
		while((ADCSRA&ADIE)==1);
		_delay_ms(500);
		
		ADCSRA&=~(0x40);
		
		data=ADC;
		char_write(13);
		_delay_ms(5);
		string_write("ADC1:");
		_delay_ms(5);
		
		_delay_ms(5);
		ascii_dec(data);
		
		_delay_ms(400);
		
	}

}