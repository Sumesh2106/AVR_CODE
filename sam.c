#include<avr/io.h>
#include<usart_com.h>
#include<stdio.h>
#include<util/delay.h>
int main(void)
{
	serial_init();
	while(1)
	{
		_delay_ms(500);
		char_write('1'+0x01);
		_delay_ms(500);
		char_write('A'+067);
		
		_delay_ms(500);
		char_write('A'+001);
		if(	(';'<=0x39)	)
		{
			char_write('m');
		}
		else
		{
			char_write('n');
		}
		
		_delay_ms(500);
	}
}