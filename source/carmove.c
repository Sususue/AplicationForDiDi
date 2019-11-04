// #include "common.h"
// #include "carmove.h"

// /*汽车的最小移动单元*/
// int carmove_basic(CAR_CONDITION *car_position,int *x,int *y, int flag)
// {
// 	int button=0;
// 	int mx=0;
//     int my=0;
// 	int x0 = (*car_position).xpixel,y0 = (*car_position).ypixel;
// 	int sigle=0;
// 	//char mprogress[8]="\0";//用于进度条数字变化
	
    
// 	//判断方向并移动相应距离
// 	switch((*car_position).direction)
// 	{
// 		case 1://上
// 		{
// 			car_draw_on(*car_position);
// 			y0 = y0-1;
// 			break;
// 		}
// 		case 2://下
// 		{
// 			car_draw_down(*car_position);
// 			y0 = y0+1;
// 			break;
// 		}
// 		case 3://左
// 		{
// 			car_draw_left(*car_position);
// 			x0 = x0-1;
// 			break;
// 		}
// 		case 4://右
// 		{
// 			car_draw_right(*car_position);
// 			x0 = x0+1;
// 			break;
// 		}
		
// 	}
	
// 	switch((*car_position).direction)
// 	{
// 		//左和右 
// 		case 3:
// 		case 4: 
// 		    /*保持图像*/
// 	        delay0(50);
// 	        newxy(x,y,&button);
// 	        put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
// 			if (flag==2)
// 			{
// 				bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
// 				//sprintf(mprogress,"%.2f",*progress);
// 				//outtextxy(850,548,mprogress,1,1,15,64384);
// 				//bar_round(896,558,190,47,8,1,65535);
// 			}
// 			(*car_position).xpixel = x0;
// 	        (*car_position).ypixel = y0;
// 	        get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
			
// 			mx = *x;
// 			my = *y;
       
// 			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
// 			{
// 				sigle=safe_box(x,y);
				
// 				if(sigle==1)
// 				{
// 					return sigle;
// 				}
// 			}
// 			break;
			
// 		//上和下
// 		case 1:
// 		case 2:
// 		    /*保持图像*/
// 	        delay0(50);
// 	        newxy(x,y,&button);
// 		    put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
// 			if (flag==2)
// 			{
// 				bar((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,65535);
// 				//sprintf(mprogress,"%.2f",* progress);
// 				//outtextxy(850,548,mprogress,1,1,15,64384);
// 				//bar_round(896,558,190,47,8,1,65535);
// 			}
// 			(*car_position).xpixel = x0;
// 	        (*car_position).ypixel = y0;
// 	        get_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
			
// 			mx = *x;
// 			my = *y;
       
// 			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
// 			{
// 				sigle=safe_box(x,y);
				
// 				if(sigle==1)
// 				{
// 					return sigle;
// 				}
// 			}	
// 			break;
// 	}
// 	return sigle;
	
    
		    
// }

// /*输入结构体，执行方向移动(40像素点）*/
// /*int carmove_onestep(CAR_CONDITION *car_position,int *x,int *y, int flag,float progress)
// {
// 	int i;
// 	int mx=0;
// 	int my=0;
// 	int button;
// 	int sigle=0;
// 	float acsend=progress;//用于数字增长
// 	char mprogress[8]="\0";//用于进度条数字变化
	
// 	switch((*car_position).direction)
// 	{
// 		//上和下
// 		case 1:
// 		case 2: 
// 			newxy(x,y,&button);
// 	        put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
// 			mx = *x;
// 			my = *y;
       
// 			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
// 			{
// 				sigle=safe_box(x,y);
				
// 				if(sigle==1)
// 				{
// 					return sigle;
// 				}
// 			}	
// 			break;
// 	    //左和右
// 		case 3:
// 		case 4:
// 			newxy(x,y,&button);
// 		    put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
// 			mx = *x;
// 			my = *y;
       
// 			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
// 			{
// 				sigle=safe_box(x,y);
				
// 				if(sigle==1)
// 				{
// 					return sigle;
// 				}
// 			}	
// 			break;
// 	}
// 	/*调用最小移动单元
// 	//for(i=0;i<20;i++)
// 	//{
// 		//newxy(x,y,&button);
// 		//mx = *x;
// 		//my = *y;
  
// 	    sigle=carmove_basic(car_position,x,y,flag);
		
// 		if(flag==2)
// 		{
// 			sprintf(mprogress,"%.2f",progress);
// 			outtextxy(850,548,mprogress,1,1,15,64384);
// 			progress+=acsend;
// 		}
		
// 		if(sigle==1)
// 		{
// 			return sigle;
// 		}
	
// 	//}
// 	return sigle;
// }*/

// /*************************
// 画某两点之间的基本运动图像
// 0:  (130,440)//学校
// 1:  (212,695)//小区
// 2： (395,25)//东湖
// 3:  (370,490)//商场
// 4:  (686,560)//图书馆
// 5:  (450,243)//游泳馆
// *************************/


// /***************************
// 学校与小区之间的动画
// ***************************/
// int carmove0to1(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=467;//两点之间的距离
// 	float prog=100.0/467;//用于进度条填充计算
// 	float pprog=100.0/467;//用于传入在某两点之间不变的值acsend
	
// 	sigle=carmove_left(130,465,55,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(45,475,45,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(55,720,212,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 学校与东湖之间的动画
// ***************************/
// int carmove0to2(int *x,int *y)
// {
// 	int sigle;
// 	//int distance=630;//两点之间的距离
// 	float prog=100.0/630;//用于进度条填充计算
// 	float pprog=100.0/630;//用于传入在某两点之间不变的值acsend
	
// 	sigle=carmove_right(130,465,262,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 学校与商场之间的动画
// ***************************/
// int carmove0to3(int * x,int *y)
// {
// 	int sigle=0;
// 	//int distance=206;//两点之间的距离
// 	float prog=100.0/206;//用于进度条填充计算
// 	float pprog=100.0/206;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,370,470,13926);
	
// 	sigle=carmove_right(130,465,336,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 学校和图书馆之间的动画
// ***************************/
// int carmove0to4(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=940;//两点之间的距离
// 	float prog=100.0/940;//用于进度条填充计算
// 	float pprog=100.0/940;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,473,470,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(463,715,720,725,13926);
// 	// bar(710,560,720,725,13926);
	
