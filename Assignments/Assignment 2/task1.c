#include <reg51.h>
unsigned char temp;
void main ()
{
	int ctr;
	P1=0xFF;
	while (1)
	{
		P2 = (P1 & 0x0F) | 0x30; 
		
		for (ctr = 0; ctr < 100; ctr++) // 4s delay
		{
			TMOD = 0x11;
			TL1 = 0xC0;
			TH1 = 0x63;
			TR1 = 1;
			while (TF1 == 0);
			TR1 = 0;
			TF1 = 0;
		} 
		
		temp = P1 & 0xF0;   
		temp = temp >> 4;  
		P2 = temp | 0x30; 
		
		for (ctr = 0; ctr < 100; ctr++) // 4s delay
		{
			TMOD = 0x11;
			TL1 = 0xC0;
			TH1 = 0x63;
			TR1 = 1;
			while (TF1 == 0);
			TR1 = 0;
			TF1 = 0;
		}
	}
}
