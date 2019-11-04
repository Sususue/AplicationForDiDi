#ifndef  _ENDORDER_H_
#define  _ENDORDER_H_




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
void neworder(int *x,int *y,USEINFOR *infor, const CARFA *car, const char **placename, int *aimplace, int mincar, char *ordertime,float price);



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
		nowtime_hour:现在的时间，根据时间段判断价格计算
		timegap:从呼叫快车开始到快车结束的时间间隔(s)
		x、y:鼠标
		waitime:等待时间，用以判断是否为预约模式
******************************************************/
void costmoney(float *price,USEINFOR *infor,int *aimplace,int nowtime_hour,int timegap, int *x, int *y, int waitime);

//生成新的租车订单
void newrentorder(int *x,int *y,USEINFOR *infor, CARRENT *rcar, int timegap,float *price);

//评价
void evaluate(int *x, int *y,CARFA *car);
//更改文件里的信息
void changepraise(CARFA *car, int flag);

#endif