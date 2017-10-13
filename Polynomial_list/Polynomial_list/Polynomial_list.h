/***************************************************
Description:Polynomial_list
Author: Zuo Lu 		Version: 1.0	Date:2017/10/13
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

typedef int Status;
//定义多项式的结构
typedef struct
{
	float coef;			//系数
	int   expn;			//指数
}term, ElemType;


typedef struct LNode//结点类型  
{
	ElemType data;
	struct LNode *next;
}LNode, *Link, *Position;


typedef struct//链表类型  
{
	Link head, tail;
	int len;
}LinkList;

//函数声明
typedef LinkList polynomial;
Status MakeNode_E(Link *p, ElemType e);
void FreeNode_E(Link *p);
Status InitList_E(LinkList *L);
Status DestroyList_E(LinkList *L);
Status InsFirst_E(LinkList *L, Link h, Link s);
Status DelFirst_E(LinkList *L, Link h, Link *q);
Status Append_E(LinkList *L, Link s);
Status SetCurElem_E(Link *p, ElemType e);
ElemType GetCurElem_E(Link p);
int ListLength_E(LinkList L);
Position GetHead_E(LinkList L);
Position NextPos_E(LinkList L, Link p);

void CreatPolyn(polynomial *P, int m);
void DestroyPolyn(polynomial *P);
void PrintPolyn(polynomial P);
int PolyLength(polynomial P);
void AddPolyn(polynomial *Pa, polynomial *Pb);
int cmp(term a, term b);