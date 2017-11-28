/***************************************************/
//Description:ShellSort
//Author: Zuo Lu 		Version: 1.0	Date:2017/11/28

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ����֪��õ�ΪO(n(logn)^2)
// ����ʱ�临�Ӷ� ---- O(n)
// ƽ��ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ��
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
/***************************************************/


#include <stdio.h>  
#include "stdlib.h"


void ShellSort(int A[], int n)
{
	int add_step = 0;
	int i = 0;
	int j = 0;
	int wait_insert = 0;

	while (add_step <= n/3)
	{
		add_step = 3 * add_step + 1;			//???Ϊʲô������,Ϊ�˿�ʼ������������󡣷ֳ�������
	}

	while (add_step >= 1)
	{
		for (i = add_step; i < n; i++)
		{
			j = i - add_step;
			wait_insert = A[i];
			while (j >= 0 && wait_insert < A[j])
			{
				A[j + add_step] = A[j];
				j = j - add_step;
			}
			A[j + add_step] = wait_insert;
		}
		add_step = (add_step - 1) / 3;       // �ݼ�����
	}
}

int main()
{
	int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8,21,13,17,25 };// ��С����ϣ������
	int n = sizeof(A) / sizeof(int);
	ShellSort(A, n);
	printf("ϣ����������");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}