#include "svgahead.h"
#include"common.h"



/*����svga��ʾģʽ 1024*768 256*/
void SetSVGA256()
{
	union REGS in;
	in.x.ax = 0x4f02;
	in.x.bx = 0x105;  /*��Ӧ��ģʽ*/
	int86(0x10,&in,&in);
	if(in.x.ax!=0x004f)//�����óɹ��򷵻�0x004f
	{
		printf("Error in setting SVGA256,0x%x\n",in.x.ax);
		exit(1);
	}
}


/*ģʽ 1024*768 64k*/
void SetSVGA64k()
{
	union REGS in;
	in.x.ax = 0x4f02;
	in.x.bx = 0x117;  /*��Ӧ��ģʽ*/
	int86(0x10,&in,&in);
	if(in.x.ax!=0x004f)//�����óɹ��򷵻�0x004f
	{
		printf("Error in setting SVGA64k,0x%x\n",in.x.ax);
		exit(1);
	}
}

/*��õ�ǰsvga��ʾģʽ����Ϣ��������ʾģʽ��*/
unsigned int GetSVGA()
{
	union REGS out;
	out.x.ax = 0x4f03;
	int86(0x10,&out,&out);
	if(out.x.ax!=0x004f)
	{
		printf("error!: ox%x\n",out.x.ax);
		exit(1);
	}
	return(out.x.bx);
}

/*��ȡSVGA��ʾģʽ��bx��ժ¼���õ�ģʽ�����£�
				ģʽ��		�ֱ���		��ɫ��
				0x101		640*480		256
				0x103		800*600		256
				0x104		1024*768	16
				0x105		1024*768	256
				0x110		640*480		32K
				0x111		640*480		64K
				0x112		640*480		16.8M
				0x113		800*600		32K
				0x114		800*600		64K
				0x115		800*600		16.8M
				0x116		1024*768	32K
				0x117		1024*768	64K
				0x118		1024*768	16.8M
 ******************************************************/



 /******************************************************
 ����˵�����Դ滻ҳ
 ����˵��: page ,ҳ���
 ********************************************************/
unsigned int SelectPage(unsigned char page)
{
	union REGS r;
	static unsigned char old_page = 0;    
	static unsigned char flag = 0;
	r.x.ax = 0x4f05;
	r.x.bx = 0;
	if (flag == 0)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
		flag++;
	}
	if (page != old_page)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
	}

	return 0;
}
 /********************************************************/

 /********************************************************
	����˵�� �����㺯��
	����˵����x,y ��Ҫ����λ�� color ��ɫ
**********************************************************/
   void   putpixel(int x,int y,int color)
 {
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  register int Newpage=0;
  /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ���� */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>16;
  SelectPage(Newpage);
  VideoBuffer[pos]=color;
  }
/**********************************************************
  ����˵�����õ�ĳ�����ɫֵ��
  ����˵����x,yΪ�õ�����ꣻ
  ����ֵ��colorΪ�õ����ɫֵ
***********************************************************/ 

int  getpixel(int x,int y)
 {
  int color;
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  register int Newpage=0;
  /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ���� */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>15;
  SelectPage(Newpage);
  color=VideoBuffer[pos];
  return color;
  }

  
  
 /*******************************************************
 ����˵����  ��򻭵㺯��
 ����˵����   x,yΪ����λ�ã�color Ϊ������ɫ
 ����ֵ��    ��
/**********************************************************/
void Xorpixel (int x, int y, int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	/*Ҫ�л���ҳ���*/
	unsigned char newpage = 0;

	unsigned char oldpage;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	newpage = page >> 15;	                          /*32k����һ��ҳ������32k������㷨*/

	
		SelectPage(newpage);


	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = video_buffer[page]^color;
}

/*************************************************************
���ܺ�������64k��ģʽ����
����˵���������λ��
����ֵ˵���� �޷���
***************************************************************/
void Putpixel64k(int x, int y,  int color)
{
	if(x>=0&&x<=1024&&y>=0&&y<=768)
	{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char newpage=0;
	
//	unsigned char oldpage=0;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	newpage = page >> 15;	/*32k����һ��ҳ������32k������㷨*/
	

		SelectPage(newpage);

	
	
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = color;	
    }
}

/***********************************************************
	����˵������Ӳ�̶�ȡ8λBMPֱ�ӵ��Դ�
	����˵����x��y����  name���ļ�·��
	����ֵ˵����
/***********************************************************/

