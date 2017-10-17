#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"
#include "Sqstack.h"


void PrintElem(SElemType *p)
{
	printf("%d ", *p);
}

int main()
{
	Status s;
	int i, n;
	SElemType m;
	SqStack *S = NULL;

	//首先建立一个栈的结构体

	printf("Function 1\n★函数Status InitStack(SqStack *S)测试...\n");
	S = InitStack();
	if (S)
		s = 1;
	else
		s = 0;
	printf("▲初始化顺序栈S: %d (0:失败 1:成功)\n\n", s);

	printf("Function 2\n★函数StackEmpty(SqStack S)测试...\n");
	s = StackEmpty(S);
	printf("▲S是否为空栈: %d   (0:否 1:是)\n\n", s);

	printf("Function 3\n★函数Push(SqStack *S,SElemType e)测试...\n");
	printf("▲请输入准备向S入栈的个数：");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("▲请输入La第%d个数：", i);
		scanf("%d", &m);
		s = Push(S, m);
		printf("▲入栈成功?:%d   (1:成功 0:失败)\n", s);
	}
	printf("\n");

	printf("Function 4\n★函数StackTraverse(SqStack S,void (*visit)(SElemType *p))测试...\n");
	printf("▲栈S中的元素为：S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 5\n★函数Pop(SqStack *S,SElemType *e)测试...\n");
	Pop(S, &m);
	printf("▲S栈顶元素\"%d\"出栈...\n", m);
	printf("▲栈S中的元素为：S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 5\n★函数Pop(SqStack *S,SElemType *e)测试...\n");
	Pop(S, &m);
	printf("▲S栈顶元素\"%d\"出栈...\n", m);
	printf("▲栈S中的元素为：S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 6\n★函数StackLength(SqStack S)测试...\n");
	n = StackLength(S);
	printf("▲栈S的长度为：%d\n\n", n);

	printf("Function 7\n★函数GetTop(SqStack S,SElemType *e)测试...\n");
	GetTop(S, &m);
	printf("▲S的栈顶元素为：%d\n\n", m);

	printf("Function 8\n★函数ClearStack(SqStack *S)测试...\n");
	printf("▲栈S置空前 :");
	StackEmpty(S) ? printf("空 栈！\n") : printf("非 空！\n");
	ClearStack(S);
	printf("▲栈S置空前 :");
	StackEmpty(S) ? printf("空 栈！\n\n") : printf("非 空！\n\n");

	printf("Function 9\n★函数DestroyStack(SqStack *S)测试...\n");
	printf("▲栈S销毁前 :");
	S->base ? printf("存  在！\n") : printf("不存在！\n");
	DestroyStack(S);
	printf("▲栈S销毁前 :");
	S->base ? printf("存  在！\n") : printf("不存在！\n");

	system("pause");
}