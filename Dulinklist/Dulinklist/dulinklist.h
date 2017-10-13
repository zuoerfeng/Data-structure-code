/***************************************************
Description:Dulinklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/13
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

//�Խڵ�洢���ͺͷ���ֵ���ͽ����ض���
typedef char ElemType;
typedef int Status;

//����˫������Ľṹ��
typedef struct link_node{
	ElemType data;
	struct link_node *prior;
	struct link_node *next;
}dulinkList;

//��������
dulinkList * dulinkListCreate();
dulinkList * ElemLocatebyNum(dulinkList *list, int n);
dulinkList * ElemLocatebyVal(dulinkList *list, char ch);
void dulinkListInsert(dulinkList *list, int n, char ch);
void dulinkListDelete(dulinkList *list, int n);

