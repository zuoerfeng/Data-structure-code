/***************************************************/
//Description:ShellSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
/***************************************************/


#include <stdio.h>  
#include "stdlib.h"


void ShellSort(int A[], int n)
{
	int add_step = 0;
	int i = 0;
	int j = 0;
	int wait_insert = 0;

	while (add_step <= n/3)
	{
		add_step = 3 * add_step + 1;			//???为什么这样做,为了开始让增量步长最大。分成三个组
	}

	while (add_step >= 1)
	{
		for (i = add_step; i < n; i++)
		{
			j = i - add_step;
			wait_insert = A[i];
			while (j >= 0 && wait_insert < A[j])
			{
				A[j + add_step] = A[j];
				j = j - add_step;
			}
			A[j + add_step] = wait_insert;
		}
		add_step = (add_step - 1) / 3;       // 递减增量
	}
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8,21,13,17,25 };// 从小到大希尔排序
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	printf("希尔排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}