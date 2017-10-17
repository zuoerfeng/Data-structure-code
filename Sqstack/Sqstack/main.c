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

	//���Ƚ���һ��ջ�Ľṹ��

	printf("Function 1\n�ﺯ��Status InitStack(SqStack *S)����...\n");
	S = InitStack();
	if (S)
		s = 1;
	else
		s = 0;
	printf("����ʼ��˳��ջS: %d (0:ʧ�� 1:�ɹ�)\n\n", s);

	printf("Function 2\n�ﺯ��StackEmpty(SqStack S)����...\n");
	s = StackEmpty(S);
	printf("��S�Ƿ�Ϊ��ջ: %d   (0:�� 1:��)\n\n", s);

	printf("Function 3\n�ﺯ��Push(SqStack *S,SElemType e)����...\n");
	printf("��������׼����S��ջ�ĸ�����");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("��������La��%d������", i);
		scanf("%d", &m);
		s = Push(S, m);
		printf("����ջ�ɹ�?:%d   (1:�ɹ� 0:ʧ��)\n", s);
	}
	printf("\n");

	printf("Function 4\n�ﺯ��StackTraverse(SqStack S,void (*visit)(SElemType *p))����...\n");
	printf("��ջS�е�Ԫ��Ϊ��S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 5\n�ﺯ��Pop(SqStack *S,SElemType *e)����...\n");
	Pop(S, &m);
	printf("��Sջ��Ԫ��\"%d\"��ջ...\n", m);
	printf("��ջS�е�Ԫ��Ϊ��S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 5\n�ﺯ��Pop(SqStack *S,SElemType *e)����...\n");
	Pop(S, &m);
	printf("��Sջ��Ԫ��\"%d\"��ջ...\n", m);
	printf("��ջS�е�Ԫ��Ϊ��S={");
	StackTraverse(S, PrintElem);
	printf("}\n\n");

	printf("Function 6\n�ﺯ��StackLength(SqStack S)����...\n");
	n = StackLength(S);
	printf("��ջS�ĳ���Ϊ��%d\n\n", n);

	printf("Function 7\n�ﺯ��GetTop(SqStack S,SElemType *e)����...\n");
	GetTop(S, &m);
	printf("��S��ջ��Ԫ��Ϊ��%d\n\n", m);

	printf("Function 8\n�ﺯ��ClearStack(SqStack *S)����...\n");
	printf("��ջS�ÿ�ǰ :");
	StackEmpty(S) ? printf("�� ջ��\n") : printf("�� �գ�\n");
	ClearStack(S);
	printf("��ջS�ÿ�ǰ :");
	StackEmpty(S) ? printf("�� ջ��\n\n") : printf("�� �գ�\n\n");

	printf("Function 9\n�ﺯ��DestroyStack(SqStack *S)����...\n");
	printf("��ջS����ǰ :");
	S->base ? printf("��  �ڣ�\n") : printf("�����ڣ�\n");
	DestroyStack(S);
	printf("��ջS����ǰ :");
	S->base ? printf("��  �ڣ�\n") : printf("�����ڣ�\n");

	system("pause");
}