int   Readbmp256(int x,int y,char * path)
{
   FILE *fp;                   //ָ��ͼƬ�ļ����ļ�ָ��
   RGBQUAD * pc01;       //bmp��ɫ��ṹָ��
   unsigned char *buf;         //�����ػ���ָ��
   long int wide,high;         //ͼƬ��ȣ�����
   long int perline;          //һ��������ռ�ֽ�
   unsigned long int clrused;  //ʵ���õ���ɫ��
   int i,j;
   unsigned int bitcount;

   if((fp=fopen(path,"rb"))==NULL)
   {
	printf("there file can't open\n");
	delay(5000);
	exit(1);
	}


	fseek(fp,28L,0);          /*���ж��ǲ���8λBMP*/
	fread(&bitcount,2,1,fp);
	if(bitcount!=8)
	{
	 printf("it is not 8");
	 delay(5000);
	 return 0;
	}


	fseek(fp,18L,0);         /*���ļ�ָ���ƶ��������ȵ�λ�ò���ȡ����*/
	fread(&wide,4,1,fp);
	fread(&high,4,1,fp);

	perline=(wide*8+31)/8;   /*һ��ɨ������ռ���ֽ�����������4�ı���*/
	perline=perline/4*4;

	fseek(fp,46l,0);          /*�õ�ʵ��ʹ����ɫ*/
	fread(&clrused,4,1,fp);

	if(clrused==0)
	{
	 clrused=1U<<8;
	}

	if((pc01=(RGBQUAD*)malloc(4L*clrused))==NULL)   /*����ʹ����ɫ����������ռ�*/
	{
	 printf("the color is wrong");
	 delay(5000); 
	 return 0;
	}
	
	fseek(fp,54L,0);            /*��ȡ��ɫ������*/
	fread(pc01,4L*clrused,1,fp); 
	
	for(i=0;i<clrused;i++,pc01++)
	{
	 outportb(0x3c8,i);
	 outportb(0x3c9,pc01->R>>2);
	 outportb(0x3c9,pc01->G>>2);
	 outportb(0x3c9,pc01->B>>2);
	}
	free(pc01);

	buf=(unsigned char *)malloc(perline);
	if(buf==NULL)  /*���䶯̬���������ݴ���ռ�*/
	{
	 return 0;
	}
	
	fseek(fp,54L+4L*clrused,0);              /*��ÿ�е�������Ϣ����ʾ����*/
	for(i=high;i>-1;i--)
	{
	 fread(buf,perline,1,fp);
	  for(j=0;j<wide;j++)
	  {
	   putpixel(x+j,i+y,buf[j]);
	   }
	}
  free(buf);
  fclose(fp);
  return 1;
 }

 
 /*��ȡ24λͼƬ������x,yΪͼƬλ�ã�nameΪ·��������ֵ��0ʧ�ܣ�1�ɹ�*/
 int Putbmp64k(int x,int y,const char *path)
{
	 FILE *fpbmp;
	 WESHEN *buffer;//�����ػ���ָ��
	 long int width,height,linebytes;//һ��������ռ�ֽ�������������ֽڣ�
	/*ѭ������*/
	int i, j;

	/*ͼƬλ��*/
	unsigned int bit;

	/*ѹ��������*/
	unsigned long int compression;

	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}

	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);

	/*��24λͼ���˳�*/
	if (bit != 24U)
	{
		return -1;
	}

	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);

	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}

	/*��ȡ��ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);


	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;

	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (WESHEN *)malloc(linebytes)) == 0)
	{
		return -1;
	}

	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/

		/*һ�����ص����ݴ���ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}

	free(buffer);
	fclose(fpbmp);
	return 0;
}


unsigned int Getpixel64k(int x, int y)
 {
	 /*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾�������޸�*/
	 unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	 /*Ҫ�л���ҳ���*/
	 unsigned char new_page;

	 /*��Ӧ�Դ��ַƫ����*/
	 unsigned long int page;

	 /*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	 if (x < 0 || x >(1024 - 1) || y < 0 || y >(768 - 1))
	 {
		 return 0;
	 }

	 /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	 page = ((unsigned long int)y << 10) + x;
	 new_page = page >> 15;	/*32k����һ��ҳ������32k������㷨*/
	 SelectPage(new_page);

	 /*������ɫ*/
	 return video_buffer[page];
 }

/**************************************************
                9��26�ձ�д
function:       get_image

description:     �õ�һƬ�����ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½����꣬save ָ��洢��Ϣ������

out:              �����
**************************************************************/

void    get_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{
	
	int i=0;                                   /*ѭ������*/
	int j=0;
	int wide=x1-x0;
    int high=y1-y0;	
	
	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L  ;
	
	long int newpage=0;
//    long int oldpage=0;
	
	unsigned long pos;

	for(i=0;i<high;i++)
	{
		for(j=0;j<x1-x0;j++)
		{

		   pos=((unsigned long)(y0+i)<<10)+x0+j;

		   newpage=pos>>15 ;                         /*����32k������㷨*/

			
			 SelectPage(newpage);
			
			save[i*wide+j]=VideoBuffer[pos];

		}
	}

}



