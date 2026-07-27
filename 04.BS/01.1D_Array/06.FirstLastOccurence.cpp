#include<bits/stdc++.h>
using namespace std;

// First and last occurence of a number x in sorted array return -1 if it doesnt exist
pair<int,int> occurenceBrute(vector<int> nums,int x)
{
    int first=-1,last=-1;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==x)
        {
            if(first==-1) first=i;
            last=i;
        }
    }

    return {first,last};

}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb=(lower_bound(nums.begin(),nums.end(),target))-nums.begin(),n=nums.size();

        if(lb==n || nums[lb]!=target) return {-1,-1};

        int ub=(upper_bound(nums.begin(),nums.end(),target))-nums.begin();

        return {lb,ub-1};
        
    }
};