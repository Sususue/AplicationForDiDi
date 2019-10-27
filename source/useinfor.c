#include "common.h"
#include "useinfor.h"

#define YES 1
#define NOT 0
#define REMAIN 1
#define PAYMETHOD 2

/********************************************
������Ϣ��غ���
*********************************************/



void infor_box(int *x,int *y, USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //���汳��
    save_image(796,165,996,612,"carselect");
    //��ͼ

    bar(796,166,996,612,65523);

    bar_round(896,198,196,52,20,1,64384);
    bar_round(896,198,190,47,18,1,65535);
    fdhz(850,184,2,2,"Ǯ",64384);
    fdhz(910,184,2,2,"��",64384);


    bar_round(896,303,196,96,25,1,64384);
    bar_round(896,303,190,92,23,1,65535);
    fdhz(820,272,2,2,"��",64384);
    fdhz(860,272,2,2,"��",64384);
    fdhz(900,272,2,2,"��",64384);
    fdhz(940,272,2,2,"��",64384);
    outtextxy(803,310,infor->phone_num,2,2,15,64384);//��ʾ�ֻ�����

    bar_round(896,433,196,96,25,1,64384);
    bar_round(896,433,190,91,23,1,65535);
    fdhz(805,408,3,3,"��",64384);
    fdhz(850,408,3,3,"��",64384);
    fdhz(900,408,3,3,"��",64384);
    fdhz(945,408,3,3,"ѯ",64384);

    bar_round(896,563,196,96,25,1,64384);
    bar_round(896,563,190,91,23,1,65535);
    fdhz(805,538,3,3,"��",64384);
    fdhz(850,538,3,3,"��",64384);
    fdhz(900,538,3,3,"ָ",64384);
    fdhz(945,538,3,3,"��",64384);


    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {

            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
        {
            safe_box(x,y);
        }
        else if (mx>=802  && mx<=994 && my>=172 && my<=224 && button)//���Ǯ��������֧����
        {
            pay_box(x,y,infor);
        }
        else if (mx>=802  && mx<=994 && my>=515 && my<=611 && button )//����û�ָ�ϣ�������Ӧ��Ϣ��
        {

            leading_box(x,y);
        }
        else if (mx>=802  && mx<=994 && my>=385 && my<=481 && button )//���������ѯ��������Ӧ��Ϣ��
        {

            order_box(x,y,infor);
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
    }

    //��ʾ����
    mousehide(*x,*y); 

    printf_image(796,165,996,612,"carselect");
    reset_mouse(x,y);
}

//Ǯ��������
void pay_box(int* x, int* y,USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    char ch[15];//������ʱ�洢���ת�����ַ���
    mousehide(*x,*y);

    save_image(83,109,683,659,"pay");

    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"Ǯ��",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    fdhz(200,285,2,2,"���",44373);
    sprintf(ch,"%.2f",infor->money);
    outtextxy(360,285,ch,2,2,20,44373);
    fdhz(200,423,2,2,"��ֵ",44373);
    fdhz(200,565,2,2,"֧����ʽ",44373);

    
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        else if(mx>=88 && mx<=678 && my>=369 && my<=509 && button)//��ֵ
        {
            top_up (x,y,infor);
        }
        else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//֧����ʽ
        {
            pay_way(x,y,infor);
        }
        
    }

    
    mousehide(*x,*y);  //�������
    printf_image(83,109,683,659,"pay");
    
    reset_mouse(x,y);   //���������������λ�õı���
   
}

