#include "common.h"
#include "useinfor.h"



/********************************************
������Ϣ��غ���
infor_box()
leading_box()
leading_fast()
leading_rent()
order_box()
showorder()
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
    // fdhz(200,565,2,2,"����",44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

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
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
        {
            break;
        }
        
        else if(mx>=88 && mx<=678 && my>=231 && my<=367 && button)//�쳵ָ��
        {
            leading_fast(x,y);
            
        }
        else if(mx>=88 && mx<=678 && my>=369 && my<=509 && button)//С���⳵ָ��
        {
            leading_rent(x,y);
        }
        // else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//����ָ��
        // {
        //     leading_bus(x,y);
        // }
        
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

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

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
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
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

    outtextxy(340,375,"0.68",1,1,10,44373);
    fdhz(390,375,1,1,"Ԫ",44373);
    outtextxy(410,375,"/min",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

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
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
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

// void leading_bus(int *x,int *y)
// {
//     int button=0;
//     int mx=0;
//     int my=0;
//     mousehide(*x,*y);
//     //���汳��
//     save_image(88,231,678,637,"leadbus");
//     //��ͼ
//     bar(88,231,678,580,65535);
//     bar(98,580,670,630,65535);

//     linelevel(88,270,335,270,3,63422);
//     linelevel(431,270,678,270,3,63422);
//     fdhz(345,265,1,1,"��·�滮",44373);

//     fdhz(140,315,1,1,"���ѡ����ʺ��Լ����еķ���",44373);
//     outtextxy(415,315,"?",1,1,10,44373);

//     fdhz(140,355,1,1,"��·�߻���ҳ��",44373);
//     outtextxy(275,355,",",1,1,10,44373);
//     fdhz(290,355,1,1,"ϵͳ��Ĭ��չʾ����Ŀ�ĵ���ʱ��̵�",44373);
//     fdhz(140,385,1,1,"����",44373);
//     fdhz(140,415,1,1,"��Ҳ����ѡ��",44373);
//     outtextxy(255,415,",",1,1,10,44373);
//     fdhz(270,415,1,1,"�ٻ���",44373);
//     outtextxy(325,415,",",1,1,10,44373);
//     fdhz(340,415,1,1,"�ٲ��е��Ƽ�����",44373);
//     outtextxy(495,415,",",1,1,10,44373);
//     fdhz(510,415,1,1,"�Ӷ�ѡ�����",44373);
//     fdhz(140,445,1,1,"�ʵĹ������з���",44373);

//     lean_line_thick(608,143,30,45,3,64384);
// 	lean_line_thick(608,143+20,30,-45,3,64384);//�����

//     //��ʾ���
//     reset_mouse(x,y);

//     while (1)
//     {
//         newxy(x,y,&button);
// 		mx = *x;
// 		my = *y;
//         if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)
//         {
//             break;
//         }
//         else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
//         {
//             break;
//         }
//         else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
//         {
//             exit(0);
//         }
        
//     }

//     //��ʾ����
//     mousehide(*x,*y);   
//     printf_image(88,231,678,637,"leadbus");
//     reset_mouse(x,y);
// }



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

void order_box(int *x,int *y,USEINFOR *infor)//��ʾ����
{
    int button=0;
    int mx=0;
    int my=0;
    char ch[7];
    mousehide(*x,*y);
    
    
    //���汳��
    save_image(83,109,683,659,"order");

    //��ͼ
	bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
	fdhz(272,135,3,3,"��ʷ����",44373);
    bar(88,200,678,230,63422);

    

    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);

    
    fdhz(200,285,2,2,"��������",44373);
    sprintf(ch,"%d",infor->num+infor->rentnum);
    outtextxy(380,285,ch,2,2,20,44373);
    fdhz(200,423,2,2,"�쳵����",44373);
    fdhz(200,565,2,2,"�⳵����",44373);

	lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

	 while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;

        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
		if (mx>=88 && mx<=678 && my>=369 && my<=509 && button)//����쳵����쳵��ʷ������ѯ
        {
            fastorder(x,y,infor);
            
        }
        else if(mx>=88 && mx<=678 && my>=511 && my<=657 && button)//���С���⳵�����⳵��ʷ������ѯ
        {
            rentorder(x,y,infor);
        }
		else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��

        {
            break;
        }
    }
    
    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"order");
    reset_mouse(x,y);
}

void fastorder(int *x,int *y,USEINFOR *infor)//��ȡ�ļ���ʽ��ʾ����
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
    if ((order = (ORDER *)malloc(sizeof(ORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
  
    sprintf(ordernum,"%d",infor->num);
    
    //���汳��
    save_image(83,109,683,659,"faorder");

    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"��ʷ����",44373);
    bar(88,200,678,230,63422);
    
    
    // bar(96,300,670,630,0);
    fdhz(135,250,1,1,"�쳵����",44373);
    outtextxy(215,250,":",1,1,10,44373);
    outtextxy(230,250,ordernum,1,1,10,44373);
    
    linelevel(88,275,335,270,3,63422);
    linelevel(431,275,678,270,3,63422);
    fdhz(350,265,1,1,"����",44373);
    // bar(390,265,430,290,0);//�����ڸ�λ��
    // outtextxy(395,265,"12",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

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
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
        {
            break;
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
        else if (page>1 && page<=infor->num && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
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
    free(order);
    ordernum=NULL;
    orderpage=NULL;
    order=NULL;
    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"faorder");
    reset_mouse(x,y);
}

void rentorder(int *x,int *y,USEINFOR *infor)//��ȡ�ļ���ʽ��ʾ�⳵����
{
    int button=0;
    int mx=0;
    int my=0;
    char *ordernum;//���ڽ�int��תΪ�ַ�����
    char *orderpage;
    // int page=0;//���ڼ�¼��Ȼ��������һҳ
    int page = infor->rentnum;//����������ʾ
    char filename[20];//������
    RENTORDER *order;
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
    if ((order = (RENTORDER *)malloc(sizeof(RENTORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
  
    sprintf(ordernum,"%d",infor->rentnum);
    
    //���汳��
    save_image(83,109,683,659,"reorder");

    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(272,135,3,3,"��ʷ����",44373);
    bar(88,200,678,230,63422);
    
    
    // bar(96,300,670,630,0);
    fdhz(135,250,1,1,"�⳵����",44373);
    outtextxy(215,250,":",1,1,10,44373);
    outtextxy(230,250,ordernum,1,1,10,44373);
    
    linelevel(88,275,335,270,3,63422);
    linelevel(431,275,678,270,3,63422);
    fdhz(350,265,1,1,"����",44373);
    // bar(390,265,430,290,0);//�����ڸ�λ��
    // outtextxy(395,265,"12",1,1,10,44373);

    lean_line_thick(608,143,30,45,3,64384);
	lean_line_thick(608,143+20,30,-45,3,64384);//�����

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
    if (infor->rentnum!=0)
    {
        
        findRentOrder(infor,order,page);
        //��ʾ�ڼ�������
        sprintf(orderpage,"%d",page);
        bar(390,265,430,290,65535);
        outtextxy(395,265,orderpage,1,1,10,44373);
        
        //��ʾ������Ϣ
        showrentorder(order);

        //���Ҽ�
        // outtextxy(135,610,"<",2,2,10,44373);
        if (infor->rentnum>1)
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
        else if(mx>=608  && mx<=628 && my>=143 && my<=163 && button)//�����淵��
        {
            break;
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
        else if (page>1 && page<=infor->rentnum && mx>=630  && mx<=660 && my>=610 && my<=640 && button)//���>�鿴��һҳ����
        {
            page--;
            findRentOrder(infor,order,page);
            mousehide(*x,*y);
            //��ʾ��Ϣ
	        showrentorder(order);
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
        else if (page < infor->rentnum && mx>=140  && mx<=170 && my>=610 && my<=640 && button)//���<�鿴��һҳ����
        {
            page++;
            findRentOrder(infor,order,page);
            mousehide(*x,*y);
            //��ʾ��Ϣ
	        showrentorder(order);
            bar(140,610,170,640,65535);//�ڸ�����ͷ
            //���Ҽ�
            
            outtextxy(626,610,">",2,2,10,44373);
            if (page < infor->rentnum)
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
    free(order);
    ordernum=NULL;
    orderpage=NULL;
    order=NULL;
    //��ʾ����
    mousehide(*x,*y);   
    printf_image(83,109,683,659,"reorder");
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
//��ʾ�⳵��������
void showrentorder(RENTORDER *order)
{
    bar(96,300,670,630,65535);

    linelevel(128,310,335,270,3,63422);
    linelevel(431,310,638,270,3,63422);
    fdhz(345,305,1,1,"��������",44373);

    fdhz(135,350,1,1,"��������",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"�⳵",44373);

    fdhz(135,390,1,1,"��ʱ��",44373);
    outtextxy(195,390,":",1,1,10,44373);
    outtextxy(210,390,order->during,1,1,10,44373);
    fdhz(250,390,1,1,"����",44373);
    
    fdhz(135,430,1,1,"����",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,order->money,1,1,10,44373);
    fdhz(250,430,1,1,"Ԫ",44373);
	
    fdhz(135,470,1,1,"����",44373);
    outtextxy(175,470,":",1,1,10,44373);
    outtextxy(190,470,order->orderstime,1,1,10,44373);
	 
    linelevel(128,510,335,510,3,63422);
    linelevel(431,510,638,510,3,63422);
    fdhz(345,505,1,1,"������Ϣ",44373);

    fdhz(135,550,1,1,"����",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"��",44373);
    outtextxy(205,550,"AD",1,1,10,44373);
    outtextxy(230,550,order->carname,1,1,10,44373);

    fdhz(135,590,1,1,"����",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,"����",44373);

}