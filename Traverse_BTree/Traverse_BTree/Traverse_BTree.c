/***************************************************
Description:Traverse_BTree
Author: Zuo Lu 		Version: 1.0	Date:2017/11/22
/***************************************************/


#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//定义二叉树
typedef struct node{
	int data;//数据元素
	struct node *left;//指向左子树
	struct node *right;//指向右子树
}BTree;

//构造二叉树：递归方式
int BTreeCreate(BTree **tp)
{
	//构造方法，或者说构造顺序：从左子树开始构造
	int x;
	scanf("%d", &x);
	if (x <= 0)
	{
		*tp = NULL;//指针为空，树节点中的某个指针为空
		return 0;
	}
	*tp = (BTree*)malloc(sizeof(BTree));//将树节点中指针指向该地址空间
	if (tp == NULL)
		return 0;
	(*tp)->data = x;
	BTreeCreate(&((*tp)->left));
	BTreeCreate(&((*tp)->right));
	return 1;
}

//遍历：前序遍历,递归的方式，先根节点，再左子树后右子树
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

//遍历：中序遍历，递归方式，先左子树再根节点最后右子树
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

//遍历：后序遍历，递归方式，先左子树再右子树最后根节点

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
	//二叉树构建
	BTree *tree;
	printf("Create binary tree:\n");
	BTreeCreate(&tree);
	//前序遍历
	printf("Pre order:\n");
	PreOrder(tree);
	printf("\n");
	//中序遍历
	printf("Mid order:\n");
	MidOrder(tree);
	printf("\n");
	//后序遍历
	printf("Post order:\n");
	PostOrder(tree);
	printf("\n");

	system("pause");
	return 0;
	
}