#include <stdio.h>
#include "stdlib.h"
#include "dulinklist.h"

//测试双向链表功能的正确性
void main()
{
	dulinkList *list = NULL;
	dulinkList *p = NULL;

	//测试双向链表的建立
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

	//测试双向链表的查找，按位置
	p = ElemLocatebyNum(list, 5);
	printf("position 5 element is %c\n", p->data);

	//测试双向链表的查找，按元素
	p = ElemLocatebyVal(list, '5');
	printf("find data(5) element is %c\n", p->data);

	//测试插入操作的正确性
	dulinkListInsert(list, 5, 'a');
	p = list->next;
	printf("After insert 'a' ,list elment:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");

	//测试删除操作
	dulinkListDelete(list, 5);
	p = list->next;
	printf("After delete 5 location, list elment:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");

	//释放节点
	while (list != NULL)
	{
		p = list;
		list = list->next;
		free(p);
	}

	system("pause");
}