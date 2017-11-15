/***************************************************
Description:HeapString
Author: Zuo Lu 		Version: 1.0	Date:2017/11/15
/***************************************************/

#include <stdio.h>
#include "stdlib.h"
#include "HeapString.h"

//��ʼ��SΪ�մ�
void InitString(HString *S)
{
	S->ch = NULL;
	S->length = 0;
}

//����һ����ֵ���ڴ�����chars�Ĵ�T
Status StrAssign(HString *T, char *chars)
{
	int i;

	//���Ƚ���T֮ǰ�ĵ�ַ�ͷŵ�
	if (!(T->ch))
		free(T->ch);

	//�жϳ����Ĵ�С
	i = strlen(chars);
	if (!i)
	{
		T->ch = NULL;
		T->length = 0;
	}
	else			//���ٳ�����С�Ŀռ䣬���ڴ�Ŵ�
	{
		T->ch = (char *)malloc(i*sizeof(char));
		if (!(T->ch))
			exit(OVERFLOW);
		T->length = i;
		for (i = 0; i < T->length; i++)
		{
			T->ch[i] = chars[i];
		}
	}
	return OK;
}

Status StrCopy(HString *T, HString S)
//�ɴ�S���Ƶ�T
{
	int i;
	//�����ͷ�֮ǰ�ĵ�ַ�ռ�
	if (T->ch)
		free(T->ch);

	T->length = S.length;
	
	if (!(T->ch = (char *)malloc((T->length)*sizeof(char))))
		exit(OVERFLOW);
	
	for (i = 0; i < T->length; i++)
		T->ch[i] = S.ch[i];
	return OK;
}

Status StrEmpty(HString S)
//��SΪ�մ����򷵻�TRUE�����򷵻�FALSE
{
	if (!S.length)
		return TRUE;
	else
		return FALSE;
}

int StrLength(HString S)
//����S��Ԫ�ظ�������Ϊ���ĳ���
{
	return S.length;
}

int StrCompare(HString S, HString T)
//��S>T,�򷵻�ֵ>0;��S=T���򷵻�ֵ=0����S<T,�򷵻�ֵ<0
{
	int i;
	for (i = 0; i<S.length&&i<T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

Status ClearString(HString *S)
//��S���
{
	if (S->ch)
	{
		free(S->ch);
		S->ch = NULL;
	}
	S->length = 0;
	return OK;
}

Status Concat(HString *T, HString S1, HString S2)
//��T������S1��S2���Ӷ��ɵ��´�
{
	int i;
	if (!(T->ch))
		free(T->ch);
	T->length = S1.length + S2.length;
	T->ch = (char*)malloc((T->length)*sizeof(char));
	if (!(T->ch))
		exit(OVERFLOW);
	for (i = 0; i < T->length; i++)
	{
		if (i<S1.length)
			T->ch[i] = S1.ch[i];
		else
			T->ch[i] = S2.ch[i - S1.length];
	}
	return OK;
}

Status SubString(HString *Sub, HString S, int pos, int len)
//��Sub���ش��ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
//���У�1<=pos<=StrLength(S)��0<=len<=StrLength(S)-pos+1
{
	int i;
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	if (Sub->ch)
	{
		free(Sub->ch);
	}
	if (!len)
	{
		Sub->length = 0;
		Sub->ch = NULL;
	}
	else
	{
		Sub->ch = (char *)malloc(len*sizeof(char));
		if (!(Sub->ch))
			exit(OVERFLOW);
		Sub->length = len;
		for (i = 0; i < Sub->length; i++, pos++)
			Sub->ch[i] = S.ch[pos - 1];
	}
	return OK;
}

Status Index(HString S, HString T, int pos)
//�㷨4.1:������S�д��ںʹ�Tֵ��ͬ���Ӵ����򷵻���������S�е�pos���ַ�֮��ĵ�һ�γ��ֵ�λ�ã�����������0
{
	int m, n, i;
	HString Sub;
	InitString(&Sub);
	if (pos>0)
	{
		n = S.length;
		m = T.length;
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(&Sub, S, i, m);
			if (StrCompare(Sub, T) != 0)
				++i;
			else
				return i;
		}
	}
	return 0;
}

Status Replace(HString *S, HString T, HString V)
//��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
{
	int i, j;
	if (!Index(*S, T, 1) || StrEmpty(T))
		return ERROR;
	for (i = 1; i <= S->length; i++)
	{
		if (j = Index(*S, T, i))
		{
			StrDelete(S, j, T.length);
			StrInsert(S, j, V);
			i = j + V.length - 1;
		}
	}
	return OK;
}

Status StrInsert(HString *S, int pos, HString T)
//�ڴ��ĵ�pos���ַ�֮ǰ���봮T
{
	int i;
	if (pos<1 || pos> S->length)
		return ERROR;
	S->length += T.length;
	S->ch = (char*)realloc(S->ch, S->length*sizeof(char));
	if (!S->ch)
		exit(OVERFLOW);
	for (i = S->length - 1; i >= pos + T.length - 1; i--)
		S->ch[i] = S->ch[i - T.length];
	for (i = 0; i<T.length; i++)
		S->ch[pos + i - 1] = T.ch[i];
	return OK;
}

Status StrDelete(HString *S, int pos, int len)
//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
{
	int i;
	if (pos<1 || pos + len> S->length + 1 || len<0)
		return ERROR;
	S->length -= len;
	for (i = 0; pos - 1 + i < S->length; i++)
		S->ch[pos - 1 + i] = S->ch[pos + len - 1 + i];
	return OK;
}

void StrPrint(HString S)
{
	if (StrEmpty(S))
		printf("���մ�������\n");
	else
	{
		int i;
		for (i = 0; i<S.length; i++)
		{
			printf("%c ", S.ch[i]);
		}
	}
}