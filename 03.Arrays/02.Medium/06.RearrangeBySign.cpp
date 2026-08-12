#include<bits/stdc++.h>
using namespace std;

vector<int> reArrange(vector<int> nums)
{
    int n=nums.size();
    vector<int> pos,neg;

    for(int i=0;i<n;i++)
    {
        if(nums[i]>0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }


    for(int i=0;i<n/2;i++)
    {
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }

    return nums;
}

vector<int> reArrange(vector<int> nums)
{
    int n=nums.size();
    vector<int> ans(n,0);
    int pos=0,neg=1;

    

    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            ans[neg]=nums[i];
            neg+=2;
        }
        else
        {
            ans[pos]=nums[i];
            pos+=2;
        }
    }

    return ans;
}

vector<int> reArrange(vector<int> nums)
{
    int n=nums.size();
    vector<int> pos,neg;

    for(int i=0;i<n;i++)
    {
        if(nums[i]>0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }


   int n1=pos.size(),n2=neg.size(),i=0,j=0,k=0;

   while(i<n1 && j<n2)
   {
    nums[k++]=pos[i++];
    nums[k++]=neg[j++];
   }

   while(i<n1)
   nums[k++]=pos[i++];

   while(j<n2)
   nums[k++]=neg[j++];

   return nums;
}

vector<int> reArrange(vector<int> nums)
{
    int n=nums.size();
    vector<int> pos,neg;

    for(int i=0;i<n;i++)
    {
        if(nums[i]>0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }


    int n1=pos.size(),n2=neg.size();

    if(n1<n2)
    {
        for(int i=0;i<n1;i++)
        {
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=2*n1;
        for(int i=n1;i<n2;i++)
        {
            nums[index++]=neg[i];
        }
    }

    else
    {
        for(int i=0;i<n2;i++)
        {
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=2*n2;
        for(int i=n2;i<n1;i++)
        {
            nums[index++]=pos[i];
        }

    }

    return nums;
}

