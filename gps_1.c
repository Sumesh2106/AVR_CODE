 
//Second attempt

#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
//$GPGGA,180432.00,4027.027912,N,08704.857070, W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73
char data[20][100],i=0,j=0,data1[80],latit[13],logi[13];
int row=0,col=0;

void chck_gpgga(void)
{
    J++;
    for(;data[i][j]!='$';j++;)
    {
//data[i][j]=char_rc();

   	 _delay_ms(2);
   	 if(data[i][j]=='G')
   	 {
   		 data[i][j]=char_rc();
   		 j++;    
   		 if(data[i][j]=='P')
   		 {
		  	data[i][j]=char_rc();
   			j++;
   			if(data[i][j]=='G')
   			{
   				data[i][j]=char_rc();
   				j++;
   				if(data[i][j]=='G')
   				{
   					data[i][j]=char_rc();
   					j++;
   					if(data[i][j]=='A')
   					{
   						_delay_ms(2);
   						j++;
   						while(1)
   						{
   							data[i][j]=char_rc();
   							 _delay_ms(2);
   							 
   							 while(data[i][j]=='$')
   							 {
   								 end1=j-1;
   								 chck_ns()
   							 }
   							 j++;
   						 }
   						 row=i;
   						 col=j;
   						 
   						 
   					 }
   				 }
   			 }
   		 }
   	 }
   	 else
   	 {
   		 chck_dollar();
   	 }
    }
}


 void chck_ns()
 {
    int k=col;					//data end index value
    for(;col<=col1;col++)
    {
		data1[col]=data[i][col];
		if(col<col1)
		{
			if(data1[k]=='N')
			{
				for(int y;data1[k]==44;--k)
				{


				}
			}
			if(data1[k]=='W')
			{

			}
			k++;
		}
    }
    
 }

void chck_dollar(void)
{
    while(1)
    {
		data[i][j]=char_rc();
		_delay_ms(2);

		while(data[i][j]=='$')
		{
			_delay_ms(2);
			chck_gpgga();

		}
		j++;
	}
}
int main(void)
{
    serial_init();
    chck_dollar();
}
