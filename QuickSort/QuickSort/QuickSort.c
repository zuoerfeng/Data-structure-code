/***************************************************/
//Description:QuickSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// 分类 ------------ 内部比较排序(快速排序)
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定
/***************************************************/


//比较函数
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//划分函数，用来划分为一个个的组
int Partition(int A[], int left, int right) 
{
	int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
	int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引


	for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
	{
		if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
		{
			Swap(A, ++tail, i);
		}
	}
	Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
	// 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
	return tail + 1;                    // 返回基准的索引
}


//不停的进行划分组排序
void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // 基准的索引
	QuickSort(A, left, pivot_index - 1);		//对左边分组进行在划分，知道left=right，表示划分完
	QuickSort(A, pivot_index + 1, right);		//对右边小组进行划分
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 }; // 从小到大快速排序
	int n = sizeof(A) / sizeof(int);
	QuickSort(A, 0, n - 1);
	printf("快速排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}