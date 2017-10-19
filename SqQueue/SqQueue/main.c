#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "SqQueue.h"

int main()
{
	SqQueue queue;		//定义队列
	QElemType elem;
	int i;

	//初始化队列
	InitQueue(&queue);

	//数据插入队列
	printf("input:\n");
	scanf("%d", &elem);
	while (elem>0)
	{
		if (EnQueue(&queue, elem) == ERROR)
			printf("The queue is full \n");
		scanf("%d", &elem);
	}

	//验证队列是否插入
	printf("\n");
	PrintQueue(queue);

	/* 输入要出队列的个数 */
	printf("\noutput:");
	scanf("%d", &i);
	while (i != 0)
	{
		if(OutQueue(&queue, &elem) == ERROR)
			printf("The queue is empty\n");
		i--;
	}
	PrintQueue(queue);
	printf("\n");
	system("pause");
	return OK;
}