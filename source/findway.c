#include "common.h"
#include "findway.h"

// #define MAXSIZE 10
// #define INF 9999
// #define NOWAY -1
// #define DIRECTNUM 4
// #define AREONUM 8 //��·��Ϊ�˸������ĸ����ţ��ĸ�����
// #define PARKR 60 //�ж�ͣ��ʱ��ͣ�����İ뾶
// #define PARKNUM 6

//���·���㷨���������洢������ģ�����ʵ���ҵ����յ㵽�������·��
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
    int dis[MAXSIZE]={0};//��ÿ��������·��
    int mark[MAXSIZE];//����1��Ϊ����ǣ�0Ϊδ����ǣ���δ�����
    int min;//���·������
    int next;//��һ�����뼯��P�ĵ�
    int last[MAXSIZE];//��¼��һ�������ĸ���
    // int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//��¼·��˳��
    for ( i = 0; i < MAXSIZE; i++)//��ʼ��mark[]��������dis[]���·����last[]��һ�ڵ�
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
    mark[start] = 1; //������
    for ( j = 0; j < MAXSIZE; j++)
    {
        min = INF;//��ʼ��Ϊ����ֵ

        for ( i = 0; i < MAXSIZE; i++)
        {
            if (mark[i] == 0 && min > dis[i])//δ���������ұ���ֵ�����·��
            {
                min = dis[i];//����֪��ֵ���·���У���Ȩֵ��С�ĵ���Ϊ��һ�α��������
                next = vexs[i];
            }
        }
        mark[next] = 1; //����ҵ�����һ���������
        //�������·��
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
    mindis=dis[end];//һ��Ҫ�ȴ�����������dis[end]��ѭ���б��ı䣬���صĲ�����̾���
    way[0] = end;           //���ڵ������������
    while (end != start)
    {
        *count=*count+1;
        way[*count]=last[end];
        end = last[end];
    }
    return mindis;
}

// ȷ���ҵ������·����ÿ�����֮��ķ���
void direction(int way[], int count, int direct[])
{
    int i=0,j=0;
    int now;
    int node[MAXSIZE][DIRECTNUM] = { 
        //�ϣ��£�����
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
            if (node[now][i] == way[j+1])//���������λ���жϵ���һ�����ķ���
            {
                direct[j]=i+1;
            }
        }
        j++;
    }
}
//�ж����������ֻ�ܵ����·��Ҫ����Ϊ·����
//���뺯��������������ڵ�ͼ�����������ҵ����λ��Ϊ��ɫ����int  getpixel(int x,int y) <-�˷���ʧ��
//node:·�ڽ��
void judgeAreo(PLACE node[MAXSIZE],int x, int y, PLACE *placeto, int *flag, int *nodenum)
{
    
    int i;//���ڼ���
    PLACE areo[AREONUM*2]={
        {2,10},{386,40},//��0
        {257,253},{766,284},//��1
        {2,450},{483,480},//��2
        {30,704},{730,736},//��3
        {30,450},{61,736},//��4
        {257,10},{287,480},//��5
        {453,253},{483,766},//��6
        {700,253},{730,736}//��7
    };
    //����������
    int correct[AREONUM]={
        25,//��0��������
        268,//��1
        465,//��2
        720,//��3
        45,//��4�ĺ�����
        272,//��5
        468,//��6
        715//��7
    };
    

    *flag=0;//�����ж��Ƿ��ڽ����,����ż��ʱ��ʾ�Ѿ��ڽڵ�
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
    else if(*flag == 1) //�ڵ�һ��·��ֻ��0��·�ڽ��
    {
        *nodenum =0;
    }
    
    
}

//�ж������·���������
// place1/place2:�ݴ����������·�ڽ��
// void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
// {
//     int i,j;
//     double max;//��������
//     int temp[AREONUM][3]={
//         {0,NOWAY,NOWAY},
//         {1,2,3},
//         {4,5,6},
//         {7,8,9},
//         {4,7,NOWAY},
//         {0,1,5},
//         {2,6,8},
//         {3,9,NOWAY}
//     };//��·����Ĺ�ϵ
//     int dele;//�����ĵ�

