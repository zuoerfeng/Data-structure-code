/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "dulinklist.h"

//创建双链表
dulinkList * dulinkListCreate()
{
	//定义两个临时变量
	dulinkList *list = NULL;
	dulinkList *p = NULL;
	dulinkList *q = NULL;
	char ch = '0';

	//首先创建首节点
	list = (dulinkList *)malloc(sizeof(dulinkList));
	list->data = '/0';
	list->prior = NULL;
	list->next = NULL;

	p = list;
	printf("input element:");
	//开始增加节点数
	while ((ch = getchar()) != '\n')
	{
		q = (dulinkList *)malloc(sizeof(dulinkList));
		q->data = ch;
		q->next = NULL;
		q->prior = p;

		//更改前后指针
		p->next = q;
		p = q;
	}

	//完成了双向链表的建立，返回首部指针
	return list;
}

//查找：根据位置查找节点，查找位置为n处的节点并返回
dulinkList * ElemLocatebyNum(dulinkList *list, int n)
{
	dulinkList *p = NULL;
	int i = 1;

	//首先取得第一节点的地址
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

//查找：根据数据元素查找，查找数据元素为ch的结点并返回
dulinkList * ElemLocatebyVal(dulinkList *list, char ch)
{
	dulinkList *p = NULL;
	p = list->next;

	//遍历寻找ch的节点，并返回
	while (p != NULL)
	{
		if (p->data == ch)
			return p;

		p = p->next;
	}

	return NULL;
}

//插入结点：在链表list位置n处插入元素ch
void dulinkListInsert(dulinkList *list, int n, char ch)
{
	dulinkList *p = NULL;			//第n个节点
	dulinkList *q = NULL;			//待插入的节点,插在第n个节点之前

	//首先查找第n个节点
	p = ElemLocatebyNum(list, n);
	if (p == NULL)
	{
		printf("Insert Error!\n");
		return ERROR;
	}

	//开始插入
	q = (dulinkList *)malloc(sizeof(dulinkList));
	q->data = ch;
	q->prior = p->prior;
	q->next = p;

	p->prior->next = q;
	p->prior = q;
}

//删除节点：删除链表list位置n处的节点
void dulinkListDelete(dulinkList *list, int n)
{
	dulinkList *p = NULL;			//第n个节点
	dulinkList *q = NULL;			//待释放的节点

	//查找第n个节点
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

