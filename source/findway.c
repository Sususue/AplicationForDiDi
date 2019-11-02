#include "common.h"
#include "findway.h"

// #define MAXSIZE 10
// #define INF 9999
// #define NOWAY -1
// #define DIRECTNUM 4
// #define AREONUM 8 //道路分为八个区，四个横着，四个竖着

//最短路径算法，由于最后存储是逆序的，所以实际找的是终点到起点的最短路径
void Dijkstra(int start, int end, int way[], int *count)
{
    int i,j;
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
    int dis[MAXSIZE];//到每个点的最短路径
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
    way[0] = end;           //将节点逆序存入数组
    while (end != start)
    {
        *count=*count+1;
        way[*count]=last[end];
        end = last[end];
    }
  
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
    

    *flag=0;//用以判断是否在结点上,等于2时表示已经在节点
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
            *flag+=2*i+1;
        }
    }
    if (*flag%2 == 0)
    {
        for ( i = 0; i < AREONUM; i++)
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
void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
{
    int i,j;
    // const int maxnum = 3;//这条路上最多三个结点
    double max;//存最大距离
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
    int dele;//舍弃的点

    switch (flag)
    {
    case 3://在1号路上
        max = pow(node[temp[1][0]].x-place.x,2)+pow(node[temp[1][0]].y-place.y,2);
        dele = 0;
        for ( i = 0; i < 3; i++)
        {
            if (max < pow(node[temp[1][i]].x-place.x,2)+pow(node[temp[1][i]].y-place.y,2))
            {
                max = pow(node[temp[1][i]].x-place.x,2)+pow(node[temp[1][i]].y-place.y,2);
                dele = i;
            }
        }
        for ( i = 0,j =0; i < 2; i++,j++)
        {
            if (j==dele)
            {
                j++;
            }
            nearplace[i]=temp[1][j];
        }
        break;
    case 5:
        max = pow(node[temp[2][0]].x-place.x,2)+pow(node[temp[2][0]].y-place.y,2);
        dele = 0;
        for ( i = 0; i < 3; i++)
        {
            if (max < pow(node[temp[2][i]].x-place.x,2)+pow(node[temp[2][i]].y-place.y,2))
            {
                max = pow(node[temp[2][i]].x-place.x,2)+pow(node[temp[2][i]].y-place.y,2);
                dele = i;
            }
        }
        for ( i = 0,j =0; i < 2; i++,j++)
        {
            if (j==dele)
            {
                j++;
            }
            nearplace[i]=temp[2][j];
        }
        break;
    case 7:
        max = pow(node[temp[3][0]].x-place.x,2)+pow(node[temp[3][0]].y-place.y,2);
        dele = 0;
        for ( i = 0; i < 3; i++)
        {
            if (max < pow(node[temp[3][i]].x-place.x,2)+pow(node[temp[3][i]].y-place.y,2))
            {
                max = pow(node[temp[3][i]].x-place.x,2)+pow(node[temp[3][i]].y-place.y,2);
                dele = i;
            }
        }
        for ( i = 0,j =0; i < 2; i++,j++)
        {
            if (j==dele)
            {
                j++;
            }
            nearplace[i]=temp[3][j];
        }
        break;
    case 9:
        nearplace[1]=4;
        nearplace[2]=7;
        break;
    case 11:
        max = pow(node[temp[5][0]].x-place.x,2)+pow(node[temp[5][0]].y-place.y,2);
        dele = 0;
        for ( i = 0; i < 3; i++)
        {
            if (max < pow(node[temp[5][i]].x-place.x,2)+pow(node[temp[5][i]].y-place.y,2))
            {
                max = pow(node[temp[5][i]].x-place.x,2)+pow(node[temp[5][i]].y-place.y,2);
                dele = i;
            }
        }
        for ( i = 0,j =0; i < 2; i++,j++)
        {
            if (j==dele)
            {
                j++;
            }
            nearplace[i]=temp[5][j];
        }
        break;
    case 13:
        max = pow(node[temp[6][0]].x-place.x,2)+pow(node[temp[6][0]].y-place.y,2);
        dele = 0;
        for ( i = 0; i < 3; i++)
        {
            if (max < pow(node[temp[6][i]].x-place.x,2)+pow(node[temp[6][i]].y-place.y,2))
            {
                max = pow(node[temp[6][i]].x-place.x,2)+pow(node[temp[6][i]].y-place.y,2);
                dele = i;
            }
        }
        for ( i = 0,j =0; i < 2; i++,j++)
        {
            if (j==dele)
            {
                j++;
            }
            nearplace[i]=temp[6][j];
        }
        break;
    case 15:
        nearplace[1]=3;
        nearplace[2]=9;
        break;
    default:
        break;
    }
}
//判断终点/起点要去两个结点中的哪一个结点
void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum)
{
    int i;
    double min;//几路最近的距离
    *placenum = nearplace[0];
    min = pow(place.x-node[nearplace[0]].x,2)+pow(place.y-node[nearplace[0]].y,2);
    if (min > pow(place.x-node[nearplace[1]].x,2)+pow(place.y-node[nearplace[1]].y,2))
    {
        *placenum = nearplace[1];
    }
    
}
//将寻找的路径转换为动画
int linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y)
{
    int i;
    int mx,my,button;
    int sigle=0;//用于接力退出
    for ( i = 0; i < count; i++)
    { 
        sigle = rentmove(car_position,node[way[i]].x,node[way[i]].y,node[way[i+1]].x,node[way[i+1]].y,x,y,direct[i],energe);
        if (sigle == 1)
        {
            break;
        }
        
    }
    return sigle;
}
//寻路
int find(int *x, int *y, int startx,int starty, int *energe)
{
    int mx,my,button;//鼠标点击
    int i;//用于计数
    int sigle=0;//用于接力退出
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
    placenow.x=startx;
    placenow.y=starty;

    judgeAreo(node,startx,starty,&placenow,&nowflag,&start);//确认当前区域

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
    car_draw_right1(placenow.x,placenow.y);//写死实验


    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=798  && mx<=994 && my>=532 && my<=584 && button)//点击锁车，判断是否能锁车
        {
            break;
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
                if (nowflag %2 != 0 && nowflag != 1)//若当前位置不在路口结点处，根据终点位置判断先去哪个结点
                {
                    StartAndEnd(node,placeto,nearstart,&start);
                }
                if (toflag %2 != 0 && toflag != 1)
                {
                    StartAndEnd(node,placenow,nearend,&end);
                }
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
                    
                        sigle = rentmove(&car_position,placenow.x,placenow.y,node[start].x,node[start].y,x,y,startdir,energe);
                        if(sigle==1)//用于安全报警后的接力退出
			            {
				            break;
			            }
                    }
                    
                    //若终点不在结点上，第一个结点到最后一个结点
                    sigle = linkCartoon(&car_position,node,way,direct,count,energe,x,y);
                    if(sigle==1)//用于安全报警后的接力退出
			        {
				        break;
			        }
                    //最后一个结点到终点
                    if (enddir != 0)
                    {
                        sigle = rentmove(&car_position,node[end].x,node[end].y,placeto.x,placeto.y,x,y,enddir,energe);
                        if(sigle==1)//用于安全报警后的接力退出
			            {
				            break;
			            }
                    }
                    
                }
                else//起点和终点在同一个区域,直接让车从起点走到终点，此时不用寻路
                {
                    if (placenow.y>placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,1,energe);//向上走
                    }
                    else if (placenow.y<placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,2,energe);//向下走
                    }
                    else if (placenow.x>placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,3,energe);//向左走
                    }
                    else if (placenow.x<placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,4,energe);//向右走
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
                for ( i = 0; i < count; i++)
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
                fdhz(450,420,1,1,"按任意键充值",44373);
                getch();
                
                printf_image(512-210,384-140,512+210,384+140,"rentnote");
                reset_mouse(x,y);
            }
            
        }
    }
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