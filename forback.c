#include"reg52.h"

sbit dianji1=P2^4;
sbit dianji2 = P2^5;
sbit dianji3=P2^6;
sbit dianji4 = P2^7;
void lforward(){
	dianji1 = 0;
	dianji2 = 1;
}
void rforward(){
	dianji3 = 1;
	dianji4 = 0;
}
void lback(){
	dianji1 = 1;
	dianji2 = 0;
}
void rback(){
	dianji3 = 0;
	dianji4 = 1;
}
void car_forward(){
	lforward();
	rforward();
}
void car_back(){
	lback();
	rback();
}
void car_left(){
	dianji1 = 0;
	dianji2 = 0;
	dianji3 = 1;
	dianji4 = 0;
}
void car_right(){
	dianji1 = 0;
	dianji2 = 1;
	dianji3 = 0;
	dianji4 = 0;
}
void car_stop(){
	dianji1 = 0;
	dianji2 = 0;
	dianji3 = 0;
	dianji4 = 0;
}
void lstop(){
	dianji1 = 0;
	dianji2 = 0;
}
void rstop(){
	dianji3 = 0;
	dianji4 = 0;
}