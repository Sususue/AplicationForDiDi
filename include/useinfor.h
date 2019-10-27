#ifndef  _USEINFOR_H_
#define  _USEINFOR_H_




void infor_box(int *x,int *y,USEINFOR *order); //个人信息

void pay_box(int *x,int *y,USEINFOR *infor); //钱包

void top_up(int *x,int *y,USEINFOR *infor);//充值
void pay_way(int *x,int *y,USEINFOR *infor);//支付方式

void leading_box(int *x,int *y); //用户指南

void leading_fast(int *x,int *y);//快车指南
void leading_rent(int *x,int *y);//租车指南
void leading_bus(int *x,int *y);//公交指南

void order_box(int *x,int *y,USEINFOR *order);

void showorder(ORDER *order);//显示订单内容
#endif

