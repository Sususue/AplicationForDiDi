#include "common.h"
#include "carrent.h"

// #define PARKNUM 6

void car_rent_box(int* x, int* y, USEINFOR *infor)
{
	int button=0;
    int mx=0;
    int my=0;
	PARK parking[PARKNUM];
	CARRENT rent[PARKNUM];
	int snumber=0;//用于停车场的编号
	char carnumber[6][3];//用于停车场上车辆数目的转换
	int carflag;//用于传递选中小车的信息
	int flaging;//用于判断从停车场信息界面返回时进入哪一个逻辑
	
	newpark(parking);
	
	mousehide(*x,*y);
	//保存背景
    save_image(771,2,996,612,"carrent");
	
	//底色
    bar(771,2,996,612,65523);
	
	//画停车场的位置
	FillCircle(317,70,30,9284);//东湖
	FillCircle(513,223,30,9284);//游泳馆
	FillCircle(100,420,30,9284);//学校
	FillCircle(340,510,30,9284);//商场
	FillCircle(182,674,30,9284);//小区
	FillCircle(670,530,30,9284);//图书馆
	
	//画停车场上车的数目
	sprintf(carnumber[2],"%d",parking[2].carnum);
	outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
	
	sprintf(carnumber[5],"%d",parking[5].carnum);
	outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
	
	sprintf(carnumber[0],"%d",parking[0].carnum);
	outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
	
	sprintf(carnumber[3],"%d",parking[3].carnum);
	outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
	
	sprintf(carnumber[1],"%d",parking[1].carnum);
	outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
	
	sprintf(carnumber[4],"%d",parking[4].carnum);
	outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
	
	
	//小桔租车
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
	fdhz(805,67,3,3,"小",64384);
    fdhz(850,67,3,3,"桔",64384);
    fdhz(900,67,3,3,"租",64384);
    fdhz(945,67,3,3,"车",64384);
	
	//去选车
	bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
	fdhz(855,190,1,1,"去",64384);
    fdhz(890,190,1,1,"选",64384);
    fdhz(925,190,1,1,"车",64384);
	
	//相关信息介绍
	fdhz(805,270,1,1,"请在指定站点内选车",64384);
	outtextxy(980,270,",",1,1,1,64384);
	fdhz(805,300,1,1,"下单即能立即用车",64384);
	
	fdhz(805,360,1,1,"用车期间请遵守交通",64384);
	fdhz(805,390,1,1,"法规",64384);
	outtextxy(839,390,",",1,1,1,64384);
	fdhz(848,390,1,1,"合理规划出行时",64384);
	fdhz(805,420,1,1,"间和线路",64384);
	outtextxy(880,420,",",1,1,1,64384);
	fdhz(894,420,1,1,"杜绝酒驾",64384);
	outtextxy(969,420,",",1,1,1,64384);
	fdhz(805,450,1,1,"疲劳驾驶等不安全驾",64384);
	fdhz(805,480,1,1,"驶行为",64384);
	outtextxy(862,480,".",1,1,1,64384);
	
	
	
	
	reset_mouse(x,y);
	 while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
		
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            //对地图上原有的停车场进行遮挡
			FillCircle(317,70,30,57083);//东湖
			FillCircle(513,223,30,57083);//游泳馆
			FillCircle(100,420,30,57083);//学校
			FillCircle(340,510,30,57083);//商场
			FillCircle(182,674,30,57083);//小区
			FillCircle(670,530,30,57083);//图书馆
			
            break;
        }
		
		else if (mx>=798  && mx<=994 && my>=172 && my<=224 && button)//点击去选车，弹出弹框提醒选择停车场
        {
            mousehide(*x,*y);

            save_image(512-210,384-140,512+210,384+140,"unpark");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(355,360,2,2,"请选择图中停车场",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"unpark");
			
            reset_mouse(x,y);
        }
		
		else if (mx>=287  && mx<=347 && my>=40  && my<=110 && button)//点击东湖停车场
		{
			snumber=2;
		
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
			
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
		else if (mx>=483  && mx<=543 && my>=193  && my<=253 && button)//点击游泳馆停车场
		{
			snumber=5;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
		else if (mx>=70  && mx<=130 && my>=390  && my<=450 && button)//点击学校停车场
		{
			snumber=0;
	
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
		else if (mx>=310  && mx<=370 && my>=480  && my<=540 && button)//点击商场停车场
		{
			snumber=3;

			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
		else if (mx>=152  && mx<=212 && my>=644  && my<=704 && button)//点击小区停车场
		{
			snumber=1;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
		else if (mx>=640  && mx<=700 && my>=500  && my<=560 && button)//点击图书馆停车场
		{
			snumber=4;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//对地图上原有的停车场进行遮挡
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//画停车场的位置
				FillCircle(317,70,30,9284);//东湖
				FillCircle(513,223,30,9284);//游泳馆
				FillCircle(100,420,30,9284);//学校
				FillCircle(340,510,30,9284);//商场
				FillCircle(182,674,30,9284);//小区
				FillCircle(670,530,30,9284);//图书馆
				//画停车场上车的数目
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//东湖
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//游泳馆
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//学校
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//商场
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//小区
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//图书馆
			}
		}
		
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
        {
            safe_box(x,y);
        }
		
		 else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
	}
	
	//显示背景
    mousehide(*x,*y); 
    printf_image(771,2,996,612,"carrent");
	
	//显示鼠标
    reset_mouse(x,y);
	
}


/*typedef struct park{
	int parknum;        //该停车场的编号
    int carnum;   //车的数量
	int x;  //停车场位置
	int y;
}PARK;


typedef struct carrent{
	int parknum;        //所处停车场的编号
    CARINFOR rentcar;
	int leftenergy;        //车辆剩余电量
}CARRENT;          //共享汽车的信息*/

int show_parkinfo(int *x,int *y,const PARK parking[],CARRENT rent[],int nuber,int *carflag1,int *flaging1)//用于显示停车场信息的函数
{
	int button=0;
    int mx=0;
    int my=0;
	int showx=120;
	int showy=255;//用于输出车辆信息的横纵坐标(初始化在第一个格子里输出)
	char parknumber[3];//用于停车场编号的数据类型转换
	char lenergy[5];//用于剩余电量的数据类型转换
	int i=0;//用于输出车辆信息的循环
	int unchoose=0;//用于判断是否选择了可租车辆
	
	newrentcar(rent,parking,nuber);
    
	mousehide(*x,*y);
	
	save_image(83,109,683,659,"parkinfo");
	
	bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);//底板
	
	sprintf(parknumber,"%d",parking[nuber].parknum);
	outtextxy(285,128,parknumber,2,2,15,44373);
    fdhz(325,128,2,2,"号停车场",44373);//显示停车场编号信息
	
	lean_line_thick(608,133,30,45,3,64384);
	lean_line_thick(608,133+20,30,-45,3,64384);//画红叉
	
	bar(88,180,678,210,63422);
	bar(88,300,678,302,63422);
	bar(88,390,678,392,63422);
	bar(88,480,678,482,63422);
	bar(88,570,678,572,63422);//分格线
	
	
	for(i=0;i<parking[nuber].carnum;i++)
	{
		fdhz(showx,showy-10,2,2,rent[0].rentcar.type,44373);//车型
		
		fdhz(showx+100,showy,1,1,"剩余电量",44373);
		outtextxy(showx+170,showy,":",1,1,1,44373);
		sprintf(lenergy,"%d",rent[i].leftenergy);
		outtextxy(showx+190,showy,lenergy,1,1,12,44373);
		outtextxy(showx+220,showy,"%",1,1,1,44373);//剩余电量
		
		outtextxy(showx+270,showy,"0.69",1,1,12,44373);
		fdhz(showx+330,showy,1,1,"元",44373);
		outtextxy(showx+345,showy,"/",1,1,1,44373);
		fdhz(showx+360,showy,1,1,"分钟",44373);//价格
		
		showy=showy+90;
		
	}
	
	bar_round(383,610,100,50,15,1,64384);
	bar_round(383,610,96,46,15,1,65535);
	fdhz(350,595,2,2,"确认",64384);//确认框
	
	
	
	reset_mouse(x,y);
	while(1)
	{
	    newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		if(mx>=333 && mx<=433 && my>=585 && my<=635 && button)//点击确认框
		{
			if(unchoose==0)
			{
				mousehide(*x,*y);

                save_image(383-210,384-140,512+210,384+140,"unchoose1");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(230,360,2,2,"您还未选择车辆",64384);
                fdhz(320,420,1,1,"按任意键继续",44373);
                getch();
                printf_image(383-210,384-140,512+210,384+140,"unchoose1");
                reset_mouse(x,y);
			}
			
			else
			{			
				*flaging1=0;
				break;
			}
		}
		if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
			*flaging1=1;
            break;
        }
		if(mx>=608  && mx<=628 && my>=133 && my<=153 && button)//点击红叉返回
        {
			*flaging1=1;
            break;
        }
		
		switch(parking[nuber].carnum)
		{
			case 1:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			break;
			
			case 2:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			break;
			
			case 3:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,392,670,480,65535);
				
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=392 && my<=480 && button)
			{
				*carflag1=2;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,302,670,390,65535);
				
				lean_line_thick(600,442,15,45,3,64384);
				lean_line_thick(600+11,442+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			break;
			
			case 4:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,392,670,480,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=392 && my<=480 && button)
			{
				*carflag1=2;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,210,670,300,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,442,15,45,3,64384);
				lean_line_thick(600+11,442+8,40,-45,3,64384);
		
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=482 && my<=570 && button)
			{
				*carflag1=3;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				bar(530,210,670,300,65535);
				
				lean_line_thick(600,532,15,45,3,64384);
				lean_line_thick(600+11,532+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			break;
		}
	}
		
	
	mousehide(*x,*y);
    printf_image(83,109,683,659,"parkinfo");
    
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景

}

