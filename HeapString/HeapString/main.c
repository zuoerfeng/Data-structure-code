#include <stdio.h>
#include "stdlib.h"
#include "HeapString.h"

//功能模块的测试
int main()
{
	char *chars = "abcdefg";			//定义三种不同的字符串
	char *t = "***";
	char *v = "^^^^";
	HString S, Tmp, T, V, Sub;
	int i;


	printf("Function 1\n★函数void InitString(HString *S)测试...\n");
	printf("▲初始化空串Tmp...\n\n");
	InitString(&Tmp);
	InitString(&T);
	InitString(&S);
	InitString(&V);
	InitString(&Sub);


	printf("Function 2\n★函数Status StrAssign(HString *T,char *chars)测试...\n");
	printf("▲为Tmp赋值%s...\n\n", chars);
	StrAssign(&Tmp, chars);			   //赋值字符串


	printf("Function 3\n★函数Status StrEmpty(HString S)测试...\n");
	StrEmpty(Tmp) ? printf("▲Tmp空串！！！\n\n", chars) : printf("▲Tmp非空！！！\n\n");			//判断字符串是不是为空串


	printf("Function 4\n★函数int StrLength(HString S)测试...\n");
	i = StrLength(Tmp);
	printf("▲Tmp的长度为:%d\n\n", i);		//计算字符串的长度


	printf("Function 5\n★函数void StrPrint(HString S)测试...\n");
	printf("▲Tmp=\"");
	StrPrint(Tmp);							//打印出当前的字符串
	printf("\"\n\n");


	printf("Function 6\n★函数Status StrCopy(HString *T,HString S)测试...\n");
	printf("▲复制Tmp到S...\n");
	StrCopy(&S, Tmp);
	printf("▲S=\"");						//赋值字符串到另一个字符串上
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 7\n★函数int StrCompare(HString S,HString T)测试...\n");
	printf("▲比较字符串Tmp、S: ");
	i = StrCompare(Tmp, S);					//比较字符串，是不是相等
	i == 0 ? printf("Tmp=S\n\n") : (i<0 ? printf("Tmp<S\n\n") : printf("Tmp>S\n\n"));


	printf("Function 8\n★函数Status StrInsert(HString *S,int pos,HString T)测试...\n");
	printf("▲将\"***\"赋给T...\n");
	StrAssign(&T, t);
	printf("▲在S的第5个字符前插入T...\n");
	StrInsert(&S, 5, T);					//插入字符串
	printf("▲S=\"");
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 9\n★函数Status Index(HString S,HString T,int pos)测试...\n");
	printf("▲获取\"***\"在S中从第1个字符算起的第一次出现的位置...\n");
	i = Index(S, T, 1);						//计算字符串出现的位置
	printf("▲\"***\"在S中从第1个字符算起的第一次出现的位置为:%d\n\n", i);


	printf("Function 10\n★函数Status SubString(HString *Sub,HString S,int pos,int len)测试...\n");
	printf("▲用Sub返回S中第5个字符起的3个字符...\n");
	SubString(&Sub, S, 5, 3);				//查找子字符串
	printf("▲Sub=\"");
	StrPrint(Sub);
	printf("\"\n\n");


	printf("Function 11\n★函数Status Replace(HString *S,HString T,HString V)测试...\n");
	printf("▲将\"^^^^\"赋给V...\n");
	StrAssign(&V, v);
	printf("▲用\"^^^^\"替换S中的\"***\"...\n");
	Replace(&S, T, V);						//字符串替换
	printf("▲S=\"");
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 12\n★函数Status StrDelete(HString *S,int pos,int len)测试...\n");
	printf("▲删除S第5个字符起的4个字符...\n");
	StrDelete(&S, 5, 4);
	printf("▲S=\"");						//字符串的删除
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 13\n★函数Status ClearString(HString *S)测试...\n");
	printf("▲清空S前：");
	StrEmpty(S) ? printf("▲S空串!!!\n") : printf("▲S非空!!!\n");
	ClearString(&S);						//清空字符串
	printf("▲清空S后：");
	StrEmpty(S) ? printf("▲S空串!!!\n\n") : printf("▲S非空!!!\n\n");


	printf("Function 14\n★函数Status Concat(HString *T,HString S1,HString S2)测试...\n");
	printf("▲链接T和V形成Tmp...\n");
	Concat(&Tmp, T, V);						//合并字符串
	printf("▲Tmp=\"");
	StrPrint(Tmp);
	printf("\"\n\n");

	system("pause");
}