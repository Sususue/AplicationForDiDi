#include "common.h"
#include "sign.h"

/*��½ʱ�����û���*/
int input_phone_num(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *p=phone_num;//�����ַ����м�ָ�����
	char ch;//������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons,judge;
	char temp[2] = {'\0','\0'};
	
	while(*p != '\0')
	{
		i++;
		p++;
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
		    if(p != phone_num)
		    {
			    bar(310 + i * 18, 295, 330 + i * 18, 318,65535);
				if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
				{
					reset_mouse(x,y);
				}
			    p--;
			    i--;
		    }
			*p = '\0';
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
		
		//��¼��
		if(*x>=200&&*x<=400&&*y<=703&&*y>=577&&buttons || key == 0x1c0d)
		{
            mousehide(*x,*y);
			fdhz(241,616,3,3,"��",64384);
			fdhz(321,616,3,3,"¼",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = sign_in_check(head,phone_num,code);
			return judge;
		}
		
		//��������
		if(*x>=320&&*x<=680&&*y>=425&&*y<=475&&buttons || key == 0x5000)
		{
			return 3;
		}
		
		
		if(*x>=600&&*x<=800&&*y>=577&&*y<=703&&buttons)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"ע",64384);
			fdhz(721,616,3,3,"��",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = UserRegist(head,phone_num,code,orderhead,x,y,&buttons);
			return judge;
		}
		
		
	/*��������Ӧ���ַ�����Phone_num��*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<11)
	    {
			temp[0] = ch;
			outtextxy(320+i*18,290,temp,2,2,10,0);
			if (*x>=320&&*x<=680&&*y>=275&&*y<=315)
			{
				reset_mouse(x,y);
			}


		/*���ַ�����������*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }
	}
}


/*��½ʱ��������*/
int input_code(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y)
{
	int key;
	int i=0;//���ڼ�����������ַ���Ŀ�ı���
	char *u = code;//�����ַ����м�ָ�����
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
		    if(u != code)
		    {
			    bar(295 + i * 25, 435, 325 + i * 25, 470,65535);
				if (*x>=320&&*x<=680&&*y>=425&&*y<=465)
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
		
		//��¼��
		if(*x>=200&&*x<=400&&*y<=703&&*y>=577&&buttons|| key == 0x1c0d)
		{
            mousehide(*x,*y);
			//��¼��
			fdhz(241,616,3,3,"��",64384);
			fdhz(321,616,3,3,"¼",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = sign_in_check(head,phone_num,code);
			return judge;
		}
		
		//��ֹ����ʱ�ڵ�
		if(*x>=320&&*x<=680&&*y>=425&&*y<=475)
		{
			mousehide(*x,*y);
		}
	
	
		//�����˺�
		if(*x>=320&&*x<=680&&*y>=275&&*y<=325&&buttons|| key == 0x4800)
		{
			
			return 2;
		}
		
		//ע���
		if(*x>=600&&*x<=800&&*y>=577&&*y<=703&&buttons)
		{
			mousehide(*x,*y);
			fdhz(641,616,3,3,"ע",64384);
			fdhz(721,616,3,3,"��",64384);
			reset_mouse(x,y);
			delay0(20);
			
			judge = UserRegist(head,phone_num,code,orderhead,x,y,&buttons);
			return judge;
		}
		
		
	/*��������Ӧ���ַ�����code������*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    
		    
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(335+i*25,455,8,0);
			if (*x>=320&&*x<=680&&*y>=425&&*y<=465)
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


/************************************************************************
register_in_phone_num
1���û�ע������˺����뺯��(�绰�������Ϊ11λ��
2��ֻ��������
3��������1��11λ
*************************************************************************/
int register_in_phone_num(char *phone_num, int *mx, int *my)
{
	int key;    //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = phone_num;   //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons;    //���Ĳ�������
	char temp[2] = { '\0','\0' };  //����outtextxy������������ַ�������

    /*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
    {
		i++;
	    p++;
	}
	
	
	while (1)
	{
		newxy(mx, my, &buttons);//���µ�λ�û����
		
		
		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		
		if (kbhit() != 0)//Ŀǰ�����ַ����룬�ȴ���һ���ַ�����
		{
			key = bioskey(0);
		}

		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}
		
		//��ֹ����ڵ�
		if(*mx>=390&&*mx<=610&&*my>=235&&*my<=265)
		{
			mousehide(*mx,*my);
		}
		/*if(����һ��enter������������������������һ���·����)����2��ʾ����register_in_code����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 335 && *my <= 365 && buttons || key == 0x1c0d || key == 0x5000)
		{
			return 2;
		}

		/*if���������һ�������������򣩷���3��ʾ����register_in_code_2����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 435 && *my <= 465 && buttons)
		{
			return 3;
		}

		/*if(���ע���������)����4��ʾע����ɲ����͵�¼���� */
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{
			return 4;
		}

		/*if(���back����)����5��ʾ���ص�½����*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{
			return 5;
		}

		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != phone_num)
			{
				
				bar(375 + i * 18, 235, 395 + i * 18, 263,65535);
				if(*mx>=390&&*mx<=610&&*my>=235&&*my<=260)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		/*��������Ӧ���ַ�����phone_num������*/
		ch = searchKeyValue(key);
		temp[0] = ch;
		
		if (ch != '\0'&&i<11)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

            outtextxy(380+i*18,245,temp,1,1,8,0);
			if(*mx>=390&&*mx<=610&&*my>=235&&*my<=260)
			{
				reset_mouse(mx,my);
			}
			if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
			{
				bar(210,550,700,580,65523);
			   	fdhz(210,550,1,1,"���������ĸ",0);	
			}

		}

	}
	
	
}


/****************************************************************
register_in_code
1���û�ע�������������뺯��
2��ֻ���Ǵ�Сд��ĸ�Լ�����
3��������1��10λ
****************************************************************/
int register_in_code(char *code, int *mx, int *my) 
{
	int key;     //��ʾ��ֵ�ı���
	int i = 0;   //���ڼ�����������ַ���Ŀ�ı���
	char *p = code;     //�����ַ����м�ָ�����
	char ch;     //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons;     //���Ĳ�������

	/*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);
		

		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		if(*mx>=390&&*mx<=610&&*my>=335&&*my<=365)
		{
			mousehide(*mx,*my);
		}
		/*if(������˺������������һ���Ϸ����)����1��ʾ����register_in_account����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 235 && *my <= 265 && buttons || key == 0x4800)
		{

			return 1;
		}

		
		/*if(������ٴ����������������һ��enter�����·����) ����3��ʾ����register_in_code_2����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 435 && *my <= 465 && buttons || key == 0x5000 || key == 0x1c0d)
		{

			return 3;
		}

		
		/*if(���ע���������) ����4��ʾע����ɲ���½*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons)
		{

			return 4;
		}

		
		/*if(��������˺�����) ����5��ʾ���ص�½����*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{

			return 5;
		}

		
		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				bar(385 + i * 15, 340, 398 + i * 15, 360,65535);
				if(*mx>=390&&*mx<=610&&*my>=335&&*my<=360)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		
		/*����ֵ����code����*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;
			FillCircle(392 + i * 15, 352, 5, 0);
			if(*mx>=390&&*mx<=610&&*my>=335&&*my<=360)
			{
				reset_mouse(mx,my);
			}
        }
	}
}


/*****************************************
register_in_code_2
1���û�ע����������ڶ������뺯��
2��ֻ���Ǵ�Сд��ĸ������
3��������1��10λ
*****************************************/
int register_in_code_2(char *code2, int *mx, int *my)
{
	int key;        //��ʾ��ֵ�ı���
	int i = 0;      //���ڼ�����������ַ���Ŀ�ı���
	char *p = code2;//�����ַ����м�ָ�����
	char ch;        //������ʱ�����ֵ����Ӧ�ַ��ı���
	int buttons=0; 



	/*ʹpָ��'\0',i��ʾ��ǰ�ַ���*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(mx, my, &buttons);

		/*���ü�ֵ���õ��¼�ֵ*/
		key = 0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		
		/*��esc���˳�*/
		if(key == 0x11b)
		{
			exit(0);
		}

		if(*mx>=390&&*mx<=610&&*my>=435&&*my<=465)
		{
			mousehide(*mx,*my);
		}
		/*if(������˺���������)����1��ʾ����register_in_phone_num����*/
		if (*mx >= 400 && *mx <= 600&& *my >= 235 && *my <= 265 && buttons)
		{
			
			return 1;
		}

		/*if(����������������������һ���Ϸ����)����2��ʾ����register_in_code����*/
		if (*mx >= 400 && *mx <= 600 && *my >= 335 && *my <= 365 && buttons || key == 0x4800)
		{
	
			return 2;
		}

		/*if(����һ��enter��������½����)����4��ʾע����ɲ���½*/
		if (*mx >= 450 && *mx <= 550 && *my >= 675 && *my <= 725 && buttons || key == 0x1c0d)
		{

			return 4;
		}

		/*if(��������˺�����)����5��ʾ���ص�½����*/
		if (*mx >= 95 && *mx <= 145 && *my >= 95 && *my <= 145 && buttons)
		{
			return 5;
		}

		/*���˻�ɾ��*/
		if (key == 0xe08)
		{
			if (p != code2)
			{
				bar(385 + i * 15, 440, 398 + i * 15, 460,65535);
				if(*mx>=390&&*mx<=610&&*my>=435&&*my<=460)
				{
					reset_mouse(mx,my);
				}
				p--;
				i--;
			}
			*p = '\0';
		}

		/*����ֵ����code2����*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;


			FillCircle(392 + i * 15, 452, 5, 0);
			if(*mx>=390&&*mx<=610&&*my>=435&&*my<=460)
			{
				reset_mouse(mx,my);
			}

		}
	}
}


/*****************************************
ע�������̣�
����judge��ֵ�ж�
judge=1���˺�����,����register_in_account����
judge=2���������룬����register_in_code()
judge=3:������������,����register_in_code_2()
judge=4���ж�ע���Ƿ�ɹ�,��ע��ɹ�������filefun�е�AddNewUser(),������û�
         ����1����frame�е�enterpage��������
judge=5�����ص�½����
         ����5����frame�е�enterpage��������
*****************************************/
int UserRegist(USER *head,char *phone_num,char *code,USEINFOR *orderhead,int *x,int *y,int *buttons)
{
	int judge = 0; //�ж�Ӧ�õ�����Щ�����ı���
	int flag1 = 0, flag2 = 0, flag3 = 0;  //�ֱ�ΪΪ�û��������롢���������Ƿ���ȷ���жϱ���
	int temp;  //�������ռ��̻������ı���
	char secondcode[11];  //�ڶ����������봮
    

	/*��Ҫ�ĳ�ʼ������*/
	secondcode[0] = '\0';
	*phone_num = '\0';
	*code = '\0';
	mousehide(*x,*y);
    register_page();
	reset_mouse(x,y);
	while (1)
	{
		newxy(x, y, buttons);

		/*���ռ��̻���������*/
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}
		
		/*��esc���˳�*/
		if(temp == 0x11b)
		{
			exit(0);
		}
		
		//���ؼ�
		if(*x>=95&&*x<=145&&*y>=95&&*y<=145&&*buttons)
		{
			return 5;
		}
		//ע�Ტ��¼
		if(*x>=450&&*x<=550&&*y>=675&&*y<=725&&*buttons)
		{
			judge = 4;
			//��֤
		}
		//�˺�����
		if(*x>=400&&*x<=600&&*y>=235&&*y<=265&&*buttons)
		{
			judge = 1;
		}
		//����
		if(*x>=400&&*x<=600&&*y>=335&&*y<=365&&*buttons)
		{
			judge = 2;
		}
		//����ȷ������
		if(*x>=400&&*x<=600&&*y>=435&&*y<=465&&*buttons)
		{
			judge = 3;
		}
		
		
		
		switch(judge)
		{
		
		/*case 1:�����˺����뺯��*/
		case 1:
		    judge = register_in_phone_num(phone_num, x, y);
		    if (SearchAccounts(head, phone_num) != NULL)
			{
				/*����ɫ�Ĳ沢��ʾ���˺��ѱ�ע��&flag1=0*/
				bar(800,210,900,290,65523);
				red_cross(800,240);
				bar(210,550,700,580,65523);
				fdhz(210,550,1,1,"���˺��ѱ�ע�������δ�����˺�",0);
				flag1 = 0;
			}
			else if(strlen(phone_num)!=11)
			{
				/*��ʾ�绰����λ������ȷ*/
				bar(210,550,700,580,65523);
				fdhz(210,550,1,1,"��������ȷλ���ĺ���",0);
			}
			
		    else
			{
                bar(800,220,900,290,65523);
                green_tick(800,240);
				flag1 = 1;

			}
			break;
		/*case 2:�����������뺯��*/
		case 2:
			judge = register_in_code(code, x, y);
			if (strlen(code) < 6)
			{
				/*����ɫ�Ĳ沢��ʾ���벻��������λ&flag2=0*/

                bar(800,325,900,395,65523);
                red_cross(800,345);
				bar(210,550,700,580,65523);
				fdhz(210,550,1, 1, "���벻��������λ",  0);
				flag2 = 0;
			}
			else
			{
				/*��һ����ɫ�Ĺ�&flag2=1*/

                bar(210,550,900,580,65523);
                bar(800,325,900,395,65523);
                green_tick(800,345);
				flag2 = 1;
			}
			break;

		/*case 3:���ö����������뺯��*/
		case 3:
			judge = register_in_code_2(secondcode, x, y);
			if (strcmp(code, secondcode) != 0)
			{
				/*����ɫ�Ĳ沢��ʾ�����������벻ͬ&&flag3=0*/
				
			
                bar(800,415,900,495,65523);
                red_cross(800,445);
				bar(210,550,700,580,65523);
				fdhz(210,550, 1, 1, "������������벻ͬ", 0);
				flag3 = 0;
			}
			else
			{
				/*��һ����ɫ�Ĺ�&flag3=1*/
				
                bar(210,550,900,580,65523);
                bar(800,425,900,495,65523);
                green_tick(800,445);

				flag3 = 1;
			}
			break;

		/*case 4:�ж��Ƿ�ע��ɹ�*/
		case 4:
			if (flag1 == 1 && flag2 == 1 && flag3 == 1)
			{
				mousehide(*x,*y);
				fdhz(464,686,2,2,"ע",64384);
				fdhz(508,686,2,2,"��",64384);
				reset_mouse(x,y);
				delay(20);
				AddNewUser(head, phone_num, code);
				AddNewInfor(orderhead,phone_num);//���������м�����
				return 1;
			}
			break;

	    /*case 5:���ص�¼����*/
		case 5: 
			return 5;
		
		}
		
	}
}


/*****************************************
��¼�����̣�
����ֵ1��Ϊ��¼�ɹ�����frame�е�enterpage��������
******************************************/
int sign_in_check(USER *head,char *phone_num,char *code)
{
	char *rightcode= NULL;
	rightcode = SearchAccounts(head, phone_num);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //��¼�ɹ�
	else
	{
		fdhz(410, 350,1, 1, "�û����������������", 0);
		fdhz(425, 500,1, 1, "����������µ�¼", 0);
        getch();
		return 5;
	}
}
