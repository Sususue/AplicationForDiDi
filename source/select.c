#include "common.h"
#include "select.h"



/********************************************
��ҳ�����
*********************************************/

int check(USEINFOR *infor,int *x,int *y)
// int check(USER *user,int *x,int *y)
{
    int button=0;
    char mouse=0;		/*������������*/
//ʵ��
    int energe=100;


    mousehide(*x,*y);

    mapdraw();//��ͼ
    select();//�Ҳ�ѡ���
    reset_mouse(x,y);

   
    while(1)
    {
        newxy(x,y,&button);

		mouse = selectbutton(x,y,button);//������������
    
        switch(mouse)
		{
			case 0:
					break;
			case 1:			//	���esc�˳�����
					exit(0);
					break;      
			case 2:			//	�����ȫ��ť
					safe_box(x,y);
					break;
            case 3:
                    // infor_box(x,y,user);
                    infor_box(x,y,infor);
                    break;
            case 4:			//	�����ȫ��ť
					car_take_box(x,y,infor);
					break;
            case 5:
					// car_rent_box(x,y,infor);
                    find(x,y,100,465,&energe);
					break;
            case 7:			//	���Back���ص�¼����
					return 0; 
            default:
                    break;
        }
        mouse=0;//����ʼ�ս���ĳһ��case
        
    }

}


int safe_box(int* x, int* y)
{
    int button=0;
    int mx=0;
    int my=0;
    int sigle = 0;//�����ظ�����
   
    mousehide(*x,*y);

    // get_image(512-210,384-140,512+210,384+140,imagesave);
    save_image(512-210,384-140,512+210,384+140,"safe");

    //��ͼ
    bar_round(512,384,416,270,50,1,64384);
    bar_round(512,384,410,265,48,1,65535);

    bar_round(512,350,300,100,45,1,63488);
    rectangle(380,315,644,385,1,65535);
    rectangle(381,316,643,384,1,65535);
    //bar_round(512,384,294,96,43,1,65535);
    outtextxy(385,330,"110",3,3,40,65535);//��ɫ������־��ɫ����
    fdhz(515,330,3,3,"����",65535);

    bar_round(512,459,120,52,20,1,64384);
    bar_round(512,459,114,47,18,1,65535);
    fdhz(478,445,2,2,"����",64384);

    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>= 452 && mx<=572 && my>=433 && my<=485 && button)
        {
            break;
        }
        if(mx>= 362 && mx<=662 && my>=300 && my<=400 && button && sigle!=1)//�������
        {

            sigle=1;         //�����ظ�����
            bar_round(512,350,300,100,45,1,63488);
            bar_round(512,350,294,95,43,1,65535);
            fdhz(395,330,3,3,"�����ɹ�",63488);

            reset_mouse(x,y);   //���������������λ�õı���
        }
    }

    
    mousehide(*x,*y);  //�������
    printf_image(512-210,384-140,512+210,384+140,"safe");
    
    reset_mouse(x,y);   //���������������λ�õı���
    return sigle;

}

