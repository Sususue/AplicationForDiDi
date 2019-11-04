#include "common.h"
#include "frame.h"

/*欢迎界面图像*/
void outwelcome(void)
{
	background();
	words();
	ball();
	
	  
}


/*登陆界面图像*/
void load_page(void)
{
	bar(0,0,1024,768,65523);//背景色
	
	fdhz(200,120,4,4,"模拟滴滴出行系统",0);
	fdhz(202,122,4,4,"模拟滴滴出行系统",64384);

	// bar_round(500,300,380,50,5,1,65535);//账号密码输入框
	// bar_round(500,450,380,50,5,1,65535);
    bar_round_with_shadow(500,300,380,50,5,1,65535,64384);
    bar_round_with_shadow(500,450,380,50,5,1,65535,64384);//账号密码输入框
	fdhz(240,290,2,2,"电",0);
	fdhz(270,290,2,2,"话",0);
	fdhz(241,291,2,2,"电",64384);
	fdhz(271,291,2,2,"话",64384);

	fdhz(240,440,2,2,"密",0);
	fdhz(270,440,2,2,"码",0);
	fdhz(241,441,2,2,"密",64384);
	fdhz(271,441,2,2,"码",64384);

	bar_round(300,640,206,126,20,1,64384);
	bar_round(300,640,200,120,20,1,65535);
	bar_round(700,640,206,126,20,1,64384);
	bar_round(700,640,200,120,20,1,65535);//登录注册框
    fdhz(240,615,3,3,"登",44373);
	fdhz(320,615,3,3,"录",44373);
	fdhz(640,615,3,3,"注",44373);
	fdhz(720,615,3,3,"册",44373);
	
}

/*注册界面*/
void register_page(void)
{
	bar(0,0,1024,768,65523);//背景
	fdhz(370,80,3,3,"注",0);
	fdhz(600,80,3,3,"册",0);
	fdhz(371,81,3,3,"注",64384);
	fdhz(601,81,3,3,"册",64384);


	bar_round(900,120,56,56,3,1,64384);
	bar_round_with_shadow(900,120,50,50,3,1,65535,64384);//back


	// bar_round(500,250,220,30,5,1,65535);//账号
    // bar_round(500,350,220,30,5,1,65535);//密码
    // bar_round(500,450,220,30,5,1,65535);//确认密码

	bar_round_with_shadow(500,250,220,30,5,1,65535,64384);//账号
    bar_round_with_shadow(500,350,220,30,5,1,65535,64384);//密码
    bar_round_with_shadow(500,450,220,30,5,1,65535,64384);//确认密码

	bar_round(500,620,206,106,20,1,64384);
	bar_round(500,620,200,100,20,1,65535);//注册
	fdhz(290,240,2,2,"电",0);
	fdhz(320,240,2,2,"话",0);
	fdhz(291,241,2,2,"电",64384);
	fdhz(321,241,2,2,"话",64384);

	fdhz(290,340,2,2,"密",0);
	fdhz(320,340,2,2,"码",0);
	fdhz(291,341,2,2,"密",64384);
	fdhz(321,341,2,2,"码",64384);
	

	fdhz(310,440,2,2,"密",0);
	fdhz(340,440,2,2,"码",0);
	fdhz(250,440,2,2,"确",0);
	fdhz(280,440,2,2,"认",0);
	fdhz(311,441,2,2,"密",64384);
	fdhz(341,441,2,2,"码",64384);
	fdhz(251,441,2,2,"确",64384);
	fdhz(281,441,2,2,"认",64384);


	fdhz(435,595,3,3,"注",44373);
	fdhz(519,595,3,3,"册",44373);

	outtextxy(878,111,"back",1,1,10,44373);
}


/************************************************************
登录界面逻辑
判断变量judge:
judge=1:登录成功，值传递给main函数
judge=2:输入用户名，调用<sign.h>中的input_phone_num函数
judge=3:输入密码，调用<sign.h>中的input_code函数
judge=5:值传递给main返回登录界面
*************************************************************/
//int enterpage(void)
int enterpage(USER *user,USEINFOR *infor,int *x,int *y)
{
	//USER user;
	USER *head = NULL;
	USEINFOR *inforhead=NULL;  //订单链表头指针
   

	int temp;
	int button=0;
	// int x,y;
	int judge=0;//判断界面跳转

	user->phone_num[0] = '\0';
	user->code[0] = '\0';

	infor->phone_num[0] = '\0';
	infor->cnt=0;
	infor->num=0;
	infor->payway=0;
	infor->money=0.0;
	infor->nowplace=0;

	if ((head = (USER*)malloc(sizeof(USER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	if ((inforhead = (USEINFOR*)malloc(sizeof(USEINFOR))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	

	CreateUserList(head);
	CreateInforList(inforhead);

	mousehide(*x,*y);
	load_page();
	reset_mouse(x,y);
	//mouseInit(&x, &y,&button);
    while(1)

	{
		newxy(x, y, &button);
				    /*初始化，接受缓冲区数据*/
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
        /*登录*/
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&button)
		{
			mousehide(*x,*y);
			fdhz(241,616,3,3,"登",64384);
			fdhz(321,616,3,3,"录",64384);
			reset_mouse(x,y);
			delay0(50);
			judge = sign_in_check(head,user->phone_num,user->code);
		}
		

		
		/*注册*/
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&button)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"注",64384);
			fdhz(721,616,3,3,"册",64384);
			reset_mouse(x,y);
			delay0(50);
			judge = UserRegist(head,user->phone_num,user->code,inforhead,x,y,&button);
		}
		

		if(*x>=300&&*x<=700&&*y>=275&&*y<=325&&button)
		{
			judge = 2;
		}
		
		if(*x>=300&&*x<=700&&*y>=425&&*y<=475&&button)
		{
			judge = 3;
		}
		
		if(judge==2)//输入账号
		{
			judge = input_phone_num(head,user->phone_num,user->code,inforhead,x,y);

		}
		if(judge==3)//输入密码
		{
			judge = input_code(head,user->phone_num,user->code,inforhead,x,y);
		}
		if(judge==1)//注册或登陆成功
		{
			findInfor(inforhead,infor,user->phone_num);
			freeUserlist(&head);
			freeInforlist(&inforhead);
			return 1;
		}
		
		//返回登陆界面
		if(judge==5)
		{
			mousehide(*x,*y);
			outtextxy(879,112,"back",1,1,10,64384);
			reset_mouse(x,y);
			delay(100);
			return 0;//返回0继续登录
		}

	}
}
