#ifndef DList_H  
#define DList_H  
typedef  int Item;
typedef struct Node * PNode;
typedef PNode Position;
/*����ڵ�����*/
typedef struct Node
{
	Item data;      /*������*/
	PNode previous; /*ָ��ǰ��*/
	PNode next;     /*ָ����*/
}Node;
/*������������*/
typedef struct
{
	PNode head;     /*ָ��ͷ�ڵ�*/
	PNode tail;     /*ָ��β�ڵ�*/
	int size;
}DList;

/*����ֵΪi�Ľڵ㣬�����ؽڵ��ַ*/
Position MakeNode(Item i);

/*�ͷ�p��ָ�Ľڵ�*/
void FreeNode(PNode p);

/*����һ���յ�˫������*/
DList* InitList();

/*�ݻ�һ��˫������*/
void DestroyList(DList *plist);

/*��һ��������Ϊ�ձ��ͷ�ԭ����ڵ�ռ�*/
void ClearList(DList *plist);

/*����ͷ�ڵ��ַ*/
Position GetHead(DList *plist);

/*����β�ڵ��ַ*/
Position GetTail(DList *plist);

/*���������С*/
int GetSize(DList *plist);

/*����p��ֱ�Ӻ��λ��*/
Position GetNext(Position p);

/*����p��ֱ��ǰ��λ��*/
Position GetPrevious(Position p);

/*��pnode��ָ�ڵ�����һ���ڵ�֮ǰ*/
PNode InsFirst(DList *plist, PNode pnode);

/*�������һ���ڵ�ɾ�����������ַ*/
PNode DelFirst(DList *plist);

/*��ýڵ��������*/
Item GetItem(Position p);

/*���ýڵ��������*/
void SetItem(Position p, Item i);

/*ɾ�������е�β�ڵ㲢�������ַ���ı������βָ��ָ���µ�β�ڵ�*/
PNode Remove(DList *plist);

/*��������pλ��֮ǰ�����½ڵ�S*/
PNode InsBefore(DList *plist, Position p, PNode s);

/*��������pλ��֮������½ڵ�s*/
PNode InsAfter(DList *plist, Position p, PNode s);

/*�����������е�i���ڵ��λ��*/
PNode LocatePos(DList *plist, int i);

/*���ζ�������ÿ��Ԫ�ص��ú���visit()*/
void ListTraverse(DList *plist, void(*visit)());
#endif  