#include "common.h"
#include "useinfor.h"



/********************************************
个人信息相关函数
infor_box()
leading_box()
leading_fast()
leading_rent()
order_box()
showorder()
*********************************************/



void infor_box(int *x,int *y, USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //保存背景
    save_image(796,165,996,612,"carselect");
    //画图

    bar(796,166,996,612,65523);

    bar_round(896,198,196,52,20,1,64384);
    bar_round(896,198,190,47,18,1,65535);
    fdhz(850,184,2,2,"钱",64384);
    fdhz(910,184,2,2,"包",64384);


    bar_round(896,303,196,96,25,1,64384);
    bar_round(896,303,190,92,23,1,65535);
    fdhz(820,272,2,2,"手",64384);
    fdhz(860,272,2,2,"机",64384);
    fdhz(900,272,2,2,"号",64384);
    fdhz(940,272,2,2,"码",64384);
    outtextxy(803,310,infor->phone_num,2,2,15,64384);//显示手机号码

    bar_round(896,433,196,96,25,1,64384);
    bar_round(896,433,190,91,23,1,65535);
    fdhz(805,408,3,3,"订",64384);
    fdhz(850,408,3,3,"单",64384);
    fdhz(900,408,3,3,"查",64384);
    fdhz(945,408,3,3,"询",64384);

    bar_round(896,563,196,96,25,1,64384);
    bar_round(896,563,190,91,23,1,65535);
    fdhz(805,538,3,3,"用",64384);
    fdhz(850,538,3,3,"户",64384);
    fdhz(900,538,3,3,"指",64384);
    fdhz(945,538,3,3,"南",64384);


    //显示鼠标
    reset_mouse(x,y);

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
        else if (mx>=802  && mx<=994 && my>=172 && my<=224 && button)//点击钱包，弹出支付框
        {
            pay_box(x,y,infor);
        }
        else if (mx>=802  && mx<=994 && my>=515 && my<=611 && button )//点击用户指南，弹出相应信息框
        {

            leading_box(x,y);
        }
        else if (mx>=802  && mx<=994 && my>=385 && my<=481 && button )//点击订单查询，弹出相应信息框
        {

            order_box(x,y,infor);
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
    }

    //显示背景
    mousehide(*x,*y); 

    printf_image(796,165,996,612,"carselect");
    reset_mouse(x,y);
}


//用户指南弹出框
void leading_box(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);

    //保存背景
    save_image(83,109,683,659,"lead");

    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"用户指南",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);
    fdhz(200,285,2,2,"快车",44373);
    fdhz(200,423,2,2,"小桔租车",44373);
    // fdhz(200,565,2,2,"公交",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        
        else if(mx>=88 && mx<=678 && my>=231 && my<=367 && button)//快车指南
        {
            leading_fast(x,y);
            
        }
        else if(mx>=88 && mx<=678 && my>=369 && my<=509 && button)//小桔租车指南
        {
            leading_rent(x,y);
        }
        // else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//公交指南
        // {
        //     leading_bus(x,y);
        // }
        
    }

    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"lead");
    reset_mouse(x,y);
}


