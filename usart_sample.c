#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
int main(void)
{
	serial_init();
	DDRB=0x0f;

	_delay_ms(1000);
	


	string_write("haii!!");
	char_write(13);
	
	_delay_ms(1000);
		
	while(1)
	{
		PORTB|=0x01;
		char data = char_rc();
		_delay_ms(1000);
		
		
		PORTB=0x00;
		char_write(data);
		_delay_ms(1000);
		
		char_write(13);
		_delay_ms(1000);
	}
}
