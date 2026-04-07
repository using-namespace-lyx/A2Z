#include<bits/stdc++.h>
using namespace std;

// brute

int count(vector<int> &nums,int k)
{
    int n=nums.size(),count=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            if(sum==k)
            count++;
        }
    }

    return count;
}

// optimal hash

int hashcount(vector<int>&nums,int k)
{
    int n=nums.size(),sum=0,count=0;
    unordered_map<int,int> m;
    m[0]=1;

    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        int remain=sum-k;
        count+=m[remain];
        m[sum]++;
    }

    return count;
}