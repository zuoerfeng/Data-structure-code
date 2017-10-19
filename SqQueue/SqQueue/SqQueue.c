/***************************************************
Description:SqQueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "SqQueue.h"

//初始化队列
Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

//插入队列
Status EnQueue(SqQueue *Q, QElemType elem)
{
	//队列为空时 1%100==1,队列满时(99+1)%100==0,最多容纳99个元素
	if ((Q->rear + 1) % MAXQSIZE == (Q->front))					//当当前尾指针的下一位与头指针相同时，则判断为满，这样保证了尾指针永远不会追上头指针
		return ERROR;

	Q->base[Q->rear] = elem;			//对尾插入，对尾指针+1
	Q->rear = (Q->rear + 1) % MAXQSIZE; //rear始终在0-100中循环
	return OK;
}

//退出队列
Status OutQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)			//当两个指针相遇了，此时定义为队列为空
		return ERROR;

	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

//打印队列元素
Status PrintQueue(SqQueue Q)
{
	printf("the queue is:");
	for (int i = Q.front; i < Q.rear; ++i)
		printf("%d ", Q.base[i]);
	return OK;
}