#include "common.h"
#include "cartake.h"
#define NOW -1
#define AIM 1
#define FASTNUM 5
#define PLACENUM 6
#define UNCHOOSE -1
#define CCT 8

void car_take_box(int* x, int* y, USEINFOR *infor)
{
	int button=0;
    int mx=0;
    int my=0;
    int waitime=0;//�����ж�ԤԼʱ��
    int mincar=0;//���ڼ�¼�����������
    int aimplace=UNCHOOSE;//��¼Ŀ��λ��
    CARFAST car[FASTNUM];//����Ⱥ����
    PLACE location[PLACENUM];//�����ص�
    char *placename[PLACENUM]={NULL};//�����ص��Ӧ������

    //��ʼ�������ص�
    location[0].x=130;//��ѧ
    location[0].y=440;
    location[1].x=212;//С��
    location[1].y=695;
    location[2].x=395;//����
    location[2].y=25;
    location[3].x=370;//�̳�
    location[3].y=490;
    location[4].x=686;//ͼ���
    location[4].y=560;
    location[5].x=450;//��Ӿ��
    location[5].y=243;

    //��ʼ���ص�����
    placename[0]="��ѧ";
    placename[1]="С��";
    placename[2]="����";
    placename[3]="�̳�";
    placename[4]="ͼ���";
    placename[5]="��Ӿ��";

    newfastcar(car);//��ʼ������

    mousehide(*x,*y);
    //���汳��
    save_image(771,2,996,612,"cartake");
    save_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    save_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    save_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    save_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    save_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    save_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
	
    //��ͼ
	//��ɫ
    bar(771,2,996,612,65523);
	
	//�쳵
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
    fdhz(840,67,3,3,"��",64384);
    fdhz(900,67,3,3,"��",64384);
	
	//��ǰλ��
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"��ǰλ��",64384);
	outtextxy(885,188,":",1,1,40,64384);
    //��ʾ��ǰλ��
    showplace(infor->nowplace,NOW,location,placename);
   
    //ѡ��Ŀ�ĵ�
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"ѡ",64384);
    fdhz(855,280,1,1,"��",64384);
    fdhz(890,280,1,1,"Ŀ",64384);
    fdhz(925,280,1,1,"��",64384);
	fdhz(960,280,1,1,"��",64384);
	
	//Ԥ�Ƽ۸�
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(810,370,1,1,"Ԥ�Ƽ۸�",64384);
	fdhz(970,370,1,1,"Ԫ",64384);
	outtextxy(885,368,":",1,1,40,64384);
	
	//��ʱ
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"��ʱ",44373);
	
	//ԤԼ
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"ԤԼ",64384);
	
	//���п쳵
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(825,550,1,1,"��",64384);
    fdhz(865,550,1,1,"��",64384);
    fdhz(905,550,1,1,"��",64384);
    fdhz(945,550,1,1,"��",64384);
	
	//С����ʼλ��
	car_draw_right1(car[0].fastcar.x,car [0].fastcar.y);//ѧУ���̳�֮��
	car_draw_right1(car[1].fastcar.x,car [1].fastcar.y);//����
	car_draw_left1(car[2].fastcar.x,car [2].fastcar.y);//С��
	car_draw_left1(car[3].fastcar.x,car [3].fastcar.y);//��Ӿ��
	car_draw_on1(car[4].fastcar.x,car [4].fastcar.y);//ͼ���
	
    //��ͼ
    save_image(1,1,1023,767,"drivinfo");
	//��ʾ���
    reset_mouse(x,y);

    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            if (aimplace!=UNCHOOSE)
            {
                starttoendroad(infor->nowplace,aimplace,65535);
            }
            
            //�Ե�ͼ��ԭ�е�С�������ڵ�
            bar_round(car[0].fastcar.x,car [0].fastcar.y,42,22,2,1,65535);
            bar_round(car[1].fastcar.x,car [1].fastcar.y,42,22,2,1,65535);
            bar_round(car[2].fastcar.x,car [2].fastcar.y,42,22,2,1,65535);
            bar_round(car[3].fastcar.x,car [3].fastcar.y,42,22,2,1,65535);
            bar_round(car[4].fastcar.x,car [4].fastcar.y,22,42,2,1,65535);
            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
        {
            safe_box(x,y);
        }
		else if (mx>=798  && mx<=994 && my>=265 && my<=311 && button)//���ѡ��Ŀ�ĵأ�����Ŀ�ĵ�ѡ�����
        {
            bar_round(car[0].fastcar.x,car [0].fastcar.y,42,22,2,1,65535);
	        bar_round(car[1].fastcar.x,car [1].fastcar.y,42,22,2,1,65535);
	        bar_round(car[2].fastcar.x,car [2].fastcar.y,42,22,2,1,65535);
	        bar_round(car[3].fastcar.x,car [3].fastcar.y,42,22,2,1,65535);
	        bar_round(car[4].fastcar.x,car [4].fastcar.y,22,42,2,1,65535);
            choose_aimplace(x,y,&aimplace,location,infor,placename);
        }
		else if (mx>=798  && mx<=994 && my>=532 && my<=584 && button)//������п쳵������˾����Ϣ��
        {
            if(aimplace == UNCHOOSE) //���ⲻѡĿ�ĵؾ�ֱ�ӵ�����п쳵
            {
                mousehide(*x,*y);

                save_image(512-210,384-140,512+210,384+140,"unchoose");
                bar_round(512,384,416,270,50,1,64384);
                bar_round(512,384,410,265,48,1,65535);
                fdhz(400,360,2,2,"��ѡ��Ŀ�ĵ�",64384);
                
                fdhz(450,420,1,1,"�����������",44373);
                getch();
                printf_image(512-210,384-140,512+210,384+140,"unchoose");
                reset_mouse(x,y);
            }
            else
            {
                mincar=desidecar(infor->nowplace,car,location);//�ж�������������
			    driver_info(x,y,infor,car,location,placename,&aimplace,mincar,waitime);
            }
		}
		else if (mx>=900  && mx<=990 && my>=442 && my<=494 && button)//���ԤԼ������ԤԼѡ�񵯿�
        {
			waitime=pre_appoint(x,y);
		}
		else if (mx>=802  && mx<=892 && my>=442 && my<=494 && button)//�����ʱ������Ϊ��ʱ��״̬
        {
			immediate(x,y);
            waitime=0;
		}
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
    }

    //��ʾ����
    mousehide(*x,*y); 

    printf_image(771,2,996,612,"cartake");
    printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
    // bar(location[0].x-3,location[0].y-3,location[0].x+3,location[0].y+3,57083);
    // bar(location[1].x-3,location[1].y-3,location[1].x+3,location[1].y+3,57083);
    // bar(location[2].x-3,location[2].y-3,location[2].x+3,location[2].y+3,57083);
    // bar(location[3].x-3,location[3].y-3,location[3].x+3,location[3].y+3,57083);
    // bar(location[4].x-3,location[4].y-3,location[4].x+3,location[4].y+3,57083);
    // bar(location[5].x-3,location[5].y-3,location[5].x+3,location[5].y+3,57083);

    reset_mouse(x,y);
}


