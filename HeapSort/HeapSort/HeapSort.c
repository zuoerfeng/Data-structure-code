/***************************************************/
//Description:HeapSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// ���� -------------- �ڲ��Ƚ�����(������)
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
/***************************************************/

//�����Ӻ���
void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}


//���ԶѺ���������һά����洢��
void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ���
{
	int left_child = 2 * i + 1;         // ��������
	int right_child = 2 * i + 2;        // �Һ�������
	int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ

	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;

	if (max != i)
	{
		Swap(A, i, max);                // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н���
		Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ���
	}
}

//����������ݽ���һ���� 
int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--)	// ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
		Heapify(A, i, heap_size);
	return heap_size;
}

//���ж�����
void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);		// ����һ�����ѣ��Ѷ�������Ԫ�أ�
	while (heap_size > 1)					// �ѣ���������Ԫ�ظ�������1��δ�������
	{
		// ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
		// �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
		Swap(A, 0, --heap_size);	  //ע�⣬���ʱ�򽻻��ĶѶ�Ԫ���Ѿ���ȡ�������ѵĽڵ����������
		Heapify(A, 0, heap_size);     // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
	}
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// ��С���������
	int n = sizeof(A) / sizeof(int);
	HeapSort(A, n);
	printf("����������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}