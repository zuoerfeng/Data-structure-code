#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "stdlib.h"
#include "Polynomial_list.h"

//���Զ���ʽ����ģ��Ĺ���
int main()
{
	polynomial Pa, Pb;
	int m, n, i;
	m = 6;  //����ʽ1Ϊ6��
	n = 5;	//����ʽ2Ϊ5��

	//���Զ���ʽ����Ĵ���
	printf("Function 1\n�ﺯ��CreatPolyn(polynomial *P,int m)����...\n");
	printf("��������һԪ����ʽPa��Ԫ��...\n");
	CreatPolyn(&Pa, m);
	printf("\n");
	printf("��������һԪ����ʽPb��Ԫ��...\n");
	CreatPolyn(&Pb, n);
	printf("\n");

	//��ӡ����Ķ���ʽ
	printf("Function 2\n�ﺯ��PrintPolyn(polynomial P)����...\n");
	printf("��һԪ����ʽPa=");
	PrintPolyn(Pa);
	printf("\n");
	printf("��һԪ����ʽPb=");
	PrintPolyn(Pb);
	printf("\n\n");

	//���Զ���ʽ�ĳ���
	printf("Function 3\n�ﺯ��PolyLength(polynomial P)����...\n");
	n = PolyLength(Pa);
	printf("��һԪ����ʽPa������Ϊ��%d\n", n);
	n = PolyLength(Pb);
	printf("��һԪ����ʽPb������Ϊ��%d\n\n", n);

	//������������ʽ��ӵĽ��
	printf("Function 4\n�ﺯ��AddPolyn(polynomial *Pa,polynomial *Pb)����...\n");
	printf("��Pa=Pa+Pb=");
	AddPolyn(&Pa, &Pb);
	PrintPolyn(Pa);
	printf("\n");

	//�������ٶ���ʽ
	printf("Function 5\n�ﺯ��DestroyPolyn(polynomial *P)����...\n");
	printf("������Paǰ��");
	(Pa.head&&Pa.tail&&Pa.len) ? printf("Pa��  �ڣ�����\n") : printf("Pa�����ڣ�����\n");
	DestroyPolyn(&Pa);
	printf("������Pa��");
	(Pa.head&&Pa.tail&&Pa.len) ? printf("Pa��  �ڣ�����\n\n") : printf("Pa�����ڣ�����\n\n");

	system("pause");
}