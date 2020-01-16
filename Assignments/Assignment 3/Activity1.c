# include <reg51.H>
	
void Ldelay()
{
		unsigned int j;
for(j=0;j<32800;j++);
}
void senddata(char dat)
{
		SBUF = dat;
		while (TI == 0);
		TI = 0;
}
void initiallize()
{
		SCON  = 0x50;     /* SCON: mode 1, 8-bit UART, enable rcvr    */
		TMOD  = 0x20;     /* TMOD: timer 1, mode 2, 8-bit reload      */
		TH1   = -3; 
		TR1 = 1;
}
	
char first[10] = { 'M', 'U', 'H', 'A', 'M', 'M', 'A', 'D', '\0', '\0' };
char last[10] = { 'R', 'E', 'H', 'M', 'A', 'N', '\0', '\0', '\0', '\0' };
void main()
{
		initiallize();
		while(1)
		{
			int i;
			for (i = 0; last[i] != '\0'; i++)
				senddata(last[i]);
			senddata(' ');
			for (i = 0; first[i] != '\0'; i++)
				senddata(first[i]);
			senddata(' ');
			Ldelay();
		}
}
