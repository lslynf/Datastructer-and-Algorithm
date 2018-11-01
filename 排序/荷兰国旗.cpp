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
            //�����ǰ��С��1����ѵ�ǰ������С������һλ�����н�������С������һλ��ͬʱcurָ����һλ
            if(nums[cur]<1)
            {
                int temp=nums[cmin+1];
                nums[cmin+1]=nums[cur];
                nums[cur]=temp;
                cmin++;
                cur++;
                continue;
            }
            //�����ǰ������1����curָ����һλ
            if(nums[cur]==1)
            {
                cur++;
                continue;//���û�м�continue����ô������������if�жϣ������
            }
            //�����ǰ������1����ѵ�ǰ�����������ǰһλ���н������������������һλ��ͬʱcur����
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
