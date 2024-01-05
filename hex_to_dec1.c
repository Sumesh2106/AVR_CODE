#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
int main(void)
{
	int hundreds=0,once=0,tense=0;
	int value=0;
	serial_init();
	_delay_ms(1000);
	
	while(1)
	{
	hundreds=tense=once=0;
	unsigned int rec_data=char_rc();
		
	_delay_ms(10);
	
	hundreds = rec_data/100;
	
	rec_data = rec_data%100;
	
	char_write(hundreds+48);
	_delay_ms(100);
	
	tense = rec_data/10;
	
	char_write(tense+48);	
	_delay_ms(100);
	
	
	once = rec_data%10;
		
	char_write(once+48);	
	_delay_ms(100);
	
	char_write(13);	
	_delay_ms(100);
	
	}
}