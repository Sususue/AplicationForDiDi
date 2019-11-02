#include "common.h"
#include "findway.h"

// #define MAXSIZE 10
// #define INF 9999
// #define NOWAY -1
// #define DIRECTNUM 4
// #define AREONUM 8 //道路分为八个区，四个横着，四个竖着
// #define PARKR 60 //判断停车时与停车场的半径
// #define PARKNUM 6

//最短路径算法，由于最后存储是逆序的，所以实际找的是终点到起点的最短路径
int Dijkstra(int start, int end, int way[], int *count)
{
    int i,j;
    int mindis;
    int vexs[MAXSIZE] = {0,1,2,3,4,5,6,7,8,9};
    int arcs[MAXSIZE][MAXSIZE] = {
        INF,243,INF,INF,INF,INF,INF,INF,INF,INF,//0
        243,INF,196,INF,INF,197,INF,INF,INF,INF,//1
        INF,196,INF,247,INF,INF,197,INF,INF,INF,//2
        INF,INF,247,INF,INF,INF,INF,INF,INF,452,//3
        INF,INF,INF,INF,INF,227,INF,255,INF,INF,//4
        INF,197,INF,INF,227,INF,196,INF,INF,INF,//5
        INF,INF,197,INF,INF,196,INF,INF,255,INF,//6
        INF,INF,INF,INF,255,INF,INF,INF,423,INF,//7
        INF,INF,INF,INF,INF,INF,255,423,INF,247,//8
        INF,INF,INF,452,INF,INF,INF,INF,247,INF //9
    };
    int dis[MAXSIZE]={0};//到每个点的最短路径
    int mark[MAXSIZE];//等于1即为被标记，0为未被标记，即未到达过
    int min;//最短路径长度
    int next;//下一个放入集合P的点
    int last[MAXSIZE];//记录上一个点是哪个点
    // int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//记录路径顺序
    for ( i = 0; i < MAXSIZE; i++)//初始化mark[]标记情况，dis[]最短路径，last[]上一节点
    {
        mark[i] = 0;
        dis[i] = arcs[start][i];
        if (dis[i] == INF)
        {
            last[i] = NOWAY;
        }
        else
        {
            last[i] = start;
        }
    }
    mark[start] = 1; //标记起点
    for ( j = 0; j < MAXSIZE; j++)
    {
        min = INF;//初始化为极大值

        for ( i = 0; i < MAXSIZE; i++)
        {
            if (mark[i] == 0 && min > dis[i])//未被遍历，且被赋值的最短路径
            {
                min = dis[i];//在已知赋值最短路径中，找权值最小的点作为下一次遍历的起点
                next = vexs[i];
            }
        }
        mark[next] = 1; //标记找到的下一个遍历起点
        //修正最短路径
        for ( i = 0; i < MAXSIZE; i++)
        {
            if (mark[i] == 0 && dis[i] > dis[next]+arcs[next][i])
            {
                dis[i] = dis[next]+arcs[next][i];
                last[i] = next;
            }
            
        }
        
    }
    printf("mindistance = %d\n",dis[end]);
    mindis=dis[end];//一定要先存下来，否则dis[end]在循环中被改变，返回的不是最短距离
    way[0] = end;           //将节点逆序存入数组
    while (end != start)
    {
        *count=*count+1;
        way[*count]=last[end];
        end = last[end];
    }
    return mindis;
}

