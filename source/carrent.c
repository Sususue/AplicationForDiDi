#include "common.h"
#include "carrent.h"

// #define PARKNUM 6

void car_rent_box(int* x, int* y, USEINFOR *infor)
{
	int button=0;
    int mx=0;
    int my=0;
	PARK parking[PARKNUM];
	CARRENT rent[PARKNUM];
	int snumber=0;//����ͣ�����ı��
	char carnumber[6][3];//����ͣ�����ϳ�����Ŀ��ת��
	int carflag;//���ڴ���ѡ��С������Ϣ
	int flaging;//�����жϴ�ͣ������Ϣ���淵��ʱ������һ���߼�
	
	newpark(parking);
	
	mousehide(*x,*y);
	//���汳��
    save_image(771,2,996,612,"carrent");
	
	//��ɫ
    bar(771,2,996,612,65523);
	
	//��ͣ������λ��
	FillCircle(317,70,30,9284);//����
	FillCircle(513,223,30,9284);//��Ӿ��
	FillCircle(100,420,30,9284);//ѧУ
	FillCircle(340,510,30,9284);//�̳�
	FillCircle(182,674,30,9284);//С��
	FillCircle(670,530,30,9284);//ͼ���
	
	//��ͣ�����ϳ�����Ŀ
	sprintf(carnumber[2],"%d",parking[2].carnum);
	outtextxy(299,54,carnumber[2],2,2,1,65535);//����
	
	sprintf(carnumber[5],"%d",parking[5].carnum);
	outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
	
	sprintf(carnumber[0],"%d",parking[0].carnum);
	outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
	
	sprintf(carnumber[3],"%d",parking[3].carnum);
	outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
	
	sprintf(carnumber[1],"%d",parking[1].carnum);
	outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
	
	sprintf(carnumber[4],"%d",parking[4].carnum);
	outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
	
	
	//С���⳵
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
	fdhz(805,67,3,3,"С",64384);
    fdhz(850,67,3,3,"��",64384);
    fdhz(900,67,3,3,"��",64384);
    fdhz(945,67,3,3,"��",64384);
	
	//ȥѡ��
	bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
	fdhz(855,190,1,1,"ȥ",64384);
    fdhz(890,190,1,1,"ѡ",64384);
    fdhz(925,190,1,1,"��",64384);
	
	//�����Ϣ����
	fdhz(805,270,1,1,"����ָ��վ����ѡ��",64384);
	outtextxy(980,270,",",1,1,1,64384);
	fdhz(805,300,1,1,"�µ����������ó�",64384);
	
	fdhz(805,360,1,1,"�ó��ڼ������ؽ�ͨ",64384);
	fdhz(805,390,1,1,"����",64384);
	outtextxy(839,390,",",1,1,1,64384);
	fdhz(848,390,1,1,"����滮����ʱ",64384);
	fdhz(805,420,1,1,"�����·",64384);
	outtextxy(880,420,",",1,1,1,64384);
	fdhz(894,420,1,1,"�ž��Ƽ�",64384);
	outtextxy(969,420,",",1,1,1,64384);
	fdhz(805,450,1,1,"ƣ�ͼ�ʻ�Ȳ���ȫ��",64384);
	fdhz(805,480,1,1,"ʻ��Ϊ",64384);
	outtextxy(862,480,".",1,1,1,64384);
	
	
	
	
	reset_mouse(x,y);
	 while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
		
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            //�Ե�ͼ��ԭ�е�ͣ���������ڵ�
			FillCircle(317,70,30,57083);//����
			FillCircle(513,223,30,57083);//��Ӿ��
			FillCircle(100,420,30,57083);//ѧУ
			FillCircle(340,510,30,57083);//�̳�
			FillCircle(182,674,30,57083);//С��
			FillCircle(670,530,30,57083);//ͼ���
			
            break;
        }
		
		else if (mx>=798  && mx<=994 && my>=172 && my<=224 && button)//���ȥѡ����������������ѡ��ͣ����
        {
            mousehide(*x,*y);

            save_image(512-210,384-140,512+210,384+140,"unpark");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(355,360,2,2,"��ѡ��ͼ��ͣ����",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"unpark");
			
            reset_mouse(x,y);
        }
		
		else if (mx>=287  && mx<=347 && my>=40  && my<=110 && button)//�������ͣ����
		{
			snumber=2;
		
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
			
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
		}
		
		else if (mx>=483  && mx<=543 && my>=193  && my<=253 && button)//�����Ӿ��ͣ����
		{
			snumber=5;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
		}
		
		else if (mx>=70  && mx<=130 && my>=390  && my<=450 && button)//���ѧУͣ����
		{
			snumber=0;
	
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
		}
		
		else if (mx>=310  && mx<=370 && my>=480  && my<=540 && button)//����̳�ͣ����
		{
			snumber=3;

			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
		}
		
		else if (mx>=152  && mx<=212 && my>=644  && my<=704 && button)//���С��ͣ����
		{
			snumber=1;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
		}
		
		else if (mx>=640  && mx<=700 && my>=500  && my<=560 && button)//���ͼ���ͣ����
		{
			snumber=4;
			
			show_parkinfo(x,y,parking,rent,snumber,&carflag,&flaging);
			
			if(flaging!=1)
			{
				//�Ե�ͼ��ԭ�е�ͣ���������ڵ�
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				
				rentprocess_box(x,y,parking,rent,&carflag,infor);
				
				//��ͣ������λ��
				FillCircle(317,70,30,9284);//����
				FillCircle(513,223,30,9284);//��Ӿ��
				FillCircle(100,420,30,9284);//ѧУ
				FillCircle(340,510,30,9284);//�̳�
				FillCircle(182,674,30,9284);//С��
				FillCircle(670,530,30,9284);//ͼ���
				//��ͣ�����ϳ�����Ŀ
				sprintf(carnumber[2],"%d",parking[2].carnum);
				outtextxy(299,54,carnumber[2],2,2,1,65535);//����
		
				sprintf(carnumber[5],"%d",parking[5].carnum);
				outtextxy(495,207,carnumber[5],2,2,1,65535);//��Ӿ��
		
				sprintf(carnumber[0],"%d",parking[0].carnum);
				outtextxy(82,404,carnumber[0],2,2,1,65535);//ѧУ
		
				sprintf(carnumber[3],"%d",parking[3].carnum);
				outtextxy(322,494,carnumber[3],2,2,1,65535);//�̳�
		
				sprintf(carnumber[1],"%d",parking[1].carnum);
				outtextxy(164,658,carnumber[1],2,2,1,65535);//С��
		
				sprintf(carnumber[4],"%d",parking[4].carnum);
				outtextxy(652,514,carnumber[4],2,2,1,65535);//ͼ���
			}
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
	
	//��ʾ����
    mousehide(*x,*y); 
    printf_image(771,2,996,612,"carrent");
	
	//��ʾ���
    reset_mouse(x,y);
	
}


