#include "common.h"
#include "admin.h"

/*******************************
����Ա�����߼�
*******************************/
int admin(int *x,int *y)
{
	int mx=0;
	int my=0;
	int button=0;
	int judge;//���ڽ����Ƴ�
	int managejudge=0;//�����жϽ�����һ������  1��driver_box   2:put_diver
	CARFA thiscar;
	
	mousehide(*x,*y);
	admin_draw();//������Ա��ʼ����ͼ
	reset_mouse(x,y);
	
	while(1)
    {
        newxy(x,y,&button);
		mx=*x;
		my=*y;
		
		if(mx>= 26 && mx<=222 && my>=272 && my<=324 && button)
		{
			mousehide(*x,*y);
			fdhz(48,285,2,2,"˾",44373);
			fdhz(88,285,2,2,"��",44373);
			fdhz(128,285,2,2,"��",44373);
			fdhz(168,285,2,2,"��",44373);
			delay0(30);
			fdhz(48,285,2,2,"˾",64384);
			fdhz(88,285,2,2,"��",64384);
			fdhz(128,285,2,2,"��",64384);
			fdhz(168,285,2,2,"��",64384);
			reset_mouse(x,y);
			managejudge=1;
		}
		else if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
		{
			mousehide(*x,*y);
			fdhz(48,685,2,2,"��",44373);
			fdhz(88,685,2,2,"��",44373);
			fdhz(128,685,2,2,"��",44373);
			fdhz(168,685,2,2,"¼",44373);
			reset_mouse(x,y);
			delay0(30);
			break;//�˳���¼
		}
		
		switch(managejudge)
		{
			case 1:
				managejudge=driver_box(x,y,&thiscar);
				break;
			case 2:
				managejudge=put_diver(x,y,&thiscar);
				break;
		}
		if(managejudge==-1)
		{
			break;
		}
	}
	return 0;
}

/*******************************
˾����Ϣ����
*******************************/
int driver_box(int *x,int *y,CARFA *thiscar)
{
	int button=0;
    int mx=0;
    int my=0;
	int i=0;//����ѭ������
	int j;//����˾����Ϣѭ��
	int x1=435;
	int x2=825;
	int y1=190;//��ʼ������������
	FILE *fp = NULL;
	CARFA car;
	int flag;
	int judge;
	
	
	mousehide(*x,*y);
    //���汳��
    //save_image(249,2,1022,768,"driver");
	bar(251,138,1022,768,65535);
	
	bar(249,2,1022,132,65523);//����ѡ����
	fdhz(307,60,2,2,"˾����Ϣ��ѯ",64384);
	
	if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 


	/* for(i=0;i<5;i++)
	{
		bar_round(x1,y1,220,70,10,1,64384);
		bar_round(x1,y1,214,65,8,1,65535);
		bar_round(x2,y1,220,70,10,1,64384);
		bar_round(x2,y1,214,65,8,1,65535);//����
		
		

		// fdhz(x1-100,y1-10,1,1,"��",64384);
		// outtextxy(x1-84,y1-10,"A-",1,1,15,64384);
		// outtextxy(x1-60,y1-10,car.,1,1,15,64384);
		// fdhz(x1+60,y1-10,1,1,"�ӵ�",64384);//��ʾ���˾����Ϣ
		
		// fdhz(x2-100,y1-10,1,1,"��",64384);
		// outtextxy(x2-84,y1-10,"A-",1,1,15,64384);
		// outtextxy(x2-60,y1-10,"12345",1,1,15,64384);
		// fdhz(x2+60,y1-10,1,1,"ͣ��",64384);//��ʾ�Ҳ�˾����Ϣ
		
		y1+=110;
	} */
	
	
	//��ʾ���˾����Ϣ(0��4)
	for(i=0;i<5;i++)
	{
		bar_round(x1,y1,220,70,10,1,64384);
		bar_round(x1,y1,214,65,8,1,65535);
		bar_round(x2,y1,220,70,10,1,64384);
		bar_round(x2,y1,214,65,8,1,65535);//����

		fread(&car,sizeof(CARFA),1,fp);


		fdhz(x1-100,y1-10,1,1,"��",64384);
		outtextxy(x1-84,y1-10,"A-",1,1,15,64384);
		outtextxy(x1-60,y1-10,car.fastcar.carname,1,1,15,64384);
		if (car.call == 1)
		{
			fdhz(x1+60,y1-10,1,1,"�ӵ�",64384);
		}
		else if (car.call >= 2)
		{
			fdhz(x1+60,y1-10,1,1,"ͣ��",64384);
		}
		
		y1+=110;
	}

	y1 = 190;
	//��ʾ�Ҳ��˾����Ϣ(5��9)
	for(i=5;i<10;i++)
	{
		fread(&car,sizeof(CARFA),1,fp);
		fdhz(x2-100,y1-10,1,1,"��",64384);
		outtextxy(x2-84,y1-10,"A-",1,1,15,64384);
		outtextxy(x2-60,y1-10,car.fastcar.carname,1,1,15,64384);
		if (car.call == 1)
		{
			fdhz(x2+60,y1-10,1,1,"�ӵ�",64384);
		}
		else if (car.call >= 2)
		{
			fdhz(x2+60,y1-10,1,1,"ͣ��",64384);
		}
		y1+=110;
	}
	fclose(fp);
	
	reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=325 && mx<=545 && my>=155 && my<=225 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 0;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=265 && my<=335 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 1;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=375 && my<=445 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 2;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=485 && my<=555 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 3;
			judge = 2;
			break;
		}
		if(mx>=325 && mx<=545 && my>=595 && my<=665 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 4;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=155 && my<=225 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 5;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=265 && my<=335 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 6;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=375 && my<=445 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 7;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=485 && my<=555 &&button)
		{
			//mousehide(*x,*y);
			//put_diver(x,y);
			flag = 8;
			judge = 2;
			break;
		}
		if(mx>=715 && mx<=935 && my>=595 && my<=665 &&button)
		{
			//mousehide(*x,*y);
			//bar_round(124,698,196,52,10,1,65523);
			//put_diver(x,y);
			flag = 9;
			judge = 2;
			break;
		}
		if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
        {
			mousehide(*x,*y);
			fdhz(48,685,2,2,"��",44373);
			fdhz(88,685,2,2,"��",44373);
			fdhz(128,685,2,2,"��",44373);
			fdhz(168,685,2,2,"¼",44373);
			reset_mouse(x,y);
			delay0(50);
            judge = -1;//�˳���¼
			break;
        }

	}
	if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 
	fseek(fp,sizeof(CARFA)*flag,SEEK_SET);
	fread(thiscar,sizeof(CARFA),1,fp);
	fclose(fp);
	

	//mousehide(*x,*y);  //�������
    //printf_image(249,2,1022,768,"driver");
    
    //reset_mouse(x,y);   //���������������λ�õı���
	return judge;
  
}

