/***************************************************
Description:SqQueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "SqQueue.h"

//��ʼ������
Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

//�������
Status EnQueue(SqQueue *Q, QElemType elem)
{
	//����Ϊ��ʱ 1%100==1,������ʱ(99+1)%100==0,�������99��Ԫ��
	if ((Q->rear + 1) % MAXQSIZE == (Q->front))					//����ǰβָ�����һλ��ͷָ����ͬʱ�����ж�Ϊ����������֤��βָ����Զ����׷��ͷָ��
		return ERROR;

	Q->base[Q->rear] = elem;			//��β���룬��βָ��+1
	Q->rear = (Q->rear + 1) % MAXQSIZE; //rearʼ����0-100��ѭ��
	return OK;
}

//�˳�����
Status OutQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)			//������ָ�������ˣ���ʱ����Ϊ����Ϊ��
		return ERROR;

	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

//��ӡ����Ԫ��
Status PrintQueue(SqQueue Q)
{
	printf("the queue is:");
	for (int i = Q.front; i < Q.rear; ++i)
		printf("%d ", Q.base[i]);
	return OK;
}