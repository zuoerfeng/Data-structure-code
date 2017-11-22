/***************************************************
Description:Traverse_BTree
Author: Zuo Lu 		Version: 1.0	Date:2017/11/22
/***************************************************/


#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//���������
typedef struct node{
	int data;//����Ԫ��
	struct node *left;//ָ��������
	struct node *right;//ָ��������
}BTree;

//������������ݹ鷽ʽ
int BTreeCreate(BTree **tp)
{
	//���췽��������˵����˳�򣺴���������ʼ����
	int x;
	scanf("%d", &x);
	if (x <= 0)
	{
		*tp = NULL;//ָ��Ϊ�գ����ڵ��е�ĳ��ָ��Ϊ��
		return 0;
	}
	*tp = (BTree*)malloc(sizeof(BTree));//�����ڵ���ָ��ָ��õ�ַ�ռ�
	if (tp == NULL)
		return 0;
	(*tp)->data = x;
	BTreeCreate(&((*tp)->left));
	BTreeCreate(&((*tp)->right));
	return 1;
}

//������ǰ�����,�ݹ�ķ�ʽ���ȸ��ڵ㣬����������������
void PreOrder(BTree *tree)
{
	if (tree == NULL)
	{
		return;
	}
	printf("%d ", tree->data);
	PreOrder(tree->left);
	PreOrder(tree->right);
}

//����������������ݹ鷽ʽ�����������ٸ��ڵ����������
void MidOrder(BTree *tree)
{
	if (tree == NULL)
	{
		return;
	}
	MidOrder(tree->left);
	printf("%d ", tree->data);
	MidOrder(tree->right);
}

//����������������ݹ鷽ʽ�����������������������ڵ�

void PostOrder(BTree *tree)
{
	if (tree == NULL)
	{
		return;
	}
	PostOrder(tree->left);
	PostOrder(tree->right);
	printf("%d ", tree->data);
}

int main()
{
	//����������
	BTree *tree;
	printf("Create binary tree:\n");
	BTreeCreate(&tree);
	//ǰ�����
	printf("Pre order:\n");
	PreOrder(tree);
	printf("\n");
	//�������
	printf("Mid order:\n");
	MidOrder(tree);
	printf("\n");
	//�������
	printf("Post order:\n");
	PostOrder(tree);
	printf("\n");

	system("pause");
	return 0;
	
}