#include <REGX51.H>
void main()
{
	unsigned char input;
	unsigned char ctr1;
	unsigned char ctr2;
	unsigned char ctr3;
	unsigned char ctr4;
	while (1)
	{
		for (ctr4 = 0; ctr4 < 20; ctr4++)
			for (ctr2 = 0; ctr2 < 255; ctr2++)
				for (ctr3 = 0; ctr3 < 255; ctr3++);
		if (P3 != 0x00) 
			P3 = 0x00;
		if (P1 > 0x99 || (P1 % 16) > 9)
		{
			P3 = 0x01;
			P2 = 0x00;
		}
		else
			P2 = P1;
	}
}
