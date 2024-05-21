#include"reg52.h"
#define num 12
#include<string.h>
#include"forback.h"
#include"delay.h"
sfr AUXR = 0x8e;

char array[num];
char cmd;

void uart_init(){
	AUXR = 0X01;
	SCON = 0x50;
	TMOD &= 0x0f;
	TMOD |= 0x20;
	TH1 = 0XFD;
	TH1 = 0XFD;
	TR1 = 1;
	EA = 1;
	ES = 1;
}
void sendbyte(char data1){
	SBUF = data1;
	while(!TI);
	TI = 0;
}
void sendstring(char *pp){
	while(*pp != '\0'){
		sendbyte(*pp);
		pp++;
	}
}
void INTR() interrupt 4{
	static int i=0;
	char test;
	if(RI == 1){
		RI = 0;
		test = SBUF;
		if(test == 'B' || test == 'L' || test == 'G' || test == 'R' || test == 'S'){
			i=0;
		}
		array[i] = test;
		i++;
		cmd = SBUF;
		if(array[0]=='G'){
			car_forward();
			memset(array,'\0',num);
		}else if(array[0]=='L'){
			car_left();
			memset(array,'\0',num);
		}else if(array[0]=='R'){
			car_right();
			memset(array,'\0',num);
		}else if(array[0]=='B'){
			car_back();
			memset(array,'\0',num);
		}else if(array[0]=='S'){
			car_stop();
			memset(array,'\0',num);
		}
	}
}
