#ifndef  _PLACE_H_
#define  _PLACE_H_




/*********************************************
功能说明:显示终点或起点的名称及位置，需要调用markpoint()
参数说明:place:输入需要显示位置的编号号码
               0:学校 1:小区 2:东湖 3:商场 4:图书馆 5:游泳馆
        mode:NOW -1:表示显示现在位置; AIM 1：表示显示目的地位置
*********************************************/
void showplace(int place,int mode, const PLACE *location, const char *placename[]);


/*********************************************
功能说明:标记出起点终点
参数说明:x,y:位置
        color:颜色
        mode:NOW -1:表示显示现在位置; AIM 1：表示显示目的地位置
**********************************************/
void markpoint(int x, int y, int color, int mode);


/*********************************************
功能说明:选择目的地
参数说明:aimplace:目标地点
        infor:用户信息，结构指针
        location:传入初始化后的几个地点坐标
        placename:传入初始化后的地点名称

**********************************************/
extern void choose_aimplace(int *x, int *y, int *aimplace, PLACE *location, USEINFOR *infor, char *placename[]);


/*********************************************
功能说明:起点到终点//显示绿色的线
参数说明:nowplace:起点的号码(不是坐标)
        aimplace:终点号码
        
返回值:wu
**********************************************/
void starttoendroad(int nowplace,int aimplace,int color);


/*********************************************
功能说明：用于预计价格显示
参数说明：nowplace：起始点的号码
*********************************************/
extern void showprice(int nowplace,int *aimplace);

#endif