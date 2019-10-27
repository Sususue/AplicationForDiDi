#ifndef sign.h
#define sign.h

/*登陆时输入用户名*/
extern int input_phone_num(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y);


/*登陆时输入密码*/
extern int input_code(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y);


/************************************************************************
register_in_phone_num
1、用户注册界面账号输入函数(电话号码必须为11位）
2、只能是数字
3、能输入1到11位
*************************************************************************/
extern int register_in_phone_num(char *phone_num, int *mx, int *my);


/****************************************************************
register_in_code
1、用户注册界面的密码输入函数
2、只能是大小写字母以及数字
3、能输入1到10位
****************************************************************/
extern int register_in_code(char *code, int *mx, int *my);


/*****************************************
register_in_code_2
1、用户注册界面的密码第二次输入函数
2、只能是大小写字母与数字
3、能输入1到10位
*****************************************/
extern int register_in_code_2(char *code2, int *mx, int *my);


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
extern int UserRegist(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y,int *buttons);


/*****************************************
登录主进程：
返回值1则为登录成功，由frame中的enterpage函数接收
******************************************/
extern int sign_in_check(USER *head,char *phone_num,char *code);

#endif