#include <stdio.h>
#include "stdlib.h"
#include "dulinklist.h"

//����˫�������ܵ���ȷ��
void main()
{
	dulinkList *list = NULL;
	dulinkList *p = NULL;

	//����˫������Ľ���
	list = dulinkListCreate();
	p = list->next;
	if (p == NULL)
	{
		printf("no element\n");
		return ERROR;
	}
	printf("list elment:\n");
	while (p)
	{
		printf("%c ",p->data);
		p = p->next;
	}
	printf("\n");

	//����˫������Ĳ��ң���λ��
	p = ElemLocatebyNum(list, 5);
	printf("position 5 element is %c\n", p->data);

	//����˫������Ĳ��ң���Ԫ��
	p = ElemLocatebyVal(list, '5');
	printf("find data(5) element is %c\n", p->data);

	//���Բ����������ȷ��
	dulinkListInsert(list, 5, 'a');
	p = list->next;
	printf("After insert 'a' ,list elment:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");

	//����ɾ������
	dulinkListDelete(list, 5);
	p = list->next;
	printf("After delete 5 location, list elment:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");

	//�ͷŽڵ�
	while (list != NULL)
	{
		p = list;
		list = list->next;
		free(p);
	}

	system("pause");
}