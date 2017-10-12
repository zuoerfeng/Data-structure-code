/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#include <stdio.h>
#include "string.h"
#include "Linklist.h"


//����һ����������,����n��Ԫ�ص�ֵ
linkList *linkListCreate()
{
	char ch;	//����ڵ�Ԫ����ʱ����
	linkList *p = NULL;
	linkList *p1 = NULL;
	linkList *p2 = NULL;

	//����ͷָ��Ŀ�����
	p = (linkList *)malloc(sizeof(linkList));
	p->next_node = NULL;
	p->data = '\0';

	p1 = p;
	//����Ԫ������������������
	while ((ch = getchar()) != '\n')
	{
		p2 = (linkList *)malloc(sizeof(linkList));
		p2->data = ch;
		p2->next_node = NULL;

		//��������
		p1->next_node = p2;
		p1 = p2;
	}

	return p;   //��������ͷָ��
}


//���ҽڵ㣺����Ų��ң���������list�е�n���ڵ㡣ע������ͷ����һ���ڵ���ǵ�һ���ڵ�
linkList *ElemLocatebyNum(linkList *list, int n)
{
	int i = 0;
	linkList *search_p = NULL;

	//��ͷָ�뿪ʼ������Ӧ��number�ڵ㣬�����ؽڵ㣬û���ҵ��򷵻�null
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


//���ҽڵ㣺������Ԫ�ز��ң���������list��Ԫ��Ϊch�Ľڵ�
linkList * ElemLocatebyVal(linkList *list, char ch,  int *loc)
{
	linkList *search_p = NULL;
	int i = 0;

	//��ͷָ�뿪ʼ������Ӧ��number�ڵ㣬�����ؽڵ㣬û���ҵ��򷵻�null
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

// ����ڵ㣺������list�ĵ�n���ڵ㴦����Ԫ��ch
void linkListInsert(linkList *list, int n, char ch)
{
	linkList *node_n_1 = NULL;
	linkList *node_n = NULL;

	//���Ȳ��ҵ�n-1���ڵ�
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

//ɾ���ڵ㣺ɾ������list�ĵ�n���ڵ�
void linkListDelete(linkList *list, int n)
{
	linkList *node_n_1 = NULL;
	linkList *node_n = NULL;

	//���Ȳ��ҵ�n-1���ڵ�
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