/**************************************************
				9��26�ձ�д
function:       put_image

description:     ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½����꣬save ָ��洢��Ϣ������

out:              �����
**************************************************************/

void    put_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{

	int i=0;                                   /*ѭ������*/
	int j=0;

	int wide=x1-x0;
	int high=y1-y0;

	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L ;

	long int newpage=0;
//	long int  oldpage=0;

	unsigned long pos;

	for(i=0;i<high;i++)
	{
		for(j=0;j<x1-x0;j++)
		{   
	        
	      pos=((unsigned long)(y0+i)<<10)+x0+j;
	
	      newpage=pos>>15 ;                         /*����32k������㷨*/
	
	      
			  SelectPage(newpage);
			

			VideoBuffer[pos]=save[i*wide+j];
		
		}
	}


}

/**************************************************
10��26�ձ�д
function:       save_image

description:    ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ�浽�ļ�����

out:            
**************************************************************/
void save_image(int x0, int y0, int x1, int y1,char *filename)
{
	FILE * fp = NULL;                            /*�����ļ�ָ��*/
    char file[50];
	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;


	int save = 0;



	// char fg[20] = "saveim.txt";
	// fp = fopen(fg, "wb");                  /*�������汳�����ļ�*/
	// char savef[40] = "..\\Dida\\img\\";//�޸ĵ��ļ�����
	// fp = fopen(strcat(savef,filename), "wb");

	sprintf(file,"..\\Dida\\img\\%s.dat",filename);
	fp = fopen(file, "wb");     //�򿪻���һ���������ļ���ֻ����д
	if (fp == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

			save = Getpixel64k(x0+j,y0+i);
			fwrite(&save,sizeof(int),1,fp);

		}
	}

	fclose(fp);

}


/**************************************************
10��26�ձ�д
function:       printf_image

description:    ���ļ��ж�ȡ�����������

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ���ǵ�������

out:
**************************************************************/

void  printf_image(int x0, int y0, int x1, int y1,char *filename)
{
	FILE * fpo= NULL;                            /*�����ļ�ָ��*/
	char file[50];
	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;

	unsigned   int save = 0;
	// char savef[40] = "..\\Dida\\img\\";//�޸ĵ��ļ�����
	// char  fas[20]="saveim.txt";
	// fpo = fopen(fas, "rb");                  /*�������汳�����ļ�*/
	
	// fpo = fopen("..\\Di\\img\\saveim.txt", "rb");
	// fpo = fopen(strcat(savef,filename), "rb");

	sprintf(file,"..\\Dida\\img\\%s.dat",filename);
	fpo = fopen(file, "rb");   //��һ���������ļ���ֻ����������ļ��������
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

		 
			fread(&save,sizeof(int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}


/**************************************************
10��26�ձ�д
function:       save_image

description:    ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ�浽�ļ�����

out:            
**************************************************************/
void save_image0(int x0, int y0, int x1, int y1)
{
	FILE * fp;                            /*�����ļ�ָ��*/
     
	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;


	int save = 0;



	char fg[20] = "saveim0.dat";
	fp = fopen(fg, "wb+");                  /*�������汳�����ļ�*/
	if (fp == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

			save = Getpixel64k(x0+j,y0+i);
			fwrite(&save,sizeof(unsigned int),1,fp);

		}
	}

	fclose(fp);

}


/**************************************************
10��26�ձ�д
function:       printf_image

description:    ���ļ��ж�ȡ�����������

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ���ǵ�������

out:
**************************************************************/

void  printf_image0(int x0, int y0, int x1, int y1)
{
	FILE * fpo;                            /*�����ļ�ָ��*/

	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;

	unsigned   int save = 0;

	char  fas[20]="saveim0.dat";
	fpo = fopen(fas, "rb+");                  /*�������汳�����ļ�*/
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

		 
			fread(&save,sizeof(unsigned int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}


void  printf_image_2(int x0, int y0, int x1, int y1, int begin_y)
{
	FILE * fpo;                            /*�����ļ�ָ��*/

	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;
	int dy = begin_y - y0;

	unsigned   int save = 0;

	char  fas[20]="saveim";
	fpo = fopen(fas, "rb");                  /*�������汳�����ļ�*/
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}

	for (i = 0; i<dy; i++)
	{
		for (j = 0; j<wide; j++)
		{
			fread(&save,sizeof(int),1,fpo);
		}
	}

	for (i = 0; i<high - dy; i++)
	{
		for (j = 0; j<wide; j++)
		{

		 
			fread(&save,sizeof(int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}