/***************************
������п쳵������˾����Ϣ��
****************************/
void driver_info(int *x,int *y, USEINFOR *infor, const CARFAST car[], const PLACE *location, const char **placename, int *aimplace, int mincar,int waitime)
{
	int button=0;
    int mx=0;
    int my=0;
    int flag=1;//�ж��˳�
    int sigle=0;//���ڽ����˳����ж�
    float price;
    struct tm *info;//���ڵ�������ϳ�ʱ��ʱ��
	char buffer[80];//��ʽ�����ʱ���ַ���������
	time_t rawtime1;//���ڻ�ȡ������п쳵���̵�ʱ��
	time_t rawtime2;//����ԤԼʱ����ж�
	time_t rawtime3;//���ڻ�ȡ��ǰʱ��
	time_t rawtime4;//����ʱ��۸����
	int time_gap;//����ԤԼ��ʱ�������ж�
	int time_gap1;//����ʱ��۸����
	int nowtime_hour;//��ȡ������п쳵����ʱ��ʱ��
	// int nowtime_min;
	// int nowtime_sec;
	// //�����жϵ�ʱ��
	// int judgetime_hour;
	// int judgetime_min;
	// int judgetime_sec;

    time(&rawtime1);//��ȡGMTʱ��
    info = gmtime(&rawtime1);//���ݵ�ǰ��time_t��ö�Ӧ�Ľṹ��
    nowtime_hour=info->tm_hour;
	// nowtime_min=info->tm_min;
	// nowtime_sec=info->tm_sec;
    
    mousehide(*x,*y);
	
	//���汳��
    // save_image(771,2,996,612,"drivinfo");
    // save_image(1,1,1023,767,"drivinfo");
	bar(location[0].x-3,location[0].y-3,location[0].x+3,location[0].y+3,57083);
    bar(location[1].x-3,location[1].y-3,location[1].x+3,location[1].y+3,57083);
    bar(location[2].x-3,location[2].y-3,location[2].x+3,location[2].y+3,57083);
    bar(location[3].x-3,location[3].y-3,location[3].x+3,location[3].y+3,57083);
    bar(location[4].x-3,location[4].y-3,location[4].x+3,location[4].y+3,57083);
    bar(location[5].x-3,location[5].y-3,location[5].x+3,location[5].y+3,57083);
	// printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    // printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    // printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    // printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    // printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    // printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
    
    showplace(infor->nowplace,NOW,location,placename);
    showplace(*aimplace,AIM,location,placename);

	//��ɫ
    bar(771,2,996,612,65523);
	
	
	//˾������
	bar_round(896,90,196,96,25,1,64384);
    bar_round(896,90,190,91,23,1,65535);
    fdhz(817,67,3,3,car[mincar].name,64384);
    fdhz(877,67,3,3,"ʦ",64384);
	fdhz(937,67,3,3,"��",64384);
	
	//���ƺ���
    bar_round(896,198,196,52,10,1,64384);
    bar_round(896,198,190,47,8,1,65535);
    fdhz(810,190,1,1,"����",64384);
	outtextxy(847,188,":",1,1,40,64384);
    fdhz(862,190,1,1,"��",64384);
    outtextxy(878,190,"A-",1,1,15,64384);

    outtextxy(910,190,car[mincar].fastcar.carname,1,1,15,64384);
   
    //����
	bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
	fdhz(810,280,1,1,"����",64384);
    outtextxy(847,278,":",1,1,40,64384);
    // outtextxy(862,278,car[0].fastcar.type,1,1,40,64384);
    fdhz(870,280,1,1,car[mincar].fastcar.type,64384);
   
	//ȡ������
	bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(825,370,1,1,"ȡ",64384);
    fdhz(865,370,1,1,"��",64384);
    fdhz(905,370,1,1,"��",64384);
    fdhz(945,370,1,1,"��",64384);
	
	//�ȴ��ϳ�
	bar_round(896,468,196,52,10,1,64384);
    bar_round(896,468,190,47,8,1,65535);
    fdhz(825,460,1,1,"��",64384);
    fdhz(865,460,1,1,"��",64384);
    fdhz(905,460,1,1,"��",64384);
    fdhz(945,460,1,1,"��",64384);
	
	//������
	bar_round(896,558,196,52,10,1,64384);
    bar_round(896,558,190,47,8,1,65535);
    fdhz(825,550,1,1,"��",64384);
    fdhz(865,550,1,1,"��",64384);
    fdhz(905,550,1,1,"��",64384);
    fdhz(945,550,1,1,"ʾ",64384);
	
    // //�Ե�ͼ��ԭ�е�С�������ڵ�
	// bar_round(car[0].fastcar.x,car [0].fastcar.y,42,22,2,1,65535);
	// bar_round(car[1].fastcar.x,car [1].fastcar.y,42,22,2,1,65535);
	// bar_round(car[2].fastcar.x,car [2].fastcar.y,42,22,2,1,65535);
	// bar_round(car[3].fastcar.x,car [3].fastcar.y,42,22,2,1,65535);
	// bar_round(car[4].fastcar.x,car [4].fastcar.y,22,42,2,1,65535);
	
	//��BACK�������ڵ�
    bar_round(976,664,76,44,15,1,65523);

	
	//��ʾ���
    reset_mouse(x,y);
    switch(waitime)
	{
	    case 15:
			mousehide(*x,*y);
		
		    save_image(512-210,384-140,512+210,384+140,"pre11");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"30",2,2,30,64384);
            fdhz(450,360,2,2,"���Ӻ󷢳�",64384);
            fdhz(450,420,1,1,"�����������",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre11");
			reset_mouse(x,y);
			
		break;
		
		case 30:
			mousehide(*x,*y);
			
		    save_image(512-210,384-140,512+210,384+140,"pre12");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"60",2,2,30,64384);
            fdhz(450,360,2,2,"���Ӻ󷢳�",64384);
			fdhz(450,420,1,1,"�����������",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre12");
			reset_mouse(x,y);
		break;
		
		case 45:
			mousehide(*x,*y);
			
		    save_image(512-210,384-140,512+210,384+140,"pre13");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
			outtextxy(380,360,"90",2,2,30,64384);
            fdhz(450,360,2,2,"���Ӻ󷢳�",64384);
			fdhz(450,420,1,1,"�����������",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"pre13");
			reset_mouse(x,y);
		break;
	}
    while(waitime!=0)
	{
		newxy(x,y,&button);
		mx = *x;
		my = *y;
		
		 if(mx>=798  && mx<=994 && my>=352 && my<=404 && button)//���ȡ����������
        {
           
            *aimplace = UNCHOOSE;
			flag=0;
			waitime=0;
            break;
        }
		
		time(&rawtime2);//��ȡGMTʱ��
		//info = gmtime(&rawtime2);//���ݵ�ǰ��time_t��ö�Ӧ�Ľṹ��
		time_gap=difftime(rawtime2,rawtime1);
		if(time_gap>=waitime)
		{
            mousehide(*x,*y);
            save_image(512-210,384-140,512+210,384+140,"notice");
            bar_round(512,384,416,270,50,1,64384);
            bar_round(512,384,410,265,48,1,65535);
            fdhz(410,360,2,2,"ԤԼʱ�䵽��",64384);
			fdhz(450,420,1,1,"�����������",44373);
            getch();
            printf_image(512-210,384-140,512+210,384+140,"notice");
            reset_mouse(x,y);
			break;
		}
	}
	// ��ʾ�����Ķ���
    if (flag==1)
    {
        cartostart(infor->nowplace,mincar,x,y);
        
        time(&rawtime3);//��ȡ�ϳ�GMTʱ��
        // info = gmtime(&rawtime3);
        info = localtime(&rawtime3);
		sprintf(buffer,"%d.%02d.%02d",(info->tm_year+1900),(info->tm_mon+1),info->tm_mday);

        //�ȴ��ϳ���������ϳ����ұ���(��ɫ)
        mousehide(*x,*y);
        bar_round(896,468,196,52,10,1,44373);
        bar_round(896,468,190,47,8,1,65535);
        fdhz(825,460,1,1,"��",44373);
        fdhz(865,460,1,1,"��",44373);
        fdhz(905,460,1,1,"��",44373);
        fdhz(945,460,1,1,"��",44373);
        reset_mouse(x,y);
    }
    
    
            /*time(&rawtime);//��ȡGMTʱ��
			info = gmtime(&rawtime);//���ݵ�ǰ��time_t��ö�Ӧ�Ľṹ��
			sprintf(judgetime_year,"%d",(info->tm_year+1900));
			sprintf(judgetime_mon,"%d",(info->tm_mon+1));
			sprintf(judgetime_mday,"%d",info->tm_mday);
			sprintf(judgetime_hour,"%d",(info->tm_hour+CCT)%24+12);
			sprintf(judgetime_min,"%d",(info->tm_min+1));
			sprintf(judgetime_sec,"%d",(info->tm_sec+1));
			
			outtextxy(350,150,judgetime_year,2,2,30,64384);
			outtextxy(350,180,judgetime_mon,2,2,30,64384);
			outtextxy(350,210,judgetime_mday,2,2,30,64384);
			outtextxy(350,240,judgetime_hour,2,2,30,64384);
			outtextxy(350,270,judgetime_min,2,2,30,64384);
			outtextxy(350,300,judgetime_sec,2,2,30,64384);*/
	while (flag==1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=798  && mx<=994 && my>=352 && my<=404 && button)//���ȡ����������
        {
			
            *aimplace = UNCHOOSE;
            waitime=0;
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
		else if (mx>=798  && mx<=994 && my>=416 && my<=520 && button)//�������/�ȴ��ϳ���ʾ���ж���
		{	
            //���±��
            mousehide(*x,*y);
            bar_round(896,468,196,52,10,1,64384);
            bar_round(896,468,190,47,8,1,65535);
            fdhz(825,460,1,1,"��",64384);
            fdhz(865,460,1,1,"��",64384);
            fdhz(905,460,1,1,"��",64384);
            fdhz(945,460,1,1,"��",64384);
            reset_mouse(x,y);
            //ȷ������
            sigle=starttoend(infor->nowplace,*aimplace,x,y);
            if(sigle==1)//���ڰ�ȫ������Ľ����˳�
			{
				break;
			}
            else
            {
                time(&rawtime4);//��ȡGMTʱ��
				time_gap1=difftime(rawtime4,rawtime1);
                //����۸񲢿۷�
                costmoney(&price,infor,aimplace,nowtime_hour,time_gap1,x,y);
                
                //���ɶ�������ͼ����
                neworder(x,y,infor,car,placename,aimplace,mincar,buffer,price);

                //���ɹ�����Ŀ�ĵصģ����޸ĵ�ǰλ��
                changeNowplace(infor,*aimplace);
                *aimplace = UNCHOOSE; 
                break;
            }
		}
    }
	
	//��ʾ����
    mousehide(*x,*y); 

    // printf_image(771,2,996,612,"drivinfo");
    printf_image(1,1,1023,767,"drivinfo");
    //С����ʼλ��
	// car_draw_right1(car[0].fastcar.x,car [0].fastcar.y);//ѧУ���̳�֮��
    // car_draw_right1(car[1].fastcar.x,car [1].fastcar.y);//����
    // car_draw_left1(car[2].fastcar.x,car [2].fastcar.y);//С��
    // car_draw_left1(car[3].fastcar.x,car [3].fastcar.y);//��Ӿ��
    // car_draw_on1(car[4].fastcar.x,car [4].fastcar.y);//ͼ���
    // //���ؼ�
    // bar_round(976,664,76,44,15,1,64384);
    // bar_round(976,664,70,39,13,1,65535);
	// outtextxy(938,645,"Back",2,2,15,64384);

    //�ڵ����е�
    printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
    printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
    printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
    printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
    printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
    printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");

    //�ڵ�֮ǰ��Ŀ�ĵ�
    bar_round(896,288,196,52,10,1,64384);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"ѡ",64384);
    fdhz(855,280,1,1,"��",64384);
    fdhz(890,280,1,1,"Ŀ",64384);
    fdhz(925,280,1,1,"��",64384);
    fdhz(960,280,1,1,"��",64384);

    //����Ϊ��ʱ״̬
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"��ʱ",44373);
	
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"ԤԼ",64384);
    //��ʾ��������λ��
    showplace(infor->nowplace,NOW,location,placename);

    reset_mouse(x,y);

	
}


