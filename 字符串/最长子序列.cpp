/*给出一个字符串，找到最长的子串且不含有重复的字符*/
//思路：利用一个数组存放该字符是否被访问
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
class Solution
{
   public:
    int lengthOfLongestSubstring(string s)
    {
        int visit[128];
        int ans=0;
        int length=0;
        int i,j;
        for(i=0;i<s.length();i++)
        {
            memset(visit,0,sizeof(visit));//每次遍历清空访问数组
            visit[s[i]]=1;
            for(j=i+1;j<s.length();j++)
            {
                if(visit[s[j]]==0)//如果没有被访问
                    visit[s[j]]=1;
                else
                {
                    length=j-i;
                    if(length>ans)
                        ans=length;
                    break;
                }
            }
            if((j==s.length())&&(j-i>ans))
            {
                ans=j-i;
            }
        }
        return ans;
    }
};
int main()
{
    string input;
    cin>>input;
    Solution  ans;
    cout<<ans.lengthOfLongestSubstring(input);
}
