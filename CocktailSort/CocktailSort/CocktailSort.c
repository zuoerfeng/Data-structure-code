/***************************************************/
//Description:CocktailSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// 分类 -------------- 内部比较排序(双向冒泡排序)
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
/***************************************************/

#include <stdio.h>

//交换函数，给两个地址交换
void swap(int A[], int i, int j)
{
	int temp;    //用于交换的临时变量
	 
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//双向冒泡排序函数
void CocktailSort(int A[], int n)
{
	int left = 0;
	int right = n - 1;
	int i;

	while (left < right)
	{
		//第一遍，将最大的元素冒泡到最后
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
				swap(A, i, i + 1);
		}
		right--;

		//第二遍，将最小的元素冒泡到最前面
		for (i = right; i > left; i--)   
		{
			if (A[i - 1] > A[i])
				swap(A, i - 1, i);
		}
		left++;
	}
}

int main()
{
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };   // 从小到大定向冒泡排序
	int n = sizeof(A) / sizeof(int);
	CocktailSort(A, n);
	printf("双向排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


