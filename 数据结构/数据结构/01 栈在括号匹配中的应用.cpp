#include<stdio.h>
#define MaxSize 20

typedef struct
{
	char data[MaxSize];//存放在栈中的元素
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
void Push(SqStack& S, char x)
{
	if (S.top == MaxSize - 1)//栈已满
	{
		return;
	}
	S.top++;
	S.data[S.top] = x;
}

//出栈
char Pop(SqStack& S)
{
	char x;
	if (S.top == -1)
	{
		printf("栈为空！");
	}
	x = S.data[S.top];
	S.top--;
	return x;
}
bool BracketCheck(char str[], int len)
{
	SqStack S;
	InitStack(S);//初始化栈
	for (int i = 0; i < len; i++)
	{
		//扫描左括号入栈
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			Push(S, str[i]);
		}
		//扫描到右括号，元素出栈匹配
		else
		{
			//栈空，匹配失败
			if (StackEmpty(S))
			{
				return false;
			}

			//栈顶元素出栈
			char topElme;
			topElme = Pop(S);
			if (str[i] == ')' && topElme != '(')
			{
				return false;
			}
			if (str[i] == ']' && topElme != '[')
			{
				return false;
			}
			if (str[i] == '}' && topElme != '{')
			{
				return false;
			}
		}
	}
	//判断栈是否为空，为空则匹配成功
	return StackEmpty(S);
}
int main()
{
	char str[] = "{[()]}()[";
	bool tmp = BracketCheck(str, 9);
	if (tmp)
	{
		printf("括号正确！");
	}
	else
	{
		printf("括号错误！");
	}
	return 0;
}