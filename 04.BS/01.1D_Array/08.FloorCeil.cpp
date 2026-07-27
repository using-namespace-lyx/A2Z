#include<bits/stdc++.h>
using namespace std;

// Floor[x] = y | y is the greatest element <= x
// Ceil[x]=y | y is the smallest element >=x

int floor(vector<int> nums, int x)
{
    int low=0,high=nums.size()-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]<=x)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return high!=nums.size()?high:-1;
}

int ceil(vector<int> nums, int x)
{
    int lb=lower_bound(nums.begin(),nums.end(),x)-nums.begin(),n=nums.size();

    return lb!=n?lb:-1;
}