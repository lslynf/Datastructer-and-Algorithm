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
     void creatList(int a[])
     {
         for(int i=0;i<length;i++)
         {
              tailInsert(a[i]);
         }
     }
     //尾插法,往后遍历找到空结点插入
     void tailInsert(int data)
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
    void deleteDuplicates()
    {
        node*p=head;
        node*q=head->next;
        node*temp;
        while(q!=NULL)
        {
            if(p->data==q->data)
            {
                temp=q;
                q=q->next;
                p->next=q;
                delete temp;
            }
            else
            {
                p=q;
                q=q->next;
            }
        }
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
};
int main()
{
    int a[]={1,1,2,3,3};
    linklist A(5);
    A.creatList(a);
    A.deleteDuplicates();
    A.transverse();
}
