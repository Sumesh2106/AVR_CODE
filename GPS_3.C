#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>

//$GPGGA,180432.00,4027.027912,N,08704.857070,W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73

	char temp[]={},temp1[100];
int j=0,k=0,i=0,count=0;
int attempt=0;


void result(void);
void check_dollar(void);
void check_longi(void);
void check_latit(void);

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
       // char_write(13);
        
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
 
	
	_delay_ms(50);
	check_latit();
	_delay_ms(10);
    check_dollar();

}

char latit[20]={},longi[20]={};
int times=0,buffer=0;

void check_latit(void)		//check n valu
{
	_delay_ms(100);
	char_write(13);
	i=j=0;
	while(1)
	{
		_delay_ms(50);
		
		while(temp1[i]=='N'||temp1[i]=='s')
		{
			int n_index=i;
			_delay_ms(50);
			while(1)
			{
				_delay_ms(5);
				
				if(temp1[n_index]==',')
				{
					
				
					_delay_ms(10);
				
					if(times==0)
					{
						buffer=n_index;
						_delay_ms(50);
						
					}
					
					times++;
					
					_delay_ms(10);
					
					while(times==2)
					{
						_delay_ms(10);
						n_index++;
						
						
						while(n_index==buffer)
						{
							_delay_ms(10);
						
							char_write(13);
							for(int y=0;latit[y]!='\0';y++)
							{
								_delay_ms(5);
								char_write(latit[y]);
							}
							check_longi();
							while(1);
						}
						_delay_ms(5);
						latit[j]=temp1[n_index];
						j++;
						_delay_ms(5);
						
					}
				}
				_delay_ms(8);
				n_index--;
			}	
		}
		_delay_ms(8);
		i++;
	}
}

void check_longi(void)
{
	_delay_ms(100);
	i=0;
	j=0;
	
	while(1)
	{
		_delay_ms(10);
		while(temp1[i]=='W'||temp1[i]=='E')
		{
			int s_index=i;
			_delay_ms(10);
		
		
			while(1)
			{
				_delay_ms(10);
				
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

	DDRB=0x0f;
	_delay_ms(1000);
	
	serial_init();
	
	
		_delay_ms(500);
	while(1)
	{
		_delay_ms(500);
		
		check_dollar();
	}
	
}