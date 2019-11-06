#include "common.h"
#include "admin.h"

/*******************************
管理员端主逻辑
*******************************/
int admin(int *x,int *y)
{
	int mx=0;
	int my=0;
	int button=0;
	int judge;//用于接力推出
	int managejudge=0;//用于判断进入哪一个函数  1：driver_box   2:put_diver
	CARFA thiscar;
	
	mousehide(*x,*y);
	admin_draw();//画管理员初始界面图
	reset_mouse(x,y);
	
	while(1)
    {
        newxy(x,y,&button);
		mx=*x;
		my=*y;
		
		if(mx>= 26 && mx<=222 && my>=272 && my<=324 && button)
		{
			mousehide(*x,*y);
			fdhz(48,285,2,2,"司",44373);
			fdhz(88,285,2,2,"机",44373);
			fdhz(128,285,2,2,"管",44373);
			fdhz(168,285,2,2,"理",44373);
			delay0(30);
			fdhz(48,285,2,2,"司",64384);
			fdhz(88,285,2,2,"机",64384);
			fdhz(128,285,2,2,"管",64384);
			fdhz(168,285,2,2,"理",64384);
			reset_mouse(x,y);
			managejudge=1;
		}
		else if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
		{
			mousehide(*x,*y);
			fdhz(48,685,2,2,"退",44373);
			fdhz(88,685,2,2,"出",44373);
			fdhz(128,685,2,2,"登",44373);
			fdhz(168,685,2,2,"录",44373);
			reset_mouse(x,y);
			delay0(30);
			break;//退出登录
		}
		
		switch(managejudge)
		{
			case 1:
				managejudge=driver_box(x,y,&thiscar);
				break;
			case 2:
				managejudge=put_diver(x,y,&thiscar);
				break;
		}
		if(managejudge==-1)
		{
			break;
		}
	}
	return 0;
}

/*******************************
司机信息界面
*******************************/
int driver_box(int *x,int *y,CARFA *thiscar)
{
	int button=0;
    int mx=0;
    int my=0;
	int i=0;//用于循环画框
	int j;//用于司机信息循环
	int x1=435;
	int x2=825;
	int y1=190;//初始化画方框坐标
	FILE *fp = NULL;
	CARFA car;
	int flag;
	int judge;
	
	
	mousehide(*x,*y);
    //保存背景
    //save_image(249,2,1022,768,"driver");
	bar(251,138,1022,768,65535);
	
	bar(249,2,1022,132,65523);//右上选择区
	fdhz(307,60,2,2,"司机信息查询",64384);
	
	if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 


	/* for(i=0;i<5;i++)
	{
		bar_round(x1,y1,220,70,10,1,64384);
		bar_round(x1,y1,214,65,8,1,65535);
		bar_round(x2,y1,220,70,10,1,64384);
		bar_round(x2,y1,214,65,8,1,65535);//画框
		
		

		// fdhz(x1-100,y1-10,1,1,"鄂",64384);
		// outtextxy(x1-84,y1-10,"A-",1,1,15,64384);
		// outtextxy(x1-60,y1-10,car.,1,1,15,64384);
		// fdhz(x1+60,y1-10,1,1,"接单",64384);//显示左侧司机信息
		
		// fdhz(x2-100,y1-10,1,1,"鄂",64384);
		// outtextxy(x2-84,y1-10,"A-",1,1,15,64384);
		// outtextxy(x2-60,y1-10,"12345",1,1,15,64384);
		// fdhz(x2+60,y1-10,1,1,"停用",64384);//显示右侧司机信息
		
		y1+=110;
	} */
	
	
	//显示左侧司机信息(0—4)
	for(i=0;i<5;i++)
	{
		bar_round(x1,y1,220,70,10,1,64384);
		bar_round(x1,y1,214,65,8,1,65535);
		bar_round(x2,y1,220,70,10,1,64384);
		bar_round(x2,y1,214,65,8,1,65535);//画框

		fread(&car,sizeof(CARFA),1,fp);


		fdhz(x1-100,y1-10,1,1,"鄂",64384);
		outtextxy(x1-84,y1-10,"A-",1,1,15,64384);
		outtextxy(x1-60,y1-10,car.fastcar.carname,1,1,15,64384);
		if (car.call == 1)
		{
			fdhz(x1+60,y1-10,1,1,"接单",64384);
		}
		else if (car.call >= 2)
		{
			fdhz(x1+60,y1-10,1,1,"停用",64384);
		}
		
		y1+=110;
	}

	y1 = 190;
	//显示右侧的司机信息(5—9)
	for(i=5;i<10;i++)
	{
		fread(&car,sizeof(CARFA),1,fp);
		fdhz(x2-100,y1-10,1,1,"鄂",64384);
		outtextxy(x2-84,y1-10,"A-",1,1,15,64384);
		outtextxy(x2-60,y1-10,car.fastcar.carname,1,1,15,64384);
		if (car.call == 1)
		{
			fdhz(x2+60,y1-10,1,1,"接单",64384);
		}
		else if (car.call >= 2)
		{
			fdhz(x2+60,y1-10,1,1,"停用",64384);
		}
		y1+=110;
	}
	fclose(fp);
	
	reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=325 && mx<=545 && my>=155 && my<=225 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 0;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=265 && my<=335 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 1;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=375 && my<=445 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 2;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=485 && my<=555 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 3;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=595 && my<=665 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 4;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=155 && my<=225 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 5;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=265 && my<=335 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 6;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=375 && my<=445 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 7;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=485 && my<=555 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 8;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=595 && my<=665 &&button)
		{
			//mousehide(*x,*y);
			//bar_round(124,698,196,52,10,1,65523);
			//put_diver(x,y);
			flag = 9;
			judge = 2;
			break;
		}
		if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
        {
			mousehide(*x,*y);
			fdhz(48,685,2,2,"退",44373);
			fdhz(88,685,2,2,"出",44373);
			fdhz(128,685,2,2,"登",44373);
			fdhz(168,685,2,2,"录",44373);
			reset_mouse(x,y);
			delay0(50);
            judge = -1;//退出登录
			break;
        }

	}
	if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 
	fseek(fp,sizeof(CARFA)*flag,SEEK_SET);
	fread(thiscar,sizeof(CARFA),1,fp);
	fclose(fp);
	

	//mousehide(*x,*y);  //隐藏鼠标
    //printf_image(249,2,1022,768,"driver");
    
    //reset_mouse(x,y);   //避免留下鼠标所在位置的背景
	return judge;
  
}

