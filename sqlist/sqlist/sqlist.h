/***************************************************
Description:Sqlist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/11
/***************************************************/


#define TRUE 1
#define FALSE 0 
#define ERROR -1
#define INFEASIBLE -2

//�������Ա�Ĵ�С��Ҫ����Ĵ�С
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT_SIZE 10

//�Խڵ�洢���ͺͷ���ֵ���ͽ����ض���
typedef int ElemType;
typedef int Status;

//����˳���Ľڵ�����
typedef struct{
	ElemType *elem;			//˳���洢�Ļ�ַ
	int length;				//˳���ǰ�ĳ���
	int list_size;			//˳������洢�ռ�Ĵ�С����λ��ElemType��
}Sqlist;

//��������
Status InitSqlst(Sqlist * list);
Status Insert_Sqlist(Sqlist *list, int loc, ElemType e);
Status Delete_Sqlist(Sqlist *list, int loc, ElemType *e);
int LocateElem(Sqlist *list, ElemType e);
void Merge_list(Sqlist *list0, Sqlist *list1, Sqlist *list2);
void Output_L(Sqlist *list);