// 	sigle=carmove_right(130,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(478,720,705,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 学校与游泳馆之间的动画
// ***************************/
// int carmove0to5(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=513;//两点之间的距离
// 	float prog=100.0/513;//用于进度条填充计算
// 	float pprog=100.0/513;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,473,470,13926);
// 	// bar(463,263,473,470,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(130,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,455,468,278,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 小区与学校之间的动画
// ***************************/
// int carmove1to0(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=467;//两点之间的距离
// 	float prog=100.0/467;//用于进度条填充计算
// 	float pprog=100.0/467;//用于传入在某两点之间不变的值acsend
// 	// bar(40,460,130,470,13926);
// 	// bar(40,460,50,725,13926);
// 	// bar(40,715,212,725,13926);
	
// 	sigle=carmove_left(212,720,55,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(45,710,45,475,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(55,465,130,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 小区与东湖之间的动画
// /**************************/
// int carmove1to2(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=1155;//两点之间的距离
// 	float prog=100.0/1155;//用于进度条填充计算
// 	float pprog=100.0/1155;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(267,460,473,470,13926);
// 	// bar(267,20,277,470,13926);
// 	// bar(267,20,380,30,13926);
	
// 	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,282,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 小区与商场之间的动画
// ***************************/
// int carmove1to3(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=536;//两点之间的距离
// 	float prog=100.0/536;//用于进度条填充计算
// 	float pprog=100.0/536;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(370,460,473,470,13926);
	
// 	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 小区与图书馆之间的动画
// ***************************/
// int carmove1to4(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=643;//两点之间的距离
// 	float prog=100.0/643;//用于进度条填充计算
// 	float pprog=100.0/643;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,720,725,13926);
// 	// bar(710,560,720,725,13926);
	
// 	sigle=carmove_right(212,720,705,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 小区与游泳馆之间的动画
// ***************************/
// int carmove1to5(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=686;//两点之间的距离
// 	float prog=100.0/686;//用于进度条填充计算
// 	float pprog=100.0/686;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,263,473,725,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,710,468,278,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 东湖与学校之间的动画
// ***************************/
// int carmove2to0(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=630;//两点之间的距离
// 	float prog=100.0/630;//用于进度条填充计算
// 	float pprog=100.0/630;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,277,470,13926);
// 	// bar(267,20,277,470,13926);
// 	// bar(267,20,380,30,13926);
	
// 	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(262,465,130,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /************************
// 东湖与小区之间的动画
// *************************/
// int carmove2to1(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=1155;//两点之间的距离
// 	float prog=100.0/1155;//用于进度条填充计算
// 	float pprog=100.0/1155;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(267,460,473,470,13926);
// 	// bar(267,20,277,470,13926);
// 	// bar(267,20,380,30,13926);
	
// 	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 东湖与商场之间的动画
// ***************************/
// int carmove2to3(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=552;//两点之间的距离
// 	float prog=100.0/552;//用于进度条填充计算
// 	float pprog=100.0/552;//用于传入在某两点之间不变的值acsend
// 	// bar(267,460,370,470,13926);
// 	// bar(267,20,277,470,13926);
// 	// bar(267,20,380,30,13926);
	
// 	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,465,336,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 东湖与图书馆之间的动画
// ***************************/
// int carmove2to4(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=1011;//两点之间的距离
// 	float prog=100.0/1011;//用于进度条填充计算
// 	float pprog=100.0/1011;//用于传入在某两点之间不变的值acsend
// 	// bar(267,20,380,30,13926);
// 	// bar(267,20,277,273,13926);
// 	// bar(267,263,720,273,13926);
// 	// bar(710,263,720,560,13926);
	
// 	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(272,35,272,258,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,268,710,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(715,278,715,560,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 东湖与游泳馆之间的动画
// ***************************/
// int carmove2to5(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=468;//两点之间的距离
// 	float prog=100.0/468;//用于进度条填充计算
// 	float pprog=100.0/468;//用于传入在某两点之间不变的值acsend
// 	// bar(267,20,380,30,13926);
// 	// bar(267,20,277,273,13926);
// 	// bar(267,263,450,273,13926);
	
// 	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
	
// 	sigle=carmove_down(272,35,272,258,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,268,450,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 商场与学校之间的动画
// ***************************/
// int carmove3to0(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=206;//两点之间的距离
// 	float prog=100.0/206;//用于进度条填充计算
// 	float pprog=100.0/206;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,370,470,13926);
	
// 	sigle=carmove_left(335,465,130,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }
	
// /***************************
// 商场与小区之间的动画
// ***************************/
// int carmove3to1(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=536;//两点之间的距离
// 	float prog=100.0/536;//用于进度条填充计算
// 	float pprog=100.0/536;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(370,460,473,470,13926);
	
// 	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 商场与东湖之间的动画
// ***************************/
// int carmove3to2(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=552;//两点之间的距离
// 	float prog=100.0/552;//用于进度条填充计算
// 	float pprog=100.0/552;//用于传入在某两点之间不变的值acsend
// 	// bar(267,460,370,470,13926);
// 	// bar(267,20,277,470,13926);
// 	// bar(267,20,380,30,13926);
	
// 	sigle=carmove_left(335,465,282,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }


// /***************************
// 商场与图书馆之间的动画
// ***************************/
// int carmove3to4(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=666;//两点之间的距离
// 	float prog=100.0/666;//用于进度条填充计算
// 	float pprog=100.0/666;//用于传入在某两点之间不变的值acsend
// 	// bar(370,460,473,470,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(463,715,720,725,13926);
// 	// bar(710,560,720,725,13926);
	
// 	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(478,720,705,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***************************
// 商场与游泳馆之间的动画
// ***************************/
// int carmove3to5(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=238;//两点之间的距离
// 	float prog=100.0/238;//用于进度条填充计算
// 	float pprog=100.0/238;//用于传入在某两点之间不变的值acsend
// 	// bar(370,460,473,470,13926);
// 	// bar(463,263,473,470,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,455,468,278,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 图书馆与学校之间的动画
// **************************/
// int carmove4to0(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=940;//两点之间的距离
// 	float prog=100.0/940;//用于进度条填充计算
// 	float pprog=100.0/940;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,473,470,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(463,715,720,725,13926);
// 	// bar(710,560,720,725,13926);
	
// 	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(705,720,478,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,130,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /*************************
// 图书馆与小区之间的动画
// *************************/
// int carmove4to1(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=643;//两点之间的距离
// 	float prog=100.0/643;//用于进度条填充计算
// 	float pprog=100.0/643;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,720,725,13926);
// 	// bar(710,560,720,725,13926);

// 	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(705,720,212,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 图书馆与东湖之间的动画
// **************************/
// int carmove4to2(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=1011;//两点之间的距离
// 	float prog=100.0/1011;//用于进度条填充计算
// 	float pprog=100.0/1011;//用于传入在某两点之间不变的值acsend
// 	// bar(267,20,380,30,13926);
// 	// bar(267,20,277,273,13926);
// 	// bar(267,263,720,273,13926);
// 	// bar(710,263,720,560,13926);
	
