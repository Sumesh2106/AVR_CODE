#include<util/delay.h>

void serial_init(void)
{
	UBRRH=0x00;
	UBRRL=0x0c;
	UCSRA=0x02;
	UCSRB=0x18;
	UCSRC=0x86;
	_delay_ms(1000);
	
}
	
void char_write(char data)
{
	UDR=data;
	while(!(UCSRA&(1<<UDRE)));
	_delay_ms(20);
}
	
void string_write(char *a)
{
	
	for (int i=0;a[i]!='\0';i++)
	{
		char_write(a[i]);	
		_delay_ms(10);
	}

}

char char_rc(void)
{
	while(!(UCSRA&(1<<RXC)));
	
	_delay_ms(1);
	
	return (UDR);
}




