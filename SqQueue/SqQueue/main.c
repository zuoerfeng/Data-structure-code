#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "SqQueue.h"

int main()
{
	SqQueue queue;		//�������
	QElemType elem;
	int i;

	//��ʼ������
	InitQueue(&queue);

	//���ݲ������
	printf("input:\n");
	scanf("%d", &elem);
	while (elem>0)
	{
		if (EnQueue(&queue, elem) == ERROR)
			printf("The queue is full \n");
		scanf("%d", &elem);
	}

	//��֤�����Ƿ����
	printf("\n");
	PrintQueue(queue);

	/* ����Ҫ�����еĸ��� */
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