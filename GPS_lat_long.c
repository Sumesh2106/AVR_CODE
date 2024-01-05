#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
void check_latit(void);
char check_longi(void);
//$GPGGA,180432.00,4027.027912,N,08704.857070,W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73
char temp1[100]="$GPGGA,180432.00,4027.027912,N,08704.857070,W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73";
int i=0,j=0;
char latit[20]={},longi[20]={};
int times=0,buffer=0;

void check_latit(void)		//check n valu
{
	_delay_ms(100);
	PORTB=0x02;
	while(1)
	{
		_delay_ms(100);
		while(temp1[i]=='N')
		{
			int n_index=i;
			_delay_ms(100);
		//	char_write(temp1[i]);
			PORTB=0x04;
			while(1)
			{
				_delay_ms(100);
				//char_write(n_index);
				if(temp1[n_index]==',')
				{
					
					//_delay_ms(500);
						//char_write(n_index+0x30);
						//_delay_ms(10);
					//	char_write(temp1[buffer]);
							_delay_ms(10);
							
					if(times==0)
					{
						buffer=n_index;
						_delay_ms(50);
						//char_write('c');
						//char_write(13);
					}
					//char_write(buffer+0x30);
					times++;
					
					_delay_ms(100);
					PORTB=0x03;
					while(times==2)
					{
						_delay_ms(100);
						n_index++;
						PORTB=0x0c;
						
						while(n_index==buffer)
						{
							_delay_ms(10);
							PORTB=0x0f;
							char_write(13);
							for(int y=0;latit[y]!='\0';y++)
							{
								_delay_ms(50);
								char_write(latit[y]);
							}
							check_longi();
							while(1);
						}
						_delay_ms(50);
						latit[j]=temp1[n_index];
						j++;
						_delay_ms(50);
						
					}
				}
				_delay_ms(100);
				n_index--;
			}	
		}
		_delay_ms(100);
		i++;
	}
}

char check_longi(void)
{
	_delay_ms(100);
	i=0;
	j=0;
	
	while(1)
	{
		_delay_ms(100);
		while(temp1[i]=='W')
		{
			int s_index=i;
			_delay_ms(100);
		
		
			while(1)
			{
				_delay_ms(100);
				
				if(temp1[s_index]==',')
				{
					
					_delay_ms(10);
				
					if(times==2)
					{
						buffer=s_index;
						_delay_ms(50);
					}
					
					times++;
					
					_delay_ms(100);

					while(times==4)
					{
						_delay_ms(100);
						s_index++;
						
						
						while(s_index==buffer)
						{
							_delay_ms(10);
							
							char_write(13);
							for(int y=0;longi[y]!='\0';y++)
							{
								_delay_ms(50);
								char_write(longi[y]);
							}
							while(1);
						}
						_delay_ms(50);
						longi[j]=temp1[s_index];
						j++;
						_delay_ms(50);
						
					}
				}
				_delay_ms(100);
				s_index--;
			}	
		}
		_delay_ms(100);
		i++;
	}
}

int main(void)
{
	_delay_ms(500);
	serial_init();
	_delay_ms(500);
	DDRB=0x0f;
	char_write('a');
	while(1)
	{
		_delay_ms(500);
		PORTB=0x01;
		check_latit();
		_delay_ms(500);
		string_write(latit);
		//check_longi();
		_delay_ms(500);
	
	}
}

