/*//简单相加
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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
class Linklist
{
  public:
    node*head;
    int length;
    Linklist(int len)
    {
        head=new node(0);
        length=len;
    }
    node* creatList(int a[])
    {
        for(int i=0;i<length;i++)
            tailInsert(a[i]);
        return head;
    }
    void tailInsert(int data)
    {
        node*p=head;
        node*q=head->next;
        while(q!=NULL)
        {
            p=q;
            q=q->next;
        }
        node*temp=new node(data);
        temp->next=p->next;
        p->next=temp;
    }
};
class Solution
{
    public :
        node*addlist(node*head1,node*head2)
        {
            node*cur1=head1->next;
            node*cur2=head2->next;
            while(cur1!=NULL&&cur2!=NULL)
            {
                cur1->data+=cur2->data;
                cur1=cur1->next;
                cur2=cur2->next;
            }
            return head1;
        }
        void show(node*head)
        {
            node*cur=head->next;
            while(cur!=NULL)
            {
                cout<<cur->data<<" ";
                cur=cur->next;
            }
        }
};
int main()
{
    int a[]={6,1,7};
    int b[]={2,9,5};
    Linklist  A(3);
    Linklist  B(3);
    node*head1=A.creatList(a);
    node*head2=B.creatList(b);
    Solution C;
    node*result=C.addlist(head1,head2);
    C.show(result);
}*/
//加上进位
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
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
class LinkList
{
  public:
    node*head;
    LinkList()
    {
        head=new node(0);
    }
    LinkList(string a)
    {
        head=new node(0);//注意一定要初始化头结点
        for(int i=0;i<a.length();i++)
            headinsert(a[i]-'0');
    }
    void headinsert(int data)
    {
        node*temp=new node(data);
        temp->next=head->next;
        head->next=temp;
        head->data++;
    }
    void transverse()
    {
    	cout<<head->data<<endl;
        node*cur=head->next;
        while(cur!=NULL)
        {
            cout<<cur->data;
            cur=cur->next;
        }
    }
};
LinkList  add(LinkList A,LinkList B)
{
    LinkList  result;
    int carry=0;
    node*cur1=A.head->next;
    node*cur2=B.head->next;
    while(cur1!=NULL&&cur2!=NULL)
    {
         int ans=(cur1->data+cur2->data+carry)%10;
         result.headinsert(ans);
         carry=(cur1->data+cur2->data+carry)/10;
         cur1=cur1->next;
         cur2=cur2->next;
    }
    //说明A没有访问完
    if(cur1!=NULL)
    {
         while(cur1!=NULL)
         {
             int ans=(cur1->data+carry)%10;
             result.headinsert(ans);
             carry=(cur1->data+carry)/10;
             cur1=cur1->next;
         }
    }
    //说明B没有访问完
    if(cur2!=NULL)
    {
        while(cur2!=NULL)
        {
            int ans=(cur2->data+carry)%10;
            result.headinsert(ans);
            carry=(cur2->data+carry)/10;
            cur2=cur2->next;
        }
    }
    //如果两个链表都访问完了，还有进位，则插入
    if(carry!=0)
    {
        result.headinsert(carry);
    }
    return result;
}
int main()
{
    string a,b;
    cin>>a;
//    cin>>b;
	LinkList  A(a);
//	LinkList  B(b);
	A.transverse(); 
//    LinkList  C=add(A,B);
//	C.transverse();
}
