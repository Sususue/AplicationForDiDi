#ifndef _COMMON_H_
#define _COMMON_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <bios.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <time.h>


#include "svgahead.h"
#include "mouse.h"
#include "hzk.h"
//#include"data.h"
#include "input.h"

#include "basicgf.h"//画图
#include"plusgf.h"



#include"usehead.h"//各种结构还有订单链表的初始化
#include"newcar.h"//初始化快车车辆

#include"welcome.h"//欢迎界面和登录注册
#include"frame.h"
#include"module.h"
#include"filefun.h"
#include"sign.h"


#include "basicmap.h"  //主界面地图
#include "map.h"

#include "useinfor.h" //用户个人信息
#include "paybox.h"//钱包
#include "carmove.h"//快车动画


#include "endorder.h"//快车完成后生成订单，以及计算价格
#include "place.h"//快车选择目的地
#include "judgfast.h"//判断那辆快车，哪个动画
#include "cartake.h"//快车

#include "rentmove.h"//租车动画
#include "findway.h"//寻路
#include "carrent.h"//租车

#include "select.h"  //主进程
 



#endif