/***************************************************/
//Description:BubbleSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/29

// ���� -------------- �ڲ��Ƚ�����(ð������)
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- ��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,���԰�����ʱ�临�ӶȽ��͵�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
/***************************************************/

#include <stdio.h>

void Swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void BubbleSort(int A[], int n)
{
	for (int j = 0; j < n - 1; j++)         // ÿ�����Ԫ�ؾ�������һ��"��"����������
	{
		for (int i = 0; i < n - 1 - j; i++) // ���αȽ����ڵ�����Ԫ��,ʹ�ϴ���Ǹ������
		{
			if (A[i] > A[i + 1])            // ��������ĳ�A[i] >= A[i + 1],���Ϊ���ȶ��������㷨
			{
				Swap(A, i, i + 1);
			}
		}
	}
}

int main()
{
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 };    // ��С����ð������
	int n = sizeof(A) / sizeof(int);
	BubbleSort(A, n);
	printf("ð����������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}