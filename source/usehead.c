#include "common.h"
#include "usehead.h"

/*
订单链表
*/

/********************************************************************************
Function: CreateInforList
Description: 根据infor.txt文件中的信息创建用户链表
Attention: 1.传递过来的头指针一定要有确定的指向！
		   2.创建的链表的开头不存有效数据！
		   3.用rb+打开，文件需要存在
Return:无返回值
*********************************************************************************/
void CreateInforList(USEINFOR *inforhead)
{
	USEINFOR *current = NULL;//指向当前结点的指针变量
    FILE *fp=NULL;    //用于打开usercode.txt的文件指针
	int size;
  	/*必要的初始化过程*/
	inforhead->phone_num[0]='\0';
	inforhead->num = 0;
	inforhead->cnt=0;
	inforhead->payway=0;
	inforhead->nowplace=0;
	inforhead->money=0.0;
	inforhead->next=NULL;

	current = inforhead;


  	if ((fp = fopen("user\\infor.txt", "rb+")) == NULL)
  	{
	  	null_box(500,500);
	  	getch();
	  	exit(1);
  	} 

	// fseek(fp,0L,SEEK_END);//判断文件是否为空
	// size=ftell(fp);
	// fseek(fp,0L,SEEK_SET);//将文件指针移回开头

  	// // while(!feof(fp)&&size!=0)
	// if(size!=0)//判断文件是否为空
	// {
	fgetc(fp);//判断文件是否为空文件，若为空，要读一下才能置位为EOF,feof()才能准确检测
	while(feof(fp)==0)/*判断指针是否已到达文件尾部，若到达尾部则返回一个不为零的值   */
	{
		fseek(fp,-1L,SEEK_CUR);//将指针移回来
			/*向系统申请空间*/
		if((current->next=(USEINFOR *)malloc(sizeof(USEINFOR)))==NULL)
		{
			overflow_box(500,500);
			getch();
			exit(1);
		}
		current=current->next;
		//读出一个结点
		fread(current,sizeof(USEINFOR),1,fp);
		current->next=NULL;	
		fgetc(fp);/*判断指针是否已到达文件尾部*/
	}
	// }	
  	fclose(fp);
}  


// void CreateinforList(infor *inforhead)
// {
// 	infor *current = NULL;//指向当前结点的指针变量
//     FILE *fp=NULL;    //用于打开usercode.txt的文件指针
// 	int size;
//   	/*必要的初始化过程*/
// 	inforhead->phone_num[0]='\0';
// 	inforhead->num = 0;
// 	inforhead->cnt=0;
// 	inforhead->next=NULL;

// 	current = inforhead;


//   	if ((fp = fopen("user\\infor.txt", "rb+")) == NULL)
//   	{
// 	  	null_box(500,500);
// 	  	getch();
// 	  	exit(1);
//   	} 

// 	fseek(fp,0L,SEEK_END);//判断文件是否为空
// 	size=ftell(fp);
// 	fseek(fp,0L,SEEK_SET);//将文件指针移回开头

//   	// while(!feof(fp)&&size!=0)
// 	if(size!=0)//判断文件是否为空
// 	{
// 		while(fgetc(fp)!=EOF)/*判断指针是否已到达文件尾部*/
// 		{
// 			fseek(fp,-1L,SEEK_CUR);//将指针移回来
// 				/*向系统申请空间*/
// 			if((current->next=(infor *)malloc(sizeof(infor)))==NULL)
// 			{
// 				overflow_box(500,500);
// 				getch();
// 				exit(1);
// 			}
// 			current=current->next;
// 			//读出一个结点
// 			fread(current,sizeof(infor),1,fp);
// 			current->next=NULL;	
// 		}
// 	}	
//   	fclose(fp);
// }  



