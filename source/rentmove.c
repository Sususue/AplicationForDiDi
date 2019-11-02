#include "common.h"
#include "rentmove.h"

/**************************************************************************
����˵��:�⳵��С��������֮���ƶ��Ķ���
         ͬʱ��ʾ��ǰ�������ó�ʱ��
����˵��:(x1,y1):��ʼ�ڵ�ĺ�������
         (x2,y2):��ֹ�ڵ�ĺ�������
		 direction:�ж�С����ʻ����Ĳ���
				   derection==1:��
				   derection==2:��
				   derection==3:��
				   derection==4:��
		 energy��������ʾ�����Ĳ���
**************************************************************************/
int rentmove(CAR_CONDITION *car_position, int x1,int y1,int x2,int y2,int *x,int *y,int direction,int *energy, USEINFOR *infor,int* avoid)
{
	int i;
	int j;//���ڵ�λ�ƶ�ѭ���ı���
	int descent=1;//ÿ��32�����ص㣬С������1%����
	char menergy[5]="\0";//����С���������ֱ仯
	int sigle=0;
	// int avoid = 0;//���ⷴ�����ѵ�������
	/*��ʼ��С��*/
	// CAR_CONDITION car_position;
	put_image(x1-22,y1-22,x1+22,y1+22,(*car_position).pic);
	/*С��λ�ó�ʼ��*/
	car_position->xpixel = x1;
	car_position->ypixel = y1;
	car_position->direction = direction;
	
	switch(direction)
	{
		case 1:
		case 2:
		j=abs(y1-y2);
		
		// /*����С��ͼ��ռ�*/
		// (car_position).pic = (unsigned int*)malloc(23*43*sizeof(unsigned int));
	
		// /*�������Ƿ�ɹ�*/
		// if((car_position).pic==NULL)
		// {
		// 	overflow_box(500,500);//����
		// 	getch();
		// 	exit(1);
		// }
	
		/*��ȡС������������С��*/
		get_image((car_position)->xpixel-22,(car_position)->ypixel-22,(car_position)->xpixel+22,(car_position)->ypixel+22,(car_position)->pic);
		break;
		
		
		case 3:
		case 4:
		j=abs(x1-x2);
		
		// /*����С��ͼ��ռ�*/
		// (car_position).pic = (unsigned int*)malloc(43*23*sizeof(unsigned int));
	
		// /*�������Ƿ�ɹ�*/
		// if((car_position).pic==NULL)
		// {
		// 	overflow_box(500,500);//����
		// 	getch();
		// 	exit(1);
		// }
	
		/*��ȡС������������С��*/
		get_image((car_position)->xpixel-22,(car_position)->ypixel-22,(car_position)->xpixel+22,(car_position)->ypixel+22,(car_position)->pic);
		break;
	}
	
	/*��ʼ��������*/
	for(i=0;i<j;i++)
	{
	    sigle=rentmove_basic(car_position,x,y);
		if(i%32==0)
		{
			if (*energy > 5)
			{
				*energy=*energy-descent;
			}
			else
			{
				*energy=5;
			}
			bar_round(896,468,190,47,8,1,65535);
			sprintf(menergy,"%d",*energy);
			outtextxy(885,460,menergy,1,1,10,64384);

			judgEnergy(energy,avoid,x,y,infor);
		}
		if(sigle==1)
		{
			return sigle;
		}
	}
	get_image(x2-22,y2-22,x2+22,y2+22,(*car_position).pic);
	//�жϷ��򲢻���С��
	(*car_position).xpixel -= 1;
	(*car_position).ypixel -= 1;
	switch((*car_position).direction)
	{
		case 1://��
		{
			
			car_draw_on(*car_position);
			break;
		}
		case 2://��
		{
			car_draw_down(*car_position);
			break;
		}
		case 3://��
		{
			car_draw_left(*car_position);
			break;
		}
		case 4://��
		{
			car_draw_right(*car_position);
			break;
		}
		
	}
	// /*�ͷŷ�����ڴ�ռ�*/
	// free((car_position).pic);

	// /*��ָ���ÿ�*/
	// (car_position).pic = NULL;
	
	return sigle;
}


/*��������С�ƶ���Ԫ*/
int rentmove_basic(CAR_CONDITION *car_position,int *x,int *y)
{
	int button=0;
	int sigle=0;
	int mx=0;
    int my=0;
	int x0 = (*car_position).xpixel,y0 = (*car_position).ypixel;



	//�жϷ����ƶ���Ӧ����
	switch((*car_position).direction)
	{
		case 1://��
		{
			car_draw_on(*car_position);
			y0 = y0-1;
			break;
		}
		case 2://��
		{
			car_draw_down(*car_position);
			y0 = y0+1;
			break;
		}
		case 3://��
		{
			car_draw_left(*car_position);
			x0 = x0-1;
			break;
		}
		case 4://��
		{
			car_draw_right(*car_position);
			x0 = x0+1;
			break;
		}
		
	}
	
	switch((*car_position).direction)
	{
		//����� 
		case 3:
		case 4: 
		    /*����ͼ��*/
	        delay0(50);
	        newxy(x,y,&button);
			
	        put_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
			{
				sigle=safe_box(x,y);
				
				if(sigle==1)
				{
					return sigle;
				}
			}
			break;
			
		//�Ϻ���
		case 1:
		case 2:
		    /*����ͼ��*/
	        delay0(50);
	        newxy(x,y,&button);
			
		    put_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			(*car_position).xpixel = x0;
	        (*car_position).ypixel = y0;
	        get_image((*car_position).xpixel-22,(*car_position).ypixel-22,(*car_position).xpixel+22,(*car_position).ypixel+22,(*car_position).pic);
			
			
			mx = *x;
			my = *y;
       
			if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
			{
				sigle=safe_box(x,y);
				
				if(sigle==1)
				{
					return sigle;
				}
			}	
			break;
	}
	return sigle;
}