// 确认找到的最短路径中每个结点之间的方向
void direction(int way[], int count, int direct[])
{
    int i=0,j=0;
    int now;
    int node[MAXSIZE][DIRECTNUM] = { 
        //上，下，左，右
        NOWAY,1,NOWAY,NOWAY,//0
        0,5,NOWAY,2,        //1
        NOWAY,6,1,3,        //2
        NOWAY,9,2,NOWAY,    //3
        NOWAY,7,NOWAY,5,    //4
        1,NOWAY,4,6,        //5
        2,8,5,NOWAY,        //6
        4,NOWAY,NOWAY,8,    //7
        6,NOWAY,7,9,        //8
        3,NOWAY,8,NOWAY     //9
    };
    while (j < count)
    {
        now = way[j];
        for ( i = 0; i < DIRECTNUM; i++)
        {
            if (node[now][i] == way[j+1])//根据所存的位置判断到下一个结点的方向
            {
                direct[j]=i+1;
            }
        }
        j++;
    }
}
//判断鼠标点击区域，只能点击道路且要修正为路中央
//进入函数的条件是鼠标在地图区域点击，并且点击的位置为白色利用int  getpixel(int x,int y) <-此方法失败
//node:路口结点
void judgeAreo(PLACE node[MAXSIZE],int x, int y, PLACE *placeto, int *flag, int *nodenum)
{
    
    int i;//用于计数
    PLACE areo[AREONUM*2]={
        {2,10},{386,40},//横0
        {257,253},{766,284},//横1
        {2,450},{483,480},//横2
        {30,704},{730,736},//横3
        {30,450},{61,736},//竖4
        {257,10},{287,480},//竖5
        {453,253},{483,766},//竖6
        {700,253},{730,736}//竖7
    };
    //修正的坐标
    int correct[AREONUM]={
        25,//横0的纵坐标
        268,//横1
        465,//横2
        720,//横3
        45,//竖4的横坐标
        272,//竖5
        468,//竖6
        715//竖7
    };
    

    *flag=0;//用以判断是否在结点上,等于偶数时表示已经在节点
    placeto->x = x;
    placeto->y = y;

    for ( i = 0; i < AREONUM; i++)
    {
        if (x >= areo[2*i].x && x <= areo[2*i+1].x && y >= areo[2*i].y && y <= areo[2*i+1].y)
        {
            if (i < AREONUM/2)
            {
                placeto->y = correct[i];
                
            }
            else
            {
                placeto->x = correct[i];
                
            }
            *flag += 2*i+1;
        }
    }
    if ((*flag)%2 == 0)
    {
        for ( i = 0; i < MAXSIZE; i++)
        {
            if (placeto->x == node[i].x && placeto->y == node[i].y)
            {
                *nodenum = i;
                break;
            }
            
        }
        
    }
    else if(*flag == 1) //在第一条路上只有0号路口结点
    {
        *nodenum =0;
    }
    
    
}

//判断最近的路口两个结点
// place1/place2:暂存两个最近的路口结点
// void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
// {
//     int i,j;
//     double max;//存最大距离
//     int temp[AREONUM][3]={
//         {0,NOWAY,NOWAY},
//         {1,2,3},
//         {4,5,6},
//         {7,8,9},
//         {4,7,NOWAY},
//         {0,1,5},
//         {2,6,8},
//         {3,9,NOWAY}
//     };//存路与结点的关系
//     int dele;//舍弃的点

