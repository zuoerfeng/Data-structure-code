#include <stdio.h>
#include "string.h"
#include "sqlist.h"

//���Ժ�����������֤�����Ӻ�������ȷ��
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
	//���Գ�ʼ��˳���
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
	
	//���˳���
	printf("Inition list1:");
	Output_L(list1);
	printf("\nInition list2:");
	Output_L(list2);
	printf("\n");

	//����˳���Ĳ��빦��
	Insert_Sqlist(list1, 11, insert_data);
	printf("After insert list1:");
	Output_L(list1);
	printf("\n");

	//����˳����ɾ������
	delete_data = (ElemType *)malloc(sizeof(ElemType));
	Delete_Sqlist(list2, 5, delete_data);
	printf("After delete list2:");
	Output_L(list2);
	printf(", delete data is %d", *delete_data);
	printf("\n");

	//����˳����Ԫ�رȽϹ���
	printf("compare location is %d\n", LocateElem(list1, compare_data1));
	printf("compare location is %d\n", LocateElem(list1, compare_data2));

	//��������˳���ĺϲ�����
	Merge_list(list1, list2, list3);
	printf("list3:");
	Output_L(list3);
	printf("\n");

	//������ɣ��ͷſ��ٵĿռ�
	free(list1->elem);
	free(list1);
	free(list2->elem);
	free(list2);

	system("pause");
}

//�ο�����;http://www.cnblogs.com/Romi/archive/2012/01/07/2315788.html