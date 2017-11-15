#include <stdio.h>
#include "stdlib.h"
#include "HeapString.h"

//����ģ��Ĳ���
int main()
{
	char *chars = "abcdefg";			//�������ֲ�ͬ���ַ���
	char *t = "***";
	char *v = "^^^^";
	HString S, Tmp, T, V, Sub;
	int i;


	printf("Function 1\n�ﺯ��void InitString(HString *S)����...\n");
	printf("����ʼ���մ�Tmp...\n\n");
	InitString(&Tmp);
	InitString(&T);
	InitString(&S);
	InitString(&V);
	InitString(&Sub);


	printf("Function 2\n�ﺯ��Status StrAssign(HString *T,char *chars)����...\n");
	printf("��ΪTmp��ֵ%s...\n\n", chars);
	StrAssign(&Tmp, chars);			   //��ֵ�ַ���


	printf("Function 3\n�ﺯ��Status StrEmpty(HString S)����...\n");
	StrEmpty(Tmp) ? printf("��Tmp�մ�������\n\n", chars) : printf("��Tmp�ǿգ�����\n\n");			//�ж��ַ����ǲ���Ϊ�մ�


	printf("Function 4\n�ﺯ��int StrLength(HString S)����...\n");
	i = StrLength(Tmp);
	printf("��Tmp�ĳ���Ϊ:%d\n\n", i);		//�����ַ����ĳ���


	printf("Function 5\n�ﺯ��void StrPrint(HString S)����...\n");
	printf("��Tmp=\"");
	StrPrint(Tmp);							//��ӡ����ǰ���ַ���
	printf("\"\n\n");


	printf("Function 6\n�ﺯ��Status StrCopy(HString *T,HString S)����...\n");
	printf("������Tmp��S...\n");
	StrCopy(&S, Tmp);
	printf("��S=\"");						//��ֵ�ַ�������һ���ַ�����
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 7\n�ﺯ��int StrCompare(HString S,HString T)����...\n");
	printf("���Ƚ��ַ���Tmp��S: ");
	i = StrCompare(Tmp, S);					//�Ƚ��ַ������ǲ������
	i == 0 ? printf("Tmp=S\n\n") : (i<0 ? printf("Tmp<S\n\n") : printf("Tmp>S\n\n"));


	printf("Function 8\n�ﺯ��Status StrInsert(HString *S,int pos,HString T)����...\n");
	printf("����\"***\"����T...\n");
	StrAssign(&T, t);
	printf("����S�ĵ�5���ַ�ǰ����T...\n");
	StrInsert(&S, 5, T);					//�����ַ���
	printf("��S=\"");
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 9\n�ﺯ��Status Index(HString S,HString T,int pos)����...\n");
	printf("����ȡ\"***\"��S�дӵ�1���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
	i = Index(S, T, 1);						//�����ַ������ֵ�λ��
	printf("��\"***\"��S�дӵ�1���ַ�����ĵ�һ�γ��ֵ�λ��Ϊ:%d\n\n", i);


	printf("Function 10\n�ﺯ��Status SubString(HString *Sub,HString S,int pos,int len)����...\n");
	printf("����Sub����S�е�5���ַ����3���ַ�...\n");
	SubString(&Sub, S, 5, 3);				//�������ַ���
	printf("��Sub=\"");
	StrPrint(Sub);
	printf("\"\n\n");


	printf("Function 11\n�ﺯ��Status Replace(HString *S,HString T,HString V)����...\n");
	printf("����\"^^^^\"����V...\n");
	StrAssign(&V, v);
	printf("����\"^^^^\"�滻S�е�\"***\"...\n");
	Replace(&S, T, V);						//�ַ����滻
	printf("��S=\"");
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 12\n�ﺯ��Status StrDelete(HString *S,int pos,int len)����...\n");
	printf("��ɾ��S��5���ַ����4���ַ�...\n");
	StrDelete(&S, 5, 4);
	printf("��S=\"");						//�ַ�����ɾ��
	StrPrint(S);
	printf("\"\n\n");


	printf("Function 13\n�ﺯ��Status ClearString(HString *S)����...\n");
	printf("�����Sǰ��");
	StrEmpty(S) ? printf("��S�մ�!!!\n") : printf("��S�ǿ�!!!\n");
	ClearString(&S);						//����ַ���
	printf("�����S��");
	StrEmpty(S) ? printf("��S�մ�!!!\n\n") : printf("��S�ǿ�!!!\n\n");


	printf("Function 14\n�ﺯ��Status Concat(HString *T,HString S1,HString S2)����...\n");
	printf("������T��V�γ�Tmp...\n");
	Concat(&Tmp, T, V);						//�ϲ��ַ���
	printf("��Tmp=\"");
	StrPrint(Tmp);
	printf("\"\n\n");

	system("pause");
}