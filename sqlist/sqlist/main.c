#include <stdio.h>
#include "string.h"
#include "sqlist.h"

//测试函数，用来验证各个子函数的正确性
void main()
{
	Sqlist *list1 = NULL;
	Sqlist *list2 = NULL;
	Sqlist *list3 = NULL;
	int i = 0;

	ElemType insert_data = 10;
	ElemType *delete_data = NULL;
	ElemType compare_data1 = 1, compare_data2 = 21;

	/************************************************************/
	//测试初始化顺序表
	list1 = (Sqlist *)malloc(sizeof(Sqlist));
	list2 = (Sqlist *)malloc(sizeof(Sqlist));
	list3 = (Sqlist *)malloc(sizeof(Sqlist));
	InitSqlst(list1);
	InitSqlst(list2);
	list1->length = 10;
	list2->length = 10;
	for (i = 0; i < list1->length; i++)
	{
		list1->elem[i] = i;
		list2->elem[i] = i + 10;
	}
	
	//输出顺序表
	printf("Inition list1:");
	Output_L(list1);
	printf("\nInition list2:");
	Output_L(list2);
	printf("\n");

	//测试顺序表的插入功能
	Insert_Sqlist(list1, 11, insert_data);
	printf("After insert list1:");
	Output_L(list1);
	printf("\n");

	//测试顺序表的删除功能
	delete_data = (ElemType *)malloc(sizeof(ElemType));
	Delete_Sqlist(list2, 5, delete_data);
	printf("After delete list2:");
	Output_L(list2);
	printf(", delete data is %d", *delete_data);
	printf("\n");

	//测试顺序表的元素比较功能
	printf("compare location is %d\n", LocateElem(list1, compare_data1));
	printf("compare location is %d\n", LocateElem(list1, compare_data2));

	//测试两个顺序表的合并功能
	Merge_list(list1, list2, list3);
	printf("list3:");
	Output_L(list3);
	printf("\n");

	//测试完成，释放开辟的空间
	free(list1->elem);
	free(list1);
	free(list2->elem);
	free(list2);

	system("pause");
}

//参考博客;http://www.cnblogs.com/Romi/archive/2012/01/07/2315788.html