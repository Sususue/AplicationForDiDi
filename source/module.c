#include "common.h"
#include "module.h"


void overflow_box(int x,int y)//当malloc分配空间失败时提示，回车退出系统
{
	bar_round(x,y+50,400,200,30,1,64384);
	bar_round(x,y+50,394,196,25,1,65535);
	

	fdhz(x-75,y+10,2,2,"内",0);
	fdhz(x-30,y+10,2,2,"存",0);
	fdhz(x+15,y+10,2,2,"溢",0);
	fdhz(x+60,y+10,2,2,"出",0);

	fdhz(x-85,y+53,2,2,"回车以退出",0);
	
}

void null_box(int x,int y)//当找不到相应文件路径时显示，回车退出系统
{
	bar_round(x,y+40,400,200,30,1,64384);
	bar_round(x,y+40,394,196,25,1,65535);

	fdhz(x-115,y-20,2,2,"找",0);
	fdhz(x-75,y-20,2,2,"不",0);
	fdhz(x-30,y-20,2,2,"到",0);
	fdhz(x+15,y-20,2,2,"该",0);
	fdhz(x+60,y-20,2,2,"路",0);
	fdhz(x+100,y-20,2,2,"径",0);
	
	fdhz(x-85,y+53,2,2,"回车以退出",0);
	
}