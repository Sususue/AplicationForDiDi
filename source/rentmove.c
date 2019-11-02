#include "common.h"
#include "rentmove.h"

/**************************************************************************
功能说明:租车中小车在两点之间移动的动画
         同时显示当前电量和用车时间
参数说明:(x1,y1):起始节点的横纵坐标
         (x2,y2):终止节点的横纵坐标
		 direction:判断小车行驶方向的参数
				   derection==1:上
				   derection==2:下
				   derection==3:左
				   derection==4:右
		 energy：用于显示电量的参数
**************************************************************************/
int rentmove(CAR_CONDITION *car_position, int x1,int y1,int x2,int y2,int *x,int *y,int direction,int *energy, USEINFOR *infor,int* avoid)
{
	int i;
	int j;//用于单位移动循环的变量
	int descent=1;//每走32个像素点，小车减少1%电量
	char menergy[5]="\0";//用于小车电量数字变化
	int sigle=0;
	// int avoid = 0;//避免反复提醒电量过低
	/*初始化小车*/
	// CAR_CONDITION car_position;
	put_image(x1-22,y1-22,x1+22,y1+22,(*car_position).pic);
	/*小车位置初始化*/
	car_position->xpixel = x1;
	car_position->ypixel = y1;
	car_position->direction = direction;
	
	switch(direction)
	{
		case 1:
		case 2:
		j=abs(y1-y2);
		
		// /*分配小车图像空间*/
		// (car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
		// /*检查分配是否成功*/
		// if((car_position).pic==NULL)
		// {
		// 	overflow_box(500,500);//报错
		// 	getch();
		// 	exit(1);
		// }
	
		/*获取小车背景并绘制小车*/
		get_image((car_position)->xpixel-22,(car_position)->ypixel-22,(car_position)->xpixel+22,(car_position)->ypixel+22,(car_position)->pic);
		break;
		
		
		case 3:
		case 4:
		j=abs(x1-x2);
		
		// /*分配小车图像空间*/
		// (car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
		// /*检查分配是否成功*/
		// if((car_position).pic==NULL)
		// {
		// 	overflow_box(500,500);//报错
		// 	getch();
		// 	exit(1);
		// }
	
		/*获取小车背景并绘制小车*/
		get_image((car_position)->xpixel-22,(car_position)->ypixel-22,(car_position)->xpixel+22,(car_position)->ypixel+22,(car_position)->pic);
		break;
	}
	
	/*开始动画绘制*/
	for(i=0;i<j;i++)
	{
	    sigle=rentmove_basic(car_position,x,y);
		if(i%32==0)
		{
			if (*energy > 5)
			{
				*energy=*energy-descent;
			}
			else
			{
				*energy=5;
			}
			bar_round(896,468,190,47,8,1,65535);
			sprintf(menergy,"%d",*energy);
			outtextxy(885,460,menergy,1,1,10,64384);

			judgEnergy(energy,avoid,x,y,infor);
		}
		if(sigle==1)
		{
			return sigle;
		}
	}
	get_image(x2-22,y2-22,x2+22,y2+22,(*car_position).pic);
	//判断方向并画出小车
	(*car_position).xpixel -= 1;
	(*car_position).ypixel -= 1;
	switch((*car_position).direction)
	{
		case 1://上
		{
			
			car_draw_on(*car_position);
			break;
		}
		case 2://下
		{
			car_draw_down(*car_position);
			break;
		}
		case 3://左
		{
			car_draw_left(*car_position);
			break;
		}
		case 4://右
		{
			car_draw_right(*car_position);
			break;
		}
		
	}
	// /*释放分配的内存空间*/
	// free((car_position).pic);

	// /*将指针置空*/
	// (car_position).pic = NULL;
	
	return sigle;
}


/*汽车的最小移动单元*/
int rentmove_basic(CAR_CONDITION *car_position,int *x,int *y)
{
	int button=0;
	int sigle=0;
	int mx=0;
    int my=0;
	int x0 = (*car_position).xpixel,y0 = (*car_position).ypixel;



	//判断方向并移动相应距离
	switch((*car_position).direction)
	{
		case 1://上
		{
			car_draw_on(*car_position);
			y0 = y0-1;
			break;
		}
		case 2://下
		{
			car_draw_down(*car_position);
			y0 = y0+1;
			break;
		}
		case 3://左
		{
			car_draw_left(*car_position);
			x0 = x0-1;
			break;
		}
		case 4://右
		{
			car_draw_right(*car_position);
			x0 = x0+1;
			break;
		}
		
	}
	
	switch((*car_position).direction)
	{
		//左和右 
		case 3:
		case 4: 
		    /*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
			
	        put_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
			{
				sigle=safe_box(x,y);
				
				if(sigle==1)
				{
					return sigle;
				}
			}
			break;
			
		//上和下
		case 1:
		case 2:
		    /*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
			
		    put_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
			{
				sigle=safe_box(x,y);
				
				if(sigle==1)
				{
					return sigle;
				}
			}	
			break;
	}
	return sigle;
}