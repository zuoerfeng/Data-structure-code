/***************************************************/
//Description:QuickSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// ���� ------------ �ڲ��Ƚ�����(��������)
// ���ݽṹ --------- ����
// ���ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ ��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)       
// �ȶ��� ---------- ���ȶ�
/***************************************************/


//�ȽϺ���
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//���ֺ�������������Ϊһ��������
int Partition(int A[], int left, int right) 
{
	int pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
	int tail = left - 1;                // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����


	for (int i = left; i < right; i++)  // ������׼���������Ԫ��
	{
		if (A[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
		{
			Swap(A, ++tail, i);
		}
	}
	Swap(A, tail + 1, right);           // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
	// �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
	return tail + 1;                    // ���ػ�׼������
}


//��ͣ�Ľ��л���������
void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // ��׼������
	QuickSort(A, left, pivot_index - 1);		//����߷�������ڻ��֣�֪��left=right����ʾ������
	QuickSort(A, pivot_index + 1, right);		//���ұ�С����л���
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 }; // ��С�����������
	int n = sizeof(A) / sizeof(int);
	QuickSort(A, 0, n - 1);
	printf("������������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}