/*******************************
进入具体司机信息显示的函数
********************************/                     
int put_diver(int *x,int *y,CARFA *thiscar)
{
	int button=0;
    int mx=0;
    int my=0;
	char chpraise[3];
	int judge = 0;
	// char chcall[3];
	mousehide(*x,*y);
    //保存背景
    //save_image(251,138,1022,768,"putdrive");
	sprintf(chpraise,"%d",thiscar->praise);
	// sprintf(chcall,"%d",thiscar->call);

	bar(251,138,1022,768,65535);
	
	fdhz(287,168,2,2,thiscar->name,44373);//姓
	fdhz(327,168,2,2,"师傅",44373);
	
	fdhz(287,268,1,1,"车牌",44373);
	outtextxy(327,268,":",1,1,15,44373);
	fdhz(347,268,1,1,"鄂",44373);
	outtextxy(363,268,"A-",1,1,15,44373);
	outtextxy(387,268,thiscar->fastcar.carname,1,1,15,44373);//车牌
	
	fdhz(287,308,1,1,"车型",44373);
	outtextxy(327,308,":",1,1,15,44373);
	fdhz(342,308,1,1,thiscar->fastcar.type,44373);//车型
	
	fdhz(287,348,1,1,"评价分",44373);
	outtextxy(347,348,":",1,1,15,44373);
	outtextxy(362,348,chpraise,1,1,15,44373);//差评数
	
	// fdhz(287,388,1,1,"好评数",44373);
	// outtextxy(347,388,":",1,1,15,44373);
	// outtextxy(362,388,"0",1,1,15,44373);//差评数
	
	fdhz(287,428,1,1,"报警记录",44373);
	outtextxy(367,428,":",1,1,15,44373);
	

	if (thiscar->call>=2)
	{
		outtextxy(382,428,"1",1,1,15,44373);
		switch (thiscar->call)
		{
			case 2:
				fdhz(382,468,1,1,"对乘客性骚扰或者性侵",44373);
				break;
			case 3:
				fdhz(382,468,1,1,"与乘客发生肢体冲突",44373);
				break;
			case 4:
				fdhz(382,468,1,1,"限制乘客人身自由",44373);
				break;
			case 5:
				fdhz(382,468,1,1,"乘客遭遇人身伤害",44373);
				break;
			case 6:
				fdhz(382,468,1,1,"其他问题",44373);
				break;
			default:
				break;
		}
	}
	else
	{
		outtextxy(382,428,"0",1,1,15,44373);
	}
	
	
	
	bar_round(480,720,220,70,10,1,64384);
	bar_round(480,720,214,65,8,1,65535);
	fdhz(410,705,2,2,"替换司机",64384);
	bar_round(815,720,220,70,10,1,64384);
	bar_round(815,720,214,65,8,1,65535);
	fdhz(752,705,2,2,"返",64384);
	fdhz(858,705,2,2,"回",64384);
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		if(mx>=705 && mx<=925 && my>=685 && my<=755 &&button)//返回
		{
			mousehide(*x,*y);
			fdhz(752,705,2,2,"返",44373);
			fdhz(858,705,2,2,"回",44373);
			reset_mouse(x,y);
			delay0(30);
			judge = 1;
			break;
		}
		else if(mx>=370 && mx<=590 && my>=685 && my<=755 &&button)//替换司机
		{
			mousehide(*x,*y);
			fdhz(410,705,2,2,"替换司机",44373);
			reset_mouse(x,y);
			delay0(50);
			if (thiscar->call == 1)
			{
				mousehide(*x,*y);
        		save_image(483-210,384-140,483+210,384+140,"note");
        		bar_round(483,384,416,270,50,1,64384);
        		bar_round(483,384,410,265,48,1,65535);
        		fdhz(330,340,2,2,"该司机不需要替换",64384);
        		fdhz(431,430,1,1,"按任意键继续",44373);
        		getch();
        		printf_image(483-210,384-140,483+210,384+140,"note");
        		reset_mouse(x,y);
			}
			else
			{
				managecar(x,y,thiscar);
				judge = 1;
				break;
			}
		}
		else if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
        {
			mousehide(*x,*y);
			fdhz(48,685,2,2,"退",44373);
			fdhz(88,685,2,2,"出",44373);
			fdhz(128,685,2,2,"登",44373);
			fdhz(168,685,2,2,"录",44373);
			reset_mouse(x,y);
			delay0(50);
            judge = -1;//退出登录
			break;
        }
		
	}
	//mousehide(*x,*y);  //隐藏鼠标
	//printf_image(251,138,1022,768,"putdrive");
	//reset_mouse(x,y);   //避免留下鼠标所在位置的背景
	return judge;
}