/*typedef struct park{
	int parknum;        //��ͣ�����ı��
    int carnum;   //��������
	int x;  //ͣ����λ��
	int y;
}PARK;


typedef struct carrent{
	int parknum;        //����ͣ�����ı��
    CARINFOR rentcar;
	int leftenergy;        //����ʣ�����
}CARRENT;          //������������Ϣ*/

int show_parkinfo(int *x,int *y,const PARK parking[],CARRENT rent[],int nuber,int *carflag1,int *flaging1)//������ʾͣ������Ϣ�ĺ���
{
	int button=0;
    int mx=0;
    int my=0;
	int showx=120;
	int showy=255;//�������������Ϣ�ĺ�������(��ʼ���ڵ�һ�����������)
	char parknumber[3];//����ͣ������ŵ���������ת��
	char lenergy[5];//����ʣ���������������ת��
	int i=0;//�������������Ϣ��ѭ��
	int unchoose=0;//�����ж��Ƿ�ѡ���˿��⳵��
	
	newrentcar(rent,parking,nuber);
    
	mousehide(*x,*y);
	
	save_image(83,109,683,659,"parkinfo");
	
	bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);//�װ�
	
	sprintf(parknumber,"%d",parking[nuber].parknum);
	outtextxy(285,128,parknumber,2,2,15,44373);
    fdhz(325,128,2,2,"��ͣ����",44373);//��ʾͣ���������Ϣ
	
	lean_line_thick(608,133,30,45,3,64384);
	lean_line_thick(608,133+20,30,-45,3,64384);//�����
	
	bar(88,180,678,210,63422);
	bar(88,300,678,302,63422);
	bar(88,390,678,392,63422);
	bar(88,480,678,482,63422);
	bar(88,570,678,572,63422);//�ָ���
	
	
	for(i=0;i<parking[nuber].carnum;i++)
	{
		fdhz(showx,showy-10,2,2,rent[0].rentcar.type,44373);//����
		
		fdhz(showx+100,showy,1,1,"ʣ�����",44373);
		outtextxy(showx+170,showy,":",1,1,1,44373);
		sprintf(lenergy,"%d",rent[i].leftenergy);
		outtextxy(showx+190,showy,lenergy,1,1,12,44373);
		outtextxy(showx+220,showy,"%",1,1,1,44373);//ʣ�����
		
		outtextxy(showx+270,showy,"0.69",1,1,12,44373);
		fdhz(showx+330,showy,1,1,"Ԫ",44373);
		outtextxy(showx+345,showy,"/",1,1,1,44373);
		fdhz(showx+360,showy,1,1,"����",44373);//�۸�
		
		showy=showy+90;
		
	}
	
	bar_round(383,610,100,50,15,1,64384);
	bar_round(383,610,96,46,15,1,65535);
	fdhz(350,595,2,2,"ȷ��",64384);//ȷ�Ͽ�
	
	
	
	reset_mouse(x,y);
	while(1)
	{
	    newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		if(mx>=333 && mx<=433 && my>=585 && my<=635 && button)//���ȷ�Ͽ�
		{
			if(unchoose==0)
			{
				mousehide(*x,*y);

                save_image(383-210,384-140,512+210,384+140,"unchoose1");
                bar_round(383,384,416,270,50,1,64384);
                bar_round(383,384,410,265,48,1,65535);
                fdhz(230,360,2,2,"����δѡ����",64384);
                fdhz(320,420,1,1,"�����������",44373);
                getch();
                printf_image(383-210,384-140,512+210,384+140,"unchoose1");
                reset_mouse(x,y);
			}
			
			else
			{			
				*flaging1=0;
				break;
			}
		}
		if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
			*flaging1=1;
            break;
        }
		if(mx>=608  && mx<=628 && my>=133 && my<=153 && button)//�����淵��
        {
			*flaging1=1;
            break;
        }
		
		switch(parking[nuber].carnum)
		{
			case 1:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			break;
			
			case 2:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
				
				reset_mouse(x,y);
			}
			break;
			
			case 3:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,392,670,480,65535);
				
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=392 && my<=480 && button)
			{
				*carflag1=2;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,302,670,390,65535);
				
				lean_line_thick(600,442,15,45,3,64384);
				lean_line_thick(600+11,442+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			break;
			
			case 4:
			if(mx>=88 && mx<=678 && my>=210 && my<=300 && button)
			{
				*carflag1=0;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,262,15,45,3,64384);
				lean_line_thick(600+11,262+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=302 && my<=390 && button)
			{
				*carflag1=1;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,210,670,300,65535);
				bar(530,392,670,480,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,352,15,45,3,64384);
				lean_line_thick(600+11,352+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=392 && my<=480 && button)
			{
				*carflag1=2;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,210,670,300,65535);
				bar(530,482,670,570,65535);
				
				lean_line_thick(600,442,15,45,3,64384);
				lean_line_thick(600+11,442+8,40,-45,3,64384);
		
				reset_mouse(x,y);
			}
			if(mx>=88 && mx<=678 && my>=482 && my<=570 && button)
			{
				*carflag1=3;
				unchoose=1;
				mousehide(*x,*y);
				bar(530,302,670,390,65535);
				bar(530,392,670,480,65535);
				bar(530,210,670,300,65535);
				
				lean_line_thick(600,532,15,45,3,64384);
				lean_line_thick(600+11,532+8,40,-45,3,64384);
			
				reset_mouse(x,y);
			}
			break;
		}
	}
		
	
	mousehide(*x,*y);
    printf_image(83,109,683,659,"parkinfo");
    
    reset_mouse(x,y);   //���������������λ�õı���

}

