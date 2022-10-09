#include<stdio.h>
#include<iostream>
using namespace std;
#define MaxSize 20

typedef struct
{
	int data[MaxSize];//�����ջ�е�Ԫ��
	int top;//ջ��ָ��
} SqStack;

//��ʼ��ջ
void InitStack(SqStack& S)
{
	S.top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack& S)
{
	if (S.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ջ
void Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)//ջ����
	{
		return;
	}
	S.top++;
	S.data[S.top] = x;
}

//��ջ
int Pop(SqStack& S)
{
	int x;
	if (S.top == -1)
	{
		printf("ջΪ�գ�");
	}
	x = S.data[S.top];
	S.top--;
	return x;
}
int p(int n, int x)
{
	SqStack S;
	InitStack(S);//��ʼ��ջ
	int fv1 = 1;
	int fv2 = 2 * x;
	int tmp = 2;//����
	if (n == 0)
	{
		return fv1;
	}
	if (n == 1)
	{
		return fv2;
	}
	Push(S, fv1);//fv1��fv2��ջ
	Push(S, fv2);
	while (tmp < n)
	{
		//��ջ
		int fa2 = Pop(S);
		int fa1 = Pop(S);
		//����ֵ
		int amp = fa2;
		fa2 = 2 * x * fa2 - 2 * tmp * fa1;
		fa1 = amp;
		//��ջ
		Push(S, fa1);
		Push(S, fa2);
		//����ֵ++
		tmp++;
	}
	//ջ��Ԫ�س�ջ������
	return Pop(S);
}
int main()
{
	int tmp = p(3, 2);
	cout << "����ǣ�" << tmp << endl;
	return 0;
}