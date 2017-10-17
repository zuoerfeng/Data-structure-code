/***************************************************
Description:Liststack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Liststack.h"

//栈的初始化
void StackInit(Stack *top)
{
	//将栈顶指针置为空
	top->next = NULL;
}

//判断栈是否为空:为空返回1，不为空返回0
Status IsEmpty(Stack *top)
{
	//栈顶是否为空，栈顶为空即栈为空
	if (top->next == NULL)
	{
		return OK;
	}
	return ERROR;
}

//进栈：将元素element压入栈中。成功返回1，失败返回0
Status Push(Stack *top, char element)
{
	//创建新的节点，存放元素element
	Stack *p;
	p = (Stack*)malloc(sizeof(Stack));
	if (p == NULL)
	{
		return ERROR;
	}
	p->data = element;
	//入栈时栈顶不变，新的节点放入栈顶下面.即栈顶指针后移
	p->next = top->next;
	top->next = p;
	return OK;
}

//出栈：出栈的数据元素给element
Status Pop(Stack *top, char *element)
{
	Stack *p;
	if (IsEmpty(top))
		return ERROR;

	p = top->next;				//栈顶下面第一个节点，即是要出栈的
	*element = p->data;			
	top->next = p->next;		//栈顶前移
	free(p);					//释放内存空间
	return OK;
}
