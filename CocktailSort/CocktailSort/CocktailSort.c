/***************************************************/
//Description:CocktailSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// ���� -------------- �ڲ��Ƚ�����(˫��ð������)
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- ���������һ��ʼ�Ѿ��󲿷�������Ļ�,��ӽ�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
/***************************************************/

#include <stdio.h>

//������������������ַ����
void swap(int A[], int i, int j)
{
	int temp;    //���ڽ�������ʱ����
	 
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//˫��ð��������
void CocktailSort(int A[], int n)
{
	int left = 0;
	int right = n - 1;
	int i;

	while (left < right)
	{
		//��һ�飬������Ԫ��ð�ݵ����
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
				swap(A, i, i + 1);
		}
		right--;

		//�ڶ��飬����С��Ԫ��ð�ݵ���ǰ��
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
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };   // ��С������ð������
	int n = sizeof(A) / sizeof(int);
	CocktailSort(A, n);
	printf("˫����������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


