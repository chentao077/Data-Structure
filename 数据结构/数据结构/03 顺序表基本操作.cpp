#include<iostream>
using namespace std;
#define MAXLEN 30
typedef struct
{
	int data[MAXLEN];
	int length;
}Sqlist;
//插入操作
bool ListInsert(Sqlist& L, int i, int e)//在第i位置插入数据e
{
	if (i<1 || i>L.length + 1)
	{
		return false;//判断i的值是否合法
	}
	if (L.length >= MAXLEN)
	{
		return false;//判断存储空间是否已满
	}
	for (int j = L.length; j > i; i--)//将i后的元素都后移
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
//删除操作
bool ListDelete(Sqlist& L, int i)//删除第i个位置的元素
{
	if (i<1 || i>L.length)
	{
		return false;
	}
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];//将i后的元素后移
	}
	L.length--;
	return true;
}
int main()
{
	Sqlist L1;//创建顺序表L1
	L1.length = 0;
	ListInsert(L1, 1, 1);//在L1的第一个位置插入数据 1
	ListDelete(L1, 1);//删除L1的第一个元素
	return 0;
}