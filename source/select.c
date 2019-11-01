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
//实验
    int energe=100;


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
			case 2:			//	点击安全按钮
					safe_box(x,y);
					break;
            case 3:
                    // infor_box(x,y,user);
                    infor_box(x,y,infor);
                    break;
            case 4:			//	点击安全按钮
					car_take_box(x,y,infor);
					break;
            case 5:
					// car_rent_box(x,y,infor);
                    find(x,y,100,465,&energe);
					break;
            case 7:			//	点击Back返回登录界面
					return 0; 
            default:
                    break;
        }
        mouse=0;//避免始终进入某一个case
        
    }

}


int safe_box(int* x, int* y)
{
    int button=0;
    int mx=0;
    int my=0;
    int sigle = 0;//避免重复报警
   
    mousehide(*x,*y);

    // get_image(512-210,384-140,512+210,384+140,imagesave);
    save_image(512-210,384-140,512+210,384+140,"safe");

    //画图
    bar_round(512,384,416,270,50,1,64384);
    bar_round(512,384,410,265,48,1,65535);

    bar_round(512,350,300,100,45,1,63488);
    rectangle(380,315,644,385,1,65535);
    rectangle(381,316,643,384,1,65535);
    //bar_round(512,384,294,96,43,1,65535);
    outtextxy(385,330,"110",3,3,40,65535);//红色报警标志白色字体
    fdhz(515,330,3,3,"报警",65535);

    bar_round(512,459,120,52,20,1,64384);
    bar_round(512,459,114,47,18,1,65535);
    fdhz(478,445,2,2,"返回",64384);

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
        if(mx>= 362 && mx<=662 && my>=300 && my<=400 && button && sigle!=1)//点击报警
        {

            sigle=1;         //避免重复报警
            bar_round(512,350,300,100,45,1,63488);
            bar_round(512,350,294,95,43,1,65535);
            fdhz(395,330,3,3,"报警成功",63488);

            reset_mouse(x,y);   //避免留下鼠标所在位置的背景
        }
    }

    
    mousehide(*x,*y);  //隐藏鼠标
    printf_image(512-210,384-140,512+210,384+140,"safe");
    
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景
    return sigle;

}