void leading_fast(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //保存背景
    save_image(88,231,678,637,"leadfast");
    //画图
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);

    fdhz(100,245,1,1,"快车计价规则",44373);

    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"实时用车",44373);

    fdhz(140,305,1,1,"时间段",44373);
    outtextxy(100,335,"00:00 - 09:00",1,1,10,44373);
    outtextxy(100,365,"12:00 - 15:00",1,1,10,44373);
    outtextxy(100,395,"17:00 - 00:00",1,1,10,44373);
    fdhz(125,425,1,1,"普通时段",44373);

    fdhz(300,305,1,1,"起步价",44373);
    outtextxy(350,305,"(",1,1,10,44373);
    outtextxy(380,305,")",1,1,10,44373);
    fdhz(367,305,1,1,"元",44373);
    outtextxy(300,335,"11.00",1,1,10,44373);
    outtextxy(300,365,"11.00",1,1,10,44373);
    outtextxy(300,395,"11.00",1,1,10,44373);
    outtextxy(300,425,"10.30",1,1,10,44373);

    fdhz(410,305,1,1,"里程费",44373);
    outtextxy(460,305,"(",1,1,10,44373);
    outtextxy(520,305,")",1,1,10,44373);
    fdhz(475,305,1,1,"元",44373);
    outtextxy(488,305,"/km",1,1,10,44373);
    outtextxy(430,335,"2.60",1,1,10,44373);
    outtextxy(430,365,"1.80",1,1,10,44373);
    outtextxy(430,395,"1.80",1,1,10,44373);
    outtextxy(430,425,"1.70",1,1,10,44373);

    fdhz(550,305,1,1,"时长费",44373);
    outtextxy(600,305,"(",1,1,10,44373);
    outtextxy(665,305,")",1,1,10,44373);
    fdhz(615,305,1,1,"元",44373);
    outtextxy(628,305,"/min",1,1,10,44373);
    outtextxy(570,335,"0.50",1,1,10,44373);
    outtextxy(570,365,"0.50",1,1,10,44373);
    outtextxy(570,395,"0.50",1,1,10,44373);
    outtextxy(570,425,"0.35",1,1,10,44373);

    fdhz(120,460,1,1,"起步价包含里程",44373);
    outtextxy(260,460,"3 km,",1,1,10,44373);
    fdhz(320,460,1,1,"包含时长",44373);
    outtextxy(395,460,"9 min",1,1,10,44373);
    fdhz(120,490,1,1,"超出部分",44373);
    outtextxy(195,490,",",1,1,10,44373);
    fdhz(215,490,1,1,"按照计价规则收费",44373);

    linelevel(88,525,335,525,3,63422);
    linelevel(431,525,678,525,3,63422);
    fdhz(345,520,1,1,"预约用车",44373);

    fdhz(120,560,1,1,"基础计价与实际用车计价保持一致",44373);
    fdhz(120,590,1,1,"基础费",44373);
    outtextxy(490,590,"19.00",1,1,10,44373);
    fdhz(550,590,1,1,"元",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        
    }

    //显示背景
    mousehide(*x,*y);   
    printf_image(88,231,678,637,"leadfast");
    reset_mouse(x,y);
}

void leading_rent(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //保存背景
    save_image(88,231,678,637,"leadrent");
    //画图
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"共享汽车",44373);

    fdhz(140,315,1,1,"请在指定站点内选车",44373);
    outtextxy(315,315,",",1,1,10,44373);
    fdhz(330,315,1,1,"下单即能立即用车",44373);

    fdhz(140,345,1,1,"车辆使用完毕后请在指定站定内停车",44373);

    fdhz(140,375,1,1,"租金按分钟计时收费",44373);

    outtextxy(340,375,"0.68",1,1,10,44373);
    fdhz(390,375,1,1,"元",44373);
    outtextxy(410,375,"/min",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)
        {
            break;
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        {
            exit(0);
        }
        
    }

    //显示背景
    mousehide(*x,*y);   
    printf_image(88,231,678,637,"leadrent");
    reset_mouse(x,y);
}

// void leading_bus(int *x,int *y)
// {
//     int button=0;
//     int mx=0;
//     int my=0;
//     mousehide(*x,*y);
//     //保存背景
//     save_image(88,231,678,637,"leadbus");
//     //画图
//     bar(88,231,678,580,65535);
//     bar(98,580,670,630,65535);

//     linelevel(88,270,335,270,3,63422);
//     linelevel(431,270,678,270,3,63422);
//     fdhz(345,265,1,1,"线路规划",44373);

//     fdhz(140,315,1,1,"如何选择更适合自己出行的方案",44373);
//     outtextxy(415,315,"?",1,1,10,44373);

