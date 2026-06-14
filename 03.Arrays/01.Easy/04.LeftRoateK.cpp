#include<bits/stdc++.h>
using namespace std;

// brute force

void rotatek(vector<int> nums, int k)
{
    vector<int> temp;
    int n=nums.size();

    for(int i=0;i<k;i++)
    {
        temp.push_back(nums[i]);
    }

    for(int i=k;i<n;i++)
    {
        nums[i-k]=nums[i];
    }

    for(int i=n-k;i<n;i++)
    {
        nums[i]=temp[i-n-k];
    }
}

// optimal;

void rotatek(vector<int> nums,int k)
{
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
}