/***************************************************
Description:Slinklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"  
#include "string.h"
#include "Slinklist.h"

extern SLinkList space;			//space���Ǿ�̬����ĵ�ַ����h�ļ����涨�����ͬ�ĸ���

//��һά����space�и���������һ����������(*space)[0].curΪͷָ�롣
void InitSpace_SL()
{
	for (int i = 0; i<MAXSIZE - 1; i++)
		space[i].cur = i + 1;		//space[0  -- MAXSIZE - 1]Ϊʵ�ʾ�̬����

	space[MAXSIZE - 1].cur = 0;		//space[MAXSIZE - 1]Ϊʵ�ʾ�̬����
}

//��ʼ����̬����
Status InitList_SL(int *H)			
{
	*H = Malloc_SL();			//�ӱ���������ȡһ���ڵ㵽��̬������
	if ((*H) == 0) 
		exit(OVERFLOW);
	space[*H].cur = 0;			//��ȡ��������ڵ���Ϊ��̬������׽ڵ�
	return OK;
}

 //�жϱ��ÿռ��Ƿ�Ϊ��
Status ListEmpty_SL(int H)     
{
	if (space[H].cur == 0)
		return TRUE;
	else
		return FALSE;
}

//�����ÿռ�����Ϊ�ǿգ���ȡ��һ�����ýڵ����̬������
int Malloc_SL()
{
	int i = space[0].cur;
	if (i != 0)
		space[0].cur = space[i].cur;       //ȡ��iָ��Ľڵ㣬ÿ�δ�ͷ���ָ��Ľڵ����
	
	return i;
}

//�Ӿ�̬�����Ͻ��±�Ϊk�Ŀ��нڵ��յ���������
void Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}


//�ھ�̬�������Ա�L�в��ҵ�1��ֵΪe��Ԫ�ء�
//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
int LocateElem_SL(int H, ElemType e)
{
	int i = space[H].cur;
	int j = 1;
	while (i)
	{
		if (space[i].data == e) 
			return j;
		j++;
		i = space[i].cur;    //ָ����һ���ڵ�
	}
	return FALSE;
}

//��̬�����в���ڵ�
Status ListInsert_SL(int *H, int i, ElemType e)
{
	int j, k;
	k = 1;
	
	//�����жϲ����λ���Ƿ���ȷ
	if (i<1 || (i > ListLength_SL(*H) + 1))					
		return FALSE;

	//������̬�����ҵ�iǰ��Ľڵ�
	j = *H;     
	while (k < i)
	{
		j = space[j].cur;
		k++;
	}

	//׼�����룬���ȴӱ���������ȡ��һ���ռ�ڵ�
	k = Malloc_SL();
	space[k].data = e;

	//�����ýڵ��дһ��ָ��ָ�����ľ�̬�����λ��
	space[k].cur = space[j].cur;
	space[j].cur = k;
	return OK;
}

//��̬����ĳ���
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

//�鿴��̬�����е�i��Ԫ��
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

//�Ӿ�̬����ȡ��i�����ݣ�������e��
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

//ȡָ��Ԫ��ǰһ���ڵ������
Status PriorElem_SL(int H, ElemType cur_e, ElemType *e)//ǰ��
{
	int i;
	i = LocateElem_SL(H, cur_e);
	if (i <= 1) return FALSE;
	GetElem_SL(H, i - 1, e);
	return OK;
}

//ȡָ��Ԫ�غ�һ���ڵ������
Status NextElem_SL(int H, ElemType cur_e, ElemType *e)//���
{
	int i, j;
	i = LocateElem_SL(H, cur_e);
	j = ListLength_SL(H);
	if (!i || i >= j) return FALSE;
	GetElem_SL(H, i + 1, e);
	return OK;
}

//����̬�����ÿգ��������о�̬��������ݹ��ڱ��ÿռ���
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

//�ͷű��ÿռ�Ľڵ�
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


//�������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A)�ľ�̬����SΪ��ͷָ�롣���豸�ÿռ��㹻��(*space)[0].curΪ��ͷָ�롣
void difference(int *S)
{
	int r, m, n, i, j, b, k, p;
	InitSpace_SL();
	(*S) = Malloc_SL();
	r = *S;
	printf("�������뼯��A�ĸ���: ");
	scanf("%d", &m);
	for (j = 1; j <= m; j++)
	{
		i = Malloc_SL();
		printf("�������뼯��A��%d����: ", j);
		scanf("%d", &space[i].data);
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	printf("�������뼯��B�ĸ���: ");
	scanf("%d", &n);
	for (j = 1; j <= n; j++)
	{
		k = space[*S].cur;
		printf("�������뼯��B��%d����: ", j);
		scanf("%d", &b);
		p = *S;
		while (space[k].data != b&&k != space[r].cur)
		{
			p = k;
			k = space[k].cur;
		}
		if (k == space[r].cur)//������A��û��b������롣
		{
			i = Malloc_SL();
			space[i].data = b;
			space[r].cur = i;
			r = i;
			space[r].cur = 0;
		}
		else//������A������b����ɾ����
		{
			space[p].cur = space[k].cur;
			Free_SL(k);
			if (k == r) r = p;
		}
	}
}















Status ListDelete_SL(int *H, int i, ElemType *e)//ɾ��
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


