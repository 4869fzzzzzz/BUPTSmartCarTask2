#include <REGX52.H>

void Delay20ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 216;
	j = 37;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	EA=1;//�����жϿ���
	EX0=1;//���ⲿ�ж�0
	IT0=1;//�����ⲿ�жϵĴ�����ʽ
	while(1);
}

void int0() interrupt 0
{
	Delay20ms();
	if(P3_2==0)
		P2_0 = ~P2_0;
}
