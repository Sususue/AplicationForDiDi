#ifndef _FRAME_H_
#define _FRAME_H_

// typedef struct users{
// 	char phone_num[12];
// 	char code[11];
//     struct users *next;
// }USER;       //�洢�û����˺ź�����

/*****************s*******************
��ӭ����ͼ��
************************************/
extern void outwelcome(void);


/************************************
��¼����ͼ��
************************************/
extern void load_page(void);


/***********************************
ע�����ͼ��
***********************************/
extern void register_page(void);


/*********************************
��¼���ƺ���
���ã�filefun(�ļ�����),sign(��¼ע�ắ��)
*********************************/
// extern int enterpage(void);
extern int enterpage(USER *user,USEINFOR *order,int *x,int *y);

/*********************************
����������
*********************************/
extern int mainpage(void);

#endif