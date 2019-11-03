#include "common.h"
#include "map.h"

/********************************************

*********************************************/

void mapdraw(void)
{
    bar(1,1,1023,767,65535); //设置背景为白色
    //地图大致街区方块

    //方形分区
    bar(61,480,453,704,57083);//左下块
    
    bar(2,479,30,766,57083);//左下角
    bar(30,736,453,766,57083);
   
    bar(483,284,700,704,57083);//右下块
 
    bar(730,284,765,766,57083);//右下角
    bar(483,736,730,766,57083);
 
    bar(287,40,766,253,57083);//右上块
    
    bar(2,40,257,450,57083);//左上块
   
    bar(2,2,386,10,57083);//上方
    
    bar(386,2,425,41,57083);//靠近湖的位置

    //中间矩形
    bar(257,254,483,479,65535);
    bar(287,284,453,449,57083);

    //马路箭头

    //画湖
    filllake(642,0,250,44796,51);

    //背景分区橙色边框
    rectangle(769,0,1023,768,2,64384); //选择界面
    rectangle(1,0,767,768,2,64384);//地图区域

    //写地点的名称
	fdhz(375,45,1,1,"东湖",0);
	fdhz(415,220,1,1,"游泳馆",1);
	fdhz(145,420,1,1,"学校",1);
	fdhz(227,674,1,1,"小区",1);
	fdhz(375,500,1,1,"商场",1);
	fdhz(640,570,1,1,"图书馆",1);

    // //上下车点
    // FillCircle(395,25,3,0);//东湖
    // FillCircle(212,695,3,0);//小区
    // FillCircle(130,440,3,0);//学校
    // FillCircle(370,490,3,0);//商场
    // FillCircle(686,560,3,0);//图书馆
    // FillCircle(450,243,3,0);//游泳馆

}

//右侧选择框
//void select(unsigned int *carbox)
void select(void)
{
    //底色
    bar(771,2,1021,765,65523);
    //头像
    FillCircle(896,90,59,65535);
    circle(896,90,59,64384);
    circle(896,90,60,64384);
    circle(896,90,61,64384);
    FillCircle(896,80,20,64384);
    bar_round(896,118,80,25,8,1,64384);
    //个人信息
    bar_round(896,198,196,52,20,1,64384);
    bar_round(896,198,190,47,18,1,65535);
    fdhz(820,184,2,2,"个",64384);
    fdhz(860,184,2,2,"人",64384);
    fdhz(900,184,2,2,"信",64384);
    fdhz(940,184,2,2,"息",64384);

    //车辆选择
    //底色
    bar(780,250,1015,645,65523);
    //按钮
    bar_round(896,303,196,96,25,1,64384);
    bar_round(896,303,190,91,23,1,65535);
    fdhz(840,280,3,3,"快",64384);
    fdhz(900,280,3,3,"车",64384);

    bar_round(896,433,196,96,25,1,64384);
    bar_round(896,433,190,91,23,1,65535);
    fdhz(805,408,3,3,"小",64384);
    fdhz(850,408,3,3,"桔",64384);
    fdhz(900,408,3,3,"租",64384);
    fdhz(945,408,3,3,"车",64384);

    bar_round(896,563,196,96,25,1,64384);
    bar_round(896,563,190,91,23,1,65535);
    fdhz(840,538,3,3,"公",64384);
    fdhz(900,538,3,3,"交",64384);

    //安全
    bar_round(862,693,120,92,25,1,64384);
    bar_round(862,693,114,85,23,1,65535);
    fdhz(815,668,3,3,"安",64384);
    fdhz(860,668,3,3,"全",64384);

    //退出键
    bar_round(976,715,60,44,15,1,64384);
    bar_round(976,715,54,39,13,1,65535);
    outtextxy(945,699,"ESC",2,2,15,64384);

    //返回键
    bar_round(976,664,76,44,15,1,64384);
    bar_round(976,664,70,39,13,1,65535);
    outtextxy(938,645,"Back",2,2,15,64384);
}




//存储按钮的位置坐标
char selectbutton(int *mx,int *my,int button)
{
    char clicksign = 0; //作为返回值
    int a[7][4];
    //a[0][]:点击esc退出
    a[0][0]=976-30; 
    a[0][1]=976+30;
    a[0][2]=715-22;
    a[0][3]=715+22;
    //	a[1][]:点击安全
    a[1][0]=862-60;  
    a[1][1]=862+60;
    a[1][2]=693-46;
    a[1][3]=693+46;
    //	a[2][]:点击个人信息
    a[2][0]=896-98; 
    a[2][1]=896+98;
    a[2][2]=198-26;
    a[2][3]=198+26; 
    // a[3][]:点击快车
    a[3][0]=896-92; 
    a[3][1]=896+92;
    a[3][2]=303-48;
    a[3][3]=303+48;
    // a[4][]:点击小桔租车
    a[4][0]=896-92; 
    a[4][1]=896+92;
    a[4][2]=433-48;
    a[4][3]=433+48;
    //  a[5][]:点击公交
    a[5][0]=896-92; 
    a[5][1]=896+92;
    a[5][2]=563-48;
    a[5][3]=563+48;
    // a[6][]:点击Back
    a[6][0]=976-38; 
    a[6][1]=976+38;
    a[6][2]=664-22;
    a[6][3]=664+22;

    if (*mx>=a[0][0] && *mx<=a[0][1] && *my>=a[0][2] && *my<=a[0][3] && button)
    {
        clicksign = 1;  //点击esc退出
    }
    else if (*mx>=a[1][0] && *mx<=a[1][1] && *my>=a[1][2] && *my<=a[1][3] && button)
    {
        clicksign = 2;  //点击安全
    }
    else if (*mx>=a[2][0] && *mx<=a[2][1] && *my>=a[2][2] && *my<=a[2][3] && button)
    {
        clicksign = 3;  //点击个人信息
    }
    else if (*mx>=a[3][0] && *mx<=a[3][1] && *my>=a[3][2] && *my<=a[3][3] && button)
    {
        clicksign = 4;  //点击快车
    }
    else if (*mx>=a[4][0] && *mx<=a[4][1] && *my>=a[4][2] && *my<=a[4][3] && button)
    {
        clicksign = 5;  //点击小桔租车
    }
    else if (*mx>=a[5][0] && *mx<=a[5][1] && *my>=a[5][2] && *my<=a[5][3] && button)
    {
        clicksign = 6;  //点击公交
    }
    else if (*mx>=a[6][0] && *mx<=a[6][1] && *my>=a[6][2] && *my<=a[6][3] && button)
    {
        clicksign = 7;  //点击Back返回登录界面
    }
    else if (button)
    {
        clicksign = 8;  //点击其他位置
    }
    
    return clicksign;

}