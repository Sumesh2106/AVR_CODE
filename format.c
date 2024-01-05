#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>

int hundreds=0,once=0,tense=0;
int value=0;
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int bit_bin[8]={};
    
unsigned int buffer_1=0;
unsigned int rec_data;
void print_bin(void);
void ascii_bin(int data)
{
	
	_delay_ms(100);
	bit_bin[7]=data%2;
	_delay_ms(5);
	buffer_1=data/2;

	_delay_ms(500);
	for(int i=6;i>=0;i--)
	{
		bit_bin[i]=buffer_1%2;
		_delay_ms(50);
		buffer_1=buffer_1/2;	
		_delay_ms(100);

	}
	_delay_ms(1000);
	print_bin();
	_delay_ms(100);
}

void print_bin(void)
{
	
	_delay_ms(500);
	
	for(int i=0;i<8;i++)
	{
		char_write(bit_bin[i]+0x30);
		_delay_ms(50);
	}
}


void send_data(int num1,char num2)
{
	_delay_ms(100);
	
	string_write("0x");
	
	_delay_ms(100);
	char_write(num1+0x30);
	
	_delay_ms(100);
	
	char_write(num2);
	_delay_ms(100);	
	
}

void ascii_hex(int l)
{
	int num1=0,num2=0;
	_delay_ms(100);
		
	for(int i=0;l>=i*16;i++)
	{
		num1=i;
		_delay_ms(100);
		if(l==num1*16)
		{
			num2='0';
			send_data(num1,num2);
		}
	}
	_delay_ms(100);
	while(l!=(num1*16))
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
		l=num1*16;
		
	
		
		
		
	}
	
}
void ascii_dec(int rec)					
{
	_delay_ms(10);
	
	hundreds = rec/100;
	
	rec = rec%100;
	
	char_write(hundreds+48);
	_delay_ms(100);
	
	tense = rec/10;
	
	char_write(tense+48);	
	_delay_ms(100);
	
	
	once = rec%10;
		
	char_write(once+48);	
	_delay_ms(100);
	hundreds=tense=once=0;
}

void start(void)
{
	_delay_ms(500);
	string_write("Enter the ASCII value :");
	_delay_ms(1000);
}

int main(void)
{
	_delay_ms(1000);
	serial_init();
	_delay_ms(1000);
	
	while(1)
	{
		start();
		_delay_ms(500);
		
		rec_data=char_rc();
		_delay_ms(500);
		
		char_write(rec_data);
		_delay_ms(500);
		
		char_write(13);
		_delay_ms(500);
		
		ascii_dec(rec_data);	
		
		_delay_ms(500);
		char_write(13);
		_delay_ms(500);
		
		ascii_hex(rec_data);	
		_delay_ms(500);
		
		char_write(13);
		_delay_ms(500);
		
		ascii_bin(rec_data);
		_delay_ms(500);
		
		char_write(13);
		_delay_ms(500);

	}
}