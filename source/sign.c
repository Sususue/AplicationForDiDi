#include "common.h"
#include "sign.h"

/*登陆时输入用户名*/
int input_phone_num(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *p=phone_num;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;
	char temp[2] = {'\0','\0'};
	
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)//按了回删键
	    {
		    if(p != phone_num)
		    {
			    bar(310 + i * 18, 295, 330 + i * 18, 318,65535);
				if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
				{
					reset_mouse(x,y);
				}
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//防止鼠标遮挡
		if(*x>=320&&*x<=680&&*y>=275&&*y<=325)
		{
			mousehide(*x,*y);
		}
		
		//登录键
		if(*x>=200&&*x<=400&&*y<=703&&*y>=577&&buttons || key == 0x1c0d)
		{
            mousehide(*x,*y);
			fdhz(241,616,3,3,"登",64384);
			fdhz(321,616,3,3,"录",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = sign_in_check(head,phone_num,code);
			return judge;
		}
		
		//密码输入
		if(*x>=320&&*x<=680&&*y>=425&&*y<=475&&buttons || key == 0x5000)
		{
			return 3;
		}
		
		
		if(*x>=600&&*x<=800&&*y>=577&&*y<=703&&buttons)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"注",64384);
			fdhz(721,616,3,3,"册",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = UserRegist(head,phone_num,code,orderhead,x,y,&buttons);
			return judge;
		}
		
		
	/*将按键对应的字符存入Phone_num中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<11)
	    {
			temp[0] = ch;
			outtextxy(320+i*18,290,temp,2,2,10,0);
			if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
			{
				reset_mouse(x,y);
			}


		/*将字符存入数组中*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }
	}
}


/*登陆时输入密码*/
int input_code(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *u = code;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)//按了回删键
	    {
		    if(u != code)
		    {
			    bar(295 + i * 25, 435, 325 + i * 25, 470,65535);
				if (*x>=320&&*x<=680&&*y>=425&&*y<=465)
				{
					reset_mouse(x,y);
				}
			    u--;
			    i--;
		    }
			*u = '\0';
	    }
	
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//登录键
		if(*x>=200&&*x<=400&&*y<=703&&*y>=577&&buttons|| key == 0x1c0d)
		{
            mousehide(*x,*y);
			//登录框
			fdhz(241,616,3,3,"登",64384);
			fdhz(321,616,3,3,"录",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = sign_in_check(head,phone_num,code);
			return judge;
		}
		
		//防止输入时遮挡
		if(*x>=320&&*x<=680&&*y>=425&&*y<=475)
		{
			mousehide(*x,*y);
		}
	
	
		//输入账号
		if(*x>=320&&*x<=680&&*y>=275&&*y<=325&&buttons|| key == 0x4800)
		{
			
			return 2;
		}
		
		//注册框
		if(*x>=600&&*x<=800&&*y>=577&&*y<=703&&buttons)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"注",64384);
			fdhz(721,616,3,3,"册",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = UserRegist(head,phone_num,code,orderhead,x,y,&buttons);
			return judge;
		}
		
		
	/*将按键对应的字符存入code数组中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    
		    
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(335+i*25,455,8,0);
			if (*x>=320&&*x<=680&&*y>=425&&*y<=465)
			{
				reset_mouse(x,y);
			}
			
			
		    
		/*将字符存入数组中*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}


/************************************************************************
register_in_phone_num
1、用户注册界面账号输入函数(电话号码必须为11位）
2、只能是数字
3、能输入1到11位
*************************************************************************/
int register_in_phone_num(char *phone_num, int *mx, int *my)
{
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = phone_num;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int buttons;    //鼠标的参数变量
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组

    /*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
    {
		i++;
	    p++;
	}
	
	
	while (1)
	{
		newxy(mx, my, &buttons);//在新的位置画鼠标
		
		
		/*重置键值并得到新键值*/
		key = 0;
		
		if (kbhit() != 0)//目前已有字符输入，等待下一个字符输入
		{
			key = bioskey(0);
		}

		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//防止鼠标遮挡
		if(*mx>=390&&*mx<=610&&*my>=235&&*my<=265)
		{
			mousehide(*mx,*my);
		}
		/*if(按了一次enter键或鼠标点击密码输入区域或按了一次下方向键)返回2表示调用register_in_code函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 335 && *my <= 365 && buttons || key == 0x1c0d || key == 0x5000)
		{
			return 2;
		}

		/*if（鼠标点击再一次输入密码区域）返回3表示调用register_in_code_2函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 435 && *my <= 465 && buttons)
		{
			return 3;
		}

		/*if(点击注册完成区域)返回4表示注册完成并发送登录请求 */
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{
			return 4;
		}

		/*if(点击back区域)返回5表示返回登陆界面*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{
			return 5;
		}

		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != phone_num)
			{
				
				bar(375 + i * 18, 235, 395 + i * 18, 263,65535);
				if(*mx>=390&&*mx<=610&&*my>=235&&*my<=260)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入phone_num数组中*/
		ch = searchKeyValue(key);
		temp[0] = ch;
		
		if (ch != '\0'&&i<11)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

            outtextxy(380+i*18,245,temp,1,1,8,0);
			if(*mx>=390&&*mx<=610&&*my>=235&&*my<=260)
			{
				reset_mouse(mx,my);
			}
			if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
			{
				bar(210,550,700,580,65523);
			   	fdhz(210,550,1,1,"请勿包含字母",0);	
			}

		}

	}
	
	
}