//��ֵ
void top_up(int *x,int *y,USEINFOR *infor)
{
    int button = 0;
    int mx = 0;
    int my = 0;
    int topmoney = 0;//����Ľ��
    char flag1 = NOT;//�ж��Ƿ�ѡ����
    char flag2 = NOT;//�ж��Ƿ�ѡ���ֵ��ʽ
    char ch[15];//��ʱ����
    mousehide(*x,*y);

    //���汳��
    save_image(83,109,683,659,"topup");
    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"Ǯ��",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);
    //�ڸ�
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"��ֵ���",44373);

    bar(135,300-2,135+134,300+84,44373);
    bar(135+2,300,135+132,300+80,65535);
    outtextxy(137+20,325,"20",2,2,20,44373);
    fdhz(137+85,325,2,2,"Ԫ",44373);

    bar(316,300-2,316+134,300+84,44373);
    bar(316+2,300,316+132,300+80,65535);
    outtextxy(318+20,325,"50",2,2,20,44373);
    fdhz(318+85,325,2,2,"Ԫ",44373);
    
    bar(497,300-2,497+134,300+84,44373);
    bar(497+2,300,497+132,300+80,65535);
    outtextxy(499+10,325,"100",2,2,20,44373);
    fdhz(499+85,325,2,2,"Ԫ",44373);

    linelevel(88,410,335,410,3,63422);
    linelevel(431,410,678,410,3,63422);
    fdhz(345,405,1,1,"��ֵ��ʽ",44373);

    // ��΢��
    bar_round(255-30,480,70,70,22,1,2016);//΢����
    FillCircle(221,480,20,65535);
    FillCircle(241,490,15,2016);
    FillCircle(241,490,13,65535);
    FillCircle(241-6,490-2,2,2016);
    FillCircle(241+6,490-2,2,2016);
    FillCircle(221-9,480-3,2,2016);
    FillCircle(221+9,480-3,2,2016);
    //��֧����
    bar_round(510-30,480,70,70,22,1,1535);//֧������
    fdhz(455,450,4,4,"֧",65535);


    bar_round(383,600,196,52,20,1,44373);
    bar_round(383,600,190,47,18,1,65535);
    fdhz(337,586,2,2,"ȷ",44373);
    fdhz(397,586,2,2,"��",44373);
    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        else if (mx>=135  && mx<=269 && my>=298 && my<=384 && button)//���20Ԫ
        {
            mousehide(*x,*y);
            //����
            bar(135,300-2,135+134,300+84,64384);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,64384);
            fdhz(137+85,325,2,2,"Ԫ",64384);
            //���
            bar(316,300-2,316+134,300+84,44373);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,44373);
            fdhz(318+85,325,2,2,"Ԫ",44373);

            
            bar(497,300-2,497+134,300+84,44373);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,44373);
            fdhz(499+85,325,2,2,"Ԫ",44373);

            reset_mouse(x,y);

            topmoney = 20;
            flag1 = YES;

        }
        else if (mx>=316  && mx<=450 && my>=298 && my<=384 && button)//���50Ԫ
        {
            mousehide(*x,*y);
            //����
            bar(316,300-2,316+134,300+84,64384);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,64384);
            fdhz(318+85,325,2,2,"Ԫ",64384);
            //���
            bar(135,300-2,135+134,300+84,44373);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,44373);
            fdhz(137+85,325,2,2,"Ԫ",44373);

            bar(497,300-2,497+134,300+84,44373);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,44373);
            fdhz(499+85,325,2,2,"Ԫ",44373);

            reset_mouse(x,y);

            topmoney = 50;
            flag1 = YES;
        }
        else if (mx>=497  && mx<=631 && my>=298 && my<=384 && button)//���100Ԫ
        {
            mousehide(*x,*y);
            //����
            bar(497,300-2,497+134,300+84,64384);
            bar(497+2,300,497+132,300+80,65535);
            outtextxy(499+10,325,"100",2,2,20,64384);
            fdhz(499+85,325,2,2,"Ԫ",64384);
        
            //���
            bar(135,300-2,135+134,300+84,44373);
            bar(135+2,300,135+132,300+80,65535);
            outtextxy(137+20,325,"20",2,2,20,44373);
            fdhz(137+85,325,2,2,"Ԫ",44373);

            bar(316,300-2,316+134,300+84,44373);
            bar(316+2,300,316+132,300+80,65535);
            outtextxy(318+20,325,"50",2,2,20,44373);
            fdhz(318+85,325,2,2,"Ԫ",44373);

            reset_mouse(x,y);

            topmoney = 100;
            flag1 = YES;
        }
        else if (mx>=190  && mx<=260 && my>=445 && my<=515 && button)//���΢��
        {
            mousehide(*x,*y);
            
            //��֧�����Ĺ�
            bar(525,490-22,525+60,490+13,65535);//��֧�����Ĺ�

            lean_line_thick(280,490,15,45,3,64384);//��(΢��)
	        lean_line_thick(280+11,490+8,40,-45,3,64384);

            // changePay(infor,2,1);
            reset_mouse(x,y);
            flag2 = YES;
        }
        else if (mx>=445  && mx<=515 && my>=445 && my<=515 && button)//���֧����
        {
            mousehide(*x,*y);

            bar(270,490-22,270+60,490+13,65535);//��΢�ŵĹ�

            lean_line_thick(535,490,15,45,3,64384);//��(֧����)
	        lean_line_thick(535+11,490+8,40,-45,3,64384);

            reset_mouse(x,y);
            flag2 = YES;
        }
        else if (mx>=285  && mx<=481 && my>=573 && my<=627 && button)//���ȷ��
        {
            if (flag1 == YES && flag2 == YES)
            {
                mousehide(*x,*y);
                bar_round(383,600,196,52,20,1,64384);
                bar_round(383,600,190,47,18,1,65535);
                fdhz(337,586,2,2,"ȷ",64384);
                fdhz(397,586,2,2,"��",64384);

                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(311,360,2,2,"��ֵ�ɹ�",64384);
                fdhz(331,420,1,1,"�����������",44373);
                getch();
                reset_mouse(x,y);
                changePay(infor,REMAIN,topmoney);
                break;
            }
            else
            {
                mousehide(*x,*y);
                save_image(383-210,384-140,383+210,384+140,"notchose");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(241,340,2,2,"��ѡ���ֵ���",64384);
                fdhz(286,380,2,2,"���ֵ��ʽ",64384);
                
                fdhz(331,430,1,1,"�����������",44373);
                getch();
                printf_image(383-210,384-140,383+210,384+140,"notchose");
                reset_mouse(x,y);
            }
            
            
            
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"topup");

    bar(300,280,650,320,65535);

    sprintf(ch,"%.2f",infor->money);
    outtextxy(360,285,ch,2,2,20,44373);
    reset_mouse(x,y);
}
//֧����ʽ
void pay_way(int *x,int *y, USEINFOR *infor)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //���汳��
    save_image(83,109,683,659,"payway");
    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"Ǯ��",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"֧����ʽ",44373);

    linelevel(88,397,678,397,3,63422);
    linelevel(88,524,678,524,3,63422);

    // bar(135-5,333-3,135+80,333+22,0);
    // bar(135+90,333-20,135+140,333+13,0);
    fdhz(135,333,1,1,"���֧��",44373);
    fdhz(135,460,1,1,"΢��֧��",44373);
    fdhz(135,587,1,1,"֧����֧��",44373);
    if (infor->payway == 1)
    {
        // bar(125,290,170,350,65535);
        fdhz(135,333,1,1,"���֧��",64384);
        lean_line_thick(230,333,15,45,3,64384);//��
	    lean_line_thick(230+11,333+8,40,-45,3,64384);
    }
    else if(infor->payway == 2)
    {
        fdhz(135,460,1,1,"΢��֧��",64384);
        lean_line_thick(230,460,15,45,3,64384);//��
	    lean_line_thick(230+11,460+8,40,-45,3,64384);
    }
    else if (infor->payway == 3)
    {
        fdhz(135,587,1,1,"֧����֧��",64384);
        lean_line_thick(250,587,15,45,3,64384);//��
	    lean_line_thick(250+11,587+8,40,-45,3,64384);
    }
    
    //���ؼ�
    bar_round(976,664,76,44,15,1,64384);
    bar_round(976,664,70,39,13,1,65535);
    outtextxy(938,645,"Back",2,2,15,64384);
    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        else if (mx>=88 && mx<=678 && my>=270 && my<=397 && button)//ѡ���
        {
            mousehide(*x,*y);
            bar(135-5,460-3,135+80,460+22,65535);//��΢��
            bar(135+90,460-22,135+140,460+13,65535);
            bar(135-5,587-3,135+100,587+22,65535);//��֧����
            bar(135+110,587-22,135+160,587+13,65535);
            
            fdhz(135,460,1,1,"΢��֧��",44373);
            fdhz(135,587,1,1,"֧����֧��",44373);

            fdhz(135,333,1,1,"���֧��",64384);
            lean_line_thick(230,333,15,45,3,64384);//��
	        lean_line_thick(230+11,333+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,1);
            reset_mouse(x,y);
        }
        else if (mx>=88 && mx<=678 && my>=397 && my<=524 && button)//ѡ΢��
        {
            mousehide(*x,*y);
            bar(135-5,333-3,135+80,333+22,65535);//�����
            bar(135+90,333-22,135+140,333+13,65535);
            bar(135-5,587-3,135+100,587+22,65535);//��֧����
            bar(135+110,587-22,135+160,587+13,65535);

            fdhz(135,333,1,1,"���֧��",44373);
            fdhz(135,587,1,1,"֧����֧��",44373);

            fdhz(135,460,1,1,"΢��֧��",64384);
            lean_line_thick(230,460,15,45,3,64384);//��
	        lean_line_thick(230+11,460+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,2);
            reset_mouse(x,y);
        }
        else if (mx>=88 && mx<=678 && my>=524 && my<=655 && button)//ѡ֧����
        {
            mousehide(*x,*y);
            bar(135-5,333-3,135+80,333+22,65535);//�����
            bar(135+90,333-22,135+140,333+13,65535);
            bar(135-5,460-3,135+80,460+22,65535);//��΢��
            bar(135+90,460-22,135+140,460+13,65535);

            fdhz(135,333,1,1,"���֧��",44373);
            fdhz(135,460,1,1,"΢��֧��",44373);

            fdhz(135,587,1,1,"֧����֧��",64384);
            lean_line_thick(250,587,15,45,3,64384);//��
	        lean_line_thick(250+11,587+8,40,-45,3,64384);
            changePay(infor,PAYMETHOD,3);
            reset_mouse(x,y);
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"payway");
    // //��BACK�������ڵ�
    // bar_round(976,664,76,44,15,1,65523);
    reset_mouse(x,y);
}


