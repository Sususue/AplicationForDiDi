#include "common.h"
#include "findway.h"

// #define MAXSIZE 10
// #define INF 9999
// #define NOWAY -1
// #define DIRECTNUM 4
// #define AREONUM 8 //��·��Ϊ�˸������ĸ����ţ��ĸ�����

//���·���㷨���������洢������ģ�����ʵ���ҵ����յ㵽�������·��
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
    int dis[MAXSIZE];//��ÿ��������·��
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
    way[0] = end;           //���ڵ������������
    while (end != start)
    {
        *count=*count+1;
        way[*count]=last[end];
        end = last[end];
    }
  
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
    

    *flag=0;//�����ж��Ƿ��ڽ����,����2ʱ��ʾ�Ѿ��ڽڵ�
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
    else if(*flag == 1) //�ڵ�һ��·��ֻ��0��·�ڽ��
    {
        *nodenum =0;
    }
    
    
}

//�ж������·���������
// place1/place2:�ݴ����������·�ڽ��
void findNode(PLACE node[MAXSIZE],PLACE place,int nearplace[2],int flag)
{
    int i,j;
    // const int maxnum = 3;//����·������������
    double max;//��������
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
    int dele;//�����ĵ�

    switch (flag)
    {
    case 3://��1��·��
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
//�ж��յ�/���Ҫȥ��������е���һ�����
void StartAndEnd(PLACE node[MAXSIZE], PLACE place, int nearplace[2],int *placenum)
{
    int i;
    double min;//��·����ľ���
    *placenum = nearplace[0];
    min = pow(place.x-node[nearplace[0]].x,2)+pow(place.y-node[nearplace[0]].y,2);
    if (min > pow(place.x-node[nearplace[1]].x,2)+pow(place.y-node[nearplace[1]].y,2))
    {
        *placenum = nearplace[1];
    }
    
}
//��Ѱ�ҵ�·��ת��Ϊ����
int linkCartoon(CAR_CONDITION *car_position,PLACE node[MAXSIZE], int way[MAXSIZE], int direct[MAXSIZE], int count, int *energe, int *x,int *y)
{
    int i;
    int mx,my,button;
    int sigle=0;//���ڽ����˳�
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
//Ѱ·
int find(int *x, int *y, int startx,int starty, int *energe)
{
    int mx,my,button;//�����
    int i;//���ڼ���
    int sigle=0;//���ڽ����˳�
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
    placenow.x=startx;
    placenow.y=starty;

    judgeAreo(node,startx,starty,&placenow,&nowflag,&start);//ȷ�ϵ�ǰ����

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
    car_draw_right1(placenow.x,placenow.y);//д��ʵ��


    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=798  && mx<=994 && my>=532 && my<=584 && button)//����������ж��Ƿ�������
        {
            break;
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
                if (nowflag %2 != 0 && nowflag != 1)//����ǰλ�ò���·�ڽ�㴦�������յ�λ���ж���ȥ�ĸ����
                {
                    StartAndEnd(node,placeto,nearstart,&start);
                }
                if (toflag %2 != 0 && toflag != 1)
                {
                    StartAndEnd(node,placenow,nearend,&end);
                }
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
                    
                        sigle = rentmove(&car_position,placenow.x,placenow.y,node[start].x,node[start].y,x,y,startdir,energe);
                        if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			            {
				            break;
			            }
                    }
                    
                    //���յ㲻�ڽ���ϣ���һ����㵽���һ�����
                    sigle = linkCartoon(&car_position,node,way,direct,count,energe,x,y);
                    if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			        {
				        break;
			        }
                    //���һ����㵽�յ�
                    if (enddir != 0)
                    {
                        sigle = rentmove(&car_position,node[end].x,node[end].y,placeto.x,placeto.y,x,y,enddir,energe);
                        if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			            {
				            break;
			            }
                    }
                    
                }
                else//�����յ���ͬһ������,ֱ���ó�������ߵ��յ㣬��ʱ����Ѱ·
                {
                    if (placenow.y>placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,1,energe);//������
                    }
                    else if (placenow.y<placeto.y)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,2,energe);//������
                    }
                    else if (placenow.x>placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,3,energe);//������
                    }
                    else if (placenow.x<placeto.x)
                    {
                        sigle = rentmove(&car_position,placenow.x,placenow.y,placeto.x,placeto.y,x,y,4,energe);//������
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
                for ( i = 0; i < count; i++)
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
                fdhz(450,420,1,1,"���������ֵ",44373);
                getch();
                
                printf_image(512-210,384-140,512+210,384+140,"rentnote");
                reset_mouse(x,y);
            }
            
        }
    }
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