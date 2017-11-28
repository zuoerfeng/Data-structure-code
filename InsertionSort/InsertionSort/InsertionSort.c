/***************************************************/
//Description:InsertionSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// 分类 ------------- 内部比较排序(直接插入排序)
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
/***************************************************/


#include <stdio.h>
#include "stdlib.h"


void InsertionSort(int A[], int n)
{
	int i, j = 0;
	int wait_insert;
	for (i = 1; i < n; i++)
	{
		wait_insert = A[i];					//给出带插入的数字
		j = i - 1;
		while (j >= 0 && A[j]>wait_insert)		//一个个的比较，当比较小于当前值的时候，即可插入到当前块	
		{
			A[j + 1] = A[j];					
			j--;
		}
		A[j + 1] = wait_insert;					//插入到j+1的位置，这个位置是空余的
	}
}



int main()
{
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 ,21,23,45,12,9};// 从小到大插入排序
	int n = sizeof(A) / sizeof(int);
	InsertionSort(A, n);
	printf("插入排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}