void rentprocess_box(int *x, int *y,const PARK parking[],const CARRENT rent[],int *carflag2, USEINFOR *infor)
{
	//time_t nowtime1;
	//time_t nowtime2;//用于获取当前时间
	//struct tm *info;
	//int time_gap;//用于时间间隔的计算
	
	//获取进入呼叫快车进程时的时间
	//int nowtime_hour;
	//int nowtime_min;
	//int nowtime_sec;
	
	int button=0;
    int mx=0;
    int my=0;
	char lefenergy[5];//用于剩余电量的数据类型转换
	int sigle=0;//用于接力退出报警
	
	mousehide(*x,*y);
	//保存背景
    save_image(771,2,996,612,"rentpro");
	
	//底色
    bar(771,2,996,612,65523);
	
	//小桔租车
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
	fdhz(805,67,3,3,"小",64384);
    fdhz(850,67,3,3,"桔",64384);
    fdhz(900,67,3,3,"租",64384);
    fdhz(945,67,3,3,"车",64384);
	
	//车牌号码
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"车牌",64384);
	outtextxy(847,188,":",1,1,40,64384);
    fdhz(862,190,1,1,"鄂",64384);
    outtextxy(878,190,"AD",1,1,15,64384);
	outtextxy(910,190,rent[*carflag2].rentcar.carname,1,1,15,64384);
   
    //用车时间
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
	fdhz(810,280,1,1,"用车时间",64384);
    outtextxy(887,278,":",1,1,40,64384);
	outtextxy(900,280,"0",1,1,1,64384);
	fdhz(950,280,1,1,"分钟",64384);
   
	//当前价格
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
	fdhz(810,370,1,1,"当前价格",64384);
    outtextxy(887,368,":",1,1,40,64384);
	outtextxy(900,370,"00.00",1,1,10,64384);
	fdhz(960,370,1,1,"元",64384);
	
	//电量
	bar_round(896,468,196,52,10,1,64384);
    bar_round(896,468,190,47,8,1,65535);
	fdhz(810,460,1,1,"电量",64384);
    outtextxy(847,458,":",1,1,40,64384);
	sprintf(lefenergy,"%d",rent[*carflag2].leftenergy);
	outtextxy(877,459,lefenergy,1,1,12,64384);
	outtextxy(927,459,"%",1,1,1,64384);
	
	//进度条
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(865,550,1,1,"锁",64384);
    fdhz(905,550,1,1,"车",64384);

	reset_mouse(x,y);

	sigle = find(x,y,&rent[*carflag2],infor,parking);
	//  while (1)
    // {
    //     newxy(x,y,&button);
	// 	mx = *x;
	// 	my = *y;
	
	// 	if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
    //     {
    //         break;
    //     }
	// 	else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
    //     {
    //         exit(0);
    //     }
	// 	else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//点击安全，弹出信息框
    //     {
    //         safe_box(x,y);
    //     }
	
	// }
	
	//显示背景
    mousehide(*x,*y); 
    printf_image(771,2,996,612,"rentpro");
	
	//显示鼠标
    reset_mouse(x,y);
}



