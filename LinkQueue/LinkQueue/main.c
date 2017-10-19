#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Linkqueue.h"

int main()
{
	Qpointer *qp;
	int x;

	//初始化队列
	qp = (Qpointer*)malloc(sizeof(Qpointer));			//创建队列
	QueueInit(qp);
	printf("input positive integers:\n");

	scanf("%d", &x);
	while (x>0)
	{
		QueuePush(qp, x);
		scanf("%d", &x);
	}

	//输出队列：队首->队尾
	Queue *p = qp->front->next;
	if (p == NULL)
		return 0;
	printf("queue element:\n");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	//删除队列
	printf("delete queue:\n");
	while (QueuePop(qp, &x))
	{
		printf("%d ", x);
	}
	printf("\n");
	//释放内存空间
	p = qp->front;
	free(p);
	free(qp);

	system("pause");
	return 0;
}