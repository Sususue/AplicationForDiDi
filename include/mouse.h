#ifndef _MOUSE_H_
#define _MOUSE_H_


extern void cursor(int x, int y);
extern void setMouseShape(int mark, int mx, int my);
extern void mousehide(int x, int y);
extern void getMousebk(int x, int y);
extern int init();
extern void mouseInit(int *mx, int *my, int *mbutt);
extern int readxy(int *mx, int *my, int *mbutt);
extern void newxy(int *mx, int *my, int *mbutt);
extern void backgroundChange(int mx, int my, int x1, int y1, int x2, int y2);
extern void AddFrame(int mx, int my, int x1, int y1, int x2, int y2, int thick, int color);
extern void reset_mouse(int *x,int *y);
#endif