//�û�ָ�ϵ�����
void leading_box(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);

    //���汳��
    save_image(83,109,683,659,"lead");

    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"�û�ָ��",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);
    fdhz(200,285,2,2,"�쳵",44373);
    fdhz(200,423,2,2,"С���⳵",44373);
    fdhz(200,565,2,2,"����",44373);

    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        
        else if(mx>=88 && mx<=678 && my>=231 && my<=367 && button)//�쳵ָ��
        {
            leading_fast(x,y);
            
        }
        else if(mx>=88 && mx<=678 && my>=369 && my<=509 && button)//С���⳵ָ��
        {
            leading_rent(x,y);
        }
        else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//����ָ��
        {
            leading_bus(x,y);
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"lead");
    reset_mouse(x,y);
}


void leading_fast(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //���汳��
    save_image(88,231,678,637,"leadfast");
    //��ͼ
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);

    fdhz(100,245,1,1,"�쳵�Ƽ۹���",44373);

    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"ʵʱ�ó�",44373);

    fdhz(140,305,1,1,"ʱ���",44373);
    outtextxy(100,335,"00:00 - 09:00",1,1,10,44373);
    outtextxy(100,365,"12:00 - 15:00",1,1,10,44373);
    outtextxy(100,395,"17:00 - 00:00",1,1,10,44373);
    fdhz(125,425,1,1,"��ͨʱ��",44373);

    fdhz(300,305,1,1,"�𲽼�",44373);
    outtextxy(350,305,"(",1,1,10,44373);
    outtextxy(380,305,")",1,1,10,44373);
    fdhz(367,305,1,1,"Ԫ",44373);
    outtextxy(300,335,"11.00",1,1,10,44373);
    outtextxy(300,365,"11.00",1,1,10,44373);
    outtextxy(300,395,"11.00",1,1,10,44373);
    outtextxy(300,425,"10.30",1,1,10,44373);

    fdhz(410,305,1,1,"��̷�",44373);
    outtextxy(460,305,"(",1,1,10,44373);
    outtextxy(520,305,")",1,1,10,44373);
    fdhz(475,305,1,1,"Ԫ",44373);
    outtextxy(488,305,"/km",1,1,10,44373);
    outtextxy(430,335,"2.60",1,1,10,44373);
    outtextxy(430,365,"1.80",1,1,10,44373);
    outtextxy(430,395,"1.80",1,1,10,44373);
    outtextxy(430,425,"1.70",1,1,10,44373);

    fdhz(550,305,1,1,"ʱ����",44373);
    outtextxy(600,305,"(",1,1,10,44373);
    outtextxy(665,305,")",1,1,10,44373);
    fdhz(615,305,1,1,"Ԫ",44373);
    outtextxy(628,305,"/min",1,1,10,44373);
    outtextxy(570,335,"0.50",1,1,10,44373);
    outtextxy(570,365,"0.50",1,1,10,44373);
    outtextxy(570,395,"0.50",1,1,10,44373);
    outtextxy(570,425,"0.35",1,1,10,44373);

    fdhz(120,460,1,1,"�𲽼۰������",44373);
    outtextxy(260,460,"3 km,",1,1,10,44373);
    fdhz(320,460,1,1,"����ʱ��",44373);
    outtextxy(395,460,"9 min",1,1,10,44373);
    fdhz(120,490,1,1,"��������",44373);
    outtextxy(195,490,",",1,1,10,44373);
    fdhz(215,490,1,1,"���ռƼ۹����շ�",44373);

    linelevel(88,525,335,525,3,63422);
    linelevel(431,525,678,525,3,63422);
    fdhz(345,520,1,1,"ԤԼ�ó�",44373);

    fdhz(120,560,1,1,"�����Ƽ���ʵ���ó��Ƽ۱���һ��",44373);
    fdhz(120,590,1,1,"������",44373);
    outtextxy(490,590,"19.00",1,1,10,44373);
    fdhz(550,590,1,1,"Ԫ",44373);

    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(88,231,678,637,"leadfast");
    reset_mouse(x,y);
}