//     switch (flag)
//     {
//     case 3://��1��·��
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
//����Ѱ�ҽ��,Ѱ�ҵ�ǰλ��·������Ľ��(һ��Ҫ��ȷ���Ժ����Ƿ��ҵ����·���кܴ�Ӱ��)
void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
{
    int i,j;
    // double min;//��������
    int temp[AREONUM][3]={
        {0,NOWAY,NOWAY},
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {4,7,NOWAY},
        {0,1,5},
        {2,6,8},
        {3,9,NOWAY}
    };//��·����Ĺ�ϵ
    int midpoint = 1;//�м�ĵ�һ����������һ�����1=(0+2)/2

    switch (flag)
    {
    case 3://��1��·��
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




// //�ж��յ�/���Ҫȥ��������е���һ�����
// void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum)
// {
//     int i;
//     double min;//��������ľ���
//     *placenum = nearplace[0];
//     min = pow(place.x-node[nearplace[0]].x,2)+pow(place.y-node[nearplace[0]].y,2);
//     if (min > pow(place.x-node[nearplace[1]].x,2)+pow(place.y-node[nearplace[1]].y,2))
//     {
//         *placenum = nearplace[1];
//     }
    
// }

//�ж��յ�/���Ҫȥ��������е���һ�����(����)���ȼ��������ѡ�������̵ķ���
void StartAndEnd(PLACE node[MAXSIZE],PLACE placenow,PLACE placeto, int nearstart[2],int nearend[2],int *start, int *end)
{
    int i;
    double min;//��������ľ���
    int tempway[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};
    int tempcount=0;
    float distance;
    *start = nearstart[0];
    *end = nearend[0];
    //��4�����������ͬ�Ľ�㣬��������յ�ѡΪͬһ�����(dijkstra��ֻ��һ�����ʱ������Ϊû��·���Ӷ�����������)
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
    else //���ĸ���㶼��ͬʱ���Ƚ���4��ѡ�񷽷�����·�����
    {
        min = Dijkstra(nearend[0],nearstart[0],tempway,&tempcount)+abs(placenow.x-node[nearstart[0]].x+placenow.y-node[nearstart[0]].y)+abs(placeto.x-node[nearend[0]].x+placeto.y-node[nearend[0]].y);
    //               �������֮������·��                           +                           ��㵽��һ�����ľ���                    +                  ���һ����㵽�յ�ľ���        
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


//��Ѱ�ҵ�·��ת��Ϊ����
int linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y,USEINFOR *infor,int *avoid)
{
    int i;
    int mx,my,button;
    int sigle=0;//���ڽ����˳�
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
//Ѱ·
int find(int *x, int *y, CARRENT *rcar, USEINFOR *infor, const PARK parking[])
{
    int mx,my,button;//�����
    int i;//���ڼ���
    int avoid = 0;//���ⷴ�����ѵ�������
    int sigle=0;//���ڽ����˳�
    int lockflag = 0;//�ж��ܷ�����,ֵΪ1ʱ�������������Ի���
    int nowflag = 0;//�ж��Ƿ��ڽ�㣬��Ϊż������·�ڽ�㣬ֱ������findNode()��StartAndEnd()��������
    int toflag = 0;
    int start;//�����
    int startdir=0;//��㷽��
    int end;//�յ���
    int enddir=0;//�յ㷽��
    int nearstart[2];//���������Ľ��
    int nearend[2];//���յ�����Ľ��
    int count = 0;//��¼�м����ڵ㣬�ܽ��(����������յ�)Ϊcount+1;
    PLACE placeto;//�����λ�õ�����
    PLACE placenow;//��ǰλ�����ڵ�����
    int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//��¼·��˳��
    int direct[MAXSIZE]={0};//��¼����1��2��3��4��
    PLACE node[MAXSIZE]={//������������
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
    /*��ʼ��С��*/
	CAR_CONDITION car_position;

    car_position.xpixel=rcar->rentcar.x;
    car_position.ypixel=rcar->rentcar.y;

    placenow.x=rcar->rentcar.x;
    placenow.y=rcar->rentcar.y;

    judgeAreo(node,rcar->rentcar.x,rcar->rentcar.y,&placenow,&nowflag,&start);//ȷ�ϵ�ǰ����

    if (nowflag%2 != 0 && nowflag != 1)//����ǰλ�ò���·�ڽ�㴦���ж�������������������
    {
        findNode(node,placenow,nearstart,nowflag);
    }

    /*����С��ͼ��ռ�*/
	(car_position).pic = (unsigned int*)malloc(44*44*sizeof(unsigned int));
                
    /*�������Ƿ�ɹ�*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//����
		getch();
		exit(1);
	}
    //��С����ǰλ�õı���
    get_image(placenow.x-22,placenow.y-22,placenow.x+22,placenow.y+22,(car_position).pic);
    //����С����λ�ú�ͣ������Ż�����ʼ��С��
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
        
        
        
        if(mx>=798  && mx<=994 && my>=532 && my<=584 && button)//����������ж��Ƿ�������
        {
            lockcar(parking,car_position,&lockflag,x,y);
            if (lockflag == 1)//ȷ�ϻ���
            {

                break;
            }
            
            
        }
        else if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
        {
            safe_box(x,y);
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        if (mx >= 1 && mx <= 767 && my >= 1 && my <= 767 && button  )
        {
            
            if (mousepress(mx,my) != 0)//����Ƿ��ڵ�·��,�ǵĻ���ʼѰ·
            {
             
            
                judgeAreo(node,mx,my,&placeto,&toflag,&end);//ȷ��������򣬲���������
                
                if (toflag %2 != 0 && toflag != 1)
                {
                    findNode(node,placeto,nearend,toflag);
                }
                // if (nowflag %2 != 0 && nowflag != 1)//����ǰλ�ò���·�ڽ�㴦�������յ�λ���ж���ȥ�ĸ����
                // {
                //     StartAndEnd(node,placeto,nearstart,&start);
                // }
                // if (toflag %2 != 0 && toflag != 1)
                // {
                //     StartAndEnd(node,placenow,nearend,&end);
                // }

                //����ȷ�Ͻ��ķ�����ֻҪ·�����˽��Ѱ����ȷ�����һ��Ϊ���·��
                if (nowflag %2 == 0 || nowflag == 1)//����ǰλ����·�ڽ�㴦����������ݴ�������鸳ֵ
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


                //��������������·��
                Dijkstra(end,start,way,&count);
                //ȷ���������֮��ķ���
                direction(way,count,direct);
                //ȷ����㵽��һ�����ķ���
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
                //ȷ�Ͻ�㵽���һ���յ�ķ���
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
                
                
                if (nowflag != toflag)//�������յ㲻��ͬһ������
                {
                    //����㲻�ڽ�㣬�ó�����㵽��һ�����
                    if (startdir != 0)
                    {
                    
                        sigle = rentmove(&car_position,placenow.x,placenow.y,node[start].x,node[start].y,x,y,startdir,&(rcar->leftenergy),infor,&avoid);
                        if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			            {
				            break;
			            }
                        // judgEnergy(&(rcar->leftenergy), &avoid, x, y,infor);
                    }
                    
                    //���յ㲻�ڽ���ϣ���һ����㵽���һ�����
                    sigle = linkCartoon(&car_position,node,way,direct,count,&(rcar->leftenergy),x,y,infor,&avoid);
                    if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			        {
				        break;
			        }
                    //���һ����㵽�յ�
                    if (enddir != 0)
                    {
                        sigle = rentmove(&car_position,node[end].x,node[end].y,placeto.x,placeto.y,x,y,enddir,&(rcar->leftenergy),infor,&avoid);
                        if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			            {
				            break;
			            }
                        // judgEnergy(&(rcar->leftenergy), &avoid, x, y,infor);
                    }
                    
                }
                else//�����յ���ͬһ������,ֱ���ó�������ߵ��յ㣬��ʱ����Ѱ·
                {
                    if (placenow.y>placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,1,&(rcar->leftenergy),infor,&avoid);//������
                    }
                    else if (placenow.y<placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,2,&(rcar->leftenergy),infor,&avoid);//������
                    }
                    else if (placenow.x>placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,3,&(rcar->leftenergy),infor,&avoid);//������
                    }
                    else if (placenow.x<placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,4,&(rcar->leftenergy),infor,&avoid);//������
                    }
                    if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			        {
				        break;
			        }
                }
                
                
                //���յ����Ϣ������ǰλ�ã���Ϊ��һ�����
                start = end;
                nowflag = toflag;
                
                nearstart[0]=nearend[0];
                nearstart[1]=nearend[1];
                placenow.x = placeto.x;
                placenow.y = placeto.y;
                startdir=0;
                enddir=0;
                //��һЩֵ���գ�������ܻ���Ӱ��
                for ( i = 0; way[i]!=NOWAY; i++)
                {
                    way[i]=NOWAY;
                    direct[1]=0;
                }
                count = 0;
            }
            else//��δ�������·��,������ʾ
            {
                mousehide(*x,*y);
                
                save_image(512-210,384-140,512+210,384+140,"rentnote");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(390,360,2,2,"���ڵ�·����ʻ",64384);
                fdhz(450,420,1,1,"�����������",44373);
                getch();
                
                printf_image(512-210,384-140,512+210,384+140,"rentnote");
                reset_mouse(x,y);
            }
            
        }
    }
    //����С�� 
    put_image(car_position.xpixel-22,car_position.ypixel-22,car_position.xpixel+22,car_position.ypixel+22,car_position.pic);
    /*�ͷŷ�����ڴ�ռ�*/
	free((car_position).pic);

	/*��ָ���ÿ�*/
	(car_position).pic = NULL;
    // reset_mouse(x,y);
    return sigle;
}
//ȷ�����������
int mousepress(int mx,int my)
{
    int i;
    int value=0;
    PLACE areo[AREONUM*2]={
        {2,10},{386,40},//��0
        {257,253},{766,284},//��1
        {2,450},{483,480},//��2
        {30,704},{730,736},//��3
        {30,450},{61,736},//��4
        {257,10},{287,480},//��5
        {453,253},{483,766},//��6
        {700,253},{730,736}//��7
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


//�жϵ���
void judgEnergy(int *energy,int *avoid, int *x, int *y, USEINFOR *infor)
{
    char menergy[5]="\0";//����С���������ֱ仯
    if (*energy <= 20 && *avoid==0)
    {
            *avoid = 1;
            mousehide(*x,*y);
                
            save_image(512-210,384-140,512+210,384+140,"energy");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(440,320,2,2,"��������",64384);
            fdhz(340,360,2,2,"�뾡����ͣ����ͣ��",64384);
            fdhz(450,420,1,1,"�����������",44373);
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
            fdhz(400,320,2,2,"���������ľ�",64384);
            fdhz(380,360,2,2,"�뾡�쿿��ͣ��",64384);
            fdhz(400,420,1,1,"���������ϵ�ͷ����л���",44373);
            getch();
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(450,360,2,2,"������",64384);
			fdhz(460,420,1,1,"�����ĵȴ�",44373);
            delay(3000);
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(440,320,2,2,"�������",64384);
            fdhz(390,360,2,2,"֧������",64384);
            outtextxy(550,360,"50",2,2,15,64384);
            fdhz(600,360,2,2,"Ԫ",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();

            while (1)
            {
                if (infor->payway == 1)//֧����ʽΪ���
                {
                    if (infor->money>=50)
                    {
                        changeMoney(infor,50);
                        mousehide(*x,*y);
                        save_image(512-210,384-140,512+210,384+140,"notice");
                        bar_round(512,384,416,270,50,1,64384);
                        bar_round(512,384,410,265,48,1,65535);
                        fdhz(440,360,2,2,"֧�����",64384);
                        fdhz(450,420,1,1,"�����������",44373);
                        
                        getch();
                        printf_image(512-210,384-140,512+210,384+140,"notice");
                        reset_mouse(x,y);
                        *energy = 100;
                        break;
                    }
                
                    else  //������
                    {
                        mousehide(*x,*y);
                        save_image(512-210,384-140,512+210,384+140,"notice");
                        bar_round(512,384,416,270,50,1,64384);
                        bar_round(512,384,410,265,48,1,65535);
                        fdhz(440,360,2,2,"����",64384);
                        fdhz(450,420,1,1,"���������ֵ",44373);
                        getch();
                        reset_mouse(x,y);
                        top_up(x,y,infor);
                        printf_image(512-210,384-140,512+210,384+140,"notice");
                        reset_mouse(x,y);
                    }
                }
                else if (infor->payway == 2)//֧����ʽΪ΢��
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    bar_round(255-30+160,480-100,70,70,22,1,2016);//΢����
                    FillCircle(221+160,480-100,20,65535);
                    FillCircle(241+160,490-100,15,2016);
                    FillCircle(241+160,490-100,13,65535);
                    FillCircle(241-6+160,490-2-100,2,2016);
                    FillCircle(241+6+160,490-2-100,2,2016);
                    FillCircle(221-9+160,480-3-100,2,2016);
                    FillCircle(221+9+160,480-3-100,2,2016);

                    fdhz(440,360,2,2,"֧�����",64384);
                    fdhz(450,420,1,1,"�����������",44373);
                    getch();
                    
                    printf_image(512-210,384-140,512+210,384+140,"notice");
                    reset_mouse(x,y);
                    *energy = 100;
                    break;
                }
                else if (infor->payway == 3)//֧����ʽΪ֧����
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    //��֧����
                    bar_round(510-30-95,480-100,70,70,22,1,1535);//֧������
                    fdhz(455-95,450-100,4,4,"֧",65535);

                    fdhz(440,360,2,2,"֧�����",64384);
                    fdhz(450,420,1,1,"�����������",44373);
                    getch();
                    
                    printf_image(512-210,384-140,512+210,384+140,"notice");
                    reset_mouse(x,y);
                    *energy = 100;
                    break;
                }
                else      //��δѡ��֧����ʽ�����֧����ʽѡ��
                {
                    mousehide(*x,*y);
                    save_image(512-210,384-140,512+210,384+140,"notice");
                    bar_round(512,384,416,270,50,1,64384);
                    bar_round(512,384,410,265,48,1,65535);
                    
                    fdhz(390,360,2,2,"δѡ��֧����ʽ",64384);
                    fdhz(450,420,1,1,"�����������",44373);
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
//�ж�����
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
        fdhz(380,360,2,2,"����û��ͣ����",64384);
        fdhz(450,420,1,1,"�����������",44373);
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
        fdhz(440,360,2,2,"��������",64384);
        // fdhz(450,420,1,1,"�����������",44373);


        bar_round(423,460,130,52,20,1,64384);
        bar_round(423,460,124,47,18,1,65535);
        fdhz(385,455,1,1,"ȷ�ϻ���",64384);

        bar_round(601,460,130,52,20,1,64384);
        bar_round(601,460,124,47,18,1,65535);
        fdhz(580,455,1,1,"����",64384);

        while (1)
        {
            newxy(x,y,&button);
		    mx = *x;
		    my = *y;
            if (mx>=358  && mx<=488 && my>=434 && my<=486 && button)//ȷ�ϻ���
            {
                
                break;
            }
            else if (mx>=536  && mx<=666 && my>=434 && my<=486 && button)//����
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
//     int start = 2;//�����
//     int end = 7;//�յ���
//     int count = 0;//��¼�м����ڵ㣬�ܽ��(����������յ�)Ϊcount+1;
//     int way[MAXSIZE]={NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY,NOWAY};//��¼·��˳��
//     int direct[MAXSIZE]={0};//��¼����1��2��3��4��
//     PLACE node[MAXSIZE]={//������������
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
//     Dijkstra(end,start,way,&count);//����յ㷴�Ŵ���
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