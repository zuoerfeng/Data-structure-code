/***************************************************
Description:HeapString
Author: Zuo Lu 		Version: 1.0	Date:2017/11/15
/***************************************************/

#define  TRUE           1  
#define  FALSE          0  
#define  OK             1  
#define  ERROR          0  
#define  INFEASIBLE    -1  
#define  OVERFLOW      -2 

//�Է������ͽ����ض���
typedef int Status;

//���崮�Ľṹ��
typedef struct
{
	char *ch;		//ָ��ѿռ䴮��ָ��
	int length;		//����ʵ�ʴ�С
}HString;

//��������
void InitString(HString *S);
Status StrAssign(HString *T, char *chars);
Status StrCopy(HString *T, HString S);
Status StrEmpty(HString S);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status ClearString(HString *S);
Status Concat(HString *T, HString S1, HString S2);
Status SubString(HString *Sub, HString S, int pos, int len);
Status Index(HString S, HString T, int pos);
Status Replace(HString *S, HString T, HString V);
Status StrInsert(HString *S, int pos, HString T);
Status StrDelete(HString *S, int pos, int len);
void StrPrint(HString S);