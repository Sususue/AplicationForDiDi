#include "common.h"
#include "place.h"


#define AIM 1
#define NOW -1
#define UNCHOOSE -1


// void showplace(int place, int mode, const PLACE *location, const char **placename)
void showplace(int place, int mode, const PLACE *location, const char *placename[])
{
    int showx;//ȷ����ʾλ��
    int showy;
    int color;

    if (mode == NOW)
    {   
        showx=905;
        showy=190;
        bar(900,180,990,215,65535);//����ѡ��Ŀ�ĵ�
        color = 9284; //���Ϊ��ɫ
    }
    else if (mode == AIM)
    {
        showx=905;
        showy=280;

        bar_round(896,288,196,52,10,1,64384);
        bar_round(896,288,190,47,8,1,65535);//����ѡ��Ŀ�ĵ�
        fdhz(810,280,1,1,"Ŀ��λ��",64384);
	    outtextxy(885,278,":",1,1,40,64384);
        color = 55463 ; //�յ�Ϊ��ɫ 
    }
    switch (place)
    {
        case 0:
            fdhz(showx,showy,1,1,placename[0],64384);
            markpoint(location[0].x,location[0].y,color,mode);
            break;
        case 1:
            fdhz(showx,showy,1,1,placename[1],64384);
            markpoint(location[1].x,location[1].y,color,mode);
            break;
        case 2:
            fdhz(showx,showy,1,1,placename[2],64384);
            markpoint(location[2].x,location[2].y,color,mode);
            break;
        case 3:
            fdhz(showx,showy,1,1,placename[3],64384);
            markpoint(location[3].x,location[3].y,color,mode);
            break;
        case 4:
            fdhz(showx,showy,1,1,placename[4],64384);
            markpoint(location[4].x,location[4].y,color,mode);
            break;
        case 5:
            fdhz(showx,showy,1,1,placename[5],64384);
            markpoint(location[5].x,location[5].y,color,mode);
            break;
        default:
            break;
    }
}

//�������յ㣬��ͼ
void markpoint(int x, int y, int color, int mode)
{
    linever(x,y-20,x,y-3,1,color);
    linever(x-1,y-20,x-1,y-3,1,color);
    linever(x+1,y-20,x+1,y-3,1,color);
    circle(x,y,4,color);
    circle(x,y,3,color);
    FillCircle(x,y-20,13,color);
    FillCircle(x,y,2,0);
    if (mode == NOW)
    {
        fdhz(x-7,y-27,1,1,"��",65535);
    }
    else 
    {
        fdhz(x-7,y-27,1,1,"��",65535);
    }
}

//ѡ��Ŀ�ĵ�
void choose_aimplace(int *x, int *y, int *aimplace, PLACE *location, USEINFOR *infor, char *placename[])
{
    int button=0;
    int mx=0;
    int my=0;
    int needmoney;//��Ҫ�ļ�Ǯ һ�����ص�5��Ǯ
    
    mousehide(*x,*y);
    
    //  �ڸ�
    switch (*aimplace)
    {
        case 0:
            printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
            break;
        case 1:
            printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
            break;
        case 2:
            printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
            break;
        case 3:
            printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
        case 4:
            printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
            break;
        case 5:
            printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
            break;
        default:
            break;
    }

    starttoendroad(infor->nowplace,*aimplace,65535);

    *aimplace =UNCHOOSE;
    //��ʾ���³���
    FillCircle(location[0].x,location[0].y,3,0);//����
    FillCircle(location[1].x,location[1].y,3,0);//С��
    FillCircle(location[2].x,location[2].y,3,0);//ѧУ
    FillCircle(location[3].x,location[3].y,3,0);//�̳�
    FillCircle(location[4].x,location[4].y,3,0);//ͼ���
    FillCircle(location[5].x,location[5].y,3,0);//��Ӿ��
    // ���֮ǰ��Ŀ�ĵ���Ϣ
    bar_round(896,288,196,52,10,1,44373);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"ѡ",44373);
    fdhz(855,280,1,1,"��",44373);
    fdhz(890,280,1,1,"Ŀ",44373);
    fdhz(925,280,1,1,"��",44373);
	fdhz(960,280,1,1,"��",44373);
    //���֮ǰ�ļ۸���Ϣ
    bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(810,370,1,1,"Ԥ�Ƽ۸�",64384);
	fdhz(970,370,1,1,"Ԫ",64384);
	outtextxy(885,368,":",1,1,40,64384);

    //��ʾ���
    reset_mouse(x,y);

    while(1)
    {   
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if (mx>=location[0].x-3  && mx<=location[0].x+3 && my>=location[0].y-3 && my<=location[0].y+3 && button)
        {
            if (infor->nowplace==0)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 0;
            mousehide(*x,*y);
            //�Ե�ͼ��ԭ�е�С�������ڵ�
	
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            
            break;
        }
        else if (mx>=location[1].x-4  && mx<=location[1].x+4 && my>=location[1].y-4 && my<=location[1].y+4 && button)
        {
            if (infor->nowplace==1)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 1;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[2].x-4  && mx<=location[2].x+4 && my>=location[2].y-4 && my<=location[2].y+4 && button)
        {
            if (infor->nowplace==2)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 2;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[3].x-4  && mx<=location[3].x+4 && my>=location[3].y-4 && my<=location[3].y+4 && button)
        {
            if (infor->nowplace==3)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 3;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[4].x-4  && mx<=location[4].x+4 && my>=location[4].y-4 && my<=location[4].y+4 && button)
        {
            if (infor->nowplace==4)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 4;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[5].x-4  && mx<=location[5].x+4 && my>=location[5].y-4 && my<=location[5].y+4 && button)
        {
            if (infor->nowplace==5)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 5;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
        {
            safe_box(x,y);
        }
        else if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            mousehide(*x,*y);
            bar_round(896,288,196,52,10,1,64384);
            bar_round(896,288,190,47,8,1,65535);
            fdhz(820,280,1,1,"ѡ",64384);
            fdhz(855,280,1,1,"��",64384);
            fdhz(890,280,1,1,"Ŀ",64384);
            fdhz(925,280,1,1,"��",64384);
            fdhz(960,280,1,1,"��",64384);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
    }
    
}

