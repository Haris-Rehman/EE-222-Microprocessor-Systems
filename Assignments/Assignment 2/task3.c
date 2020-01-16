#include <reg51.h>

unsigned char A1= 0x39; 
unsigned char A2=0x37; 

void main()
{
	A1 = A1 & 0x0F;  // ANDing lower 4 bits of input ascii-1
	A1 = A1 << 4;    // shift left by 4
	A2 = A2 & 0x0F;  // ANDing lower 4 bits of input ascii-2
	P2 = A1 | A2; 	 // packed BCD
}
