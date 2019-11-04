#ifndef  _JUDGFAST_H_
#define  _JUDGFAST_H_

#define FASTNUM 5
/*********************************************
功能说明:确定哪辆车进行接送
参数说明:nowplace:起点的号码(不是坐标)
        car:传入初始化的快车数组
        location:传入初始化后的几个地点坐标
返回值:mincar:最近的快车编号
**********************************************/
int desidecar(int nowplace, PLACE fastplace[FASTNUM], PLACE *location);

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



#endif