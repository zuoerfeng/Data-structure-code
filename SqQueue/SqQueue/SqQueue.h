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

#define  MAXQSIZE 5		//预置队列大小

//变量重定义
typedef int Status;
typedef int QElemType;

//队列结点定义
typedef struct Node
{
   QElemType *base; //初始化动态分配存储空间
   int front;
   int rear;
} SqQueue;

//函数声明
Status InitQueue(SqQueue *Q);
Status EnQueue(SqQueue *Q, QElemType elem);
Status OutQueue(SqQueue *Q, QElemType *e);
Status PrintQueue(SqQueue Q);
