#include<bits/stdc++.h>
using namespace std;

void move(vector<int> nums)
{
    int n=nums.size();
    vector<int> temp;

    for(int num:nums)
    {
        if(num) temp.push_back(num);
    }

    int t=temp.size();

    for(int i=0;i<t;i++)
    {
        nums[i]=temp[i];
    }

    for(int i=t;i<n;i++)
    {
        nums[i]=0;
    }
}

void move(vector<int> nums)
{
    int i,n=nums.size();

    for(i=0;i<n;i++)
    {
        if(nums[i]==0)
        break;
    }

    if(i==n) return;

    

    for(int j=i+1;j<n;j++)
    {
        if(nums[j])
        {
            swap(nums[i++],nums[j]);
        }
    }
}