/*******************************
管理员界面图
*******************************/
void admin_draw(void)
{
	
	bar(1,1,1023,767,65535); //设置背景为白色
	 
	//底色
	bar(2,2,247,766,65523);//左侧选择区
	bar(249,2,1022,134,65523);//右上选择区
	
	//背景分区橙色边框
	rectangle(1,0,249,768,2,64384); //左侧选择区
    rectangle(247,0,1023,136,2,64384);//右上选择区
	
	//管理员
	bar_round(124,90,196,96,25,1,64384);
    bar_round(124,90,190,91,23,1,65535);
    fdhz(48,67,3,3,"管",64384);
    fdhz(103,67,3,3,"理",64384);
	fdhz(158,67,3,3,"员",64384);
	
	//司机管理
    bar_round(124,298,196,52,10,1,64384);
    bar_round(124,298,190,47,8,1,65535);
    fdhz(48,285,2,2,"司",64384);
    fdhz(88,285,2,2,"机",64384);
    fdhz(128,285,2,2,"管",64384);
    fdhz(168,285,2,2,"理",64384);
	
	//退出登录
	bar_round(124,698,196,52,10,1,64384);
    bar_round(124,698,190,47,8,1,65535);
    fdhz(48,685,2,2,"退",64384);
    fdhz(88,685,2,2,"出",64384);
    fdhz(128,685,2,2,"登",64384);
    fdhz(168,685,2,2,"录",64384);
	
	//信息说明
	fdhz(307,60,2,2,"点击司机管理进入司机信息界面",64384);
	
}