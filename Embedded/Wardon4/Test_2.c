#include <REGX52.H>

/*��ʱ��0��ʼ��*/
void Timer0_Init(void)		//1����@11.0592MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}
void main()
{
	Timer0_Init();
	while(1)
	{
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;				//���ö�ʱ��ʼֵ
	TH0 = 0xFC;				//���ö�ʱ��ʼֵ
	T0Count++;
	if(T0Count>=500)//��һ������˸һ������
	{
		T0Count=0;
		P2_0 = ~P2_0;
	}
}