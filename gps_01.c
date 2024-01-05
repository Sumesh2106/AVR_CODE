#include<avr/io.h>
#include<util/delay.h>
#include<usart_com.h>
//$GPGGA,180432.00,4027.027912,N,08704.857070, W,2,07,1.0,212.15,M,-33.81,M,4.2,0555*73
char data[20][100],data1[80],latit[13],logi[13],GPGGA[5]={'G','p','G','G','A'};
int row=0,colm=0,i=0,j=0,m=0;

void chck_gpgga(void)
{
	data[row][colm]=char_rc();
    colm++;
	_delay_ms(2);
    for(;data[row][colm]!='$';colm++)
    {
//data[i][j]=char_rc();

   	 _delay_ms(2);
   	 /*if(data[i][j]=='G')
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
   						j++;*/
		
		 i=row;
		 j=col;
		 
   						 
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
	data
	chick=0
	for(int i=7;i<row_end_index;i++)
	{
		if(chick<=1)
		{
			while (data01[i]=='N')
			{
				N_index=i;
				End_flag=N_index-1;
				for(int j=N_index;j>7;j--)   
				{	
					if(data01[j]==',')
					{	   
					    Start_flag=j+1;
						
					    for(;Start_flag<End_flag;Start_flag++)
					    {
					   
							char_write(data01[Start_flag]);
							
						}
						
						j=0;
						
					}		 
				}
				chick++;
				i++;
			
			}
			while(data02[i]=='w')
			{
				W_index=i;
				End_flag1=W_index-1;
				for(int j=W_index;j>7;j--)   
				{
					if(data01[j]==',')
					{		  
						Start_flag1=j+1;
						for(;Start_flag1<End_flag;Start_flag1++)
						{
							char_write(data01[Start_flag1]);
						}
						
						j=0;
						
					}
				}
				chick++;
				i++;
			}						 
		}
	}
}

void chck_dollar(void)
{
    while(1)
    {
		data1[m]=char_rc();
		_delay_ms(2);

		while(data1[m]=='$')
		{
			/*_delay_ms(2);
			data[i][m]=char_rc();
			
			m++;
			
			_delay_ms(2);
			
			//for(;data[i][m]!='$';m++)
			*/
			
			
			while(1)
			{
				data[row][colm]=char_rc();
				_delay_ms(2);

				while(data[row][colm]=='$')
				{
					row++;
					colm=0;
					
					//end1=j-1;
					//chck_ns()
				}
				colm++;
			}

		}
		m++;
	}
}

int main(void)
{
    serial_init();
    chck_dollar();
}
