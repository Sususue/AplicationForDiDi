#include "basicmap.h"
#include "common.h"



//��һ��ֱ��
void Line(int x0, int y0, int x1, int y1, int color)
{
	int	dx, dy;			/*ֱ��x��y�����ֵ*/
	int dx2, dy2;		/*�ӿ������ٶȵ��м�ֵ*/
	int xinc, yinc;		/*�ж��롢y���ӷ���ķ���ֵ*/
	int d, dxy;			/*���߱���*/

	/*���������ֵ���м����*/
	dx = abs(x1 - x0);
	dx2 = dx << 1;
	dy = abs(y1 - y0);
	dy2 = dy << 1;

	/*�ж�ֱ��x�������ӷ���*/
	if (x1 > x0)
	{
		xinc = 1;
	}

	/*�������ֱ��*/
	else if (x1 == x0)
	{
		/*y��������*/
		if (y0 > y1)
		{
			dx = y0;
			y0 = y1;
			y1 = dx;
		}

		/*����ֱ��*/
		for (dx = y0; dx <= y1; dx++)
		{
			Putpixel64k(x0, dx, color);
		}

		return;
	}

	else
	{
		xinc = -1;
	}

	/*�ж�ֱ��y�������ӷ���*/
	if (y1 > y0)
	{
		yinc = 1;
	}

	/*�����ˮƽ��*/
	else if (y1 == y0)
	{
		Horizline(x0, y0, x1 - x0, color);
		return;
	}

	else
	{
		yinc = -1;
	}

	/*******************************
	��������Bresenham�㷨����ֱ�ߡ�
	���㷨�ǵõ����ϵĳ���Ŀ����㷨��
	����ϸ����ȥ��
	*******************************/
	Putpixel64k(x0, y0, color);

	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;

		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}

			else
			{
				d += dxy;
				y0 += yinc;
			}

			x0 += xinc;
			Putpixel64k(x0, y0, color);
		}
	}

	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;

		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}

			else
			{
				d += dxy;
				x0 += xinc;
			}

			y0 += yinc;
			Putpixel64k(x0, y0, color);
		}
	}
}

//�����ô�ϸ��ˮƽ��
void Horizlinewide(int x0,int y0,int width,int thick,int color)
{
	int i;
	for (i=0;i<thick;i++)
	{
		Horizline(x0,y0+i,width,color);
	}
}
//���ľ���
void rectangle(int x0,int y0,int x1,int y1,int thick,int color)
{
	Horizlinewide(x0,y0,x1-x0,thick,color);
	Horizlinewide(x0,y1-thick,x1-x0,thick,color);//�����±���Ϊ�д�ϸ���������ƶ�
	linever(x0,y0+1,x0,y1-1,thick,color);
	linever(x1-thick,y0+1,x1,y1-1,thick,color);//�����ұ���Ϊ�д�ϸ���������ƶ�

}

//������
void arclake(int x0,int y0,int radius,int color,int bias)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)     //��������
	{
		if(x0+x<=x0+radius/2)
		{
			Putpixel64k(x0 + x, y0 - bias + y, color);//4��
		}
		// Putpixel64k(x0 + x, y0 - y, color);//1��
		// Putpixel64k(x0 - x, y0 - y, color);//2��
		Putpixel64k(x0 - x, y0 - bias + y, color);//3��
		// Putpixel64k(x0 + y, y0 + x, color);//4��
		// Putpixel64k(x0 + y, y0 - x, color);//1�� 
		// Putpixel64k(x0 - y, y0 - x, color);//2��
		if(y0+x>=bias)
		{
			Putpixel64k(x0 - y, y0 -bias + x, color);//3��
		}
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
//��ʵ�Ļ���(��)
void filllake(int x0,int y0,int radius,int color,int bias)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	for (x = 0; x <= y; x++)     //��������
	{
		//Putpixel64k(x0 + x, y0 + y, color);//4��
		Horizline(x0,y0-bias+y,x+1,color);//4��
		// Putpixel64k(x0 + x, y0 - y, color);//1��
		// Putpixel64k(x0 - x, y0 - y, color);//2��
		//Putpixel64k(x0 - x, y0 + y, color);//3��
		Horizline(x0-x,y0-bias+y,x+1,color);//3��
		// Putpixel64k(x0 + y, y0 + x, color);//4��
		// Putpixel64k(x0 + y, y0 - x, color);//1�� 
		// Putpixel64k(x0 - y, y0 - x, color);//2��
		//Putpixel64k(x0 - y, y0 + x, color);//3��
		if(y0+x>bias-1)
		{
			Horizline(x0-y,y0-bias+x,y+1,color);//3��
		}
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
	bar(x0,y0,x0+1+radius/2,y0-bias+radius/1.41,color);//����4�ϵ���䲿��
	bar(x0+radius/2,y0,x0+radius,y0-bias+radius,65535);//�ڵ��ұ߶��ಿ��
}


