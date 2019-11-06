#ifndef _CARRENT_H_
#define _CARRENT_H_

#define PARKNUM 6

extern void car_rent_box(int* x, int* y, USEINFOR *infor);

extern void show_parkinfo(int *x,int *y,const PARK parking[],CARRENT rent[],int nuber,int *carflag1,int *flaging1);

extern void rentprocess_box(int *x, int *y,const PARK parking[],const CARRENT rent[],int *carflag2, USEINFOR *infor);

extern void newrentcar(CARRENT *car,const PARK parking[],int number1);

extern void newpark(PARK *parking);

#endif