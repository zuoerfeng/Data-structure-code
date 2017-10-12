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
#define  MAXSIZE 100			//���徲̬����Ĵ�С

//�Խڵ�洢���ͺͷ���ֵ���ͽ����ض���
typedef char ElemType;
typedef int Status;

//���徲̬����Ľṹ
typedef struct{
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];    
//���ṹ�������ض���Ϊcomponent���Լ��ض�����MAXSIZE��component���͵Ľṹ�壬ΪSLinkList����ͬ��typedef component SLinkList[MAXSIZE]��  ע��typedef������һ�������ͣ������Ǳ���


//��������
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