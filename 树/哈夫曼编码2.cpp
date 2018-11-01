#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int weight;
	int code;//标记左右孩子 
	struct node *parent,*lchild,*rchild;
	bool leaf;
}HuffmanNode,*Huffman;
struct cmp
{
	bool operator()(node* a,node* b)
	{
		return a->weight>b->weight;
	}
};
priority_queue<node*,vector<Huffman>,cmp> q;
map<int,string>ans;
string res=""; 
int cnt=0;
void UTDCode(Huffman T)
{
	if(T->leaf==true)//如果遍历到叶子节点 
	{
		ans[T->weight]=res;
		return;
	}
	res+='0';
	UTDCode(T->lchild);
	res[res.size()-1]='1';//回退 
	UTDCode(T->rchild);
	res=res.substr(0,res.size()-1);//同理回溯 
}
void DTUCode(Huffman T)
{
	if(T==NULL)
		return;
	if(T->leaf==true)//找到叶子节点 
	{
		cout<<T->weight<<": ";
		Huffman temp=T->parent;
		while(temp!=NULL) 
		{
			cout<<T->code;
			T=temp;
			temp=T->parent;
		}
		cout<<endl;
	}
	else
	{
		DTUCode(T->lchild);
		DTUCode(T->rchild);
	}
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int value;
		cin>>value;
		Huffman temp=new HuffmanNode;
		temp->weight=value;
		temp->lchild=temp->rchild=temp->parent=NULL;
		temp->code=0; 
		temp->leaf=true;
		q.push(temp);
	}
	//构建哈夫曼树 
	while(q.size()>1)
	{
		Huffman x=q.top();q.pop();
		Huffman y=q.top();q.pop();
		Huffman root=new HuffmanNode;
		root->weight=x->weight+y->weight;
		root->lchild=x; root->rchild=y;
		root->leaf=false; root->parent=NULL;
		x->parent=y->parent = root;
		x->code=0; y->code=1; 
		q.push(root);
	}
	//得到哈夫曼编码 
	UTDCode(q.top());
	cout<<"从上往下得到哈夫曼编码:"<<endl;
	map<int,string>::iterator it;
	for(it=ans.begin();it!=ans.end();it++) 
	{
		cout<<it->first<<": ";
		cout<<it->second<<endl; 
	}
	cout<<"从下往上得到哈夫曼编码:"<<endl;
	cnt=q.top()->weight;
	DTUCode(q.top()); 
} 
