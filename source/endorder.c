#include "common.h"
#include "endorder.h"




// ����ɺ����ɶ���
void neworder(int *x,int *y,USEINFOR *infor, const CARFAST car[], const char **placename, int *aimplace, int mincar, char *ordertime,float price)
{
    int button=0;
    int mx=0;
    int my=0;
    char chprice[8];
    ORDER *ordernew;
    
	if ((ordernew = (ORDER *)malloc(sizeof(ORDER))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
    sprintf(chprice,"%.2f",price);

    save_image(83,109,683,659,"orderadd");

    mousehide(*x,*y);
    // ��ͼ
    //���ؼ�
    bar_round(976,664,76,44,15,1,64384);
    bar_round(976,664,70,39,13,1,65535);
    outtextxy(938,645,"Back",2,2,15,64384);

    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(340,135,3,3,"����",44373);
    bar(88,200,678,230,63422);



    //����Ҫ��ȡ�����ݣ����һ�д�ֵ

    linelevel(128,310,335,270,3,63422);
    linelevel(431,310,638,270,3,63422);
    fdhz(345,305,1,1,"��������",44373);

    fdhz(135,350,1,1,"��������",44373);
    outtextxy(215,350,":",1,1,10,44373);
    fdhz(230,350,1,1,"�쳵",44373);

    fdhz(390,350,1,1,"����",44373);
    outtextxy(430,350,":",1,1,10,44373);
    outtextxy(445,350,chprice,1,1,10,44373);

    fdhz(135,390,1,1,"������",44373);
    outtextxy(195,390,":",1,1,10,44373);
    fdhz(210,390,1,1,placename[infor->nowplace],44373);

    fdhz(390,390,1,1,"Ŀ�ĵ�",44373);
    outtextxy(450,390,":",1,1,10,44373);
    fdhz(465,390,1,1,placename[*aimplace],44373);

    fdhz(135,430,1,1,"����",44373);
    outtextxy(175,430,":",1,1,10,44373);
    outtextxy(190,430,ordertime,1,1,10,44373);

    linelevel(128,470,335,270,3,63422);
    linelevel(431,470,638,270,3,63422);
    fdhz(345,465,1,1,"˾����Ϣ",44373);

    fdhz(135,510,1,1,"˾��",44373);
    outtextxy(175,510,":",1,1,10,44373);
    fdhz(190,510,1,1,car[mincar].name,44373);
    fdhz(210,510,1,1,"ʦ��",44373);

    fdhz(135,550,1,1,"����",44373);
    outtextxy(175,550,":",1,1,10,44373);
    fdhz(190,550,1,1,"��",44373);
    outtextxy(205,550,"A",1,1,10,44373);
    outtextxy(220,550,car[mincar].fastcar.carname,1,1,10,44373);

    fdhz(135,590,1,1,"����",44373);
    outtextxy(175,590,":",1,1,10,44373);
    fdhz(190,590,1,1,car[mincar].fastcar.type,44373);

    reset_mouse(x,y);
    strcpy(ordernew->name,car[mincar].name);
    strcpy(ordernew->carname,car[mincar].fastcar.carname);
    strcpy(ordernew->type,car[mincar].fastcar.type);
    strcpy(ordernew->startname,placename[infor->nowplace]);
    strcpy(ordernew->endname,placename[*aimplace]);
    strcpy(ordernew->money,chprice);
    strcpy(ordernew->orderstime,ordertime);
    // changeOrder(infor);//�����ļ��еĶ����������Լ����ɱ��ζ�����ͼƬ������
    addOrder(infor,ordernew);//��������Ϣ����ļ�
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
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
    }
    
    mousehide(*x,*y);
    printf_image(83,109,683,659,"orderadd");
    //��BACK�������ڵ�
    bar_round(976,664,76,44,15,1,65523);
    reset_mouse(x,y);

}


/*******************************
 ������̣�3km
 ����ʱ����9min
 ��̼��㷽����50���ص� = 1����
               ������������1����
 ʱ�����㷽����2min = 1s
               ������������1����
 ����˵���� timegap:�����Ǽ���ʱ�䳤��
			timegap=0:����Ԥ�Ƽ۸�
			timegap!=0:�������ռ۸�
			
			timecase:�����жϼ۸���㷽��
			timecase=0:����Ԥ�Ƽ۸� �𲽼�11Ԫ����̷�1.8Ԫ/KM
			timecase=1: 0:00-9:00ʱ�Σ��𲽼�11Ԫ����̷�2.6Ԫ/KM��ʱ����0.5Ԫ/min
			timecase=2: 12:00-15:00ʱ�Σ��𲽼�11Ԫ����̷�1.8Ԫ/KM��ʱ����0.5Ԫ/min
			timecase=3: 17:00-00:00ʱ�Σ��𲽼�11Ԫ����̷�1.8Ԫ/KM��ʱ����0.5Ԫ/min
			timecase=4: ��ͨʱ�Σ��𲽼�10.3Ԫ����̷�1.70Ԫ/KM,ʱ����0.35Ԫ/min
********************************/
void countprice(float *pointprice,int nowplace,int *aimplace,int timegap,int timecase)//���ڼ���۸�
{
	int kilometer;//���ڼ��㹫����
	int minite;//���ڼ���ʱ��
	float startfare;//���ڼ����𲽼�
	int pointlength[15];//����֮����̷�����
    int judging=0;//�����ж�ѡ����һ��length

    pointlength[0]=507;//ѧУ��С��֮��
	pointlength[1]=690;//ѧУ�Ͷ���֮��
	pointlength[2]=240;//ѧУ���̳�֮��
	pointlength[3]=1000;//ѧУ��ͼ���֮��
	pointlength[4]=553;//ѧУ����Ӿ��֮��
	pointlength[5]=1012;//С���Ͷ���֮��
	pointlength[6]=609;//С�����̳�֮��
	pointlength[7]=663;//С����ͼ���֮��
	pointlength[8]=726;//С������Ӿ��֮��
	pointlength[9]=646;//�������̳�֮��
	pointlength[10]=1086;//������ͼ���֮��
	pointlength[11]=529;//��������Ӿ��֮��
	pointlength[12]=760;//�̳���ͼ���֮��
	pointlength[13]=313;//�̳�����Ӿ��֮��
	pointlength[14]=557;//ͼ��ݺ���Ӿ��֮��
	
	
	
	if((nowplace==0&&*aimplace==1)||(nowplace==1&&*aimplace==0))
	{
		judging=0;
	}
	else if((nowplace==0&&*aimplace==2)||(nowplace==2&&*aimplace==0))
	{
		judging=1;
	}
	else if((nowplace==0&&*aimplace==3)||(nowplace==3&&*aimplace==0))
	{
		judging=2;
	}
	else if((nowplace==0&&*aimplace==4)||(nowplace==4&&*aimplace==0))
	{
		judging=3;
	}
	else if((nowplace==0&&*aimplace==5)||(nowplace==5&&*aimplace==0))
	{
		judging=4;
	}
	else if((nowplace==1&&*aimplace==2)||(nowplace==2&&*aimplace==1))
	{
		judging=5;
	}
	else if((nowplace==1&&*aimplace==3)||(nowplace==3&&*aimplace==1))
	{
		judging=6;
	}
	else if((nowplace==1&&*aimplace==4)||(nowplace==4&&*aimplace==1))
	{
		judging=7;
	}
	else if((nowplace==1&&*aimplace==5)||(nowplace==5&&*aimplace==1))
	{
		judging=8;
	}
	else if((nowplace==2&&*aimplace==3)||(nowplace==3&&*aimplace==2))
	{
		judging=9;
	}
	else if((nowplace==2&&*aimplace==4)||(nowplace==4&&*aimplace==2))
	{
		judging=10;
	}
	else if((nowplace==2&&*aimplace==5)||(nowplace==5&&*aimplace==2))
	{
		judging=11;
	}
	else if((nowplace==3&&*aimplace==4)||(nowplace==4&&*aimplace==3))
	{
		judging=12;
	}
	else if((nowplace==3&&*aimplace==5)||(nowplace==5&&*aimplace==3))
	{
		judging=13;
	}
	else if((nowplace==4&&*aimplace==5)||(nowplace==5&&*aimplace==4))
	{
		judging=14;
	}
	
    //80���ص�һ����
	kilometer=(pointlength[judging])/80+1-3;
	if(kilometer<0)
	{
		kilometer=0;
	}
	// minite=timegap/120+1-9;
    minite=timegap+1-9;//���ļ�ʱ����һ����һ����
	if(minite<0)
	{
		minite=0;
	}
	
	switch(timecase)
	{
		case 0:
			startfare=11;
			*pointprice=startfare+kilometer*1.8;
			break;
		
		case 1:
			startfare=11;
			*pointprice=startfare+kilometer*2.6+minite*0.5;
			break;
		
		case 2:
		case 3:
			startfare=11;
			*pointprice=startfare+kilometer*1.8+minite*0.5;
			break;

		case 4:
			startfare=10.3;
			*pointprice=startfare+kilometer*1.7+minite*0.35;
			break;
	}

}
//��ɶ�������ʾ��ȷ��֧��
void costmoney(float *price,USEINFOR *infor,int *aimplace,int nowtime_hour,int timegap, int *x, int *y, int waitime)
{
    int timecase;
    char chprice[8];
    int mx=0;
    int my=0;
    int button=0;

    //����ʱ��μƷ�
    if (nowtime_hour >= 0 && nowtime_hour <= 8)
    {
        timecase = 1;
    }
    else if (nowtime_hour >= 12 && nowtime_hour <= 14)
    {
        timecase = 2;
    }
    
    else if (nowtime_hour >= 17 && nowtime_hour <= 23)
    {
        timecase = 3;
    }
    else 
    {
        timecase = 4;
    }
    countprice(price,infor->nowplace,aimplace,timegap,timecase);
    
    if (waitime != 0 && *price < 19.00)//�����ԤԼ��ԤԼ��������Ϊ19.00
    {
        *price = 19.00;
    }
    if (infor->payway == 1)//��Ϊ���֧����9��
    {
        *price=(*price)*0.9;
    }
    sprintf(chprice,"%.2f",*price);

    mousehide(*x,*y);
    save_image(512-210,384-140,512+210,384+140,"notice");
    //��ʾ���
    bar_round(512,384,416,270,50,1,64384);
    bar_round(512,384,410,265,48,1,65535);
    fdhz(410,360,2,2,"���",64384);
	outtextxy(475,360,":",2,2,20,64384);
	outtextxy(500,360,chprice,2,2,20,64384);
    bar_round(512,460,190,52,20,1,64384);
    bar_round(512,460,184,47,18,1,65535);
	fdhz(466,446,2,2,"ȷ",44373);
    fdhz(526,446,2,2,"��",44373);
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=417  && mx<=607 && my>=433 && my<=487 && button)//���ȷ��
        {
            break;
        }
        

    }
    mousehide(*x,*y);
    printf_image(512-210,384-140,512+210,384+140,"notice");
    reset_mouse(x,y);
    while (1)
    {
        if (infor->payway == 1)//֧����ʽΪ���
        {
            if (infor->money>=*price)
            {
                changeMoney(infor,*price);
                mousehide(*x,*y);
                save_image(512-210,384-140,512+210,384+140,"notice");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(440,360,2,2,"֧�����",64384);
                fdhz(450,420,1,1,"�����������",44373);
                
                getch();
                printf_image(512-210,384-140,512+210,384+140,"notice");
                reset_mouse(x,y);
                break;
            }
        
            else  //������
            {
                mousehide(*x,*y);
                save_image(512-210,384-140,512+210,384+140,"notice");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(440,360,2,2,"����",64384);
                fdhz(450,420,1,1,"���������ֵ",44373);
                getch();
                reset_mouse(x,y);
                top_up(x,y,infor);
                printf_image(512-210,384-140,512+210,384+140,"notice");
                reset_mouse(x,y);
            }
        }
        else if (infor->payway == 2)//֧����ʽΪ΢��
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            bar_round(255-30+160,480-100,70,70,22,1,2016);//΢����
            FillCircle(221+160,480-100,20,65535);
            FillCircle(241+160,490-100,15,2016);
            FillCircle(241+160,490-100,13,65535);
            FillCircle(241-6+160,490-2-100,2,2016);
            FillCircle(241+6+160,490-2-100,2,2016);
            FillCircle(221-9+160,480-3-100,2,2016);
            FillCircle(221+9+160,480-3-100,2,2016);

            fdhz(440,360,2,2,"֧�����",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();
            
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
            break;
        }
        else if (infor->payway == 3)//֧����ʽΪ֧����
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            //��֧����
            bar_round(510-30-95,480-100,70,70,22,1,1535);//֧������
            fdhz(455-95,450-100,4,4,"֧",65535);

            fdhz(440,360,2,2,"֧�����",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();
            
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
            break;
        }
        else      //��δѡ��֧����ʽ�����֧����ʽѡ��
        {
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            
            fdhz(390,360,2,2,"δѡ��֧����ʽ",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();
            reset_mouse(x,y);
            pay_way(x,y,infor);   
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
        }
        
    }
     
}