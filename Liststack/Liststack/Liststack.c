/***************************************************
Description:Liststack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Liststack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack *top)
{
	//��ջ��ָ����Ϊ��
	top->next = NULL;
}

//�ж�ջ�Ƿ�Ϊ��:Ϊ�շ���1����Ϊ�շ���0
Status IsEmpty(Stack *top)
{
	//ջ���Ƿ�Ϊ�գ�ջ��Ϊ�ռ�ջΪ��
	if (top->next == NULL)
	{
		return OK;
	}
	return ERROR;
}

//��ջ����Ԫ��elementѹ��ջ�С��ɹ�����1��ʧ�ܷ���0
Status Push(Stack *top, char element)
{
	//�����µĽڵ㣬���Ԫ��element
	Stack *p;
	p = (Stack*)malloc(sizeof(Stack));
	if (p == NULL)
	{
		return ERROR;
	}
	p->data = element;
	//��ջʱջ�����䣬�µĽڵ����ջ������.��ջ��ָ�����
	p->next = top->next;
	top->next = p;
	return OK;
}

//��ջ����ջ������Ԫ�ظ�element
Status Pop(Stack *top, char *element)
{
	Stack *p;
	if (IsEmpty(top))
		return ERROR;

	p = top->next;				//ջ�������һ���ڵ㣬����Ҫ��ջ��
	*element = p->data;			
	top->next = p->next;		//ջ��ǰ��
	free(p);					//�ͷ��ڴ�ռ�
	return OK;
}
