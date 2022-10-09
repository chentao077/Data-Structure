#include<iostream>
using namespace std;
typedef struct BitNode
{
	int data;
	struct BitNode* lchild;
	struct BitNode* rchild;
}BiTNode, * Bitree;
void visit(Bitree T)
{
	cout << T->data << endl;
}
//�������
void PreOrder(Bitree T)
{
	visit(T);//���ʸ��ڵ�
	PreOrder(T->lchild);//����������
	PreOrder(T->rchild);//����������
}
//�������
void InOrder(Bitree T)
{
	InOrder(T->lchild);//����������
	visit(T);//���ʸ��ڵ�
	InOrder(T->rchild);//����������
}
//�������
void LastOrder(Bitree T)
{
	LastOrder(T->lchild);//����������
	LastOrder(T->rchild);//����������
	visit(T);//���ʸ��ڵ�
}