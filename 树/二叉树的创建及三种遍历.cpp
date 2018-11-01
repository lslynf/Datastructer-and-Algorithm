#include<bits/stdc++.h> 
using namespace std;
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BiTreeNode,*BiTree;
void CreatTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if(ch=='#')
		T=NULL;
	else
	{
		T=new BiTreeNode;
		T->data=ch;
		CreatTree(T->lchild);
		CreatTree(T->rchild);
	}
}
void PreOrder(BiTree &T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void MidOrder(BiTree &T)
{
	if(T!=NULL)
	{
		MidOrder(T->lchild);
		cout<<T->data<<" ";
		MidOrder(T->rchild);
	}
}
void PostOrder(BiTree &T)
{
	if(T!=NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout<<T->data<<" ";
	}
}
void LayerOrder(BiTree &T)
{
	queue<BiTree>q;
	if(T!=NULL)
	{
		q.push(T);
	}
	while(!q.empty())
	{
	 	BiTree temp=q.front();
	 	q.pop();
		cout<<temp->data<<" ";
		if(temp->lchild) 
		{
			q.push(temp->lchild);
		}
		if(temp->rchild)
		{
			q.push(temp->rchild);
		}
	}
}
int main()
{
	BiTree T;
	CreatTree(T);
	cout<<"前序遍历"<<endl;
	PreOrder(T);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	MidOrder(T);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	PostOrder(T);
	cout<<endl;
	cout<<"层次遍历"<<endl;
	LayerOrder(T);
}
