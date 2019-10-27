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
extern void driver_info(int *x,int *y, USEINFOR *infor, const CARFAST car[], const PLACE *location, const char **placename, int *aimplace, int mincar,int waitime);


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


extern void car_draw_right1(int x,int y);

extern void car_draw_left1(int x,int y);

extern void car_draw_on1(int x,int y);

extern void car_draw_down1(int x,int y);

/*********************************************
功能说明:显示终点或起点的名称及位置，需要调用markpoint()
参数说明:place:输入需要显示位置的编号号码
               0:学校 1:小区 2:东湖 3:商场 4:图书馆 5:游泳馆
        mode:NOW -1:表示显示现在位置; AIM 1：表示显示目的地位置
*********************************************/
void showplace(int place,int mode, const PLACE *location, const char **placename);

/*********************************************
功能说明:标记出起点终点
参数说明:x,y:位置
        color:颜色
        mode:NOW -1:表示显示现在位置; AIM 1：表示显示目的地位置
**********************************************/
void markpoint(int x, int y, int color, int mode);


/*********************************************
功能说明:传入车辆数组，初始化其信息
参数说明:car:快车的结构数组
*********************************************/
void newfastcar(CARFAST *car);

/*********************************************
功能说明:选择目的地
参数说明:aimplace:目标地点
        infor:用户信息，结构指针
        location:传入初始化后的几个地点坐标
        placename:传入初始化后的地点名称

**********************************************/
void choose_aimplace(int *x, int *y, int *aimplace, PLACE *location, USEINFOR *infor, char *placename[]);


/*********************************************
功能说明:确定哪辆车进行接送
参数说明:nowplace:起点的号码(不是坐标)
        car:传入初始化的快车数组
        location:传入初始化后的几个地点坐标
返回值:mincar:最近的快车编号
**********************************************/
int desidecar(int nowplace, CARFAST *car, PLACE *location);

/*********************************************
功能说明:确定哪辆车的动画
参数说明:nowplace:起点的号码(不是坐标)
        mincar:最近的那辆车
        x,y:鼠标
返回值:无
**********************************************/
void cartostart(int nowplace,int mincar,int *x,int *y);


/*********************************************
功能说明:起点到终点的动画
参数说明:nowplace:起点的号码(不是坐标)
        aimplace:终点号码
        x,y:鼠标
返回值:sigle:用于接力退出
**********************************************/
int starttoend(int nowplace,int aimplace,int *x,int *y);


/*********************************************
功能说明:起点到终点//显示绿色的线
参数说明:nowplace:起点的号码(不是坐标)
        aimplace:终点号码
        
返回值:wu
**********************************************/
void starttoendroad(int nowplace,int aimplace,int color);

/*********************************************
功能说明:打车完成后生成订单
        调用changeOrder进行订单信息修改
        本函数主要显示出订单信息:起点、终点、价格，日期
参数说明:x,y:鼠标坐标
        infor:用户信息结构变量
        car:快车数组
        placename:位置名字数组
        aimplace:目标地点的号码
        mincar:接送快车的号码
返回值:无
**********************************************/
void neworder(int *x,int *y,USEINFOR *infor, const CARFAST car[], const char **placename, int *aimplace, int mincar, char *ordertime,float price);

/*********************************************
功能说明：用于预计价格显示
参数说明：nowplace：起始点的号码
*********************************************/
extern void showprice(int nowplace,int *aimplace);

/*********************************************
功能说明：用于计算预计价格
参数说明: judgement:用于判断计算的是哪两点之间的价格
		  pointprice:价格数组
		  pointlength:里程数组（两点之间像素点的个数）
		  timegap:用于是计算预计价格还是最终价格的判断
		  timegap=0:计算预计价格
		  timegap!=0:计算最终价格
		   基础里程：3km
基础时长：9min
里程计算方法：500像素点 = 1公里
              超出部分算作1公里
时长计算方法：2min = 1s
              超出部分算作1分钟
参数说明： timegap:用于是计算时间长度
		   timegap=0:计算预计价格
		   timegap!=0:计算最终价格
			
		   timecase:用于判断价格计算方法
		   timecase=0:计算预计价格 起步价11元，里程费1.8元/KM
		   timecase=1: 0:00-9:00时段：起步价11元，里程费2.6元/KM，时长费0.5元/min
		   timecase=2: 12:00-15:00时段：起步价11元，里程费1.8元/KM，时长费0.5元/min
		   timecase=3: 17:00-00:00时段：起步价11元，里程费1.8元/KM，时长费0.5元/min
		   timecase=4: 普通时段：起步价10.3元，里程费1.70元/KM,时长费0.35元/min
**********************************************/
extern void countprice(float *pointprice,int nowplace,int *aimplace,int timegap,int timecase);

/******************************************************
 功能说明：算价格并扣费
参数说明：price:价格
        infor:用户信息结构
        aimplace:目的地
******************************************************/
void costmoney(float *price,USEINFOR *infor,int *aimplace,int nowtime_hour,int timegap, int *x, int *y);
#endif