void leading_rent(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //���汳��
    save_image(88,231,678,637,"leadrent");
    //��ͼ
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);
    
    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"��������",44373);

    fdhz(140,315,1,1,"����ָ��վ����ѡ��",44373);
    outtextxy(315,315,",",1,1,10,44373);
    fdhz(330,315,1,1,"�µ����������ó�",44373);

    fdhz(140,345,1,1,"����ʹ����Ϻ�����ָ��վ����ͣ��",44373);

    fdhz(140,375,1,1,"��𰴷��Ӽ�ʱ�շ�",44373);

    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(88,231,678,637,"leadrent");
    reset_mouse(x,y);
}

void leading_bus(int *x,int *y)
{
    int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
    //���汳��
    save_image(88,231,678,637,"leadbus");
    //��ͼ
    bar(88,231,678,580,65535);
    bar(98,580,670,630,65535);

    linelevel(88,270,335,270,3,63422);
    linelevel(431,270,678,270,3,63422);
    fdhz(345,265,1,1,"��·�滮",44373);

    fdhz(140,315,1,1,"���ѡ����ʺ��Լ����еķ���",44373);
    outtextxy(415,315,"?",1,1,10,44373);

    fdhz(140,355,1,1,"��·�߻���ҳ��",44373);
    outtextxy(275,355,",",1,1,10,44373);
    fdhz(290,355,1,1,"ϵͳ��Ĭ��չʾ����Ŀ�ĵ���ʱ��̵�",44373);
    fdhz(140,385,1,1,"����",44373);
    fdhz(140,415,1,1,"��Ҳ����ѡ��",44373);
    outtextxy(255,415,",",1,1,10,44373);
    fdhz(270,415,1,1,"�ٻ���",44373);
    outtextxy(325,415,",",1,1,10,44373);
    fdhz(340,415,1,1,"�ٲ��е��Ƽ�����",44373);
    outtextxy(495,415,",",1,1,10,44373);
    fdhz(510,415,1,1,"�Ӷ�ѡ�����",44373);
    fdhz(140,445,1,1,"�ʵĹ������з���",44373);


    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
        
    }

    //��ʾ����
    mousehide(*x,*y);   
    printf_image(88,231,678,637,"leadbus");
    reset_mouse(x,y);
}

