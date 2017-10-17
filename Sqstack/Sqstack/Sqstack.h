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

#define STACK_INIT_SIZE 100		//˳��ջ��ʼ���Ĵ�С
#define STACKINCREMENT 10		//�����ռ�Ĵ�С

typedef   int Status;
typedef  int SElemType;

//��ջ�Ľṹ������
typedef struct
{
	SElemType *base;		//ջ��ָ��
	SElemType *top;			//ջ��ָ��
	int stacksize;			//��ǰջ�Ŀռ��С
}SqStack;

//��������
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