// 	sigle=carmove_on(715,560,715,278,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(710,268,282,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(272,258,272,35,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 图书馆与商场之间的动画
// **************************/
// int carmove4to3(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=666;//两点之间的距离
// 	float prog=100.0/666;//用于进度条填充计算
// 	float pprog=100.0/666;//用于传入在某两点之间不变的值acsend
// 	// bar(370,460,473,470,13926);
// 	// bar(463,460,473,725,13926);
// 	// bar(463,715,720,725,13926);
// 	// bar(710,560,720,725,13926);
	
// 	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(705,720,478,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 图书馆与游泳馆之间的动画
// **************************/
// int carmove4to5(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=542;//两点之间的距离
// 	float prog=100.0/542;//用于进度条填充计算
// 	float pprog=100.0/542;//用于传入在某两点之间不变的值acsend
// 	// bar(710,263,720,560,13926);
// 	// bar(450,263,720,273,13926);
	
// 	sigle=carmove_on(715,560,715,278,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(710,268,450,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /*************************
// 游泳馆和学校之间的动画
// *************************/
// int carmove5to0(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=513;//两点之间的距离
// 	float prog=100.0/513;//用于进度条填充计算
// 	float pprog=100.0/513;//用于传入在某两点之间不变的值acsend
// 	// bar(130,460,473,470,13926);
// 	// bar(463,263,473,470,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,278,468,455,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,130,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 游泳馆和小区之间的动画
// **************************/
// int carmove5to1(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=686;//两点之间的距离
// 	float prog=100.0/686;//用于进度条填充计算
// 	float pprog=100.0/686;//用于传入在某两点之间不变的值acsend
// 	// bar(212,715,473,725,13926);
// 	// bar(463,263,473,725,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,278,468,710,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***********************
// 游泳馆和东湖之间的动画
// ***********************/
// int carmove5to2(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=468;//两点之间的距离
// 	float prog=100.0/468;//用于进度条填充计算
// 	float pprog=100.0/468;//用于传入在某两点之间不变的值acsend
// 	// bar(267,20,380,30,13926);
// 	// bar(267,20,277,273,13926);
// 	// bar(267,263,450,273,13926);
	
// 	sigle=carmove_left(450,268,282,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_on(272,258,272,35,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /***********************
// 游泳馆和商场之间的动画
// ***********************/
// int carmove5to3(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=238;//两点之间的距离
// 	float prog=100.0/238;//用于进度条填充计算
// 	float pprog=100.0/238;//用于传入在某两点之间不变的值acsend
// 	// bar(370,460,473,470,13926);
// 	// bar(463,263,473,470,13926);
// 	// bar(450,263,473,273,13926);
	
// 	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(468,278,468,455,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }

// /**************************
// 游泳馆和图书馆之间的动画
// **************************/
// int carmove5to4(int *x,int *y)
// {
// 	int sigle=0;
// 	//int distance=542;//两点之间的距离
// 	float prog=100.0/542;//用于进度条填充计算
// 	float pprog=100.0/542;//用于传入在某两点之间不变的值acsend
// 	// bar(710,263,720,560,13926);
// 	// bar(450,263,720,273,13926);
	
// 	sigle=carmove_right(450,268,710,268,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	sigle=carmove_down(715,278,715,560,x,y,2,&prog,pprog);
// 	if(sigle==1)
// 	{
// 		return sigle;
// 	}
// 	bar_round(910,558,70,47,8,1,65535);
// 	outtextxy(885,550,"100.00",1,1,10,64384);
// 	return sigle;
// }


// /**************************
// 各个小车开到最近点的动画
// ***************************/
// void car_school(int *x,int *y)
// {
// 	carmove_left(240,465,130,465,x,y,1,0,0);
// }

// void car_xiaoqu(int *x,int *y)
// {
// 	carmove_left(310,720,212,720,x,y,1,0,0);
// }

// void car_lake(int *x,int *y)
// {
// 	carmove_right(130,25,360,25,x,y,1,0,0);
// }

// void car_market(int *x,int *y)
// {
// 	carmove_right(240,465,370,465,x,y,1,0,0);
// }

// void car_library(int *x,int *y)
// {
// 	carmove_on(715,680,715,560,x,y,1,0,0);
// }

// void car_pool(int *x,int *y)
// {
// 	carmove_left(590,269,450,268,x,y,1,0,0);
// }




// /*****************************
// 画路段之间的基本移动图像
// *****************************/
// int carmove_on(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
// {
// 	int i;
// 	int j;
// 	//float acsend=*progress;//用于数字增长
// 	int sigle=0;
// 	char mprogress[8]="\0";//用于进度条数字变化
	
// 	/*初始化小车*/
// 	CAR_CONDITION car_position;
	
// 	/*小车位置初始化*/
// 	car_position.xpixel = x1;
// 	car_position.ypixel = y1;
// 	car_position.direction = 1;
	
// 	/*分配小车图像空间*/
// 	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
// 	/*检查分配是否成功*/
// 	if((car_position).pic==NULL)
// 	{
// 		overflow_box(500,500);//报错
// 		getch();
// 		exit(1);
// 	}
	
// 	/*获取小车背景并绘制小车*/
// 	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
// 	car_draw_on(car_position);
	
// 	j=y1-y2;
	
// 	/*开始动画绘制*/
// 	for(i=0;i<j;i++)
// 	{
// 	    sigle=carmove_basic(&car_position,x,y,flag);
// 		*progress=*progress+acsend;
// 		if(flag==2&&i%5==0)
// 		{
// 			bar_round(910,558,70,47,8,1,65535);
// 			sprintf(mprogress,"%.2f",*progress);
// 			outtextxy(885,550,mprogress,1,1,10,64384);
			
// 		}
// 		if(sigle==1)
// 		{
// 			return sigle;
// 		}
// 	}
	
// 	/*释放分配的内存空间*/
// 	free((car_position).pic);

// 	/*将指针置空*/
// 	(car_position).pic = NULL;
	
// 	return sigle;
// }

// int carmove_down(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
// {
// 	int i;
// 	int j;
// 	//float acsend=*progress;//用于数字增长
// 	int sigle=0;
// 	char mprogress[8]="\0";//用于进度条数字变化
	
// 	/*初始化小车*/
// 	CAR_CONDITION car_position;
	
// 	/*小车位置初始化*/
// 	car_position.xpixel = x1;
// 	car_position.ypixel = y1;
// 	car_position.direction = 2;
	
