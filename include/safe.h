#ifndef  _SAFE_H_
#define  _SAFE_H_


void safe_box(int* x, int* y, int *sigle); //安全窗口弹出

int catchBox(int *x,int *y);//被警车追到后

// 更改司机状态为不能接单
void changecall(CARFA *thiscar, int callstyle);

#endif