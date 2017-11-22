/***************************************************
Description:BTree
Author: Zuo Lu 		Version: 1.0	Date:2017/11/22
/***************************************************/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//����������Ľṹ��
typedef struct node{
	int data;				//����ڵ������
	struct node *left;		//������ڵ�
	struct node *right;		//�����ҽڵ�
}BTree;

//��������������ù���ݹ麯��
int BTreeCreate(BTree * *tp)
{
	//����������й���
	int x;
	scanf("%d\n", &x);

	if (x < 0)
	{
		(*tp) = NULL;
		return 0;
	}
	else
	{
		(*tp) = (BTree *)malloc(sizeof(BTree));
		if ((*tp) == NULL)
			return 0;
		(*tp)->data = x;

		//��ʼ�ݹ���������
		BTreeCreate(&((*tp)->left));
		BTreeCreate(&((*tp)->right));

		return 1;
	}
}

//��ʼ����
int main()
{
	BTree *tree;
	printf("Create binary tree:\n");
	BTreeCreate(&tree);

	return 0;
}