// 	/*分配小车图像空间*/
// 	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
// 	/*检查分配是否成功*/
// 	if((car_position).pic==NULL)
// 	{
// 		overflow_box(500,500);//报错
// 		getch();
// 		exit(1);
// 	}
	
// 	/*获取小车背景并绘制小车*/
// 	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
// 	car_draw_down(car_position);
	
// 	j=y2-y1;
	
// 	/*开始动画绘制*/
// 	for(i=0;i<j;i++)
// 	{
//         sigle=carmove_basic(&car_position,x,y,flag);
// 		*progress+=acsend;
// 		if(flag==2&&i%5==0)
// 		{
// 			bar_round(910,558,70,47,8,1,65535);
// 			sprintf(mprogress,"%.2f",*progress);
// 			outtextxy(885,550,mprogress,1,1,10,64384);
			
// 		}
// 		if(sigle==1)
// 		{
// 			return sigle;
// 		}
// 	}
	
// 	/*释放分配的内存空间*/
// 	free((car_position).pic);

// 	/*将指针置空*/
// 	(car_position).pic = NULL;
	
// 	return sigle;
// }

// int carmove_left(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
// {
// 	int i;
// 	int j;
// 	//float acsend=*progress;//用于数字增长
// 	int sigle=0;
// 	char mprogress[8]="\0";//用于进度条数字变化
	
// 	/*初始化小车*/
// 	CAR_CONDITION car_position;
	
// 	/*小车位置初始化*/
// 	car_position.xpixel = x1;
// 	car_position.ypixel = y1;
// 	car_position.direction = 3;
	
// 	/*分配小车图像空间*/
// 	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
// 	/*检查分配是否成功*/
// 	if((car_position).pic==NULL)
// 	{
// 		overflow_box(500,500);//报错
// 		getch();
// 		exit(1);
// 	}
	
// 	/*获取小车背景并绘制小车*/
// 	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
// 	car_draw_left(car_position);
	
// 	j=x1-x2;
	
// 	/*开始动画绘制*/
// 	for(i=0;i<j;i++)
// 	{
// 	    sigle=carmove_basic(&car_position,x,y,flag);
// 		*progress+=acsend;
// 		if(flag==2&&i%5==0)
// 		{
// 			bar_round(910,558,70,47,8,1,65535);
// 			sprintf(mprogress,"%.2f",*progress);
// 			outtextxy(885,550,mprogress,1,1,10,64384);
			
// 		}
// 		if(sigle==1)
// 		{
// 			return sigle;
// 		}
// 	}
	
// 	/*释放分配的内存空间*/
// 	free((car_position).pic);

// 	/*将指针置空*/
// 	(car_position).pic = NULL;
	
// 	return sigle;
// }

// int carmove_right(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
// {
// 	int i;
// 	int j;
// 	//float acsend=*progress;//用于数字增长
// 	int sigle=0;
// 	char mprogress[8]="\0";//用于进度条数字变化
	
// 	/*初始化小车*/
// 	CAR_CONDITION car_position;
	
// 	/*小车位置初始化*/
// 	car_position.xpixel = x1;
// 	car_position.ypixel = y1;
// 	car_position.direction = 4;
	
// 	/*分配小车图像空间*/
// 	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
// 	/*检查分配是否成功*/
// 	if((car_position).pic==NULL)
// 	{
// 		overflow_box(500,500);//报错
// 		getch();
// 		exit(1);
// 	}
	
// 	/*获取小车背景并绘制小车*/
// 	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
// 	car_draw_left(car_position);
	
// 	j=x2-x1;
	
// 	/*开始动画绘制*/
// 	for(i=0;i<j;i++)
// 	{ 
// 	    sigle=carmove_basic(&car_position,x,y,flag);
// 		*progress+=acsend;
// 		if(flag==2&&i%5==0)
// 		{
// 			bar_round(910,558,70,47,8,1,65535);
// 			sprintf(mprogress,"%.2f",*progress);
// 			outtextxy(885,550,mprogress,1,1,10,64384);
			
// 		}
// 		if(sigle==1)
// 		{
// 			return sigle;
// 		}
// 	}
	
// 	/*释放分配的内存空间*/
// 	free((car_position).pic);

// 	/*将指针置空*/
// 	(car_position).pic = NULL;
	
// 	return sigle;
// }

 


#include "common.h"
#include "carmove.h"

/*汽车的最小移动单元*/
void carmove_basic(CAR_CONDITION *car_position,int *x,int *y, int flag,int *sig)
{
	int button=0;
	int mx=0;
    int my=0;
	//int x0 = (*car_position).xpixel,y0 = (*car_position).ypixel;
	//char mprogress[8]="\0";//用于进度条数字变化
	
    
	
	
	switch((*car_position).direction)
	{
		//左和右 
		case 3:
			/*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
	        //put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			//if (flag==2)
			//{
			//	bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
				
			//}
			//(*car_position).xpixel = x0;
	        //(*car_position).ypixel = y0;
	        //get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
			if (flag==2)
			{
				bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
				(*car_position).xpixel -= 1;
				//(*car_position).ypixel += 1;
			}
			else
			{
				put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
				(*car_position).xpixel -=1 ;
				//(*car_position).ypixel +=1 ;
				get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			}
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button && flag==2)//点击安全，弹出信息框
			{
				safe_box(x,y,sig);
				
				/*if(sigle==1)
				{
					return sigle;
				}*/
			}
			break;
		case 4: 
		    /*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
	        //put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			//if (flag==2)
			//{
			//	bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
				
			//}
			//(*car_position).xpixel = x0;
	        //(*car_position).ypixel = y0;
	        //get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			
			if (flag==2)
			{
				bar((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,65535);
				(*car_position).xpixel += 1;
				//(*car_position).ypixel += 1;
			}
			else
			{
				put_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
				(*car_position).xpixel +=1 ;
				//(*car_position).ypixel +=1 ;
				get_image((*car_position).xpixel-21,(*car_position).ypixel-11,(*car_position).xpixel+22,(*car_position).ypixel+12,(*car_position).pic);
			}
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
			{
				safe_box(x,y,sig);
				
				/*if(sigle==1)
				{
					return sigle;
				}*/
			}
			break;
			
		//上和下
		case 1:
			/*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
		    put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			if (flag==2)
			{
				bar((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,65535);
				//sprintf(mprogress,"%.2f",* progress);
				//outtextxy(850,548,mprogress,1,1,15,64384);
				//bar_round(896,558,190,47,8,1,65535);
			}
			//(*car_position).xpixel +=1;
	        (*car_position).ypixel -=1;
	        get_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
			{
				safe_box(x,y,sig);
				
				/*if(sigle==1)
				{
					return sigle;
				}*/
			}	
			break;
		case 2:
		    /*保持图像*/
	        delay0(50);
	        newxy(x,y,&button);
		    put_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			if (flag==2)
			{
				bar((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,65535);
				//sprintf(mprogress,"%.2f",* progress);
				//outtextxy(850,548,mprogress,1,1,15,64384);
				//bar_round(896,558,190,47,8,1,65535);
			}
			//(*car_position).xpixel +=1;
	        (*car_position).ypixel +=1;
	        get_image((*car_position).xpixel-11,(*car_position).ypixel-21,(*car_position).xpixel+12,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
			{
				safe_box(x,y,sig);
				
				/*if(sigle==1)
				{
					return sigle;
				}*/
			}	
			break;
	}
	//return sigle;
	//判断方向并移动相应距离
	switch((*car_position).direction)
	{
		case 1://上
		{
			car_draw_on(*car_position);
			//y0 = y0-1;
			break;
		}
		case 2://下
		{
			car_draw_down(*car_position);
			//y0 = y0+1;
			break;
		}
		case 3://左
		{
			car_draw_left(*car_position);
			//x0 = x0-1;
			break;
		}
		case 4://右
		{
			car_draw_right(*car_position);
			//x0 = x0+1;
			break;
		}
		
	}
    
		    
}