/**************************
���ԤԼ������ԤԼѡ�񵯿�
ʱ�任�㣺
	waitime = 0 = ��ʱ
    waitime = 30min = 15s
	waitime = 60min = 30s
	waitime = 90min = 45s
**************************/
int pre_appoint(int *x,int *y)
{
    int waitime=0;//�����ж�ԤԼʱ��
	int button=0;
    int mx=0;
    int my=0;
    
    mousehide(*x,*y);

    save_image(83,109,683,659,"preappoint");
	
	
	//��ʱ��ť��ɫ�����ı�
	bar_round(847,468,90,52,10,1,64384);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"��ʱ",64384);
	
	
	//ԤԼ��ť��ɫ�����ı�
	bar_round(945,468,90,52,10,1,44373);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"ԤԼ",44373);

	
    //��ͼ
    bar_round(383,384,596,546,50,1,64384);
    bar_round(383,384,590,542,48,1,65535);
    fdhz(210,135,3,3,"ԤԼ�ϳ�ʱ��",44373);
    bar(88,200,678,230,63422);
    linelevel(88,368,678,368,5,63422);
    linelevel(88,510,678,510,5,63422);
	outtextxy(150,285,"30",2,2,30,44373);
    fdhz(230,285,2,2,"���Ӻ�",44373);
	outtextxy(150,423,"60",2,2,30,44373);
    fdhz(230,423,2,2,"���Ӻ�",44373);
	outtextxy(150,565,"90",2,2,30,44373);
    fdhz(230,565,2,2,"���Ӻ�",44373);

    
    reset_mouse(x,y);
    while (1)
    {
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if(mx>=88 && mx<=678 && my>=230 && my<=368 &&button)//�����30���ӡ�����
		{
			waitime=15;
			mousehide(*x,*y);
			
			//����
			bar(88,230,678,368,65535);
			outtextxy(150,285,"30",2,2,30,64384);
			fdhz(230,285,2,2,"���Ӻ�",64384);
			//���
			bar(88,373,678,510,65535);
			outtextxy(150,423,"60",2,2,30,44373);
			fdhz(230,423,2,2,"���Ӻ�",44373);
			bar(88,515,678,615,65535);
			outtextxy(150,565,"90",2,2,30,44373);
			fdhz(230,565,2,2,"���Ӻ�",44373);
			//��
			lean_line_thick(500,300,15,45,3,64384);
			lean_line_thick(500+11,300+8,40,-45,3,64384);
			
			reset_mouse(x,y);
		}
		if(mx>=88 && mx<=678 && my>=373 && my<=510 &&button)//�����60���ӡ�����
		{
			waitime=30;
			mousehide(*x,*y);
			
			//����
			bar(88,373,678,510,65535);
			outtextxy(150,423,"60",2,2,30,64384);
			fdhz(230,423,2,2,"���Ӻ�",64384);
			//���
			bar(88,230,678,368,65535);
			outtextxy(150,285,"30",2,2,30,44373);
			fdhz(230,285,2,2,"���Ӻ�",44373);
			bar(88,515,678,615,65535);
			outtextxy(150,565,"90",2,2,30,44373);
			fdhz(230,565,2,2,"���Ӻ�",44373);
			//��
			lean_line_thick(500,442,15,45,3,64384);
			lean_line_thick(500+11,442+8,40,-45,3,64384);
			reset_mouse(x,y);
			
		}
		if(mx>=88 && mx<=678 && my>=515 && my<=653 &&button)//�����90���ӡ�����
		{
			waitime=45;
			mousehide(*x,*y);
			
			//����
			bar(88,515,678,615,65535);
			outtextxy(150,565,"90",2,2,30,64384);
			fdhz(230,565,2,2,"���Ӻ�",64384);
			//���
			bar(88,230,678,368,65535);
			outtextxy(150,285,"30",2,2,30,44373);
			fdhz(230,285,2,2,"���Ӻ�",44373);
			bar(88,373,678,510,65535);
			outtextxy(150,423,"60",2,2,30,44373);
			fdhz(230,423,2,2,"���Ӻ�",44373);
			//��
			lean_line_thick(500,584,15,45,3,64384);
			lean_line_thick(500+11,584+8,40,-45,3,64384);
			
			reset_mouse(x,y);
		}
        if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
		
    }

    
    mousehide(*x,*y);  //�������
    printf_image(83,109,683,659,"preappoint");
    
    reset_mouse(x,y);   //���������������λ�õı���
   
    return waitime;
}