// void order_box(int *x,int *y,USEINFOR *infor)//��ͼ��ʽ��ʾ����
// {
//     int button=0;
//     int mx=0;
//     int my=0;
//     char *ordernum;//���ڽ�int��תΪ�ַ�����
//     char *orderpage;
//     // int page=0;//���ڼ�¼��Ȼ��������һҳ
//     int page = infor->num;//����������ʾ
//     char filename[20];//������
//     mousehide(*x,*y);
    
//     if((ordernum = (char *)malloc(sizeof(char)*4)) == NULL)
// 	{
// 		overflow_box(500,500);
// 		getch();
// 		exit(1);
// 	}
//     if((orderpage = (char *)malloc(sizeof(char)*4)) == NULL)
// 	{
// 		overflow_box(500,500);
// 		getch();
// 		exit(1);
// 	}
//     // changeOrder(infor);
//     // itoa(infor->num,change,10);
//     sprintf(ordernum,"%d",infor->num);
    
//     //���汳��
//     save_image(83,109,683,659,"order");

//     //��ͼ
//     bar_round(383,384,596,546,50,1,64384);
//     bar_round(383,384,590,542,48,1,65535);
//     fdhz(272,135,3,3,"��ʷ����",44373);
//     bar(88,200,678,230,63422);
    
//     // linelevel(88,368,678,368,5,63422);
//     // linelevel(88,510,678,510,5,63422);
//     // fdhz(200,285,2,2,"�쳵",44373);
//     // fdhz(200,423,2,2,"С���⳵",44373);
//     // fdhz(200,565,2,2,"����",44373);
    
//     // bar(96,300,670,630,0);
//     fdhz(135,250,1,1,"��������",44373);
//     outtextxy(215,250,":",1,1,10,44373);
//     outtextxy(230,250,ordernum,1,1,10,44373);
    
//     linelevel(88,275,335,270,3,63422);
//     linelevel(431,275,678,270,3,63422);
//     fdhz(350,265,1,1,"����",44373);
//     // bar(390,265,430,290,0);//�����ڸ�λ��
//     // outtextxy(395,265,"12",1,1,10,44373);


//     //ʵ���ͼ

//     // linelevel(128,310,335,310,3,63422);
//     // linelevel(431,310,638,310,3,63422);
//     // fdhz(345,305,1,1,"��������",44373);

//     // fdhz(135,350,1,1,"��������",44373);
//     // outtextxy(215,350,":",1,1,10,44373);
//     // fdhz(230,350,1,1,"�쳵",44373);

//     // fdhz(390,350,1,1,"����",44373);
//     // outtextxy(430,350,":",1,1,10,44373);
//     // outtextxy(445,350,"10.00",1,1,10,44373);

//     // fdhz(135,390,1,1,"������",44373);
//     // outtextxy(195,390,":",1,1,10,44373);
//     // fdhz(210,390,1,1,"��ѧ",44373);

//     // fdhz(390,390,1,1,"Ŀ�ĵ�",44373);
//     // outtextxy(450,390,":",1,1,10,44373);
//     // fdhz(465,390,1,1,"ͼ���",44373);

