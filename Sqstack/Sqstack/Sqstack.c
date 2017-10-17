/***************************************************
Description:Sqstack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "Sqstack.h"
#include "malloc.h"

//初始化一个栈
SqStack * InitStack()
{
	SqStack *S = NULL;
	S = (SqStack *)malloc(sizeof(SqStack));

	//创建第一个节点
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (S->base == NULL)
		exit(OVERFLOW);

	//初始化栈结构体
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return S;
}

//销毁栈S，S不再存在
Status DestroyStack(SqStack *S)
{
	//由于顺序表的连续的空间，可以直接通过栈底指针释放
	free(S->base);
	S->base = S->top = NULL;//避免野指针
	S->stacksize = 0;
	return OK;
}

//将栈的元素全部弹出
Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack *S)
{
	if (S->base == S->top) 
		return TRUE;
	else return FALSE;
}

//判断当前栈内元素的长度
int StackLength(SqStack *S)
{
	return S->top - S->base;				//由于栈顶指针一直比栈顶的元素大1，所以栈顶指针减去栈底指针即为当前栈内的数据
}

//查找栈顶的元素
Status GetTop(SqStack *S, SElemType *e)
{
	if (StackEmpty(S)) 
		return ERROR;

	//若不为空，则选择栈顶的元素并返回
	*e = *(S->top - 1);
	return OK;
}


//入栈函数：插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
	//如果栈满了，则此时需要增加额外的空间存放新入栈的数据
	if ((S->top - S->base) >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (S->base == NULL)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;			//由于base的指针变了，所以这里都需要改变
		S->stacksize += STACKINCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return OK;
}

//出栈函数：删除S的栈顶元素，用e返回其值
Status Pop(SqStack *S, SElemType *e)
{
	if (S->base == S->top) 
		return ERROR;

	S->top--;
	*e = *(S->top);
	return OK;
}

//遍历栈，并输出元素
Status StackTraverse(SqStack *S, void(*visit)(SElemType *p))
{
	SElemType *p;
	p = S->base;     //从栈底像栈顶遍历
	while (p != S->top)
	{
		visit(p);
		p++;
	}
	return OK;
}