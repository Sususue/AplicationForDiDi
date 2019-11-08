#include "common.h"
#include "select.h"



/********************************************
主页面控制
*********************************************/

int check(USEINFOR *infor,int *x,int *y)
// int check(USER *user,int *x,int *y)
{
    int button=0;
    char mouse=0;		/*检测鼠标点击区域*/
    
    mousehide(*x,*y);

    mapdraw();//地图
    select();//右侧选择框
    reset_mouse(x,y);

   
    while(1)
    {
        newxy(x,y,&button);

		mouse = selectbutton(x,y,button);//检测鼠标点击区域
    
        switch(mouse)
		{
			case 0:
					break;
			case 1:			//	点击esc退出程序
					exit(0);
					break;      
			// case 2:			//	点击安全按钮
			// 		safe_box(x,y);
			// 		break;
            case 3:
                    // infor_box(x,y,user);
                    infor_box(x,y,infor);
                    break;
            case 4:			//	点击安全按钮
					car_take_box(x,y,infor);
					break;
            case 5:
					car_rent_box(x,y,infor);
                    // find(x,y,100,465,&energe);
					break;
            case 7:			//	点击Back返回登录界面
					return 0; 
            default:
                    break;
        }
        mouse=0;//避免始终进入某一个case
        
    }

}

