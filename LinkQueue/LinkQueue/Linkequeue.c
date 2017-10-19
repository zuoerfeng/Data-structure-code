/***************************************************
Description:Linkqueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "malloc.h"
#include "Linkqueue.h"

//队列初始化
void QueueInit(Qpointer *qp)
{
	Queue *que;
	que = (Queue*)malloc(sizeof(Queue));
	que->next = NULL;
	//队首和队尾指向同一个内存空间，指针域为NULL
	qp->front = que;
	qp->rear = que;
}

//判断队列是否为空：为空返回1，不为空返回0
int IsEmpty(Qpointer *qp)
{
	//判断方法：对手指针和队尾指针是否相同
	if (qp->front == qp->rear)
	{
		return 1;
	}
	return 0;
}

//插入数据元素:插入成功返回1，失败返回0
int QueuePush(Qpointer *qp, int element)
{
	Queue *que;

	//创建新的节点
	que = (Queue*)malloc(sizeof(Queue));
	if (que == NULL)
		return 0;

	que->data = element;
	que->next = NULL;

	qp->rear->next = que;//将节点插入队列尾
	qp->rear = que;//调整队尾指针
	return 0;
}

//删除数据元素：删除成功返回1，失败返回0
int QueuePop(Qpointer *qp, int *element)
{
	Queue *que;
	if (IsEmpty(qp))
	{
		return 0;
	}

	//从队头开始删除，注意队头没有数据
	que = qp->front->next;//que指向队列头结点的下一个节点，即真正的队首
	*element = que->data;//将要出队列的元素
	qp->front->next = que->next;

	//判断队列是否就只剩下一个元素
	if (qp->rear == que)
	{
		qp->rear = qp->front;		//当删除到了队尾的时候，要修改对尾的指针到队头
	}
	free(que);
	return 1;
}