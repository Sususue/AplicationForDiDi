#include "common.h"
#include "main.h"



void main()
{
	
	unsigned int a;
	int enterjudge=0;//判断进入登录页面还是进入主界面
	//int finish=0;
	int x,y,button;//
	USER user;
	USER *p_user= &user;
	USEINFOR order;
	USEINFOR *p_order= &order;

	SetSVGA64k();
	
	
	a = GetSVGA();
	
	srand((int)time(0));
	
	outwelcome();
	getch();
	
	mouseInit(&x, &y,&button);

	while (1)
	{
		switch (enterjudge)
		{
			case 0:
					enterjudge = enterpage(p_user,p_order,&x,&y);
					break;
			case 1:
					enterjudge = check(p_order,&x,&y);
					// enterjudge = check(p_user,&x,&y);
			default:
					break;
		}
	}
	
	
	/*
	while(enterjudge!=1)
	{
		enterjudge = enterpage(p_user);
	}
	
	 while(finish!=1)
    {
		//finish = check();
		check(p_user);
	} 
	*/
    
}