//     // fdhz(135,430,1,1,"����",44373);
//     // outtextxy(175,430,":",1,1,10,44373);
//     // outtextxy(190,430,"2019.10.26",1,1,10,44373);

//     // linelevel(128,470,335,270,3,63422);
//     // linelevel(431,470,638,270,3,63422);
//     // fdhz(345,465,1,1,"˾����Ϣ",44373);

//     // fdhz(135,510,1,1,"˾��",44373);
//     // outtextxy(175,510,":",1,1,10,44373);
//     // fdhz(190,510,1,1,"��",44373);
//     // fdhz(210,510,1,1,"ʦ��",44373);

//     // fdhz(135,550,1,1,"����",44373);
//     // outtextxy(175,550,":",1,1,10,44373);
//     // fdhz(190,550,1,1,"��",44373);
//     // outtextxy(205,550,"A",1,1,10,44373);
//     // outtextxy(220,550,"7L27D",1,1,10,44373);

//     // fdhz(135,590,1,1,"����",44373);
//     // outtextxy(175,590,":",1,1,10,44373);
//     // fdhz(190,590,1,1,"����",44373);

//     // //��ʾ��һ������
//     // if (infor->num!=0)
//     // {
//     //     page++;
//     //     sprintf(filename,"%d_%d",infor->cnt,page);
// 	//     printf_image(96,300,670,630,filename);
//     //     //��ʾ�ڼ�������
//     //     sprintf(orderpage,"%d",page);
//     //     bar(390,265,430,290,65535);
//     //     outtextxy(395,265,orderpage,1,1,10,44373);
//     //     //���Ҽ�
//     //     // outtextxy(135,610,"<",2,2,10,44373);
//     //     if (infor->num>1)
//     //     {
//     //         outtextxy(626,610,">",2,2,10,44373);
//     //     }
        
        
//     // }
//     //��ʾ���һ������(����������ʾ)
//     if (infor->num!=0)
//     {
//         // page++;
//         sprintf(filename,"%d_%d",infor->cnt,page);
// 	    printf_image(96,300,670,630,filename);
//         //��ʾ�ڼ�������
//         sprintf(orderpage,"%d",page);
//         bar(390,265,430,290,65535);
//         outtextxy(395,265,orderpage,1,1,10,44373);
//         //���Ҽ�
//         // outtextxy(135,610,"<",2,2,10,44373);
//         if (infor->num>1)
//         {
//             outtextxy(626,610,">",2,2,10,44373);
//         }
        
        
//     }
    
//     // bar(140,610,170,640,0);//�жϵ������
//     // bar(630,610,660,640,0);
//     // outtextxy(135,610,"<",2,2,10,44373);
//     // outtextxy(626,610,">",2,2,10,44373);


//     // ��ʱ��һ��ֵ�Ƿ���ȷ
//     // outtextxy(415,385,ordernum,1,1,10,44373);
//     // outtextxy(415,355,ordercnt,1,1,10,44373);
//     // outtextxy(415,315,infor->phone_num,1,1,10,44373);

//     //��ʾ���
//     reset_mouse(x,y);

//     while (1)
//     {
//         newxy(x,y,&button);
// 		mx = *x;
// 		my = *y;
//         if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
//         {
//             break;
//         }
//         else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//  ���ESC�˳�ϵͳ
//         {
//             exit(0);
//         }
//         //˳����ʾ����
//         // else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
//         // {
//         //     page++;
//         //     sprintf(filename,"%d_%d",infor->cnt,page);
//         //     mousehide(*x,*y);
// 	    //     printf_image(96,300,670,630,filename);
//         //     bar(630,610,660,640,65535);//�ڸ��Ҳ��ͷ
//         //     //���Ҽ�
//         //     outtextxy(135,610,"<",2,2,10,44373);
//         //     if (page < infor->num)
//         //     {
//         //         outtextxy(626,610,">",2,2,10,44373);
//         //     }
//         //     //��ʾ�ڼ�������
//         //     sprintf(orderpage,"%d",page);
//         //     bar(390,265,430,290,65535);
//         //     outtextxy(395,265,orderpage,1,1,10,44373);
//         //     reset_mouse(x,y);
//         // }
//         // else if (page>1 && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//���<�鿴��һҳ����
//         // {
//         //     page--;
//         //     sprintf(filename,"%d_%d",infor->cnt,page);
//         //     mousehide(*x,*y);
// 	    //     printf_image(96,300,670,630,filename);
//         //     bar(140,610,170,640,65535);//�ڸ�����ͷ
//         //     //���Ҽ�
            
