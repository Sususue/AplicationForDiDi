#include "common.h"
#include "admload.h"

/*����Ա��¼����ͼ��*/
void manage_in_page(void)
{
	bar(0,0,1024,768,65523);//����ɫ
	
	fdhz(300,120,4,4,"����Ա��¼",0);
	fdhz(302,122,4,4,"����Ա��¼",64384);
    bar_round_with_shadow(500,300,380,50,5,1,65535,64384);

	fdhz(240,290,2,2,"��",0);
	fdhz(270,290,2,2,"Կ",0);
	fdhz(241,291,2,2,"��",64384);
	fdhz(271,291,2,2,"Կ",64384);

	bar_round(300,640,206,126,20,1,64384);
	bar_round(300,640,200,120,20,1,65535);
	bar_round(700,640,206,126,20,1,64384);
	bar_round(700,640,200,120,20,1,65535);//��¼ע���
    fdhz(240,615,3,3,"��",44373);
	fdhz(320,615,3,3,"��",44373);
	fdhz(640,615,3,3,"��",44373);
	fdhz(720,615,3,3,"¼",44373);
	
}
/*********************
����Ա��¼���߼�
*********************/
int manage_in(int *x,int *y)
{
	int temp;
	int button=0;
	int judge=0;//�жϽ�����ת
	
	//char rightcode[7]="654321";
	char incode[7]="\0";
	
	mousehide(*x,*y);
    manage_in_page();
	reset_mouse(x,y);
	
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
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&button)//���������¼����
		{
			mousehide(*x,*y);
			fdhz(241,616,3,3,"��",64384);
			fdhz(321,616,3,3,"��",64384);
			reset_mouse(x,y);
			delay0(50);
			
			return 5;
		}
		/*��¼*/
		if(*x>=600&&*x<=800&&*y>=525&&*y<=675&&button)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"��",64384);
			fdhz(721,616,3,3,"¼",64384);
			reset_mouse(x,y);
			delay0(50);
			judge = manage_in_check(incode);
			return judge;
		}
		if(*x>=300&&*x<=700&&*y>=275&&*y<=325&&button)//��������
		{
			fdhz(241,291,2,2,"��",63776);
			fdhz(271,291,2,2,"Կ",63776);
			
			judge=manage_input(x,y,incode);
			return judge;
		}
	
	}
	
}
	
	
int manage_input(int *x,int *y,char *inputcode)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *u = inputcode;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;
	
	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)//���˻�ɾ��
	    {
		    if(u != inputcode)
		    {
			    bar(295 + i * 25, 285, 325 + i * 25, 320,65535);
				if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
				{
					reset_mouse(x,y);
				}
			    u--;
			    i--;
		    }
			*u = '\0';
	    }
	
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}
		//��ֹ����ڵ�
		if(*x>=320&&*x<=680&&*y>=275&&*y<=325)
		{
			mousehide(*x,*y);
		}
		if(*x>=600&&*x<=800&&*y>=577&&*y<=703&&buttons)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"��",64384);
			fdhz(721,616,3,3,"¼",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = manage_in_check(inputcode);
			return judge;
		}
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)//���������¼����
		{
			mousehide(*x,*y);
			fdhz(241,616,3,3,"��",64384);
			fdhz(321,616,3,3,"��",64384);
			reset_mouse(x,y);
			delay0(50);
			
			return 5;
		}
		/*��������Ӧ���ַ�����code������*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    
		    
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(335+i*25,305,8,0);
			
			if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
			{
				reset_mouse(x,y);
			}
			
			/*���ַ�����������*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
	
}

int manage_in_check(char *inputcode)
{
	char rightcode[7]="654321";
	if (rightcode != NULL &&strcmp(rightcode, inputcode) == 0)
	{
		return 6; //����Ա��¼�ɹ�
	}
	else
	{
		fdhz(410, 350,1, 1, "��Կ�������", 0);
		fdhz(395, 400,1, 1, "����������µ�¼", 0);
        getch();
		return 7;
	}
}