//     fdhz(140,355,1,1,"在路线换乘页面",44373);
//     outtextxy(275,355,",",1,1,10,44373);
//     fdhz(290,355,1,1,"系统将默认展示到达目的地用时最短的",44373);
//     fdhz(140,385,1,1,"方案",44373);
//     fdhz(140,415,1,1,"您也可以选择",44373);
//     outtextxy(255,415,",",1,1,10,44373);
//     fdhz(270,415,1,1,"少换乘",44373);
//     outtextxy(325,415,",",1,1,10,44373);
//     fdhz(340,415,1,1,"少步行的推荐方案",44373);
//     outtextxy(495,415,",",1,1,10,44373);
//     fdhz(510,415,1,1,"从而选择更合",44373);
//     fdhz(140,445,1,1,"适的公交出行方案",44373);

//     lean_line_thick(608,143,30,45,3,64384);
// 	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

//     //显示鼠标
//     reset_mouse(x,y);

//     while (1)
//     {
//         newxy(x,y,&button);
// 		mx = *x;
// 		my = *y;
//         if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)
//         {
//             break;
//         }
//         else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
//         {
//             break;
//         }
//         else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
//         {
//             exit(0);
//         }
        
//     }

//     //显示背景
//     mousehide(*x,*y);   
//     printf_image(88,231,678,637,"leadbus");
//     reset_mouse(x,y);
// }



// void order_box(int *x,int *y,USEINFOR *infor)//存图形式显示订单
// {
//     int button=0;
//     int mx=0;
//     int my=0;
//     char *ordernum;//用于将int型转为字符串型
//     char *orderpage;
//     // int page=0;//用于记录当然订单在哪一页
//     int page = infor->num;//尝试逆序显示
//     char filename[20];//存名字
//     mousehide(*x,*y);
    
//     if((ordernum = (char *)malloc(sizeof(char)*4)) == NULL)
// 	{
// 		overflow_box(500,500);
// 		getch();
// 		exit(1);
// 	}
//     if((orderpage = (char *)malloc(sizeof(char)*4)) == NULL)
// 	{
// 		overflow_box(500,500);
// 		getch();
// 		exit(1);
// 	}
//     // changeOrder(infor);
//     // itoa(infor->num,change,10);
//     sprintf(ordernum,"%d",infor->num);
    
//     //保存背景
//     save_image(83,109,683,659,"order");

//     //画图
//     bar_round(383,384,596,546,50,1,64384);
//     bar_round(383,384,590,542,48,1,65535);
//     fdhz(272,135,3,3,"历史订单",44373);
//     bar(88,200,678,230,63422);
    
//     // linelevel(88,368,678,368,5,63422);
//     // linelevel(88,510,678,510,5,63422);
//     // fdhz(200,285,2,2,"快车",44373);
//     // fdhz(200,423,2,2,"小桔租车",44373);
//     // fdhz(200,565,2,2,"公交",44373);
    
//     // bar(96,300,670,630,0);
//     fdhz(135,250,1,1,"订单总数",44373);
//     outtextxy(215,250,":",1,1,10,44373);
//     outtextxy(230,250,ordernum,1,1,10,44373);
    
//     linelevel(88,275,335,270,3,63422);
//     linelevel(431,275,678,270,3,63422);
//     fdhz(350,265,1,1,"订单",44373);
//     // bar(390,265,430,290,0);//测试遮盖位置
//     // outtextxy(395,265,"12",1,1,10,44373);


//     //实验给图

//     // linelevel(128,310,335,310,3,63422);
//     // linelevel(431,310,638,310,3,63422);
//     // fdhz(345,305,1,1,"订单详情",44373);

//     // fdhz(135,350,1,1,"订单类型",44373);
//     // outtextxy(215,350,":",1,1,10,44373);
//     // fdhz(230,350,1,1,"快车",44373);

//     // fdhz(390,350,1,1,"费用",44373);
//     // outtextxy(430,350,":",1,1,10,44373);
//     // outtextxy(445,350,"10.00",1,1,10,44373);

//     // fdhz(135,390,1,1,"出发点",44373);
//     // outtextxy(195,390,":",1,1,10,44373);
//     // fdhz(210,390,1,1,"大学",44373);

//     // fdhz(390,390,1,1,"目的地",44373);
//     // outtextxy(450,390,":",1,1,10,44373);
//     // fdhz(465,390,1,1,"图书馆",44373);

