/***************************************************/
//Description:InsertionSortDichotomy
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// 分类 -------------- 内部比较排序(二分插入排序)
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
/***************************************************/



void InsertionSortDichotomy(int A[], int n)
{
	int i, j = 0;
	int left, right = 0;
	int wait_insert = 0;

	for (int i = 1; i < n; i++)
	{
		wait_insert = A[i];
		left = 0;									//认为左边都是已经排序好的
		right = i - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;			//从中间选择
			if (A[mid] > wait_insert)
				right = mid - 1;					//在左半边，则缩小右边的边距
			else
				left = mid + 1;						//往右边去找
		}


		for (int j = i - 1; j >= left; j--)			//跳出循环，此时左地址即为要插入的地址，left及以上都应该后移
		{
			A[j + 1] = A[j];
		}
		A[left] = wait_insert;
	}
}


int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8, 10,24,21 };// 从小到大二分插入排序
	int n = sizeof(A) / sizeof(int);
	InsertionSortDichotomy(A, n);
	printf("二分插入排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}