#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cmin=-1;
        int cmax=nums.size();
        int cur=0;
        while(cur<cmax)
        {
            //如果当前数小于1，则把当前数和最小区的下一位数进行交换，最小区扩大一位，同时cur指向下一位
            if(nums[cur]<1)
            {
                int temp=nums[cmin+1];
                nums[cmin+1]=nums[cur];
                nums[cur]=temp;
                cmin++;
                cur++;
                continue;
            }
            //如果当前数等于1，把cur指向下一位
            if(nums[cur]==1)
            {
                cur++;
                continue;//如果没有加continue，那么会紧接着下面的if判断，会出错
            }
            //如果当前数大于1，则把当前数和最大区的前一位进行交换，最大区向左扩大一位，同时cur不变
            if(nums[cur]>1)
            {
                int temp=nums[cmax-1];
                nums[cmax-1]=nums[cur];
                nums[cur]=temp;
                cmax--;
                continue;
            }
        }
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    Solution test;
    vector<int>a;
    int b[7]={2,1,2,0,1,2,1};
    for(int i=0;i<7;i++)
        a.push_back(b[i]);
    test.sortColors(a);
}
