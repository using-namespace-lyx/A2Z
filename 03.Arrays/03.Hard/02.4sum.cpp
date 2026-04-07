/*
QUESTION:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> foursum(vector<int> &nums, int target)
{
    int n=nums.size();
    set<vector<int>> s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);

                    }
                }
            }
        }
    }

    vector<vector<int>> res(s.begin(),s.end());
    return res;
}

// better

vector<vector<int>> foursum(vector<int> &nums, int target)
{
    int n=nums.size();
    set<vector<int>> s;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            unordered_set<int> hash;
            for(int k=j+1;k<n;k++)
            {
                int remain=target-nums[i]-nums[j]-nums[k];

                if(hash.find(remain)!=hash.end())
                {
                    vector<int> temp={nums[i],nums[j],nums[k],remain};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hash.insert(nums[k]);
            }

        }
    }

    vector<vector<int>> res(s.begin(),s.end());
    return res;
}

// optimal

vector<vector<int>> foursum(vector<int> &nums,int target)
{
    int n=nums.size();
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1;j<n;j++)
        {
            if(j>(i+1) && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;

            while(k<l)
            {
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target) k++;
                else if(sum>target) l--;
                else
                {
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    res.push_back(temp);
                    k++;l--;
                    while(k<l &&nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }

    return res;
}