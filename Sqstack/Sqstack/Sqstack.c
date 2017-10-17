/***************************************************
Description:Sqstack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "Sqstack.h"
#include "malloc.h"

//��ʼ��һ��ջ
SqStack * InitStack()
{
	SqStack *S = NULL;
	S = (SqStack *)malloc(sizeof(SqStack));

	//������һ���ڵ�
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (S->base == NULL)
		exit(OVERFLOW);

	//��ʼ��ջ�ṹ��
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return S;
}

//����ջS��S���ٴ���
Status DestroyStack(SqStack *S)
{
	//����˳���������Ŀռ䣬����ֱ��ͨ��ջ��ָ���ͷ�
	free(S->base);
	S->base = S->top = NULL;//����Ұָ��
	S->stacksize = 0;
	return OK;
}

//��ջ��Ԫ��ȫ������
Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack *S)
{
	if (S->base == S->top) 
		return TRUE;
	else return FALSE;
}

//�жϵ�ǰջ��Ԫ�صĳ���
int StackLength(SqStack *S)
{
	return S->top - S->base;				//����ջ��ָ��һֱ��ջ����Ԫ�ش�1������ջ��ָ���ȥջ��ָ�뼴Ϊ��ǰջ�ڵ�����
}

//����ջ����Ԫ��
Status GetTop(SqStack *S, SElemType *e)
{
	if (StackEmpty(S)) 
		return ERROR;

	//����Ϊ�գ���ѡ��ջ����Ԫ�ز�����
	*e = *(S->top - 1);
	return OK;
}


//��ջ����������Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack *S, SElemType e)
{
	//���ջ���ˣ����ʱ��Ҫ���Ӷ���Ŀռ�������ջ������
	if ((S->top - S->base) >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (S->base == NULL)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;			//����base��ָ����ˣ��������ﶼ��Ҫ�ı�
		S->stacksize += STACKINCREMENT;
	}
	*(S->top) = e;
	S->top++;
	return OK;
}

//��ջ������ɾ��S��ջ��Ԫ�أ���e������ֵ
Status Pop(SqStack *S, SElemType *e)
{
	if (S->base == S->top) 
		return ERROR;

	S->top--;
	*e = *(S->top);
	return OK;
}

//����ջ�������Ԫ��
Status StackTraverse(SqStack *S, void(*visit)(SElemType *p))
{
	SElemType *p;
	p = S->base;     //��ջ����ջ������
	while (p != S->top)
	{
		visit(p);
		p++;
	}
	return OK;
}