#include<stdio.h>
#include<iostream>
using namespace std;
#define MaxSize 20

typedef struct
{
	int data[MaxSize];//存放在栈中的元素
	int top;//栈顶指针
} SqStack;

//初始化栈
void InitStack(SqStack& S)
{
	S.top = -1;
}

//判断栈是否为空
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

//进栈
void Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)//栈已满
	{
		return;
	}
	S.top++;
	S.data[S.top] = x;
}

//出栈
int Pop(SqStack& S)
{
	int x;
	if (S.top == -1)
	{
		printf("栈为空！");
	}
	x = S.data[S.top];
	S.top--;
	return x;
}
int p(int n, int x)
{
	SqStack S;
	InitStack(S);//初始化栈
	int fv1 = 1;
	int fv2 = 2 * x;
	int tmp = 2;//计数
	if (n == 0)
	{
		return fv1;
	}
	if (n == 1)
	{
		return fv2;
	}
	Push(S, fv1);//fv1和fv2入栈
	Push(S, fv2);
	while (tmp < n)
	{
		//出栈
		int fa2 = Pop(S);
		int fa1 = Pop(S);
		//计算值
		int amp = fa2;
		fa2 = 2 * x * fa2 - 2 * tmp * fa1;
		fa1 = amp;
		//入栈
		Push(S, fa1);
		Push(S, fa2);
		//计数值++
		tmp++;
	}
	//栈顶元素出栈并返回
	return Pop(S);
}
int main()
{
	int tmp = p(3, 2);
	cout << "结果是：" << tmp << endl;
	return 0;
}