/*******************************
�������˾����Ϣ��ʾ�ĺ���
********************************/                     
int put_diver(int *x,int *y,CARFA *thiscar)
{
	int button=0;
    int mx=0;
    int my=0;
	char chpraise[3];
	int judge = 0;
	// char chcall[3];
	mousehide(*x,*y);
    //���汳��
    //save_image(251,138,1022,768,"putdrive");
	sprintf(chpraise,"%d",thiscar->praise);
	// sprintf(chcall,"%d",thiscar->call);

	bar(251,138,1022,768,65535);
	
	fdhz(287,168,2,2,thiscar->name,44373);//��
	fdhz(327,168,2,2,"ʦ��",44373);
	
	fdhz(287,268,1,1,"����",44373);
	outtextxy(327,268,":",1,1,15,44373);
	fdhz(347,268,1,1,"��",44373);
	outtextxy(363,268,"A-",1,1,15,44373);
	outtextxy(387,268,thiscar->fastcar.carname,1,1,15,44373);//����
	
	fdhz(287,308,1,1,"����",44373);
	outtextxy(327,308,":",1,1,15,44373);
	fdhz(342,308,1,1,thiscar->fastcar.type,44373);//����
	
	fdhz(287,348,1,1,"���۷�",44373);
	outtextxy(347,348,":",1,1,15,44373);
	outtextxy(362,348,chpraise,1,1,15,44373);//������
	
	// fdhz(287,388,1,1,"������",44373);
	// outtextxy(347,388,":",1,1,15,44373);
	// outtextxy(362,388,"0",1,1,15,44373);//������
	
	fdhz(287,428,1,1,"������¼",44373);
	outtextxy(367,428,":",1,1,15,44373);
	

	if (thiscar->call>=2)
	{
		outtextxy(382,428,"1",1,1,15,44373);
		switch (thiscar->call)
		{
			case 2:
				fdhz(382,468,1,1,"�Գ˿���ɧ�Ż�������",44373);
				break;
			case 3:
				fdhz(382,468,1,1,"��˿ͷ���֫���ͻ",44373);
				break;
			case 4:
				fdhz(382,468,1,1,"���Ƴ˿���������",44373);
				break;
			case 5:
				fdhz(382,468,1,1,"�˿����������˺�",44373);
				break;
			case 6:
				fdhz(382,468,1,1,"��������",44373);
				break;
			default:
				break;
		}
	}
	else
	{
		outtextxy(382,428,"0",1,1,15,44373);
	}
	
	
	
	bar_round(480,720,220,70,10,1,64384);
	bar_round(480,720,214,65,8,1,65535);
	fdhz(410,705,2,2,"�滻˾��",64384);
	bar_round(815,720,220,70,10,1,64384);
	bar_round(815,720,214,65,8,1,65535);
	fdhz(752,705,2,2,"��",64384);
	fdhz(858,705,2,2,"��",64384);
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		if(mx>=705 && mx<=925 && my>=685 && my<=755 &&button)//����
		{
			mousehide(*x,*y);
			fdhz(752,705,2,2,"��",44373);
			fdhz(858,705,2,2,"��",44373);
			reset_mouse(x,y);
			delay0(30);
			judge = 1;
			break;
		}
		else if(mx>=370 && mx<=590 && my>=685 && my<=755 &&button)//�滻˾��
		{
			mousehide(*x,*y);
			fdhz(410,705,2,2,"�滻˾��",44373);
			reset_mouse(x,y);
			delay0(50);
			if (thiscar->call == 1)
			{
				mousehide(*x,*y);
        		save_image(483-210,384-140,483+210,384+140,"note");
        		bar_round(483,384,416,270,50,1,64384);
        		bar_round(483,384,410,265,48,1,65535);
        		fdhz(330,340,2,2,"��˾������Ҫ�滻",64384);
        		fdhz(431,430,1,1,"�����������",44373);
        		getch();
        		printf_image(483-210,384-140,483+210,384+140,"note");
        		reset_mouse(x,y);
			}
			else
			{
				managecar(x,y,thiscar);
				judge = 1;
				break;
			}
		}
		else if(mx>= 26 && mx<=222 && my>=672 && my<=724 && button)
        {
			mousehide(*x,*y);
			fdhz(48,685,2,2,"��",44373);
			fdhz(88,685,2,2,"��",44373);
			fdhz(128,685,2,2,"��",44373);
			fdhz(168,685,2,2,"¼",44373);
			reset_mouse(x,y);
			delay0(50);
            judge = -1;//�˳���¼
			break;
        }
		
	}
	//mousehide(*x,*y);  //�������
	//printf_image(251,138,1022,768,"putdrive");
	//reset_mouse(x,y);   //���������������λ�õı���
	return judge;
}

