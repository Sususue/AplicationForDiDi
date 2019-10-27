#include "common.h"
#include "plusgf.h"

#define PI 3.14159



/*填充右半圆*/
void fill_hemicircle_right(int x,int y,int r,int color)//(x,y)为半圆的圆心坐标
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx=sqrt(r*r-tx*tx);
		for(i=x;i<=x+sx;i++)
		{
			Putpixel64k(i,y-tx,color);
		}
		for(i=x;i<=x+sx;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}
}




/*四个画四分之一弧函数，非实心，均使用勾股定理计算*/

void right_up(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y-tx,color);
		tx++;
	}
}

void right_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y+tx,color);
		tx++;
	}
}


void left_up(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y-tx,color);
		tx++;
	}
}

void left_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y+tx,color);
		tx++;
	}
}




/*填充四分之一圆*/
void fill_right_up(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i <= x + tx; i++)
			{
				Putpixel64k(i, y - ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			
		}
}

void fill_left_up(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i >= x - ty; i--)
		{
			Putpixel64k(i, y - tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i >= x - tx; i--)
			{
				Putpixel64k(i, y - ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i >= x - ty; i--)
		{
			Putpixel64k(i, y - tx, color);
			
		}
	/*int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y-tx,color);
		}
		tx++;
	}*/
}

void fill_right_down(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y + tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i <= x + tx; i++)
			{
				Putpixel64k(i, y + ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y + tx, color);
			
		}
	/*int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x;i<=x+sx;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}*/
}

void fill_left_down(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i >= x - ty; i--)
		{
			Putpixel64k(i, y + tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i >= x - tx; i--)
			{
				Putpixel64k(i, y + ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i >= x - ty; i--)
		{
			Putpixel64k(i, y + tx, color);
			
		}
	/*int tx=0,ty=r,i;
	double sx;
	while(tx<ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}*/
}


/*圆角矩形*/
void bar_round(int x,int y,int length,int height,int r,int thick,int color)
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,color);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick,color);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,color);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick,color);
    right_up(x+length/2-r,y-height/2+r,r,color);
	left_up(x-length/2+r,y-height/2+r,r,color);
	left_down(x-length/2+r,y+height/2-r,r,color);
	right_down(x+length/2-r,y+height/2-r,r,color);
}

void bar_round_2(int x0,int y0,int x1,int y1,int r,int thick,int color)
{
	int length, height, x, y;
	length = x1-x0;
	height = y1-y0;
	x = (x1+x0)/2;
	y = (y1+y0)/2;
	bar_round(x,y,length,height,r,thick,color);
}


void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color, int color2)
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,65535);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick*3,color2);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,65535);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick*2,color2);
    right_up(x+length/2-r,y-height/2+r,r,color2);
	left_up(x-length/2+r,y-height/2+r,r,65535);
	left_down(x-length/2+r,y+height/2-r,r,65535);
	right_down(x+length/2-r,y+height/2-r,r,color2);
}





/*********************************************
  朝向左侧的直角三角形，（x,y)为上顶点的坐标
  用于画梯形
  ********************************************/
void triangle_left(int x,int y,int height,int color)
{
	int i,j=0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<=i/2 ;j++)
		{
			Putpixel64k(x-j/2,y+i,color);
		}
	}
}

/********************************************
  朝向右侧的直角三角形，（x，y)为上顶点的坐标 
  用于画梯形
  ********************************************/
void triangle_right(int x,int y,int height,int color)
{
	int i,j=0;
	for(i=0;i<height;i++)
	{
		for(j=0;j<=i/2;j++)
		{
			Putpixel64k(x+j/2,y+i,color);
		}
	}
}

/*********************************************
 画梯形
 （x1,y1),(x2,y2)分别为梯形中的上顶点坐标
 ********************************************/
void trapezoid(int x1,int y1,int x2,int y2,int height,int color)
{
	triangle_left(x1,y1,height,color);
	triangle_right(x2,y2,height,color);
	bar(x1,y1,x2,y2+height-1,color);
}



/*斜线*/
void lean_line(int x,int y,int length,int theta,int color)//x,y为线段的起点
{
	double right_x;
	double i,y0;
	double theta0 = ((double)(theta))/180*PI;
	right_x= x+cos(theta0)*(length);
    y0 = y;
	if((int)(theta)<=90)
	{
		for(i=x;i<=right_x;i++)
	    {
		    Putpixel64k(i,y0,color);
		    y0 += tan(theta0);
	    }
	}
	else
	{
		for(i=x;i>=right_x;i--)
	    {
		    Putpixel64k(i,y0,color);
		    y0 = y0+tan(theta0);
	    }
	}

}

/*通过加粗斜线画出平行四边形*/
void lean_line_thick(int x,int y,int length,int theta,int thick,int color)//x,y 为矩形的左边左上角坐标
{
	int i;
	for(i=0;i<thick;i++)
	{
		lean_line(x+i,y,length,theta,color);
	}
}

/*提示错误的红色叉*/
void red_cross(int x,int y)
{
	lean_line_thick(x,y,30,45,3,63488);
	lean_line_thick(x,y+20,30,-45,3,63488);
}

/*提示正确的绿色勾*/
void green_tick(int x,int y)
{
	lean_line_thick(x,y,15,45,3,2047);
	lean_line_thick(x+11,y+8,40,-45,3,2047);
}


/***************************************************************
功能说明：以（x,y)为圆心，以radius为半径画下半圆
void subhemicircle(int x0,int y0,int radius,int color)
{
	int x,y,d;
	y=radius;
	d=3-radius << 1;
	
	for(x = 0; x <= y; x++)
	{
		Putpixel64k(x0+x, y0+y, color);
		Putpixel64k(x0-x, y0+y, color);
		Putpixel64k(x0+y, y0+x, color);
		Putpixel64k(x0-y, y0+x, color);
		
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
}*/

/***************************************************
功能说明：以（x,y)为圆心，以radiius 为半径画上半圆
****************************************************/
void uphemicircle(int x0,int y0,int radius,int color)
{
	int x,y,d;
	y=radius;
	d=3-radius << 1;
	
	for(x = 0; x <= y; x++)
	{
		Putpixel64k(x0+x, y0-y, color);
		Putpixel64k(x0-x, y0-y, color);
		Putpixel64k(x0+y, y0-x, color);
		Putpixel64k(x0-y, y0-x, color);
		
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
/****************************************************************
功能说明：以（x,y)为圆心，以radius为半径画右半圆
****************************************************************/
void righthemicircle(int x0,int y0,int radius,int color)
{
	int x,y,d;
	y=radius;
	d=3-radius << 1;
	
	for(x = 0; x <= y; x++)
	{
		Putpixel64k(x0+x, y0+y, color);
		Putpixel64k(x0+y, y0+x, color);
		Putpixel64k(x0+y, y0-x, color);
		Putpixel64k(x0+x, y0-y, color);
		
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





	
	
 