void rentprocess_box(int *x, int *y,const PARK parking[],const CARRENT rent[],int *carflag2, USEINFOR *infor)
{
	//time_t nowtime1;
	//time_t nowtime2;//���ڻ�ȡ��ǰʱ��
	//struct tm *info;
	//int time_gap;//����ʱ�����ļ���
	
	//��ȡ������п쳵����ʱ��ʱ��
	//int nowtime_hour;
	//int nowtime_min;
	//int nowtime_sec;
	
	int button=0;
    int mx=0;
    int my=0;
	char lefenergy[5];//����ʣ���������������ת��
	int sigle=0;//���ڽ����˳�����
	
	mousehide(*x,*y);
	//���汳��
    save_image(771,2,996,612,"rentpro");
	
	//��ɫ
    bar(771,2,996,612,65523);
	
	//С���⳵
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
	fdhz(805,67,3,3,"С",64384);
    fdhz(850,67,3,3,"��",64384);
    fdhz(900,67,3,3,"��",64384);
    fdhz(945,67,3,3,"��",64384);
	
	//���ƺ���
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"����",64384);
	outtextxy(847,188,":",1,1,40,64384);
    fdhz(862,190,1,1,"��",64384);
    outtextxy(878,190,"AD",1,1,15,64384);
	outtextxy(910,190,rent[*carflag2].rentcar.carname,1,1,15,64384);
   
    //�ó�ʱ��
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
	fdhz(810,280,1,1,"�ó�ʱ��",64384);
    outtextxy(887,278,":",1,1,40,64384);
	outtextxy(900,280,"0",1,1,1,64384);
	fdhz(950,280,1,1,"����",64384);
   
	//��ǰ�۸�
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
	fdhz(810,370,1,1,"��ǰ�۸�",64384);
    outtextxy(887,368,":",1,1,40,64384);
	outtextxy(900,370,"00.00",1,1,10,64384);
	fdhz(960,370,1,1,"Ԫ",64384);
	
	//����
	bar_round(896,468,196,52,10,1,64384);
    bar_round(896,468,190,47,8,1,65535);
	fdhz(810,460,1,1,"����",64384);
    outtextxy(847,458,":",1,1,40,64384);
	sprintf(lefenergy,"%d",rent[*carflag2].leftenergy);
	outtextxy(877,459,lefenergy,1,1,12,64384);
	outtextxy(927,459,"%",1,1,1,64384);
	
	//������
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(865,550,1,1,"��",64384);
    fdhz(905,550,1,1,"��",64384);

	reset_mouse(x,y);

	sigle = find(x,y,&rent[*carflag2],infor,parking);
	//  while (1)
    // {
    //     newxy(x,y,&button);
	// 	mx = *x;
	// 	my = *y;
	
	// 	if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
    //     {
    //         break;
    //     }
	// 	else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
    //     {
    //         exit(0);
    //     }
	// 	else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
    //     {
    //         safe_box(x,y);
    //     }
	
	// }
	
	//��ʾ����
    mousehide(*x,*y); 
    printf_image(771,2,996,612,"rentpro");
	
	//��ʾ���
    reset_mouse(x,y);
}



