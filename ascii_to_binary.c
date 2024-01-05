#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
int main(void)
{
    int bit_0=0,bit_1=0,bit_2=0,bit_3=0,bit_4=0,bit_5=0,bit_6=0,bit_7=0;
    
	unsigned int buffer_1=0;
    
	int rec_data;
	DDRB=0x01;

	_delay_ms(1000);
	
	serial_init();
	_delay_ms(1000);
    
	char_write('1');
	_delay_ms(1000);
	while(1)
	{
		
		_delay_ms(1000);
		rec_data=char_rc();
		
		_delay_ms(500);
		
		char_write(rec_data);
		_delay_ms(500);
		char_write('0');
		_delay_ms(500);
		while(buffer_1!=0)
		{
			_delay_ms(500);
			PORTB=0x01;
			bit_7=rec_data%2;
			_delay_ms(5);
			buffer_1=rec_data/2;
			
			_delay_ms(5);
			bit_6=buffer_1%2;
			_delay_ms(5);
			buffer_1=buffer_1/2;
			
			_delay_ms(5);
			bit_5=buffer_1%2;
			_delay_ms(5);
			buffer_1=buffer_1/2;
			
			_delay_ms(5);
			bit_4=buffer_1%2;
			_delay_ms(5);
			buffer_1=buffer_1/2;
			
			_delay_ms(5);
			bit_3=buffer_1%2; 
			_delay_ms(5);
			buffer_1=buffer_1/2;
			
			_delay_ms(5);
			bit_2=buffer_1%2;
			buffer_1=buffer_1/2;
			
		
			
			bit_1=buffer_1%2;
			buffer_1=buffer_1/2;
			
			 
			
			
			bit_0=buffer_1%2;
			buffer_1=buffer_1/2;
			
			_delay_ms(500);
		}
    
			PORTB=0x00;
			_delay_ms(100);
			char_write(13);
			char_write(bit_0+0x30);
			_delay_ms(100);
			char_write(bit_1+0x30);
			_delay_ms(100);
			char_write(bit_2+0x30);
			_delay_ms(100);
			char_write(bit_3+0x30);
			_delay_ms(100);
			
			char_write(bit_4+0x30);
			_delay_ms(100);
			char_write(bit_5+0x30);
			_delay_ms(100);
			char_write(bit_6+0x30);
			_delay_ms(100);
			char_write(bit_7+0x30);
			_delay_ms(500);

    }
}