#include<bits/stdc++.h>
using namespace std;


// O(n*n) TC
// O(1) SC
pair<int,int> find(vector<int> &nums)
{
    int n=nums.size();
    int repeat=-1,miss=-1;

    for(int i=1;i<=n;i++) // all n numbers
    {
        int count=0;

        for(int j=0;j<n;j++)
        {
            if(nums[j]==i)
            count++;

        }

        if(count==2) repeat=i;
        else if(count==0) miss=i;
        if(repeat!=-1 && miss!=-1) break;

    }

    return {repeat,miss};
}

// TC O(N)  SC O(N)

pair<int,int> hashfind(vector<int>&nums)
{
    int n=nums.size();
    vector<int> hash(n+1,0);
    pair<int,int> ans={-1,-1};
    for(int i=0;i<n;i++)
    {
        hash[nums[i]]++;
    }

    for(int i=1;i<=n;i++)
    {
        if(hash[i]==0) ans.second=i;
        else if(hash[i]==2) ans.first=i;
    }

    return ans;
}

// TC:O(N) SC: 0(1)
pair<int,int> findmath(vector<int> &nums)
{
    int n=nums.size();
    // x is repeat, y is miss

    int actsum=0,actsqrsum=0;
    for(int i=0;i<n;i++)
    {
        actsum+=nums[i];
        actsqrsum+=nums[i]*nums[i];
    }

    int optsum=(n)*(n+1)/2;
    int optsqrsum= n*(n+1)*(2*n+1)/6;

    int xminusy=actsum-optsum;
    int x2minusy2=actsqrsum-optsqrsum;
    int xplusy= x2minusy2/xminusy;
    int x= (xplusy+xminusy)/2;
    int y= xplusy-x;

    return {x,y};
}