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
extern void driver_info(int *x,int *y, USEINFOR *infor, CARFA *car, const PLACE *location, const char **placename, int *aimplace, int mincar,int waitime);


/**************************
点击"预约"弹出预约选择弹框
**************************/
extern int pre_appoint(int *x,int *y);


/**************************
返回即时状态函数
***************************/
extern void immediate(int *x,int *y);


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



/*********************************************
功能说明:传入车辆数组，初始化其信息
参数说明:car:快车的结构数组
*********************************************/
// void newfastcar(CARFAST *car);
void newfastcar(CARFA *car);

/*********************************************
功能说明:传入车辆数组，退出后，更改司机
参数说明:car:快车的结构数组
*********************************************/
void changecar(CARFA *thiscar, int x,int y);

// 更改司机状态为不能接单
void changecall(CARFA *thiscar, int callstyle);
/*********************************************
功能说明:取消订单
参数说明:x,y:鼠标
        infor:用户信息
返回值:返回0表示取消订单，1不取消
*********************************************/
int cancelorder(int *x, int *y, USEINFOR *infor);


#endif