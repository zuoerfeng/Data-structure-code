/***************************************************
Description:Linkqueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Linkqueue.h"

//���г�ʼ��
void QueueInit(Qpointer *qp)
{
	Queue *que;
	que = (Queue*)malloc(sizeof(Queue));
	que->next = NULL;
	//���׺Ͷ�βָ��ͬһ���ڴ�ռ䣬ָ����ΪNULL
	qp->front = que;
	qp->rear = que;
}

//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
int IsEmpty(Qpointer *qp)
{
	//�жϷ���������ָ��Ͷ�βָ���Ƿ���ͬ
	if (qp->front == qp->rear)
	{
		return 1;
	}
	return 0;
}

//��������Ԫ��:����ɹ�����1��ʧ�ܷ���0
int QueuePush(Qpointer *qp, int element)
{
	Queue *que;

	//�����µĽڵ�
	que = (Queue*)malloc(sizeof(Queue));
	if (que == NULL)
		return 0;

	que->data = element;
	que->next = NULL;

	qp->rear->next = que;//���ڵ�������β
	qp->rear = que;//������βָ��
	return 0;
}

//ɾ������Ԫ�أ�ɾ���ɹ�����1��ʧ�ܷ���0
int QueuePop(Qpointer *qp, int *element)
{
	Queue *que;
	if (IsEmpty(qp))
	{
		return 0;
	}

	//�Ӷ�ͷ��ʼɾ����ע���ͷû������
	que = qp->front->next;//queָ�����ͷ������һ���ڵ㣬�������Ķ���
	*element = que->data;//��Ҫ�����е�Ԫ��
	qp->front->next = que->next;

	//�ж϶����Ƿ��ֻʣ��һ��Ԫ��
	if (qp->rear == que)
	{
		qp->rear = qp->front;		//��ɾ�����˶�β��ʱ��Ҫ�޸Ķ�β��ָ�뵽��ͷ
	}
	free(que);
	return 1;
}