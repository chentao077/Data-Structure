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
//先序遍历
void PreOrder(Bitree T)
{
	visit(T);//访问根节点
	PreOrder(T->lchild);//访问左子树
	PreOrder(T->rchild);//访问右子树
}
//中序遍历
void InOrder(Bitree T)
{
	InOrder(T->lchild);//访问左子树
	visit(T);//访问根节点
	InOrder(T->rchild);//访问右子树
}
//后序遍历
void LastOrder(Bitree T)
{
	LastOrder(T->lchild);//访问左子树
	LastOrder(T->rchild);//访问右子树
	visit(T);//访问根节点
}