/*******************************
����Ա����ͼ
*******************************/
void admin_draw(void)
{
	
	bar(1,1,1023,767,65535); //���ñ���Ϊ��ɫ
	 
	//��ɫ
	bar(2,2,247,766,65523);//���ѡ����
	bar(249,2,1022,134,65523);//����ѡ����
	
	//����������ɫ�߿�
	rectangle(1,0,249,768,2,64384); //���ѡ����
    rectangle(247,0,1023,136,2,64384);//����ѡ����
	
	//����Ա
	bar_round(124,90,196,96,25,1,64384);
    bar_round(124,90,190,91,23,1,65535);
    fdhz(48,67,3,3,"��",64384);
    fdhz(103,67,3,3,"��",64384);
	fdhz(158,67,3,3,"Ա",64384);
	
	//˾������
    bar_round(124,298,196,52,10,1,64384);
    bar_round(124,298,190,47,8,1,65535);
    fdhz(48,285,2,2,"˾",64384);
    fdhz(88,285,2,2,"��",64384);
    fdhz(128,285,2,2,"��",64384);
    fdhz(168,285,2,2,"��",64384);
	
	//�˳���¼
	bar_round(124,698,196,52,10,1,64384);
    bar_round(124,698,190,47,8,1,65535);
    fdhz(48,685,2,2,"��",64384);
    fdhz(88,685,2,2,"��",64384);
    fdhz(128,685,2,2,"��",64384);
    fdhz(168,685,2,2,"¼",64384);
	
	//��Ϣ˵��
	fdhz(307,60,2,2,"���˾���������˾����Ϣ����",64384);
	
}