#ifndef  _FINDWAY_H_
#define  _FINDWAY_H_

#define MAXSIZE 10
#define INF 9999
#define NOWAY -1
#define DIRECTNUM 4
#define AREONUM 8 //道路分为八个区，四个横着，四个竖着
#define PARKR 60  //判断停车时与停车场的半径
#define PARKNUM 6 //停车场数量

/***********************************************
功能说明:最短路径算法
注意事项:由于最后存储是逆序的，所以实际找的是终点到起点的最短路径，所以在调用时先传入终点，再传入起点
参数说明:start:开始结点的序号(实际终点的序号)
        end:结束结点的序号(实际起点的序号)
        way:数组，用于存储找到的路径途经的结点序号(包括起点和终点)
        count:途经的结点数目(不包括起点)
返回值:最短距离为多长
****************************************************/
int Dijkstra(int start, int end, int way[], int *count);


/***********************************************
功能说明:确认找到的最短路径中每个结点之间的方向
注意事项:
参数说明:way:数组，用于存储找到的路径途经的结点序号(包括起点和终点)
        count:途经的结点数目(不包括起点)
        direct:数组，用于存储way[]中结点与结点之间的方向
                (1上2下3左4右)
****************************************************/
void direction(int way[], int count, int direct[]);


/***********************************************
功能说明:判断鼠标点击区域，只能点击道路且要将坐标修正为路中央,若为路口，则直接修正为路口坐标
注意事项:
参数说明:node:路口结点的坐标
        x、y:点击的坐标(修正前的坐标)
        placeto:放修正之后的坐标
        flag:判断在哪条路上(值 += 2*路的编号+1)若为奇数，则说明在路口处
        nodenum:若在路口，放判断后的结点序号
****************************************************/
void judgeAreo(PLACE node[MAXSIZE],int x, int y, PLACE *placeto, int *flag, int *nodenum);

/***********************************************
功能说明:判断最近的路口两个结点
注意事项:
参数说明:node:路口结点的坐标
        place:修正之后的坐标
        flag:判断在哪条路上(值 += 2*路的编号+1)若为奇数，则说明在路口处(4号路和7号路只有两个结点)
        nearplace:存找到的最近的两个路口结点
****************************************************/
void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag);

/***********************************************
功能说明:判断终点/起点要去两个结点中的哪一个结点(使路径更短)
注意事项:找起点附近结点时place为终点坐标;找终点附近节点时place为起点坐标
参数说明:node:路口结点的坐标
        place:修正之后的坐标
        nearplace:存找到的最近的两个路口结点
        placenum:放判断后的结点
****************************************************/
// void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum);
/***********************************************
功能说明:(加强改良版)判断终点/起点要去两个结点中的哪一个结点(使路径更短)
注意事项:
参数说明:node:路口结点的坐标
        placenow:修正之后的当前坐标
        placeto:修正之后的终点坐标
        nearstart:存找到的离当前位置最近的两个路口结点
        nearend:存找到的离终点最近的两个路口结点
        start:放判断后的当前要去的第一个结点
        end:放判断后去终点前的最后一个结点
****************************************************/
void StartAndEnd(PLACE node[MAXSIZE],PLACE placenow,PLACE placeto, int nearstart[2],int nearend[2],int *start, int *end);

/***********************************************
功能说明:将寻找的路径转换为动画
注意事项:
参数说明:car_position:存小车运动信息的结构
        node:路口结点的坐标
        way:寻找到的路径结点
        direct:结点之间的方向
        count:途经的结点数目(不包括起点)
        energe:小车的电量
        x,y:鼠标
返回值说明:sigle:用于接力退出
****************************************************/
int linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y,USEINFOR *infor,int *avoid);


/***********************************************
功能说明:寻路主进程函数
注意事项:
参数说明:x,y:鼠标
        car_position:存小车运动信息的结构
        
        energe:小车的电量
        infor:用户信息结构
返回值说明:sigle:用于接力退出
****************************************************/
int find(int *x, int *y, CARRENT *rcar, USEINFOR *infor, const PARK parking[]);

/***********************************************
功能说明:确认鼠标点击区域,判断点击的区域是否在道路上
注意事项:
参数说明:mx,my:鼠标点击时所处的坐标
返回值说明:value:若未点击在道路上则返回0
****************************************************/
int mousepress(int mx,int my);

void judgEnergy(int *energy,int *avoid, int *x, int *y, USEINFOR *infor);

void lockcar(const PARK parking[], CAR_CONDITION car_position, int * lockflag, int *x, int *y);

#endif