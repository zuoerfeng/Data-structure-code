/***************************************************
Description:Polynomial_list
Author: Zuo Lu 		Version: 1.0	Date:2017/10/13
/***************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"
#include "Polynomial_list.h"


/*********************************�����������ز���********************************/
Status MakeNode_E(Link *p, ElemType e)//
//������pָ���ֵΪe�Ľ�㣬������OK��
//������ʧ�ܣ��򷵻�ERROE��
{
	(*p) = (Link)malloc(sizeof(LNode));
	if (!(*p)) exit(OVERFLOW);
	(**p).data = e;
	(**p).next = NULL;
	return OK;
}

void FreeNode_E(Link *p)//
//�ͷ�p��ָ�Ľ�㡣
{
	free(*p);
	*p = NULL;
}

Status InitList_E(LinkList *L)//
//����һ���յ���������L��
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
//������������L��L���ٴ��ڡ�
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
//��֪hָ�����������ͷ���,��s��ָ�������ڵ�һ�����֮ǰ��
{
	(*s).next = (*h).next;
	(*h).next = s;
	(*L).len++;
	if ((*L).tail == h) (*L).tail = s;
	return OK;
}

Status DelFirst_E(LinkList *L, Link h, Link *q)//
//��֪hָ�����������ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء�
{
	if (!((*h).next)) return ERROR;
	if (!(*(*h).next).next) (*L).tail = (*L).head;
	*q = (*h).next;
	(*h).next = (*(*h).next).next;
	(*L).len--;
	return OK;
}

Status Append_E(LinkList *L, Link s)//
//��ָ��s��ָ(�˴���ָ������)��һ��������������Ա�L�����һ�����
//֮�󣬲��ı�����L��βָ��ָ���µ�β��㡣
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
//��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ��
{
	if (!(*p)) return ERROR;
	(**p).data = e;
	return OK;
}

ElemType GetCurElem_E(Link p)//
//��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ��
{
	return (*p).data;
}

int ListLength_E(LinkList L)//
//������������L��Ԫ�صĸ�����
{
	return L.len;
}

Position GetHead_E(LinkList L)//
//������������L��ͷ����λ�á�
{
	return L.head;
}


Position NextPos_E(LinkList L, Link p)//
//��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�ã�
//���޺�̣��򷵻�NULL��
{
	return (*p).next;
}

/*********************************�����������ز���********************************/

/**********************************����ʽ�Ĳ���************************************/
void CreatPolyn(polynomial *P, int m)
//�㷨2.22������m���ϵ����ָ����������ʾһԪ����ʽ����������
{
	Position h;
	Link q;
	int i;
	ElemType e;

	//��������
	InitList_E(P);

	//�ҵ�ͷ��㣬������ͷ����ֵ
	h = GetHead_E(*P);
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem_E(&h, e);
	(*h).next = NULL;

	//���������㣬������Ķ���ʽ�������ʾ����
	for (i = 1; i <= m; i++)
	{
		printf("���������%d��Ԫ�أ�", i);
		scanf("%f,%d", &(e.coef), &(e.expn));
		MakeNode_E(&q, e);
		InsFirst_E(P, h, q);
		h = (*h).next;
	}
}

void DestroyPolyn(polynomial *P)
//����һԪ����ʽP
{
	DestroyList_E(P);
}

void PrintPolyn(polynomial P)
//��ӡ���һԪ����ʽP
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
//����һԪ����ʽP�е�����
{
	return ListLength_E(P);
}

int cmp(term a, term b)
//��a��ָ��ֵ<(��=)(��>)b��ָ��ֵ���ֱ𷵻�-1��0��+1��
{
	if (a.expn<b.expn) return -1;
	else if (a.expn == b.expn) return 0;
	else return 1;
}

void AddPolyn(polynomial *Pa, polynomial *Pb)
//�㷨2.23������ʽ�ӷ���Pa=Pa+Pb,������������ʽ�Ľ�㹹�ɡ��Ͷ���ʽ��
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

