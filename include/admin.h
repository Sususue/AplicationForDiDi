#ifndef  _ADMIN_H_
#define  _ADMIN_H_


/*******************************
管理员端主逻辑
*******************************/
extern int admin(int *x,int *y);


/*******************************
司机信息界面
*******************************/
extern int driver_box(int *x,int *y,CARFA *thiscar);


/*******************************
进入具体司机信息显示的函数
********************************/                     
extern int put_diver(int *x,int *y,CARFA *thiscar);


/*******************************
管理员界面图
*******************************/
extern void admin_draw(void);






#endif