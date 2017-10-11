/***************************************************
Description:Sqlist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/11
/***************************************************/

#include <stdio.h>
#include "string.h"
#include "sqlist.h"


//˳����ʼ������������Ԥ����С�����飬���������С֮�������������
Status InitSqlst(Sqlist * list)
{
	//ͨ��malloc����һ��˳���
	list->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (list->elem == NULL)
		exit(ERROR);

	//��ʼ��˳���
	list->length = 0;
	list->list_size = LIST_INIT_SIZE;

	return 0;
}

//˳�������
void Output_L(Sqlist *list)
{
	int i;
	for (i = 0; i < list->length; i++)
		printf("%d ", list->elem[i]);
}



//˳���Ĳ���
Status Insert_Sqlist(Sqlist *list, int loc, ElemType e)
{
	ElemType *newbase = NULL;
	ElemType *p, *q = NULL;

	//�����жϲ����λ���Ƿ���ȷ
	if (loc < 1 || loc > list->length + 1)
		return FALSE;

	//�жϲ��뵱ǰԪ�ش�ʱ���ٵĿռ��Ƿ�
	if (list->length >= list->list_size)
	{
		newbase = (ElemType *)realloc(list->elem, (list->list_size + LIST_INCREMENT_SIZE)*sizeof(ElemType));
		if (newbase == NULL)
			exit(ERROR);
		list->elem = newbase;
		list->list_size += LIST_INCREMENT_SIZE;
	}
		
	//����
	q = &(list->elem[loc - 1]);				//������Ҫ˵��һ�£�list->elem[loc - 1] == *(list->elem + (loc-1))
	for (p = &(list->elem[list->length - 1]); p >= q; p--)
		*(p + 1) = *p;
	
	//����
	*q = e;
	list->length++;

	return TRUE;
}

//˳����ɾ��
Status Delete_Sqlist(Sqlist *list, int loc, ElemType *e)
{
	ElemType *p, *q = NULL;
	
	//�����ж�ɾ����λ���Ƿ���ȷ
	if (loc < 1 || loc > list->length)
		return FALSE;

	//����ɾ��ֵ
	p = &(list->elem[list->length - 1]);		//���һ���ڵ��λ��
	q = &(list->elem[loc - 1]);					//ɾ���ڵ㵥��λ��
	*e = *q;

	//ǰ��
	for (q; q < p; q++)
		*q = *(q + 1);
	list->length--;

	return TRUE;
}

//˳�����Ԫ�صıȽ�
int LocateElem(Sqlist *list, ElemType e)
{
	int loc = 0;
	ElemType *p, *q = NULL;

	//��˳����и���Ԫ�ؽ��бȽ�
	p = list->elem;
	q = &(list->elem[list->length - 1]);
	for (p; p <= q; p++)
	{
		loc++;
		if (*p == e)
			return loc;
	}

	return 0;
}


//����˳���ĺϲ�,��������������
void Merge_list(Sqlist *list0, Sqlist *list1, Sqlist *list2)
{
	ElemType *p, *q, *k = NULL;
	ElemType *p_last, *q_last = NULL;

	//�����µĺϳɱ�
	k = list2->elem = (ElemType *)malloc((list0->length + list1->length)*sizeof(ElemType));
	if (list2->elem == NULL)
		exit(ERROR);
	list2->list_size = list0->length + list1->length;

	//�ϲ���Ԫ
	p = list0->elem;
	q = list1->elem;
	p_last = &(list0->elem[list0->length - 1]);
	q_last = &(list1->elem[list1->length - 1]);

	//��������list0,list1�ϲ���һ��
	while (p <= p_last && q <= q_last)
	{
		if (*p <= *q)
		{
			*k = *p;
			k++;
			p++;
		}
		else
		{
			*k = *q;
			k++;
			q++;
		}
	}

	//��ĳһ��list�������ʱ������һ��list���μ���ϳɱ���
	while (p <= p_last)
	{
		*k = *p;
		k++;
		p++;
	}

	while (q <= q_last)
	{
		*k = *q;
		k++;
		q++;
	}

	//�������ϲ���˳���Ĵ�С
	list2->length = k - list2->elem;
}