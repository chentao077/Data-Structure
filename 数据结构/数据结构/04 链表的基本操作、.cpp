#include<iostream>
using namespace std;
typedef struct Lnode
{
	int data;
	struct Lnode* next;
}LNode, * Linkilst;
//ͷ�巨����������
Linkilst HeadInsert(Linkilst& L)
{
	LNode* s;
	int x;
	L = (Linkilst)malloc(sizeof(LNode));
	L->next = NULL;
	cout << "��������ӵ�����(����99999ֹͣ)��" << endl;
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
//����Ų��ҽ��ֵ
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
//�������
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
//ɾ������
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
	HeadInsert(L1);//����������L1
	int i = 1;
	LNinsert(L1, 1, 1);//�ڵ�һ��λ�ò���������Ϊ1�Ľ��
	LNdelete(L1, 1);//ɾ����һ�����
}