/**************************
���ؼ�ʱ״̬����
***************************/
void immediate(int *x,int *y)
{
	int button=0;
    int mx=0;
    int my=0;
    mousehide(*x,*y);
	
	//save_image(802,442,990,494,"immediate");
	
	//��ʱ��ť��ɫ�����ı�
	bar_round(847,468,90,52,10,1,44373);
    bar_round(847,468,84,47,8,1,65535);
    fdhz(830,460,1,1,"��ʱ",44373);
	
	
	//ԤԼ��ť��ɫ�����ı�
	bar_round(945,468,90,52,10,1,64384);
    bar_round(945,468,84,47,8,1,65535);
    fdhz(928,460,1,1,"ԤԼ",64384);
	
	if (mx>=900  && mx<=990 && my>=442 && my<=494 && button)//���ԤԼ������ԤԼѡ�񵯿�
    {
		pre_appoint(x,y);
    }
	
    //mousehide(*x,*y);  //�������
	//printf_image(802,442,990,494,"immediate");
  
    reset_mouse(x,y);   //���������������λ�õı���
   
}


/***************************
�ĸ������С����ͼ����
****************************/
void car_draw_right(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel+6,car_position.ypixel,6,15,1,1,1);
	bar_round(car_position.xpixel-16,car_position.ypixel,3,15,1,1,1);
	bar_round(car_position.xpixel-6,car_position.ypixel-8,18,1,0,1,1);
	bar_round(car_position.xpixel-6,car_position.ypixel+8,18,1,0,1,1);
}	