//     // fdhz(135,430,1,1,"日期",44373);
//     // outtextxy(175,430,":",1,1,10,44373);
//     // outtextxy(190,430,"2019.10.26",1,1,10,44373);

//     // linelevel(128,470,335,270,3,63422);
//     // linelevel(431,470,638,270,3,63422);
//     // fdhz(345,465,1,1,"司机信息",44373);

//     // fdhz(135,510,1,1,"司机",44373);
//     // outtextxy(175,510,":",1,1,10,44373);
//     // fdhz(190,510,1,1,"张",44373);
//     // fdhz(210,510,1,1,"师傅",44373);

//     // fdhz(135,550,1,1,"车牌",44373);
//     // outtextxy(175,550,":",1,1,10,44373);
//     // fdhz(190,550,1,1,"鄂",44373);
//     // outtextxy(205,550,"A",1,1,10,44373);
//     // outtextxy(220,550,"7L27D",1,1,10,44373);

//     // fdhz(135,590,1,1,"车型",44373);
//     // outtextxy(175,590,":",1,1,10,44373);
//     // fdhz(190,590,1,1,"轩逸",44373);

//     // //显示第一个订单
//     // if (infor->num!=0)
//     // {
//     //     page++;
//     //     sprintf(filename,"%d_%d",infor->cnt,page);
// 	//     printf_image(96,300,670,630,filename);
//     //     //显示第几个订单
//     //     sprintf(orderpage,"%d",page);
//     //     bar(390,265,430,290,65535);
//     //     outtextxy(395,265,orderpage,1,1,10,44373);
//     //     //左右键
//     //     // outtextxy(135,610,"<",2,2,10,44373);
//     //     if (infor->num>1)
//     //     {
//     //         outtextxy(626,610,">",2,2,10,44373);
//     //     }
        
        
//     // }
//     //显示最后一个订单(尝试逆序显示)
//     if (infor->num!=0)
//     {
//         // page++;
//         sprintf(filename,"%d_%d",infor->cnt,page);
// 	    printf_image(96,300,670,630,filename);
//         //显示第几个订单
//         sprintf(orderpage,"%d",page);
//         bar(390,265,430,290,65535);
//         outtextxy(395,265,orderpage,1,1,10,44373);
//         //左右键
//         // outtextxy(135,610,"<",2,2,10,44373);
//         if (infor->num>1)
//         {
//             outtextxy(626,610,">",2,2,10,44373);
//         }
        
        
//     }
    
//     // bar(140,610,170,640,0);//判断点击区域
//     // bar(630,610,660,640,0);
//     // outtextxy(135,610,"<",2,2,10,44373);
//     // outtextxy(626,610,">",2,2,10,44373);


//     // 暂时看一下值是否正确
//     // outtextxy(415,385,ordernum,1,1,10,44373);
//     // outtextxy(415,355,ordercnt,1,1,10,44373);
//     // outtextxy(415,315,infor->phone_num,1,1,10,44373);

//     //显示鼠标
//     reset_mouse(x,y);

//     while (1)
//     {
//         newxy(x,y,&button);
// 		mx = *x;
// 		my = *y;
//         if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
//         {
//             break;
//         }
//         else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//  点击ESC退出系统
//         {
//             exit(0);
//         }
//         //顺序显示订单
//         // else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
//         // {
//         //     page++;
//         //     sprintf(filename,"%d_%d",infor->cnt,page);
//         //     mousehide(*x,*y);
// 	    //     printf_image(96,300,670,630,filename);
//         //     bar(630,610,660,640,65535);//遮盖右侧箭头
//         //     //左右键
//         //     outtextxy(135,610,"<",2,2,10,44373);
//         //     if (page < infor->num)
//         //     {
//         //         outtextxy(626,610,">",2,2,10,44373);
//         //     }
//         //     //显示第几个订单
//         //     sprintf(orderpage,"%d",page);
//         //     bar(390,265,430,290,65535);
//         //     outtextxy(395,265,orderpage,1,1,10,44373);
//         //     reset_mouse(x,y);
//         // }
//         // else if (page>1 && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
//         // {
//         //     page--;
//         //     sprintf(filename,"%d_%d",infor->cnt,page);
//         //     mousehide(*x,*y);
// 	    //     printf_image(96,300,670,630,filename);
//         //     bar(140,610,170,640,65535);//遮盖左侧箭头
//         //     //左右键
            
