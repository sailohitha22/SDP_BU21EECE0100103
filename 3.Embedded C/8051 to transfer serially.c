#include <reg51.h>
void main(void)
{
	TMOD = 0X20; //use Timer 1, mode 2
	TH1 = 0XFA; //4800 baud rate
	SCON = 0X50;
	TR1 = 1; //start timer
	while(1)
	{
		SBUF ='B';
		while(TI==0);
		TI=0;
	}
}