void car_draw_left(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,42,22,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,38,18,2,1,65535);
	bar_round(car_position.xpixel-6,car_position.ypixel,6,15,1,1,1);
	bar_round(car_position.xpixel+16,car_position.ypixel,3,15,1,1,1);
	bar_round(car_position.xpixel+6,car_position.ypixel-8,18,1,0,1,1);
	bar_round(car_position.xpixel+6,car_position.ypixel+8,18,1,0,1,1);
}

void car_draw_on(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel-6,15,6,1,1,1);
	bar_round(car_position.xpixel,car_position.ypixel+16,15,3,1,1,1);
	bar_round(car_position.xpixel-8,car_position.ypixel+6,1,18,0,1,1);
	bar_round(car_position.xpixel+8,car_position.ypixel+6,1,18,0,1,1);
}

void car_draw_down(CAR_CONDITION car_position)
{
	bar_round(car_position.xpixel,car_position.ypixel,22,42,2,1,1);
	bar_round(car_position.xpixel,car_position.ypixel,18,38,2,1,65535);
	bar_round(car_position.xpixel,car_position.ypixel+6,15,6,1,1,1);
	bar_round(car_position.xpixel,car_position.ypixel-16,15,3,1,1,1);
	bar_round(car_position.xpixel-8,car_position.ypixel-6,1,18,0,1,1);
	bar_round(car_position.xpixel+8,car_position.ypixel-6,1,18,0,1,1);
}



void car_draw_right1(int x,int y)
{
	bar_round(x,y,42,22,2,1,1);
	bar_round(x,y,38,18,2,1,65535);
	bar_round(x+6,y,6,15,1,1,1);
	bar_round(x-16,y,3,15,1,1,1);
	bar_round(x-6,y-8,18,1,0,1,1);
	bar_round(x-6,y+8,18,1,0,1,1);
}	

void car_draw_left1(int x,int y)
{
	bar_round(x,y,42,22,2,1,1);
	bar_round(x,y,38,18,2,1,65535);
	bar_round(x-6,y,6,15,1,1,1);
	bar_round(x+16,y,3,15,1,1,1);
	bar_round(x+6,y-8,18,1,0,1,1);
	bar_round(x+6,y+8,18,1,0,1,1);
}

void car_draw_on1(int x,int y)
{
	bar_round(x,y,22,42,2,1,1);
	bar_round(x,y,18,38,2,1,65535);
	bar_round(x,y-6,15,6,1,1,1);
	bar_round(x,y+16,15,3,1,1,1);
	bar_round(x-8,y+6,1,18,0,1,1);
	bar_round(x+8,y+6,1,18,0,1,1);
}

void car_draw_down1(int x,int y)
{
	bar_round(x,y,22,42,2,1,1);
	bar_round(x,y,18,38,2,1,65535);
	bar_round(x,y+6,15,6,1,1,1);
	bar_round(x,y-16,15,3,1,1,1);
	bar_round(x-8,y-6,1,18,0,1,1);
	bar_round(x+8,y-6,1,18,0,1,1);
}

