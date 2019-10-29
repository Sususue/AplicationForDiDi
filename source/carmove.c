#include "common.h"
#include "carmove.h"

/*汽车的最小移动单元*/
int carmove_basic(CAR_CONDITION *car_position,int *x,int *y, int flag)
{
	int button=0;
	int mx=0;
    int my=0;
	int x0 = (*car_position).xpixel,y0 = (*car_position).ypixel;
	int sigle=0;
    
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
	        put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			if (flag==2)
			{
				bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
			}
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
			
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
		    put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			if (flag==2)
			{
				bar((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,65535);
			}
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
			
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

/*输入结构体，执行方向移动(40像素点）*/
int carmove_onestep(CAR_CONDITION *car_position,int *x,int *y, int flag)
{
	int i;
	int mx=0;
	int my=0;
	int button;
	int sigle=0;
	
	switch((*car_position).direction)
	{
		//上和下
		case 1:
		case 2: 
			newxy(x,y,&button);
	        put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
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
	    //左和右
		case 3:
		case 4:
			newxy(x,y,&button);
		    put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
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
	/*调用最小移动单元*/
	// for(i=0;i<20;i++);//这个分号不能少，不然就真的进循环了。这个for语句其实是个废话
	// {
	// 	newxy(x,y,&button);
	// 	mx = *x;
	// 	my = *y;
  
	    sigle=carmove_basic(car_position,x,y,flag);
		if(sigle==1)
		{
			return sigle;
		}
	
	// }
	return sigle;
}

/*************************
画某两点之间的基本运动图像
0:  (130,440)//学校
1:  (212,695)//小区
2： (395,25)//东湖
3:  (370,490)//商场
4:  (686,560)//图书馆
5:  (450,243)//游泳馆
*************************/

/***************************
学校与小区之间的动画
***************************/
int carmove0to1(int *x,int *y)
{
	int sigle=0;
	
	sigle=carmove_left(130,465,55,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(45,475,45,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(55,720,212,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
学校与东湖之间的动画
***************************/
int carmove0to2(int *x,int *y)
{
	int sigle;
	
	
	sigle=carmove_right(130,465,262,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
学校与商场之间的动画
***************************/
int carmove0to3(int * x,int *y)
{
	int sigle=0;
	// bar(130,460,370,470,13926);
	
	sigle=carmove_right(130,465,346,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
学校和图书馆之间的动画
***************************/
int carmove0to4(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(130,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(478,720,705,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
学校与游泳馆之间的动画
***************************/
int carmove0to5(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(130,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,455,468,278,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
小区与学校之间的动画
***************************/
int carmove1to0(int *x,int *y)
{
	int sigle=0;
	// bar(40,460,130,470,13926);
	// bar(40,460,50,725,13926);
	// bar(40,715,212,725,13926);
	
	sigle=carmove_left(212,720,55,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(45,710,45,475,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(55,465,130,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
小区与东湖之间的动画
/**************************/
int carmove1to2(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(267,460,473,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,282,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
小区与商场之间的动画
***************************/
int carmove1to3(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(370,460,473,470,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,370,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
小区与图书馆之间的动画
***************************/
int carmove1to4(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(212,720,705,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
小区与游泳馆之间的动画
***************************/
int carmove1to5(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,263,473,725,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,278,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
东湖与学校之间的动画
***************************/
int carmove2to0(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,277,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(262,465,130,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/************************
东湖与小区之间的动画
*************************/
int carmove2to1(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(267,460,473,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
东湖与商场之间的动画
***************************/
int carmove2to3(int *x,int *y)
{
	int sigle=0;
	// bar(267,460,370,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,465,370,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
东湖与图书馆之间的动画
***************************/
int carmove2to4(int *x,int *y)
{
	int sigle=0;
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,720,273,13926);
	// bar(710,263,720,560,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,258,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,268,710,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(715,278,715,560,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
东湖与游泳馆之间的动画
***************************/
int carmove2to5(int *x,int *y)
{
	int sigle=0;
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,450,273,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	
	sigle=carmove_down(272,35,272,258,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,268,450,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
商场与学校之间的动画
***************************/
int carmove3to0(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,370,470,13926);
	
	sigle=carmove_left(370,465,130,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}
	
/***************************
商场与小区之间的动画
***************************/
int carmove3to1(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(370,460,473,470,13926);
	
	sigle=carmove_right(370,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
商场与东湖之间的动画
***************************/
int carmove3to2(int *x,int *y)
{
	int sigle=0;
	// bar(267,460,370,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(370,465,282,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}


/***************************
商场与图书馆之间的动画
***************************/
int carmove3to4(int *x,int *y)
{
	int sigle=0;
	// bar(370,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(370,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(478,720,705,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***************************
商场与游泳馆之间的动画
***************************/
int carmove3to5(int *x,int *y)
{
	int sigle=0;
	// bar(370,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(370,465,458,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,455,468,278,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
图书馆与学校之间的动画
**************************/
int carmove4to0(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_down(715,560,715,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,478,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,130,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/*************************
图书馆与小区之间的动画
*************************/
int carmove4to1(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,720,725,13926);
	// bar(710,560,720,725,13926);

	sigle=carmove_down(715,560,715,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,212,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
图书馆与东湖之间的动画
**************************/
int carmove4to2(int *x,int *y)
{
	int sigle=0;
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,720,273,13926);
	// bar(710,263,720,560,13926);
	
	sigle=carmove_on(715,560,715,278,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(710,268,282,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,258,272,35,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
图书馆与商场之间的动画
**************************/
int carmove4to3(int *x,int *y)
{
	int sigle=0;
	// bar(370,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_down(715,560,715,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,478,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,370,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
图书馆与游泳馆之间的动画
**************************/
int carmove4to5(int *x,int *y)
{
	int sigle=0;
	// bar(710,263,720,560,13926);
	// bar(450,263,720,273,13926);
	
	sigle=carmove_on(715,560,715,278,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(710,268,450,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/*************************
游泳馆和学校之间的动画
*************************/
int carmove5to0(int *x,int *y)
{
	int sigle=0;
	// bar(130,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,455,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,130,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
游泳馆和小区之间的动画
**************************/
int carmove5to1(int *x,int *y)
{
	int sigle=0;
	// bar(212,715,473,725,13926);
	// bar(463,263,473,725,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,710,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***********************
游泳馆和东湖之间的动画
***********************/
int carmove5to2(int *x,int *y)
{
	int sigle=0;
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,450,273,13926);
	
	sigle=carmove_left(450,268,282,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,258,272,35,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/***********************
游泳馆和商场之间的动画
***********************/
int carmove5to3(int *x,int *y)
{
	int sigle=0;
	// bar(370,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,455,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,370,465,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}

/**************************
游泳馆和图书馆之间的动画
**************************/
int carmove5to4(int *x,int *y)
{
	int sigle=0;
	// bar(710,263,720,560,13926);
	// bar(450,263,720,273,13926);
	
	carmove_right(450,268,710,268,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	carmove_down(715,278,715,560,x,y,2);
	if(sigle==1)
	{
		return sigle;
	}
	return sigle;
}


/**************************
各个小车开到最近点的动画
***************************/
void car_school(int *x,int *y)
{
	carmove_left(240,465,130,465,x,y,1);
}

void car_xiaoqu(int *x,int *y)
{
	carmove_left(310,720,212,720,x,y,1);
}

void car_lake(int *x,int *y)
{
	carmove_right(130,25,360,25,x,y,1);
}

void car_market(int *x,int *y)
{
	carmove_right(240,465,370,465,x,y,1);
}

void car_library(int *x,int *y)
{
	carmove_on(715,680,715,560,x,y,1);
}

void car_pool(int *x,int *y)
{
	carmove_left(590,269,450,268,x,y,1);
}




/*****************************
画路段之间的基本移动图像
*****************************/
int carmove_on(int x1,int y1, int x2, int y2,int *x,int *y, int flag)
{
	int i;
	int j;

	int sigle=0;
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 1;
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
	car_draw_on(car_position);
	
	j=y1-y2;
	
	/*开始动画绘制*/
	for(i=0;i<j;i++)
	{
	    sigle=carmove_onestep(&car_position,x,y,flag);
		if(sigle==1)
		{
			return sigle;
		}
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	
	return sigle;
}

int carmove_down(int x1,int y1, int x2, int y2,int *x,int *y, int flag)
{
	int i;
	int j;

	int sigle=0;
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 2;
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
	car_draw_down(car_position);
	
	j=y2-y1;
	
	/*开始动画绘制*/
	for(i=0;i<j;i++)
	{
        sigle=carmove_onestep(&car_position,x,y,flag);
		if(sigle==1)
		{
			return sigle;
		}
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	
	return sigle;
}

int carmove_left(int x1,int y1, int x2, int y2,int *x,int *y, int flag)
{
	int i;
	int j;
	
	int sigle=0;
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 3;
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
	car_draw_left(car_position);
	
	j=x1-x2;
	
	/*开始动画绘制*/
	for(i=0;i<j;i++)
	{
	    sigle=carmove_onestep(&car_position,x,y,flag);
		if(sigle==1)
		{
			return sigle;
		}
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	
	return sigle;
}

int carmove_right(int x1,int y1, int x2, int y2,int *x,int *y, int flag)
{
	int i;
	int j;
	
	int sigle=0;
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 4;
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
	car_draw_left(car_position);
	
	j=x2-x1;
	
	/*开始动画绘制*/
	for(i=0;i<j;i++)
	{ 
	    sigle=carmove_onestep(&car_position,x,y,flag);
		if(sigle==1)
		{
			return sigle;
		}
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	
	return sigle;
}

 



