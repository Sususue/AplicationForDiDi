#include "common.h"
#include "frame.h"

/*��ӭ����ͼ��*/
void outwelcome(void)
{
	background();
	words();
	ball();
	
	  
}


/*��½����ͼ��*/
void load_page(void)
{
	bar(0,0,1024,768,65523);//����ɫ
	
	fdhz(200,120,4,4,"ģ��εγ���ϵͳ",0);
	fdhz(202,122,4,4,"ģ��εγ���ϵͳ",64384);

	// bar_round(500,300,380,50,5,1,65535);//�˺����������
	// bar_round(500,450,380,50,5,1,65535);
    bar_round_with_shadow(500,300,380,50,5,1,65535,64384);
    bar_round_with_shadow(500,450,380,50,5,1,65535,64384);//�˺����������
	fdhz(240,290,2,2,"��",0);
	fdhz(270,290,2,2,"��",0);
	fdhz(241,291,2,2,"��",64384);
	fdhz(271,291,2,2,"��",64384);

	fdhz(240,440,2,2,"��",0);
	fdhz(270,440,2,2,"��",0);
	fdhz(241,441,2,2,"��",64384);
	fdhz(271,441,2,2,"��",64384);

	bar_round(300,640,206,126,20,1,64384);
	bar_round(300,640,200,120,20,1,65535);
	bar_round(700,640,206,126,20,1,64384);
	bar_round(700,640,200,120,20,1,65535);//��¼ע���
    fdhz(240,615,3,3,"��",44373);
	fdhz(320,615,3,3,"¼",44373);
	fdhz(640,615,3,3,"ע",44373);
	fdhz(720,615,3,3,"��",44373);
	
}

/*ע�����*/
void register_page(void)
{
	bar(0,0,1024,768,65523);//����
	fdhz(370,80,3,3,"ע",0);
	fdhz(600,80,3,3,"��",0);
	fdhz(371,81,3,3,"ע",64384);
	fdhz(601,81,3,3,"��",64384);


	bar_round(900,120,56,56,3,1,64384);
	bar_round_with_shadow(900,120,50,50,3,1,65535,64384);//back


	// bar_round(500,250,220,30,5,1,65535);//�˺�
    // bar_round(500,350,220,30,5,1,65535);//����
    // bar_round(500,450,220,30,5,1,65535);//ȷ������

	bar_round_with_shadow(500,250,220,30,5,1,65535,64384);//�˺�
    bar_round_with_shadow(500,350,220,30,5,1,65535,64384);//����
    bar_round_with_shadow(500,450,220,30,5,1,65535,64384);//ȷ������

	bar_round(500,620,206,106,20,1,64384);
	bar_round(500,620,200,100,20,1,65535);//ע��
	fdhz(290,240,2,2,"��",0);
	fdhz(320,240,2,2,"��",0);
	fdhz(291,241,2,2,"��",64384);
	fdhz(321,241,2,2,"��",64384);

	fdhz(290,340,2,2,"��",0);
	fdhz(320,340,2,2,"��",0);
	fdhz(291,341,2,2,"��",64384);
	fdhz(321,341,2,2,"��",64384);
	

	fdhz(310,440,2,2,"��",0);
	fdhz(340,440,2,2,"��",0);
	fdhz(250,440,2,2,"ȷ",0);
	fdhz(280,440,2,2,"��",0);
	fdhz(311,441,2,2,"��",64384);
	fdhz(341,441,2,2,"��",64384);
	fdhz(251,441,2,2,"ȷ",64384);
	fdhz(281,441,2,2,"��",64384);


	fdhz(435,595,3,3,"ע",44373);
	fdhz(519,595,3,3,"��",44373);

	outtextxy(878,111,"back",1,1,10,44373);
}


/************************************************************
��¼�����߼�
�жϱ���judge:
judge=1:��¼�ɹ���ֵ���ݸ�main����
judge=2:�����û���������<sign.h>�е�input_phone_num����
judge=3:�������룬����<sign.h>�е�input_code����
judge=5:ֵ���ݸ�main���ص�¼����
*************************************************************/
//int enterpage(void)
int enterpage(USER *user,USEINFOR *infor,int *x,int *y)
{
	//USER user;
	USER *head = NULL;
	USEINFOR *inforhead=NULL;  //��������ͷָ��
   

	int temp;
	int button=0;
	// int x,y;
	int judge=0;//�жϽ�����ת

	user->phone_num[0] = '\0';
	user->code[0] = '\0';

	infor->phone_num[0] = '\0';
	infor->cnt=0;
	infor->num=0;
	infor->payway=0;
	infor->money=0.0;
	infor->nowplace=0;

	if ((head = (USER*)malloc(sizeof(USER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	if ((inforhead = (USEINFOR*)malloc(sizeof(USEINFOR))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	

	CreateUserList(head);
	CreateInforList(inforhead);

	mousehide(*x,*y);
	load_page();
	reset_mouse(x,y);
	//mouseInit(&x, &y,&button);
    while(1)

	{
		newxy(x, y, &button);
				    /*��ʼ�������ܻ���������*/
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*��esc���˳�*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
        /*��¼*/
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&button)
		{
			mousehide(*x,*y);
			fdhz(241,616,3,3,"��",64384);
			fdhz(321,616,3,3,"¼",64384);
			reset_mouse(x,y);
			delay0(50);
			judge = sign_in_check(head,user->phone_num,user->code);
		}
		

		
		/*ע��*/
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&button)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"ע",64384);
			fdhz(721,616,3,3,"��",64384);
			reset_mouse(x,y);
			delay0(50);
			judge = UserRegist(head,user->phone_num,user->code,inforhead,x,y,&button);
		}
		

		if(*x>=300&&*x<=700&&*y>=275&&*y<=325&&button)
		{
			judge = 2;
		}
		
		if(*x>=300&&*x<=700&&*y>=425&&*y<=475&&button)
		{
			judge = 3;
		}
		
		if(judge==2)//�����˺�
		{
			judge = input_phone_num(head,user->phone_num,user->code,inforhead,x,y);

		}
		if(judge==3)//��������
		{
			judge = input_code(head,user->phone_num,user->code,inforhead,x,y);
		}
		if(judge==1)//ע����½�ɹ�
		{
			findInfor(inforhead,infor,user->phone_num);
			freeUserlist(&head);
			freeInforlist(&inforhead);
			return 1;
		}
		
		//���ص�½����
		if(judge==5)
		{
			mousehide(*x,*y);
			outtextxy(879,112,"back",1,1,10,64384);
			reset_mouse(x,y);
			delay(100);
			return 0;//����0������¼
		}

	}
}
