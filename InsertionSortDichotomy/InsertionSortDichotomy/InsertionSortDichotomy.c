/***************************************************/
//Description:InsertionSortDichotomy
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// ���� -------------- �ڲ��Ƚ�����(���ֲ�������)
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
/***************************************************/



void InsertionSortDichotomy(int A[], int n)
{
	int i, j = 0;
	int left, right = 0;
	int wait_insert = 0;

	for (int i = 1; i < n; i++)
	{
		wait_insert = A[i];
		left = 0;									//��Ϊ��߶����Ѿ�����õ�
		right = i - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;			//���м�ѡ��
			if (A[mid] > wait_insert)
				right = mid - 1;					//�����ߣ�����С�ұߵı߾�
			else
				left = mid + 1;						//���ұ�ȥ��
		}


		for (int j = i - 1; j >= left; j--)			//����ѭ������ʱ���ַ��ΪҪ����ĵ�ַ��left�����϶�Ӧ�ú���
		{
			A[j + 1] = A[j];
		}
		A[left] = wait_insert;
	}
}


int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8, 10,24,21 };// ��С������ֲ�������
	int n = sizeof(A) / sizeof(int);
	InsertionSortDichotomy(A, n);
	printf("���ֲ�����������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}