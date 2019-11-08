#ifndef _CARTAKE_H_
#define _CARTAKE_H_

// typedef struct point{
// 	int length;  //储存两点之间像素点距离的信息
// 	float pprice; //记录两点之间的价格信息
// }POINT;

/********************
快车窗口
********************/
extern void car_take_box(int *x, int *y,USEINFOR *infor);


/*****************************
功能说明:点击"呼叫快车"后弹出司机信息窗口
参数说明:x、y:鼠标
        infor:用户信息的结构指针
        car:初始化过后的快车数组
        location:初始化后的几个地点坐标
        placename:初始化后的几个地点名称(中文)
        aimplace:目标地点对应的编号(不是坐标)
返回值:无
*****************************/
extern void driver_info(int *x,int *y, USEINFOR *infor, CARFA *car, const PLACE *location,/*  const  */char **placename, int *aimplace, int mincar,int waitime);







/*********************************************
功能说明:传入车辆数组，初始化其信息
参数说明:car:快车结构变量，当前的快车信息
*********************************************/
// void newfastcar(CARFAST *car);
// void newfastcar(CARFA *car);

/*********************************************
功能说明:传入车辆数组，退出后，更改司机
参数说明:car:快车的结构
*********************************************/
void changecar(CARFA *thiscar, int x,int y);


/*********************************************
功能说明:取消订单
参数说明:x,y:鼠标
        infor:用户信息
返回值:返回0表示取消订单，1不取消
*********************************************/
int cancelorder(int *x, int *y, USEINFOR *infor);


#endif