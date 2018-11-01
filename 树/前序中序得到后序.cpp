#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BiTreeNode,*BiTree;
char pre[1005];
char mid[1005];
int Find(char value)
{
	int n=strlen(mid);
	for(int i=0;i<n;i++)
	{
		if(mid[i]==value)
			return i;
	}
}
void CreatTree(BiTree &T,int l,int r,int RootP)
{
	if(l>r)
		return;
	T=new BiTreeNode;
	T->data=pre[RootP];
	T->lchild=T->rchild=NULL;
	int indice=Find(T->data);
	CreatTree(T->lchild,l,indice-1,RootP+1);
	CreatTree(T->rchild,indice+1,r,RootP+indice-l+1);	
}
void PostOrder(BiTree T)
{
	if(T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout<<T->data<<" ";
	}
}
int main()
{
	cin>>pre;
	cin>>mid;
	BiTree T;
	int len=strlen(pre)-1;
	CreatTree(T,0,len,0);
	PostOrder(T);
}