//     switch (flag)
//     {
//     case 3://在1号路上
//         max = pow(node[temp[1][0]].x-place.x,2)+pow(node[temp[1][0]].y-place.y,2);
//         dele = 0;
//         for ( i = 0; i < 3; i++)
//         {
//             if (max < pow(node[temp[1][i]].x-place.x,2)+pow(node[temp[1][i]].y-place.y,2))
//             {
//                 max = pow(node[temp[1][i]].x-place.x,2)+pow(node[temp[1][i]].y-place.y,2);
//                 dele = i;
//             }
//         }
//         for ( i = 0,j =0; i < 2; i++,j++)
//         {
//             if (j==dele)
//             {
//                 j++;
//             }
//             nearplace[i]=temp[1][j];
//         }
//         break;
//     case 5:
//         max = pow(node[temp[2][0]].x-place.x,2)+pow(node[temp[2][0]].y-place.y,2);
//         dele = 0;
//         for ( i = 0; i < 3; i++)
//         {
//             if (max < pow(node[temp[2][i]].x-place.x,2)+pow(node[temp[2][i]].y-place.y,2))
//             {
//                 max = pow(node[temp[2][i]].x-place.x,2)+pow(node[temp[2][i]].y-place.y,2);
//                 dele = i;
//             }
//         }
//         for ( i = 0,j =0; i < 2; i++,j++)
//         {
//             if (j==dele)
//             {
//                 j++;
//             }
//             nearplace[i]=temp[2][j];
//         }
//         break;
//     case 7:
//         max = pow(node[temp[3][0]].x-place.x,2)+pow(node[temp[3][0]].y-place.y,2);
//         dele = 0;
//         for ( i = 0; i < 3; i++)
//         {
//             if (max < pow(node[temp[3][i]].x-place.x,2)+pow(node[temp[3][i]].y-place.y,2))
//             {
//                 max = pow(node[temp[3][i]].x-place.x,2)+pow(node[temp[3][i]].y-place.y,2);
//                 dele = i;
//             }
//         }
//         for ( i = 0,j =0; i < 2; i++,j++)
//         {
//             if (j==dele)
//             {
//                 j++;
//             }
//             nearplace[i]=temp[3][j];
//         }
//         break;
//     case 9:
//         nearplace[0]=4;
//         nearplace[1]=7;
//         break;
//     case 11:
//         max = pow(node[temp[5][0]].x-place.x,2)+pow(node[temp[5][0]].y-place.y,2);
//         dele = 0;
//         for ( i = 0; i < 3; i++)
//         {
//             if (max < pow(node[temp[5][i]].x-place.x,2)+pow(node[temp[5][i]].y-place.y,2))
//             {
//                 max = pow(node[temp[5][i]].x-place.x,2)+pow(node[temp[5][i]].y-place.y,2);
//                 dele = i;
//             }
//         }
//         for ( i = 0,j =0; i < 2; i++,j++)
//         {
//             if (j==dele)
//             {
//                 j++;
//             }
//             nearplace[i]=temp[5][j];
//         }
//         break;
//     case 13:
//         max = pow(node[temp[6][0]].x-place.x,2)+pow(node[temp[6][0]].y-place.y,2);
//         dele = 0;
//         for ( i = 0; i < 3; i++)
//         {
//             if (max < pow(node[temp[6][i]].x-place.x,2)+pow(node[temp[6][i]].y-place.y,2))
//             {
//                 max = pow(node[temp[6][i]].x-place.x,2)+pow(node[temp[6][i]].y-place.y,2);
//                 dele = i;
//             }
//         }
//         for ( i = 0,j =0; i < 2; i++,j++)
//         {
//             if (j==dele)
//             {
//                 j++;
//             }
//             nearplace[i]=temp[6][j];
//         }
//         break;
//     case 15:
//         nearplace[0]=3;
//         nearplace[1]=9;
//         break;
//     default:
//         break;
//     }
// }
//改良寻找结点,寻找当前位置路段两侧的结点(一定要正确，对后面是否找到最短路径有很大影响)
void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
{
    int i,j;
    // double min;//存最大距离
    int temp[AREONUM][3]={
        {0,NOWAY,NOWAY},
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {4,7,NOWAY},
        {0,1,5},
        {2,6,8},
        {3,9,NOWAY}
    };//存路与结点的关系
    int midpoint = 1;//中间的点一定会是其中一个结点1=(0+2)/2

    switch (flag)
    {
    case 3://在1号路上
        nearplace[0] = temp[1][midpoint];
        if (place.x - node[temp[1][midpoint]].x < 0)
        {
            if (place.x - node[temp[1][0]].x > 0)
            {
                nearplace[1] = temp[1][0];
            }
            else
            {
                nearplace[1] = temp[1][2];
            } 
        }
        else
        {
            if (place.x - node[temp[1][0]].x < 0)
            {
                nearplace[1] = temp[1][0];
            }
            else
            {
                nearplace[1] = temp[1][2];
            } 
        }
        break;
    case 5:
        nearplace[0] = temp[2][midpoint];
        if (place.x - node[temp[2][midpoint]].x < 0)
        {
            if (place.x - node[temp[2][0]].x > 0)
            {
                nearplace[1] = temp[2][0];
            }
            else
            {
                nearplace[1] = temp[2][2];
            } 
        }
        else
        {
            if (place.x - node[temp[2][0]].x < 0)
            {
                nearplace[1] = temp[2][0];
            }
            else
            {
                nearplace[1] = temp[2][2];
            } 
        }
        break;
    case 7:
        nearplace[0] = temp[3][midpoint];
        if (place.x - node[temp[3][midpoint]].x < 0)
        {
            if (place.x - node[temp[3][0]].x > 0)
            {
                nearplace[1] = temp[3][0];
            }
            else
            {
                nearplace[1] = temp[3][2];
            } 
        }
        else
        {
            if (place.x - node[temp[3][0]].x < 0)
            {
                nearplace[1] = temp[3][0];
            }
            else
            {
                nearplace[1] = temp[3][2];
            } 
        }
        break;
    case 9:
        nearplace[0]=4;
        nearplace[1]=7;
        break;
    case 11:
        nearplace[0] = temp[5][midpoint];
        if (place.y - node[temp[5][midpoint]].y < 0)
        {
            if (place.y - node[temp[5][0]].y > 0)
            {
                nearplace[1] = temp[5][0];
            }
            else
            {
                nearplace[1] = temp[5][2];
            } 
        }
        else
        {
            if (place.y - node[temp[5][0]].y < 0)
            {
                nearplace[1] = temp[5][0];
            }
            else
            {
                nearplace[1] = temp[5][2];
            } 
        }
        break;
    case 13:
        nearplace[0] = temp[6][midpoint];
        if (place.y - node[temp[6][midpoint]].y < 0)
        {
            if (place.y - node[temp[6][0]].y > 0)
            {
                nearplace[1] = temp[6][0];
            }
            else
            {
                nearplace[1] = temp[6][2];
            } 
        }
        else
        {
            if (place.y - node[temp[6][0]].y < 0)
            {
                nearplace[1] = temp[6][0];
            }
            else
            {
                nearplace[1] = temp[6][2];
            } 
        }
        break;
    case 15:
        nearplace[0]=3;
        nearplace[1]=9;
        break;
    default:
        break;
    }
}