//初始化共享车辆信息
void newrentcar(CARRENT *car,const PARK parking[],int number1)
{
    int i;//用于计数
	int m;
    int n;//用于记录随机数
    PLACE rentplace[PARKNUM];
    char rentcard[25][6];//车牌号集
    // char renttype[7];//车辆类型
	
	
    //初始化车的位置
    rentplace[2].x=317;
    rentplace[2].y=25;//东湖
    rentplace[5].x=513;
    rentplace[5].y=268;//游泳馆
    rentplace[0].x=100;
    rentplace[0].y=465;//学校
    rentplace[3].x=340;
    rentplace[3].y=465;//商场
    rentplace[1].x=182;
    rentplace[1].y=720;//小区
	rentplace[4].x=715;
    rentplace[4].y=530;//图书馆


    //初始化车牌号集
    strcpy(rentcard[0],"B7351");
    strcpy(rentcard[1],"92857");
    strcpy(rentcard[2],"A6103");
    strcpy(rentcard[3],"61135");
    strcpy(rentcard[4],"C2861");
    strcpy(rentcard[5],"B8963");
    strcpy(rentcard[6],"C8272");
    strcpy(rentcard[7],"95512");
    strcpy(rentcard[8],"B3519");
    strcpy(rentcard[9],"93760");
	strcpy(rentcard[10],"95287");
	strcpy(rentcard[11],"A2392");
	strcpy(rentcard[12],"C6665");
	strcpy(rentcard[13],"B7328");
	strcpy(rentcard[14],"C1275");
	strcpy(rentcard[15],"91295");
	strcpy(rentcard[16],"B3028");
	strcpy(rentcard[17],"C9778");
	strcpy(rentcard[18],"A9517");
	strcpy(rentcard[19],"B2637");
	strcpy(rentcard[20],"C7970");
	strcpy(rentcard[21],"B3187");
	strcpy(rentcard[22],"A5681");
	strcpy(rentcard[23],"B1886");
	strcpy(rentcard[24],"97395");


	//初始化车辆类型
    // strcpy(renttype,"东风");


    srand((unsigned int)time(NULL));

	strcpy(car->rentcar.type,"东风");
	
    for ( i = 0; i < parking[number1].carnum; i++, car++)
    {
        n=rand()%25;
		m=rand()%61;
		car->leftenergy=40+m;		//初始电量在40%-100%内以保证车辆可以使用
        car->rentcar.x=rentplace[number1].x;
        car->rentcar.y=rentplace[number1].y;//根据停车场编号，初始化小车开出停车场的位置
		car->parknum=number1+1;             //小车所处停车场编号，注意加一
        strcpy(car->rentcar.carname,rentcard[n]);
    }
}


//初始化停车场信息
void newpark(PARK *parking)
{
	int i;//用于计数
	int n;//用于记录随机数
	PLACE parkplace[PARKNUM];
	
	//初始化停车场的位置
    parkplace[2].x=317;
    parkplace[2].y=70;//东湖
    parkplace[5].x=513;
    parkplace[5].y=223;//游泳馆
    parkplace[0].x=100;
    parkplace[0].y=420;//学校
    parkplace[3].x=340;
    parkplace[3].y=510;//商场
    parkplace[1].x=182;
    parkplace[1].y=674;//小区
	parkplace[4].x=670;
    parkplace[4].y=530;//图书馆

	for ( i = 0; i < PARKNUM; i++, parking++)
    {
        n=rand()%4+1;
		parking->parknum=i+1;
        parking->x=parkplace[i].x;
        parking->y=parkplace[i].y;
		parking->carnum=n;
    }
}