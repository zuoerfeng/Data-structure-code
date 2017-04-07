#include "Queue.h"

/*初始化链队*/
void initQueue(struct queue *hq)
{
   hq->front=hq->rear=NULL;        /*把队首和队尾指针置空*/
}

/*向链队中插入一个元素x*/
void inQueue(struct queue *hq, char *x)
{
   struct Node *newNode;   /*得到一个由newNode指针所指向的新结点*/
   newNode=malloc(sizeof(struct Node));
   if(newNode==NULL)
   {
      printf("内存空间分配失败！ ");
      exit(1);
   }
   strcpy(newNode->data,x); /*把x的值赋给新结点的值域*/
   newNode->next=NULL;    /*把新结点的指针域置空*/
   /*若链队为空，则新结点即是队首结点又是队尾结点*/
   if(hq->rear==NULL)
   {
      hq->front=hq->rear=newNode;
   }else
   {
      /*若链队非空，则依次修改队尾结点的指针域和队尾指针，使之指向新的队尾结点*/
     hq->rear=hq->rear->next=newNode;
   }
}

/*从队列中删除一个元素*/
char* delQueue(struct queue*hq)
{
    struct Node*p;
    char temp[16];
    /*若链队为空则停止运行*/
    if(hq->front==NULL)
    {
      printf("队列为空，无法删除！ ");
      //exit(1);
      return temp;
    }
    strcpy(temp,hq->front->data);
    /*暂存队首元素以便返回*/
    p=hq->front;
    /*暂存队首指针以便回收队尾结点*/
    hq->front=p->next;   /*使队首指针指向下一个结点*/
    /*若删除后链队为空，则需同时使队尾指针为空*/
    if(hq->front==NULL)
    {
       hq->rear=NULL;
    }
    free(p);      /*回收原队首结点*/
    return temp;    /*返回被删除的队首元素值*/
}

/*读取队首元素*/
int peekQueue(struct queue *hq)
{   /*若链队为空则停止运行*/
    if(hq->front==NULL)
    {
       printf("队列为空，无法读取！ ");
       //exit(1);
       return 0;
    }
    return hq->front->data;      /*返回队首元素*/
}

/*检查链队是否为空，若为空则返回1,否则返回0*/
int emptyQueue(struct queue *hq)
{
   /*判断队首或队尾任一个指针是否为空即可*/
   if(hq->front==NULL)
   {
      return 1;
   }else
   {
      return 0;
   }
}

/*清除链队中的所有元素*/
void clearQueue(struct queue *hq)
{
   struct Node *p=hq->front;    /*队首指针赋给p*/
   /*依次删除队列中的每一个结点，最后使队首指针为空*/
   while(p!=NULL)
   {
       hq->front=hq->front->next;
       free(p);
       p=hq->front;
   }
   /*循环结束后队首指针已经为空*/
   hq->rear=NULL;    /*置队尾指针为空*/
   return;
}

/*
int main(int argc,char *argv[])
{
    struct queue q;
    char *a="smart";
    char *b="state";
    char *c="sata";
    char *d="destory";
    char *f="format";
    int i;
    int flag;

    initQueue(&q);
    //进队
    inQueue(&q,a);
    inQueue(&q,b);
    inQueue(&q,c);
    inQueue(&q,d);
    inQueue(&q,f);
    printf("peeknode is %s\n",peekQueue(&q)); //读取队首元素smart
    //出队
    //printf("delnode is %s\n",delQueue(&q));     //出列去执行smart
    //while(1)
    //{
        flag = atoi(argv[1]);
        if(flag == 1)
        {
            delQueue(&q);
            printf("peeknode is %s\n",peekQueue(&q));
        }
    //}
    //printf("peeknode is %s\n",peekQueue(&q)); //读取队首元素state

    /*
    while(!emptyQueue(&q))
    {
        printf("delnode is %s\n",delQueue(&q));
    }
    clearQueue(&q);

}
*/
