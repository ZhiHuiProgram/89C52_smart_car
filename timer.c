#include"reg52.h"
#include"forback.h"
int time0= 0;
int time1 = 0;
int ltimer,rtimer;
void time0_init(){
	TMOD &= 0xf0;
	TMOD |= 0x01;
	//2 计算需要的时间
	TL0 = 0x33;
	TH0 = 0xFE;
	//3 开始运行
	TR0 = 1;
	TF0 = 0;
	//打开中断
	ET0 = 1;
	//打开总线
	EA = 1;
}
/*void overtime0() interrupt 1
{
	time0++;
	TL0 = 0x33;
	TH0 = 0xFE;//初值计算20ms波形信号，分成40份调速
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
	//2 计算需要的时间
	TL1 = 0x33;
	TH1 = 0xFE;
	//3 开始运行
	TR1 = 1;
	TF1 = 0;
	//打开中断
	ET1 = 1;
	//打开总线
	EA = 1;
}
void overtime1() interrupt 3
{
	time1++;
	TL1 = 0x33;
	TH1 = 0xFE;//初值计算20ms波形信号，分成40份调速
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