void showplace(int place, int mode, const PLACE *location, const char **placename)
{
    int showx;//ȷ����ʾλ��
    int showy;
    int color;

    if (mode == NOW)
    {   
        showx=905;
        showy=190;
        bar(900,180,990,215,65535);//����ѡ��Ŀ�ĵ�
        color = 9284; //���Ϊ��ɫ
    }
    else if (mode == AIM)
    {
        showx=905;
        showy=280;

        bar_round(896,288,196,52,10,1,64384);
        bar_round(896,288,190,47,8,1,65535);//����ѡ��Ŀ�ĵ�
        fdhz(810,280,1,1,"Ŀ��λ��",64384);
	    outtextxy(885,278,":",1,1,40,64384);
        color = 55463 ; //�յ�Ϊ��ɫ 
    }
    switch (place)
    {
        case 0:
            fdhz(showx,showy,1,1,placename[0],64384);
            markpoint(location[0].x,location[0].y,color,mode);
            break;
        case 1:
            fdhz(showx,showy,1,1,placename[1],64384);
            markpoint(location[1].x,location[1].y,color,mode);
            break;
        case 2:
            fdhz(showx,showy,1,1,placename[2],64384);
            markpoint(location[2].x,location[2].y,color,mode);
            break;
        case 3:
            fdhz(showx,showy,1,1,placename[3],64384);
            markpoint(location[3].x,location[3].y,color,mode);
            break;
        case 4:
            fdhz(showx,showy,1,1,placename[4],64384);
            markpoint(location[4].x,location[4].y,color,mode);
            break;
        case 5:
            fdhz(showx,showy,1,1,placename[5],64384);
            markpoint(location[5].x,location[5].y,color,mode);
            break;
        default:
            break;
    }
}

//�������յ㣬��ͼ
void markpoint(int x, int y, int color, int mode)
{
    linever(x,y-20,x,y-3,1,color);
    linever(x-1,y-20,x-1,y-3,1,color);
    linever(x+1,y-20,x+1,y-3,1,color);
    circle(x,y,4,color);
    circle(x,y,3,color);
    FillCircle(x,y-20,13,color);
    FillCircle(x,y,2,0);
    if (mode == NOW)
    {
        fdhz(x-7,y-27,1,1,"��",65535);
    }
    else 
    {
        fdhz(x-7,y-27,1,1,"��",65535);
    }
    
    

}

//��ʼ���쳵������Ϣ
void newfastcar(CARFAST *car)
{
    int i;//���ڼ���
    int n;//���ڼ�¼�����
    PLACE fastplace[FASTNUM];
    char carcard[10][6];//���ƺż�
    char driver[10][3];//˾������
    char cartpye[6][7];//��������
    //��ʼ������λ��
    fastplace[0].x=240;
    fastplace[0].y=465;
    fastplace[1].x=130;
    fastplace[1].y=25;
    fastplace[2].x=310;
    fastplace[2].y=719;
    fastplace[3].x=590;
    fastplace[3].y=269;
    fastplace[4].x=715;
    fastplace[4].y=680;

    //��ʼ�����ƺż�
    
    strcpy(carcard[0],"7A128");
    strcpy(carcard[1],"S116W");
    strcpy(carcard[2],"0D789");
    strcpy(carcard[3],"3D816");
    strcpy(carcard[4],"QE722");
    strcpy(carcard[5],"E289Q");
    strcpy(carcard[6],"U0207");
    strcpy(carcard[7],"02151");
    strcpy(carcard[8],"L8553");
    strcpy(carcard[9],"7L27D");

    //��ʼ��˾��
    strcpy(driver[0],"��");
    strcpy(driver[1],"��");
    strcpy(driver[2],"��");
    strcpy(driver[3],"��");
    strcpy(driver[4],"��");
    strcpy(driver[5],"��");
    strcpy(driver[6],"��");
    strcpy(driver[7],"��");
    strcpy(driver[8],"��");
    strcpy(driver[9],"��");

    //��ʼ����������
    strcpy(cartpye[0],"����");
    strcpy(cartpye[1],"����");
    strcpy(cartpye[2],"������");
    strcpy(cartpye[3],"����");
    strcpy(cartpye[4],"��̩");
    strcpy(cartpye[5],"����");


    srand((unsigned int)time(NULL));


    for ( i = 0; i < FASTNUM; i++, car++)
    {
        n=rand()%10;
        strcpy(car->name,driver[n]);
        car->fastcar.x=fastplace[i].x;
        car->fastcar.y=fastplace[i].y;
        strcpy(car->fastcar.type,cartpye[n%6]);
        strcpy(car->fastcar.carname,carcard[n]);
    }
}

