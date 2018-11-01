#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int weight;
	struct node *lchild,*rchild;
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
void Code(Huffman T)
{
	if(T->leaf==true)//���������Ҷ�ӽڵ� 
	{
		ans[T->weight]=res;
		return;
	}
	res+='0';
	Code(T->lchild);
	res[res.size()-1]='1';//���� 
	Code(T->rchild);
	res=res.substr(0,res.size()-1);//ͬ����� 
}
void LayerOrder(Huffman &T)
{
	queue<Huffman>q;
	if(T!=NULL)
	{
		q.push(T);
	}
	while(!q.empty())
	{
	 	Huffman temp=q.front();
	 	q.pop();
		cout<<temp->weight<<" ";
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
	int n;
	cin>>n;
	while(n--)
	{
		int value;
		cin>>value;
		Huffman temp=new HuffmanNode;
		temp->weight=value;
		temp->lchild=temp->rchild=NULL;
		temp->leaf=true;
		q.push(temp);
	}
	//������������ 
	while(q.size()>1)
	{
		Huffman x=q.top();q.pop();
		Huffman y=q.top();q.pop();
		Huffman root=new HuffmanNode;
		root->weight=x->weight+y->weight;
		root->lchild=x;root->rchild=y;
		root->leaf=false;
		q.push(root);
	}
	//�õ����������� 
	Huffman t=q.top();
//	LayerOrder(t);
	Code(q.top());
	map<int,string>::iterator it;
	cout<<"�������µõ�����������:"<<endl;
	for(it=ans.begin();it!=ans.end();it++) 
	{
		cout<<it->first<<": ";
		cout<<it->second<<endl; 
	}
}
