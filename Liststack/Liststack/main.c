#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Liststack.h"


void main()
{
	char ch;
	Stack *top = NULL;	
	Stack *p = NULL;
		
	//�����׽ڵ�,ջ��
	top = (Stack*)malloc(sizeof(Stack));//ջ��
	StackInit(top);//ջ��ʼ��
	

	//��ջ��������
	printf("input some positive integers:\n");
	while ((ch = getchar()) != '\n')
		Push(top, ch);//��ջ

	//���ջ��Ԫ��(��ջ����ʼ)
	p = top->next;
	printf("elemet in stack:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	p = NULL;
	printf("\n");


	//��ջ�������ջԪ��
	printf("Pop stack element:\n");
	while (Pop(top, &ch))
	{
		printf("%c ", ch);
	}

	printf("\n");
	//ע����ջʱ�Ѿ��ͷŵ���ջ�е��ڴ�ռ�
	free(top);

	system("pause");
}