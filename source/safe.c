#include "common.h"
#include "safe.h"


void safe_box(int* x, int* y, int *sigle)
{
    int button=0;
    int mx=0;
    int my=0;
    // int sigle = 0;//避免重复报警
   
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
        if(mx>= 362 && mx<=662 && my>=300 && my<=400 && button && *sigle!=1)//点击报警
        {

            *sigle=1;         //避免重复报警
            bar_round(512,350,300,100,45,1,63488);
            bar_round(512,350,294,95,43,1,65535);
            fdhz(395,330,3,3,"报警成功",63488);
            reset_mouse(x,y);   //避免留下鼠标所在位置的背景
            
        }
        
    }

    mousehide(*x,*y);  //隐藏鼠标
    if (*sigle == 1)
    {
        bar_round(512,350,300,100,45,1,63488);
        bar_round(512,350,294,95,43,1,65535);
        fdhz(395,330,3,3,"警察出警",63488);
        delay(1000);
    }
    printf_image(512-210,384-140,512+210,384+140,"safe");
    
    
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景
    
    // return sigle;

}
int catchBox(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    int flag = 0;
    mousehide(*x,*y);

    save_image(83,109,683,659,"catch");

    //画图
    bar_round(383,384,416,270,50,1,64384);
    bar_round(383,384,410,265,48,1,65535);
    fdhz(311,360,2,2,"警察到达",64384);
    fdhz(331,430,1,1,"按任意键继续",44373);
    getch();

    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(230,145,2,2,"请选择你遇到的问题",44373);
    bar(88,200,678,230,63422);

    linelevel(88,290,678,368,4,63422);
    linelevel(88,360,678,368,4,63422);
    linelevel(88,430,678,510,4,63422);
    linelevel(88,500,678,368,4,63422);
	linelevel(88,570,678,368,4,63422);


    fdhz(140,260,1,1,"遭遇性骚扰或者性侵",44373);
    fdhz(140,330,1,1,"与他人发生肢体冲突",44373);
	fdhz(140,400,1,1,"被限制人身自由",44373);
    fdhz(140,470,1,1,"遭遇其他人身伤害",44373);
	fdhz(140,540,1,1,"遇到其他问题",44373);
    
    FillCircle(500,270,14,44373);
    FillCircle(500,270,12,65535);
    FillCircle(500,340,14,44373);
    FillCircle(500,340,12,65535);
    FillCircle(500,410,14,44373);
    FillCircle(500,410,12,65535);
    FillCircle(500,480,14,44373);
    FillCircle(500,480,12,65535);
    FillCircle(500,550,14,44373);
    FillCircle(500,550,12,65535);

    bar_round(383,620,196,52,20,1,44373);
    bar_round(383,620,190,47,18,1,65535);
    fdhz(337,606,2,2,"确",44373);
    fdhz(397,606,2,2,"定",44373);

//  lean_line_thick(608,143,30,45,3,64384);
// 	lean_line_thick(608,143+20,30,-45,3,64384);//画红叉
    
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        // if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//点击Back返回
        // {
        //     break;
        // }
        // else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//点击ESC退出系统
        // {
        //     exit(0);
        // }
        if(mx>=88 && mx<=678 && my>=230 && my<=290 && button)//第一个
        {
            flag = 2;     
            mousehide(*x,*y);
            FillCircle(500,270,12,64384);
            FillCircle(500,340,12,65535);         
            FillCircle(500,410,12,65535);        
            FillCircle(500,480,12,65535);       
            FillCircle(500,550,12,65535);
            reset_mouse(x,y);
        }
        else if(mx>=88 && mx<=678 && my>=290 && my<=360 && button)
        {
            flag = 3;
            mousehide(*x,*y);
            FillCircle(500,270,12,65535);
            FillCircle(500,340,12,64384);          
            FillCircle(500,410,12,65535);         
            FillCircle(500,480,12,65535);        
            FillCircle(500,550,12,65535);
            reset_mouse(x,y);
        }
        else if(mx>=88 && mx<=678 && my>=360 && my<=430 && button)
        {
            flag = 4;
            mousehide(*x,*y);
            FillCircle(500,270,12,65535);
            FillCircle(500,340,12,65535);          
            FillCircle(500,410,12,64384);          
            FillCircle(500,480,12,65535);          
            FillCircle(500,550,12,65535);
            reset_mouse(x,y);
        }
        else if(mx>=88 && mx<=678 && my>=430 && my<=500 && button)
        {
            flag = 5;
            mousehide(*x,*y);
            FillCircle(500,270,12,65535);
            FillCircle(500,340,12,65535);          
            FillCircle(500,410,12,65535);          
            FillCircle(500,480,12,64384);          
            FillCircle(500,550,12,65535);
            reset_mouse(x,y);
        }
        else if(mx>=88 && mx<=678 && my>=500 && my<=570 && button)
        {
            flag = 6;
            mousehide(*x,*y);
            FillCircle(500,270,12,65535);
            FillCircle(500,340,12,65535);
            FillCircle(500,410,12,65535);          
            FillCircle(500,480,12,65535);          
            FillCircle(500,550,12,64384);
            reset_mouse(x,y);
        }
        else if (mx>=285  && mx<=481 && my>=593 && my<=647 && button)//点击确定
        {
            if (flag != 0)
            {
                mousehide(*x,*y);
                
                bar_round(383,620,196,52,20,1,64384);
                bar_round(383,620,190,47,18,1,65535);
                fdhz(337,606,2,2,"确",64384);
                fdhz(397,606,2,2,"定",64384);
                delay(50);
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(241,360,2,2,"警察核实情况中",64384);
                delay(2000);
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(311,330,2,2,"核实成功",64384); 
                fdhz(260,380,2,2,"司机已被处理",64384);
                fdhz(331,430,1,1,"按任意键继续",44373);
                getch();

                reset_mouse(x,y);
    
                break;
            }
            else
            {
                mousehide(*x,*y);
                save_image(383-210,384-140,383+210,384+140,"not");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(241,340,2,2,"请选择遇到问题",64384);
                fdhz(331,430,1,1,"按任意键继续",44373);
                getch();
                printf_image(383-210,384-140,383+210,384+140,"not");
                reset_mouse(x,y);
            } 
        }
        
    }
 
    mousehide(*x,*y);  //隐藏鼠标
    printf_image(83,109,683,659,"catch");
    reset_mouse(x,y);   //避免留下鼠标所在位置的背景 
    return flag;
}


// 更改司机状态为不能接单
void changecall(CARFA *thiscar , int callstyle)
{
 
    FILE *fp = NULL;

    // 修改状态
    thiscar->call = callstyle;
    if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 
    
    
    fseek(fp,sizeof(CARFA)*thiscar->order,SEEK_SET);
    fwrite(thiscar,sizeof(CARFA),1,fp);
   
    fclose(fp);

    if ((fp = fopen("driver\\fastcar.txt", "rb+")) == NULL)//更改资源库的信息
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 

    fseek(fp,sizeof(CARFA)*thiscar->number,SEEK_SET);
    fwrite(thiscar,sizeof(CARFA),1,fp);


    // fseek(fp,0L,SEEK_SET);
    // fread(thiscar,sizeof(CARFA),1,fp);
    fclose(fp);

    
}