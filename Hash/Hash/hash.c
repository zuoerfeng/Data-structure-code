/***************************************************
Description:Hash
Author: Zuo Lu 		Version: 1.0	Date:2017/11/27
/***************************************************/

#include <stdio.h>

//�궨��
#define DataType int		//������������
#define M 30				//����hash��Ĵ�С

//����hash�ڵ�Ľṹ��
typedef struct HashNode
{
	DataType data;    //�洢ֵ 
	int isNull;           //��־��λ���Ƿ��ѱ���� 
}HashTable;

//ȫ�ֱ���
HashTable hashTable[M];

//��hash����г�ʼ��
void initHashTable()     
{
	int i;
	for (i = 0; i<M; i++)
	{
		hashTable[i].isNull = 1;    //��ʼ״̬Ϊ�� 
	}
}

//Hash����
int getHashAddress(DataType key)     
{
	return key % 29;     //Hash����Ϊ key%29 
}

//��hash���в���Ԫ�� 
int insert(DataType key)    
{
	int address = getHashAddress(key);	 //ͨ��hash������ؼ�����hash���λ��
	if (hashTable[address].isNull == 1)  //û�з�����ͻ 
	{
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}
	else    //��������ͻ��ʱ�� 
	{
		while (hashTable[address].isNull == 0 && address < M)
		{
			address++;     //��������̽�ⷨ������Ϊ1 
		}
		if (address == M)    //Hash������� 
			return -1;

		//ͨ��̽�ֱⷨ���ҵ�һ��û�г�ͻ�ĵ�ַ
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}
	return 0;
}

//���в��� 
int find(DataType key)     
{
	int address = getHashAddress(key);
	while (!(hashTable[address].isNull == 0 && hashTable[address].data == key && address<M))
	{
		address++;
	}
	if (address == M)
		address = -1;
	return address;
}

int main(int argc, char *argv[])
{
	int key[] = { 123, 456, 7000, 8, 1, 13, 11, 555, 425, 393, 212, 546, 2, 99, 196 };
	int i;

	//����hash��
	initHashTable();

	//����hash��
	for (i = 0; i<15; i++)
	{
		insert(key[i]);
	}

	//ͨ��hash����в���
	for (i = 0; i<15; i++)
	{
		int address;
		address = find(key[i]);
		printf("key:%10d address:%10d\n", key[i], address);
	}

	system("pause");
	return 0;
}