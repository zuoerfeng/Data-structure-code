#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Linkqueue.h"

int main()
{
	Qpointer *qp;
	int x;

	//��ʼ������
	qp = (Qpointer*)malloc(sizeof(Qpointer));			//��������
	QueueInit(qp);
	printf("input positive integers:\n");

	scanf("%d", &x);
	while (x>0)
	{
		QueuePush(qp, x);
		scanf("%d", &x);
	}

	//������У�����->��β
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

	//ɾ������
	printf("delete queue:\n");
	while (QueuePop(qp, &x))
	{
		printf("%d ", x);
	}
	printf("\n");
	//�ͷ��ڴ�ռ�
	p = qp->front;
	free(p);
	free(qp);

	system("pause");
	return 0;
}