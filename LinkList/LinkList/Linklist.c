/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#include <stdio.h>
#include "string.h"
#include "Linklist.h"


//创建一个单向链表,输入n个元素的值
linkList *linkListCreate()
{
	char ch;	//输入节点元素临时变量
	linkList *p = NULL;
	linkList *p1 = NULL;
	linkList *p2 = NULL;

	//创建头指针的空链表
	p = (linkList *)malloc(sizeof(linkList));
	p->next_node = NULL;
	p->data = '\0';

	p1 = p;
	//输入元素完善整个单向链表
	while ((ch = getchar()) != '\n')
	{
		p2 = (linkList *)malloc(sizeof(linkList));
		p2->data = ch;
		p2->next_node = NULL;

		//更改链表
		p1->next_node = p2;
		p1 = p2;
	}

	return p;   //返回链表头指针
}


//查找节点：按序号查找，查找链表list中第n个节点。注：链表头的下一个节点才是第一个节点
linkList *ElemLocatebyNum(linkList *list, int n)
{
	int i = 0;
	linkList *search_p = NULL;

	//从头指针开始搜索对应的number节点，并返回节点，没有找到则返回null
	search_p = list;
	while (search_p != NULL)
	{
		i++;
		search_p = search_p->next_node;
		if (n == i)
			return search_p;
	}

	return NULL;
}


//查找节点：按数据元素查找，查找链表list中元素为ch的节点
linkList * ElemLocatebyVal(linkList *list, char ch,  int *loc)
{
	linkList *search_p = NULL;
	int i = 0;

	//从头指针开始搜索对应的number节点，并返回节点，没有找到则返回null
	search_p = list;
	while (search_p != NULL)
	{
		search_p = search_p->next_node;
		i++;
		if (search_p->data == ch)
		{
			*loc = i;
			return search_p;
		}
			
	}

	return NULL;
}

// 插入节点：在链表list的第n个节点处插入元素ch
void linkListInsert(linkList *list, int n, char ch)
{
	linkList *node_n_1 = NULL;
	linkList *node_n = NULL;

	//首先查找第n-1个节点
	node_n_1 = ElemLocatebyNum(list, n - 1);
	if (node_n_1 == NULL)
	{
		printf("insert Error!\n");
		return ERROR;
	}

	node_n = (linkList *)malloc(sizeof(linkList));
	node_n->data = ch;
	node_n->next_node = node_n_1->next_node;
	node_n_1->next_node = node_n;
}

//删除节点：删除链表list的第n个节点
void linkListDelete(linkList *list, int n)
{
	linkList *node_n_1 = NULL;
	linkList *node_n = NULL;

	//首先查找第n-1个节点
	node_n_1 = ElemLocatebyNum(list, n - 1);
	if (node_n_1 == NULL || node_n_1->next_node == NULL)
	{
		printf("delete Error!\n");
		return ERROR;
	}
	
	node_n = node_n_1->next_node;
	node_n_1->next_node = node_n->next_node;
	free(node_n);
}

