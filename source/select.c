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
			// case 2:			//	�����ȫ��ť
			// 		safe_box(x,y);
			// 		break;
            case 3:
                    // infor_box(x,y,user);
                    infor_box(x,y,infor);
                    break;
            case 4:			//	�����ȫ��ť
					car_take_box(x,y,infor);
					break;
            case 5:
					car_rent_box(x,y,infor);
                    // find(x,y,100,465,&energe);
					break;
            case 7:			//	���Back���ص�¼����
					return 0; 
            default:
                    break;
        }
        mouse=0;//����ʼ�ս���ĳһ��case
        
    }

}

