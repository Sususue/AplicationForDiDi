#include "common.h"
#include "newcar.h"

#define CARNUMBER 24
#define USINGNUM 10

void newfast(void)
{
    int i;
    CARFA fast[25];//资源池快车数组
    char cartpye[6][7];//车辆类型
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

    strcpy(fast[0].name,"张");
    strcpy(fast[1].name,"李");
    strcpy(fast[2].name,"赵");
    strcpy(fast[3].name,"王");
    strcpy(fast[4].name,"孙");
    strcpy(fast[5].name,"唐");
    strcpy(fast[6].name,"马");
    strcpy(fast[7].name,"刘");
    strcpy(fast[8].name,"周");
    strcpy(fast[9].name,"杨");
    strcpy(fast[10].name,"宋");
    strcpy(fast[11].name,"何");
    strcpy(fast[12].name,"方");
    strcpy(fast[13].name,"陈");
    strcpy(fast[14].name,"许");
    strcpy(fast[15].name,"苏");
    strcpy(fast[16].name,"牛");
    strcpy(fast[17].name,"巫");
    strcpy(fast[18].name,"罗");
    strcpy(fast[19].name,"薛");
    strcpy(fast[20].name,"贾");
    strcpy(fast[21].name,"林");
    strcpy(fast[22].name,"孟");
    strcpy(fast[23].name,"姜");


    strcpy(cartpye[0],"朗逸");
    strcpy(cartpye[1],"轩逸");
    strcpy(cartpye[2],"卡罗拉");
    strcpy(cartpye[3],"景逸");
    strcpy(cartpye[4],"众泰");
    strcpy(cartpye[5],"丰田"); 

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
    fseek(fp,0L,SEEK_SET);//记得把文件指针移到开头，不然问题很严重
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
//替换司机
void managecar(int *x,int *y,CARFA *car)
{
   FILE *fp = NULL;
   CARFA anothercar;
   int note = 0; //若文件找完都找不到符合要求的，报错退出
//    在车辆资源池中找到还未启用的车辆
   

    if ((fp = fopen("driver\\fastcar.txt", "rb+")) == NULL)//更改资源库的信息
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
        fdhz(411,340,2,2,"替换成功",64384);
        fdhz(431,430,1,1,"按任意键继续",44373);
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
        fdhz(341,340,2,2,"没有可替换司机",64384);
        fdhz(431,430,1,1,"按任意键继续",44373);
        getch();
        printf_image(483-210,384-140,483+210,384+140,"note");
        reset_mouse(x,y);
    }
    
    
    

    
}
