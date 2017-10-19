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

//定义队列结点结构体
typedef struct node
{
	int data;
	struct node *next;
}Queue;

//定义队列的结构体，对尾和队头指针
typedef struct pointer{
    Queue *front;		//队首指针，对首指针不存放队列元素
    Queue *rear;		//队尾指针，存放队尾的数据元素
 }Qpointer;

//函数声明
void QueueInit(Qpointer *qp);
int IsEmpty(Qpointer *qp);
int QueuePush(Qpointer *qp, int element);
int QueuePop(Qpointer *qp, int *element);
