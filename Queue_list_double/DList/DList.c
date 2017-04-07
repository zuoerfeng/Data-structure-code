#include"DList.h"  
#include<malloc.h>  
#include <stdio.h> 
/*����ֵΪi�Ľڵ㣬�����ؽڵ��ַ*/
Position MakeNode(Item i)
{
	PNode p = NULL;
	p = (PNode)malloc(sizeof(Node));
	if (p != NULL)
	{
		p->data = i;
		p->previous = NULL;
		p->next = NULL;
	}
	return p;
}
/*�ͷ�p��ָ�Ľڵ�*/
void FreeNode(PNode p)
{
	free(p);
}
/*����һ���յ�˫������*/
DList * InitList()
{
	DList *plist = (DList *)malloc(sizeof(DList));
	PNode head = MakeNode(0);
	if (plist != NULL)
	{
		if (head != NULL)
		{
			plist->head = head;
			plist->tail = head;
			plist->size = 0;
		}
		else
			return NULL;
	}
	return plist;
}

/*�ݻ�һ��˫������*/
void DestroyList(DList *plist)
{
	ClearList(plist);
	free(GetHead(plist));
	free(plist);
}

/*�ж������Ƿ�Ϊ�ձ�*/
int IsEmpty(DList *plist)
{
	if (GetSize(plist) == 0 && GetTail(plist) == GetHead(plist))
		return 1;
	else
		return 0;
}
/*��һ��������Ϊ�ձ��ͷ�ԭ����ڵ�ռ�*/
void ClearList(DList *plist)
{
	PNode temp, p;
	p = GetTail(plist);
	while (!IsEmpty(plist))
	{
		temp = GetPrevious(p);
		FreeNode(p);
		p = temp;
		plist->tail = temp;
		plist->size--;
	}
}

/*����ͷ�ڵ��ַ*/
Position GetHead(DList *plist)
{
	return plist->head;
}

/*����β�ڵ��ַ*/
Position GetTail(DList *plist)
{
	return plist->tail;
}

/*���������С*/
int GetSize(DList *plist)
{
	return plist->size;
}

/*����p��ֱ�Ӻ��λ��*/
Position GetNext(Position p)
{
	return p->next;
}

/*����p��ֱ��ǰ��λ��*/
Position GetPrevious(Position p)
{
	return p->previous;
}

/*��pnode��ָ�ڵ�����һ���ڵ�֮ǰ*/
PNode InsFirst(DList *plist, PNode pnode)
{
	Position head = GetHead(plist);

	if (IsEmpty(plist))
		plist->tail = pnode;
	plist->size++;

	pnode->next = head->next;
	pnode->previous = head;

	if (head->next != NULL)
		head->next->previous = pnode;
	head->next = pnode;

	return pnode;
}

/*�������һ���ڵ�ɾ��,���ظýڵ�ĵ�ַ*/
PNode DelFirst(DList *plist)
{
	Position head = GetHead(plist);
	Position p = head->next;
	if (p != NULL)
	{
		if (p == GetTail(plist))
			plist->tail = p->previous;
		head->next = p->next;
		head->next->previous = head;
		plist->size--;

	}
	return p;
}

/*��ýڵ��������*/
Item GetItem(Position p)
{
	return p->data;
}

/*���ýڵ��������*/
void SetItem(Position p, Item i)
{
	p->data = i;
}

/*ɾ�������е�β�ڵ㲢���ص�ַ���ı������βָ��ָ���µ�β�ڵ�*/
PNode Remove(DList *plist)
{
	Position p = NULL;
	if (IsEmpty(plist))
		return NULL;
	else
	{
		p = GetTail(plist);
		p->previous->next = p->next;
		plist->tail = p->previous;
		plist->size--;
		return p;
	}
}
/*��������pλ��֮ǰ�����½ڵ�s*/
PNode InsBefore(DList *plist, Position p, PNode s)
{
	s->previous = p->previous;
	s->next = p;
	p->previous->next = s;
	p->previous = s;

	plist->size++;
	return s;
}
/*��������pλ��֮������½ڵ�s*/
PNode InsAfter(DList *plist, Position p, PNode s)
{
	s->next = p->next;
	s->previous = p;

	if (p->next != NULL)
		p->next->previous = s;
	p->next = s;

	if (p = GetTail(plist))
		plist->tail = s;

	plist->size++;
	return s;
}

/*�����������е�i���ڵ��λ��*/
PNode LocatePos(DList *plist, int i)
{
	int cnt = 0;
	Position p = GetHead(plist);
	if (i>GetSize(plist) || i<1)
		return NULL;

	while (++cnt <= i)
	{
		p = p->next;
	}

	return p;
}

/*���ζ�������ÿ��Ԫ�ص��ú���visit()*/
void ListTraverse(DList *plist, void(*visit)())
{
	Position p = GetHead(plist);
	if (IsEmpty(plist))
		exit(0);
	else
	{

		while (p->next != NULL)
		{
			p = p->next;
			visit(p->data);
		}
	}
}