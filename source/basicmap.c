#include "basicmap.h"
#include "common.h"



//画一般直线
void Line(int x0, int y0, int x1, int y1, int color)
{
	int	dx, dy;			/*直线x、y坐标差值*/
	int dx2, dy2;		/*加快运算速度的中间值*/
	int xinc, yinc;		/*判断想、y增加方向的符号值*/
	int d, dxy;			/*决策变量*/

	/*计算坐标差值和中间变量*/
	dx = abs(x1 - x0);
	dx2 = dx << 1;
	dy = abs(y1 - y0);
	dy2 = dy << 1;

	/*判断直线x坐标增加方向*/
	if (x1 > x0)
	{
		xinc = 1;
	}

	/*如果是竖直线*/
	else if (x1 == x0)
	{
		/*y坐标排序*/
		if (y0 > y1)
		{
			dx = y0;
			y0 = y1;
			y1 = dx;
		}

		/*画竖直线*/
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

	/*判断直线y坐标增加方向*/
	if (y1 > y0)
	{
		yinc = 1;
	}

	/*如果是水平线*/
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
	以下运用Bresenham算法生成直线。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
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

//可设置粗细的水平线
void Horizlinewide(int x0,int y0,int width,int thick,int color)
{
	int i;
	for (i=0;i<thick;i++)
	{
		Horizline(x0,y0+i,width,color);
	}
}
//空心矩形
void rectangle(int x0,int y0,int x1,int y1,int thick,int color)
{
	Horizlinewide(x0,y0,x1-x0,thick,color);
	Horizlinewide(x0,y1-thick,x1-x0,thick,color);//矩形下边因为有粗细所以往上移动
	linever(x0,y0+1,x0,y1-1,thick,color);
	linever(x1-thick,y0+1,x1,y1-1,thick,color);//矩形右边因为有粗细所以往左移动

}

//画弧度
void arclake(int x0,int y0,int radius,int color,int bias)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)     //湖的轮廓
	{
		if(x0+x<=x0+radius/2)
		{
			Putpixel64k(x0 + x, y0 - bias + y, color);//4下
		}
		// Putpixel64k(x0 + x, y0 - y, color);//1上
		// Putpixel64k(x0 - x, y0 - y, color);//2上
		Putpixel64k(x0 - x, y0 - bias + y, color);//3下
		// Putpixel64k(x0 + y, y0 + x, color);//4上
		// Putpixel64k(x0 + y, y0 - x, color);//1下 
		// Putpixel64k(x0 - y, y0 - x, color);//2下
		if(y0+x>=bias)
		{
			Putpixel64k(x0 - y, y0 -bias + x, color);//3上
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
//画实心弧度(湖)
void filllake(int x0,int y0,int radius,int color,int bias)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	for (x = 0; x <= y; x++)     //湖的轮廓
	{
		//Putpixel64k(x0 + x, y0 + y, color);//4下
		Horizline(x0,y0-bias+y,x+1,color);//4下
		// Putpixel64k(x0 + x, y0 - y, color);//1上
		// Putpixel64k(x0 - x, y0 - y, color);//2上
		//Putpixel64k(x0 - x, y0 + y, color);//3下
		Horizline(x0-x,y0-bias+y,x+1,color);//3下
		// Putpixel64k(x0 + y, y0 + x, color);//4上
		// Putpixel64k(x0 + y, y0 - x, color);//1下 
		// Putpixel64k(x0 - y, y0 - x, color);//2下
		//Putpixel64k(x0 - y, y0 + x, color);//3上
		if(y0+x>bias-1)
		{
			Horizline(x0-y,y0-bias+x,y+1,color);//3上
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
	bar(x0,y0,x0+1+radius/2,y0-bias+radius/1.41,color);//增加4上的填充部分
	bar(x0+radius/2,y0,x0+radius,y0-bias+radius,65535);//遮挡右边多余部分
}


