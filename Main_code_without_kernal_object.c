#include <lpc214x.h>
#include <Stdio.h> 
void lcd_init(void);
void delay(unsigned long int);
void cmd(unsigned int );
void data(unsigned int );
void rtc(void);
void extint0_ISR(void)__irq;
unsigned  int adc_value=0,temp_adc=0;
unsigned int i,z,j=0;;
unsigned int lol=0,temp,k=0;
unsigned int thr;
unsigned int thrs=0x00000200;
unsigned int thrr=0x00000250;
unsigned int thrw=0x00000275;
int waterval=15;
char msg1[]={"Plant is SAFE"};//adc_value>thr
char msg2[]={"Moisture lvl:MID"};//adc_valur<thr
char msg3[]={"Filling Water"};
char msg4[]={"TANK-_-_-_-_-"};
char msg5[]={"Water Tank Empty"};
char msg6[]={"Water supply ON"};
char msg7[20];
char msg8[]={"TEAM 3"};
char msg9[]={"Summer season"};
char msg10[20]={"Rainy season"};
char msg11[]={"Winter season"};
int main()
{	    
			PINSEL1  = 0X00040001;       //AD0.4 pin is selected(P0.18)
      IO0DIR   = 0x000F40FC;      //configure o/p lines for lcd AND buzzer
			IO1DIR   = 0x00000000;
			lcd_init();
			rtc();	
			temp=MONTH;
			//interrrupt to fill tank
			EXTMODE=0x00000001;
			VICVectAddr0=(unsigned long)extint0_ISR;
			VICVectCntl0=0x20|14;
			VICIntEnable|=0x00004000;	
							cmd(0x01);
							cmd(0x80);

							for( i=0;i<6;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg8[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);

								
							}
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000);
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000);
									delay(3200000); 
									delay(3200000);
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000); 
									delay(3200000);



															
			while(1)
			{  
					z=MONTH;
					if(temp!=z)
					{													
							k=0;
					}																			
					//CONTROL register for ADC
					AD0CR = 0x09200010;       				  	//command register for ADC-AD0.4
					delay(100);
					while((temp_adc = AD0GDR) == 0x80000000);	//to check the interrupt bit
					adc_value = AD0GDR;          				//reading the ADC value
					adc_value >>=6;
					adc_value=adc_value&0x000003ff;
					while(k<1)
					{
				if(z>=1&&z<=5)
				{
					thr=thrs;
							cmd(0x01);
							cmd(0x80);

							for( i=0;i<13;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg9[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);

								
							}
				}
				else if(z>5&&z<=7)
				{
					thr=thrr;
							cmd(0x01);
							cmd(0x80);

							for( i=0;i<12;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg10[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
							}
				}
				else
				{
					thr=thrw;
							cmd(0x01);
							cmd(0x80);

							for( i=0;i<13;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg11[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);

								
							}
					
						}
						k++;
					}
				if(adc_value>=thr)
				{
							j=0;
							cmd(0x01);
							cmd(0x80);
							//msg1
							for( i=0;i<13;i++)
							{
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									data(msg1[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
							}
							cmd(0xc0);
							//msg2
							for( i=0;i<16;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg2[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
							}
					}
					else if(adc_value<thr)
					{
									if(waterval<10)
									{
											cmd(0x01);
											delay(120000);
											delay(120000);
											cmd(0x80);

										//msg5
											for( i=0;i<16;i++)
											{
														delay(32000); 
														delay(32000); 
														delay(32000); 
														delay(32000);
														data(msg5[i]);
														delay(320000); 
														delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
											}
											
					
									}
									else
									{
											

											//msg6
											IOCLR0=0x00000C00;

											IOSET0=0x00000400;
											IOCLR0=0x00000800;
											delay(120000);
											delay(120000);
											delay(5000000);
										  cmd(0x01);
											cmd(0x80);
											for( i=0;i<15;i++)
											{
														delay(32000); 
														delay(32000); 
														delay(32000); 
														delay(32000);
														data(msg6[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
											}
											sprintf(msg7,"percentage:%d%%",waterval);
											cmd(0xc0);
											for( i=0;i<14;i++)
											{
														delay(32000); 
														delay(32000); 
														delay(32000); 
														delay(32000);
														data(msg7[i]);
														delay(320000); 
														delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
											}
											IOSET0=0x00000800;
											IOCLR0=0x00000400;
											delay(5000000);
											while(j<1)
											{
												waterval=waterval-5;
												j++;
											}
									}
								}
						}
}		
void lcd_init(void)
{
		unsigned int i;
		unsigned  int c[]={0x30,0x20,0x28,0x01,0x06,0x0E,0x80};
		IODIR0=0x000000fc;
		IOCLR0=0x000000fc;
		for(i=0;i<7;i++)
		{
				cmd(c[i]);
				delay(10000);
		}
}
void cmd(unsigned int value)
{
		unsigned int y;
		y=value;
		y=y & 0xf0;
		IOCLR0=0x000000fc;
		IOCLR0=0X00000004;
		IOSET0=y;

		IOSET0=0x00000008;
		delay(10);
		IOCLR0=0x00000008;

		y=value;
		y=y & 0x0f;
		y=y<<4;
		IOCLR0=0x000000fc;
		IOCLR0=0X00000004;
		IOSET0=y; 

		IOSET0=0x00000008;
		delay(10);
		IOCLR0=0x00000008;
}
void data(unsigned int dat)
{
		unsigned int y;
		y=dat;
		y=y & 0xf0;
		IOCLR0=0x000000fc;
		IOSET0=0X00000004;
		IOSET0=y; 
 
		IOSET0=0x00000008;
		delay(10);
		IOCLR0=0x00000008;

		y=dat;
		y=y & 0x0f;
		y=y<<4;
		IOCLR0=0x000000fc;	
		IOSET0=0X00000004;
		IOSET0=y;

		IOSET0=0x00000008;
		delay(10);
		IOCLR0=0x00000008;
}
void delay(unsigned  long int r1)
{
  	unsigned  long int r;
  	for(r=0;r<r1;r++);
}
void rtc(void)
{
PREINT=0X5A;
PREFRAC=0X46C0;
CCR=0X00;
MONTH=2;
CCR=0X01;
}
void extint0_ISR(void)__irq
{
	if(waterval<10)
	{
	lcd_init();
	//PINSEL0=0x00000000;S
	//IODIR0=0x000f0000;
	IOCLR0=0X000f0000; 	// ON LEDS
	delay(100000);	  
	delay(100000);
							cmd(0x01);
		delay(100);
							cmd(0x80);
							//msg1
							for( i=0;i<13;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg3[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
							}
							cmd(0xc0);
							//msg2
							for( i=0;i<13;i++)
							{
									delay(32000); 
									delay(32000); 
									delay(32000); 
									delay(32000);
									data(msg4[i]);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000); 
									delay(320000);
							}
							if( lol<1)
							{
								waterval = 15;
								lol++;
							}
							else
							{
								waterval=100;
							}
							
	
	IOSET0=0X000f0000; 	// ON LEDS

	}
	EXTINT|=0X00000001;	//Clear interrupt flag
	VICVectAddr=0;		// End of interrupt execution
}