/*输入结构体，执行方向移动(40像素点）*/
/*int carmove_onestep(CAR_CONDITION *car_position,int *x,int *y, int flag,float progress)
{
	int i;
	int mx=0;
	int my=0;
	int button;
	int sigle=0;
	float acsend=progress;//用于数字增长
	char mprogress[8]="\0";//用于进度条数字变化
	
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
	/*调用最小移动单元
	//for(i=0;i<20;i++)
	//{
		//newxy(x,y,&button);
		//mx = *x;
		//my = *y;
  
	    sigle=carmove_basic(car_position,x,y,flag);
		
		if(flag==2)
		{
			sprintf(mprogress,"%.2f",progress);
			outtextxy(850,548,mprogress,1,1,15,64384);
			progress+=acsend;
		}
		
		if(sigle==1)
		{
			return sigle;
		}
	
	//}
	return sigle;
}*/

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
	//int distance=467;//两点之间的距离
	float prog=100.0/467;//用于进度条填充计算
	float pprog=100.0/467;//用于传入在某两点之间不变的值acsend
	
	sigle=carmove_left(130,465,55,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(45,475,45,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(55,720,212,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
学校与东湖之间的动画
***************************/
int carmove0to2(int *x,int *y)
{
	int sigle;
	//int distance=630;//两点之间的距离
	float prog=100.0/630;//用于进度条填充计算
	float pprog=100.0/630;//用于传入在某两点之间不变的值acsend
	
	sigle=carmove_right(130,465,262,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
学校与商场之间的动画
***************************/
int carmove0to3(int * x,int *y)
{
	int sigle=0;
	//int distance=206;//两点之间的距离
	float prog=100.0/206;//用于进度条填充计算
	float pprog=100.0/206;//用于传入在某两点之间不变的值acsend
	// bar(130,460,370,470,13926);
	
	sigle=carmove_right(130,465,336,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
学校和图书馆之间的动画
***************************/
int carmove0to4(int *x,int *y)
{
	int sigle=0;
	//int distance=940;//两点之间的距离
	float prog=100.0/940;//用于进度条填充计算
	float pprog=100.0/940;//用于传入在某两点之间不变的值acsend
	// bar(130,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(130,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(478,720,705,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
学校与游泳馆之间的动画
***************************/
int carmove0to5(int *x,int *y)
{
	int sigle=0;
	//int distance=513;//两点之间的距离
	float prog=100.0/513;//用于进度条填充计算
	float pprog=100.0/513;//用于传入在某两点之间不变的值acsend
	// bar(130,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(130,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,455,468,278,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
小区与学校之间的动画
***************************/
int carmove1to0(int *x,int *y)
{
	int sigle=0;
	//int distance=467;//两点之间的距离
	float prog=100.0/467;//用于进度条填充计算
	float pprog=100.0/467;//用于传入在某两点之间不变的值acsend
	// bar(40,460,130,470,13926);
	// bar(40,460,50,725,13926);
	// bar(40,715,212,725,13926);
	
	sigle=carmove_left(212,720,55,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(45,710,45,475,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(55,465,130,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
小区与东湖之间的动画
/**************************/
int carmove1to2(int *x,int *y)
{
	int sigle=0;
	//int distance=1155;//两点之间的距离
	float prog=100.0/1155;//用于进度条填充计算
	float pprog=100.0/1155;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(267,460,473,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,282,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
小区与商场之间的动画
***************************/
int carmove1to3(int *x,int *y)
{
	int sigle=0;
	//int distance=536;//两点之间的距离
	float prog=100.0/536;//用于进度条填充计算
	float pprog=100.0/536;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(370,460,473,470,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
小区与图书馆之间的动画
***************************/
int carmove1to4(int *x,int *y)
{
	int sigle=0;
	//int distance=643;//两点之间的距离
	float prog=100.0/643;//用于进度条填充计算
	float pprog=100.0/643;//用于传入在某两点之间不变的值acsend
	// bar(212,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(212,720,705,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
小区与游泳馆之间的动画
***************************/
int carmove1to5(int *x,int *y)
{
	int sigle=0;
	//int distance=686;//两点之间的距离
	float prog=100.0/686;//用于进度条填充计算
	float pprog=100.0/686;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,263,473,725,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(212,720,458,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,278,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
东湖与学校之间的动画
***************************/
int carmove2to0(int *x,int *y)
{
	int sigle=0;
	//int distance=630;//两点之间的距离
	float prog=100.0/630;//用于进度条填充计算
	float pprog=100.0/630;//用于传入在某两点之间不变的值acsend
	// bar(130,460,277,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(262,465,130,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/************************
东湖与小区之间的动画
*************************/
int carmove2to1(int *x,int *y)
{
	int sigle=0;
	//int distance=1155;//两点之间的距离
	float prog=100.0/1155;//用于进度条填充计算
	float pprog=100.0/1155;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(267,460,473,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
东湖与商场之间的动画
***************************/
int carmove2to3(int *x,int *y)
{
	int sigle=0;
	//int distance=552;//两点之间的距离
	float prog=100.0/552;//用于进度条填充计算
	float pprog=100.0/552;//用于传入在某两点之间不变的值acsend
	// bar(267,460,370,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,455,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,465,336,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
东湖与图书馆之间的动画
***************************/
int carmove2to4(int *x,int *y)
{
	int sigle=0;
	//int distance=1011;//两点之间的距离
	float prog=100.0/1011;//用于进度条填充计算
	float pprog=100.0/1011;//用于传入在某两点之间不变的值acsend
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,720,273,13926);
	// bar(710,263,720,560,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(272,35,272,258,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,268,710,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(715,278,715,560,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
东湖与游泳馆之间的动画
***************************/
int carmove2to5(int *x,int *y)
{
	int sigle=0;
	//int distance=468;//两点之间的距离
	float prog=100.0/468;//用于进度条填充计算
	float pprog=100.0/468;//用于传入在某两点之间不变的值acsend
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,450,273,13926);
	
	sigle=carmove_left(360,25,282,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	
	sigle=carmove_down(272,35,272,258,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,268,450,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
商场与学校之间的动画
***************************/
int carmove3to0(int *x,int *y)
{
	int sigle=0;
	//int distance=206;//两点之间的距离
	float prog=100.0/206;//用于进度条填充计算
	float pprog=100.0/206;//用于传入在某两点之间不变的值acsend
	// bar(130,460,370,470,13926);
	
	sigle=carmove_left(335,465,130,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}
	
/***************************
商场与小区之间的动画
***************************/
int carmove3to1(int *x,int *y)
{
	int sigle=0;
	//int distance=536;//两点之间的距离
	float prog=100.0/536;//用于进度条填充计算
	float pprog=100.0/536;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,460,473,725,13926);
	// bar(370,460,473,470,13926);
	
	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
商场与东湖之间的动画
***************************/
int carmove3to2(int *x,int *y)
{
	int sigle=0;
	//int distance=552;//两点之间的距离
	float prog=100.0/552;//用于进度条填充计算
	float pprog=100.0/552;//用于传入在某两点之间不变的值acsend
	// bar(267,460,370,470,13926);
	// bar(267,20,277,470,13926);
	// bar(267,20,380,30,13926);
	
	sigle=carmove_left(335,465,282,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,455,272,35,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}


/***************************
商场与图书馆之间的动画
***************************/
int carmove3to4(int *x,int *y)
{
	int sigle=0;
	//int distance=666;//两点之间的距离
	float prog=100.0/666;//用于进度条填充计算
	float pprog=100.0/666;//用于传入在某两点之间不变的值acsend
	// bar(370,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,475,468,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(478,720,705,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(715,710,715,560,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***************************
商场与游泳馆之间的动画
***************************/
int carmove3to5(int *x,int *y)
{
	int sigle=0;
	//int distance=238;//两点之间的距离
	float prog=100.0/238;//用于进度条填充计算
	float pprog=100.0/238;//用于传入在某两点之间不变的值acsend
	// bar(370,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(404,465,458,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,455,468,278,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,268,450,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
图书馆与学校之间的动画
**************************/
int carmove4to0(int *x,int *y)
{
	int sigle=0;
	//int distance=940;//两点之间的距离
	float prog=100.0/940;//用于进度条填充计算
	float pprog=100.0/940;//用于传入在某两点之间不变的值acsend
	// bar(130,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,478,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,130,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/*************************
图书馆与小区之间的动画
*************************/
int carmove4to1(int *x,int *y)
{
	int sigle=0;
	//int distance=643;//两点之间的距离
	float prog=100.0/643;//用于进度条填充计算
	float pprog=100.0/643;//用于传入在某两点之间不变的值acsend
	// bar(212,715,720,725,13926);
	// bar(710,560,720,725,13926);

	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,212,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
图书馆与东湖之间的动画
**************************/
int carmove4to2(int *x,int *y)
{
	int sigle=0;
	//int distance=1011;//两点之间的距离
	float prog=100.0/1011;//用于进度条填充计算
	float pprog=100.0/1011;//用于传入在某两点之间不变的值acsend
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,720,273,13926);
	// bar(710,263,720,560,13926);
	
	sigle=carmove_on(715,560,715,278,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(710,268,282,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,258,272,35,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
图书馆与商场之间的动画
**************************/
int carmove4to3(int *x,int *y)
{
	int sigle=0;
	//int distance=666;//两点之间的距离
	float prog=100.0/666;//用于进度条填充计算
	float pprog=100.0/666;//用于传入在某两点之间不变的值acsend
	// bar(370,460,473,470,13926);
	// bar(463,460,473,725,13926);
	// bar(463,715,720,725,13926);
	// bar(710,560,720,725,13926);
	
	sigle=carmove_down(715,560,715,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(705,720,478,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(468,710,468,475,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
图书馆与游泳馆之间的动画
**************************/
int carmove4to5(int *x,int *y)
{
	int sigle=0;
	//int distance=542;//两点之间的距离
	float prog=100.0/542;//用于进度条填充计算
	float pprog=100.0/542;//用于传入在某两点之间不变的值acsend
	// bar(710,263,720,560,13926);
	// bar(450,263,720,273,13926);
	
	sigle=carmove_on(715,560,715,278,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(710,268,450,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/*************************
游泳馆和学校之间的动画
*************************/
int carmove5to0(int *x,int *y)
{
	int sigle=0;
	//int distance=513;//两点之间的距离
	float prog=100.0/513;//用于进度条填充计算
	float pprog=100.0/513;//用于传入在某两点之间不变的值acsend
	// bar(130,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,455,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,130,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
游泳馆和小区之间的动画
**************************/
int carmove5to1(int *x,int *y)
{
	int sigle=0;
	//int distance=686;//两点之间的距离
	float prog=100.0/686;//用于进度条填充计算
	float pprog=100.0/686;//用于传入在某两点之间不变的值acsend
	// bar(212,715,473,725,13926);
	// bar(463,263,473,725,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,710,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,720,212,720,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***********************
游泳馆和东湖之间的动画
***********************/
int carmove5to2(int *x,int *y)
{
	int sigle=0;
	//int distance=468;//两点之间的距离
	float prog=100.0/468;//用于进度条填充计算
	float pprog=100.0/468;//用于传入在某两点之间不变的值acsend
	// bar(267,20,380,30,13926);
	// bar(267,20,277,273,13926);
	// bar(267,263,450,273,13926);
	
	sigle=carmove_left(450,268,282,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_on(272,258,272,35,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_right(282,25,360,25,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/***********************
游泳馆和商场之间的动画
***********************/
int carmove5to3(int *x,int *y)
{
	int sigle=0;
	//int distance=238;//两点之间的距离
	float prog=100.0/238;//用于进度条填充计算
	float pprog=100.0/238;//用于传入在某两点之间不变的值acsend
	// bar(370,460,473,470,13926);
	// bar(463,263,473,470,13926);
	// bar(450,263,473,273,13926);
	
	sigle=carmove_right(450,268,458,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(468,278,468,455,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_left(458,465,403,465,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}

/**************************
游泳馆和图书馆之间的动画
**************************/
int carmove5to4(int *x,int *y)
{
	int sigle=0;
	//int distance=542;//两点之间的距离
	float prog=100.0/542;//用于进度条填充计算
	float pprog=100.0/542;//用于传入在某两点之间不变的值acsend
	// bar(710,263,720,560,13926);
	// bar(450,263,720,273,13926);
	
	sigle=carmove_right(450,268,710,268,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	sigle=carmove_down(715,278,715,560,x,y,2,&prog,pprog);
	if(sigle==1)
	{
		return sigle;
	}
	bar_round(910,558,70,47,8,1,65535);
	outtextxy(885,550,"100.00",1,1,10,64384);
	return sigle;
}


/**************************
各个小车开到最近点的动画
***************************/
void car_school(int *x,int *y)
{
	carmove_left(240,465,130,465,x,y,1,0,0);
}

void car_xiaoqu(int *x,int *y)
{
	carmove_left(310,720,212,720,x,y,1,0,0);
}

void car_lake(int *x,int *y)
{
	carmove_right(130,25,360,25,x,y,1,0,0);
}

void car_market(int *x,int *y)
{
	carmove_right(240,465,370,465,x,y,1,0,0);
}

void car_library(int *x,int *y)
{
	carmove_on(715,680,715,560,x,y,1,0,0);
}

void car_pool(int *x,int *y)
{
	carmove_left(590,269,450,268,x,y,1,0,0);
}




/*****************************
画路段之间的基本移动图像
*****************************/
int carmove_on(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
{
	int i;
	int j;
	//float acsend=*progress;//用于数字增长
	int sigle=0;
	char mprogress[8]="\0";//用于进度条数字变化
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	/*初始化警车信息*/
	CAR_CONDITION police_position1;
	CAR_CONDITION police_position2;
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 1;
	
	/*警车位置初始化*/
	police_position1.xpixel = x1;
	police_position1.ypixel = y1;
	police_position1.direction = 1;//向上
	
	police_position2.xpixel = x2;
	police_position2.ypixel = y2;
	police_position2.direction = 2;//向下
	
	/*分配警车的图像空间*/
	(police_position1).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	(police_position2).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position1).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position2).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);

	if (flag==2)
	{
		bar((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,65535);
		get_image((police_position1).xpixel-11,(police_position1).ypixel-21,(police_position1).xpixel+12,(police_position1).ypixel+22,(police_position1).pic);
		get_image((police_position2).xpixel-11,(police_position2).ypixel-21,(police_position2).xpixel+12,(police_position2).ypixel+22,(police_position2).pic);
	}
	car_draw_on(car_position);
	
	j=y1-y2;
	
	/*开始动画绘制*/
	for(i=0;i<2*j;i++)
	{
		if(i%2==0)
		{
			carmove_basic(&car_position,x,y,flag,&sigle);
			*progress=*progress+acsend;
		}
		
		if(sigle==1)
		{
			/*获取警车背景并绘制警车*/
			// get_image((police_position1).xpixel-11,(police_position1).ypixel-21,(police_position1).xpixel+12,(police_position1).ypixel+22,(police_position1).pic);
			police_draw_on(police_position1);
			
			// get_image((police_position2).xpixel-11,(police_position2).ypixel-21,(police_position2).xpixel+12,(police_position2).ypixel+22,(police_position2).pic);
			police_draw_down(police_position2);
			
			carmove_basic(&police_position1,x,y,1,&sigle);
			carmove_basic(&police_position2,x,y,1,&sigle);
			
			if((abs(police_position1.ypixel-car_position.ypixel)<44)||(abs(police_position2.ypixel-car_position.ypixel)<45))
			{
				delay(80);
				catchBox(x,y);
				break;
			}

		}
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
	}
	

	if (flag == 2)
	{
		bar((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,65535);
	}
	else
	{
		put_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);
	free((police_position1).pic);
	free((police_position2).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	(police_position1).pic = NULL;
	(police_position2).pic = NULL;
	
	return sigle;
	
}

int carmove_down(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
{
	int i;
	int j;
	//float acsend=*progress;//用于数字增长
	int sigle=0;
	char mprogress[8]="\0";//用于进度条数字变化
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	/*初始化警车信息*/
	CAR_CONDITION police_position1;
	CAR_CONDITION police_position2;
	
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 2;
	/*警车位置初始化*/
	police_position1.xpixel = x1;
	police_position1.ypixel = y1;
	police_position1.direction = 2;//向下
	
	police_position2.xpixel = x2;
	police_position2.ypixel = y2;
	police_position2.direction = 1;//向上
	
	/*分配警车的图像空间*/
	(police_position1).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	(police_position2).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position1).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position2).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);

	if (flag==2)
	{
		bar((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,65535);
		get_image((police_position1).xpixel-11,(police_position1).ypixel-21,(police_position1).xpixel+12,(police_position1).ypixel+22,(police_position1).pic);
		get_image((police_position2).xpixel-11,(police_position2).ypixel-21,(police_position2).xpixel+12,(police_position2).ypixel+22,(police_position2).pic);
	}
	car_draw_down(car_position);
	
	j=y2-y1;
	
	/*开始动画绘制*/
	for(i=0;i<2*j;i++)
	{
		if(i%2==0)
		{
			carmove_basic(&car_position,x,y,flag,&sigle);
			*progress=*progress+acsend;
		}
		
		if(sigle==1)
		{
			/*获取警车背景并绘制警车*/
			// get_image((police_position1).xpixel-11,(police_position1).ypixel-21,(police_position1).xpixel+12,(police_position1).ypixel+22,(police_position1).pic);
			police_draw_down(police_position1);
			
			// get_image((police_position2).xpixel-11,(police_position2).ypixel-21,(police_position2).xpixel+12,(police_position2).ypixel+22,(police_position2).pic);
			police_draw_on(police_position2);
			
			carmove_basic(&police_position2,x,y,1,&sigle);
			carmove_basic(&police_position1,x,y,1,&sigle);
			
			
			if((abs(police_position1.ypixel-car_position.ypixel)<44)||(abs(police_position2.ypixel-car_position.ypixel)<45))
			{
				delay(80);
				catchBox(x,y);
				break;
			}
			

		}
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
	}
	
	if (flag == 2)
	{
		bar((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,65535);
	}
	else
	{
		put_image((car_position).xpixel-11,(car_position).ypixel-21,(car_position).xpixel+12,(car_position).ypixel+22,(car_position).pic);
	}
	/*开始动画绘制
	for(i=0;i<j;i++)
	{
        sigle=carmove_basic(&car_position,x,y,flag);
		*progress+=acsend;
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
		if(sigle==1)
		{
			return sigle;
		}
	}*/
	
	/*释放分配的内存空间*/
	free((car_position).pic);
	free((police_position1).pic);
	free((police_position2).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	(police_position1).pic = NULL;
	(police_position2).pic = NULL;
	
	return sigle;
	
}

int carmove_left(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
{
	int i;
	int j;
	//float acsend=*progress;//用于数字增长
	int sigle=0;
	char mprogress[8]="\0";//用于进度条数字变化
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	/*初始化警车信息*/
	CAR_CONDITION police_position1;
	CAR_CONDITION police_position2;
	
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 3;
	/*警车位置初始化*/
	police_position1.xpixel = x1;
	police_position1.ypixel = y1;
	police_position1.direction = 3;//向左
	
	police_position2.xpixel = x2;
	police_position2.ypixel = y2;
	police_position2.direction = 4;//向右
	
	/*分配警车的图像空间*/
	(police_position1).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	(police_position2).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position1).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position2).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);

	if (flag==2)
	{
		bar((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,65535);
		get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
		get_image((police_position2).xpixel-21,(police_position2).ypixel-11,(police_position2).xpixel+22,(police_position2).ypixel+12,(police_position2).pic);
	}
	car_draw_left(car_position);
	// get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
	// get_image((police_position2).xpixel-21,(police_position2).ypixel-11,(police_position2).xpixel+22,(police_position2).ypixel+12,(police_position2).pic);
	j=x1-x2;
	
	/*开始动画绘制*/
	for(i=0;i<2*j;i++)
	{
		if(i%2==0)
		{
			carmove_basic(&car_position,x,y,flag,&sigle);
			*progress=*progress+acsend;
		}
		
		if(sigle==1)
		{
			/*获取警车背景并绘制警车*/
			// get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
			police_draw_left(police_position1);
			
			carmove_basic(&police_position1,x,y,1,&sigle);
			// get_image((police_position2).xpixel-21,(police_position2).ypixel-11,(police_position2).xpixel+22,(police_position2).ypixel+12,(police_position2).pic);
			police_draw_right(police_position2);
			
			
			carmove_basic(&police_position2,x,y,1,&sigle);
			
			if((abs(police_position1.xpixel-car_position.xpixel)<44)||(abs(police_position2.xpixel-car_position.xpixel)<45))
			{
				delay(80);
				catchBox(x,y);
				break;
			}

		}
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
	}
	
	/*开始动画绘制
	for(i=0;i<j;i++)
	{
	    sigle=carmove_basic(&car_position,x,y,flag);
		*progress+=acsend;
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
		if(sigle==1)
		{
			return sigle;
		}
	}*/
	if (flag == 2)
	{
		bar((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,65535);
	}
	else
	{
		put_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
	}
	/*释放分配的内存空间*/
	free((car_position).pic);
	free((police_position1).pic);
	free((police_position2).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	(police_position1).pic = NULL;
	(police_position2).pic = NULL;
	
	return sigle;

}

int carmove_right(int x1,int y1, int x2, int y2,int *x,int *y, int flag,float *progress,float acsend)
{
	int i;
	int j;
	//float acsend=*progress;//用于数字增长
	int sigle=0;
	char mprogress[8]="\0";//用于进度条数字变化
	
	/*初始化小车*/
	CAR_CONDITION car_position;
	/*初始化警车信息*/
	CAR_CONDITION police_position1;
	CAR_CONDITION police_position2;
	
	
	/*小车位置初始化*/
	car_position.xpixel = x1;
	car_position.ypixel = y1;
	car_position.direction = 4;
	/*警车位置初始化*/
	police_position1.xpixel = x1;
	police_position1.ypixel = y1;
	police_position1.direction = 4;//向右
	
	police_position2.xpixel = x2;
	police_position2.ypixel = y2;
	police_position2.direction = 3;//向左
	
	/*分配警车的图像空间*/
	(police_position1).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	(police_position2).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*分配小车图像空间*/
	(car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((car_position).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position1).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	if((police_position2).pic==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}
	
	/*获取小车背景并绘制小车*/
	get_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);

	if (flag==2)
	{
		bar((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,65535);
		get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
		get_image((police_position2).xpixel-21,(police_position2).ypixel-11,(police_position2).xpixel+22,(police_position2).ypixel+12,(police_position2).pic);
	
	}
	
	
	
	car_draw_left(car_position);
	
	j=x2-x1;
	// get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
	// get_image((police_position2).xpixel-21,(police_position2).ypixel-11,(police_position2).xpixel+22,(police_position2).ypixel+12,(police_position2).pic);
	/*开始动画绘制*/
	for(i=0;i<2*j;i++)
	{
		if(i%2==0)
		{
			carmove_basic(&car_position,x,y,flag,&sigle);
			*progress=*progress+acsend;
		}
		
		if(sigle==1)
		{
			/*获取警车背景并绘制警车*/
			// get_image((police_position1).xpixel-21,(police_position1).ypixel-11,(police_position1).xpixel+22,(police_position1).ypixel+12,(police_position1).pic);
			 police_draw_right(police_position1);
			carmove_basic(&police_position1,x,y,1,&sigle);
			
			police_draw_left(police_position2);
			
			
			carmove_basic(&police_position2,x,y,1,&sigle);
			
			if((abs(police_position1.xpixel-car_position.xpixel)<44)||(abs(police_position2.xpixel-car_position.xpixel)<45))
			{
				delay(80);
				catchBox(x,y);
				break;
			}

		}
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
	}
	
	/*开始动画绘制
	for(i=0;i<j;i++)
	{ 
	    sigle=carmove_basic(&car_position,x,y,flag);
		*progress+=acsend;
		if(flag==2&&i%5==0)
		{
			bar_round(910,558,70,47,8,1,65535);
			sprintf(mprogress,"%.2f",*progress);
			outtextxy(885,550,mprogress,1,1,10,64384);
			
		}
		if(sigle==1)
		{
			return sigle;
		}
	}*/
	
	if (flag == 2)
	{
		bar((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,65535);
	}
	else
	{
		put_image((car_position).xpixel-21,(car_position).ypixel-11,(car_position).xpixel+22,(car_position).ypixel+12,(car_position).pic);
	}
	
	/*释放分配的内存空间*/
	free((car_position).pic);
	free((police_position1).pic);
	free((police_position2).pic);

	/*将指针置空*/
	(car_position).pic = NULL;
	(police_position1).pic = NULL;
	(police_position2).pic = NULL;
	
	return sigle;
	
}

 




