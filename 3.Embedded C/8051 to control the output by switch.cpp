#include <reg51.h>
sbit sw1 = P2^1;
sbit sw2 = P2^2;
void delay(unsigned int);
void main(void)
{
	sw1 = 0;
	sw2 = 0;
	while(1)
	{
		if(sw1==0 && sw2==0)
		{
			P1=0x00;
		}
			else if (sw1==0 && sw2==1)
			{
				P1=0xAA;
			}
			else if (sw1==1 && sw2==0)	
			{
				P1=0x55;
			}
			else if (sw1==1 && sw2==1)	
			{
			//while(1)   // repeat forever
				//{
					P1=0x55; // toggle all bits of P1
					delay(5000); // calling delay
					P1=0xAA; // toggle all bits of P1
					delay(5000); // calling delay
				//}
			}
		}
	}
void delay(unsigned int time)
{
	unsigned int i, j;
	for (i=0;i<time;i++)
		for (j=0;j<1275;j++);
}