//         //     outtextxy(626,610,">",2,2,10,44373);
//         //     if (page > 1)
//         //     {
//         //         outtextxy(135,610,"<",2,2,10,44373);
//         //     }
//         //     //显示第几个订单
//         //     sprintf(orderpage,"%d",page);
//         //     bar(390,265,430,290,65535);
//         //     outtextxy(395,265,orderpage,1,1,10,44373);
//         //     reset_mouse(x,y);
//         // }
//         //尝试逆序显示订单
//         else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
//         {
//             page--;
//             sprintf(filename,"%d_%d",infor->cnt,page);
//             mousehide(*x,*y);
// 	        printf_image(96,300,670,630,filename);
//             bar(630,610,660,640,65535);//遮盖右侧箭头
//             //左右键
//             outtextxy(135,610,"<",2,2,10,44373);
//             if (page > 1)
//             {
//                 outtextxy(626,610,">",2,2,10,44373);
//             }
//             //显示第几个订单
//             sprintf(orderpage,"%d",page);
//             bar(390,265,430,290,65535);
//             outtextxy(395,265,orderpage,1,1,10,44373);
//             reset_mouse(x,y);
//         }
//         else if (page < infor->num && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
//         {
//             page++;
//             sprintf(filename,"%d_%d",infor->cnt,page);
//             mousehide(*x,*y);
// 	        printf_image(96,300,670,630,filename);
//             bar(140,610,170,640,65535);//遮盖左侧箭头
//             //左右键
            
//             outtextxy(626,610,">",2,2,10,44373);
//             if (page < infor->num)
//             {
//                 outtextxy(135,610,"<",2,2,10,44373);
//             }
//             //显示第几个订单
//             sprintf(orderpage,"%d",page);
//             bar(390,265,430,290,65535);
//             outtextxy(395,265,orderpage,1,1,10,44373);
//             reset_mouse(x,y);
//         }
//     }
//     free(ordernum);
//     free(orderpage);
//     ordernum=NULL;
//     orderpage=NULL;
//     // 显示背景
//     mousehide(*x,*y);   
//     printf_image(83,109,683,659,"order");
//     reset_mouse(x,y);
// }

void order_box(int *x,int *y,USEINFOR *infor)//显示订单
{
    int button=0;
    int mx=0;
    int my=0;
    char ch[7];
    mousehide(*x,*y);
    
    
    //保存背景
    save_image(83,109,683,659,"order");

    //画图
	bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
	fdhz(272,135,3,3,"历史订单",44373);
    bar(88,200,678,230,63422);

    

    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    
    fdhz(200,285,2,2,"订单总数",44373);
    sprintf(ch,"%d",infor->num+infor->rentnum);
    outtextxy(380,285,ch,2,2,20,44373);
    fdhz(200,423,2,2,"快车订单",44373);
    fdhz(200,565,2,2,"租车订单",44373);

	lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

	 while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;

        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
		if (mx>=88 && mx<=678 && my>=369 && my<=509 && button)//点击快车进入快车历史订单查询
        {
            fastorder(x,y,infor);
            
        }
        else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//点击小桔租车进入租车历史订单查询
        {
            rentorder(x,y,infor);
        }
		else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回

        {
            break;
        }
    }
    
    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"order");
    reset_mouse(x,y);
}