/************************************
Function: AddNewInfor
Description: 创建新的用户订单
Attention:phone指代用户电话串
Return:
*************************************/
void AddNewInfor(USEINFOR *head,char *phone)
{
	USEINFOR *current = head;
	FILE *fp;
	
	int n=0;   //记录是第几个结点(不含头结点) 
	/*以下程序块是为新用户在链表中创建节点*/
	while(current->next != NULL) //这个位置不知道为什么只有头结点的时候还是会进入一次循环
	                              //√发现是创建链表中的feof()的机制问题，导致无法一次判断是否为文件末尾
	{
		current = current->next;
		n++;
	}
	if((current->next = (USEINFOR *)malloc(sizeof(USEINFOR))) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	strcpy((current->next)->phone_num,phone);
	(current->next)->num = 0; //初始订单数量都为0
	(current->next)->cnt=n;
	(current->next)->payway=0;
	(current->next)->money=0.0;
	(current->next)->nowplace=0;
	(current->next)->next = NULL;
	
	/*以下程序块是将将新用户的信息写入infor.txt文件末尾*/
	if((fp = fopen("user\\infor.txt","ab")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
    fwrite(current->next,sizeof(USEINFOR),1,fp);

 	fclose(fp);

	// sprintf(filename,"order\\%d.txt",n);//生成一个以用户结点数为名字的文件用于存储订单
	// if((fp_order = fopen(filename,"w+")) == NULL)
	// {
	// 	null_box(500,500);
	// 	getch();
	// 	exit(1);
	// }
	// fclose(fp_order);
}



/****************************************************
Function: changeOrder
Description: 传入当前用户信息,并修改对应用户的订单数量(增加1)
			生成新订单,并以图片的形式保存//截图形式存订单图
			以用户结点位置(infor->cnt)加订单数的形式存文件，中间用下划线隔开
			例如 1_2 :第一个用户的第二个订单
Attention:
Return:无
****************************************************/
// void changeOrder(USEINFOR *infor)
// {
// 	FILE *fp;
	
// 	char filename[20];//存名字


// 	infor->num=(infor->num)+1;
// 	//修改文件中
// 	if((fp = fopen("USER\\infor.txt","rb+")) == NULL)
// 	{
// 		null_box(500,500);
// 		getch();
// 		exit(1);
// 	}
// 	/*将文件内部指针移到文件中需要修改的位置*/
//     fseek(fp,sizeof(USEINFOR)*infor->cnt,SEEK_SET);

//     fwrite(infor,sizeof(USEINFOR),1,fp);

//  	fclose(fp);

// 	sprintf(filename,"%d_%d",infor->cnt,infor->num);
	
// 	//写入图片
// 	save_image(96,300,670,630,filename);
// }

/****************************************************
Function: addOrder
Description: 传入当前用户信息,并修改对应用户的订单数量(增加1)，与订单结构
			生成新订单,并以文件的形式保存//形式存订单图
			以用户结点位置(infor->cnt)加订单数的形式存文件，中间用下划线隔开
			例如 1_2 :第一个用户的第二个订单
Attention:
Return:无
****************************************************/
void addOrder(USEINFOR *infor, ORDER *order)
{
	FILE *fp;
	FILE *fp_order;
	char filename[20];//存名字


	infor->num=(infor->num)+1;
	//修改文件中
	if((fp = fopen("USER\\infor.txt","rb+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	/*将文件内部指针移到文件中需要更改的位置*/
    fseek(fp,sizeof(USEINFOR)*infor->cnt,SEEK_SET);

    fwrite(infor,sizeof(USEINFOR),1,fp);

 	fclose(fp);

	sprintf(filename,"order\\%d.txt",infor->cnt);
	if((fp_order = fopen(filename,"ab+")) == NULL)
	// if((fp = fopen(filename,"wb")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	fwrite(order,sizeof(ORDER),1,fp_order);

	fclose(fp_order);
	
}

/****************************************************
Function: findOrder
Description: 传入当前用户信息infor,与订单结构order
			打开文件的形式保存//形式存订单图
			以用户结点位置(infor->cnt)的形式存文件，一个用户的订单都存在一个文件中
			例如 1:第一个用户的订单
			n:第几个订单
Attention:
Return:无
****************************************************/
void findOrder(USEINFOR *infor, ORDER *order, int n)
{
	FILE *fp_order;
	char filename[20];//存名字

	sprintf(filename,"order\\%d.txt",infor->cnt);
	if((fp_order = fopen(filename,"rb+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	fseek(fp_order,sizeof(ORDER)*(n-1),SEEK_SET);
	fread(order,sizeof(ORDER),1,fp_order);//将订单信息写入订单结构

	fclose(fp_order);
	
}

/****************************************************
Function: findInfor
Description: 传入指定电话号码,在链表中找到对应用户的订单
Attention:
Return:无
****************************************************/
void findInfor(USEINFOR *head,USEINFOR *infor,char *phone)
{
 	USEINFOR *current=head;

	//当current不是最后一个结点并且当前的电话号码不相同时，继续比较下一个
 	while(current!=NULL&&strcmp(current->phone_num,phone)!=0)
 	{
   		current=current->next;
 	}
	infor->num=current->num;
	infor->cnt=current->cnt;
	infor->payway=current->payway;
	infor->money=current->money;
	infor->nowplace=current->nowplace;
	strcpy(infor->phone_num,current->phone_num);
	infor->next=current->next;
	
}


/***********************************************
Function: freeInforlist
Description:释放链表的内存空间并将头指针置为NULL
Attention:文件必须按要求格式化书写
Return:
************************************************/
void freeInforlist(USEINFOR **head)
{
	USEINFOR *pre = *head;
	USEINFOR *current = (*head)->next;

	if (*head == NULL)return ;

	while (current != NULL)
	{
		free(pre);
		pre = current;
		current = current->next;
	}
	free(pre);
	*head = NULL;
}


/****************************************************
Function: changePay
Description: 传入当前用户信息,并修改对应用户的支付方式与金额(增加1)
			根据传入mode的值确定修改什么
			mode:1.修改余额 2.修改支付方式
			value为修改的值
Attention:
Return:无
****************************************************/
void changePay(USEINFOR *infor, int mode,int value)
{
	FILE *fp;

	if (mode == 1)
	{
		infor->money+=value;
	}
	else if(mode == 2)
	{
		infor->payway=value;
	}

	//修改文件中
	if((fp = fopen("USER\\infor.txt","rb+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	/*将文件内部指针移到文件中需要修改的位置*/
    fseek(fp,sizeof(USEINFOR)*infor->cnt,SEEK_SET);

    fwrite(infor,sizeof(USEINFOR),1,fp);

 	fclose(fp);
	
}
/****************************************************
Function: changeNowplace
Description: 传入当前用户信息，修改当前位置
		
			aimplace:之前的终点(目的地)号码
Attention:
Return:无
****************************************************/
void changeNowplace(USEINFOR *infor, int aimplace)
{
	FILE *fp;

	infor->nowplace=aimplace;
	
	//修改文件中
	if((fp = fopen("USER\\infor.txt","rb+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	/*将文件内部指针移到文件中需要修改的位置*/
    fseek(fp,sizeof(USEINFOR)*infor->cnt,SEEK_SET);

    fwrite(infor,sizeof(USEINFOR),1,fp);

 	fclose(fp);
	
}
/****************************************************
Function: changeMoney
Description: 传入当前用户信息，修改当前位置
			price:订单金额
Attention:
Return:无
****************************************************/
void changeMoney(USEINFOR *infor, float price)
{
	FILE *fp;


	infor->money-=price;
	//修改文件中
	if((fp = fopen("USER\\infor.txt","rb+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	/*将文件内部指针移到文件中需要修改的位置*/
    fseek(fp,sizeof(USEINFOR)*infor->cnt,SEEK_SET);

    fwrite(infor,sizeof(USEINFOR),1,fp);

 	fclose(fp);
}
		
		

	
	
	
	
	
	
	


