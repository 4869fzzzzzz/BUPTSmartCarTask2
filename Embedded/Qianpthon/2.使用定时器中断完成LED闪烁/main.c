
#include <REGX52.H>
void Timer0_Init()
{
	//��ʱ������
		TMOD=0x01;//0000 0001������ģʽ
		TF0=0;//������0
		TR0=1,//��ʱ��on
		TH0=64535/256;//�߰�λ
		TL0=64535%256;//�Ͱ�λ
	//�ж�����
		ET0=1;
		EA=1;
    PT0=0;
}
void main()
{
	Timer0_Init();
	while(1)
	{
		
	}
}
unsigned int T0Count;
 void Timer0_Routine() interrupt 1
 {
		TH0=64535/256;
		TL0=64535%256;
		T0Count++;
	 if(T0Count>=1000)
	 {
		T0Count=0;
		 P2_0=~P2_0;
	 }
 }