//ѡ��Ŀ�ĵغ���ʾ��ɫ����//13926��ɫ//��ɫ65535
void starttoendroad(int nowplace,int aimplace,int color)
{
    switch (nowplace)
    {
        case 0:
                switch (aimplace)
                {
                    case 1:
                            bar(40,460,130,470,color);
	                        bar(40,460,50,725,color);
	                        bar(40,715,212,725,color);
                            break;
                    case 2:
                            bar(130,460,277,470,color);
	                        bar(267,20,277,470,color);
	                        bar(267,20,380,30,color);
                            break;
                    case 3:
                            bar(130,460,357,470,color);
            
                            break;
                    case 4:
                            bar(130,460,473,470,color);
	                        bar(463,460,473,725,color);
	                        bar(463,715,720,725,color);
	                        bar(710,560,720,725,color);
	
                            break;
                    case 5:
                            bar(130,460,473,470,color);
	                        bar(463,263,473,470,color);
	                        bar(450,263,473,273,color);
            
                            break;

                    default:
                            break;
                }
                break;
        case 1:
                switch (aimplace)
                {
                    case 0:
                            bar(40,460,130,470,color);
                            bar(40,460,50,725,color);
                            bar(40,715,212,725,color);
                            break;
                    case 2:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(267,460,473,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
	
                            break;
                    case 3:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(383,460,473,470,color);
                            break;
                    case 4:
                            bar(212,715,720,725,color);
	                        bar(710,560,720,725,color);
            
                            break;
                    case 5:
                            bar(212,715,473,725,color);
                            bar(463,263,473,725,color);
                            bar(450,263,473,273,color);
            
                            break;

                    default:
                            break;
                }
                break;
        case 2:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,277,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(267,460,473,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
                            break;
                    case 3:
                            bar(267,460,357,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
            
                            break;
                    case 4:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,720,273,color);
                            bar(710,263,720,560,color);
            
                            break;
                    case 5:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,450,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 3:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,357,470,color);
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(383,460,473,470,color);
            
                            break;
                    case 2:
                            bar(267,460,357,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
            
                            break;
                    case 4:
                            bar(383,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
                            break;
                    case 5:
                            bar(383,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 4:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
                            break;
                    case 1:
                            bar(212,715,720,725,color);
                            bar(710,560,720,725,color);
            
                            break;
                    case 2:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,720,273,color);
                            bar(710,263,720,560,color);
            
                            break;
                    case 3:
                            bar(383,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
            
                            break;
                    case 5:
                            bar(710,263,720,560,color);
	                        bar(450,263,720,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 5:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
	
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,263,473,725,color);
                            bar(450,263,473,273,color);
                            break;
                    case 2:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,450,273,color);
            
                            break;
                    case 3:
                            bar(383,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
            
                            break;
                    case 4:
                            bar(710,263,720,560,color);
	                        bar(450,263,720,273,color);
                            break;

                    default:
                            break;
                }
                break;
        default:
                break;
    }
}

//���㲢��ʾ����֮��ļ۸�
void showprice(int nowplace,int *aimplace)
{
	// int pointlength[15];//����֮����̷�����
	float pointprice;//����֮��۸�
	int showx=905;//ȷ����ʾλ��
    int showy=370;
    int color;
	int timegap=0;
	int timecase=0;

	
	char pricing[10]="\0";//���ڼ۸���������ת��
	
	
	countprice(&pointprice,nowplace,aimplace,timegap,timecase);
	sprintf(pricing,"%.2f",pointprice);
	outtextxy(showx,showy,pricing,1,1,10,64384);
	
}