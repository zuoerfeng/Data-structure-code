/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#define TRUE 1
#define FALSE 0 
#define ERROR -1
#define INFEASIBLE -2

//�Խڵ�洢���ͺͷ���ֵ���ͽ����ض���
typedef char ElemType;
typedef int Status;

//���嵥������Ľṹ
typedef struct link_node
{
	ElemType data;					//�ڵ�Ԫ��
	struct link_node * next_node;			//ָ����һ�ڵ��ָ��
}linkList;          //typedef���ṹ��struct linknode�ض����Ϊ��link_node�������


//��������
linkList *linkListCreate();
linkList *ElemLocatebyNum(linkList *list, int n);
linkList * ElemLocatebyVal(linkList *list, char ch);
void linkListInsert(linkList *list, int n, char ch);
void linkListDelete(linkList *list, int n);