//ѡ��Ŀ�ĵ�
void choose_aimplace(int *x, int *y, int *aimplace, PLACE *location, USEINFOR *infor, char *placename[])
{
    int button=0;
    int mx=0;
    int my=0;
    int needmoney;//��Ҫ�ļ�Ǯ һ�����ص�5��Ǯ
    
    mousehide(*x,*y);
    
    //  �ڸ�
    switch (*aimplace)
    {
        case 0:
            printf_image(location[0].x-13,location[0].y-34,location[0].x+13,location[0].y+5,"school");
            break;
        case 1:
            printf_image(location[1].x-13,location[1].y-34,location[1].x+13,location[1].y+5,"xiaoqu");
            break;
        case 2:
            printf_image(location[2].x-13,location[2].y-34,location[2].x+13,location[2].y+5,"lake");
            break;
        case 3:
            printf_image(location[3].x-13,location[3].y-34,location[3].x+13,location[3].y+5,"market");
        case 4:
            printf_image(location[4].x-13,location[4].y-34,location[4].x+13,location[4].y+5,"labrary");
            break;
        case 5:
            printf_image(location[5].x-13,location[5].y-34,location[5].x+13,location[5].y+5,"pool");
            break;
        default:
            break;
    }

    starttoendroad(infor->nowplace,*aimplace,65535);

    *aimplace =UNCHOOSE;
    //��ʾ���³���
    FillCircle(location[0].x,location[0].y,3,0);//����
    FillCircle(location[1].x,location[1].y,3,0);//С��
    FillCircle(location[2].x,location[2].y,3,0);//ѧУ
    FillCircle(location[3].x,location[3].y,3,0);//�̳�
    FillCircle(location[4].x,location[4].y,3,0);//ͼ���
    FillCircle(location[5].x,location[5].y,3,0);//��Ӿ��
    // ���֮ǰ��Ŀ�ĵ���Ϣ
    bar_round(896,288,196,52,10,1,44373);
    bar_round(896,288,190,47,8,1,65535);
    fdhz(820,280,1,1,"ѡ",44373);
    fdhz(855,280,1,1,"��",44373);
    fdhz(890,280,1,1,"Ŀ",44373);
    fdhz(925,280,1,1,"��",44373);
	fdhz(960,280,1,1,"��",44373);
    //���֮ǰ�ļ۸���Ϣ
    bar_round(896,378,196,52,10,1,64384);
    bar_round(896,378,190,47,8,1,65535);
    fdhz(810,370,1,1,"Ԥ�Ƽ۸�",64384);
	fdhz(970,370,1,1,"Ԫ",64384);
	outtextxy(885,368,":",1,1,40,64384);

    //��ʾ���
    reset_mouse(x,y);

    while(1)
    {   
        newxy(x,y,&button);
		mx = *x;
		my = *y;
        if (mx>=location[0].x-3  && mx<=location[0].x+3 && my>=location[0].y-3 && my<=location[0].y+3 && button)
        {
            if (infor->nowplace==0)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 0;
            mousehide(*x,*y);
            //�Ե�ͼ��ԭ�е�С�������ڵ�
	
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            
            break;
        }
        else if (mx>=location[1].x-3  && mx<=location[1].x+3 && my>=location[1].y-3 && my<=location[1].y+3 && button)
        {
            if (infor->nowplace==1)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 1;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[2].x-3  && mx<=location[2].x+3 && my>=location[2].y-3 && my<=location[2].y+3 && button)
        {
            if (infor->nowplace==2)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 2;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[3].x-3  && mx<=location[3].x+3 && my>=location[3].y-3 && my<=location[3].y+3 && button)
        {
            if (infor->nowplace==3)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 3;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[4].x-3  && mx<=location[4].x+3 && my>=location[4].y-3 && my<=location[4].y+3 && button)
        {
            if (infor->nowplace==4)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 4;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=location[5].x-3  && mx<=location[5].x+3 && my>=location[5].y-3 && my<=location[5].y+3 && button)
        {
            if (infor->nowplace==5)//����������յ�ѡΪͬһ����
            {
                continue;
            }
            *aimplace = 5;
            mousehide(*x,*y);
            
            starttoendroad(infor->nowplace,*aimplace,13926);
            showplace(*aimplace,AIM,location,placename);
            showprice(infor->nowplace,aimplace);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=802  && mx<=922 && my>=647 && my<=739 && button)//�����ȫ��������Ϣ��
        {
            safe_box(x,y);
        }
        else if(mx>=938  && mx<=1014 && my>=642 && my<=684 && button)//���Back����
        {
            mousehide(*x,*y);
            bar_round(896,288,196,52,10,1,64384);
            bar_round(896,288,190,47,8,1,65535);
            fdhz(820,280,1,1,"ѡ",64384);
            fdhz(855,280,1,1,"��",64384);
            fdhz(890,280,1,1,"Ŀ",64384);
            fdhz(925,280,1,1,"��",64384);
            fdhz(960,280,1,1,"��",64384);
            reset_mouse(x,y);
            break;
        }
        else if (mx>=946  && mx<=1006 && my>=688 && my<=732 && button)//���ESC�˳�ϵͳ
        {
            exit(0);
        }
    }
    
}

//ȷ�����������н���
int desidecar(int nowplace, CARFAST *car, PLACE *location)
{
    int i;//���ڼ���
    int mincar;//��¼�����һ����
    double distance;//��¼�������ľ���,���ⳬ����
    mincar = 0;
    distance = pow((location[nowplace].x-car[0].fastcar.x),2)+pow((location[nowplace].y-car[0].fastcar.y),2);
    for ( i = 0; i < FASTNUM; i++)
    {
        if (distance > pow((location[nowplace].x-car[i].fastcar.x),2)+pow((location[nowplace].y-car[i].fastcar.y),2))
        {
            distance = pow((location[nowplace].x-car[i].fastcar.x),2)+pow((location[nowplace].y-car[i].fastcar.y),2);
            mincar = i;
        }
    }
    return mincar;
}

