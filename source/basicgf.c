#include"common.h"
#include"basicgf.h"
  /******************************************************************
   ����˵������ˮƽ�ߺ���
   ����˵����x0,y0 ��ʼ����   x1,y1��ֹ����  thick ���  color ��ɫ
   �޷���ֵ
 *******************************************************************/
  void linelevel(int x0,int y0,int x1,int y1,int thick,int color)
  {
   int i,j,k;
   if(x0>x1)                                       /*ȷ��x0Ϊ��С��һ��*/
   {
	k=x0;
	x0=x1;
	x1=k;
   }

   if(x1<=0||x1>=1024||y1<=0||y1>=768)  /*ȷ����������Ļ��Χ֮��*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<x1-x0;j++)
	{
		Putpixel64k(x0+j,y0+i,color);
	}
   }
 }

/***************************************************************
   ����˵���������ߺ���
   ����˵����x0,y0 ��ʼ����   x1,y1��ֹ����  thick ���  color ��ɫ
   �޷���ֵ
***************************************************************/
void linever(int x0,int y0,int x1,int y1,int thick,int color)
  {
	int   i = 0;
	int   j = 0;
	//int   k=0;
   int high;
   high = y1 - y0;
  /* if(y0>y1)                                       ȷ��y0Ϊ��С��һ��
   {
	k=y0;
	y0=y1;
	y1=k;
   }  
   */
   if(x1<=0||x1>=1024||y1<=0||y1>=768||x1>=1024)  /*ȷ����������Ļ��Χ֮��*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<high;j++)
	{
		Putpixel64k(x0+i,y0+j,color);
	}
   }
 }


/**********************************************************/


/**********************************************************
Function��		Horizline

Description��	��ˮƽ�ߺ���
���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Selectpage

Called By��		Line
Bar
Circlefill

Input��			int x					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
int y					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
int width				ˮƽ���ȣ�Ϊ���������죬Ϊ����������
unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ˮƽ��

Return��		None
Others��		None
**********************************************************/
void Horizline(int x, int y, int width, int  color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned int  far * const video_buffer = (unsigned int  far *)0xa0000000L;

	/*Ҫ�л���ҳ���*/
	unsigned char new_page = 0;

//	unsigned char old_page = 0;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	/*i��x����ʱ����������ѭ������*/
	int i;

	/*�ж����췽������ʼ�㿿��*/
	if (width < 0)
	{
		x = x + width;
		width = -width;
	}

	i = x;

	/*ʡ�Գ�����Ļ��߲���*/
	if (x < 0)
	{
		x = 0;
		width += i;
	}

	/*����������Ļ��ʱ�˳�*/
	if (x >= 1024)
	{
		return;
	}

	/*����������Ļ��ʱ�˳�*/
	if (y < 0 || y >= 768)
	{
		return;
	}

	/*ʡ�Գ�����Ļ�ұ߲���*/
	if (x + width > 1024)
	{
		width = 1024 - x;
	}

	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;
	
		SelectPage(new_page);
	


	/*���Դ�д����ɫ��ˮƽ�߻���*/
	for (i = 0; i < width; i++)
	{
		*(video_buffer + page + i) = color;
	}
}


/************************************************************
   ����˵������ˮƽ���κ���
   ����˵��: x0,y0 ���Ͻ�����   x1,y1���½����� color ��ɫ
************************************************************/
void bar(int x0, int y0, int x1, int y1, int color)
{

	int i;

	int wide;                /*������εĳ��Ϳ�*/
	wide = x1 - x0;


	for (i = y0; i <= y1; i++)
	{
		Horizline(x0, i, wide, color);
	}
}


/**************************************************************
 ����˵������(x,y)��ΪԲ�ģ���radiusΪ�뾶��Բ��û�з�ֹ������Ļ���жϣ�
 ���Խ�û�г����Ĳ��ֻ�����
 ����˵����x,yΪԲ�㣬radius Ϊ�뾶��colorΪ��ɫ��
 �޷���ֵ��
 **************************************************************/
 void circle(int x0,int y0,int radius,int color)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);//4��
		Putpixel64k(x0 + x, y0 - y, color);//1��
		Putpixel64k(x0 - x, y0 - y, color);//2��
		Putpixel64k(x0 - x, y0 + y, color);//3��
		Putpixel64k(x0 + y, y0 + x, color);//4��
		Putpixel64k(x0 + y, y0 - x, color);//1�� 
		Putpixel64k(x0 - y, y0 - x, color);//2��
		Putpixel64k(x0 - y, y0 + x, color);//3��
		
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}






/**************************************************************************
      ����˵������ʵ��Բ
      ����˵����x,yΪԲ��
     �޷���ֵ
**************************************************************************/
 void FillCircle(/*int x, int y, int r, int color*/int xc, int yc, int radius, int color)
{
	/*��ԲȦ�Ķ�λ�����;��߱���*/
	int x = 0,
		y = radius,
		dx = 3,
		dy = 2 - radius - radius,
		d = 1 - radius;
	
	
	/*�뾶����Ϊ���������˳�*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	��������Bresenham�㷨����ʵ��Բ��
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	************************************/
	while (x <= y)
	{
		Horizline(xc - x, yc - y, x + x, color);
        Horizline(xc - y, yc - x, y + y, color);
        Horizline(xc - y, yc + x, y + y, color);
        Horizline(xc - x, yc + y, x + x, color);
        
        if (d < 0)
        {
            d += dx;
            dx += 2;
        }
        
        else
        {
            d += (dx + dy);
            dx += 2;
            dy += 2;
            y--;
		}

        x++;
	}
 } 
 
 
 
 /*��*/
void bow(int x0,int y0,int r,int color)//���ȹ̶�
{
	int x,y,d;
	y = r;
	d = 3-r<<1;
	
	for(x=0;x<=y/4;x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 - x, y0 + y, color);
	    if(d<0)
		{
			d+=x*4+6;
		}
		else{
			d+=(x-y)*4+10;
			y--;
		}
	}
}


void delay0(int time)
 {
 	int i,j,k;
 	for(i=0;i<time;i++)
 	{
		for (j = 0; j < 1100; j++)
			for(k=0;k<100;k++);
			
		
	}
 }

