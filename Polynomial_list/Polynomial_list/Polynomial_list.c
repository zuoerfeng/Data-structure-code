/***************************************************
Description:Polynomial_list
Author: Zuo Lu 		Version: 1.0	Date:2017/10/13
/***************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"
#include "Polynomial_list.h"


/*********************************线性链表的相关操作********************************/
Status MakeNode_E(Link *p, ElemType e)//
//分配由p指向的值为e的结点，并返回OK；
//若分配失败，则返回ERROE。
{
	(*p) = (Link)malloc(sizeof(LNode));
	if (!(*p)) exit(OVERFLOW);
	(**p).data = e;
	(**p).next = NULL;
	return OK;
}

void FreeNode_E(Link *p)//
//释放p所指的结点。
{
	free(*p);
	*p = NULL;
}

Status InitList_E(LinkList *L)//
//构造一个空的线性链表L。
{
	Link p;
	p = (Link)malloc(sizeof(LNode));
	if (!p) exit(OVERFLOW);
	(*p).next = NULL;
	(*L).head = (*L).tail = p;
	(*L).len = 0;
	return OK;
}

Status DestroyList_E(LinkList *L)//
//销毁线性链表L，L不再存在。
{
	Link p, q;
	p = (*L).head;
	while (p)
	{
		q = p;
		p = (*p).next;
		free(q);
	}
	(*L).head = (*L).tail = NULL;
	(*L).len = 0;
	return OK;
}


Status InsFirst_E(LinkList *L, Link h, Link s)//
//已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前。
{
	(*s).next = (*h).next;
	(*h).next = s;
	(*L).len++;
	if ((*L).tail == h) (*L).tail = s;
	return OK;
}

Status DelFirst_E(LinkList *L, Link h, Link *q)//
//已知h指向线性链表的头结点，删除链表中的第一个结点并以q返回。
{
	if (!((*h).next)) return ERROR;
	if (!(*(*h).next).next) (*L).tail = (*L).head;
	*q = (*h).next;
	(*h).next = (*(*h).next).next;
	(*L).len--;
	return OK;
}

Status Append_E(LinkList *L, Link s)//
//将指针s所指(彼此以指针相连)的一串结点链接在线性表L的最后一个结点
//之后，并改变链表L的尾指针指向新的尾结点。
{
	Link p, q = NULL;
	int count = 0;
	p = (*L).tail;
	(*p).next = s;
	while (s)
	{
		q = s;
		s = (*s).next;
		count++;
	}
	(*L).tail = q;
	(*L).len += count;
	return OK;
}



Status SetCurElem_E(Link *p, ElemType e)//
//已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值。
{
	if (!(*p)) return ERROR;
	(**p).data = e;
	return OK;
}

ElemType GetCurElem_E(Link p)//
//已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值。
{
	return (*p).data;
}

int ListLength_E(LinkList L)//
//返回线性链表L中元素的个数。
{
	return L.len;
}

Position GetHead_E(LinkList L)//
//返回线性链表L中头结点的位置。
{
	return L.head;
}


Position NextPos_E(LinkList L, Link p)//
//已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置，
//若无后继，则返回NULL。
{
	return (*p).next;
}

/*********************************线性链表的相关操作********************************/

/**********************************多项式的操作************************************/
void CreatPolyn(polynomial *P, int m)
//算法2.22：输入m项的系数和指数，建立表示一元多项式的有序链表。
{
	Position h;
	Link q;
	int i;
	ElemType e;

	//创建链表
	InitList_E(P);

	//找到头结点，并设置头结点初值
	h = GetHead_E(*P);
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem_E(&h, e);
	(*h).next = NULL;

	//增加链表结点，将输入的多项式用链表表示出来
	for (i = 1; i <= m; i++)
	{
		printf("▲请输入第%d组元素：", i);
		scanf("%f,%d", &(e.coef), &(e.expn));
		MakeNode_E(&q, e);
		InsFirst_E(P, h, q);
		h = (*h).next;
	}
}

void DestroyPolyn(polynomial *P)
//销毁一元多项式P
{
	DestroyList_E(P);
}

void PrintPolyn(polynomial P)
//打印输出一元多项式P
{
	int i;
	Link q;
	q = (*P.head).next;
	for (i = 1; i <= P.len; i++)
	{
		if (i == 1)
			printf("%g", (*q).data.coef);
		else
		{
			if ((*q).data.coef>0)
			{
				printf("+");
				printf("%g", (*q).data.coef);
			}
			else
			{
				printf("-");
				printf("%g", -(*q).data.coef);
			}
		}
		if ((*q).data.expn)
		{
			printf("X");
			if ((*q).data.expn != 1)
				printf("^%d", (*q).data.expn);
		}
		q = (*q).next;
	}
}

int PolyLength(polynomial P)
//返回一元多项式P中的项数
{
	return ListLength_E(P);
}

int cmp(term a, term b)
//依a的指数值<(或=)(或>)b的指数值，分别返回-1、0和+1。
{
	if (a.expn<b.expn) return -1;
	else if (a.expn == b.expn) return 0;
	else return 1;
}

void AddPolyn(polynomial *Pa, polynomial *Pb)
//算法2.23：多项式加法：Pa=Pa+Pb,利用两个多项式的结点构成“和多项式”
{
	term a, b;
	float sum;
	Position ha, hb, qa, qb;
	ha = GetHead_E(*Pa);
	hb = GetHead_E(*Pb);
	qa = NextPos_E(*Pa, ha);
	qb = NextPos_E(*Pb, hb);
	while (qa&&qb)
	{
		a = GetCurElem_E(qa);
		b = GetCurElem_E(qb);
		switch (cmp(a, b))
		{
		case -1:ha = qa; qa = NextPos_E(*Pa, ha); break;
		case 0:
			sum = a.coef + b.coef;
			if (sum != 0)
			{
				a.coef = sum;
				SetCurElem_E(&qa, a);
				ha = qa;
			}
			else
			{
				DelFirst_E(Pa, ha, &qa);
				FreeNode_E(&qa);
			}
			DelFirst_E(Pb, hb, &qb);
			FreeNode_E(&qb);
			qa = NextPos_E(*Pa, ha);
			qb = NextPos_E(*Pb, hb);
			break;
		case 1:
			DelFirst_E(Pb, hb, &qb);
			InsFirst_E(Pa, ha, qb);
			qb = NextPos_E(*Pb, hb);
			ha = NextPos_E(*Pa, ha);
			break;
		}
	}
	if (qb) Append_E(Pa, qb);
	FreeNode_E(&hb);
}

