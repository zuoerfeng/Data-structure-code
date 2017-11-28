/***************************************************/
//Description:InsertionSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// ���� ------------- �ڲ��Ƚ�����(ֱ�Ӳ�������)
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- ����Ϊ���������ǽ������е�,��ʱʱ�临�Ӷ�O(n^2)
// ����ʱ�临�Ӷ� ---- ������Ϊ�����������������е�,��ʱʱ�临�Ӷ�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
/***************************************************/


#include <stdio.h>
#include "stdlib.h"


void InsertionSort(int A[], int n)
{
	int i, j = 0;
	int wait_insert;
	for (i = 1; i < n; i++)
	{
		wait_insert = A[i];					//���������������
		j = i - 1;
		while (j >= 0 && A[j]>wait_insert)		//һ�����ıȽϣ����Ƚ�С�ڵ�ǰֵ��ʱ�򣬼��ɲ��뵽��ǰ��	
		{
			A[j + 1] = A[j];					
			j--;
		}
		A[j + 1] = wait_insert;					//���뵽j+1��λ�ã����λ���ǿ����
	}
}



int main()
{
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 ,21,23,45,12,9};// ��С�����������
	int n = sizeof(A) / sizeof(int);
	InsertionSort(A, n);
	printf("������������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}