#ifndef _CARRENT_H_
#define _CARRENT_H_

extern void car_rent_box(int* x, int* y, USEINFOR *infor);

extern int show_parkinfo(int *x,int *y,const PARK parking[],CARRENT rent[],int nuber,int *carflag1,int *flaging1);

extern void rentprocess_box(int *x, int *y,const PARK parking[],const CARRENT rent[],int *carflag2);

extern void newrentcar(CARRENT *car,const PARK parking[],int number1);

extern void newpark(PARK *parking);

#endif