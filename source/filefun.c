#include "common.h"
#include "filefun.h"


/********************************************************************************
Function: CreateUserList
Description: 根据usercode.txt文件中的信息创建用户链表
Attention: 1、传递过来的头指针一定要有确定的指向！
           2、若usercode.txt文件被清空，要在其开头用记事本加上#号才能正常创建链表！
		   3、创建的链表的开头与末尾节点都不存有效数据！
Return:无返回值
*********************************************************************************/
void CreateUserList(USER *head)
{
	USER *current = NULL;//指向当前结点的指针变量
    FILE *fp=NULL;    //用于打开usercode.txt的文件指针
    char ch;    //用于接收并传送文件内部字符的中间变量
    char *p=NULL;   //指向需要接收字符的地址的指针变量
	
	
  /*必要的初始化过程*/
  current = head;
  p = head->phone_num;
  strcpy(head->code, "     ");   //防止不输入账号密码直接点登陆进入的情况发生
  strcpy(head->phone_num,"      ");


  if ((fp = fopen("USER\\usercode.txt", "r+")) == NULL)
  {
	  null_box(500,500);
	  getch();
	  exit(1);
  }  
  while(!feof(fp))/*判断指针是否已到达文件尾部*/
  {
	ch=fgetc(fp);    //从usercode.txt文件中提取一个字符

	if(ch=='#')    //表示账户串的开始，密码串的结束
	 {
		/*向系统申请空间*/
	   if((current->next=(USER *)malloc(sizeof(USER)))==NULL)
		{
           overflow_box(500,500);
		   getch();
		   exit(1);
		}

	   current=current->next;

	   *p='\0';
	   p=current->phone_num;
	 }
	else if(ch=='*')      //表示账户串的结束，密码串的开始
	{
	  *p='\0';
	  p=current->code;
	}
	else if(ch!=' '&&ch!='\n')       //将对应的账户串或密码串装入链表中
	{
	  *p=ch;
	  p++;
	}
  }

  strcpy(current->code, "   "); //防止直接点击登陆进入的情况发生
  current->next=NULL;
  fclose(fp);
}  

/************************************
Function: AddNewUser
Description: 创建新的用户
Attention:s1指代用户串，s2指代密码串
Return:
*************************************/
void AddNewUser(USER *head,char *s1,char *s2)
{
	USER *current = head;
	FILE *fp;
	char *p;
	int length = strlen(s2);
    int i = 0;	
	
	/*以下程序块是为新用户在链表中创建节点*/
	while(current->next != NULL)
	{
		current = current->next;
	}
	strcpy(current->phone_num,s1);
	strcpy(current->code,s2);
	if((current->next = (USER *)malloc(sizeof(USER))) == NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	current = current->next;
	strcpy(current->phone_num," ");
	strcpy(current->code," ");
	current->next = NULL;
	
	/*以下程序块是将将新用户的信息写入usercode.txt文件中*/
	if((fp = fopen("USER\\usercode.txt","r+")) == NULL)
	{
		null_box(500,500);
		getch();
		exit(1);
	}
	/*将文件内部指针移到文件末端*/
    fseek(fp,0L,2);

    p=s1;
    while(*p!='\0')
    {
	    putc(*p,fp);//输入字符到指定文件
	    p++;
    }
    putc('*',fp);//账户串结束，密码串开始

    p=s2;
    while(*p!='\0')
    {
	    putc(*p,fp);
	    p++;
    }
    for (i = 0;i < 10 - length;i++)
	{
	  putc(' ', fp);
	}
    putc('#',fp);

 	fclose(fp);
}

/****************************************************
Function: SearchAccounts
Description: 在链表中搜索账号信息
Attention:
Return:若有则返回对应的密码串的地址，若没有则返回NULL
****************************************************/
char *SearchAccounts(USER *head,char *string)
{
 USER *current=head;

 while(current&&strcmp(current->phone_num,string)!=0)
 {
   current=current->next;
 }
 if(!current)return NULL;
 else return current->code;
}



/***********************************************
Function: freeUserlist
Description:释放链表的内存空间并将头指针置为NULL
Attention:文件必须按要求格式化书写
Return:
************************************************/
void freeUserlist(USER **head)
{
	USER *previous = *head;
	USER *current = (*head)->next;

	if (*head == NULL)return ;

	while (current != NULL)
	{
		free(previous);
		previous = current;
		current = current->next;
	}
	free(previous);
	*head = NULL;
}