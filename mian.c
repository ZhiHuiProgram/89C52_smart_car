#include "forback.h"
#include "delay.h"
#include "uart.h"
#include "timer.h"
#include "reg52.h"
#include "ste_wave.h"
#define left  1
#define right 2
#define middle 3
sbit a25 = P1^7;
sbit a26 = P1^6;
sbit a27 = P1^5;
sbit rinf = P2^2;
sbit linf = P2^3;
//sbit remote1 = P1^3;
//sbit remote2 = P1^4;
//sbit remote3 = P1^5;
//sbit remote4 = P1^6;
extern int overtime;
extern int angle;
extern int ltimer,rtimer;
int remote_mark = 0;
char location;
double l_dis,r_dis,m_dis;
void rig_turn();
void lef_turn();
void mid_turn();
void main(){
	T0init();
	T1init();
	angle = 4;
	location = middle;
	Delay300ms();
	Delay300ms();
//	mid_turn();
	while(1){
		Delay30ms();
//		if(remote1 == 1){
//			remote_mark = 1;
//		}
//		if(remote2 == 1){
//			remote_mark = 2;
//		}
//		if(remote3 == 1){
//			remote_mark = 3;
//		}
//		if(remote4 == 1){
//			remote_mark = 4;
//		}
//		switch(remote_mark){
//			case 1:
//				if(location != middle){
//					angle = 4;
//					location = middle;
//					Delay300ms();
//				}
//				m_dis = get_distance();
//				
//				if(m_dis > 35){
//					//??
//					car_forward();
//				}else if(m_dis < 10){
//					car_back();
//					
//				}else
//				{
//					//??
//					car_stop();
//					//?????
//					angle = 6;
//					Delay300ms();
//					l_dis = get_distance();
//					
//					angle = 4;
//					Delay300ms();
//					
//					angle = 2;
//					location = right;
//					Delay300ms();
//					r_dis = get_distance();
//					
//					if(l_dis < r_dis){
//						car_right();
//						Delay250ms();
//						car_stop();
//					}
//					if(r_dis < l_dis){
//						car_left();
//						Delay250ms();
//						car_stop();
//					}
//				}
			if(a25 == 1 && a26 == 0 && a27 == 1){
				mid_turn();
				if(m_dis >30){
					car_forward();
				}else if(m_dis < 10){ 
					car_back();
					Delay150ms();
				}else{
					car_stop();
					lef_turn();
					angle = 4;
					Delay350ms();
					rig_turn();
					if(l_dis > r_dis && l_dis > 10){
						car_left();
						Delay250ms();
						car_stop();
					}else if (l_dis < r_dis && r_dis >10){
						car_right();
						Delay250ms();
						car_stop();
					}else{
						car_back();
						Delay250ms();
						car_stop();
					}
				}
			}
//			break;
//			case 2:
			if(a25 == 0 && a26 == 1 && a27 == 1){
				car_stop();
			}
//			break;
//			case 3:
//				if(linf == 0 && rinf ==0){
//					car_forward();
//				}else if(linf == 1 && rinf ==0){
//					car_left();
//				}else if(linf == 0 && rinf ==1){
//					car_right();
//				}else if(linf == 1 && rinf == 1){
//					car_stop();
//				}
//			break;
//			case 4:
			if(a25 == 1 && a26 == 1 && a27 == 0){
				if(linf == 1 && rinf ==1){
					car_forward();
				}else if(linf == 1 && rinf ==0){
					car_right();
				}else if(linf == 0 && rinf ==1){
					car_left();
				}else if(linf == 0 && rinf == 0){
					car_stop();
				}
			}
//				break;
//			default:
//				car_stop();
//			break;
//		}
		
	}
}
void mid_turn(){
	angle = 4;
	Delay350ms();
	m_dis = get_distance();
	
}
void rig_turn(){
	angle = 2;
	Delay350ms();
	r_dis = get_distance();
	
}
void lef_turn(){
	angle = 6;
	Delay350ms();
	l_dis = get_distance();
	
}
/*void main(){ //小车循迹，向收不到信号的方向转
//	uart_init();
	time1_init();
	time0_init();
	while(1){ 
		if(linf == 0 && rinf ==0){
			car_forward();
		}else if(linf == 1 && rinf ==0){
			ltimer = 10;
			rtimer = 40;
		}else if(linf == 0 && rinf ==1){
			ltimer = 40;
			rtimer = 10;
		}else if(linf == 1 && rinf == 1){
			car_stop();
		}
	}
}*/
/*void main(){ //小车跟随，原理和循迹一样，向收到信号的方向转
//	uart_init();
	time1_init();
	time0_init();
	while(1){ 
		if(linf == 0 && rinf ==0){
			car_forward();
		}else if(linf == 1 && rinf ==0){
			ltimer = 10;
			rtimer = 40;
		}else if(linf == 0 && rinf ==1){
			ltimer = 40;
			rtimer = 10;
		}else if(linf == 1 && rinf == 1){
			car_stop();
		}
	}
}*/
