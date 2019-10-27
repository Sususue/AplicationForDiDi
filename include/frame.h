#ifndef _FRAME_H_
#define _FRAME_H_

// typedef struct users{
// 	char phone_num[12];
// 	char code[11];
//     struct users *next;
// }USER;       //存储用户的账号和密码

/*****************s*******************
欢迎界面图像
************************************/
extern void outwelcome(void);


/************************************
登录界面图像
************************************/
extern void load_page(void);


/***********************************
注册界面图像
***********************************/
extern void register_page(void);


/*********************************
登录控制函数
调用：filefun(文件操作),sign(登录注册函数)
*********************************/
// extern int enterpage(void);
extern int enterpage(USER *user,USEINFOR *order,int *x,int *y);

/*********************************
进入主进程
*********************************/
extern int mainpage(void);

#endif