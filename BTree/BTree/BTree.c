/***************************************************
Description:BTree
Author: Zuo Lu 		Version: 1.0	Date:2017/11/22
/***************************************************/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//构造二叉树的结构体
typedef struct node{
	int data;				//定义节点的数据
	struct node *left;		//定义左节点
	struct node *right;		//定义右节点
}BTree;

//构造二叉树：利用构造递归函数
int BTreeCreate(BTree * *tp)
{
	//按照先序进行构造
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

		//开始递归左、右子树
		BTreeCreate(&((*tp)->left));
		BTreeCreate(&((*tp)->right));

		return 1;
	}
}

//开始测试
int main()
{
	BTree *tree;
	printf("Create binary tree:\n");
	BTreeCreate(&tree);

	return 0;
}