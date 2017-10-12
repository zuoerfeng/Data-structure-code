#define _CRT_SECURE_NO_DEPRECATE
#include "string.h"
#include "stdlib.h"  
#include "Slinklist.h"

SLinkList space;			//������һ��ȫ�ֵľ�̬��������

void visit(int i)
{
	printf("%d ", space[i].data);
}

int main()
{
	int H, n, m, i;
	ElemType e;
	Status s;
	printf("��Function 1\n�ﺯ��InitSpace_SL()����...\n");
	printf("����ʼ����̬����ı��ÿռ�SPACE...\n\n");
	InitSpace_SL();

	printf("��Function 2\n�ﺯ��Malloc_SL()��InitList_SL(int *H)����...\n");
	printf("����ʼ����̬����H����Malloc_SL����ռ�...\n\n");
	InitList_SL(&H);    //H����ž�̬������׽ڵ�

	printf("��Function 3\n�ﺯ��ListEmpty_SL(int H)����...\n");
	s = ListEmpty_SL(H);
	if (s)
		printf("����HΪ�գ�����\n\n");
	else
		printf("����H�ǿգ�����\n\n");

	printf("��Function 4\n�ﺯ��ListInsert_SL(int *H,int i,ElemType e)����...\n");
	printf("��������׼����H����ĸ�����");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("��������La��%d������", i);
		scanf("%d", &m);
		s = ListInsert_SL(&H, i, m);    //����i����m���뵽������
		printf("������ɹ�?:%d   (1:�ɹ� 0:ʧ��)\n", s);
	}
	printf("\n");

	printf("��Function 5\n�ﺯ��ListTraverse_SL(int H,void (*visit)(int i))����...\n");
	printf("����H��Ԫ��Ϊ��H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	printf("��Function 6\n�ﺯ��ListLength_SL(int H)����...\n");
	printf("����H�ĳ���Ϊ��%d\n\n", ListLength_SL(H));

	printf("��Function 7\n�ﺯ��Free_SL(int k)��ListDelete_SL(int *H,int i,ElemType *e)����...\n");
	ListDelete_SL(&H, 3, &e);

	printf("��ɾ����H�ĵ�3��Ԫ��\"%d\",��Free_SL�ͷſռ�...\n", e);
	printf("����H��Ԫ��Ϊ��H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	printf("��Function 8\n�ﺯ��GetElem_SL(int H,int i,ElemType *e)����...\n");
	GetElem_SL(H, 3, &e);
	printf("����H�ĵ�3��Ԫ����\"%d\"\n\n", e);

	printf("��Function 9\n�ﺯ��LocateElem_SL(int H,ElemType e)����...\n");
	printf("��Ԫ��8��H�е�λ��\"%d\"\n\n", LocateElem_SL(H, 8));

	printf("��Function 10\n�ﺯ��PriorElem_SL(int H,ElemType cur_e,ElemType *e)����...\n");
	PriorElem_SL(H, 5, &e);
	printf("����HԪ��5��ǰ��Ϊ��%d\n\n", e);

	printf("��Function 11\n�ﺯ��NextElem_SL(int H,ElemType cur_e,ElemType *e)����...\n");
	NextElem_SL(H, 5, &e);
	printf("����HԪ��5�ĺ��Ϊ��%d\n\n", e);

	printf("��Function 12\n�ﺯ��ClearList_SL(int H)����...\n");
	printf("���ÿ�ǰ��");
	ListEmpty_SL(H) ? printf("��HΪ�գ�����\n") : printf("��H�ǿգ�����\n");
	ClearList_SL(H);
	printf("���ÿպ�");
	ListEmpty_SL(H) ? printf("��HΪ�գ�����\n\n") : printf("��H�ǿգ�����\n\n");

	printf("��Function 13\n�ﺯ��DestroyList_SL(int *H)����...\n");
	printf("������ǰ��");
	H ? printf("��H��  �ڣ�����\n") : printf("��H�����ڣ�����\n");
	DestroyList_SL(&H);
	printf("�����ٺ�");
	H ? printf("��H��  �ڣ�����\n\n") : printf("��H�����ڣ�����\n\n");

	printf("��Function 14\n�ﺯ��difference(int *S)����...\n");
	difference(&H);
	printf("����H��Ԫ��Ϊ��H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	system("pause");
}