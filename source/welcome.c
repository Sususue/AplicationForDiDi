#include "common.h"
#include "welcome.h"


/***************************************************
欢迎界面背景图
***************************************************/
void background(void)
{
   bar(0,0,1024,768,65523);
}   

 
/***************************************************
欢迎界面上的字母
***************************************************/
void words(void)
{
   FillCircle(67,453,34,64384);
   bar(33,453,128,487,64264);
   FillCircle(54,498,10,64384);
   FillCircle(102,498,10,64384);
   uphemicircle(67,453,34,0);
   circle(54,498,10,0);
   circle(102,498,10,0);
   linelevel(33,453,128,453,1,0);
   linelevel(33,487,128,487,1,0);
   linever(33,453,33,487,1,0);
   linever(128,453,128,487,1,0);/*小车*/
   
   bar(205,258,249,512,64384);
   fill_hemicircle_right(249,385,127,64384);
   fill_hemicircle_right(249,385,80,65523);/*D字母(1)*/
   
   
   
   bar(599,258,643,512,64384);
   fill_hemicircle_right(643,385,127,64384);
   fill_hemicircle_right(643,385,80,65523);/*D字母(2)*/
   
   bar_round_2(448,331,512,512,5,1,64384);/*i字母，不含点*/
  
   trapezoid(882,258,926,258,254,64384);
   trapezoid(902,327,906,327,100,65523);
   trapezoid(872,472,936,472,40,65523);/*A字母*/
   
   
   
}
   
void ball(void)
{
   FillCircle(480,290,32,64264);
}  
   

   
   
   