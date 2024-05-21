#include"reg52.h"
#include"forback.h"
int time0= 0;
int time1 = 0;
int ltimer,rtimer;
void time0_init(){
	TMOD &= 0xf0;
	TMOD |= 0x01;
	//2 ������Ҫ��ʱ��
	TL0 = 0x33;
	TH0 = 0xFE;
	//3 ��ʼ����
	TR0 = 1;
	TF0 = 0;
	//���ж�
	ET0 = 1;
	//������
	EA = 1;
}
/*void overtime0() interrupt 1
{
	time0++;
	TL0 = 0x33;
	TH0 = 0xFE;//��ֵ����20ms�����źţ��ֳ�40�ݵ���
	if(time0 == 1){
		rforward();
	}
	if(time0 == rtimer){
		rstop();
	}
		
	if(time0 == 40){
		time0 = 0;
				
	}
}*/
void time1_init(){
	TMOD &= 0x0f;
	TMOD |= 0x10;
	//2 ������Ҫ��ʱ��
	TL1 = 0x33;
	TH1 = 0xFE;
	//3 ��ʼ����
	TR1 = 1;
	TF1 = 0;
	//���ж�
	ET1 = 1;
	//������
	EA = 1;
}
void overtime1() interrupt 3
{
	time1++;
	TL1 = 0x33;
	TH1 = 0xFE;//��ֵ����20ms�����źţ��ֳ�40�ݵ���
	if(time1 == 1){
		lforward();
	}
	if(time1 == ltimer){
		lstop();
	}
		
	if(time1 == 40){
		time1 = 0;
				
	}
}