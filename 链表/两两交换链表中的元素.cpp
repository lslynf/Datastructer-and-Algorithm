#include<bits/stdc++.h> 
using namespace std;
struct node
{
	int data;
	node*next;
	node(int a)	
	{
		data=a;
		next=NULL;
	}
};
class linklist
{
	public:
		int length;
		node* head;
		linklist(int len)
		{
			head=new node(0);//��ʼ��ͷ�ڵ� 
			length=len;//������ 
		}
		//�������� 
		void creatlist(int a[]) 
		{
			for(int i=0;i<length;i++)
			{
				tailinsert(a[i]);
			}
		}
		//β�巨,��ͷ��㿪ʼ��������ҵ��ս����� 
		void tailinsert(int data)
		{
			node*pre=head;
			node*p=head->next;
			while(p!=NULL)	
			{
				pre=p;
				p=p->next;
			}
			node*temp=new node(data);
			temp->next=pre->next;
			pre->next=temp;
		}
		//��ӡ���� 
		void traverse()
		{
			node*cur=head->next;
        	while(cur!=NULL)
            {
               cout<<cur->data<<" ";
               cur=cur->next;
            }
            cout<<endl;
		}
		//����������� 
		node *change()
		{
			node* r=new node(0);
			r=head;
			node* p=r;
			//�ظ��˹���,����ָ��p����ǰ�� 
			while(p->next!=NULL&&p->next->next!=NULL)
			{
				node* a=p->next;
				node* b=a->next;
				node* c=b->next;
				
				p->next=b;	
				b->next=a;
				a->next=c;
				
				p=a;
			}
			return r->next;	
		}
};	
int main()
{
	int a[]={1,2,3,4,5};
    linklist  A(5);
    A.creatlist(a);
    A.traverse();
    A.change();
    A.traverse();
}