/****************************************************************
register_in_code
1、用户注册界面的密码输入函数
2、只能是大小写字母以及数字
3、能输入1到10位
****************************************************************/
int register_in_code(char *code, int *mx, int *my) 
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = code;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int buttons;     //鼠标的参数变量

	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);
		

		/*重置键值并得到新键值*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		if(*mx>=390&&*mx<=610&&*my>=335&&*my<=365)
		{
			mousehide(*mx,*my);
		}
		/*if(鼠标点击账号输入区域或按了一次上方向键)返回1表示调用register_in_account函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 235 && *my <= 265 && buttons || key == 0x4800)
		{

			return 1;
		}

		
		/*if(鼠标点击再次输入密码区域或按了一次enter键或下方向键) 返回3表示调用register_in_code_2函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 435 && *my <= 465 && buttons || key == 0x5000 || key == 0x1c0d)
		{

			return 3;
		}

		
		/*if(点击注册完成区域) 返回4表示注册完成并登陆*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{

			return 4;
		}

		
		/*if(点击已有账号区域) 返回5表示返回登陆界面*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{

			return 5;
		}

		
		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				bar(385 + i * 15, 340, 398 + i * 15, 360,65535);
				if(*mx>=390&&*mx<=610&&*my>=335&&*my<=360)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		
		/*将键值存入code数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;
			FillCircle(392 + i * 15, 352, 5, 0);
			if(*mx>=390&&*mx<=610&&*my>=335&&*my<=360)
			{
				reset_mouse(mx,my);
			}
        }
	}
}


/*****************************************
register_in_code_2
1、用户注册界面的密码第二次输入函数
2、只能是大小写字母与数字
3、能输入1到10位
*****************************************/
int register_in_code_2(char *code2, int *mx, int *my)
{
	int key;        //表示键值的变量
	int i = 0;      //用于计算已输入的字符数目的变量
	char *p = code2;//输入字符的中间指针变量
	char ch;        //用于临时储存键值所对应字符的变量
	int buttons=0; 



	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*重置键值并得到新键值*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		if(*mx>=390&&*mx<=610&&*my>=435&&*my<=465)
		{
			mousehide(*mx,*my);
		}
		/*if(鼠标点击账号输入区域)返回1表示调用register_in_phone_num函数*/
		if (*mx >= 400 && *mx <= 600&& *my >= 235 && *my <= 265 && buttons)
		{
			
			return 1;
		}

		/*if(鼠标点击新密码输入区域或按了一下上方向键)返回2表示调用register_in_code函数*/
		if (*mx >= 400 && *mx <= 600 && *my >= 335 && *my <= 365 && buttons || key == 0x4800)
		{
	
			return 2;
		}

		/*if(按了一次enter键或点击登陆区域)返回4表示注册完成并登陆*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons || key == 0x1c0d)
		{

			return 4;
		}

		/*if(点击已有账号区域)返回5表示返回登陆界面*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{
			return 5;
		}

		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != code2)
			{
				bar(385 + i * 15, 440, 398 + i * 15, 460,65535);
				if(*mx>=390&&*mx<=610&&*my>=435&&*my<=460)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将键值存入code2数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;


			FillCircle(392 + i * 15, 452, 5, 0);
			if(*mx>=390&&*mx<=610&&*my>=435&&*my<=460)
			{
				reset_mouse(mx,my);
			}

		}
	}
}


/*****************************************
注册主进程：
进行judge的值判断
judge=1：账号输入,调用register_in_account（）
judge=2：密码输入，调用register_in_code()
judge=3:二次密码输入,调用register_in_code_2()
judge=4：判断注册是否成功,若注册成功，调用filefun中的AddNewUser(),添加新用户
         返回1，由frame中的enterpage函数接收
judge=5：返回登陆界面
         返回5，由frame中的enterpage函数接收
*****************************************/
int UserRegist(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y,int *buttons)
{
	int judge = 0; //判断应该调用那些函数的变量
	int flag1 = 0, flag2 = 0, flag3 = 0;  //分别为为用户名、密码、二次密码是否正确的判断变量
	int temp;  //用于吸收键盘缓冲区的变量
	char secondcode[11];  //第二次输入密码串
    

	/*必要的初始化过程*/
	secondcode[0] = '\0';
	*phone_num = '\0';
	*code = '\0';
	mousehide(*x,*y);
    register_page();
	reset_mouse(x,y);
	while (1)
	{
		newxy(x, y, buttons);

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}
		
		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
		//返回键
		if(*x>=95&&*x<=145&&*y>=95&&*y<=145&&*buttons)
		{
			return 5;
		}
		//注册并登录
		if(*x>=450&&*x<=550&&*y>=675&&*y<=725&&*buttons)
		{
			judge = 4;
			//验证
		}
		//账号输入
		if(*x>=400&&*x<=600&&*y>=235&&*y<=265&&*buttons)
		{
			judge = 1;
		}
		//密码
		if(*x>=400&&*x<=600&&*y>=335&&*y<=365&&*buttons)
		{
			judge = 2;
		}
		//二次确认密码
		if(*x>=400&&*x<=600&&*y>=435&&*y<=465&&*buttons)
		{
			judge = 3;
		}
		
		
		
		switch(judge)
		{
		
		/*case 1:调用账号输入函数*/
		case 1:
		    judge = register_in_phone_num(phone_num, x, y);
		    if (SearchAccounts(head, phone_num) != NULL)
			{
				/*画红色的叉并提示该账号已被注册&flag1=0*/
				bar(800,210,900,290,65523);
				red_cross(800,240);
				bar(210,550,700,580,65523);
				fdhz(210,550,1,1,"该账号已被注册或您还未输入账号",0);
				flag1 = 0;
			}
			else if(strlen(phone_num)!=11)
			{
				/*提示电话号码位数不正确*/
				bar(210,550,700,580,65523);
				fdhz(210,550,1,1,"请输入正确位数的号码",0);
			}
			
		    else
			{
                bar(800,220,900,290,65523);
                green_tick(800,240);
				flag1 = 1;

			}
			break;
		/*case 2:调用密码输入函数*/
		case 2:
			judge = register_in_code(code, x, y);
			if (strlen(code) < 6)
			{
				/*画红色的叉并提示密码不得少于六位&flag2=0*/

                bar(800,325,900,395,65523);
                red_cross(800,345);
				bar(210,550,700,580,65523);
				fdhz(210,550,1, 1, "密码不得少于六位",  0);
				flag2 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag2=1*/

                bar(210,550,900,580,65523);
                bar(800,325,900,395,65523);
                green_tick(800,345);
				flag2 = 1;
			}
			break;

		/*case 3:调用二次密码输入函数*/
		case 3:
			judge = register_in_code_2(secondcode, x, y);
			if (strcmp(code, secondcode) != 0)
			{
				/*画红色的叉并提示两次密码输入不同&&flag3=0*/
				
			
                bar(800,415,900,495,65523);
                red_cross(800,445);
				bar(210,550,700,580,65523);
				fdhz(210,550, 1, 1, "两次输入的密码不同", 0);
				flag3 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag3=1*/
				
                bar(210,550,900,580,65523);
                bar(800,425,900,495,65523);
                green_tick(800,445);

				flag3 = 1;
			}
			break;

		/*case 4:判断是否注册成功*/
		case 4:
			if (flag1 == 1 && flag2 == 1 && flag3 == 1)
			{
				mousehide(*x,*y);
				fdhz(464,686,2,2,"注",64384);
				fdhz(508,686,2,2,"册",64384);
				reset_mouse(x,y);
				delay(20);
				AddNewUser(head, phone_num, code);
				AddNewInfor(orderhead,phone_num);//订单链表中加入结点
				return 1;
			}
			break;

	    /*case 5:返回登录界面*/
		case 5: 
			return 5;
		
		}
		
	}
}


/*****************************************
登录主进程：
返回值1则为登录成功，由frame中的enterpage函数接收
******************************************/
int sign_in_check(USER *head,char *phone_num,char *code)
{
	char *rightcode= NULL;
	rightcode = SearchAccounts(head, phone_num);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //登录成功
	else
	{
		fdhz(410, 350,1, 1, "用户名或密码输入错误", 0);
		fdhz(425, 500,1, 1, "按任意键重新登录", 0);
        getch();
		return 5;
	}
}
