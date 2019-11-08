#include "common.h"
#include "newcar.h"

#define CARNUMBER 24
#define USINGNUM 10

void newfast(void)
{
    int i;
    CARFA fast[25];//��Դ�ؿ쳵����
    char cartpye[6][7];//��������
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    CARFA *pfast = fast;
    CARFA *p;

    strcpy(fast[0].fastcar.carname,"B7351");
    strcpy(fast[1].fastcar.carname,"92857");
    strcpy(fast[2].fastcar.carname,"A6103");
    strcpy(fast[3].fastcar.carname,"61135");
    strcpy(fast[4].fastcar.carname,"C2861");
    strcpy(fast[5].fastcar.carname,"B8963");
    strcpy(fast[6].fastcar.carname,"C8272");
    strcpy(fast[7].fastcar.carname,"95512");
    strcpy(fast[8].fastcar.carname,"B3519");
    strcpy(fast[9].fastcar.carname,"93760");
	strcpy(fast[10].fastcar.carname,"95287");
	strcpy(fast[11].fastcar.carname,"A2392");
	strcpy(fast[12].fastcar.carname,"C6665");
	strcpy(fast[13].fastcar.carname,"B7328");
	strcpy(fast[14].fastcar.carname,"C1275");
	strcpy(fast[15].fastcar.carname,"91295");
	strcpy(fast[16].fastcar.carname,"B3028");
	strcpy(fast[17].fastcar.carname,"C9778");
	strcpy(fast[18].fastcar.carname,"A9517");
	strcpy(fast[19].fastcar.carname,"B2637");
	strcpy(fast[20].fastcar.carname,"C7970");
	strcpy(fast[21].fastcar.carname,"B3187");
	strcpy(fast[22].fastcar.carname,"A5681");
	strcpy(fast[23].fastcar.carname,"B1886");
	strcpy(fast[24].fastcar.carname,"97395");

    strcpy(fast[0].name,"��");
    strcpy(fast[1].name,"��");
    strcpy(fast[2].name,"��");
    strcpy(fast[3].name,"��");
    strcpy(fast[4].name,"��");
    strcpy(fast[5].name,"��");
    strcpy(fast[6].name,"��");
    strcpy(fast[7].name,"��");
    strcpy(fast[8].name,"��");
    strcpy(fast[9].name,"��");
    strcpy(fast[10].name,"��");
    strcpy(fast[11].name,"��");
    strcpy(fast[12].name,"��");
    strcpy(fast[13].name,"��");
    strcpy(fast[14].name,"��");
    strcpy(fast[15].name,"��");
    strcpy(fast[16].name,"ţ");
    strcpy(fast[17].name,"��");
    strcpy(fast[18].name,"��");
    strcpy(fast[19].name,"Ѧ");
    strcpy(fast[20].name,"��");
    strcpy(fast[21].name,"��");
    strcpy(fast[22].name,"��");
    strcpy(fast[23].name,"��");


    strcpy(cartpye[0],"����");
    strcpy(cartpye[1],"����");
    strcpy(cartpye[2],"������");
    strcpy(cartpye[3],"����");
    strcpy(cartpye[4],"��̩");
    strcpy(cartpye[5],"����"); 

    if ((fp = fopen("driver\\fastcar.txt", "wb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 

    for ( i = 0; i < CARNUMBER; i++)
    {
        if (i<10)
        {
            fast[i].call = 1;
        }
        else
        {
            fast[i].call = 0;
        }
        fast[i].praise = 5;
        fast[i].number = i;
        fast[i].fastcar.x = 0;
        fast[i].fastcar.y = 0;
        fast[i].order = 0;
        strcpy(fast[i].fastcar.type,cartpye[i%6]);
        fwrite(pfast,sizeof(CARFA),1,fp);
        pfast++;
    }

    if ((fp2 = fopen("driver\\usecar.txt", "wb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 

    if((p = (CARFA *)malloc(sizeof(CARFA))) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
    fseek(fp,0L,SEEK_SET);//�ǵð��ļ�ָ���Ƶ���ͷ����Ȼ���������
    i=0;
    while (i<10)
    {
        fread(p,sizeof(CARFA),1,fp);
        if (p->call == 1)
        {
            p->order = i;
            fwrite(p,sizeof(CARFA),1,fp2);
            i++;
        }
    }
    
    free(p);
    p = NULL;
    fclose(fp);
    fclose(fp2);
}
//�滻˾��
void managecar(int *x,int *y,CARFA *car)
{
   FILE *fp = NULL;
   CARFA anothercar;
   int note = 0; //���ļ����궼�Ҳ�������Ҫ��ģ������˳�
//    �ڳ�����Դ�����ҵ���δ���õĳ���
   

    if ((fp = fopen("driver\\fastcar.txt", "rb+")) == NULL)//������Դ�����Ϣ
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 

    do
    {
        fread(&anothercar,sizeof(CARFA),1,fp);
        if (feof(fp)!=0)
        {
            note = 1;
        }
        
    } while (anothercar.call != 0);
    
    anothercar.call = 1 ;
    fseek(fp,-1L*sizeof(CARFA),SEEK_CUR);
    fwrite(&anothercar,sizeof(CARFA),1,fp);
    fclose(fp);

    if (note == 0)
    {
        if ((fp = fopen("driver\\usecar.txt", "rb+")) == NULL)
        {
            null_box(500,500);
            getch();
            exit(1);
        } 
        
        anothercar.order = car->order;
        fseek(fp,sizeof(CARFA)*car->order,SEEK_SET);
        fwrite(&anothercar,sizeof(CARFA),1,fp);
    
        
        // fseek(fp,0L,SEEK_SET);
        // fread(thiscar,sizeof(CARFA),1,fp);
        fclose(fp);

        mousehide(*x,*y);
        save_image(483-210,384-140,483+210,384+140,"note");
        bar_round(483,384,416,270,50,1,64384);
        bar_round(483,384,410,265,48,1,65535);
        fdhz(411,340,2,2,"�滻�ɹ�",64384);
        fdhz(431,430,1,1,"�����������",44373);
        getch();
        printf_image(483-210,384-140,483+210,384+140,"note");
        reset_mouse(x,y);
    }
    else
    {
        mousehide(*x,*y);
        save_image(483-210,384-140,483+210,384+140,"note");
        bar_round(483,384,416,270,50,1,64384);
        bar_round(483,384,410,265,48,1,65535);
        fdhz(341,340,2,2,"û�п��滻˾��",64384);
        fdhz(431,430,1,1,"�����������",44373);
        getch();
        printf_image(483-210,384-140,483+210,384+140,"note");
        reset_mouse(x,y);
    }
    
    
    

    
}
