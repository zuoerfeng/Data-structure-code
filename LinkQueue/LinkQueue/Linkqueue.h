/***************************************************
Description:Linkqueue
Author: Zuo Lu 		Version: 1.0	Date:2017/10/19
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

//������н��ṹ��
typedef struct node
{
	int data;
	struct node *next;
}Queue;

//������еĽṹ�壬��β�Ͷ�ͷָ��
typedef struct pointer{
    Queue *front;		//����ָ�룬����ָ�벻��Ŷ���Ԫ��
    Queue *rear;		//��βָ�룬��Ŷ�β������Ԫ��
 }Qpointer;

//��������
void QueueInit(Qpointer *qp);
int IsEmpty(Qpointer *qp);
int QueuePush(Qpointer *qp, int element);
int QueuePop(Qpointer *qp, int *element);
