#ifndef module.h
#define module.h

/**************************************************
function:        overflow_box

description:     堆分配内存失败提示框

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void overflow_box(int x,int y);


/**************************************************
function:        null_box

description:     寻找文件失败提示框

Input:           x,y(坐标)

out:             提示框

quote:           advancegf.h,basicgf.h中相关画图函数,hzxs.h,input.h中文字函数
**************************************************************/
extern void null_box(int x,int y);

#endif