#include "reg52.h"
#include "intrins.h"
#include "delay.h"
#include "ste_wave.h"
sbit sg90_con = P1^0;
sbit trig = P1^1;
sbit echo = P1^2;
int overtime;
int angle;
double get_distance(){
	double time;
	double distance;
	startHC();
	while(echo == 0);
	TR1 = 1;
	while(echo == 1);
	TR1 = 0;
	time = (TL1+TH1*256)* 1.085;
	distance = time*0.017;
	TH1 = 0;
	TL1 = 0;
	return distance;
}
void T0init(){
	//1 初始化
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
void sg90_control() interrupt 1
{
	overtime++;
	TL0 = 0x33;
	TH0 = 0xFE;
	if(overtime == 1){
		sg90_con = 1;
	}
	if(overtime == angle){
		sg90_con = 0;
	}
		
	if(overtime == 40){
		overtime = 0;
		sg90_con = 0;
				
	}
}
void T1init(){
	TMOD &= 0x0f;
	TMOD |= 0x10;
	TH1 =0;
	TL1 =0;
}
void startHC(){
	trig = 0;
	trig = 1;
	Delay15us();
	trig = 0;
}
