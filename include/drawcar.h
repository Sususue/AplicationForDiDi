#ifndef _DRAWCAR_H_
#define _DRAWCAR_H_


/***************************
四个方向的小车画图函数
x,y为小车中心点坐标
****************************/
extern void car_draw_right(CAR_CONDITION car_position);

extern void car_draw_left(CAR_CONDITION car_position);

extern void car_draw_on(CAR_CONDITION car_position);

extern void car_draw_down(CAR_CONDITION car_position);


extern void police_draw_right(CAR_CONDITION car_position);

extern void police_draw_left(CAR_CONDITION car_position);

extern void police_draw_on(CAR_CONDITION car_position);

extern void police_draw_down(CAR_CONDITION car_position);


extern void car_draw_right1(int x,int y);

extern void car_draw_left1(int x,int y);

extern void car_draw_on1(int x,int y);

extern void car_draw_down1(int x,int y);




#endif