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
		
	//创建首节点,栈顶
	top = (Stack*)malloc(sizeof(Stack));//栈顶
	StackInit(top);//栈初始化
	

	//进栈函数测试
	printf("input some positive integers:\n");
	while ((ch = getchar()) != '\n')
		Push(top, ch);//进栈

	//输出栈中元素(从栈顶开始)
	p = top->next;
	printf("elemet in stack:\n");
	while (p)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	p = NULL;
	printf("\n");


	//出栈，输出出栈元素
	printf("Pop stack element:\n");
	while (Pop(top, &ch))
	{
		printf("%c ", ch);
	}

	printf("\n");
	//注：出栈时已经释放掉了栈中的内存空间
	free(top);

	system("pause");
}