//ȷ���������Ķ���
void cartostart(int nowplace,int mincar,int *x,int *y)
{
    switch (mincar)
    {
        case 0:
            if (nowplace==0)
            {
                car_school(x,y);
            }
            else
            {
                car_market(x,y);
            }
            break;
        case 1:
            car_lake(x,y);
            break;
        case 2:
             car_xiaoqu(x,y);
            break;
        case 3:
            car_pool(x,y);
            break;
        case 4:
            car_library(x,y);
            break;
        default:
            break;
    }
    
}
// ��㵽�յ�Ķ���
int starttoend(int nowplace,int aimplace,int *x,int *y)
{
    int sigle=0;//���ڽ����˳�
    switch (nowplace)
    {
        case 0:
                switch (aimplace)
                {
                    case 1:
                            sigle = carmove0to1(x,y);
                            if(sigle==1)//����˱������˳���ǰ�Ĵ�
			                {
				                break;
			                }
                            break;
                    case 2:
                            sigle = carmove0to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove0to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove0to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove0to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 1:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove1to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 2:
                            sigle = carmove1to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove1to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove1to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove1to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 2:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove2to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove2to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove2to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove2to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove2to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;

                    default:
                            break;
                }
                break;
        case 3:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove3to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove3to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove3to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove3to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove3to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        case 4:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove4to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove4to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove4to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove4to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 5:
                            sigle = carmove4to5(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        case 5:
                switch (aimplace)
                {
                    case 0:
                            sigle = carmove5to0(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;
                    case 1:
                            sigle = carmove5to1(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 2:
                            sigle = carmove5to2(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 3:
                            sigle = carmove5to3(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
            
                            break;
                    case 4:
                            sigle = carmove5to4(x,y);
                            if(sigle==1)
			                {
				                break;
			                }
                            break;

                    default:
                            break;
                }
                break;
        default:
                break;
    }
    return sigle;
}
//��ʾ��ɫ����//13926��ɫ//��ɫ65535
void starttoendroad(int nowplace,int aimplace,int color)
{
    switch (nowplace)
    {
        case 0:
                switch (aimplace)
                {
                    case 1:
                            bar(40,460,130,470,color);
	                        bar(40,460,50,725,color);
	                        bar(40,715,212,725,color);
                            break;
                    case 2:
                            bar(130,460,277,470,color);
	                        bar(267,20,277,470,color);
	                        bar(267,20,380,30,color);
                            break;
                    case 3:
                            bar(130,460,357,470,color);
            
                            break;
                    case 4:
                            bar(130,460,473,470,color);
	                        bar(463,460,473,725,color);
	                        bar(463,715,720,725,color);
	                        bar(710,560,720,725,color);
	
                            break;
                    case 5:
                            bar(130,460,473,470,color);
	                        bar(463,263,473,470,color);
	                        bar(450,263,473,273,color);
            
                            break;

                    default:
                            break;
                }
                break;
        case 1:
                switch (aimplace)
                {
                    case 0:
                            bar(40,460,130,470,color);
                            bar(40,460,50,725,color);
                            bar(40,715,212,725,color);
                            break;
                    case 2:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(267,460,473,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
	
                            break;
                    case 3:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(383,460,473,470,color);
                            break;
                    case 4:
                            bar(212,715,720,725,color);
	                        bar(710,560,720,725,color);
            
                            break;
                    case 5:
                            bar(212,715,473,725,color);
                            bar(463,263,473,725,color);
                            bar(450,263,473,273,color);
            
                            break;

                    default:
                            break;
                }
                break;
        case 2:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,277,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(267,460,473,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
                            break;
                    case 3:
                            bar(267,460,357,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
            
                            break;
                    case 4:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,720,273,color);
                            bar(710,263,720,560,color);
            
                            break;
                    case 5:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,450,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 3:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,357,470,color);
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,460,473,725,color);
                            bar(383,460,473,470,color);
            
                            break;
                    case 2:
                            bar(267,460,357,470,color);
                            bar(267,20,277,470,color);
                            bar(267,20,380,30,color);
            
                            break;
                    case 4:
                            bar(383,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
                            break;
                    case 5:
                            bar(383,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 4:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
                            break;
                    case 1:
                            bar(212,715,720,725,color);
                            bar(710,560,720,725,color);
            
                            break;
                    case 2:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,720,273,color);
                            bar(710,263,720,560,color);
            
                            break;
                    case 3:
                            bar(383,460,473,470,color);
                            bar(463,460,473,725,color);
                            bar(463,715,720,725,color);
                            bar(710,560,720,725,color);
            
                            break;
                    case 5:
                            bar(710,263,720,560,color);
	                        bar(450,263,720,273,color);
                            break;

                    default:
                            break;
                }
                break;
        case 5:
                switch (aimplace)
                {
                    case 0:
                            bar(130,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
	
                            break;
                    case 1:
                            bar(212,715,473,725,color);
                            bar(463,263,473,725,color);
                            bar(450,263,473,273,color);
                            break;
                    case 2:
                            bar(267,20,380,30,color);
                            bar(267,20,277,273,color);
                            bar(267,263,450,273,color);
            
                            break;
                    case 3:
                            bar(383,460,473,470,color);
                            bar(463,263,473,470,color);
                            bar(450,263,473,273,color);
            
                            break;
                    case 4:
                            bar(710,263,720,560,color);
	                        bar(450,263,720,273,color);
                            break;

                    default:
                            break;
                }
                break;
        default:
                break;
    }
}
// ����ɺ����ɶ���
void neworder(int *x,int *y,USEINFOR *infor, const CARFAST car[], const char **placename, int *aimplace, int mincar, char *ordertime,float price)
{
    int button=0;
    int mx=0;
    int my=0;
    char chprice[8];
    ORDER *order;
    
	if ((order = (ORDER*)malloc(sizeof(ORDER))) == NULL)
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
    strcpy(order->name,car[mincar].name);
    strcpy(order->carname,car[mincar].fastcar.carname);
    strcpy(order->type,car[mincar].fastcar.type);
    strcpy(order->startname,placename[infor->nowplace]);
    strcpy(order->endname,placename[*aimplace]);
    strcpy(order->money,chprice);
    strcpy(order->orderstime,ordertime);
    // changeOrder(infor);//�����ļ��еĶ����������Լ����ɱ��ζ�����ͼƬ������
    addOrder(infor,order);//��������Ϣ����ļ�
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

//���㲢��ʾ����֮��ļ۸�
void showprice(int nowplace,int *aimplace)
{
	// int pointlength[15];//����֮����̷�����
	float pointprice;//����֮��۸�
	int showx=905;//ȷ����ʾλ��
    int showy=370;
    int color;
	int timegap=0;
	int timecase=0;

	
	char pricing[10]="\0";//���ڼ۸���������ת��
	
	
	countprice(&pointprice,nowplace,aimplace,timegap,timecase);
	sprintf(pricing,"%.2f",pointprice);
	outtextxy(showx,showy,pricing,1,1,10,64384);
	
	
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
	

	kilometer=(pointlength[judging])/100+1-3;
	if(kilometer<0)
	{
		kilometer=0;
	}
	// minite=timegap/120+1-9;
    minite=timegap+1-9;
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

void costmoney(float *price,USEINFOR *infor,int *aimplace,int nowtime_hour,int timegap, int *x, int *y)
{
    int timecase;
    char chprice[8];
    int mx=0;
    int my=0;
    int button=0;

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
    
    sprintf(chprice,"%.2f",*price);

    mousehide(*x,*y);
    save_image(512-210,384-140,512+210,384+140,"notice");
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
        
            else
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
        else
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
// void initialize()