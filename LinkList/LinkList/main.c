#include <stdio.h>
#include "string.h"
#include "Linklist.h"

//���Ե�������������ܵ���ȷ��
void main()
{
	//����������֤
	linkList *list = NULL;
	linkList *list_head = NULL;
	linkList *check_list = NULL;
	linkList *free_list = NULL;
	int check_loc = 0;

	list_head = linkListCreate();
	list = list_head->next_node;
	printf("craete list/elment:");
	while (list != NULL)
	{
		printf("%c ", list->data);
		list = list->next_node;
	}

	printf("\n");
	//��֤���ҽڵ㣺�����
	check_list = ElemLocatebyNum(list_head, 4);
	if (check_list != NULL)
		printf("find node/positon 4 elment:%c", check_list->data);
	else
		printf("cannot find node\n");

	printf("\n");
	//��֤���ҽڵ㣺��Ԫ��
	check_list = ElemLocatebyVal(list_head, 'b', &check_loc);
	if (check_list != NULL)
		printf("find node/element b location is:%d", check_loc);
	else
		printf("cannot find node\n");

	printf("\n");
	//��֤����ڵ�
	linkListInsert(list_head, 4, 'Q');
	printf("insert Q list/elment:");
	list = list_head->next_node;
	while (list != NULL)
	{
		printf("%c ", list->data);
		list = list->next_node;
	}

	printf("\n");
	//��֤ɾ���ڵ�
	linkListDelete(list_head, 7);
	list = list_head->next_node;
	printf("delete location 7 list/elment:");
	while (list != NULL)
	{
		printf("%c ", list->data);
		list = list->next_node;
	}
	printf("\n");

	//�ͷ����еĽڵ�
	while (list_head != NULL)
	{
		free_list = list_head;
		list_head = list_head->next_node;
		free(free_list);
	}

	system("pause");
}