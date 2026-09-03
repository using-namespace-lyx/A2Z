#include<bits/stdc++.h>
using namespace std;

vector<int> majorityEl2(vector<int> nums)
{
    int n= nums.size();
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=i;j<n;j++)
        {
            if(nums[i]==nums[j])
            {
                count++;
                if(count>n/3)
                {
                    res.push_back(nums[i]);
                }
            }
        }
    }
    return res;
}

vector<int> majEl2(vector<int> nums)
{
    unordered_map<int,int> mpp;
    vector<int> res;
    for(int num:nums)
    {
        mpp[num]++;
        if(mpp[num]>n/3)
        res.push_back(num);

    }
    return res;
}

class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int count1=0,el1=0,count2=0,el2=0;

        for(int num:nums)
        {
            if(count1==0 && el2!=num )
            {
                el1=num;
                
            }
            else if(count2==0 && num!=el1)
            {
                el2=num;
                
            }
            if(num==el1)
            {
                count1++;
            }
            else if(num==el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1=0;
        count2=0;
        for(int num:nums)
        {
            if(num==el1)
            count1++;
            else if(num==el2)
            count2++;
        }

        int n=nums.size();
        vector<int> res;
        if(count1>n/3) res.push_back(el1);
        if(count2>n/3) res.push_back(el2);

        return res;
        
    }
};