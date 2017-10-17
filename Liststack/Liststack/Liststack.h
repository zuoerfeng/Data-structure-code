/***************************************************
Description:Liststack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

typedef int Status;

//定义栈的结构体
typedef struct node{
	char data;				//节点数据
	struct node *next;		//下一个节点
}Stack;

//函数声明
void StackInit(Stack *top);
Status IsEmpty(Stack *top);
Status Push(Stack *top, char element);
Status Pop(Stack *top, char *element);