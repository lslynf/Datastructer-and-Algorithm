#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class TreeNode
{
 public:
    int val;
    TreeNode*left,*right;
    TreeNode(int a)
    {
        this->val=a;
        this->left=this->right=NULL;
    }
};
class Tree
{
public:
    string input;
    int i=0;//控制字符串的读入
    TreeNode*root;
    Tree(string input)
    {
        this->input=input;
    }
    void creat(TreeNode*& root)
    {
        char ch=input[i];
        if(ch=='\0')//读到了字符串的最后，退出程序
            return;
        if(input[i]=='#')
           {
              root=NULL;
           }
        else
        {
            root=new TreeNode(input[i]-'0');
            i++;
            creat(root->left);
            creat(root->right);
        }
    }
    void preorder(TreeNode*root)
    {
        if(root)
        {
            cout<<root->val;
            preorder(root->left);
            preorder(root->right);
        }
    }
};
int main()
{
    string a="392##57";
    Tree test(a);
    test.creat(test.root);
    test.preorder(test.root);
}