//��ʼ����������Ϣ
void newrentcar(CARRENT *car,const PARK parking[],int number1)
{
    int i;//���ڼ���
	int m;
    int n;//���ڼ�¼�����
    PLACE rentplace[PARKNUM];
    char rentcard[25][6];//���ƺż�
    // char renttype[7];//��������
	
	
    //��ʼ������λ��
    rentplace[2].x=317;
    rentplace[2].y=25;//����
    rentplace[5].x=513;
    rentplace[5].y=268;//��Ӿ��
    rentplace[0].x=100;
    rentplace[0].y=465;//ѧУ
    rentplace[3].x=340;
    rentplace[3].y=465;//�̳�
    rentplace[1].x=182;
    rentplace[1].y=720;//С��
	rentplace[4].x=715;
    rentplace[4].y=530;//ͼ���


    //��ʼ�����ƺż�
    strcpy(rentcard[0],"B7351");
    strcpy(rentcard[1],"92857");
    strcpy(rentcard[2],"A6103");
    strcpy(rentcard[3],"61135");
    strcpy(rentcard[4],"C2861");
    strcpy(rentcard[5],"B8963");
    strcpy(rentcard[6],"C8272");
    strcpy(rentcard[7],"95512");
    strcpy(rentcard[8],"B3519");
    strcpy(rentcard[9],"93760");
	strcpy(rentcard[10],"95287");
	strcpy(rentcard[11],"A2392");
	strcpy(rentcard[12],"C6665");
	strcpy(rentcard[13],"B7328");
	strcpy(rentcard[14],"C1275");
	strcpy(rentcard[15],"91295");
	strcpy(rentcard[16],"B3028");
	strcpy(rentcard[17],"C9778");
	strcpy(rentcard[18],"A9517");
	strcpy(rentcard[19],"B2637");
	strcpy(rentcard[20],"C7970");
	strcpy(rentcard[21],"B3187");
	strcpy(rentcard[22],"A5681");
	strcpy(rentcard[23],"B1886");
	strcpy(rentcard[24],"97395");


	//��ʼ����������
    // strcpy(renttype,"����");


    srand((unsigned int)time(NULL));

	strcpy(car->rentcar.type,"����");
	
    for ( i = 0; i < parking[number1].carnum; i++, car++)
    {
        n=rand()%25;
		m=rand()%61;
		car->leftenergy=40+m;		//��ʼ������40%-100%���Ա�֤��������ʹ��
        car->rentcar.x=rentplace[number1].x;
        car->rentcar.y=rentplace[number1].y;//����ͣ������ţ���ʼ��С������ͣ������λ��
		car->parknum=number1+1;             //С������ͣ������ţ�ע���һ
        strcpy(car->rentcar.carname,rentcard[n]);
    }
}


//��ʼ��ͣ������Ϣ
void newpark(PARK *parking)
{
	int i;//���ڼ���
	int n;//���ڼ�¼�����
	PLACE parkplace[PARKNUM];
	
	//��ʼ��ͣ������λ��
    parkplace[2].x=317;
    parkplace[2].y=70;//����
    parkplace[5].x=513;
    parkplace[5].y=223;//��Ӿ��
    parkplace[0].x=100;
    parkplace[0].y=420;//ѧУ
    parkplace[3].x=340;
    parkplace[3].y=510;//�̳�
    parkplace[1].x=182;
    parkplace[1].y=674;//С��
	parkplace[4].x=670;
    parkplace[4].y=530;//ͼ���

	for ( i = 0; i < PARKNUM; i++, parking++)
    {
        n=rand()%4+1;
		parking->parknum=i+1;
        parking->x=parkplace[i].x;
        parking->y=parkplace[i].y;
		parking->carnum=n;
    }
}