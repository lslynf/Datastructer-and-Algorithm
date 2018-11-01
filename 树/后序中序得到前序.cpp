#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	char data;
	struct node *lchild,*rchild;
}BiTreeNode,*BiTree;
char mid[1005];
char post[1005];
int Find(char value)
{
	int n=strlen(mid);
	for(int i=0;i<n;i++)
	{
		if(mid[i]==value)
			return i;
	}
}
//l,r是指区间长度 
void CreatTree(BiTree &T,int l,int r,int RootP)//最后一个位置是根的位置 
{
	if(l>r)
		return;
	T=new BiTreeNode;
	T->data=post[RootP];
	T->lchild=T->rchild=NULL;
	int indice=Find(T->data);
	CreatTree(T->lchild,l,indice-1,RootP-r+indice-1);
	CreatTree(T->rchild,indice+1,r,RootP-1);
}
void PreOrder(BiTree T)
{
	if(T)
	{
		cout<<T->data<<" ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 
int TreeHight(BiTree T)
{
	if(T)
	{
		int l=TreeHight(T->lchild)+1;
		int r=TreeHight(T->rchild)+1;
		return max(l,r);
	}
}
int main()
{
	cin>>mid;
	cin>>post;
	int len=strlen(mid)-1;
	BiTree T;
	CreatTree(T,0,len,len);
	PreOrder(T);
	int hight=TreeHight(T);
	cout<<hight<<endl;
}
//dbaecf dbefca
//dbheijafcg dhjiebfgca