void fastorder(int *x,int *y,USEINFOR *infor)//读取文件形式显示订单
{
    int button=0;
    int mx=0;
    int my=0;
    char *ordernum;//用于将int型转为字符串型
    char *orderpage;
    // int page=0;//用于记录当然订单在哪一页
    int page = infor->num;//尝试逆序显示
    char filename[20];//存名字
    ORDER *order;
    mousehide(*x,*y);
    
    if((ordernum = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if((orderpage = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if ((order = (ORDER *)malloc(sizeof(ORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
  
    sprintf(ordernum,"%d",infor->num);
    
    //保存背景
    save_image(83,109,683,659,"faorder");

    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"历史订单",44373);
    bar(88,200,678,230,63422);
    
    
    // bar(96,300,670,630,0);
    fdhz(135,250,1,1,"快车订单",44373);
    outtextxy(215,250,":",1,1,10,44373);
    outtextxy(230,250,ordernum,1,1,10,44373);
    
    linelevel(88,275,335,270,3,63422);
    linelevel(431,275,678,270,3,63422);
    fdhz(350,265,1,1,"订单",44373);
    // bar(390,265,430,290,0);//测试遮盖位置
    // outtextxy(395,265,"12",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    // 实验给图
    
    
    // //显示第一个订单
    // if (infor->num!=0)
    // {
    //     page++;
    //     sprintf(filename,"%d_%d",infor->cnt,page);
	//     printf_image(96,300,670,630,filename);
    //     //显示第几个订单
    //     sprintf(orderpage,"%d",page);
    //     bar(390,265,430,290,65535);
    //     outtextxy(395,265,orderpage,1,1,10,44373);
    //     //左右键
    //     // outtextxy(135,610,"<",2,2,10,44373);
    //     if (infor->num>1)
    //     {
    //         outtextxy(626,610,">",2,2,10,44373);
    //     }
        
        
    // }
    //显示最后一个订单(尝试逆序显示)
    if (infor->num!=0)
    {
        
        findOrder(infor,order,page);
        //显示第几个订单
        sprintf(orderpage,"%d",page);
        bar(390,265,430,290,65535);
        outtextxy(395,265,orderpage,1,1,10,44373);
        
        //显示订单信息
        showorder(order);

        //左右键
        // outtextxy(135,610,"<",2,2,10,44373);
        if (infor->num>1)
        {
            outtextxy(626,610,">",2,2,10,44373);
        }
        
        
    }
    
    // bar(140,610,170,640,0);//判断点击区域
    // bar(630,610,660,640,0);
    // outtextxy(135,610,"<",2,2,10,44373);
    // outtextxy(626,610,">",2,2,10,44373);


    // 暂时看一下值是否正确
    // outtextxy(415,385,ordernum,1,1,10,44373);
    // outtextxy(415,355,ordercnt,1,1,10,44373);
    // outtextxy(415,315,infor->phone_num,1,1,10,44373);

    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//  点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        //顺序显示订单
        // else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
        // {
        //     page++;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(630,610,660,640,65535);//遮盖右侧箭头
        //     //左右键
        //     outtextxy(135,610,"<",2,2,10,44373);
        //     if (page < infor->num)
        //     {
        //         outtextxy(626,610,">",2,2,10,44373);
        //     }
        //     //显示第几个订单
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        // else if (page>1 && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
        // {
        //     page--;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(140,610,170,640,65535);//遮盖左侧箭头
        //     //左右键
            
        //     outtextxy(626,610,">",2,2,10,44373);
        //     if (page > 1)
        //     {
        //         outtextxy(135,610,"<",2,2,10,44373);
        //     }
        //     //显示第几个订单
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        //尝试逆序显示订单
        else if (page>1 && page<=infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
        {
            page--;
            findOrder(infor,order,page);
            mousehide(*x,*y);
            //显示信息
	        showorder(order);
            bar(630,610,660,640,65535);//遮盖右侧箭头
            //左右键
            outtextxy(135,610,"<",2,2,10,44373);
            if (page > 1)
            {
                outtextxy(626,610,">",2,2,10,44373);
            }
            //显示第几个订单
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
        else if (page < infor->num && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
        {
            page++;
            findOrder(infor,order,page);
            mousehide(*x,*y);
            //显示信息
	        showorder(order);
            bar(140,610,170,640,65535);//遮盖左侧箭头
            //左右键
            
            outtextxy(626,610,">",2,2,10,44373);
            if (page < infor->num)
            {
                outtextxy(135,610,"<",2,2,10,44373);
            }
            //显示第几个订单
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
    }
    free(ordernum);
    free(orderpage);
    free(order);
    ordernum=NULL;
    orderpage=NULL;
    order=NULL;
    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"faorder");
    reset_mouse(x,y);
}

void rentorder(int *x,int *y,USEINFOR *infor)//读取文件形式显示租车订单
{
    int button=0;
    int mx=0;
    int my=0;
    char *ordernum;//用于将int型转为字符串型
    char *orderpage;
    // int page=0;//用于记录当然订单在哪一页
    int page = infor->rentnum;//尝试逆序显示
    char filename[20];//存名字
    RENTORDER *order;
    mousehide(*x,*y);
    
    if((ordernum = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if((orderpage = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if ((order = (RENTORDER *)malloc(sizeof(RENTORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
  
    sprintf(ordernum,"%d",infor->rentnum);
    
    //保存背景
    save_image(83,109,683,659,"reorder");

    //画图
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"历史订单",44373);
    bar(88,200,678,230,63422);
    
    
    // bar(96,300,670,630,0);
    fdhz(135,250,1,1,"租车订单",44373);
    outtextxy(215,250,":",1,1,10,44373);
    outtextxy(230,250,ordernum,1,1,10,44373);
    
    linelevel(88,275,335,270,3,63422);
    linelevel(431,275,678,270,3,63422);
    fdhz(350,265,1,1,"订单",44373);
    // bar(390,265,430,290,0);//测试遮盖位置
    // outtextxy(395,265,"12",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉

    // 实验给图
    
    
    // //显示第一个订单
    // if (infor->num!=0)
    // {
    //     page++;
    //     sprintf(filename,"%d_%d",infor->cnt,page);
	//     printf_image(96,300,670,630,filename);
    //     //显示第几个订单
    //     sprintf(orderpage,"%d",page);
    //     bar(390,265,430,290,65535);
    //     outtextxy(395,265,orderpage,1,1,10,44373);
    //     //左右键
    //     // outtextxy(135,610,"<",2,2,10,44373);
    //     if (infor->num>1)
    //     {
    //         outtextxy(626,610,">",2,2,10,44373);
    //     }
        
        
    // }
    //显示最后一个订单(尝试逆序显示)
    if (infor->rentnum!=0)
    {
        
        findRentOrder(infor,order,page);
        //显示第几个订单
        sprintf(orderpage,"%d",page);
        bar(390,265,430,290,65535);
        outtextxy(395,265,orderpage,1,1,10,44373);
        
        //显示订单信息
        showrentorder(order);

        //左右键
        // outtextxy(135,610,"<",2,2,10,44373);
        if (infor->rentnum>1)
        {
            outtextxy(626,610,">",2,2,10,44373);
        }
        
        
    }
    
    // bar(140,610,170,640,0);//判断点击区域
    // bar(630,610,660,640,0);
    // outtextxy(135,610,"<",2,2,10,44373);
    // outtextxy(626,610,">",2,2,10,44373);


    // 暂时看一下值是否正确
    // outtextxy(415,385,ordernum,1,1,10,44373);
    // outtextxy(415,355,ordercnt,1,1,10,44373);
    // outtextxy(415,315,infor->phone_num,1,1,10,44373);

    //显示鼠标
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//  点击ESC退出系统
        {
            exit(0);
        }
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//点击红叉返回
        {
            break;
        }
        //顺序显示订单
        // else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
        // {
        //     page++;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(630,610,660,640,65535);//遮盖右侧箭头
        //     //左右键
        //     outtextxy(135,610,"<",2,2,10,44373);
        //     if (page < infor->num)
        //     {
        //         outtextxy(626,610,">",2,2,10,44373);
        //     }
        //     //显示第几个订单
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        // else if (page>1 && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
        // {
        //     page--;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(140,610,170,640,65535);//遮盖左侧箭头
        //     //左右键
            
        //     outtextxy(626,610,">",2,2,10,44373);
        //     if (page > 1)
        //     {
        //         outtextxy(135,610,"<",2,2,10,44373);
        //     }
        //     //显示第几个订单
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        //尝试逆序显示订单
        else if (page>1 && page<=infor->rentnum && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//点击>查看下一页订单
        {
            page--;
            findRentOrder(infor,order,page);
            mousehide(*x,*y);
            //显示信息
	        showrentorder(order);
            bar(630,610,660,640,65535);//遮盖右侧箭头
            //左右键
            outtextxy(135,610,"<",2,2,10,44373);
            if (page > 1)
            {
                outtextxy(626,610,">",2,2,10,44373);
            }
            //显示第几个订单
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
        else if (page < infor->rentnum && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//点击<查看上一页订单
        {
            page++;
            findRentOrder(infor,order,page);
            mousehide(*x,*y);
            //显示信息
	        showrentorder(order);
            bar(140,610,170,640,65535);//遮盖左侧箭头
            //左右键
            
            outtextxy(626,610,">",2,2,10,44373);
            if (page < infor->rentnum)
            {
                outtextxy(135,610,"<",2,2,10,44373);
            }
            //显示第几个订单
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
    }
    free(ordernum);
    free(orderpage);
    free(order);
    ordernum=NULL;
    orderpage=NULL;
    order=NULL;
    //显示背景
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"reorder");
    reset_mouse(x,y);
}

void showorder(ORDER *order)
{
    bar(96,300,670,630,65535);

    linelevel(128,310,335,310,3,63422);
    linelevel(431,310,638,310,3,63422);
    fdhz(345,305,1,1,"订单详情",44373);

    fdhz(135,350,1,1,"订单类型",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"快车",44373);

    fdhz(390,350,1,1,"费用",44373);
    outtextxy(430,350,":",1,1,10,44373);
    outtextxy(445,350,order->money,1,1,10,44373);

    fdhz(135,390,1,1,"出发点",44373);
    outtextxy(195,390,":",1,1,10,44373);
    fdhz(210,390,1,1,order->startname,44373);

    fdhz(390,390,1,1,"目的地",44373);
    outtextxy(450,390,":",1,1,10,44373);
    fdhz(465,390,1,1,order->endname,44373);

    fdhz(135,430,1,1,"日期",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,order->orderstime,1,1,10,44373);

    linelevel(128,470,335,270,3,63422);
    linelevel(431,470,638,270,3,63422);
    fdhz(345,465,1,1,"司机信息",44373);

    fdhz(135,510,1,1,"司机",44373);
    outtextxy(175,510,":",1,1,10,44373);
    fdhz(190,510,1,1,order->name,44373);
    fdhz(210,510,1,1,"师傅",44373);

    fdhz(135,550,1,1,"车牌",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"鄂",44373);
    outtextxy(205,550,"A",1,1,10,44373);
    outtextxy(220,550,order->carname,1,1,10,44373);

    fdhz(135,590,1,1,"车型",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,order->type,44373);

}
//显示租车订单内容
void showrentorder(RENTORDER *order)
{
    bar(96,300,670,630,65535);

    linelevel(128,310,335,270,3,63422);
    linelevel(431,310,638,270,3,63422);
    fdhz(345,305,1,1,"订单详情",44373);

    fdhz(135,350,1,1,"订单类型",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"租车",44373);

    fdhz(135,390,1,1,"总时长",44373);
    outtextxy(195,390,":",1,1,10,44373);
    outtextxy(210,390,order->during,1,1,10,44373);
    fdhz(250,390,1,1,"分钟",44373);
    
    fdhz(135,430,1,1,"费用",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,order->money,1,1,10,44373);
    fdhz(250,430,1,1,"元",44373);
	
    fdhz(135,470,1,1,"日期",44373);
    outtextxy(175,470,":",1,1,10,44373);
    outtextxy(190,470,order->orderstime,1,1,10,44373);
	 
    linelevel(128,510,335,510,3,63422);
    linelevel(431,510,638,510,3,63422);
    fdhz(345,505,1,1,"车辆信息",44373);

    fdhz(135,550,1,1,"车牌",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"鄂",44373);
    outtextxy(205,550,"AD",1,1,10,44373);
    outtextxy(230,550,order->carname,1,1,10,44373);

    fdhz(135,590,1,1,"车型",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,"东风",44373);

}