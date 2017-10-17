/***************************************************
Description:Sqstack
Author: Zuo Lu 		Version: 1.0	Date:2017/10/17
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

#define STACK_INIT_SIZE 100		//顺序栈初始化的大小
#define STACKINCREMENT 10		//增量空间的大小

typedef   int Status;
typedef  int SElemType;

//对栈的结构体描述
typedef struct
{
	SElemType *base;		//栈底指针
	SElemType *top;			//栈顶指针
	int stacksize;			//当前栈的空间大小
}SqStack;

//函数声明
SqStack * InitStack();
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack *S);
int StackLength(SqStack *S);
Status GetTop(SqStack *S, SElemType *e);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
Status StackTraverse(SqStack *S, void(*visit)(SElemType *p));
void PrintElem(SElemType *p);
