#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>&a,vector<int>&temp,int start,int mid,int end)
    {
        int i=start,j=mid+1,k=start;
        while(i<=mid&&j<=end)
        {
            if(a[i]<a[j])
                temp[k++]=a[i++];
            else
                temp[k++]=a[j++];
        }
        while(i<=mid)
            temp[k++]=a[i++];
        while(j<=end)
            temp[k++]=a[j++];
        for(int p=start;p<=end;p++)
             a[p]=temp[p];
    }
    void mergesort(vector<int>&a,vectot<int>&temp,int start,int end)
    {
        if(start<end)
        {
            int mid=(start+end)/2;
            mergesort(a,temp,start,mid);
            mergesort(a,temp,mid+1,end);
            merge(a,temp,start,mid,end);
        }
    }
    void sortIntegers2(vector<int> &A) {
        vector<int>temp;
        mergesort(A,temp,0,A.size()-1);
    }
};
