#ifndef  _RENTMOVE_H_
#define  _RENTMOVE_H_

/**************************************************************************
功能说明:租车中小车在两点之间移动的动画
         同时显示当前电量和用车时间
参数说明:(x1,y1):起始节点的横纵坐标
         (x2,y2):终止节点的横纵坐标
		 derection:判断小车行驶方向的参数
				   derection==1:上
				   derection==2:下
				   derection==3:左
				   derection==4:右
		 energy：用于显示电量的参数
**************************************************************************/
extern int rentmove(CAR_CONDITION *car_position, int x1,int y1,int x2,int y2,int *x,int *y,int direction,int *energy);

/*******************************
汽车的最小移动单元
*******************************/
extern int rentmove_basic(CAR_CONDITION *car_position,int *x,int *y);

#endif