// //判断终点/起点要去两个结点中的哪一个结点
// void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum)
// {
//     int i;
//     double min;//距离最近的距离
//     *placenum = nearplace[0];
//     min = pow(place.x-node[nearplace[0]].x,2)+pow(place.y-node[nearplace[0]].y,2);
//     if (min > pow(place.x-node[nearplace[1]].x,2)+pow(place.y-node[nearplace[1]].y,2))
//     {
//         *placenum = nearplace[1];
//     }
    
// }

//判断终点/起点要去两个结点中的哪一个结点(改良)事先计算距离再选择距离最短的方案
void StartAndEnd(PLACE node[MAXSIZE],PLACE placenow,PLACE placeto, int nearstart[2],int nearend[2],int *start, int *end)
{
    int i;
    double min;//距离最近的距离
    int tempway[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};
    int tempcount=0;
    float distance;
    *start = nearstart[0];
    *end = nearend[0];
    //若4个结点中有相同的结点，则起点与终点选为同一个结点(dijkstra当只有一个结点时，会认为没有路径从而返回最大距离)
    if (nearstart[0]==nearend[0])
    {
        *start = nearstart[0];
        *end = nearend[0];
    }
    else if(nearstart[0]==nearend[1])
    {
        *start = nearstart[0];
        *end = nearend[1];
    }
    else if(nearstart[1]==nearend[0])
    {
        *start = nearstart[1];
        *end = nearend[0];
    }
    else if(nearstart[1]==nearend[1])
    {
        *start = nearstart[1];
        *end = nearend[1];
    }
    else //当四个结点都不同时，比较这4中选择方法哪种路径最短
    {
        min = Dijkstra(nearend[0],nearstart[0],tempway,&tempcount)+abs(placenow.x-node[nearstart[0]].x+placenow.y-node[nearstart[0]].y)+abs(placeto.x-node[nearend[0]].x+placeto.y-node[nearend[0]].y);
    //               结点与结点之间的最短路径                           +                           起点到第一个结点的距离                    +                  最后一个结点到终点的距离        
        distance = Dijkstra(nearend[0],nearstart[1],tempway,&tempcount)+abs(placenow.x-node[nearstart[1]].x+placenow.y-node[nearstart[1]].y)+abs(placeto.x-node[nearend[0]].x+placeto.y-node[nearend[0]].y);
        
        if (min > distance)
        {
            *start = nearstart[1];
            min = distance;
        }

        distance = Dijkstra(nearend[1],nearstart[0],tempway,&tempcount)+abs(placenow.x-node[nearstart[0]].x+placenow.y-node[nearstart[0]].y)+abs(placeto.x-node[nearend[1]].x+placeto.y-node[nearend[1]].y);
        if (min > distance)
        {
            *end = nearend[1];
            min = distance;
        }

        distance = Dijkstra(nearend[1],nearstart[1],tempway,&tempcount)+abs(placenow.x-node[nearstart[1]].x+placenow.y-node[nearstart[1]].y)+abs(placeto.x-node[nearend[1]].x+placeto.y-node[nearend[1]].y);
        
        if (min > distance)
        {
            *start = nearstart[1];
            *end = nearend[1];
        }
    }
    
}


