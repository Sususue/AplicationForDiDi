#ifndef  _RENTMOVE_H_
#define  _RENTMOVE_H_

/**************************************************************************
����˵��:�⳵��С��������֮���ƶ��Ķ���
         ͬʱ��ʾ��ǰ�������ó�ʱ��
����˵��:(x1,y1):��ʼ�ڵ�ĺ�������
         (x2,y2):��ֹ�ڵ�ĺ�������
		 derection:�ж�С����ʻ����Ĳ���
				   derection==1:��
				   derection==2:��
				   derection==3:��
				   derection==4:��
		 energy��������ʾ�����Ĳ���
**************************************************************************/
extern int rentmove(CAR_CONDITION *car_position, int x1,int y1,int x2,int y2,int *x,int *y,int direction,int *energy);

/*******************************
��������С�ƶ���Ԫ
*******************************/
extern int rentmove_basic(CAR_CONDITION *car_position,int *x,int *y);

#endif