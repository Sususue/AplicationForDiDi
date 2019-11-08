#include "common.h"
#include "drawcar.h"



/***************************
四个方向的小车画图函数
****************************/

void car_draw_right(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel+6,car_position.ypixel,6,15,1,1,1);
	bar_round(car_position.xpixel-16,car_position.ypixel,3,15,1,1,1);
	bar_round(car_position.xpixel-6,car_position.ypixel-8,18,1,0,1,1);
	bar_round(car_position.xpixel-6,car_position.ypixel+8,18,1,0,1,1);
}	

void car_draw_left(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel-6,car_position.ypixel,6,15,1,1,1);
	bar_round(car_position.xpixel+16,car_position.ypixel,3,15,1,1,1);
	bar_round(car_position.xpixel+6,car_position.ypixel-8,18,1,0,1,1);
	bar_round(car_position.xpixel+6,car_position.ypixel+8,18,1,0,1,1);
}

void car_draw_on(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel-6,15,6,1,1,1);
	bar_round(car_position.xpixel,car_position.ypixel+16,15,3,1,1,1);
	bar_round(car_position.xpixel-8,car_position.ypixel+6,1,18,0,1,1);
	bar_round(car_position.xpixel+8,car_position.ypixel+6,1,18,0,1,1);
}

void car_draw_down(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel+6,15,6,1,1,1);
	bar_round(car_position.xpixel,car_position.ypixel-16,15,3,1,1,1);
	bar_round(car_position.xpixel-8,car_position.ypixel-6,1,18,0,1,1);
	bar_round(car_position.xpixel+8,car_position.ypixel-6,1,18,0,1,1);
}

/***************************
四个方向的警车画图函数
****************************/

void police_draw_right(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel+6,car_position.ypixel,6,15,1,1,63488);
	bar_round(car_position.xpixel-16,car_position.ypixel,3,15,1,1,63488);
	bar_round(car_position.xpixel-6,car_position.ypixel-8,18,1,0,1,63488);
	bar_round(car_position.xpixel-6,car_position.ypixel+8,18,1,0,1,63488);
}	

void police_draw_left(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel-6,car_position.ypixel,6,15,1,1,63488);
	bar_round(car_position.xpixel+16,car_position.ypixel,3,15,1,1,63488);
	bar_round(car_position.xpixel+6,car_position.ypixel-8,18,1,0,1,63488);
	bar_round(car_position.xpixel+6,car_position.ypixel+8,18,1,0,1,63488);
}

void police_draw_on(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel-6,15,6,1,1,63488);
	bar_round(car_position.xpixel,car_position.ypixel+16,15,3,1,1,63488);
	bar_round(car_position.xpixel-8,car_position.ypixel+6,1,18,0,1,63488);
	bar_round(car_position.xpixel+8,car_position.ypixel+6,1,18,0,1,63488);
}

void police_draw_down(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel+6,15,6,1,1,63488);
	bar_round(car_position.xpixel,car_position.ypixel-16,15,3,1,1,63488);
	bar_round(car_position.xpixel-8,car_position.ypixel-6,1,18,0,1,63488);
	bar_round(car_position.xpixel+8,car_position.ypixel-6,1,18,0,1,63488);
}


void car_draw_right1(int x,int y)
{
	bar_round(x,y,42,22,2,1,1);
	bar_round(x,y,38,18,2,1,65535);
	bar_round(x+6,y,6,15,1,1,1);
	bar_round(x-16,y,3,15,1,1,1);
	bar_round(x-6,y-8,18,1,0,1,1);
	bar_round(x-6,y+8,18,1,0,1,1);
}	

void car_draw_left1(int x,int y)
{
	bar_round(x,y,42,22,2,1,1);
	bar_round(x,y,38,18,2,1,65535);
	bar_round(x-6,y,6,15,1,1,1);
	bar_round(x+16,y,3,15,1,1,1);
	bar_round(x+6,y-8,18,1,0,1,1);
	bar_round(x+6,y+8,18,1,0,1,1);
}

void car_draw_on1(int x,int y)
{
	bar_round(x,y,22,42,2,1,1);
	bar_round(x,y,18,38,2,1,65535);
	bar_round(x,y-6,15,6,1,1,1);
	bar_round(x,y+16,15,3,1,1,1);
	bar_round(x-8,y+6,1,18,0,1,1);
	bar_round(x+8,y+6,1,18,0,1,1);
}

void car_draw_down1(int x,int y)
{
	bar_round(x,y,22,42,2,1,1);
	bar_round(x,y,18,38,2,1,65535);
	bar_round(x,y+6,15,6,1,1,1);
	bar_round(x,y-16,15,3,1,1,1);
	bar_round(x-8,y-6,1,18,0,1,1);
	bar_round(x+8,y-6,1,18,0,1,1);
}