//将寻找的路径转换为动画
int linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y,USEINFOR *infor,int *avoid)
{
    int i;
    int mx,my,button;
    int sigle=0;//用于接力退出
    for ( i = 0; i < count; i++)
    { 
        sigle = rentmove(car_position,node[way[i]].x,node[way[i]].y,node[way[i+1]].x,node[way[i+1]].y,x,y,direct[i],energe,infor,avoid);
        if (sigle == 1)
        {
            break;
        }
        
    }
    return sigle;
}
//寻路
int find(int *x, int *y, CARRENT *rcar, USEINFOR *infor, const PARK parking[])
{
    int mx,my,button;//鼠标点击
    int i;//用于计数
    int avoid = 0;//避免反复提醒电量过低
    int sigle=0;//用于接力退出
    int lockflag = 0;//判断能否锁车,值为1时可以锁车，可以还车
    int nowflag = 0;//判断是否在结点，若为偶数则在路口结点，直接跳过findNode()和StartAndEnd()两个函数
    int toflag = 0;
    int start;//起点标号
    int startdir=0;//起点方向
    int end;//终点标号
    int enddir=0;//终点方向
    int nearstart[2];//存起点两侧的结点
    int nearend[2];//存终点两侧的结点
    int count = 0;//记录有几个节点，总结点(加上起点与终点)为count+1;
    PLACE placeto;//鼠标点击位置的坐标
    PLACE placenow;//当前位置所在的坐标
    int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//记录路径顺序
    int direct[MAXSIZE]={0};//记录方向，1上2下3左4右
    PLACE node[MAXSIZE]={//各个结点的坐标
        {272,25},//0
        {272,268},//1
        {468,268},//2
        {715,268},//3
        {45,465},//4
        {272,465},//5
        {468,465},//6
        {45,720},//7
        {468,720},//8
        {715,720}//9
    };
    /*初始化小车*/
	CAR_CONDITION car_position;

    car_position.xpixel=rcar->rentcar.x;
    car_position.ypixel=rcar->rentcar.y;

    placenow.x=rcar->rentcar.x;
    placenow.y=rcar->rentcar.y;

    judgeAreo(node,rcar->rentcar.x,rcar->rentcar.y,&placenow,&nowflag,&start);//确认当前区域

    if (nowflag%2 != 0 && nowflag != 1)//若当前位置不在路口结点处，判断最近两个结点是哪两个
    {
        findNode(node,placenow,nearstart,nowflag);
    }

    /*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(44*44*sizeof(unsigned int));
                
    /*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
    //存小车当前位置的背景
    get_image(placenow.x-22,placenow.y-22,placenow.x+22,placenow.y+22,(car_position).pic);
    //根据小车的位置和停车场编号画出起始的小车
    switch (rcar->parknum)
    {
        case 1:
            car_draw_right1(placenow.x,placenow.y);
            break;
        case 2:
            car_draw_right1(placenow.x,placenow.y);
            break;
        case 3:
            car_draw_left1(placenow.x,placenow.y);
            break;
        case 4:
            car_draw_left1(placenow.x,placenow.y);
            break;
        case 5:
            car_draw_on1(placenow.x,placenow.y);
            break;
        case 6:
            car_draw_right1(placenow.x,placenow.y);
            break;
        default:
            break;
    }

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        
        // judgEnergy(&(rcar->leftenergy), &avoid, x, y,infor);
        
        
        
        if(mx>=798  && mx<=994 && my>=532 && my<=584 && button)//点击锁车，判断是否能锁车
        {
            lockcar(parking,car_position,&lockflag,x,y);
            if (lockflag == 1)//确认还车
            {

                break;
            }
            
            
        }
        else if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
        {
            safe_box(x,y);
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        if (mx >= 1 && mx <= 767 && my >= 1 && my <= 767 && button  )
        {
            
            if (mousepress(mx,my) != 0)//检测是否在道路上,是的话开始寻路
            {
             
            
                judgeAreo(node,mx,my,&placeto,&toflag,&end);//确定点击区域，并修正坐标
                
                if (toflag %2 != 0 && toflag != 1)
                {
                    findNode(node,placeto,nearend,toflag);
                }
                // if (nowflag %2 != 0 && nowflag != 1)//若当前位置不在路口结点处，根据终点位置判断先去哪个结点
                // {
                //     StartAndEnd(node,placeto,nearstart,&start);
                // }
                // if (toflag %2 != 0 && toflag != 1)
                // {
                //     StartAndEnd(node,placenow,nearend,&end);
                // }

                //改良确认结点的方法，只要路口两端结点寻找正确，最后一定为最短路径
                if (nowflag %2 == 0 || nowflag == 1)//若当前位置在路口结点处，则给两个暂存结点的数组赋值
                {
                    nearstart[0] = start;
                    nearstart[1] = start;
                }
                if (toflag %2 == 0 || toflag == 1)
                {
                    nearend[0] = end;
                    nearend[1] = end;
                }
                StartAndEnd(node,placenow,placeto,nearstart,nearend,&start,&end);


                //找两个结点间的最短路径
                Dijkstra(end,start,way,&count);
                //确定各个结点之间的方向
                direction(way,count,direct);
                //确认起点到第一个结点的方向
                if (placenow.y > node[start].y)
                {
                    startdir = 1;
                }
                else if (placenow.y < node[start].y)
                {
                    startdir = 2;
                }
                else if (placenow.x > node[start].x)
                {
                    startdir = 3;
                }
                else if (placenow.x < node[start].x)
                {
                    startdir = 4;
                }
                //确认结点到最后一个终点的方向
                if (placeto.y < node[end].y)
                {
                    enddir = 1;
                }
                else if (placeto.y > node[end].y)
                {
                    enddir = 2;
                }
                else if (placeto.x < node[end].x)
                {
                    enddir = 3;
                }
                else if (placeto.x > node[end].x)
                {
                    enddir = 4;
                }
                
                
                if (nowflag != toflag)//若起点和终点不在同一个区域
                {
                    //若起点不在结点，让车从起点到第一个结点
                    if (startdir != 0)
                    {
                    
                        sigle = rentmove(&car_position,placenow.x,placenow.y,node[start].x,node[start].y,x,y,startdir,&(rcar->leftenergy),infor,&avoid);
                        if(sigle==1)//用于安全报警后的接力退出
			            {
				            break;
			            }
                        // judgEnergy(&(rcar->leftenergy), &avoid, x, y,infor);
                    }
                    
                    //若终点不在结点上，第一个结点到最后一个结点
                    sigle = linkCartoon(&car_position,node,way,direct,count,&(rcar->leftenergy),x,y,infor,&avoid);
                    if(sigle==1)//用于安全报警后的接力退出
			        {
				        break;
			        }
                    //最后一个结点到终点
                    if (enddir != 0)
                    {
                        sigle = rentmove(&car_position,node[end].x,node[end].y,placeto.x,placeto.y,x,y,enddir,&(rcar->leftenergy),infor,&avoid);
                        if(sigle==1)//用于安全报警后的接力退出
			            {
				            break;
			            }
                        // judgEnergy(&(rcar->leftenergy), &avoid, x, y,infor);
                    }
                    
                }
                else//起点和终点在同一个区域,直接让车从起点走到终点，此时不用寻路
                {
                    if (placenow.y>placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,1,&(rcar->leftenergy),infor,&avoid);//向上走
                    }
                    else if (placenow.y<placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,2,&(rcar->leftenergy),infor,&avoid);//向下走
                    }
                    else if (placenow.x>placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,3,&(rcar->leftenergy),infor,&avoid);//向左走
                    }
                    else if (placenow.x<placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,4,&(rcar->leftenergy),infor,&avoid);//向右走
                    }
                    if(sigle==1)//用于安全报警后的接力退出
			        {
				        break;
			        }
                }
                
                
                //将终点的信息赋给当前位置，作为下一个起点
                start = end;
                nowflag = toflag;
                
                nearstart[0]=nearend[0];
                nearstart[1]=nearend[1];
                placenow.x = placeto.x;
                placenow.y = placeto.y;
                startdir=0;
                enddir=0;
                //将一些值赋空，否则可能会受影响
                for ( i = 0; way[i]!=NOWAY; i++)
                {
                    way[i]=NOWAY;
                    direct[1]=0;
                }
                count = 0;
            }
            else//若未点击到道路上,进行提示
            {
                mousehide(*x,*y);
                
                save_image(512-210,384-140,512+210,384+140,"rentnote");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(390,360,2,2,"请在道路上行驶",64384);
                fdhz(450,420,1,1,"按任意键继续",44373);
                getch();
                
                printf_image(512-210,384-140,512+210,384+140,"rentnote");
                reset_mouse(x,y);
            }
            
        }
    }
    //隐藏小车 
    put_image(car_position.xpixel-22,car_position.ypixel-22,car_position.xpixel+22,car_position.ypixel+22,car_position.pic);
    /*释放分配的内存空间*/
	free((car_position).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
    // reset_mouse(x,y);
    return sigle;
}
//确认鼠标点击区域
int mousepress(int mx,int my)
{
    int i;
    int value=0;
    PLACE areo[AREONUM*2]={
        {2,10},{386,40},//横0
        {257,253},{766,284},//横1
        {2,450},{483,480},//横2
        {30,704},{730,736},//横3
        {30,450},{61,736},//竖4
        {257,10},{287,480},//竖5
        {453,253},{483,766},//竖6
        {700,253},{730,736}//竖7
    };
    for ( i = 0; i < AREONUM; i++)
    {
        if (mx>=areo[2*i].x&&mx<=areo[2*i+1].x&&my>=areo[2*i].y&&my<=areo[2*i+1].y)
        {
            value = i+1;
            break;
        }
    }
    
    return value;
    

}


//判断电量
void judgEnergy(int *energy,int *avoid, int *x, int *y, USEINFOR *infor)
{
    char menergy[5]="\0";//用于小车电量数字变化
    if (*energy <= 20 && *avoid==0)
    {
            *avoid = 1;
            mousehide(*x,*y);
                
            save_image(512-210,384-140,512+210,384+140,"energy");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(440,320,2,2,"电量过低",64384);
            fdhz(340,360,2,2,"请尽快找停车场停车",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"energy");
            reset_mouse(x,y);
    }
    if (*energy <= 5 )
    {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"energy");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(400,320,2,2,"电量即将耗尽",64384);
            fdhz(380,360,2,2,"请尽快靠边停车",64384);
            fdhz(400,420,1,1,"按任意键联系客服进行换电",44373);
            getch();
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(450,360,2,2,"换电中",64384);
			fdhz(460,420,1,1,"请耐心等待",44373);
            delay(3000);
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(440,320,2,2,"换电完成",64384);
            fdhz(390,360,2,2,"支付费用",64384);
            outtextxy(550,360,"50",2,2,15,64384);
            fdhz(600,360,2,2,"元",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();

            while (1)
            {
                if (infor->payway == 1)//支付方式为余额
                {
                    if (infor->money>=50)
                    {
                        changeMoney(infor,50);
                        mousehide(*x,*y);
                        save_image(512-210,384-140,512+210,384+140,"notice");
                        bar_round(512,384,416,270,50,1,64384);
                        bar_round(512,384,410,265,48,1,65535);
                        fdhz(440,360,2,2,"支付完成",64384);
                        fdhz(450,420,1,1,"按任意键继续",44373);
                        
                        getch();
                        printf_image(512-210,384-140,512+210,384+140,"notice");
                        reset_mouse(x,y);
                        *energy = 100;
                        break;
                    }
                
                    else  //若余额不足
                    {
                        mousehide(*x,*y);
                        save_image(512-210,384-140,512+210,384+140,"notice");
                        bar_round(512,384,416,270,50,1,64384);
                        bar_round(512,384,410,265,48,1,65535);
                        fdhz(440,360,2,2,"余额不足",64384);
                        fdhz(450,420,1,1,"按任意键充值",44373);
                        getch();
                        reset_mouse(x,y);
                        top_up(x,y,infor);
                        printf_image(512-210,384-140,512+210,384+140,"notice");
                        reset_mouse(x,y);
                    }
                }
                else if (infor->payway == 2)//支付方式为微信
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    bar_round(255-30+160,480-100,70,70,22,1,2016);//微信绿
                    FillCircle(221+160,480-100,20,65535);
                    FillCircle(241+160,490-100,15,2016);
                    FillCircle(241+160,490-100,13,65535);
                    FillCircle(241-6+160,490-2-100,2,2016);
                    FillCircle(241+6+160,490-2-100,2,2016);
                    FillCircle(221-9+160,480-3-100,2,2016);
                    FillCircle(221+9+160,480-3-100,2,2016);

                    fdhz(440,360,2,2,"支付完成",64384);
                    fdhz(450,420,1,1,"按任意键继续",44373);
                    getch();
                    
                    printf_image(512-210,384-140,512+210,384+140,"notice");
                    reset_mouse(x,y);
                    *energy = 100;
                    break;
                }
                else if (infor->payway == 3)//支付方式为支付宝
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    //画支付宝
                    bar_round(510-30-95,480-100,70,70,22,1,1535);//支付宝蓝
                    fdhz(455-95,450-100,4,4,"支",65535);

                    fdhz(440,360,2,2,"支付完成",64384);
                    fdhz(450,420,1,1,"按任意键继续",44373);
                    getch();
                    
                    printf_image(512-210,384-140,512+210,384+140,"notice");
                    reset_mouse(x,y);
                    *energy = 100;
                    break;
                }
                else      //若未选择支付方式则进入支付方式选择
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    fdhz(390,360,2,2,"未选择支付方式",64384);
                    fdhz(450,420,1,1,"按任意键继续",44373);
                    getch();
                    reset_mouse(x,y);
                    pay_way(x,y,infor);   
                    printf_image(512-210,384-140,512+210,384+140,"notice");
                    reset_mouse(x,y);
                }
            }
            printf_image(512-210,384-140,512+210,384+140,"energy");
            reset_mouse(x,y);
            bar_round(896,468,190,47,8,1,65535);
			sprintf(menergy,"%d",*energy);
			outtextxy(885,460,menergy,1,1,10,64384);
    }
}
//判断锁车
void lockcar(const PARK parking[], CAR_CONDITION car_position, int *lockflag, int *x, int *y)
{
    int i;
    int mx,my,button;
    double dis;
    for ( i = 0; i < PARKNUM; i++)
    {
        dis = pow(parking[i].x-car_position.xpixel,2)+pow(parking[i].y-car_position.ypixel,2);
        if (dis < PARKR*PARKR)
        {
            *lockflag = 1;
            break;
        }
        
    }
    if (*lockflag == 0)
    {
        mousehide(*x,*y);
        save_image(512-210,384-140,512+210,384+140,"lock");
        bar_round(512,384,416,270,50,1,64384);
        bar_round(512,384,410,265,48,1,65535);
        fdhz(380,360,2,2,"附近没有停车场",64384);
        fdhz(450,420,1,1,"按任意键继续",44373);
        getch();
        printf_image(512-210,384-140,512+210,384+140,"lock");
        reset_mouse(x,y);
    }
    else
    {
        mousehide(*x,*y);
        
        
        save_image(512-210,384-140,512+210,384+140,"lock");
        bar_round(512,384,416,270,50,1,64384);
        bar_round(512,384,410,265,48,1,65535);
        fdhz(440,360,2,2,"车已上锁",64384);
        // fdhz(450,420,1,1,"按任意键继续",44373);


        bar_round(423,460,130,52,20,1,64384);
        bar_round(423,460,124,47,18,1,65535);
        fdhz(385,455,1,1,"确认还车",64384);

        bar_round(601,460,130,52,20,1,64384);
        bar_round(601,460,124,47,18,1,65535);
        fdhz(580,455,1,1,"解锁",64384);

        while (1)
        {
            newxy(x,y,&button);
		    mx = *x;
		    my = *y;
            if (mx>=358  && mx<=488 && my>=434 && my<=486 && button)//确认还车
            {
                
                break;
            }
            else if (mx>=536  && mx<=666 && my>=434 && my<=486 && button)//解锁
            {
                *lockflag = 0;
                break;
            }
        
        }

        printf_image(512-210,384-140,512+210,384+140,"lock");
        reset_mouse(x,y);
    }
    
 
}
// void main()
// {
//     int i;
//     int nowflag = 0;
//     int toflag = 0;
//     int start = 2;//起点标号
//     int end = 7;//终点标号
//     int count = 0;//记录有几个节点，总结点(加上起点与终点)为count+1;
//     int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//记录路径顺序
//     int direct[MAXSIZE]={0};//记录方向，1上2下3左4右
//     PLACE node[MAXSIZE]={//各个结点的坐标
//         {272,25},//0
//         {272,268},//1
//         {468,268},//2
//         {715,268},//3
//         {45,465},//4
//         {272,465},//5
//         {468,465},//6
//         {45,720},//7
//         {468,720},//8
//         {715,720}//9
//     };
//     Dijkstra(end,start,way,&count);//起点终点反着传递
//     printf("count = %d\n",count);
//     direction(way,count,direct);
//     for ( i = 0; i < count; i++)
//     {
//         printf("%d\n",direct[i]);
//     }
//     // while (1)
//     // {
        
//     // }
 

// }