//         //     outtextxy(626,610,">",2,2,10,44373);
//         //     if (page > 1)
//         //     {
//         //         outtextxy(135,610,"<",2,2,10,44373);
//         //     }
//         //     //��ʾ�ڼ�������
//         //     sprintf(orderpage,"%d",page);
//         //     bar(390,265,430,290,65535);
//         //     outtextxy(395,265,orderpage,1,1,10,44373);
//         //     reset_mouse(x,y);
//         // }
//         //����������ʾ����
//         else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
//         {
//             page--;
//             sprintf(filename,"%d_%d",infor->cnt,page);
//             mousehide(*x,*y);
// 	        printf_image(96,300,670,630,filename);
//             bar(630,610,660,640,65535);//�ڸ��Ҳ��ͷ
//             //���Ҽ�
//             outtextxy(135,610,"<",2,2,10,44373);
//             if (page > 1)
//             {
//                 outtextxy(626,610,">",2,2,10,44373);
//             }
//             //��ʾ�ڼ�������
//             sprintf(orderpage,"%d",page);
//             bar(390,265,430,290,65535);
//             outtextxy(395,265,orderpage,1,1,10,44373);
//             reset_mouse(x,y);
//         }
//         else if (page < infor->num && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//���<�鿴��һҳ����
//         {
//             page++;
//             sprintf(filename,"%d_%d",infor->cnt,page);
//             mousehide(*x,*y);
// 	        printf_image(96,300,670,630,filename);
//             bar(140,610,170,640,65535);//�ڸ�����ͷ
//             //���Ҽ�
            
//             outtextxy(626,610,">",2,2,10,44373);
//             if (page < infor->num)
//             {
//                 outtextxy(135,610,"<",2,2,10,44373);
//             }
//             //��ʾ�ڼ�������
//             sprintf(orderpage,"%d",page);
//             bar(390,265,430,290,65535);
//             outtextxy(395,265,orderpage,1,1,10,44373);
//             reset_mouse(x,y);
//         }
//     }
//     free(ordernum);
//     free(orderpage);
//     ordernum=NULL;
//     orderpage=NULL;
//     // ��ʾ����
//     mousehide(*x,*y);   
//     printf_image(83,109,683,659,"order");
//     reset_mouse(x,y);
// }

