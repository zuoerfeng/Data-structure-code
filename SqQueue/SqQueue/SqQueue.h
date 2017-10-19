/***************************************************
Description:SqQueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

#define  MAXQSIZE 5		//Ԥ�ö��д�С

//�����ض���
typedef int Status;
typedef int QElemType;

//���н�㶨��
typedef struct Node
{
   QElemType *base; //��ʼ����̬����洢�ռ�
   int front;
   int rear;
} SqQueue;

//��������
Status InitQueue(SqQueue *Q);
Status EnQueue(SqQueue *Q, QElemType elem);
Status OutQueue(SqQueue *Q, QElemType *e);
Status PrintQueue(SqQueue Q);
