#ifndef  _USEHEAD_H_
#define  _USEHEAD_H_

/***********************
 1.相关的结构
 2.用户信息链表的初始化
 3.对用户信息的相关操作
 ***********************/ 
typedef struct place{
	int x;           //几个点的位置
	int y;
}PLACE;

typedef struct carinfor{
	int x;           //车的位置
	int y;
	char type[7];  //区分车的型号
    char carname[6];       //车牌号码，默认鄂A开头
}CARINFOR;


// typedef struct carfast{
// 	char name[3];        //车主名字对应的号码
//     CARINFOR fastcar;
// }CARFAST;     //存储快车车辆的信息的




typedef struct carfa{
	char name[3];        //车主名字对应的号码
    
	int call;//报警情况 0:未启用 1:正常接单 2:被报警 -1:被踢 
	int praise;//评价 初始化为5
	int number;//存储位置的编号        //在资源池文件中用编号寻找位置进行替换，在正在使用的文件中可以用对比车牌号的方式寻找并替换
	int order;//在usecar文件里的顺序
	CARINFOR fastcar;
}CARFA;     //重新写的存储快车车辆的信息的结构





typedef struct park{
	int parknum;        //该停车场的编号
    int carnum;   //车的数量
	int x;  //停车场位置
	int y;
}PARK;


typedef struct carrent{
	int parknum;        //所处停车场的编号
    CARINFOR rentcar;
	int leftenergy;        //车辆剩余电量
}CARRENT;          //共享汽车的信息

/************************************
 用一个文件存整个链表，用一个链表存所有用户的订单信息
 以订单数量确认用户新订单的序号
 以用户电话加订单序号的形式存储每一个订单截图
 num:为订单总数
 cnt:保存结点位置，这样在进入主进程时，可以不用将链表传入
-------------------------------------------------
 由于dos下文件最多8个字符，使用用户名对应的mark(即order里的cnt数字)存文件，
一个用户一个文件
payway:支付方式，1表示钱包支付，2表示微信支付，3表示支付宝支付
nowplace:用户现在所处的位置用数字对应
		0:学校 1:小区 2:东湖 3:商场 4:图书馆 5:游泳馆
money:用户钱包的余额
 *************/
typedef struct useinfor{
	int cnt;  //记录是链表中的第几个结点(不含头结点)
    int num;     //快车订单的数量
	int rentnum;//租车的订单数量
	int payway; //支付方式:1为余额支付，2为微信支付，3为支付宝支付 默认为0-未设置
	int nowplace;    //存位置对应的号码  刚开始默认为在学校
	float money;//金额
	char phone_num[12]; //用户电话
	struct useinfor *next;
}USEINFOR; //用于存储用户的信息

typedef struct order{
	char name[3];//司机名字
	char carname[6];//车牌
	char type[7];  //车的型号
	char startname[7];//起点
	char endname[7];//终点
	char money[8];//金额
	char orderstime[11];//日期
}ORDER; //用于存储订单的信息


typedef struct rentorder{
	char carname[7];//车牌
	char type[7];  //车的型号
	char during[5];//持续时间
	char money[8];//金额
	char orderstime[11];//日期
}RENTORDER; //用于存储租车订单的信息

typedef struct users{
	char phone_num[12];
	char code[11];
    struct users *next;
}USER;       //存储用户的账号和密码


/*********************************************************
Function: CreateOrderList
Description: 根据order.txt文件中的信息创建用户链表
Attention: 1、传递过来的头指针一定要有确定的指向！
		   2、创建的链表的开头不存有效数据！
Return:无返回值
***********************************************************/
extern void CreateInforList(USEINFOR *head);




/************************************
Function: AddNewOrder
Description: 创建新的用户订单
Attention:s1指代用户串
Return:
*************************************/
extern void AddNewInfor(USEINFOR *head,char *phone);



/****************************************************
Function: SearchOrder
Description: 传入指定电话号码,并返回对应用户的订单数量
Attention:
Return:若有则返回对应的订单数量，若没有则返回0
****************************************************/
// extern int SearchPhone(USER *head,char *phone);

// /****************************************************
// Function: changeOrder
// Description: 传入指定电话号码,并修改对应用户的订单数量(增加1)
// Attention:
// Return:无
// ****************************************************/
// extern void changeOrder(USEINFOR *infor);


/****************************************************
Function: changeOrder
Description: 传入指定电话号码,与订单结构，并修改对应用户的订单数量(增加1)
Attention:
Return:无
****************************************************/
extern void addOrder(USEINFOR *infor, ORDER *order);



/****************************************************
Function: findOrder
Description: 传入当前用户信息,与订单结构
			打开文件的形式保存//形式存订单图
			以用户结点位置(infor->cnt)的形式存文件，一个用户的订单都存在一个文件中
			例如 1:第一个用户的订单
			n:第几个订单
Attention:
Return:无
****************************************************/
void findOrder(USEINFOR *infor, ORDER *order, int n);



/****************************************************
Function: addRentOrder
Description: 传入当前用户信息,并修改对应用户的订单数量(增加1)，与订单结构
			生成新订单,并以文件的形式保存//形式存订单图
			以用户结点位置(infor->cnt)加订单数的形式存文件，中间用下划线隔开
			例如 1_2 :第一个用户的第二个订单
Attention:
Return:无
****************************************************/
void addRentOrder(USEINFOR *infor, RENTORDER *order);




/****************************************************
Function: findRentOrder
Description: 传入当前用户信息infor,与订单结构order
			打开文件的形式保存//形式存订单图
			以用户结点位置(infor->cnt)的形式存文件，一个用户的订单都存在一个文件中
			例如 1:第一个用户的订单
			n:第几个订单
Attention:
Return:无
****************************************************/
void findRentOrder(USEINFOR *infor, RENTORDER *order, int n);



/****************************************************
Function: findInfor
Description: 传入指定电话号码,在链表中找到对应用户的订单
Attention:phone为电话号码
Return:无
****************************************************/
void findInfor(USEINFOR *head, USEINFOR *infor, char *phone);



/***********************************************
Function: freeOrderlist
Description:释放链表的内存空间并将头指针置为NULL
Attention:文件必须按要求格式化书写
Return:
************************************************/
extern void freeInforlist(USEINFOR **head);



/****************************************************
Function: changePay
Description: 传入指定电话号码,并修改对应用户的支付方式与金额(增加1)
			根据传入mode的值确定修改什么
			mode:1.修改余额 2.修改支付方式
			value为修改的值
Attention:
Return:无
****************************************************/
void changePay(USEINFOR *infor, int mode,int value);



/****************************************************
Function: changeNowplace
Description: 传入当前用户信息，修改当前位置
		
			aimplace:之前的终点(目的地)
Attention:
Return:无
****************************************************/
void changeNowplace(USEINFOR *infor, int aimplace);



/****************************************************
Function: changeMoney
Description: 传入当前用户信息，修改当前位置
			price:订单金额
Attention:
Return:无
****************************************************/
void changeMoney(USEINFOR *infor, float price);



#endif