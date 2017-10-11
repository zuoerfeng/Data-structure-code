/***************************************************
Description:Sqlist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/11
/***************************************************/


#define TRUE 1
#define FALSE 0 
#define ERROR -1
#define INFEASIBLE -2

//定义线性表的大小和要扩大的大小
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT_SIZE 10

//对节点存储类型和返回值类型进行重定义
typedef int ElemType;
typedef int Status;

//构造顺序表的节点内容
typedef struct{
	ElemType *elem;			//顺序表存储的基址
	int length;				//顺序表当前的长度
	int list_size;			//顺序表分配存储空间的大小，单位（ElemType）
}Sqlist;

//函数声明
Status InitSqlst(Sqlist * list);
Status Insert_Sqlist(Sqlist *list, int loc, ElemType e);
Status Delete_Sqlist(Sqlist *list, int loc, ElemType *e);
int LocateElem(Sqlist *list, ElemType e);
void Merge_list(Sqlist *list0, Sqlist *list1, Sqlist *list2);
void Output_L(Sqlist *list);