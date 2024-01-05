#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>

//$GPGGA,180432.00,4027.027912,N,08704.857070,W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73

	char temp[]={},temp1[100];
int j=0,k=0,i=0,count=0;
int attempt=0;
void result(void);
void check_dollar(void);

void check_gpgga(void)
{
	_delay_ms(800);
    char check[6]={'G','P','G','G','A'};
    int k=0;
    PORTB=0x01;
	_delay_ms(800);
    while(1)
    {
        _delay_ms(80);
        if(check[k]==temp1[k])
        {
            _delay_ms(5);
            count++;
            _delay_ms(5);
            if(count==5)
            {
                _delay_ms(10);
                
                result();
            }
            
        }	
        else
        {
            _delay_ms(10);
            check_dollar();
            
        }
        char_write(13);
        
        k++;
        

	}
}

void check_dollar(void)
{
	_delay_ms(50);
    count=j=i=0;
	
	_delay_ms(10); 
	while(1)
	{
		//_delay_ms(10);
		temp[i]=char_rc();
		//_delay_ms(10);
		//PORTB=0x02;

		while(temp[i]=='$')
	    {
			
			//_delay_ms(10);
			PORTB=0x03;
			while(1)
			{
				//_delay_ms(10);
				temp1[j]=char_rc();
				

				//_delay_ms(30);
				
					
					while(temp1[j]=='$')
					{
						_delay_ms(10);
						PORTB=0x0f;
						for(int e=0;temp1[e];e++)
						{
							char_write(temp1[e]);
							_delay_ms(30);
						}
						char_write(13);
						
						check_gpgga();
					}

				
				j++;
				//_delay_ms(10);
			
			}
		}
		//_delay_ms(10);
	    i++;
		//_delay_ms(10);
	}
	
}

void result(void)
{
 
	
	_delay_ms(500);
	
	PORTB=0x0f;
	char_write('P');
	_delay_ms(500);
    check_dollar();

}

int main(void)
{

	DDRB=0x0f;
	_delay_ms(1000);
	
	serial_init();
	_delay_ms(1000);
	//_delay_ms(500);
		char_write('a');
		
		PORTB=0x01;
		_delay_ms(500);
	while(1)
	{
		_delay_ms(500);
		
		check_dollar();
	}
	
}