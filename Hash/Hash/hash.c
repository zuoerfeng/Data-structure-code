/***************************************************
Description:Hash
Author: Zuo Lu 		Version: 1.0	Date:2017/11/27
/***************************************************/

#include <stdio.h>

//宏定义
#define DataType int		//定义数据类型
#define M 30				//定义hash表的大小

//定义hash节点的结构体
typedef struct HashNode
{
	DataType data;    //存储值 
	int isNull;           //标志该位置是否已被填充 
}HashTable;

//全局变量
HashTable hashTable[M];

//对hash表进行初始化
void initHashTable()     
{
	int i;
	for (i = 0; i<M; i++)
	{
		hashTable[i].isNull = 1;    //初始状态为空 
	}
}

//Hash函数
int getHashAddress(DataType key)     
{
	return key % 29;     //Hash函数为 key%29 
}

//向hash表中插入元素 
int insert(DataType key)    
{
	int address = getHashAddress(key);	 //通过hash函数求关键词在hash表的位置
	if (hashTable[address].isNull == 1)  //没有发生冲突 
	{
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}
	else    //当发生冲突的时候 
	{
		while (hashTable[address].isNull == 0 && address < M)
		{
			address++;     //采用线性探测法，步长为1 
		}
		if (address == M)    //Hash表发生溢出 
			return -1;

		//通过探测法直到找到一个没有冲突的地址
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}
	return 0;
}

//进行查找 
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

	//建立hash表
	initHashTable();

	//完善hash表
	for (i = 0; i<15; i++)
	{
		insert(key[i]);
	}

	//通过hash表进行查找
	for (i = 0; i<15; i++)
	{
		int address;
		address = find(key[i]);
		printf("key:%10d address:%10d\n", key[i], address);
	}

	system("pause");
	return 0;
}