/***************************************************
Description:Slinklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2  
#define  MAXSIZE 100			//定义静态链表的大小

//对节点存储类型和返回值类型进行重定义
typedef char ElemType;
typedef int Status;

//定义静态链表的结构
typedef struct{
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];    
//将结构体类型重定义为component，以及重定义了MAXSIZE个component类型的结构体，为SLinkList，等同于typedef component SLinkList[MAXSIZE]；  注意typedef下来的一定是类型，而不是变量


//函数声明
void InitSpace_SL();
int Malloc_SL();
void Free_SL(int k);
void difference(int *S);
int LocateElem_SL(int H, ElemType e);
Status InitList_SL(int *H);
Status ClearList_SL(int H);
Status DestroyList_SL(int *H);
Status ListEmpty_SL(int H);
int ListLength_SL(int H);
Status GetElem_SL(int H, int i, ElemType *e);
Status PriorElem_SL(int H, ElemType cur_e, ElemType *e);
Status NextElem_SL(int H, ElemType cur_e, ElemType *e);
Status ListInsert_SL(int *H, int i, ElemType e);
Status ListDelete_SL(int *H, int i, ElemType *e);
Status ListTraverse_SL(int H, void(*visit)(int i));
void visit(int i);