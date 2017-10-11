/***************************************************
Description:Sqlist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/11
/***************************************************/

#include <stdio.h>
#include "string.h"
#include "sqlist.h"


//顺序表初始化函数：分配预定大小的数组，超过数组大小之后进行容量扩充
Status InitSqlst(Sqlist * list)
{
	//通过malloc创建一个顺序表
	list->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (list->elem == NULL)
		exit(ERROR);

	//初始化顺序表
	list->length = 0;
	list->list_size = LIST_INIT_SIZE;

	return 0;
}

//顺序表的输出
void Output_L(Sqlist *list)
{
	int i;
	for (i = 0; i < list->length; i++)
		printf("%d ", list->elem[i]);
}



//顺序表的插入
Status Insert_Sqlist(Sqlist *list, int loc, ElemType e)
{
	ElemType *newbase = NULL;
	ElemType *p, *q = NULL;

	//首先判断插入的位置是否正确
	if (loc < 1 || loc > list->length + 1)
		return FALSE;

	//判断插入当前元素此时开辟的空间是否够
	if (list->length >= list->list_size)
	{
		newbase = (ElemType *)realloc(list->elem, (list->list_size + LIST_INCREMENT_SIZE)*sizeof(ElemType));
		if (newbase == NULL)
			exit(ERROR);
		list->elem = newbase;
		list->list_size += LIST_INCREMENT_SIZE;
	}
		
	//后移
	q = &(list->elem[loc - 1]);				//这里需要说明一下，list->elem[loc - 1] == *(list->elem + (loc-1))
	for (p = &(list->elem[list->length - 1]); p >= q; p--)
		*(p + 1) = *p;
	
	//插入
	*q = e;
	list->length++;

	return TRUE;
}

//顺序表的删减
Status Delete_Sqlist(Sqlist *list, int loc, ElemType *e)
{
	ElemType *p, *q = NULL;
	
	//首先判断删除的位置是否正确
	if (loc < 1 || loc > list->length)
		return FALSE;

	//返回删除值
	p = &(list->elem[list->length - 1]);		//最后一个节点的位置
	q = &(list->elem[loc - 1]);					//删除节点单的位置
	*e = *q;

	//前移
	for (q; q < p; q++)
		*q = *(q + 1);
	list->length--;

	return TRUE;
}

//顺序表中元素的比较
int LocateElem(Sqlist *list, ElemType e)
{
	int loc = 0;
	ElemType *p, *q = NULL;

	//与顺序表中各个元素进行比较
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


//两个顺序表的合并,并按照升序排列
void Merge_list(Sqlist *list0, Sqlist *list1, Sqlist *list2)
{
	ElemType *p, *q, *k = NULL;
	ElemType *p_last, *q_last = NULL;

	//创建新的合成表
	k = list2->elem = (ElemType *)malloc((list0->length + list1->length)*sizeof(ElemType));
	if (list2->elem == NULL)
		exit(ERROR);
	list2->list_size = list0->length + list1->length;

	//合并单元
	p = list0->elem;
	q = list1->elem;
	p_last = &(list0->elem[list0->length - 1]);
	q_last = &(list1->elem[list1->length - 1]);

	//按照升序将list0,list1合并在一起
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

	//当某一个list遍历完成时，将另一个list依次加入合成变中
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

	//设置最后合并的顺序表的大小
	list2->length = k - list2->elem;
}