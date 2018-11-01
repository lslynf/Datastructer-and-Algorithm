//创建循环链表 
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	struct node*next;
}Listnode,*Pnode;
int n; 
void CreatList(Pnode &head)
{
	head=new Listnode;
	head->data=1;
	head->next=NULL;
	Pnode r,p;
	r=head;
	for(int i=2;i<=n;i++)
	{
		p=new Listnode;
		p->data=i;
		r->next=p;
		r=p;
		p->next=NULL;
	}
	p->next=head;
}
void Print(Pnode head)
{
	int cnt=0;
	Pnode r;
	r=head;
	while(true)
	{
		cout<<r->data<<" ";
		r=r->next;
		cnt++;
		if(cnt==2*n)
			break;
	}
}
int main()
{
	cin>>n;
	Pnode head;//头指针也是头结点 
    CreatList(head);
    Print(head);
}
