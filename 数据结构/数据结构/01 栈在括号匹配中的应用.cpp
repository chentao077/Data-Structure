#include<stdio.h>
#define MaxSize 20

typedef struct
{
	char data[MaxSize];//�����ջ�е�Ԫ��
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
void Push(SqStack& S, char x)
{
	if (S.top == MaxSize - 1)//ջ����
	{
		return;
	}
	S.top++;
	S.data[S.top] = x;
}

//��ջ
char Pop(SqStack& S)
{
	char x;
	if (S.top == -1)
	{
		printf("ջΪ�գ�");
	}
	x = S.data[S.top];
	S.top--;
	return x;
}
bool BracketCheck(char str[], int len)
{
	SqStack S;
	InitStack(S);//��ʼ��ջ
	for (int i = 0; i < len; i++)
	{
		//ɨ����������ջ
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			Push(S, str[i]);
		}
		//ɨ�赽�����ţ�Ԫ�س�ջƥ��
		else
		{
			//ջ�գ�ƥ��ʧ��
			if (StackEmpty(S))
			{
				return false;
			}

			//ջ��Ԫ�س�ջ
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
	//�ж�ջ�Ƿ�Ϊ�գ�Ϊ����ƥ��ɹ�
	return StackEmpty(S);
}
int main()
{
	char str[] = "{[()]}()[";
	bool tmp = BracketCheck(str, 9);
	if (tmp)
	{
		printf("������ȷ��");
	}
	else
	{
		printf("���Ŵ���");
	}
	return 0;
}