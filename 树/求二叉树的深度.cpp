#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
char mid[105];
char post[105];
int len,ans;
typedef struct node
{
	char data;
	struct node *lchild,*rchild; 
}treenode,*tree;
int find(char ch)
{
	for(int i=0;i<len;i++)
	{
		if(mid[i]==ch)
			return i;
	}
}
void buildtree(tree &root,int l,int r,int pos)
{
	if(l>r)
		return;
	root=new treenode();
	root->data=post[pos];
	root->lchild=root->rchild=NULL;
	int index=find(root->data);
	buildtree(root->lchild,l,index-1,pos-r+index-1);
	buildtree(root->rchild,index+1,r,pos-1);
}
void pretreavl(tree root)
{
	if(root)
	{
		printf("%c ",root->data);
		pretreavl(root->lchild);
		pretreavl(root->rchild);
	}
}
void getdepth(tree root,int deep)
{
	if(root)
	{
		if(deep>ans)
			ans=deep;
		getdepth(root->lchild,deep+1);
		getdepth(root->rchild,deep+1);
	}
}
int main()
{
	scanf("%s",mid);
	scanf("%s",post);
	tree T;
	len=strlen(mid);
	buildtree(T,0,len-1,len-1);
	printf("前序遍历为:\n");
	pretreavl(T);
	printf("\n");
	ans=-1;
	printf("二叉树的深度为:\n");
	getdepth(T,1);
	printf("%d\n",ans);
}

//dbgeafc
//dgebfca

