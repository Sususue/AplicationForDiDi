#ifndef  _CARMOV_H_
#define  _CARMOV_H_

/*小车结构体,储存小车相关信息*/
typedef struct{
	int xpixel;
	int ypixel;//1024*768
	int direction;//方向，1为上，2为下，3为左，4为右
	unsigned int *pic;//存储其图像信息
}CAR_CONDITION;


/****************************
汽车的最小移动单元
flag:1:车到出发点，不用遮掉线路; 2:起点到终点，需要遮掉绿色的线
****************************/
extern int carmove_basic(CAR_CONDITION *car_position,int *x,int *y, int flag);
//extern void carmove_basic(CAR_CONDITION *car_position);

/*********************************
输入结构体，执行方向移动(40像素点）
flag:1:车到出发点，不用遮掉线路; 2:起点到终点，需要遮掉绿色的线
*********************************/
// extern int carmove_onestep(CAR_CONDITION *car_position,int *x,int *y, int flag);
//extern void carmove_onestep(CAR_CONDITION *car_position);

/*************************
画某两点之间的基本运动图像
0： (130,440)//学校
1:  (212,695)//小区
2:  (395,25)//东湖
3:  (370,490)//商场
4:  (686,560)//图书馆
5:  (450,243)//游泳馆
*************************/

extern int carmove0to1(int *x,int *y);
extern int carmove0to2(int *x,int *y);
extern int carmove0to3(int *x,int *y);
extern int carmove0to4(int *x,int *y);
extern int carmove0to5(int *x,int *y);
extern int carmove1to0(int *x,int *y);
extern int carmove1to2(int *x,int *y);
extern int carmove1to3(int *x,int *y);
extern int carmove1to4(int *x,int *y);
extern int carmove1to5(int *x,int *y);
extern int carmove2to0(int *x,int *y);
extern int carmove2to1(int *x,int *y);
extern int carmove2to3(int *x,int *y);
extern int carmove2to4(int *x,int *y);
extern int carmove2to5(int *x,int *y);
extern int carmove3to0(int *x,int *y);
extern int carmove3to1(int *x,int *y);
extern int carmove3to2(int *x,int *y);
extern int carmove3to4(int *x,int *y);
extern int carmove3to5(int *x,int *y);
extern int carmove4to0(int *x,int *y);
extern int carmove4to1(int *x,int *y);
extern int carmove4to2(int *x,int *y);
extern int carmove4to3(int *x,int *y);
extern int carmove4to5(int *x,int *y);
extern int carmove5to0(int *x,int *y);
extern int carmove5to1(int *x,int *y);
extern int carmove5to2(int *x,int *y);
extern int carmove5to3(int *x,int *y);
extern int carmove5to4(int *x,int *y);


//x,y为鼠标坐标
void car_school(int *x,int *y);
void car_xiaoqu(int *x,int *y);
void car_lake(int *x,int *y);
void car_market(int *x,int *y);
void car_library(int *x,int *y);
void car_pool(int *x,int *y);

/*****************************
画路段之间的基本移动图像
flag:1:车到出发点，不用遮掉线路; 2:起点到终点，需要遮掉绿色的线
*****************************/
extern int carmove_on(int x1,int y1,int x2,int y2,int *x,int *y, int flag,float *progress,float acsend);
extern int carmove_down(int x1,int y1,int x2,int y2,int *x,int *y, int flag,float *progress,float acsend);
extern int carmove_left(int x1,int y1,int x2,int y2,int *x,int *y, int flag,float *progress,float acsend);
extern int carmove_right(int x1,int y1,int x2,int y2,int *x,int *y, int flag,float *progress,float acsend);

#endif