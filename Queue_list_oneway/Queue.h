#include<stdio.h>
#include<stdlib.h>

//定义链表节点数据结构
struct Node
{
    char data[16];                /*值域*/
    struct Node *next;       /*链接指针*/
};

struct queue
{
   struct Node *front;    /*队首指针*/
   struct Node *rear;    /*队尾指针*/
};

//队列函数声明
void initQueue(struct queue *hq);
void inQueue(struct queue *hq, char *x);
char* delQueue(struct queue*hq);
int peekQueue(struct queue *hq);
int emptyQueue(struct queue *hq);
void clearQueue(struct queue *hq);

