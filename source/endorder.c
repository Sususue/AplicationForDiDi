#include "common.h"
#include "endorder.h"




// 打车完成后生成订单
void neworder(int *x,int *y,USEINFOR *infor, const CARFAST car[], const char **placename, int *aimplace, int mincar, char *ordertime,float price)
{
    int button=0;
    int mx=0;
    int my=0;
    char chprice[8];
    ORDER *ordernew;
    
	if ((ordernew = (ORDER *)malloc(sizeof(ORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
    sprintf(chprice,"%.2f",price);

    save_image(83,109,683,659,"orderadd");

    mousehide(*x,*y);
    // 画图
    //返回键
    bar_round(976,664,76,44,15,1,64384);
    bar_round(976,664,70,39,13,1,65535);
    outtextxy(938,645,"Back",2,2,15,64384);

    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"订单",44373);
    bar(88,200,678,230,63422);



    //订单要截取的内容，最后一行传值

    linelevel(128,310,335,270,3,63422);
    linelevel(431,310,638,270,3,63422);
    fdhz(345,305,1,1,"订单详情",44373);

    fdhz(135,350,1,1,"订单类型",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"快车",44373);

    fdhz(390,350,1,1,"费用",44373);
    outtextxy(430,350,":",1,1,10,44373);
    outtextxy(445,350,chprice,1,1,10,44373);

    fdhz(135,390,1,1,"出发点",44373);
    outtextxy(195,390,":",1,1,10,44373);
    fdhz(210,390,1,1,placename[infor->nowplace],44373);

    fdhz(390,390,1,1,"目的地",44373);
    outtextxy(450,390,":",1,1,10,44373);
    fdhz(465,390,1,1,placename[*aimplace],44373);

    fdhz(135,430,1,1,"日期",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,ordertime,1,1,10,44373);

    linelevel(128,470,335,270,3,63422);
    linelevel(431,470,638,270,3,63422);
    fdhz(345,465,1,1,"司机信息",44373);

    fdhz(135,510,1,1,"司机",44373);
    outtextxy(175,510,":",1,1,10,44373);
    fdhz(190,510,1,1,car[mincar].name,44373);
    fdhz(210,510,1,1,"师傅",44373);

    fdhz(135,550,1,1,"车牌",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"鄂",44373);
    outtextxy(205,550,"A",1,1,10,44373);
    outtextxy(220,550,car[mincar].fastcar.carname,1,1,10,44373);

    fdhz(135,590,1,1,"车型",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,car[mincar].fastcar.type,44373);

    reset_mouse(x,y);
    strcpy(ordernew->name,car[mincar].name);
    strcpy(ordernew->carname,car[mincar].fastcar.carname);
    strcpy(ordernew->type,car[mincar].fastcar.type);
    strcpy(ordernew->startname,placename[infor->nowplace]);
    strcpy(ordernew->endname,placename[*aimplace]);
    strcpy(ordernew->money,chprice);
    strcpy(ordernew->orderstime,ordertime);
    // changeOrder(infor);//更改文件中的订单数量，以及生成本次订单的图片并保存
    addOrder(infor,ordernew);//将订单信息存进文件
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
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
    
    mousehide(*x,*y);
    printf_image(83,109,683,659,"orderadd");
    //对BACK键进行遮挡
    bar_round(976,664,76,44,15,1,65523);
    reset_mouse(x,y);

}


/*******************************
 基础里程：3km
 基础时长：9min
 里程计算方法：50像素点 = 1公里
               超出部分算作1公里
 时长计算方法：2min = 1s
               超出部分算作1分钟
 参数说明： timegap:用于是计算时间长度
			timegap=0:计算预计价格
			timegap!=0:计算最终价格
			
			timecase:用于判断价格计算方法
			timecase=0:计算预计价格 起步价11元，里程费1.8元/KM
			timecase=1: 0:00-9:00时段：起步价11元，里程费2.6元/KM，时长费0.5元/min
			timecase=2: 12:00-15:00时段：起步价11元，里程费1.8元/KM，时长费0.5元/min
			timecase=3: 17:00-00:00时段：起步价11元，里程费1.8元/KM，时长费0.5元/min
			timecase=4: 普通时段：起步价10.3元，里程费1.70元/KM,时长费0.35元/min
********************************/
void countprice(float *pointprice,int nowplace,int *aimplace,int timegap,int timecase)//用于计算价格
{
	int kilometer;//用于计算公里数
	int minite;//用于计算时间
	float startfare;//用于计算起步价
	int pointlength[15];//两点之间里程费数组
    int judging=0;//用于判断选择哪一个length

    pointlength[0]=507;//学校和小区之间
	pointlength[1]=690;//学校和东湖之间
	pointlength[2]=240;//学校和商场之间
	pointlength[3]=1000;//学校和图书馆之间
	pointlength[4]=553;//学校和游泳馆之间
	pointlength[5]=1012;//小区和东湖之间
	pointlength[6]=609;//小区和商场之间
	pointlength[7]=663;//小区和图书馆之间
	pointlength[8]=726;//小区和游泳馆之间
	pointlength[9]=646;//东湖和商场之间
	pointlength[10]=1086;//东湖和图书馆之间
	pointlength[11]=529;//东湖到游泳馆之间
	pointlength[12]=760;//商场和图书馆之间
	pointlength[13]=313;//商场和游泳馆之间
	pointlength[14]=557;//图书馆和游泳馆之间
	
	
	
	if((nowplace==0&&*aimplace==1)||(nowplace==1&&*aimplace==0))
	{
		judging=0;
	}
	else if((nowplace==0&&*aimplace==2)||(nowplace==2&&*aimplace==0))
	{
		judging=1;
	}
	else if((nowplace==0&&*aimplace==3)||(nowplace==3&&*aimplace==0))
	{
		judging=2;
	}
	else if((nowplace==0&&*aimplace==4)||(nowplace==4&&*aimplace==0))
	{
		judging=3;
	}
	else if((nowplace==0&&*aimplace==5)||(nowplace==5&&*aimplace==0))
	{
		judging=4;
	}
	else if((nowplace==1&&*aimplace==2)||(nowplace==2&&*aimplace==1))
	{
		judging=5;
	}
	else if((nowplace==1&&*aimplace==3)||(nowplace==3&&*aimplace==1))
	{
		judging=6;
	}
	else if((nowplace==1&&*aimplace==4)||(nowplace==4&&*aimplace==1))
	{
		judging=7;
	}
	else if((nowplace==1&&*aimplace==5)||(nowplace==5&&*aimplace==1))
	{
		judging=8;
	}
	else if((nowplace==2&&*aimplace==3)||(nowplace==3&&*aimplace==2))
	{
		judging=9;
	}
	else if((nowplace==2&&*aimplace==4)||(nowplace==4&&*aimplace==2))
	{
		judging=10;
	}
	else if((nowplace==2&&*aimplace==5)||(nowplace==5&&*aimplace==2))
	{
		judging=11;
	}
	else if((nowplace==3&&*aimplace==4)||(nowplace==4&&*aimplace==3))
	{
		judging=12;
	}
	else if((nowplace==3&&*aimplace==5)||(nowplace==5&&*aimplace==3))
	{
		judging=13;
	}
	else if((nowplace==4&&*aimplace==5)||(nowplace==5&&*aimplace==4))
	{
		judging=14;
	}
	
    //80像素点一公里
	kilometer=(pointlength[judging])/80+1-3;
	if(kilometer<0)
	{
		kilometer=0;
	}
	// minite=timegap/120+1-9;
    minite=timegap+1-9;//更改计时规则，一秒算一分钟
	if(minite<0)
	{
		minite=0;
	}
	
	switch(timecase)
	{
		case 0:
			startfare=11;
			*pointprice=startfare+kilometer*1.8;
			break;
		
		case 1:
			startfare=11;
			*pointprice=startfare+kilometer*2.6+minite*0.5;
			break;
		
		case 2:
		case 3:
			startfare=11;
			*pointprice=startfare+kilometer*1.8+minite*0.5;
			break;

		case 4:
			startfare=10.3;
			*pointprice=startfare+kilometer*1.7+minite*0.35;
			break;
	}

}
//完成订单后显示金额并确认支付
void costmoney(float *price,USEINFOR *infor,int *aimplace,int nowtime_hour,int timegap, int *x, int *y, int waitime)
{
    int timecase;
    char chprice[8];
    int mx=0;
    int my=0;
    int button=0;

    //根据时间段计费
    if (nowtime_hour >= 0 && nowtime_hour <= 8)
    {
        timecase = 1;
    }
    else if (nowtime_hour >= 12 && nowtime_hour <= 14)
    {
        timecase = 2;
    }
    
    else if (nowtime_hour >= 17 && nowtime_hour <= 23)
    {
        timecase = 3;
    }
    else 
    {
        timecase = 4;
    }
    countprice(price,infor->nowplace,aimplace,timegap,timecase);
    
    if (waitime != 0 && *price < 19.00)//如果是预约，预约基础费用为19.00
    {
        *price = 19.00;
    }
    if (infor->payway == 1)//若为余额支付打9折
    {
        *price=(*price)*0.9;
    }
    sprintf(chprice,"%.2f",*price);

    mousehide(*x,*y);
    save_image(512-210,384-140,512+210,384+140,"notice");
    //显示金额
    bar_round(512,384,416,270,50,1,64384);
    bar_round(512,384,410,265,48,1,65535);
    fdhz(410,360,2,2,"金额",64384);
	outtextxy(475,360,":",2,2,20,64384);
	outtextxy(500,360,chprice,2,2,20,64384);
    bar_round(512,460,190,52,20,1,64384);
    bar_round(512,460,184,47,18,1,65535);
	fdhz(466,446,2,2,"确",44373);
    fdhz(526,446,2,2,"定",44373);
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=417  && mx<=607 && my>=433 && my<=487 && button)//点击确定
        {
            break;
        }
        

    }
    mousehide(*x,*y);
    printf_image(512-210,384-140,512+210,384+140,"notice");
    reset_mouse(x,y);
    while (1)
    {
        if (infor->payway == 1)//支付方式为余额
        {
            if (infor->money>=*price)
            {
                changeMoney(infor,*price);
                mousehide(*x,*y);
                save_image(512-210,384-140,512+210,384+140,"notice");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(440,360,2,2,"支付完成",64384);
                fdhz(450,420,1,1,"按任意键继续",44373);
                
                getch();
                printf_image(512-210,384-140,512+210,384+140,"notice");
                reset_mouse(x,y);
                break;
            }
        
            else  //若余额不足
            {
                mousehide(*x,*y);
                save_image(512-210,384-140,512+210,384+140,"notice");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(440,360,2,2,"余额不足",64384);
                fdhz(450,420,1,1,"按任意键充值",44373);
                getch();
                reset_mouse(x,y);
                top_up(x,y,infor);
                printf_image(512-210,384-140,512+210,384+140,"notice");
                reset_mouse(x,y);
            }
        }
        else if (infor->payway == 2)//支付方式为微信
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            bar_round(255-30+160,480-100,70,70,22,1,2016);//微信绿
            FillCircle(221+160,480-100,20,65535);
            FillCircle(241+160,490-100,15,2016);
            FillCircle(241+160,490-100,13,65535);
            FillCircle(241-6+160,490-2-100,2,2016);
            FillCircle(241+6+160,490-2-100,2,2016);
            FillCircle(221-9+160,480-3-100,2,2016);
            FillCircle(221+9+160,480-3-100,2,2016);

            fdhz(440,360,2,2,"支付完成",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
            break;
        }
        else if (infor->payway == 3)//支付方式为支付宝
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            //画支付宝
            bar_round(510-30-95,480-100,70,70,22,1,1535);//支付宝蓝
            fdhz(455-95,450-100,4,4,"支",65535);

            fdhz(440,360,2,2,"支付完成",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
            break;
        }
        else      //若未选择支付方式则进入支付方式选择
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            fdhz(390,360,2,2,"未选择支付方式",64384);
            fdhz(450,420,1,1,"按任意键继续",44373);
            getch();
            reset_mouse(x,y);
            pay_way(x,y,infor);   
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
        }
        
    }
     
}