#include<iostream>
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}LNode, * Linkilst;
//头插法建立单链表
Linkilst HeadInsert(Linkilst& L)
{
	LNode* s;
	int x;
	L = (Linkilst)malloc(sizeof(LNode));
	L->next = NULL;
	cout << "请输入添加的数据(输入99999停止)：" << endl;
	cin >> x;
	while (x != 99999)
	{
		s = (Linkilst)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}
//按序号查找结点值
LNode* GetElem(Linkilst& L, int i)
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)
	{
		return L;
	}
	if (i < i)
	{
		return NULL;
	}
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}
//插入操作
bool LNinsert(Linkilst& L, int i, int x)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p = GetElem(L, i - 1);
	LNode* s = (Linkilst)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return true;
}
//删除操作
bool LNdelete(Linkilst& L, int i)
{
	if (i < 1)
	{
		return false;
	}
	LNode* p = GetElem(L, i - 1);
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	return true;
}
int main()
{
	LNode* L1;
	HeadInsert(L1);//创建单链表L1
	int i = 1;
	LNinsert(L1, 1, 1);//在第一个位置插入数据域为1的结点
	LNdelete(L1, 1);//删除第一个结点
}