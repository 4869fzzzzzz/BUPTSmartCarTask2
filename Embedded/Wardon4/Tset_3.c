#include <REGX52.H>

unsigned char i,j,k;

void Timer0_Init(void)//100΢��@11.0592MHz��ʱ����ʼ��
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0xA4;
	TH0 = 0xFF;
	TF0 = 0;
	TR0 = 1;
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

void Timer0_Routine() interrupt 1 //100΢�����һ��
{
	TL0 = 0xA4;
	TH0 = 0xFF;//���ö�ʱ����ʼֵ
	i++;//ÿ����һ��i����
	if(i>=100)
	{
		if(j==100)
		k=~k;
		i = i%100;//i��100ʱ�Զ�����
		j++;
		if(j>100) j = 0;
	}
	if(k==0)
	{
		if(i<j)
		  P2_0 = 1;//iС��j����j/100��ʱ����
	  else
		  P2_0 = 0;//i����j��������1-j��/100��ʱ����
	}
	else
	{
		if(i>j)
		P2_0 = 1;//iС��j����j/100��ʱ����
	else
		P2_0 = 0;//i����j��������1-j��/100��ʱ����
	}
	
}