void order_box(int *x,int *y,USEINFOR *infor)//��ȡ�ļ���ʽ��ʾ����
{
    int button=0;
    int mx=0;
    int my=0;
    char *ordernum;//���ڽ�int��תΪ�ַ�����
    char *orderpage;
    // int page=0;//���ڼ�¼��Ȼ��������һҳ
    int page = infor->num;//����������ʾ
    char filename[20];//������
    ORDER *order;
    mousehide(*x,*y);
    
    if((ordernum = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if((orderpage = (char *)malloc(sizeof(char)*4)) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    if ((order = (ORDER*)malloc(sizeof(ORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
  
    sprintf(ordernum,"%d",infor->num);
    
    //���汳��
    save_image(83,109,683,659,"order");

    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"��ʷ����",44373);
    bar(88,200,678,230,63422);
    
    
    // bar(96,300,670,630,0);
    fdhz(135,250,1,1,"��������",44373);
    outtextxy(215,250,":",1,1,10,44373);
    outtextxy(230,250,ordernum,1,1,10,44373);
    
    linelevel(88,275,335,270,3,63422);
    linelevel(431,275,678,270,3,63422);
    fdhz(350,265,1,1,"����",44373);
    // bar(390,265,430,290,0);//�����ڸ�λ��
    // outtextxy(395,265,"12",1,1,10,44373);


    // ʵ���ͼ
    
    
    // //��ʾ��һ������
    // if (infor->num!=0)
    // {
    //     page++;
    //     sprintf(filename,"%d_%d",infor->cnt,page);
	//     printf_image(96,300,670,630,filename);
    //     //��ʾ�ڼ�������
    //     sprintf(orderpage,"%d",page);
    //     bar(390,265,430,290,65535);
    //     outtextxy(395,265,orderpage,1,1,10,44373);
    //     //���Ҽ�
    //     // outtextxy(135,610,"<",2,2,10,44373);
    //     if (infor->num>1)
    //     {
    //         outtextxy(626,610,">",2,2,10,44373);
    //     }
        
        
    // }
    //��ʾ���һ������(����������ʾ)
    if (infor->num!=0)
    {
        
        findOrder(infor,order,page);
        //��ʾ�ڼ�������
        sprintf(orderpage,"%d",page);
        bar(390,265,430,290,65535);
        outtextxy(395,265,orderpage,1,1,10,44373);
        
        //��ʾ������Ϣ
        showorder(order);

        //���Ҽ�
        // outtextxy(135,610,"<",2,2,10,44373);
        if (infor->num>1)
        {
            outtextxy(626,610,">",2,2,10,44373);
        }
        
        
    }
    
    // bar(140,610,170,640,0);//�жϵ������
    // bar(630,610,660,640,0);
    // outtextxy(135,610,"<",2,2,10,44373);
    // outtextxy(626,610,">",2,2,10,44373);


    // ��ʱ��һ��ֵ�Ƿ���ȷ
    // outtextxy(415,385,ordernum,1,1,10,44373);
    // outtextxy(415,355,ordercnt,1,1,10,44373);
    // outtextxy(415,315,infor->phone_num,1,1,10,44373);

    //��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//  ���ESC�˳�ϵͳ
        {
            exit(0);
        }
        //˳����ʾ����
        // else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
        // {
        //     page++;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(630,610,660,640,65535);//�ڸ��Ҳ��ͷ
        //     //���Ҽ�
        //     outtextxy(135,610,"<",2,2,10,44373);
        //     if (page < infor->num)
        //     {
        //         outtextxy(626,610,">",2,2,10,44373);
        //     }
        //     //��ʾ�ڼ�������
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        // else if (page>1 && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//���<�鿴��һҳ����
        // {
        //     page--;
        //     sprintf(filename,"%d_%d",infor->cnt,page);
        //     mousehide(*x,*y);
	    //     printf_image(96,300,670,630,filename);
        //     bar(140,610,170,640,65535);//�ڸ�����ͷ
        //     //���Ҽ�
            
        //     outtextxy(626,610,">",2,2,10,44373);
        //     if (page > 1)
        //     {
        //         outtextxy(135,610,"<",2,2,10,44373);
        //     }
        //     //��ʾ�ڼ�������
        //     sprintf(orderpage,"%d",page);
        //     bar(390,265,430,290,65535);
        //     outtextxy(395,265,orderpage,1,1,10,44373);
        //     reset_mouse(x,y);
        // }
        //����������ʾ����
        else if (page>0 && page<infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
        {
            page--;
            findOrder(infor,order,page);
            mousehide(*x,*y);
            //��ʾ��Ϣ
	        showorder(order);
            bar(630,610,660,640,65535);//�ڸ��Ҳ��ͷ
            //���Ҽ�
            outtextxy(135,610,"<",2,2,10,44373);
            if (page > 1)
            {
                outtextxy(626,610,">",2,2,10,44373);
            }
            //��ʾ�ڼ�������
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
        else if (page < infor->num && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//���<�鿴��һҳ����
        {
            page++;
            findOrder(infor,order,page);
            mousehide(*x,*y);
            //��ʾ��Ϣ
	        showorder(order);
            bar(140,610,170,640,65535);//�ڸ�����ͷ
            //���Ҽ�
            
            outtextxy(626,610,">",2,2,10,44373);
            if (page < infor->num)
            {
                outtextxy(135,610,"<",2,2,10,44373);
            }
            //��ʾ�ڼ�������
            sprintf(orderpage,"%d",page);
            bar(390,265,430,290,65535);
            outtextxy(395,265,orderpage,1,1,10,44373);
            reset_mouse(x,y);
        }
    }
    free(ordernum);
    free(orderpage);
    ordernum=NULL;
    orderpage=NULL;
    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"order");
    reset_mouse(x,y);
}

void showorder(ORDER *order)
{
    bar(96,300,670,630,65535);

    linelevel(128,310,335,310,3,63422);
    linelevel(431,310,638,310,3,63422);
    fdhz(345,305,1,1,"��������",44373);

    fdhz(135,350,1,1,"��������",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"�쳵",44373);

    fdhz(390,350,1,1,"����",44373);
    outtextxy(430,350,":",1,1,10,44373);
    outtextxy(445,350,order->money,1,1,10,44373);

    fdhz(135,390,1,1,"������",44373);
    outtextxy(195,390,":",1,1,10,44373);
    fdhz(210,390,1,1,order->startname,44373);

    fdhz(390,390,1,1,"Ŀ�ĵ�",44373);
    outtextxy(450,390,":",1,1,10,44373);
    fdhz(465,390,1,1,order->endname,44373);

    fdhz(135,430,1,1,"����",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,order->orderstime,1,1,10,44373);

    linelevel(128,470,335,270,3,63422);
    linelevel(431,470,638,270,3,63422);
    fdhz(345,465,1,1,"˾����Ϣ",44373);

    fdhz(135,510,1,1,"˾��",44373);
    outtextxy(175,510,":",1,1,10,44373);
    fdhz(190,510,1,1,order->name,44373);
    fdhz(210,510,1,1,"ʦ��",44373);

    fdhz(135,550,1,1,"����",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"��",44373);
    outtextxy(205,550,"A",1,1,10,44373);
    outtextxy(220,550,order->carname,1,1,10,44373);

    fdhz(135,590,1,1,"����",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,order->type,44373);

}