#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void send_data(int num1,char num2)
{
	_delay_ms(100);
	char_write(13);
	
	_delay_ms(100);
	string_write("0x");
	
	_delay_ms(100);
	char_write(num1+0x30);
	
	_delay_ms(100);
	
	char_write(num2);
	_delay_ms(100);
	
	char_write(13);
	
}

void option(int l)
{
	int num1=0,num2=0;
	_delay_ms(100);
	while(l==1)
	
	{
		_delay_ms(500);
		string_write("Enter the ASCII value :");
		_delay_ms(1000);
		unsigned int rec_data=char_rc();
		_delay_ms(100);
		for(int i=0;rec_data>=i*16;i++)
		{
			num1=i;
			_delay_ms(100);
			if(rec_data==num1*16)
			{
				num2='0';
				send_data(num1,num2);
			}
		}
		_delay_ms(100);
		while(rec_data!=(num1*16))
		{
			_delay_ms(100);
			
			int sum=num1*16;
			num2=rec_data-sum;
			
			_delay_ms(100);
			
			if(num2<=15)
			{
				_delay_ms(100);
				num2=hex[num2];
				_delay_ms(100);
				send_data(num1,num2);
			}
			
			
			_delay_ms(1000);
			rec_data=num1*16;
			
		
			
			
			
		}
	}
}

int main(void)
{
	//int hundreds=0,once=0,tense=0;
//	int value=0;
	serial_init();
	DDRB=0x03;
	PORTB=0x03;
	_delay_ms(1000);
	PORTB=0x01;
	//_delay_ms(1000);
	char_write('a');
	PORTB=0x02;
	_delay_ms(100);
	
	while(1)
	{
		//hundreds=tense=once=0;
		char_write(13);
		_delay_ms(500);
		string_write("Enter the value :");
		char_write(13);
		_delay_ms(1000);
		unsigned int rec_data=char_rc();
		
		
		_delay_ms(100);
		if(rec_data=='1')
		{
			option(1);
			_delay_ms(100);
		}
		_delay_ms(100);
		
		
	}
}