// Find the number of occurences of x in sorted array nums

#include<bits/stdc++.h>
using namespace std;

int count(vector<int> nums, int x)
{
    int n=nums.size();

    int lb=lower_bound(nums.begin(),nums.end(),x)-nums.begin();

    if(lb==n || nums[lb]!=x) return 0;

    int ub=upper_bound(nums.begin(),nums.end(),x)-nums.begin();

    int first=lb,last=ub-1;

    return last-first+1;

}