#include<iostream>
using namespace std;
#define MAXLEN 30
typedef struct
{
	int data[MAXLEN];
	int length;
}Sqlist;
//�������
bool ListInsert(Sqlist& L, int i, int e)//�ڵ�iλ�ò�������e
{
	if (i<1 || i>L.length + 1)
	{
		return false;//�ж�i��ֵ�Ƿ�Ϸ�
	}
	if (L.length >= MAXLEN)
	{
		return false;//�жϴ洢�ռ��Ƿ�����
	}
	for (int j = L.length; j > i; i--)//��i���Ԫ�ض�����
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
//ɾ������
bool ListDelete(Sqlist& L, int i)//ɾ����i��λ�õ�Ԫ��
{
	if (i<1 || i>L.length)
	{
		return false;
	}
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];//��i���Ԫ�غ���
	}
	L.length--;
	return true;
}
int main()
{
	Sqlist L1;//����˳���L1
	L1.length = 0;
	ListInsert(L1, 1, 1);//��L1�ĵ�һ��λ�ò������� 1
	ListDelete(L1, 1);//ɾ��L1�ĵ�һ��Ԫ��
	return 0;
}