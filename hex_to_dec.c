#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include<usart_com.h>
#include <string.h>	
#include <math.h>
int ascii_to_decimal(char c) {
  // A char value in C is implicitly convertible to an int [^1^][1] [^2^][2]
  // We can simply cast the char to an int and return it
 // printf("haiii!");
 _delay_ms(100);
  return (int)c;
}
void ascii_to_decimal_string(char c, char *s) {
  // use sprintf to format the decimal value as a string
  
  sprintf(s, "%d", c);
}
void char_writ(int *data)
{
	UDR=*data;
	while(!(UCSRA&(1<<UDRE)));
	_delay_ms(20);
}
void hd(char hexadecimalnumber[])
{
  int decimalNumber = 0;
    
    // Storing hexa number digits in one array
    char hexDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
     
    int i, j, power = 0;
  
    // Converting hexadecimal number to equivalent decimal
    // number
	_delay_ms(20);
	char_write(hexadecimalnumber);
	
    for (i = strlen(hexadecimalnumber) - 1; i >= 0; i--) {
  
        // search if given input character is present in the
        // array or not. if it present in the array then
        // find the equivalent decimal number for each hexa
        // digit
        for (j = 0; j < 16; j++) {
            _delay_ms(80);
			if (hexadecimalnumber[i] == hexDigits[j]) { 
				_delay_ms(80);
                decimalNumber += j * pow(16, power);
            }
        }
        power++;
		_delay_ms(20);
    }
	_delay_ms(20);
	char_write(decimalNumber);
	_delay_ms(20);
}
int main(void)
{
	serial_init();
	DDRB=0x0f;
//	char data1[8];
	while(1)
	{
		_delay_ms(1000);
		//char_write('a');
		PORTB|=0x01;
		
		//string_write("haii!!");
		
		
		int data=char_rc();
		
		_delay_ms(100);
		
		char_write(data);
		
		char_write(13);
		hd(data);
		//data1=ascii_to_decimal(data); 
		//ascii_to_decimal_string(data, data1);
		
		_delay_ms(100);
		
		//char_write(data1);
		
		//char_write(13);
		
		//char_writ(data1);
		
		//_delay_ms(100);
	}
}
