/***************************************************
Description:Linklist
Author: Zuo Lu 		Version: 1.0	Date:2017/10/12
/***************************************************/

#define TRUE 1
#define FALSE 0 
#define ERROR -1
#define INFEASIBLE -2

//对节点存储类型和返回值类型进行重定义
typedef char ElemType;
typedef int Status;

//定义单向链表的结构
typedef struct link_node
{
	ElemType data;					//节点元素
	struct link_node * next_node;			//指向下一节点的指针
}linkList;          //typedef将结构体struct linknode重定义成为了link_node这个类型


//函数声明
linkList *linkListCreate();
linkList *ElemLocatebyNum(linkList *list, int n);
linkList * ElemLocatebyVal(linkList *list, char ch);
void linkListInsert(linkList *list, int n, char ch);
void linkListDelete(linkList *list, int n);