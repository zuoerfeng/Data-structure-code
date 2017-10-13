/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "dulinklist.h"

//����˫����
dulinkList * dulinkListCreate()
{
	//����������ʱ����
	dulinkList *list = NULL;
	dulinkList *p = NULL;
	dulinkList *q = NULL;
	char ch = '0';

	//���ȴ����׽ڵ�
	list = (dulinkList *)malloc(sizeof(dulinkList));
	list->data = '/0';
	list->prior = NULL;
	list->next = NULL;

	p = list;
	printf("input element:");
	//��ʼ���ӽڵ���
	while ((ch = getchar()) != '\n')
	{
		q = (dulinkList *)malloc(sizeof(dulinkList));
		q->data = ch;
		q->next = NULL;
		q->prior = p;

		//����ǰ��ָ��
		p->next = q;
		p = q;
	}

	//�����˫������Ľ����������ײ�ָ��
	return list;
}

//���ң�����λ�ò��ҽڵ㣬����λ��Ϊn���Ľڵ㲢����
dulinkList * ElemLocatebyNum(dulinkList *list, int n)
{
	dulinkList *p = NULL;
	int i = 1;

	//����ȡ�õ�һ�ڵ�ĵ�ַ
	p = list->next;
	while (p != NULL)
	{
		if (i == n)
			return p;

		p = p->next;
		i++;
	}

	return NULL;
}

//���ң���������Ԫ�ز��ң���������Ԫ��Ϊch�Ľ�㲢����
dulinkList * ElemLocatebyVal(dulinkList *list, char ch)
{
	dulinkList *p = NULL;
	p = list->next;

	//����Ѱ��ch�Ľڵ㣬������
	while (p != NULL)
	{
		if (p->data == ch)
			return p;

		p = p->next;
	}

	return NULL;
}

//�����㣺������listλ��n������Ԫ��ch
void dulinkListInsert(dulinkList *list, int n, char ch)
{
	dulinkList *p = NULL;			//��n���ڵ�
	dulinkList *q = NULL;			//������Ľڵ�,���ڵ�n���ڵ�֮ǰ

	//���Ȳ��ҵ�n���ڵ�
	p = ElemLocatebyNum(list, n);
	if (p == NULL)
	{
		printf("Insert Error!\n");
		return ERROR;
	}

	//��ʼ����
	q = (dulinkList *)malloc(sizeof(dulinkList));
	q->data = ch;
	q->prior = p->prior;
	q->next = p;

	p->prior->next = q;
	p->prior = q;
}

//ɾ���ڵ㣺ɾ������listλ��n���Ľڵ�
void dulinkListDelete(dulinkList *list, int n)
{
	dulinkList *p = NULL;			//��n���ڵ�
	dulinkList *q = NULL;			//���ͷŵĽڵ�

	//���ҵ�n���ڵ�
	p = ElemLocatebyNum(list, n);
	q = p->prior;
	if (p == NULL || q == NULL)
	{
		printf("Delete Error!\n");
		return ERROR;
	}
	q->next = p->next;
	p->next->prior = q;
	free(p);
}

