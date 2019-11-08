#ifndef _SVGAHEAD_H_
#define _SVGAHEAD_H_


/*BMP�ļ�ͷ�ṹ*/
typedef struct tagBITMAPFILEHEADER{
	int bfType;
	long bfsize;//�ļ���С����λΪ�ֽ�
	int bfReserved1;//����������Ϊ0
	int bfReserved2;//����������Ϊ0
	long bfOffBits;
}BITMAPFILEHEADER;

/*BMP��Ϣͷ�ṹ*/
typedef struct tagBITMAPINFOHEADER{
	long biSize; /*��Ϣͷ��С*/
	long biWidth; /*ͼ����*/
	long biHeight; /*ͼ��߶�*/
	int biPlanes; /*����Ϊ1*/
	int biBitCount; /*ÿ����λ��������Ϊ1��4��8��24*/
	long	biCompression;	/*  ѹ������ */
	long	biSizeImage;	/* ʵ��ͼ���С�������� 4 �ı��� */
	long	biXPelsPerMeter;	/*  ˮƽ����ÿ�������� */
	long	biYPelsPerMeter;	/*  ��ֱ����ÿ��������*/
	long	biClrUsed;	/*  ������ɫ��*/
	long	biClrImportant;	/* ��Ҫ����ɫ�� */
} BITMAPINFOHEADER;


typedef struct tagRGBQUAD
{
	unsigned char B;	/*��ɫ������RED��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������BLUE��д*/
	unsigned char reserved;		/*������*/
} RGBQUAD;

/*����svga��ʾģʽ 1024*768 256*/
extern void SetSVGA256(void);



/*ģʽ 1024*768 64k*/
extern void SetSVGA64k(void);


/*��õ�ǰsvga��ʾģʽ����Ϣ��������ʾģʽ��*/
extern unsigned int GetSVGA(void);


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

typedef struct
{
	unsigned char B;	/*��ɫ������BLUE��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������RED��д*/
} WESHEN;

 /******************************************************
 ����˵�����Դ滻ҳ
 ����˵��: page ,ҳ���
 ********************************************************/
extern unsigned int SelectPage(unsigned char page);

 /********************************************************/

 /********************************************************
	����˵�� �����㺯��
	����˵����x,y ��Ҫ����λ�� color ��ɫ
**********************************************************/
extern void   putpixel(int x,int y,int color);

/**********************************************************
  ����˵�����õ�ĳ�����ɫֵ��
  ����˵����x,yΪ�õ�����ꣻ
  ����ֵ��colorΪ�õ����ɫֵ
***********************************************************/ 

extern int getpixel(int x,int y);

  
  
 /*******************************************************
 ����˵����  ��򻭵㺯��
 ����˵����   x,yΪ����λ�ã�color Ϊ������ɫ
 ����ֵ��    ��
/**********************************************************/
extern void Xorpixel (int x, int y, int color);

/*************************************************************
���ܺ�������64k��ģʽ����
����˵���������λ��
����ֵ˵���� �޷���
***************************************************************/
extern void Putpixel64k(int x, int y,  int color);


/***********************************************************
	����˵������Ӳ�̶�ȡ8λBMPֱ�ӵ��Դ�
	����˵����x��y����  name���ļ�·��
	����ֵ˵����
/***********************************************************/

extern int   Readbmp256(int x,int y,char * path);

 
 /*��ȡ24λͼƬ������x,yΪͼƬλ�ã�nameΪ·��������ֵ��0ʧ�ܣ�1�ɹ�*/
extern int Putbmp64k(int x,int y,const char *path);
extern unsigned int Getpixel64k(int x, int y);
extern void  put_image(int x0,int y0,int x1,int y1,unsigned int far *save);
extern void get_image(int x0,int y0,int x1,int y1,unsigned int far *save);
extern void  printf_image0(int x0, int y0, int x1, int y1);
extern void save_image0(int x0, int y0, int x1, int y1);
//
extern void  printf_image(int x0, int y0, int x1, int y1,char *filename);
//
extern void save_image(int x0, int y0, int x1, int y1,char *filename);
extern void  printf_image_2(int x0, int y0, int x1, int y1, int begin_y);

#endif
