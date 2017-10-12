/***************************************************
Description:Slinklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"  
#include "string.h"
#include "Slinklist.h"

extern SLinkList space;			//space就是静态链表的地址，和h文件里面定义的相同的概念

//将一维数组space中各分量链成一个备用链表，(*space)[0].cur为头指针。
void InitSpace_SL()
{
	for (int i = 0; i<MAXSIZE - 1; i++)
		space[i].cur = i + 1;		//space[0  -- MAXSIZE - 1]为实际静态链表

	space[MAXSIZE - 1].cur = 0;		//space[MAXSIZE - 1]为实际静态链表
}

//初始化静态链表
Status InitList_SL(int *H)			
{
	*H = Malloc_SL();			//从备用链表上取一个节点到静态链表上
	if ((*H) == 0) 
		exit(OVERFLOW);
	space[*H].cur = 0;			//将取出的这个节点作为静态链表的首节点
	return OK;
}

 //判断备用空间是否为空
Status ListEmpty_SL(int H)     
{
	if (space[H].cur == 0)
		return TRUE;
	else
		return FALSE;
}

//若备用空间链表为非空，则取出一个备用节点给静态链表上
int Malloc_SL()
{
	int i = space[0].cur;
	if (i != 0)
		space[0].cur = space[i].cur;       //取出i指向的节点，每次从头结点指向的节点向后
	
	return i;
}

//从静态链表上将下标为k的空闲节点收到备用链表。
void Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}


//在静态单链线性表L中查找第1个值为e的元素。
//若找到，则返回它在L中的位序，否则返回0。
int LocateElem_SL(int H, ElemType e)
{
	int i = space[H].cur;
	int j = 1;
	while (i)
	{
		if (space[i].data == e) 
			return j;
		j++;
		i = space[i].cur;    //指向下一个节点
	}
	return FALSE;
}

//静态链表中插入节点
Status ListInsert_SL(int *H, int i, ElemType e)
{
	int j, k;
	k = 1;
	
	//首先判断插入的位置是否正确
	if (i<1 || (i > ListLength_SL(*H) + 1))					
		return FALSE;

	//遍历静态链表，找到i前面的节点
	j = *H;     
	while (k < i)
	{
		j = space[j].cur;
		k++;
	}

	//准备插入，首先从备用链表中取出一个空间节点
	k = Malloc_SL();
	space[k].data = e;

	//将备用节点的写一个指针指向插入的静态链表的位置
	space[k].cur = space[j].cur;
	space[j].cur = k;
	return OK;
}

//求静态链表的长度
int ListLength_SL(int H)
{
	int n = 0;
	int i = space[H].cur;
	while (i)
	{
		i = space[i].cur;
		n++;
	}
	return n;
}

//查看静态链表中第i个元素
Status ListTraverse_SL(int H, void(*visit)(int i))
{
	int j, k;
	j = space[H].cur;
	k = 0;
	while (k<ListLength_SL(H))
	{
		visit(j);
		j = space[j].cur;
		k++;
	}
	return OK;
}

//从静态链表取第i个数据，保存在e上
Status GetElem_SL(int H, int i, ElemType *e)
{
	int j, k;
	k = space[H].cur;
	j = 1;
	while (k&&j<i)
	{
		k = space[k].cur;
		j++;
	}
	if (!k || j>i) return ERROR;
	*e = space[k].data;
	return OK;
}

//取指定元素前一个节点的数据
Status PriorElem_SL(int H, ElemType cur_e, ElemType *e)//前驱
{
	int i;
	i = LocateElem_SL(H, cur_e);
	if (i <= 1) return FALSE;
	GetElem_SL(H, i - 1, e);
	return OK;
}

//取指定元素后一个节点的数据
Status NextElem_SL(int H, ElemType cur_e, ElemType *e)//后继
{
	int i, j;
	i = LocateElem_SL(H, cur_e);
	j = ListLength_SL(H);
	if (!i || i >= j) return FALSE;
	GetElem_SL(H, i + 1, e);
	return OK;
}

//将静态链表置空，即将所有静态链表的数据挂在备用空间上
Status ClearList_SL(int H)
{
	int j, k;
	j = space[H].cur;
	while (j)
	{
		k = space[j].cur;
		Free_SL(j);
		j = k;
	}
	space[H].cur = 0;
	return OK;
}

//释放备用空间的节点
Status DestroyList_SL(int *H)
{
	int i;
	i = *H;
	while (i)
	{
		i = space[*H].cur;
		Free_SL(*H);
		*H = i;
	}
	return OK;
}


//依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)的静态链表，S为其头指针。假设备用空间足够大，(*space)[0].cur为其头指针。
void difference(int *S)
{
	int r, m, n, i, j, b, k, p;
	InitSpace_SL();
	(*S) = Malloc_SL();
	r = *S;
	printf("▼请输入集合A的个数: ");
	scanf("%d", &m);
	for (j = 1; j <= m; j++)
	{
		i = Malloc_SL();
		printf("▼请输入集合A第%d个数: ", j);
		scanf("%d", &space[i].data);
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	printf("▼请输入集合B的个数: ");
	scanf("%d", &n);
	for (j = 1; j <= n; j++)
	{
		k = space[*S].cur;
		printf("▼请输入集合B第%d个数: ", j);
		scanf("%d", &b);
		p = *S;
		while (space[k].data != b&&k != space[r].cur)
		{
			p = k;
			k = space[k].cur;
		}
		if (k == space[r].cur)//若集合A中没有b，则插入。
		{
			i = Malloc_SL();
			space[i].data = b;
			space[r].cur = i;
			r = i;
			space[r].cur = 0;
		}
		else//若集合A中已有b，则删除。
		{
			space[p].cur = space[k].cur;
			Free_SL(k);
			if (k == r) r = p;
		}
	}
}















Status ListDelete_SL(int *H, int i, ElemType *e)//删除
{
	if (i<1 || i>ListLength_SL(*H)) return FALSE;
	int j, k;
	k = 1;
	j = *H;
	while (k<i)
	{
		j = space[j].cur;
		k++;
	}
	k = space[j].cur;
	space[j].cur = space[k].cur;
	*e = space[k].data;
	Free_SL(k);
	return OK;
}


