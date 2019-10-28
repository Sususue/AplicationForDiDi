#include "common.h"
#include "judgfast.h"

#define FASTNUM 5

//确定哪辆车进行接送
int desidecar(int nowplace, CARFAST *car, PLACE *location)
{
    int i;//用于计数
    int mincar;//记录最近的一辆车
    double distance;//记录车到起点的距离,避免超距离
    mincar = 0;
    distance = pow((location[nowplace].x-car[0].fastcar.x),2)+pow((location[nowplace].y-car[0].fastcar.y),2);
    for ( i = 0; i < FASTNUM; i++)
    {
        if (distance > pow((location[nowplace].x-car[i].fastcar.x),2)+pow((location[nowplace].y-car[i].fastcar.y),2))
        {
            distance = pow((location[nowplace].x-car[i].fastcar.x),2)+pow((location[nowplace].y-car[i].fastcar.y),2);
            mincar = i;
        }
    }
    return mincar;
}

//确定哪辆车的动画
void cartostart(int nowplace,int mincar,int *x,int *y)
{
    switch (mincar)
    {
        case 0:
            if (nowplace==0)
            {
                car_school(x,y);
            }
            else
            {
                car_market(x,y);
            }
            break;
        case 1:
            car_lake(x,y);
            break;
        case 2:
             car_xiaoqu(x,y);
            break;
        case 3:
            car_pool(x,y);
            break;
        case 4:
            car_library(x,y);
            break;
        default:
            break;
    }
    
}
// 起点到终点的动画
int starttoend(int nowplace,int aimplace,int *x,int *y)
{
    int sigle=0;//用于接力退出
    switch (nowplace)
    {
        case 0:
                switch (aimplace)
                {
                    case 1:
                            sigle = carmove0to1(x,y);
                            if(sigle==1)//点击了报警，退出当前的打车
			                {
				                break;
			                }
                            break;
                    case 2:
                            sigle = carmove0to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove0to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove0to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove0to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 1:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove1to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 2:
                            sigle = carmove1to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove1to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove1to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove1to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 2:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove2to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove2to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove2to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove2to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove2to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 3:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove3to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove3to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove3to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove3to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove3to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        case 4:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove4to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove4to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove4to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove4to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove4to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        case 5:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove5to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove5to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove5to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove5to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove5to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        default:
                break;
    }
    return sigle;
}
