#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode*next;
    ListNode(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
//����ͷ��������
/*class List
{
    public:
        ListNode*head;
        List()
        {
            head=new ListNode(0);
        }
        List(string input)
        {
            head=new ListNode(0);
            for(int i=0;i<input.length();i++)
                tailinsert(input[i]-'0');
        }
        void tailinsert(int data)
        {
            ListNode*p=head;
            ListNode*q=head->next;
            while(q!=NULL)
            {
                p=q;
                q=q->next;
            }
            ListNode*temp=new ListNode(data);
            temp->next=p->next;
            p->next=temp;
        }
        ListNode* ReverseList()
        {
            if(head==NULL)
                return 0;
            ListNode*p=head->next;
            ListNode*q=head->next->next;
            ListNode*r;
            head->next->next=NULL;
            while(q)
            {
                r=q->next;
                q->next=p;
                p=q;
                q=r;
            }
            return p;
        }
};*/
//����ͷ��������,��ת�����е�m�����͵�n�����Ĳ���
class List
{
  public:
    ListNode *head;
    List(string a)
    {
        int i=0;
        head=new ListNode(a[i]-'0');
        for(i=1;i<a.length();i++)
            {
                tailinsert(a[i]-'0');
            }
    }
    void tailinsert(int data)
    {
            ListNode*p=head;
            ListNode*q=head->next;
            while(q!=NULL)
            {
                p=q;
                q=q->next;
            }
            ListNode*temp=new ListNode(data);
            temp->next=p->next;
            p->next=temp;
    }
    ListNode* ReverseList(int m,int n)
    {
        //dummy��ٵģ��ٵ�,��һ�������ͷ��㣬��ͷ��㱻��ת�����
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        //�õ�m���ǰ��һ�����
        for(int i=1;i<m;i++)
        {
            //cout<<"1"<<endl;
            if(head==NULL)//�ղų���ĵط���д����head=NULL
                return NULL;
            head=head->next;
        }
        //��¼m�ڵ��ǰһ�����
        ListNode*start=head;
        ListNode*mnode=head->next;
        ListNode*nnode=mnode;
        ListNode*end=nnode->next;
        for(int i=m;i<n;i++)
        {
            if(end==NULL)
                return NULL;
            ListNode*temp=end->next;
            end->next=nnode;
            nnode=end;
            end=temp;
        }
        start->next=nnode;
        mnode->next=end;
        return  dummy->next;
    }
    void show(ListNode*head)
    {
         ListNode*p=head;
         while(p)
         {
             cout<<p->val<<" ";
             p=p->next;
         }
    }
};
int main()
{
    string a="12345";
    List  A(a);
    ListNode*ans=A.ReverseList(2,4);
    A.show(ans);
}
