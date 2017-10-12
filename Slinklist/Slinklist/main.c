#define _CRT_SECURE_NO_DEPRECATE
#include "string.h"
#include "stdlib.h"  
#include "Slinklist.h"

SLinkList space;			//定义了一个全局的静态链表数组

void visit(int i)
{
	printf("%d ", space[i].data);
}

int main()
{
	int H, n, m, i;
	ElemType e;
	Status s;
	printf("▼Function 1\n★函数InitSpace_SL()测试...\n");
	printf("▲初始化静态链表的备用空间SPACE...\n\n");
	InitSpace_SL();

	printf("▼Function 2\n★函数Malloc_SL()、InitList_SL(int *H)测试...\n");
	printf("▲初始化静态链表H，用Malloc_SL申请空间...\n\n");
	InitList_SL(&H);    //H存放着静态链表的首节点

	printf("▼Function 3\n★函数ListEmpty_SL(int H)测试...\n");
	s = ListEmpty_SL(H);
	if (s)
		printf("▲表H为空！！！\n\n");
	else
		printf("▲表H非空！！！\n\n");

	printf("▼Function 4\n★函数ListInsert_SL(int *H,int i,ElemType e)测试...\n");
	printf("▲请输入准备向H输入的个数：");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("▲请输入La第%d个数：", i);
		scanf("%d", &m);
		s = ListInsert_SL(&H, i, m);    //将第i个数m插入到链表中
		printf("▲插入成功?:%d   (1:成功 0:失败)\n", s);
	}
	printf("\n");

	printf("▼Function 5\n★函数ListTraverse_SL(int H,void (*visit)(int i))测试...\n");
	printf("▲表H的元素为：H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	printf("▼Function 6\n★函数ListLength_SL(int H)测试...\n");
	printf("▲表H的长度为：%d\n\n", ListLength_SL(H));

	printf("▼Function 7\n★函数Free_SL(int k)、ListDelete_SL(int *H,int i,ElemType *e)测试...\n");
	ListDelete_SL(&H, 3, &e);

	printf("▲删除表H的第3个元素\"%d\",用Free_SL释放空间...\n", e);
	printf("▲表H的元素为：H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	printf("▼Function 8\n★函数GetElem_SL(int H,int i,ElemType *e)测试...\n");
	GetElem_SL(H, 3, &e);
	printf("▲表H的第3个元素是\"%d\"\n\n", e);

	printf("▼Function 9\n★函数LocateElem_SL(int H,ElemType e)测试...\n");
	printf("▲元素8在H中的位序：\"%d\"\n\n", LocateElem_SL(H, 8));

	printf("▼Function 10\n★函数PriorElem_SL(int H,ElemType cur_e,ElemType *e)测试...\n");
	PriorElem_SL(H, 5, &e);
	printf("▲表H元素5的前驱为：%d\n\n", e);

	printf("▼Function 11\n★函数NextElem_SL(int H,ElemType cur_e,ElemType *e)测试...\n");
	NextElem_SL(H, 5, &e);
	printf("▲表H元素5的后继为：%d\n\n", e);

	printf("▼Function 12\n★函数ClearList_SL(int H)测试...\n");
	printf("▲置空前：");
	ListEmpty_SL(H) ? printf("表H为空！！！\n") : printf("表H非空！！！\n");
	ClearList_SL(H);
	printf("▲置空后：");
	ListEmpty_SL(H) ? printf("表H为空！！！\n\n") : printf("表H非空！！！\n\n");

	printf("▼Function 13\n★函数DestroyList_SL(int *H)测试...\n");
	printf("▲销毁前：");
	H ? printf("表H存  在！！！\n") : printf("表H不存在！！！\n");
	DestroyList_SL(&H);
	printf("▲销毁后：");
	H ? printf("表H存  在！！！\n\n") : printf("表H不存在！！！\n\n");

	printf("▼Function 14\n★函数difference(int *S)测试...\n");
	difference(&H);
	printf("▲表H的元素为：H={");
	ListTraverse_SL(H, visit);
	printf("}\n\n");

	system("pause");
}