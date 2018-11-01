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
class linklist
{
   public:
     int length;
     node* head;
     linklist(int len)
     {
        head=new node(0);
        length=len;
     }
     void creatlist(int a[])
     {
         for(int i=0;i<length;i++)
         {
              tailinsert(a[i]);
         }
     }
     //尾插法,从头结点开始往后遍历找到空结点插入
     void tailinsert(int data)
     {
         node*pre=head;
         node*p=head->next;
         while(p!=NULL)
         {
            pre=p;
            p=p->next;
         }
         node* temp=new node(data);
         temp->next=pre->next;
         pre->next=temp;
     }
     //头插法
    void headinsert(int data)
    {
        node* temp=new node(data);
        temp->next=head->next;
        head->next=temp;
    }
    void transverse()
    {
        node*cur=head->next;
        while(cur!=NULL)
           {
               cout<<cur->data<<" ";
               cur=cur->next;
           }
    }
    void deletedata(int data)
    {
        node*p=head;
        node*temp=head->next;
        node*q;
        while(temp!=NULL)
        {
            if(temp->data==data)
            {
                q=temp;
                temp=temp->next;
                p->next=temp;
                delete q;
            }
            else
            {
                p=temp;
                temp=temp->next;
            }
        }
    }
};
int main()
{
    int a[]={1,2,6,3,4,5,6};
    linklist  A(7);
    A.creatlist(a);
    A.deletedata(6);
    A.transverse();
}
