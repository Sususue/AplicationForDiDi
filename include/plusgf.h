#ifndef advancegf.h
#define advancegf.h



/**************************************************
function:        lean_line

description:     倾斜直线

Input:           x1,y1(直线起点坐标),x2,y2(直线终点坐标），color;

out:             倾斜直线

quote:           
**************************************************************/
/*extern void lean_line(int x1,int y1,int x2,int y2,int color);*/


/****************************************************
  填充右半圆，（x,y)为半圆圆心坐标
  ****************************************************/
void fill_hemicircle_right(int x,int y,int r,int color);


/***********************************************
四个画四分之一弧的函数，用勾股定理计算
************************************************/
extern void right_up(int x,int y,int r,int color);
extern void right_down(int x,int y,int r,int color);
extern void left_up(int x,int y,int r,int color);
extern void left_down(int x,int y,int r,int color);



/**************************************************
function:        fill_right_up

description:     右上填充扇形

Input:           x,y,r,color;

out:             右上角1/4扇形
**************************************************************/
extern void fill_right_up(int x,int y,int r,int color);


/**************************************************
function:        fill_left_up

description:     左上填充扇形

Input:           x,y,r,color;

out:             左上角1/4扇形
**************************************************************/
extern void fill_left_up(int x,int y,int r,int color);


/**************************************************
function:        fill_left_down

description:     左下填充扇形

Input:           x,y,r,color;

out:             左下角1/4扇形
**************************************************************/
extern void fill_left_down(int x,int y,int r,int color);


/**************************************************
function:        fill_right_down

description:     右下填充扇形

Input:           x,y,r,color;

out:             右下角1/4扇形
**************************************************************/
extern void fill_right_down(int x,int y,int r,int color);



/**************************************************
function:        bar_round

description:     圆角矩形

Input:           x,y(矩形中心坐标),length(矩形长度),height(矩形高度),r(圆角半径),thick(线段粗,目前只能改变直线段粗细-09/25),color;

out:             圆角半径可变，线粗可变的圆角矩形

quote:           fill_right_down,fill_right_up,fill_left_down,fill_left_up,right_up,right_down,left_up,left_down;
**************************************************************/
extern void bar_round(int x,int y,int length,int height,int r,int thick,int color);


/**************************************************
function:        bar_round_2

description:     圆角矩形(无边框)

Input:           x0,y0(左上角坐标),x1,y1(右下角坐标),r(圆角半径),thick(线段粗),color;

out:             无边框圆角矩形

quote:           fill_right_down,fill_right_up,fill_left_down,fill_left_up,right_up,right_down,left_up,left_down;
**************************************************************/
extern void bar_round_2(int x0,int y0,int x1,int y1,int r,int thick,int color);


/**************************************************
function:        bar_round_with_shadow

description:     带阴影效果的圆角矩形

Input:           x,y(矩形中心坐标),length(矩形长度),height(矩形高度),r(圆角半径),thick(线段粗,目前只能改变直线段粗细-09/25),color(中心颜色),color(阴影颜色);

out:             圆角半径可变，线粗可变的带阴影（阴影大小与线粗有关）圆角矩形

quote:           fill_bow_right_down,fill_bow_right_up,fill_bow_left_down,fill_bow_left_up,bow_right_up,bow_right_down,bow_left_up,bow_left_down;
**************************************************************/
extern void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color, int color2);




/*********************************************
  朝向左侧的直角三角形，（x,y)为直角顶点的坐标
  用于画梯形
  ********************************************/
extern void triangle_left(int x,int y,int height,int color);


/********************************************
  朝向右侧的直角三角形，（x，y)为直角顶点的坐标 
  用于画梯形
  ********************************************/
extern void triangle_right(int x,int y,int height,int color);


/*********************************************
 画梯形
 （x1,y1),(x2,y2)分别为梯形中的左右上顶点坐标
 ********************************************/
extern void trapezoid(int x1,int y1,int x2,int y2,int height,int color);


/**************************************************
function:        lean_line

description:     倾斜直线

Input:           x,y(直线起点坐标),length(线长),theta,color;

out:             倾斜直线

quote:           
**************************************************************/
extern void lean_line(int x,int y,int length,int theta,int color);

/**************************************************
function:        lean_line_thick

description:     线粗可变的倾斜直线

Input:           x,y(直线起点坐标),length(线长),theta,thick,color;

out:             线粗可变的倾斜直线

quote:           lean_line
**************************************************************/
extern void lean_line_thick(int x,int y,int length,int theta,int thick,int color);


/**************************************************
function:        red_cross

description:     一个红色的叉

Input:           x,y

out:             图形

quote:           theta_bar
**************************************************************/
extern void red_cross(int x,int y);

/**************************************************
function:        green_tick

description:     一个绿色的勾

Input:           x,y

out:             图形

quote:           theta_bar
**************************************************************/
extern void green_tick(int x,int y);


/*************************************************************
功能说明：画下半圆
*************************************************************
extern void subhemicircle(int x0,int y0,int radius,int color);


/*************************************************************
功能说明：画上半圆
*************************************************************/
extern void uphemicircle(int x0,int y0, int radius, int color);



/**************************************************************
功能说明：画右半圆
**************************************************************/
extern void righthemicircle(int x0,int y0,int radius,int color);

#endif