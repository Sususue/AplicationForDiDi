#ifndef  _USEHEAD_H_
#define  _USEHEAD_H_

/***********************
 1.��صĽṹ
 2.�û���Ϣ����ĳ�ʼ��
 3.���û���Ϣ����ز���
 ***********************/ 
typedef struct place{
	int x;           //�������λ��
	int y;
}PLACE;

typedef struct carinfor{
	int x;           //����λ��
	int y;
	char type[7];  //���ֳ����ͺ�
    char carname[6];       //���ƺ��룬Ĭ�϶�A��ͷ
}CARINFOR;


typedef struct carfast{
	char name[3];        //�������ֶ�Ӧ�ĺ���
    CARINFOR fastcar;
}CARFAST;     //�洢�쳵��������Ϣ��


typedef struct park{
	char parknum;        //��ͣ�����ı��
    char carnum;   //��������
	int x;  //ͣ����λ��
	int y;
}PARK;


typedef struct carrent{
	char parknum;        //����ͣ�����ı��
    CARINFOR rentcar;
}CARRENT;          //������������Ϣ

/************************************
 ��һ���ļ�������������һ������������û��Ķ�����Ϣ
 �Զ�������ȷ���û��¶��������
 ���û��绰�Ӷ�����ŵ���ʽ�洢ÿһ��������ͼ
 num:Ϊ��������
 cnt:������λ�ã������ڽ���������ʱ�����Բ��ý�������
-------------------------------------------------
 ����dos���ļ����8���ַ���ʹ���û�����Ӧ��mark(��order���cnt����)���ļ���
һ���û�һ���ļ�
payway:֧����ʽ��1��ʾǮ��֧����2��ʾ΢��֧����3��ʾ֧����֧��
nowplace:�û�����������λ�������ֶ�Ӧ
		0:ѧУ 1:С�� 2:���� 3:�̳� 4:ͼ��� 5:��Ӿ��
money:�û�Ǯ�������
 *************/
typedef struct useinfor{
	int cnt;  //��¼�������еĵڼ������(����ͷ���)
    int num;     //����������
	int payway; //֧����ʽ:1Ϊ���֧����2Ϊ΢��֧����3Ϊ֧����֧�� Ĭ��Ϊ0-δ����
	int nowplace;    //��λ�ö�Ӧ�ĺ���  �տ�ʼĬ��Ϊ��ѧУ
	float money;//���
	char phone_num[12]; //�û��绰
	struct useinfor *next;
}USEINFOR; //���ڴ洢�û�����Ϣ

typedef struct order{
	char name[3];//˾������
	char carname[6];//����
	char type[7];  //�����ͺ�
	char startname[7];    //���
	char endname[7];//�յ�
	char money[8];//���
	char orderstime[11];//����
}ORDER; //���ڴ洢��������Ϣ



typedef struct users{
	char phone_num[12];
	char code[11];
    struct users *next;
}USER;       //�洢�û����˺ź�����

/*********************************************************
Function: CreateOrderList
Description: ����order.txt�ļ��е���Ϣ�����û�����
Attention: 1�����ݹ�����ͷָ��һ��Ҫ��ȷ����ָ��
		   2������������Ŀ�ͷ������Ч���ݣ�
Return:�޷���ֵ
***********************************************************/
extern void CreateInforList(USEINFOR *head);

/************************************
Function: AddNewOrder
Description: �����µ��û�����
Attention:s1ָ���û���
Return:
*************************************/
extern void AddNewInfor(USEINFOR *head,char *phone);

/****************************************************
Function: SearchOrder
Description: ����ָ���绰����,�����ض�Ӧ�û��Ķ�������
Attention:
Return:�����򷵻ض�Ӧ�Ķ�����������û���򷵻�0
****************************************************/
// extern int SearchPhone(USER *head,char *phone);

// /****************************************************
// Function: changeOrder
// Description: ����ָ���绰����,���޸Ķ�Ӧ�û��Ķ�������(����1)
// Attention:
// Return:��
// ****************************************************/
// extern void changeOrder(USEINFOR *infor);
/****************************************************
Function: changeOrder
Description: ����ָ���绰����,�붩���ṹ�����޸Ķ�Ӧ�û��Ķ�������(����1)
Attention:
Return:��
****************************************************/
extern void addOrder(USEINFOR *infor, ORDER *order);

/****************************************************
Function: findOrder
Description: ���뵱ǰ�û���Ϣ,�붩���ṹ
			���ļ�����ʽ����//��ʽ�涩��ͼ
			���û����λ��(infor->cnt)����ʽ���ļ���һ���û��Ķ���������һ���ļ���
			���� 1:��һ���û��Ķ���
			n:�ڼ�������
Attention:
Return:��
****************************************************/
void findOrder(USEINFOR *infor, ORDER *order, int n);
/****************************************************
Function: findInfor
Description: ����ָ���绰����,���������ҵ���Ӧ�û��Ķ���
Attention:phoneΪ�绰����
Return:��
****************************************************/

void findInfor(USEINFOR *head, USEINFOR *infor, char *phone);
/***********************************************
Function: freeOrderlist
Description:�ͷ�������ڴ�ռ䲢��ͷָ����ΪNULL
Attention:�ļ����밴Ҫ���ʽ����д
Return:
************************************************/
extern void freeInforlist(USEINFOR **head);

/****************************************************
Function: changePay
Description: ����ָ���绰����,���޸Ķ�Ӧ�û���֧����ʽ����(����1)
			���ݴ���mode��ֵȷ���޸�ʲô
			mode:1.�޸���� 2.�޸�֧����ʽ
			valueΪ�޸ĵ�ֵ
Attention:
Return:��
****************************************************/
void changePay(USEINFOR *infor, int mode,int value);

/****************************************************
Function: changeNowplace
Description: ���뵱ǰ�û���Ϣ���޸ĵ�ǰλ��
		
			aimplace:֮ǰ���յ�(Ŀ�ĵ�)
Attention:
Return:��
****************************************************/
void changeNowplace(USEINFOR *infor, int aimplace);

/****************************************************
Function: changeMoney
Description: ���뵱ǰ�û���Ϣ���޸ĵ�ǰλ��
			price:�������
Attention:
Return:��
****************************************************/
void changeMoney(USEINFOR *infor, float price);

#endif

