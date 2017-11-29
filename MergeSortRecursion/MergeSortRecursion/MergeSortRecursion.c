/***************************************************/
//Description:MergeSortRecursion
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定
/***************************************************/


#include <stdio.h>
#include <limits.h>
#include <malloc.h>

//归并操作: 将两个已经排序的序列合并成一个序列的操作
void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
	int len = right - left + 1;
	int *temp = (int*)malloc(len*sizeof(int));// 辅助空间O(n)       
	int index = 0;
	int i = left;                   // 前一数组的起始元素
	int j = mid + 1;                // 后一数组的起始元素

	//比较两个数组，按照大小进行合并
	while (i <= mid && j <= right)
	{
		if (A[i] <= A[j])				// 带等号保证归并排序的稳定性
		{
			temp[index] = A[i];
			i++;
			index++;
		}
		else
		{
			temp[index] = A[j];
			index++;
			j++;
		}
	}

	//当i还有剩余，则将i后面的数据补充在末尾
	while (i <= mid)
	{
		temp[index++] = A[i++];
	}

	//当j还有剩余，则将j后面的数据补充在末尾
	while (j <= right)
	{
		temp[index++] = A[j++];
	}
	
	//最后将临时数组中的数据返回A
	for (int k = 0; k < len; k++)
	{
		A[left++] = temp[k];
	}
}

// 递归实现的归并排序(自顶向下)----先8个，再4个，在2个
void MergeSortRecursion(int A[], int left, int right)   
{
	if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
		return;
	int mid = (left + right) / 2;      //两路归并
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid + 1, right);
	Merge(A, left, mid, right);
}

// 非递归(迭代)实现的归并排序(自底向上)（每两个合并，每4个合并）
void MergeSortIteration(int A[], int len)    
{
	int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
	for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
	{
		left = 0;
		while (left + i < len)              // 后一个子数组存在(需要归并)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
			Merge(A, left, mid, right);
			left = right + 1;               // 前一个子数组索引向后移动
		}
	}
}

int main()
{
	int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // 从小到大归并排序
	int A2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	int n1 = sizeof(A1) / sizeof(int);
	int n2 = sizeof(A2) / sizeof(int);
	MergeSortRecursion(A1, 0, n1 - 1);          // 递归实现
	MergeSortIteration(A2, n2);                 // 非递归实现
	printf("递归实现的归并排序结果：");
	for (int i = 0; i < n1; i++)
	{
		printf("%d ", A1[i]);
	}
	printf("\n");
	printf("非递归实现的归并排序结果：");
	for (int i = 0; i < n2; i++)
	{
		printf("%d ", A2[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}