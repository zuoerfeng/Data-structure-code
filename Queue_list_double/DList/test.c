#include"DList.h"
#include <stdio.h>
void print(Item i)
{
	printf("������Ϊ%d \n", i);
}

main()
{
	DList *plist = NULL;
	PNode p = NULL;
    PNode a = NULL;


	plist = InitList();
	p = InsFirst(plist, MakeNode(2));
	InsBefore(plist, p, MakeNode(5));
	InsAfter(plist, p, MakeNode(3));

	printf("pǰ��λ�õ�ֵΪ%d\n", GetItem(GetPrevious(p)));
	printf("pλ�õ�ֵΪ%d\n", GetItem(p));
	printf("p���λ�õ�ֵΪ%d\n", GetItem(GetNext(p)));

	a = LocatePos(plist,3);
	InsBefore(plist, a, MakeNode(1));

	printf("����������ڵ�������:\n");
	ListTraverse(plist, print);
	printf("����ͷ�ڵ��������%d���ڵ�\n", GetSize(plist));
	FreeNode(DelFirst(plist));
	printf("ɾ����һ���ڵ�����±������Ϊ:\n");
	ListTraverse(plist, print);
	printf("����ͷ�ڵ��������%d���ڵ�\n", GetSize(plist));
	DestroyList(plist);
	printf("�����ѱ�����\n");
}





