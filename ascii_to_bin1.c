#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>

int bit_bin[8]={};
    
unsigned int buffer_1=0;
    
int rec_data;

void print_bin(void);
void ascii_bin(int data)
{
	//while(buffer_1!=1)
	//{
		_delay_ms(100);
		bit_bin[7]=data%2;
		_delay_ms(5);
		buffer_1=data/2;


	
	_delay_ms(1000);
	
	
		for(int i=6;i>=0;i--)
		{
			bit_bin[i]=buffer_1%2;
			_delay_ms(50);
			buffer_1=buffer_1/2;
			
			_delay_ms(100);

		}
		
	//}
	
	_delay_ms(1000);
	print_bin();
	_delay_ms(100);
}

void print_bin(void)
{
	_delay_ms(500);
	char_write(13);
	_delay_ms(500);
	string_write("PRINTING THE BIN: ");
	_delay_ms(500);

	for(int i=0;i<8;i++)
	{
		char_write(bit_bin[i]+0x30);
		_delay_ms(50);
	}
}
int main(void)
{
   

	

	
	_delay_ms(1000);
	
	serial_init();
	
	_delay_ms(1000);
	while(1)
	{
		
		_delay_ms(1000);
		rec_data=char_rc();
		
		_delay_ms(500);
	

		char_write(rec_data);
		_delay_ms(500);

		
		ascii_bin(rec_data);
		_delay_ms(500);
		char_write(13);
		_delay_ms(500);
    }
}